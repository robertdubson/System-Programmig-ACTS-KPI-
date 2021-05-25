#include "server.h"
#include "serverworker.h"
#include <QThread>
#include <functional>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTimer>
#include <QMessageBox>
#include "quiz.h"
Server::Server(QObject *parent)
    : QTcpServer(parent)
{}

void Server::incomingConnection(qintptr socketDescriptor)
{
    ServerWorker *worker = new ServerWorker(this);
    if (!worker->setSocketDescriptor(socketDescriptor)) {
        worker->deleteLater();
        return;
    }
    connect(worker, &ServerWorker::disconnectedFromClient, this, std::bind(&Server::userDisconnected, this, worker));
    connect(worker, &ServerWorker::error, this, std::bind(&Server::userError, this, worker));
    connect(worker, &ServerWorker::jsonReceived, this, std::bind(&Server::jsonReceived, this, worker, std::placeholders::_1));
    connect(worker, &ServerWorker::logMessage, this, &Server::logMessage);
    m_clients.append(worker);
    emit logMessage(QString("Новий клієнт під'єднано!"));
}
void Server::sendJson(ServerWorker *destination, const QJsonObject &message)
{
    Q_ASSERT(destination);
    destination->sendJson(message);
}
void Server::broadcast(const QJsonObject &message, ServerWorker *exclude)
{
    for (ServerWorker *worker : m_clients) {
        Q_ASSERT(worker);
        if (worker == exclude)
            continue;
        sendJson(worker, message);
    }
}

void Server::jsonReceived(ServerWorker *sender, const QJsonObject &doc)
{
    Q_ASSERT(sender);


    emit logMessage(QString("ОТРИМАНО JSON: ") + QString::fromUtf8(QJsonDocument(doc).toJson()));

    QJsonObject receivedJson = doc;
    if(doc.value(QString::fromStdString("type")).toString()=="quizRequest"){
        return sendQuizzes(sender);
    }
    if (sender->userName().isEmpty())
        return jsonFromLoggedOut(sender, doc);

    jsonFromLoggedIn(sender, doc);
}

void Server::userDisconnected(ServerWorker *sender)
{
    m_clients.removeAll(sender);
    const QString userName = sender->userName();
    if (!userName.isEmpty()) {
        QJsonObject disconnectedMessage;
        disconnectedMessage[QStringLiteral("type")] = QStringLiteral("userdisconnected");
        disconnectedMessage[QStringLiteral("username")] = userName;
        broadcast(disconnectedMessage, nullptr);
        emit logMessage(userName + QLatin1String(" disconnected"));
    }
    sender->deleteLater();
}

void Server::userError(ServerWorker *sender)
{
    Q_UNUSED(sender)
    emit logMessage(QLatin1String("Error from ") + sender->userName());
}

void Server::stopServer()
{
    for (ServerWorker *worker : m_clients) {
        worker->disconnectFromClient();
    }
    close();
}

void Server::jsonFromLoggedOut(ServerWorker *sender, const QJsonObject &docObj)
{
    Q_ASSERT(sender);
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) != 0)
        return;
    const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
    if (usernameVal.isNull() || !usernameVal.isString())
        return;
    const QString newUserName = usernameVal.toString().simplified();
    if (newUserName.isEmpty())
        return;
    for (ServerWorker *worker : qAsConst(m_clients)) {
        if (worker == sender)
            continue;
        if (worker->userName().compare(newUserName, Qt::CaseInsensitive) == 0) {
            QJsonObject message;
            message[QStringLiteral("type")] = QStringLiteral("login");
            message[QStringLiteral("success")] = false;
            message[QStringLiteral("reason")] = QStringLiteral("duplicate username");
            sendJson(sender, message);
            return;
        }
    }
    sender->setUserName(newUserName);
    QJsonObject successMessage;
    successMessage[QStringLiteral("type")] = QStringLiteral("login");
    successMessage[QStringLiteral("success")] = true;
    sendJson(sender, successMessage);
    QJsonObject connectedMessage;
    connectedMessage[QStringLiteral("type")] = QStringLiteral("newuser");
    connectedMessage[QStringLiteral("username")] = newUserName;
    broadcast(connectedMessage, sender);
}

void Server::jsonFromLoggedIn(ServerWorker *sender, const QJsonObject &docObj)
{
    Q_ASSERT(sender);
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) != 0)
        return;
    const QJsonValue textVal = docObj.value(QLatin1String("text"));
    if (textVal.isNull() || !textVal.isString())
        return;
    const QString text = textVal.toString().trimmed();
    if (text.isEmpty())
        return;
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("message");
    message[QStringLiteral("text")] = text;
    message[QStringLiteral("sender")] = sender->userName();
    broadcast(message, sender);
}

void Server::sendQuizzes(ServerWorker *destination){



    //for (int i=0; i < destination->getDataBase().getQuizzes().size(); i++){

      //  QJsonObject jsonQuizzes;

        //QString quizName;

        //quizName = QString::fromStdString(destination->getDataBase().getQuizzes()[i].getQuizName());

        //int quizID;

        //quizID = destination->getDataBase().getQuizzes()[i].getID();

        //jsonQuizzes[QStringLiteral("type")] = QStringLiteral("quizzes");

        //jsonQuizzes[QStringLiteral("quizName")] = quizName;

        //jsonQuizzes[QStringLiteral("ID")] = quizID;

        //QMessageBox box;

        //box.setText(jsonQuizzes.value(quizName).toString());

        //box.exec();

        //sendJson(destination, jsonQuizzes);

    //}

    QJsonObject jsonQuizzes;

    QJsonArray quizzArray = QJsonArray();

    QMessageBox box;

    foreach(Quiz currentQuiz, destination->getDataBase().getQuizzes()){

        QJsonObject quizzObject;

        QString quizzName;

        quizzName = QString::fromStdString(currentQuiz.getQuizName());

        quizzObject["NAME"] = quizzName;

        box.setText(quizzName);

        //box.exec();

        quizzObject["ID"] = currentQuiz.getID();

        QJsonArray questionsArray = QJsonArray();

        foreach(Question quest, currentQuiz.getQuestions()){


            QJsonObject questionJson;

            questionJson["QUESTION_ID"] = quest.getID();

            questionJson["TEXT"] = QString::fromStdString(quest.getText());

            QJsonObject rightVariantJson;

            rightVariantJson["VARIANT_ID"] = quest.getRightAnwser().getID();

            rightVariantJson["VARIANT_TEXT"] = QString::fromStdString(quest.getRightAnwser().getText());

            questionJson["RIGHT_VARIANT"] = rightVariantJson;

            QJsonArray variantsJsonArray = QJsonArray();

            foreach(Variant variant, quest.getAllVariants()){

                QJsonObject variantJson;

                variantJson["VARIANT_ID"] = variant.getID();

                variantJson["TEXT"] = QString::fromStdString(variant.getText());

                variantsJsonArray.append(variantJson);

            }

            questionJson["VARIANTS_LIST"] = variantsJsonArray;

            questionsArray.append(questionJson);

        }

        quizzObject["QUESTIONS_LIST"] = questionsArray;

        quizzArray.append(quizzObject);

    }

    jsonQuizzes["QUIZZES_LIST"] = quizzArray;

    jsonQuizzes[QStringLiteral("type")] = QStringLiteral("quizzes");

    sendJson(destination, jsonQuizzes);

    //QMessageBox box;

    //for (auto it = jsonQuizzes.begin(); it != jsonQuizzes.end(); ++it)
    //{
      //  box.setText(it.value().toString());
        //box.exec();
    //}







}



void Server::sendQuestions(ServerWorker *destination){



}

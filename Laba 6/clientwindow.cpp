#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "client.h"
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <vector>
#include "quiz.h"
#include <QJsonObject>
#include <QHostAddress>
#include <QJsonArray>
#include <QListWidget>
#include "questionform.h"
#include <map>
ClientWindow::ClientWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWindow) // create the elements defined in the .ui file
    , m_chatClient(new Client(this)) // create the chat client
    , m_chatModel(new QStandardItemModel(this)) // create the model to hold the messages
{
    // set up of the .ui file
    ui->setupUi(this);
    // the model for the messages will have 1 column
    m_chatModel->insertColumn(0);
    // set the model as the data source vor the list view
    ui->chatView->setModel(m_chatModel);
    // connect the signals from the chat client to the slots in this ui
    connect(m_chatClient, &Client::connected, this, &ClientWindow::connectedToServer);
    connect(m_chatClient, &Client::loggedIn, this, &ClientWindow::loggedIn);
    connect(m_chatClient, &Client::loginError, this, &ClientWindow::loginFailed);
    connect(m_chatClient, &Client::messageReceived, this, &ClientWindow::messageReceived);
    connect(m_chatClient, &Client::disconnected, this, &ClientWindow::disconnectedFromServer);
    connect(m_chatClient, &Client::error, this, &ClientWindow::error);
    connect(m_chatClient, &Client::userJoined, this, &ClientWindow::userJoined);
    connect(m_chatClient, &Client::userLeft, this, &ClientWindow::userLeft);
    connect(m_chatClient, &Client::quizzesReceivedOnClient, this, &ClientWindow::quizzesReceivedOnClient);
    // connect the connect button to a slot that will attempt the connection
    connect(ui->connectButton, &QPushButton::clicked, this, &ClientWindow::attemptConnection);
    // connect the click of the "send" button and the press of the enter while typing to the slot that sends the message
    connect(ui->sendButton, &QPushButton::clicked, this, &ClientWindow::sendMessage);

    connect(ui->messageEdit, &QLineEdit::returnPressed, this, &ClientWindow::sendMessage);
    connect(ui->getQuizzesButton, &QPushButton::clicked, this, &ClientWindow::quizzesReceived);
    //connect(ui->poopButton, &QPushButton::clicked, this, &ChatWindow::quizzesReceived);
}

ClientWindow::~ClientWindow()
{
    // delete the elements created from the .ui file
    delete ui;
}

void ClientWindow::attemptConnection()
{
    // We ask the user for the address of the server, we use 127.0.0.1 (aka localhost) as default
    const QString hostAddress = QInputDialog::getText(
        this
        , tr("Chose Server")
        , tr("Server Address")
        , QLineEdit::Normal
        , QStringLiteral("127.0.0.1")
    );
    if (hostAddress.isEmpty())
        return; // the user pressed cancel or typed nothing
    // disable the connect button to prevent the user clicking it again
    ui->connectButton->setEnabled(false);
    // tell the client to connect to the host using the port 1967
    m_chatClient->connectToServer(QHostAddress(hostAddress), 1967);
}

void ClientWindow::connectedToServer()
{
    // once we connected to the server we ask the user for what username they would like to use
    const QString newUsername = QInputDialog::getText(this, tr("Chose Username"), tr("Username"));
    if (newUsername.isEmpty()){
        // if the user clicked cancel or typed nothing, we just disconnect from the server
        return m_chatClient->disconnectFromHost();
    }
    // try to login with the given username
    attemptLogin(newUsername);
}

void ClientWindow::attemptLogin(const QString &userName)
{
    // use the client to attempt a log in with the given username
    m_chatClient->login(userName);
}

void ClientWindow::loggedIn()
{
    // once we successully log in we enable the ui to display and send messages
    ui->sendButton->setEnabled(true);
    ui->messageEdit->setEnabled(true);
    ui->chatView->setEnabled(true);
    // clear the user name record
    m_lastUserName.clear();
}

void ClientWindow::loginFailed(const QString &reason)
{
    // the server rejected the login attempt
    // display the reason for the rejection in a message box
    QMessageBox::critical(this, tr("Error"), reason);
    // allow the user to retry, execute the same slot as when just connected
    connectedToServer();
}

void ClientWindow::messageReceived(const QString &sender, const QString &text)
{
    // store the index of the new row to append to the model containing the messages
    int newRow = m_chatModel->rowCount();
    // we display a line containing the username only if it's different from the last username we displayed
    if (m_lastUserName != sender) {
        // store the last displayed username
        m_lastUserName = sender;
        // create a bold default font
        QFont boldFont;
        boldFont.setBold(true);
        // insert 2 row, one for the message and one for the username
        m_chatModel->insertRows(newRow, 2);
        // store the username in the model
        m_chatModel->setData(m_chatModel->index(newRow, 0), sender + QLatin1Char(':'));
        // set the alignment for the username
        m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
        // set the for the username
        m_chatModel->setData(m_chatModel->index(newRow, 0), boldFont, Qt::FontRole);
        ++newRow;
    } else {
        // insert a row for the message
        m_chatModel->insertRow(newRow);
    }
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), text);
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
}

void ClientWindow::sendMessage()
{
    // we use the client to send the message that the user typed
    m_chatClient->sendMessage(ui->messageEdit->text());
    // now we add the message to the list
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row for the message
    m_chatModel->insertRow(newRow);
    // store the message in the model
    m_chatModel->setData(m_chatModel->index(newRow, 0), ui->messageEdit->text());
    // set the alignment for the message
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);
    // clear the content of the message editor
    ui->messageEdit->clear();
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();
}

void ClientWindow::disconnectedFromServer()
{
    // if the client loses connection to the server
    // comunicate the event to the user via a message box
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    // disable the ui to send and display messages
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->chatView->setEnabled(false);
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    // reset the last printed username
    m_lastUserName.clear();
}

void ClientWindow::userJoined(const QString &username)
{
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row
    m_chatModel->insertRow(newRow);
    // store in the model the message to comunicate a user joined
    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Joined the Chat").arg(username));
    // set the alignment for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    // set the color for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::blue), Qt::ForegroundRole);
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();
}
void ClientWindow::userLeft(const QString &username)
{
    // store the index of the new row to append to the model containing the messages
    const int newRow = m_chatModel->rowCount();
    // insert a row
    m_chatModel->insertRow(newRow);
    // store in the model the message to comunicate a user left
    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Left the Chat").arg(username));
    // set the alignment for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    // set the color for the text
    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::red), Qt::ForegroundRole);
    // scroll the view to display the new message
    ui->chatView->scrollToBottom();
    // reset the last printed username
    m_lastUserName.clear();
}

void ClientWindow::error(QAbstractSocket::SocketError socketError)
{
    // show a message to the user that informs of what kind of error occurred
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::ProxyConnectionClosedError:
        return; // handled by disconnectedFromServer
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The host refused the connection"));
        break;
    case QAbstractSocket::ProxyConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The proxy refused the connection"));
        break;
    case QAbstractSocket::ProxyNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the proxy"));
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the server"));
        break;
    case QAbstractSocket::SocketAccessError:
        QMessageBox::critical(this, tr("Error"), tr("You don't have permissions to execute this operation"));
        break;
    case QAbstractSocket::SocketResourceError:
        QMessageBox::critical(this, tr("Error"), tr("Too many connections opened"));
        break;
    case QAbstractSocket::SocketTimeoutError:
        QMessageBox::warning(this, tr("Error"), tr("Operation timed out"));
        return;
    case QAbstractSocket::ProxyConnectionTimeoutError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy timed out"));
        break;
    case QAbstractSocket::NetworkError:
        QMessageBox::critical(this, tr("Error"), tr("Unable to reach the network"));
        break;
    case QAbstractSocket::UnknownSocketError:
        QMessageBox::critical(this, tr("Error"), tr("An unknown error occured"));
        break;
    case QAbstractSocket::UnsupportedSocketOperationError:
        QMessageBox::critical(this, tr("Error"), tr("Operation not supported"));
        break;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
        QMessageBox::critical(this, tr("Error"), tr("Your proxy requires authentication"));
        break;
    case QAbstractSocket::ProxyProtocolError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy comunication failed"));
        break;
    case QAbstractSocket::TemporaryError:
    case QAbstractSocket::OperationError:
        QMessageBox::warning(this, tr("Error"), tr("Operation failed, please try again"));
        return;
    default:
        Q_UNREACHABLE();
    }
    // enable the button to connect to the server again
    ui->connectButton->setEnabled(true);
    // disable the ui to send and display messages
    ui->sendButton->setEnabled(false);
    ui->messageEdit->setEnabled(false);
    ui->chatView->setEnabled(false);
    // reset the last printed username
    m_lastUserName.clear();
}

void ClientWindow::quizzesReceived(){

    QMessageBox box;

    box.setText(QString::fromStdString("HERE WE ARE RECEIVING QUIZZES"));

    box.exec();

    m_chatClient->sendReqForQuizzes(QString::fromStdString("giveMeTheQuizzes"));

}

void ClientWindow::quizzesReceivedOnClient(const QJsonObject &quizzes){

    std::vector<Quiz> quizzes_vector;

    QMessageBox box;

    QJsonArray quizzJsonArray = quizzes["QUIZZES_LIST"].toArray();

    foreach (QJsonValue quizzJsonObj, quizzJsonArray){

        Quiz currentQuiz;

        currentQuiz.setID(quizzJsonObj["ID"].toInt());

        QString quizzName;

        quizzName = quizzJsonObj["NAME"].toString();

        currentQuiz.setName(quizzName.toStdString());

        std::vector<Question> *questions;

        questions = new vector<Question>();

        foreach (QJsonValue questionJson, quizzJsonObj["QUESTIONS_LIST"].toArray()){

            Question quest;

            quest.setID(questionJson["QUESTION_ID"].toInt());

            QString questText;

            questText = questionJson["TEXT"].toString();

            quest.setText(questText.toStdString());

            box.setText(questText);

            //box.exec();

            QJsonObject rightVariantJson;

            rightVariantJson = questionJson["RIGHT_VARIANT"].toObject();

            Variant rightVariant;

            rightVariant.setID(rightVariantJson["VARIANT_ID"].toInt());

            QString rightVariantText;

            rightVariantText = rightVariantJson["VARIANT_TEXT"].toString();

            rightVariant.setText(rightVariantText.toStdString());

            quest.setRightAnwser(rightVariant);

            //box.setText(rightVariantText);

            //box.exec();

            std::vector <Variant> *variants;

            variants = new vector<Variant>();

            foreach(QJsonValue variantJson, questionJson["VARIANTS_LIST"].toArray()){

                Variant *currentVarinat;

                currentVarinat = new Variant();

                currentVarinat->setID(variantJson["VARIANT_ID"].toInt());

                QString variantText;

                variantText = variantJson["TEXT"].toString();

                box.setText(variantText);

                //box.exec();

                currentVarinat->setText(variantText.toStdString());

                variants->push_back(*currentVarinat);


            }

            quest.setVariants(*variants);

            questions->push_back(quest);

        }

        currentQuiz.setQuestions(*questions);

        quizzes_vector.push_back(currentQuiz);

        //box.setText(quizzName);

        //box.exec();

    }

    QStringList quizzNames;

    foreach(Quiz currentQuiz, quizzes_vector){

        quizzNames << QString::fromStdString(currentQuiz.getQuizName());

        quizMap.insert(make_pair(QString::fromStdString(currentQuiz.getQuizName()), currentQuiz));


        //box.setText(QString::fromStdString(currentQuiz.getQuizName()));

        //box.exec();
        //foreach(Question currentQuestion, currentQuiz.getQuestions()){

            //box.setText(QString::fromStdString(currentQuestion.getText()));

            //box.exec();

            //foreach(Variant var, currentQuestion.getAllVariants()){

                //box.setText(QString::fromStdString(var.getText()));

                //box.exec();

            //}


        //}

    }

    ui->quizzesListWidget->addItems(quizzNames);


}

void ClientWindow::questionsReceived(){


}
void ClientWindow::selectedQuizSent(){


}
void ClientWindow::selectedVariantSent(){


}


void ClientWindow::on_quizzesListWidget_itemDoubleClicked(QListWidgetItem *item)
{

    Quiz selectdQuiz;

    selectdQuiz = quizMap[item->text()];

    Points = 0;

    foreach(Question quest, selectdQuiz.getQuestions()){

        QuestionForm *questForm;

        questForm = new QuestionForm(this);

        questForm->setMainWindow(this);

        questForm->setQuestion(quest);

        questForm->show();

    }




}

void ClientWindow::setPoints(int inPoints){

    Points = inPoints;

}

int ClientWindow::getPoints(){

    return Points;

}

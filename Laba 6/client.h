#ifndef CHATCLIENT_H
#define CHATCLIENT_H
#include <QListWidgetItem>
#include <QObject>
#include <QTcpSocket>
#include "quiz.h"
class QHostAddress;
class QJsonDocument;
class Client : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Client)
public:
    explicit Client(QObject *parent = nullptr);
public slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void login(const QString &userName);
    void sendMessage(const QString &text);
    void disconnectFromHost();
    void selectedQuizSent(const int &selectedQuizID);
    void selectedVariantSent(const int &selectedVarID);
    void sendReqForQuizzes(const QString name);
private slots:
    void onReadyRead();
signals:
    void connected();
    void loggedIn();
    void loginError(const QString &reason);
    void disconnected();
    void messageReceived(const QString &sender, const QString &text);
    void error(QAbstractSocket::SocketError socketError);
    void userJoined(const QString &username);
    void userLeft(const QString &username);
    void quizzesReceivedOnClient(const QJsonObject &quizzes);
    void questionsReceived(const QJsonObject &questions);

private:

    QTcpSocket *m_clientSocket;
    bool m_loggedIn;
    void jsonReceived(const QJsonObject &doc);

};

#endif // CHATCLIENT_H

#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QAbstractSocket>
#include "quiz.h"
#include <QListWidgetItem>
#include <QListWidget>
class Client;
class QStandardItemModel;
namespace Ui { class ClientWindow; }
class ClientWindow : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ClientWindow)
public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();
    void setPoints(int inPoints);
    int getPoints();

private:
    Ui::ClientWindow *ui;
    Client *m_chatClient;
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;
private slots:
    void attemptConnection();
    void connectedToServer();
    void attemptLogin(const QString &userName);
    void loggedIn();
    void loginFailed(const QString &reason);
    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    void userJoined(const QString &username);
    void userLeft(const QString &username);
    void error(QAbstractSocket::SocketError socketError);
    void quizzesReceived();
    void quizzesReceivedOnClient(const QJsonObject &quizzes);
    void questionsReceived();
    void selectedQuizSent();
    void selectedVariantSent();

    void on_quizzesListWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    map<QString, Quiz> quizMap;
    int Points;

};

#endif // CHATWINDOW_H

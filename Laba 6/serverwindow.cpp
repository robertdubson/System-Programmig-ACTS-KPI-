#include "serverwindow.h"
#include "ui_serverwindow.h"
#include "server.h"
#include <QMessageBox>
ServerWindow::ServerWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWindow)
    , m_chatServer(new Server(this))
{
    ui->setupUi(this);
    connect(ui->startStopButton, &QPushButton::clicked, this, &ServerWindow::toggleStartServer);
    connect(m_chatServer, &Server::logMessage, this, &ServerWindow::logMessage);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::toggleStartServer()
{
    if (m_chatServer->isListening()) {
        m_chatServer->stopServer();
        ui->startStopButton->setText(tr("Увімкнути сервер"));
        logMessage(QString("Сервер було зупинено"));
    } else {
        if (!m_chatServer->listen(QHostAddress::Any, 1967)) {
            QMessageBox::critical(this, tr("ПОМИЛКА"), tr("НЕМОЖЛИВО ПІД'ЄДНАТИСЯ ДО СЕРВЕРУ"));
            return;
        }
        logMessage(QString("ПІД'ЄДНАННЯ ДО СЕРВЕРУ УСПІШНЕ!"));
        ui->startStopButton->setText(tr("Зупинити сервер"));
    }
}

void ServerWindow::logMessage(const QString &msg)
{
    ui->logEditor->appendPlainText(msg + QLatin1Char('\n'));
}

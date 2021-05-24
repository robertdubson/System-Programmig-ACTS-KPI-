#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButtonStart_clicked()
{
    //hide();
    selectionWindow = new QuizSelectionWindow(this);
    selectionWindow->show();
}

void MainWindow::on_toolButtonCheckResults_clicked()
{
    //hide();
    userResults = new UserResults(this);
    userResults->show();
}

void MainWindow::on_toolButtonAbout_clicked()
{
    //hide();
    about = new AboutWindow(this);
    about->show();
}

void MainWindow::on_toolButtonExit_clicked()
{
    close();
}

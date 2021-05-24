#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "quizselectionwindow.h"
#include "ui_quizselectionwindow.h"
#include "ui_userresults.h"
#include "userresults.h"
#include "aboutwindow.h"
#include "ui_aboutwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButtonStart_clicked();

    void on_toolButtonCheckResults_clicked();

    void on_toolButtonAbout_clicked();

    void on_toolButtonExit_clicked();

private:
    Ui::MainWindow *ui;
    QuizSelectionWindow *selectionWindow;
    UserResults *userResults;
    AboutWindow *about;

};
#endif // MAINWINDOW_H

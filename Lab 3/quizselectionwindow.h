#ifndef QUIZSELECTIONWINDOW_H
#define QUIZSELECTIONWINDOW_H

#include <QDialog>
#include "InMemoryDataBase.h"
#include <QListWidgetItem>

namespace Ui {
class QuizSelectionWindow;
}

class QuizSelectionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QuizSelectionWindow(QWidget *parent = nullptr);
    ~QuizSelectionWindow();
    void setCurrentRating(int inRating);
    int getCurrentRating();

private slots:
    void on_quizzesListWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::QuizSelectionWindow *ui;
    InMemoryDataBase *Db;
    map<QString, Quiz> quizMap;
    int current_rating;
};

#endif // QUIZSELECTIONWINDOW_H

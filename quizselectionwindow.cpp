#include "quizselectionwindow.h"
#include "ui_quizselectionwindow.h"
#include <QLineEdit>
#include <map>
#include <QMessageBox>
#include "questionform.h"


QuizSelectionWindow::QuizSelectionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuizSelectionWindow)
{
    ui->setupUi(this);

    InMemoryDataBase *dataBase;

    dataBase = new InMemoryDataBase();

    QStringList strList;

    for (long i=0; i<dataBase->getQuizzes().size(); i++){

        strList << QString::fromStdString(dataBase->getQuizzes()[i].ToString());
        quizMap.insert(make_pair(QString::fromStdString(dataBase->getQuizzes()[i].ToString()), dataBase->getQuizzes()[i]));

    }

    ui->quizzesListWidget->addItems(strList);

}

QuizSelectionWindow::~QuizSelectionWindow()
{
    delete ui;
}

void QuizSelectionWindow::on_quizzesListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    Quiz selectdQuiz;

    //selectdQuiz = new Quiz();

    selectdQuiz = quizMap[item->text()];

    //current_rating = 0;

    Round *currentRound;

    currentRound = new Round();

    currentRound->setRating(0);

    for(int i = 0; i<selectdQuiz.getQuestions().size(); i++){

        QuestionForm *quesForm;

        quesForm = new QuestionForm(this);

        quesForm->setQuestionText(selectdQuiz.getQuestions()[i]);

        quesForm->setCurrentRound(*currentRound);

        quesForm->show();

    }


}

void QuizSelectionWindow::setCurrentRating(int inRating){

    current_rating = inRating;

}

int QuizSelectionWindow::getCurrentRating(){

    return current_rating;

}



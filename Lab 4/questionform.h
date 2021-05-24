#ifndef QUESTIONFORM_H
#define QUESTIONFORM_H

#include <QDialog>
#include "QuizHeader.h"
#include <map>
#include <QListWidgetItem>
#include "quizselectionwindow.h"
#include "Round.h"
#include "currentratingform.h"
namespace Ui {
class QuestionForm;
}

class QuestionForm : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionForm(QWidget *parent = nullptr);
    ~QuestionForm();
    //Question getQuestion();
    void setQuestionText(Question inQuestion);
    void setCurrentRound(Round inRound);
    void setCurrentRoundForm(CurrentRatingForm *inForm);
    CurrentRatingForm getCurrentRoundForm();
    Round getRound();
    //void setParentWindow(QuizSelectionWindow inParentWindow);
    //QuizSelectionWindow getParentWindow();
    //Question ques;

private slots:
    //void on_acceptAnwserButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::QuestionForm *ui;
    Question quest;
    map <QString, Variant> variants;
    Round currentRound;
    CurrentRatingForm *ratingForm;
    //QuizSelectionWindow myParentWindow;
    //Question ques;
};

#endif // QUESTIONFORM_H

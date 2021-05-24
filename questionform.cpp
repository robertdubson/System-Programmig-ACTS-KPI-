#include "questionform.h"
#include "ui_questionform.h"
#include<QMessageBox>
QuestionForm::QuestionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionForm)
{
    ui->setupUi(this);
}

QuestionForm::~QuestionForm()
{
    delete ui;
}

void QuestionForm::setQuestionText(Question inQuestion){

    //ques = new Question();

    //*ques = inQuestion;

    quest = inQuestion;

    ui->questTextLabel->setText(QString::fromStdString(inQuestion.getText()));

    QStringList strList;

    for(int i=0; i<inQuestion.getAllVariants().size(); i++){

        strList<< QString::fromStdString(inQuestion.getAllVariants()[i].getText());
        variants.insert(make_pair(QString::fromStdString(inQuestion.getAllVariants()[i].getText()), inQuestion.getAllVariants()[i]));

    }
    ui->listWidget->addItems(strList);

}



void QuestionForm::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    Variant selectedVariant;

    selectedVariant = variants[item->text()];

    if(quest.checkUserAnwser(selectedVariant)){

        QMessageBox Msgbox;
        Msgbox.setText("Ви відповіли вірно!");
        Msgbox.exec();
        currentRound.setRating(currentRound.getRating()+1);

    }
    else{

        QMessageBox Msgbox;
        Msgbox.setText("Нажаль, ви помилилися. Правильний варіант: " + QString::fromStdString(quest.getRightAnwser().getText()));
        Msgbox.exec();

    }
    this->close();
}

void QuestionForm::setCurrentRound(Round inRound){

    currentRound = inRound;

}

Round QuestionForm::getRound(){

    return currentRound;

}



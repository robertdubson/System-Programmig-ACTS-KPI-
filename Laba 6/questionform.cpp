#include "questionform.h"
#include "ui_questionform.h"
#include "variant.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
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

void QuestionForm::setQuestion(Question inQuestion){

    quest = inQuestion;

    ui->questionTextLabel->setText(QString::fromStdString(inQuestion.getText()));

    QStringList variantTexts;

    foreach (Variant variant, inQuestion.getAllVariants()){

        variants.insert(make_pair(QString::fromStdString(variant.getText()), variant));
        variantTexts << QString::fromStdString(variant.getText());

    }

    ui->VariantsListWidget->addItems(variantTexts);

}

void QuestionForm::on_VariantsListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    Variant selectedVariant;

    selectedVariant = variants[item->text()];

    if(quest.checkUserAnwser(selectedVariant)){

        currentMainWindow->setPoints(currentMainWindow->getPoints()+1);

        QString currentRating;

        currentRating.setNum(currentMainWindow->getPoints());

        QMessageBox Msgbox;
        Msgbox.setText("Ви відповіли вірно! Поточний результат складає " + currentRating + " балів");
        Msgbox.exec();


        //currentRound.setRating(currentRound.getRating()+1);
        //ratingForm->setRating(ratingForm->getRating() + 1);
        //ratingForm->getCurrentRound().setRating(ratingForm->getCurrentRound().getRating() + 1);
        //ratingForm->setCurrentRound(ratingForm->getCurrentRound().setRating());
        //ratingForm->showCurrentRating();
        //QMessageBox msgBox;
        //QString str;
        //str.setNum(currentRound.getRating());

        //msgBox.setText("Ваш рейтинг складає " + str);
        //msgBox.exec();

    }
    else{

        QMessageBox Msgbox;

        QString currentRating;

        currentRating.setNum(currentMainWindow->getPoints());

        Msgbox.setText("Нажаль, ви помилилися. Правильний варіант: " + QString::fromStdString(quest.getRightAnwser().getText()) + " Поточний результат:" + currentRating);
        Msgbox.exec();

        //ratingForm->showCurrentRating();

    }
    this->close();
}

void QuestionForm::setMainWindow(ClientWindow *inWindow){

    currentMainWindow = inWindow;

}

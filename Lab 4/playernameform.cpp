#include "playernameform.h"
#include "ui_playernameform.h"
#include <QString>
#include <QMessageBox>

PlayerNameForm::PlayerNameForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerNameForm)
{
    ui->setupUi(this);
}

PlayerNameForm::~PlayerNameForm()
{
    delete ui;
}

void PlayerNameForm::setPlayerName(std::string inName){

    playerName = inName;

}

std::string PlayerNameForm::getPlayerName(){

    return playerName;

}
void PlayerNameForm::on_pushButton_clicked()
{
    QString str;

    str = ui->playerNameTextEdit->toPlainText();

    if(str == ""){

        QMessageBox box;

        box.setText("Будь ласка, вкажіть ім'я гравця.");

        box.exec();
    }
    else{

        this->setPlayerName(str.toStdString());

        ratingForm->setPlayerName(str.toStdString());

        this->close();



    }


}

void PlayerNameForm::setCurrentRatingForm(CurrentRatingForm *inForm){

    ratingForm = inForm;

}


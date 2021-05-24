#include "currentratingform.h"
#include "ui_currentratingform.h"
#include <QMessageBox>
#include <QtSql>
#include <QFile>
CurrentRatingForm::CurrentRatingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CurrentRatingForm)
{
    ui->setupUi(this);
}

CurrentRatingForm::~CurrentRatingForm()
{
    delete ui;
}

void CurrentRatingForm::setCurrentRound(Round *inRound){

    currentRound = inRound;

}

Round CurrentRatingForm::getCurrentRound(){

    return *currentRound;

}
void CurrentRatingForm::showCurrentRating(){

    QString ratingStr;
    ratingStr.setNum(this->getRating());
    ui->labelCurrentRating->setText(ratingStr);

    ui->labelPlayerName->setText(QString::fromStdString(PlayerName));

}

int CurrentRatingForm::getRating(){

    return Rating;

}

void CurrentRatingForm::setRating(int inRating){

    Rating = inRating;

}

void CurrentRatingForm::setPlayerName(std::string inName){

    PlayerName = inName;

}

std::string CurrentRatingForm::getPlayerName(){

    return PlayerName;

}


void CurrentRatingForm::on_pushButton_clicked()
{
    QMessageBox messageBox;

    if(QString::fromStdString(PlayerName) ==""){

        messageBox.setText("НЕ ВКАЗАНО ІМ'Я ГРАВЦЯ!");

        messageBox.exec();
    }
    else{

        messageBox.setText("Збережно ім'я гравця " + QString::fromStdString(PlayerName));

        messageBox.exec();


    }
    QString fileName = "C:/Users/Robert/Documents/testApplication/results.txt";
    QFile myFile(fileName);

    if(!myFile.open(QFile::Append | QFile::Text)){

        QMessageBox::warning(this, "title", "Не вдалося відкрити файл");

    }

    QTextStream out(&myFile);

    QString strRating;

    out <<"======" << endl;

    out << QString::fromStdString(PlayerName);

    out << " - ";

    out << strRating.setNum(Rating) << endl;

    myFile.flush();
    myFile.close();

    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("quizGame.sqlite");
    if (!sdb.open()) {
          qDebug() << sdb.lastError().text();
    }
    QSqlQuery query;
    QString qstr = "CREATE TABLE IF NOT EXISTS USERS ("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
    "NAME VARCHAR(255), ""RATING INTEGER NOT NULL"
    ");";

    if(query.exec(qstr)){

        QMessageBox msgboxx;

        msgboxx.setText("YEEEAH");

        //msgboxx.exec();

    }
    else{

        QMessageBox msgboxx;

        msgboxx.setText("Запис до бази даних не вийшов :(");

        msgboxx.exec();


    }


    QString quryString = "INSERT INTO USERS (NAME, RATING) VALUES ('" + QString::fromStdString(PlayerName) + "', '" + strRating + "');";

    if(query.exec(quryString)){

        QMessageBox msgboxx;

        msgboxx.setText("cocojumbo!!");

        //msgboxx.exec();

    }
    else{

        QMessageBox msgboxx;

        msgboxx.setText("nicht!");

        msgboxx.exec();


    }
    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //db.setHostName("robert");
    //db.setDatabaseName("QuizGame");
    //bool ok = db.open();



    //if (ok){

        //messageBox.setText("З'єднання встановлено!");

        //messageBox.exec();


    //}
    //else{

        //messageBox.setText("З'єднання з базою даних не встановлено.");

        //messageBox.exec();

    //}

    this->close();


}

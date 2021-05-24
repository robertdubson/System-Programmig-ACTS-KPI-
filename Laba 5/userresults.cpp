#include "userresults.h"
#include "ui_userresults.h"
#include <QFile>
#include <QTextStream>

UserResults::UserResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserResults)
{
    ui->setupUi(this);

    QStringList strList;
    QString fileName = "C:/Users/Robert/Documents/testApplication/results.txt";
    QFile myFile(fileName);
    QTextStream in(&myFile);
    if (myFile.open(QIODevice::ReadOnly))
    {
       while (!in.atEnd())
       {
          QString line = in.readLine();
          if(line!=QString::fromStdString("======") || line!=QString::fromStdString("----")){

              strList.append(line);
          }
       }
       myFile.close();
    }
       ui->listWidgetCurrentResults->addItems(strList);
}

UserResults::~UserResults()
{
    delete ui;
}

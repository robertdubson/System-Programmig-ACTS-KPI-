#include "userresults.h"
#include "ui_userresults.h"

UserResults::UserResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserResults)
{
    ui->setupUi(this);
}

UserResults::~UserResults()
{
    delete ui;
}

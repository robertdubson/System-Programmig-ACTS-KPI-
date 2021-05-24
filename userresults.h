#ifndef USERRESULTS_H
#define USERRESULTS_H

#include <QDialog>

namespace Ui {
class UserResults;
}

class UserResults : public QDialog
{
    Q_OBJECT

public:
    explicit UserResults(QWidget *parent = nullptr);
    ~UserResults();

private:
    Ui::UserResults *ui;
};

#endif // USERRESULTS_H

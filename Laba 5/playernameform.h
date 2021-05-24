#ifndef PLAYERNAMEFORM_H
#define PLAYERNAMEFORM_H

#include <QDialog>
#include "currentratingform.h"

namespace Ui {
class PlayerNameForm;
}

class PlayerNameForm : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerNameForm(QWidget *parent = nullptr);
    ~PlayerNameForm();
    void setPlayerName(std::string inName);
    std::string getPlayerName();
    void setCurrentRatingForm(CurrentRatingForm *inForm);
    CurrentRatingForm getRatingForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PlayerNameForm *ui;
    std::string playerName;
    CurrentRatingForm *ratingForm;

};

#endif // PLAYERNAMEFORM_H

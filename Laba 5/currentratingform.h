#ifndef CURRENTRATINGFORM_H
#define CURRENTRATINGFORM_H

#include <QDialog>
#include "Round.h"
namespace Ui {
class CurrentRatingForm;
}

class CurrentRatingForm : public QDialog
{
    Q_OBJECT

public:
    explicit CurrentRatingForm(QWidget *parent = nullptr);
    ~CurrentRatingForm();
    void setCurrentRound(Round *inRound);
    int getRating();
    void setRating(int inRating);
    Round getCurrentRound();
    void showCurrentRating();
    std::string getPlayerName();
    void setPlayerName(std::string inName);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CurrentRatingForm *ui;
    Round *currentRound;
    int Rating;
    std::string PlayerName;

};

#endif // CURRENTRATINGFORM_H

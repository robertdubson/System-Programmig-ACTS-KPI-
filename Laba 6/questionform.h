#ifndef QUESTIONFORM_H
#define QUESTIONFORM_H
#include "question.h"

#include <QDialog>
#include <map>
#include <QListWidgetItem>
#include <QListWidget>
#include "clientwindow.h"
namespace Ui {
class QuestionForm;
}

class QuestionForm : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionForm(QWidget *parent = nullptr);
    ~QuestionForm();
    void setQuestion(Question inQuestion);
    void setMainWindow(ClientWindow *inWindow);

private slots:
    void on_VariantsListWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::QuestionForm *ui;
    map <QString, Variant> variants;
    Question quest;
    ClientWindow *currentMainWindow;

};

#endif // QUESTIONFORM_H

#include <QApplication>
#include "clientwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientWindow chatWin;
    chatWin.show();
    return a.exec();
}

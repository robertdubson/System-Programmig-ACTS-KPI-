#include "filereaderwriter.h"
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
FileReaderWriter::FileReaderWriter()
{

}

void FileReaderWriter::Write(QString inText){

    QString fileName = "C:/Users/Robert/Documents/testApplication/results.txt";
    QFile myFile(fileName);

    if(!myFile.open(QFile::WriteOnly | QFile::Text)){

        //QMessageBox::warning(this, "title", "file not open");

    }

    QTextStream out(&myFile);

    out << inText;

    myFile.flush();
    myFile.close();
}

void FileReaderWriter::Read(){



}

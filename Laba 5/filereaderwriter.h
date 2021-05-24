#ifndef FILEREADERWRITER_H
#define FILEREADERWRITER_H

#include<QString>
class FileReaderWriter
{
public:
    FileReaderWriter();
    ~FileReaderWriter();
    void Write(QString inText);
    void Read();
};

#endif // FILEREADERWRITER_H

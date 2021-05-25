#ifndef VARIANT_H
#define VARIANT_H


#include <iostream>
#include <list>

#include<vector>

using namespace std;


class Variant{

private:
    std::string Text;
    int ID;
public:
    Variant();
    Variant(std::string inText);
    ~Variant();
    bool isCorrect;
    std::string getText();
    void setText(std::string inText);
    int getID();
    void setID(int inID);

};
#endif // VARIANT_H

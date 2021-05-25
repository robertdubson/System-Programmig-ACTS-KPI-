#include "variant.h"
#ifndef QUESTION_H
#define QUESTION_H
using namespace std;

class Question{

private:
    std::string QuestionText;
    Variant rightAnwser;
    vector<Variant> variants;
    int ID;

public:
    Question(std::string inText, vector<Variant> inVariants);
    Question();
    ~Question();
    Variant getRightAnwser();
    vector<Variant> getAllVariants();
    void setVariants(vector<Variant> inVariants);
    void setRightAnwser(Variant inVariant);
    bool checkUserAnwser(Variant selectedVariant);
    std::string getText();
    void setText(std::string inText);
    int getID();
    void setID(int inID);

};

#endif // QUESTION_H

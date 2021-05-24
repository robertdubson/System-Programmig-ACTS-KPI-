#ifndef QUIZHEADER_H
#define QUIZHEADER_H

#include <iostream>
#include <list>

#include<vector>

using namespace std;


class Variant{

private:
    std::string Text;

public:
    Variant();
    Variant(std::string inText);
    ~Variant();
    std::string getText();
    void setText(std::string inText);


};


class Question{

private:
    std::string QuestionText;
    Variant rightAnwser;
    vector<Variant> variants;

public:
    Question(std::string inText, vector<Variant> inVariants, Variant inRightAnwser);
    Question();
    ~Question();
    Variant getRightAnwser();
    vector<Variant> getAllVariants();
    void setVariants(vector<Variant> inVariants);
    void setRightAnwser(Variant inVariant);
    bool checkUserAnwser(Variant selectedVariant);
    std::string getText();


};

class Quiz{

private:
    vector<Question> questions;
    int points;
    std::string quizName;


public:
    bool operator == (const Quiz& s) const { return quizName == s.quizName; }
        bool operator != (const Quiz& s) const { return !operator==(s); }
    Quiz(std::string name, vector<Question> inQuestions);
    Quiz();
    ~Quiz();
    vector<Question> getQuestions();
    void setQuestions(vector<Question> inQuestions);
    void setName(std::string inName);
    std::string getQuizName();
    std::string getPlayerName();
    std::string ToString();

};


#endif // QUIZHEADER_H

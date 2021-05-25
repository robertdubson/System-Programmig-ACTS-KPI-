
#include "question.h"
#ifndef QUIZ_H
#define QUIZ_H


class Quiz{

private:
    vector<Question> questions;
    int points;
    std::string quizName;
    int ID;

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
    int getID();
    void setID(int inID);

};
#endif // QUIZ_H

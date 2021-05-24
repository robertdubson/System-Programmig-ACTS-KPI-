#ifndef INMEMORYDATABASE_H
#define INMEMORYDATABASE_H
#include <iostream>
#include <list>
#include<vector>
#include "QuizHeader.h"
#include "Round.h"
class InMemoryDataBase{

public:
    InMemoryDataBase();
    ~InMemoryDataBase();
    void setQuizzes(list<Quiz> inQuizzes);
    vector<Quiz> getQuizzes();
    vector<Round> getRounds();
    void setRounds(vector<Round> inRounds);
    void setQuizzes(vector<Quiz> inQuizzes);
    void DeleteRound(Round inRound);
    void UpdateRound(Round inRound);
    void AddRound(Round inRound);
    //Round GetRound();
    void DeleteQuiz(Quiz inQuiz);
    void UpdateQuiz(Quiz inQuiz);
    void AddQuiz(Quiz inQuiz);



private:
    vector<Quiz> quizzes;
    vector<Round> rounds;



};

#endif // INMEMORYDATABASE_H

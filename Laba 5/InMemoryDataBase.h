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


    void setQuizzes(vector<Quiz> inQuizzes);

    //Round GetRound();
    void DeleteQuiz(Quiz inQuiz);
    void UpdateQuiz(Quiz inQuiz);
    void AddQuiz(Quiz inQuiz);



private:
    vector<Quiz> quizzes;




};

#endif // INMEMORYDATABASE_H

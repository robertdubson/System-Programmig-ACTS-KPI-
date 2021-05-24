#include <iostream>
#include <list>
#include "QuizHeader.h"

using namespace std;

Quiz::Quiz(std::string name, vector<Question> inQuestions){

    questions = inQuestions;
    quizName = name;

}

Quiz::Quiz(){}

Quiz::~Quiz(){}

vector<Question> Quiz::getQuestions(){

    return questions;

}

void Quiz::setQuestions(vector<Question> inQuestions){

    questions = inQuestions;

}

std::string Quiz::getQuizName(){

    return quizName;

}

void Quiz::setName(std::string inName){

    quizName = inName;

}
std::string Quiz::ToString(){

    return quizName;

}


int Quiz::getID(){

    return ID;

}

void Quiz::setID(int inID){

    ID = inID;

}

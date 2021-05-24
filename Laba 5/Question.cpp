#include <iostream>
#include <list>
#include "QuizHeader.h"

Question:: Question(std::string inText, vector<Variant> inVariants){

    QuestionText = inText;

    variants = inVariants;



}

Question::Question(){}

Question::~Question(){}

vector<Variant> Question::getAllVariants(){

    return variants;

}

void Question:: setVariants(vector<Variant> inVariants){

    variants = inVariants;

}

Variant Question::getRightAnwser(){

    return rightAnwser;

}

void Question::setRightAnwser(Variant inVariant){

    rightAnwser = inVariant;

}

bool Question::checkUserAnwser(Variant selectedVariant){

    if(selectedVariant.getText() == rightAnwser.getText()){

        return true;

    }
    else{

        return false;

    }

}

std::string Question::getText(){

    return QuestionText;

}

void Question::setText(std::string inText){

    QuestionText = inText;

}

int Question::getID(){

    return ID;

}

void Question::setID(int inID){

    ID = inID;

}


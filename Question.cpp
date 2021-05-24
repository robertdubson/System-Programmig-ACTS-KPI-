#include <iostream>
#include <list>
#include "QuizHeader.h"

Question:: Question(std::string inText, vector<Variant> inVariants, Variant inRightAnwser){

    QuestionText = inText;

    variants = inVariants;

    rightAnwser = inRightAnwser;

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






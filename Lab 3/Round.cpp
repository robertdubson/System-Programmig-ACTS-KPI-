#include <iostream>
#include <list>

#include "Round.h"

using namespace std;

Round::Round(){

}

Round::~Round(){}

void Round::setPlayerName(std::string inPlayerName){

    playerName = inPlayerName;
}

void Round::setRating(int inRating){

    rating = inRating;

}

std::string Round::getPlayerName(){

    return playerName;

}

int Round::getRating(){

    return rating;

}

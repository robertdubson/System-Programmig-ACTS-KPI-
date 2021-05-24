#include <iostream>
#include <list>
#include "QuizHeader.h"

using namespace std;

Variant::Variant(){


}

Variant:: Variant(std::string inText){

    Text = inText;

}

Variant::~Variant(){


}

std::string Variant:: getText(){

    return Text;

}

void Variant::setText(std::string inText){

    Text = inText;

}



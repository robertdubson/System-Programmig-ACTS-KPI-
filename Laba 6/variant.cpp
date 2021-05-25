#include "variant.h"

#include <iostream>
#include <list>


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

int Variant::getID(){

    return ID;

}

void Variant::setID(int inID){

    ID = inID;

}

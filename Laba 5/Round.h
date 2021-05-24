#ifndef ROUND_H
#define ROUND_H
#include <iostream>
#include <list>
#include "QuizHeader.h"

class Round{

private:
    std::string playerName;
    int rating;
public:
    bool operator == (const  Round& s) const { return playerName == s.playerName; }
        bool operator != (const  Round& s) const { return !operator==(s); }
    Round();
    ~Round();
    Round(std::string inPlayerName, int inRating);
    std::string getPlayerName();
    void setPlayerName(std::string inPlayerName);
    int getRating();
    void setRating(int inRating);

};
#endif // ROUND_H

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "InMemoryDataBase.h"
class Controller{

public:
    Controller();
    ~Controller();
    Controller(InMemoryDataBase inDB);


private:
    void DisplayData();


};
#endif // CONTROLLER_H

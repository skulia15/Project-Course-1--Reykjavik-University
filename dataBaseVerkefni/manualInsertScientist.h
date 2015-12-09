#ifndef COMPUTERS_H
#define COMPUTERS_H
#include "connectiontodatabase.h"
#include <iostream>
#include <string>
using namespace std;

class Scientists{
public:
    Scientists();
    void manualInput();
    void deleteScientist();
    //friend ostream& operator<<(ostream& out, Computers acc);
private:
    string id;
    string firstName;
    string lastName;
    string sex;
    int YoB;
    int YoD;

    string nameOfCpuBuilt;
};

#endif //COMPUTERS_H

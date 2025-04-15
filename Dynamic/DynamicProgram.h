#ifndef DYNAMICPROGRAM_H_INCLUDED
#define DYNAMICPROGRAM_H_INCLUDED
#include"KnapsackData.h"
using namespace std;

class DynamicProgramm
{
private :
    int Value;

public :
    DynamicProgramm();
    void searchSolution(int*,int*,int,int);

    void printSolution(){cout << Value <<endl;}
};

#endif // DYNAMICPROGRAM_H_INCLUDED

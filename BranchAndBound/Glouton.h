#ifndef GLOUTON_H_INCLUDED
#define GLOUTON_H_INCLUDED
#include<iostream>
#include"KnapsackData.h"

using namespace :: std;
class Glouton
{
private :
    bool *solution;
    int value;
    int n;

public :
    Glouton(int);
    void serachSolution(int*,int*,int,int);
    int getValue(){return value;}
    bool* getSolution(){return solution;}
    void printSolution();
};
#endif // GLOUTON_H_INCLUDED

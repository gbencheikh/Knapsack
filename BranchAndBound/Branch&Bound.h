#ifndef BRANCH&BOUND_H_INCLUDED
#define BRANCH&BOUND_H_INCLUDED
#include"KnapsackData.h"

using namespace std;
class BranchAndBound
{
private :
    int LB;
    bool *Solution;
    int n;
public :
    BranchAndBound(int);
    void searchSolution(int*,int*,int);
    void printSolution();
};

#endif // BRANCH&BOUND_H_INCLUDED

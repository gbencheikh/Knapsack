#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED
#include"KnapsackData.h"

using namespace std;
class Core
{
public :
    int c;
    int value;
    int weight;
    bool *solution;

    Core(int,int*,int*,int);
    int V(int,int,int,int*,int*);
    void searchSolution(int*,int*,int,int);

};

#endif // CORE_H_INCLUDED

#ifndef FLOT_H_INCLUDED
#define FLOT_H_INCLUDED
#include<iostream>
#include"KnapsackData.h"
#include<list>
#include<string>

using namespace std;
struct arc
{
    int item;
    int name;
    int profit;
};
struct sommet
{
    int name;
    int weight;
    list < arc > successor;
};
struct Table
{
    int name;
    int perd;
    int dist;
    bool etat;
};
class Flot
{
private :
    list < sommet > Graph;
    int t;
public :

    void creatGraph(int,int*,int*,int);
    void printGraph();
    void searchSolution();
    ~Flot(){Graph.clear();}
} ;


#endif // FLOT_H_INCLUDED

#ifndef FLOT_H_INCLUDED
#define FLOT_H_INCLUDED
#include<iostream>
#include<list>
#include"KnapsackData.h"

using namespace std;
struct successeur
{
    int name;
    int distance;
};
struct Sommet
{
    int name; // nom du sommet
    int niv;  // indice de l'objet
    int poids; // poids du sac jusqu'à présent
    int dist;
    list<successeur> succ; //liste des successeurs
};
class Flot
{
private :
    list < Sommet > Graph; // liste d'adjacence du graphe
public :
    Flot(int n);
    void Creation(int,int*,int*,int);
    void AfficherGraph();
    void Solution();
    ~Flot(){Graph.clear();}
};

#endif // FLOT_H_INCLUDED

#include<iostream>
#include"Glouton.h"
#include"KnapsackData.h"
#include<stdlib.h>
using namespace :: std;

Glouton :: Glouton(int size)
{
    n = size;
    solution = new bool[n];
    for(int i = 0 ; i < n ; i++)
        solution[i] = 0 ;
    value = 0 ;
}
void Glouton :: serachSolution(int *p,int *w,int C,int n)
{
    // Initialization :
    int cap = 0;

    for(int i = 0 ; i < n ; i++)
        if(w[i] <= C - cap)
        {
            solution[i] = 1;
            value += p[i];
            cap += w[i];
        }
}
void Glouton :: printSolution()
{
    cout << "la solution trouve par l'algorithme glouton :"<<endl;
    for(int i = 0 ; i < n ; i++)
        cout << solution[i] << " ";
    cout << endl << "Valeur :" << value << endl;
}

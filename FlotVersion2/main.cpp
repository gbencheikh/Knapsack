#include <iostream>
#include"KnapsackData.h"
#include"Flot.h"
#include<string>
#include<ctime>
using namespace std;

int main()
{
    char T[10];
    for(int i = 0 ; i < 10 ; i++)
        T[i] = '0' + i;
    clock_t time = clock();
    for(int i = 0 ; i < 10 ; i++)
    {
        string nom;
        nom = "Instance";
        nom+=T[i];
        nom+= ".dat";
        KnapsackData data(nom);

        Flot F;
        time = clock();
        double time_lect = (double) time/CLOCKS_PER_SEC;

        F.creatGraph(data.getSize(),data.getW(),data.getP(),data.getC());
        //F.printGraph();
        F.searchSolution();
        time = clock();
        double ex = (double) time/CLOCKS_PER_SEC - time_lect;
        cout << "temps d'execution " << ex << endl;
    }
    return 0;
}

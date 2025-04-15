#include <iostream>
#include"KnapsackData.h"
#include"Glouton.h"
#include"Branch&Bound.h"
#include<ctime>
#include<string>
using namespace std;

int main()
{

    clock_t time = clock();

    char T[10];
    string nom = "Instance";
    for(int i = 0 ; i < 10 ; i++)
        T[i] = '0' + i;
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << "Instance " << i << endl;
        nom = "Instance";
        nom += T[i];
        nom += ".dat";

        KnapsackData data(nom);
        data.sortdata();
        BranchAndBound bb(data.getSize());
        time = clock();
        double time_lect = (double) time/CLOCKS_PER_SEC;
        bb.searchSolution(data.getW(),data.getP(),data.getC());
        time = clock();
        double time_bb = (double) time/CLOCKS_PER_SEC - time_lect;

        bb.printSolution();
        cout << "temps d'execution " << time_bb << endl;
    }


    return 0;
}

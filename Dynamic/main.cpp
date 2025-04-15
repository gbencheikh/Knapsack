#include <iostream>
#include<string>
#include<ctime>
#include"KnapsackData.h"
#include"DynamicProgram.h"
#include"Glouton.h"
using namespace std;

int main()
{
    char T[10];
    for(int i = 0 ; i < 10 ; i++)
        T[i] = '0' + i;
    clock_t time = clock();
    for(int i = 0 ; i <  10 ; i++)
    {
        string nom;
        nom = "Instance";
        nom += T[i];
        cout << nom << endl;
        nom += ".dat";

        KnapsackData data(nom);
        data.sortdata();
        double lecture = (double) time/CLOCKS_PER_SEC;
        DynamicProgramm dyna;
        dyna.searchSolution(data.getW(),data.getP(),data.getC(),data.getSize());
        time = clock();
        double ex = (double) time / CLOCKS_PER_SEC - lecture ;
        dyna.printSolution();
        cout << "temps d'exxecution : "<< ex << endl;
    }

    return 0;
}

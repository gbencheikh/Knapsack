#include <iostream>
#include"KnapsackData.h"
#include"Flot.h"
#include<stdlib.h>
#include<string>
#include<ctime>
using namespace std;

int main()
{
    char T[10];
    for(int i = 0 ; i < 10 ; i++)
        T[i]='0' + i;
    clock_t time = clock();
    for(int i = 0 ; i < 10 ; i++)
    {
        string nom;
        nom = "Instance";
        nom += T[i] ;
        cout << nom <<endl;
        nom += ".dat";
        KnapsackData data(nom);

	    Flot graph(data.getSize());
	    time = clock();
	    double lecture = (double) time / CLOCKS_PER_SEC;
	    graph.Creation(data.getSize(),data.getW(),data.getP(),data.getC());
        //graph.AfficherGraph();
        graph.Solution();
        time = clock();
        double ex = (double) time/CLOCKS_PER_SEC - lecture ;
        cout << "temps d'execution " << ex << endl;
        graph.~Flot();
    }


    return 0;
}

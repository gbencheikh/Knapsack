#include <iostream>
#include"KnapsackData.h"
#include"Core.h"
#include<ctime>
#include<string>

using namespace std;

int main()
{
    char T[10];
    for(int i = 0 ; i < 10 ; i++)
        T[i] = '0' + i ;
    clock_t time = clock();
    for(int i = 0 ; i < 10 ; i++)
    {
        string nom;
        nom = "Instance";
        nom += T[i] ;
        cout << nom << endl;
        nom += ".dat";
        KnapsackData data(nom);
        data.sortdata();
        data.AffichageDesDonnees();

        int *p = new int[data.getSize()];
        int *w = new int[data.getSize()];
        for(int i = 0 ; i < data.getSize() ; i++)
        {
            w[i] = data.getValueW(i);
            p[i] = data.getValueP(i);
        }
        double lecture = (double) time / CLOCKS_PER_SEC;
        Core C(data.getSize(),w,p,data.getC());
        time = clock();
        C.searchSolution(w,p,data.getSize(),data.getC());
        double ex = (double) time / CLOCKS_PER_SEC - lecture ;
        cout << "temps d'execution : " << ex << endl;
    }
    cout << "\a";

    return 0;
}

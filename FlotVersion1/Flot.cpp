#include<iostream>
#include<list>
#include<stack>
#include"Flot.h"
#include"KnapsackData.h"
#include<stdlib.h>

using namespace std;
struct Table
{
    int name;
    int d;
    int perd;
    bool x;
};
Flot :: Flot(int n)
{
    Sommet element;
    element.name = -1;
    element.niv = n;
    element.poids = 0;
    element.dist = 0;
    Graph.push_back(element);
}
void Flot :: Creation(int n, int *w , int *p, int W)
{
    stack<Sommet> pile;
    //Initialisation des sommets sources
    Sommet start;
    start.name = 0; start.niv = -1; start.poids = 0;

    pile.push(start); // pile des sommets en cours de traitement
    int nom = 1;

    while(!pile.empty())
    {
        Sommet elem = pile.top();
        pile.pop();
        if(elem.niv < n-1)
        {
            if(elem.poids + w[elem.niv+1] <= W)
            {
                successeur ajout;
                ajout.name = nom; nom++;
                ajout.distance = p[elem.niv+1];
                elem.succ.push_back(ajout); // ajouter ce nouveau sommet à la liste des successeur du sommet en cours de traitement

                Sommet nouveau;
                nouveau.name = ajout.name;
                nouveau.niv = elem.niv+1;
                nouveau.poids = (elem.poids) + w[elem.niv+1];
                pile.push(nouveau);
            }
            successeur ajout;

            ajout.name = nom; nom++;
            ajout.distance = 0;
            elem.succ.push_back(ajout);
            Sommet nouveau;

            nouveau.name = ajout.name;
            nouveau.niv = elem.niv + 1 ;
            nouveau.poids = (elem.poids);
            pile.push(nouveau);

            Graph.push_back(elem);
        }
        if(elem.niv == n-1)
        {
            successeur ajout;
            ajout.name = -1;
            ajout.distance = 0;
            elem.succ.push_back(ajout);

            Graph.push_back(elem);
        }
    }
}
void Flot :: AfficherGraph()
{
    cout << "Affichage du Graphe :" << endl;
    list<Sommet>::iterator it;
    for(it = Graph.begin(); it!=Graph.end();++it)
    {
        cout << it->name << ": ";
        for(list<successeur> :: iterator it2 = (it->succ).begin();it2 != (it->succ).end() ; ++it2)
            cout << it2->name << "(" << it2->distance << ") " ;
        cout<<endl;
    }
}
void Flot :: Solution()
{
    list<Table> l;
    list<Table> pile;
    for(list<Sommet>::iterator it = Graph.begin() ; it != Graph.end() ; ++it)
    {
        Table elem;
        elem.name = it->name;
        elem.perd = -2;

        if(it->name == 0)
        {
            elem.d = 0;
            elem.x = true;
            pile.push_back(elem);
        }
        else
        {
            elem.d = -100;
            elem.x = false;
        }
        l.push_back(elem);
    }
    while(!pile.empty())
    {
        list<Table>::iterator max = pile.begin();
        for(list<Table>::iterator it = pile.begin() ; it != pile.end() ; ++it)
            if(max-> d < it-> d )
                max = it;
        for(list<Sommet>::iterator it = Graph.begin() ; it != Graph.end() ; ++it) // Search for this node in the Graph
            if(it->name == max->name)
            {
                for(list<successeur>::iterator it2 = (it->succ).begin() ; it2 != (it->succ).end() ; ++it2) // get its successors
                {
                    for(list<Table>::iterator it3 = l.begin() ; it3 != l.end() ; ++it3) // check if they have been visited or not
                    {
                        if(it2->name == it3->name && it3->x == false) // if its successor has not been visited yet
                        {
                            it3->x = true;
                            it3->perd = it->name;
                            it3->d = max->d + it2->distance; // it distance is equal to the distance of its father and the distance between each other
                            pile.push_back(*it3); // add it to the list of nodes to treat
                        }
                        if(it2->name == it3->name && it3->d < max->d + it2->distance ) // if it exist a longer way to get to this node
                        {
                            it3->d = max->d + it2->distance;
                            it3->perd = it->name;
                        }
                    }
                }
            }
        pile.erase(max);
    }

    for(list<Table>::iterator it = l.begin() ; it != l.end() ; ++it)
        if(it->name == -1)
           cout << "solution : " << it->d << endl;
    list<Table>::iterator it = l.begin();
    while( it != l.end() )
    {
        list<Table>::iterator it2 = it;
        ++it;
        l.erase(it2);
    }
}

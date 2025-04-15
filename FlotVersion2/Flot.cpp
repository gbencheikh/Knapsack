#include<iostream>
#include<stack>
#include"KnapsackData.h"
#include"Flot.h"
#include"stdlib.h"
using namespace std;

void Flot :: creatGraph(int n,int *w, int *p, int W)
{
    sommet source;
    source.name = 0;
    source.weight = 0;
    int name= 1;
    Graph.push_back(source);

    for(int i = 0 ; i < n ; i++)
    {
        list<sommet> pile;
        for(list<sommet>::iterator it = Graph.begin() ; it != Graph.end() ; ++it)
        {
            if(it->weight + w[i] <= W)
            {
                sommet newS; arc newA;

                newA.name= name;
                newA.profit = p[i];
                newA.item = i;
                (it->successor).push_back(newA);

                newS.name = name; name++;
                newS.weight = it->weight + w[i];

                pile.push_back(newS);
            }
        }
        for(list<sommet>::iterator it = pile.begin() ; it != pile.end() ; ++it)
        {
            Graph.push_back(*it);
        }

    }
    sommet puits;
    puits.weight = W;
    puits.name = name;
    t = name;

    arc finalA;
    finalA.item = n;
    finalA.name = name;
    finalA.profit = 0;

    for(list<sommet>::iterator it = Graph.begin() ; it != Graph.end() ; ++it)
    {
        (it->successor).push_back(finalA);
    }
    Graph.push_back(puits);
}
void Flot::printGraph()
{
    cout << "name(weight) : (name,item,successor1) (name,item,successor2) etc"<<endl;
    for(list<sommet>::iterator it = Graph.begin() ; it != Graph.end() ; ++it)
    {
        cout << it->name << "(" << it->weight << ") : ";
        for(list<arc>::iterator it2 = (it->successor).begin() ; it2 != (it->successor).end() ; ++it2)
            cout << "(" << it2->name << "," << it2->item << "," << it2->profit << ") ";
        cout << endl;
    }
}
void Flot::searchSolution()
{
    list<Table> T;
    list<Table> pile;
    for(list<sommet>::iterator it = Graph.begin() ; it != Graph.end() ; ++it)
    {
        Table element;
        element.name = it-> name;
        element.perd = -1;
        if(it->name == 0)
        {
            element.dist = 0;
            element.etat = true;
            pile.push_back(element);
        }
        else
        {
            element.dist = -100;
            element.etat = false;
        }
        T.push_back(element);
    }
    bool fin = false;
    while(!pile.empty() && fin == false)
    {
        list<Table>::iterator maximum = pile.begin();                            //
        for(list<Table>::iterator it = pile.begin() ; it != pile.end() ; ++it)   //the farest summit
            if(maximum->dist < it->dist)                                         //
                maximum = it;                                                    //
        if(maximum->name == t)
            fin = true;
        else
        {
            list<sommet>::iterator element = Graph.begin() ; //
            while(element->name != maximum->name)            // search for this element in the graph
                ++element;                                   //

            for(list<arc>::iterator it = (element->successor).begin() ; it != (element->successor).end() ; ++it) // get its successors
            {
                list<Table>::iterator it2 = T.begin();
                while(it2->name != it->name)
                    ++it2;

                if(maximum->dist + it->profit > it2->dist)
                {
                    it2->dist = maximum->dist + it->profit;
                    it2->perd = maximum->name;


                    if(it2->etat == false)
                    {
                        pile.push_back(*it2);
                        it2->etat = true;
                    }
                }
            }
            pile.erase(maximum);
        }
    }

    list<Table>::iterator it=T.begin();
    for(list<Table>::iterator it = T.begin(); it != T.end() ; ++it)
        if(it->name == t )
        {
           cout << "Solution : " << it->dist << endl;
           break;
        }
}

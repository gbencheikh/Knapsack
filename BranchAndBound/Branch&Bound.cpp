#include<iostream>
#include"Branch&Bound.h"
#include"Glouton.h"
#include"Noeud.h"
#include<stack>
#include<stdlib.h>
#include"KnapsackData.h"

using namespace std;
int UB(int level, int *p,int *w, int W,int n)
{
    int cap , i , Z;
    cap = 0;
    Z = 0 ;
    /*
    i = level;
    while(cap != W)
    {
        if(cap + w[i] > W)
        {
            Z += p[i]*(W - cap)/w[i];
            cap = W;
        }
        else
        {
            Z+= p[i];
            cap += w[i];
            i++;
        }
    }*/
    for(int i = level+1 ; i < n ; i++ )
        Z+= p[i];
    return Z;
}
BranchAndBound :: BranchAndBound(int size)
{
    n = size;
    Solution = new bool[n];
    LB = 0 ;
}
void BranchAndBound :: searchSolution(int *W,int *P,int C)
{
    Glouton approximation(n);

    approximation.serachSolution(P,W,C,n);
    LB = approximation.getValue();

    Solution = approximation.getSolution();
    approximation.printSolution();
    //printSolution();
    stack<Noeud> arbre;
    Noeud root; // creat the root of the tree which is a node
    // Initialization
    root.setStage(-1);
    root.setWeight(0);
    root.setValue(0);
    arbre.push(root);

    while(!arbre.empty())
    {
        bool exist = false; // to check if we the last object has been added to the list or not
        Noeud node = arbre.top(); // get the first element of the list of nodes
        arbre.pop();
        if(node.getStage() == n-1) // if is's a leaf
        {

            if(node.getValue() > LB) // check if it's a better solution
            {
                LB = node.getValue();
                Solution = node.getChoice();
            }
        }
        else
        {
            if(LB < node.getValue() + UB(node.getStage()+1 , P , W , C-node.getWeight() , n)) // check if this node can have a better solution
                if(node.getWeight() + W[node.getStage() + 1 ] <= C) // check if the object can be fitted into the knapsack
                {
                    Noeud newNode;
                    newNode.create(node,true,W[node.getStage() + 1],P[node.getStage()+1]);
                    arbre.push(newNode);
                    if(node.getStage() == n-2)
                       exist = true;
                }
            if(node.getStage() < n-2 || (node.getStage() == n-2 && exist == false) ) // to avoid some unnecessary nodes (explanation is in the report )
            {
                Noeud newNode;
                newNode.create(node,false,W[node.getStage()],P[node.getStage()] );
                arbre.push(newNode);
            }
        }
    }
}
void BranchAndBound :: printSolution()
{
    cout << "la solution trouve par l'algorithme branch and bound :"<<endl;
    for(int i = 0 ; i < n ; i++)
        cout << Solution[i] << " ";
    cout << endl << "Valeur :" << LB << endl;
}

#include<iostream>
#include<stdlib.h>
#include"KnapsackData.h"
#include"DynamicProgram.h"
#include"Glouton.h"

using namespace std;
int maximum(int a , int b){ return (a > b)? a : b;}
int max3(int a,int b,int c)
{
    if(a > b && a > c)
        return a;
    if(b > c && b > a)
        return b;
    if(c > a && c > b)
        return c;
}
int max4(int a,int b,int c ,int d)
{
    if(a > b && a > c && a > d)
        return a;
    if(b > a && b > c && b > d)
        return b;
    if(c > a && c > b && c > d)
        return c;
    if(d > a && d > b && d > c)
        return d;
}

DynamicProgramm :: DynamicProgramm()
{
    Value = 0 ;
}

int V(int k, int b,int *w,int *p)
{
    if(k == 0 || b == 0)
        return 0;
    else{
        if(w[k-1] > b)
            return V(k-1,b,w,p);
        else
            return maximum(V(k-1,b,w,p),V(k-1,b-w[k-1],w,p) + p[k-1]);
    }

}
void DynamicProgramm :: searchSolution(int *W,int *P,int C,int n)
{
    Value = V(n,C,W,P);
}

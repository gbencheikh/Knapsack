#include"KnapsackData.h"
#include"Core.h"
#include<iostream>
#include<stdlib.h>

using namespace std;
int max2(int a, int b,int *i)
{
    // i c'est l'indice du max
    if (a > b )
    {
        *i = 1;
        return a;
    }
    *i = 2;
    return b;
}
int max3(int a, int b,int c,int *i)
{
    if(a > b && a > c)
    {
        *i = 1;
        return a;
    }

    if(b > a && b > c)
    {
        *i = 2;
        return b;
    }
    *i = 3;
    return c;
}
int max4(int a, int b, int c, int d, int *i)
{
    if(a > b && a > c && a > d)
    {
        *i = 1;
        return a;
    }

    if(b > a && b > c && b > d)
    {
        *i = 2;
        return b;
    }

    if(c > a && c > b && c > d)
    {
        *i = 3;
        return c;
    }

    *i = 4;
    return d;
}
Core :: Core(int n, int *w, int *p, int W)
{
    solution = new bool[n];
    for(int i = 0 ; i < n ; i++ )
        solution[i] = 0;
    int i = 0 ;
    int poids = 0;
    value = 0;
    while(poids + w[i] <= W)
    {
        value += p[i];
        poids += w[i];
        solution[i] = 1;
        i++;
    }
    c = i+1;
    weight = poids;
}
int Core::V(int a, int b, int d , int *w,int *p )
{
    if(a == c && b == c-1)
    {
        return value;
    }

    if( a != c && b != c-1)
    {
        int xa1, xa0, xb1, xb0;
        xa1 = V(a+1,b,d,w,p);
        xa0 = V(a+1,b,d+w[a],w,p)-p[a];
        xb0 = V(a,b-1,d,w,p);
        if(w[b] <= d)
        {
            int i=0;
            xb1 = V(a,b-1,d-w[b],w,p)+p[b];
            int sol = max4(xa1,xa0,xb1,xb0,&i);
            if(i == 2 )
                solution[a] =0;
            if(i == 3)
                solution[b] = 1;
            return sol;
        }
        else
        {
            int i=0;
            int sol = max3(xa1,xa0,xb0,&i);
            if(i == 2)
                solution[a] = 0;
            return sol;
        }

    }
    if(a == c && b != c-1)
    {
        int xb0;
        xb0 = V(a,b-1,d,w,p);
        if(w[b] <= d)
        {
            int xb1;
            int i = 0;
            xb1 = V(a,b-1,d-w[b],w,p)+p[b];
            int sol = max2(xb1,xb0,&i);
            if( i == 1)
                solution[b] = 1;
            return sol;
        }
        return xb0;
    }
    if(b==c-1 && a != c)
    {
        int xa0,xa1;
        int i = 0;
        xa1 = V(a+1,b,d,w,p);
        xa0 = V(a+1,b,d+w[a],w,p)-p[a];
        int sol = max2(xa1,xa0,&i);
        if( i == 2)
            solution[a] = 0;
        return sol ;
    }
}
void Core :: searchSolution(int *w,int *p,int n,int W)
{
    cout << "c = " << c << "Vlaue = " << value << "weight = " << weight << " W = " << W << endl;
    cout <<  V(0,n-1,W-weight,w,p) << endl;
    cout << "x = ";
    for(int i = 0 ; i < n ; i++)
        cout << solution[i] << " ";
}

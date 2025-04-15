#ifndef KNAPSACKDATA_H_INCLUDED
#define KNAPSACKDATA_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

class KnapsackData{
private :

	int *p;
	int *w;
	int size;
	int C;

public :

	KnapsackData(string file){

	    ifstream lect(file.c_str(),ios::in);

		size=-1; // plus facile à débuger si bug lecture
        if(!lect.fail())
        {
           char c;
   		   lect >> c >> c >> size >> c; // lecture de la taille
           lect >> c >> c >> C >> c; // lecture de la capacité

		   p = new int [size];  // allocation des tableau dans la mémoire
		   w = new int [size];

		   lect >> c >> c >> c;
           for (int i = 0; i < size; i++)
               lect >> w[i] >> c;
           lect >> c ;

           lect >> c >> c >> c;
           for (int i = 0; i < size; i++)
               lect >> p[i] >> c;
           lect >> c ;
           lect.close();
        }
	}

	~KnapsackData(){
		delete[] p;
		delete[] w;
	}

	/* retourne les donnees du tableau des poids */
	int* getW(){return w;}
	int getValueW(int i){return w[i];}
	/* retourne les donnees du tableau des profis */
	int* getP(){return p;}
	int getValueP(int i){return p[i];}
	/* retourne la taille du probleme lu */
	int getSize() const{return size;}
	/* retoune la Capacité maximal du sac */
	int getC() const {return C;}

	void AffichageDesDonnees(){
	    cout <<"nombre d'objets = " << size << endl;
        cout << "capacite du sac  = " << C << endl;
        cout << "W = ";
	    for(int i = 0 ; i < size ; i++)
           cout << w[i] << " ";
        cout << endl ;
        cout << "P = ";
        for(int i = 0 ; i < size ; i++)
           cout << p[i] << " ";
        cout << endl;
	}
};

#endif // KNAPSACKDATA_H_INCLUDED

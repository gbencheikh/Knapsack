#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED

class Noeud
{
private :
    int stage;
    int weight;
    int value;
    bool *choice;
public :

    /* the seters */
    void setStage(int s){stage = s;}
    void setWeight(int w){weight = w;}
    void setValue(int v){value = v;}
    void setchoice(bool x)
    {
        choice = new bool[stage+1];
        for(int i = 0 ; i < stage ; i++)
            choice[i] = 0 ;
        choice[stage] = x;
    }
    void setPreviousChoices(bool *tab)
    {
        for(int i = 0 ; i < stage ; i++)
            choice[i] = tab[i];
    }
    /* the geters */
    int getStage(){return stage;}
    int getWeight(){return weight;}
    int getValue(){return value;}
    bool* getChoice(){return choice;}
    bool getChoiceValue(int i){return choice[i];}

    /* Create a new node from its father */
    void create(Noeud father, bool decision, int w, int p)
    {
        stage = father.getStage() + 1;
        weight = decision*w + father.getWeight();
        value = decision*p + father.getValue();
        choice = new bool[stage+1];
        for(int i= 0 ; i < stage ; i++)
            choice[i] = father.getChoiceValue(i);
        choice[stage] = decision;
    }
};

#endif // NOEUD_H_INCLUDED

#include <iostream>
#include <string>
#include "Creation.h"
#include "Participant.h"
#pragma once
using namespace std;

class Resultat
{
    Creation creation;
    Participant participant;
    int note ;
public :
    Resultat();
    Resultat(Creation,Participant,int);
    ~Resultat(void);
    void afficher();
    void saisir();
    Creation getCreation();
    Participant getPartcipant();
    int getNote();
    friend istream& operator >>(istream&,Resultat&);
    friend ostream& operator << (ostream&,Resultat&);
    bool operator<(const Resultat&);

};

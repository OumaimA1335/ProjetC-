#include <iostream>
#include <string>
#include <vector>
#include<list>
#include <map>
#pragma once
#include "Resultat.h"
#include "Personne.h"
#include "Evenement.h"
#include "Participant.h"
#include "Creation.h"
#include "Atelier.h"
#include "Artisant.h"
using namespace std;
class Congre
{
    string nom;
    string local;
    string date;
    vector <Personne*> TabPersonne;
    vector<Evenemnet<int>*>TabEvenemnet;
    list<Resultat*>TabResultat;
public :
    Congre();
    Congre(string,string,string);
    void RemplirTabPersonne();
    void RemplirTabEvenemnet();
    void remplirTabResultat();
    Congre(const Congre&);
    ~Congre(void);
    void afficher();
    friend istream& operator >>(istream&,Congre&);
    friend ostream& operator<<(ostream&,Congre&);
    Congre&  operator=(const Congre&);
    map<int,Creation> CreationGangants();
    map<int,Creation>::iterator findCreationGagnante(int);

};


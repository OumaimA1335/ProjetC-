#include "Evenement.h"
#include "Artisant.h"
#include "Creation.h"
#include <iostream>
#pragma once
#include <string>
#include<vector>
#include <map>
#include<algorithm>
using namespace std;
class Atelier : public Evenemnet<int>
{
protected:

    map <int,Creation> TabCreation;
public :
    Atelier();
    Atelier(string,string,int);
    ~Atelier(void);
    void afficher();
    void saisirEvenement();
    void ajouterCreation();
    void supprimeCreation(int);
    friend istream& operator >>(istream&,Atelier&);
    friend ostream& operator<<(ostream&,Atelier&);
    Atelier&  operator=(const Atelier&);
    map<int,Creation>::iterator rechercher(int);
    void modifierCreations(int,string);


} ;

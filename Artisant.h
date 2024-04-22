#include <iostream>
#include <string>
#include "Personne.h"
#include "Stand.h"
#include "MyException.h"
#include <algorithm>
#pragma once
using namespace std;

class Artisant : public Personne
{
    string specialite ;
    vector <Stand*> TabStand;
public :
    Artisant();
    Artisant(string,string,string,string);
    Artisant(const Artisant&);
    ~Artisant(void);
    void afficher();
    void ajouterStand();
    void supprimerStand(int);
    void saisirPersonne();
    bool findStand(const Stand&);
    void TriStand();
    friend ostream& operator<<(ostream&,Artisant&);
    friend istream& operator>> (istream&,Artisant&);
    Artisant& operator =(const Artisant&);



};

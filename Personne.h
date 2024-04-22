#include <iostream>
#include <string>
#include "Connexion.h"
#include <vector>
using namespace std;
#pragma once;

class Personne
{
protected :

    string nom;
    string prenom;
    string address_mail;
    vector <Connexion*> TabConnexion;
public :
    Personne();
    Personne(string,string,string);
    Personne(const Personne&);
    virtual ~Personne(void);
    virtual void afficher()=0;
    virtual void saisirPersonne()=0;
    void ajouterConnexion();
    Personne&  operator=(const Personne&);
    friend ostream& operator <<(ostream&,Personne&);
    friend istream& operator >>(istream&,Personne&);



};

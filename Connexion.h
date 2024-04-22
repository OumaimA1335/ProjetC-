#include <iostream>
using namespace std ;
#pragma once

class Connexion
{
    int date;
    float duree;
public :
    Connexion(int,float);
    Connexion();
    ~Connexion(void);
    void saisirConnexion();
    void afficher();
    int GetDate();
    float GetDuree();
    friend ostream& operator<<(ostream&,Connexion&);
    friend istream& operator>>(istream&,Connexion&);

};

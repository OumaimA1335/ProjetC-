#include <iostream>
#include <string>
#pragma once
using namespace std ;
class Stand
{
    static int numStand;
    string nom;
public :
    Stand();
    Stand(string);
    ~Stand(void);
    void afficher();
    void setNom(string);
    string getNom();
    static void afficherNbStand();
    void saisir();
    friend ostream& operator<<(ostream&,Stand&);
    friend istream& operator>>( istream&,Stand&);
    bool operator == (const Stand&);
    bool operator<(const Stand&);

} ;

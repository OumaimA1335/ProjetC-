#include <iostream>
#include <string>
#include <fstream>
#include "Artisant.h"

#pragma once
using namespace std ;
class Creation
{
    string nom;
    string photo;
    string dimensions;
    string description;
    Artisant artisant;

public :
    Creation*suivant;
    Creation();
    Creation(string,string,string,string);
    ~Creation(void);
    void afficher();
    void saisirCreation();
    void setDimensions(string);
    friend ostream& operator<<(ostream&,Creation&);
    friend istream& operator>>(istream&,Creation&);



};


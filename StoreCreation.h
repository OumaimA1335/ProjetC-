#pragma once
#include "Creation.h"
#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class StoreCreation
{
    Creation*premier;
    Creation*courant;
public:
    StoreCreation(void);
    ~StoreCreation(void);
    static void creer(fstream&);
    void enregistrer();
    void inserer(Creation*);
    void supprimer();
    static void supprimer(fstream&,int);
    friend ostream& operator<<(ostream&, StoreCreation&);
    friend istream& operator>>(istream&,StoreCreation&);
    friend istream& operator>>(istream&,StoreCreation*);
    friend ostream& operator<<(ostream&,StoreCreation*);




};

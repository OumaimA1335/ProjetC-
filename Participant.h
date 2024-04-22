#include <iostream>
#include "Personne.h"
#pragma once
using namespace std;
 class Participant : public Personne
 {
     int codeParticipant ;
 public :
    Participant();
    Participant(string ,string,string,int);
    ~Participant(void);
    void saisirPersonne();
    void afficher();
    friend ostream& operator<<(ostream&,Participant&);
    friend istream& operator>>(istream&,Participant&);
 };

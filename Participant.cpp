#include <iostream>
#include "Participant.h"
#include "Personne.h"
using namespace std;

Participant::Participant():Personne()
{
    codeParticipant =0;
}
Participant::Participant(string nom ,string prenom ,string adresee_mail,int code):Personne(nom,prenom,adresee_mail)
{
    codeParticipant =code;
}
Participant::~Participant()
{
    cout<<"Appelle du destructeur \n"<<endl;
}
void Participant::afficher()
{
    Personne::afficher();
    cout<<" le code de participant est "<<codeParticipant<<endl;
}
void Participant::saisirPersonne()
{
    Personne::saisirPersonne();
    cout<<"Donnez le code de participant"<<endl;
    cin>>codeParticipant;
}
ostream& operator <<(ostream& out , Participant& par)
{
    Personne *p=&par;
    out<<*p;
    out<<"le code de participant est "<<par.codeParticipant<<endl;
    return out ;
}
istream& operator>>(istream& in , Participant& par)
{
    Personne *p =&par;
    in>>*p;
    cout<<"Donnez le code de participant"<<endl;
    in>>par.codeParticipant;
    return in;
}



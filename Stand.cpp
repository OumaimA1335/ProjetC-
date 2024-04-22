#include "Stand.h"
using namespace std ;
int Stand::numStand=0;
Stand::Stand()
{
    nom="";
    numStand++;
}
Stand::Stand(string nom)
{
    this->nom=nom;
    numStand++;
}
Stand::~Stand()
{
    cout<<"Appelle du destructeur"<<endl;
}
void Stand::saisir()
{
    cout<<"Donnez le nom de stand "<<endl;
    cin>>nom;
}
void Stand::afficher()
{
   // cout<<"le numéro de stand est "<<numStand<<endl;
    cout<<"Le nom de stand est " <<nom<<endl;
}
void Stand::afficherNbStand()
{
    cout <<"Le nombre des stand est "<<numStand<<endl;
}
void Stand::setNom(string no)
{
    nom=no;
}
string Stand::getNom()
{
    return nom;
}
ostream& operator<<(ostream& out , Stand & stand)
{

    out<<"\n Le nom du stand est " <<stand.nom<<endl;
    ///out<<"Le nombre des stands est "<<stand.numStand;
    return out;
}
istream& operator >> (istream& in,Stand& stand)
{
    cout<<"Donnez le nom du stand "<<endl;
    in>>stand.nom;
    return in ;
}
bool Stand::operator==(const Stand& stan)
{
   if(numStand==stan.numStand && stan.nom==nom) return true;
   else return false;

}
bool Stand::operator<(const Stand& s){
     if(numStand<s.numStand) return true;
    else return false;
}


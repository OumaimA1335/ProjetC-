#include <iostream>
#include <string>
#include "Personne.h"
#include "Connexion.h"
using namespace std;

Personne::Personne()
{
    string resp="oui";
    this->nom="";
    this->prenom="";
    this->address_mail="";
    /*do
    {   Connexion* c = new Connexion();
        c->saisirConnexion();
        TabConnexion.push_back(c);
        cout<<"Voulez-vous ajouter une autre connexion \n "<< endl;
        cin>>resp;

    }while(resp=="oui");*/
}
Personne::Personne(string nom,string prenom,string adress_mail )
{
    string resp;
    this->nom=nom;
    this->prenom=prenom;
    this->address_mail=adress_mail;
    do
    {
        Connexion* c = new Connexion();
        c->saisirConnexion();
        TabConnexion.push_back(c);
        cout<<"Voulez-vous ajouter une autre connexion \n "<< endl;
        cin>>resp;

    }while(resp=="oui");
}
Personne::Personne(const Personne& p)
{
    nom =p.nom;
    prenom=p.prenom;
    address_mail=p.address_mail;
    for(int i =0;i<p.TabConnexion.size();i++)
    {
        TabConnexion.push_back(p.TabConnexion[i]);
    }
}
Personne::~Personne()
{
      for(int i =0;i<TabConnexion.size();i++)
    {
        delete TabConnexion[i];
    }
}
void Personne::saisirPersonne()
{
    Connexion* c;
    string resp;
    cout<<"Donnez le nom \n"<<endl;
    cin>>nom;
    cout<<"Donnez le prenom \n"<<endl;
    cin>>prenom;
    cout<<"Donnez l'adresse mail \n"<<endl;
    cin>>address_mail;
    cout<<"voulez vous ajouter une connexion \n"<<endl;
    cin>>resp;
    if(resp=="oui")
    {
    c = new Connexion();
    c->saisirConnexion();
    TabConnexion.push_back(c);
    }

}
void Personne::afficher()
{
    cout<<"Le nom est "<<nom<<" le prénom est "<<prenom<<" l'adresse mail est "<<address_mail<<endl;
    if( TabConnexion.empty())
    {
        cout<<"Il y a pas aucune connexion \n"<<endl;
    }else
    {
    cout<<"La liste de connexion de ce personne est : "<<endl;
    for(int i=0;i<TabConnexion.size();i++)
    {
      TabConnexion[i]->afficher();
    }
    }


}
void Personne::ajouterConnexion()
{
    char resp;
    Connexion* c = new Connexion();
    do
    {
        c->saisirConnexion();
        TabConnexion.push_back(c);
        cout<<"Voulez-vous ajouter une autre connexion \n "<< endl;
        cin>>resp;

    }while(resp=='oui'||resp=='OUI');
}
ostream& operator<< (ostream& out , Personne& p)
{
    out<<"\n lecture du nom "<<p.nom<<endl;
    out<<"\n lecture du prenom "<<p.prenom<<endl;
    out<<"\n lecture du adresse mail "<<p.address_mail<<endl;
    if(!p.TabConnexion.empty())
    {
    cout<<"La liste de connexion de ce personne est  "<<endl;
     for(int i=0;i<p.TabConnexion.size();i++)
    {
        cout<<*(p.TabConnexion[i]);

    }
    }
    return out;
}
istream& operator>> (istream& in , Personne& P)
{
    string resp ="";
    cout<<"Saisie de nom et prénom et adresse mail\n"<<endl;
    in>>P.nom;
    in>>P.prenom;
    in>>P.address_mail;
    cout<<"Voulez vous ajouter une connexion \n"<<endl;
    cin>>resp;
    if(resp=="oui")
    {
    Connexion *c;
    c = new Connexion();
    cin>>*c;
    P.TabConnexion.push_back(c);
    }
    return in;
}
Personne& Personne::operator= (const Personne& p)
{
    if(this!=&p)
    {
      nom=p.nom;
      prenom=p.prenom;
      address_mail=p.address_mail;
      for(int i=0;i<TabConnexion.size();i++)
      {
          delete TabConnexion[i];
      }
      TabConnexion.clear();
      for(int i=0;i<p.TabConnexion.size();i++)
      {
         TabConnexion.push_back( p.TabConnexion[i]);
      }

    }
    return *this;
}





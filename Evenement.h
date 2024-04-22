#include <iostream>
#include <string>
#include "Participant.h"
#include <vector>
#pragma once
#include "MyException.h"
using namespace std;
template <class T>
class Evenemnet;
template <class T>
istream& operator>>(istream&,Evenemnet<T>&);
template <class T>
ostream& operator<<(ostream&,Evenemnet<T>&);
template <class T>
class Evenemnet
{
protected:

    string nom;
    string emplacement;
    T date ;
    vector <Participant*> tabParticipant;
public :
    Evenemnet();
    Evenemnet(string,string,T);
    Evenemnet(const Evenemnet<T>&);
    virtual ~Evenemnet(void);
    virtual void afficher();
    void ajouterParticipant();
    void supprimerParticipant(int);
    virtual void saisirEvenement();
    friend istream& operator>> <>(istream&,Evenemnet<T>&);
    friend ostream& operator<< <>(ostream&,Evenemnet<T>&);
    Evenemnet<T>&  operator=(const Evenemnet<T>&);

};


template <class T>
Evenemnet<T>::Evenemnet(string no ,string local , T da)
{
    nom=no;
    emplacement=local;
    date=da;
}
template <class T>
Evenemnet<T>::Evenemnet (const Evenemnet<T>& event)
{
     nom =event.nom;
    emplacement =event.emplacement;
    date =event.date;
     for(int i =0;i<event.tabParticipant.size();i++)
     {
         tabParticipant.push_back(event.tabParticipant[i]);
     }
}
template <class T>
Evenemnet<T>::~Evenemnet()
{
     for(int i=0;i<tabParticipant.size();i++)
    {
       delete tabParticipant[i];
    }
    tabParticipant.clear();
}
template <class T>
void Evenemnet<T>::afficher()
{
    cout<<"le nom de l'évenement est "<<nom<<"\n"<<endl;
    cout<<"l'emplacement de l'evenement est "<<emplacement<<"\n"<<endl;
    cout<<" la date de l'evenement est "<<date<<"\n"<<endl;
    cout<<"les personnes assitées sont : \n"<<endl;
    for(int i =0;i<tabParticipant.size();i++)
     {
        tabParticipant[i]->afficher();
     }

}
template <class T>
void Evenemnet<T>::saisirEvenement()
{
    string resp ="";
    cout<<"Donnez le nom de l'évenement /n"<<endl;
    cin>>nom;
    cout<<"Donnez l'emplacement de l'evenement"<<endl;
    cin>>emplacement;
    cout<<"Donnez la date de l'evenement "<<endl;
    cin>>date;
    cout<<"Ajoutez les participants qui assisteront ce évenement \n"<<endl;
    Participant *p = new Participant();
    do
    {
          p->saisirPersonne();
          tabParticipant.push_back(p);
          cout<<"voulez vous continuer ?\n"<<endl;
          cin>>resp;
    }while(resp=="oui");
}
template<class T>
istream& operator>>(istream&in ,Evenemnet<T>& evnet)
{
    string resp ="";
    cout<<"Donnez le nom de l'évenement /n"<<endl;
    in>>evnet.nom;
    cout<<"Donnez l'emplacement de l'evenement"<<endl;
    in>>evnet.emplacement;
    cout<<"Donnez la date de l'evenement "<<endl;
    in>>evnet.date;

    cout<<"Voulez vous ajouter des participants \n "<<endl;
    cin>>resp;
    if(resp=="oui")
    {
         Participant *p;
         p = new Participant();
         cin>>*p;
         evnet.tabParticipant.push_back(p);
    }

    return in;
}
template <class T>
ostream& operator<<(ostream& out ,Evenemnet<T>& e){
     out<<"\n lecture du nom "<<e.nom<<endl;
    out<<"\n lecture du l'emplacement "<<e.emplacement<<endl;
    out<<"\n lecture de date "<<e.date<<endl;
    out<<"La liste des perrsonnes participée dans ce événement est "<<endl;
     for(int i=0;i<e.tabParticipant.size();i++)
    {
        cout<<*(e.tabParticipant[i])<<endl;;
    }
    return out;
}
template <class T>
Evenemnet<T>& Evenemnet<T>::operator= (const Evenemnet<T>& e)
{
    if(this!=&e)
    {
      nom=e.nom;
      emplacement=e.emplacement;
      date=e.date;
      for(int i=0;i<tabParticipant.size();i++)
      {
          delete tabParticipant[i];
      }
      tabParticipant.clear();
      for(int i=0;i<e.tabParticipant.size();i++)
      {
         tabParticipant.push_back( e.tabParticipant[i]);
      }

    }
    return *this;
}
template <class T>
Evenemnet<T>::Evenemnet()
{
    nom="";
    emplacement="";
}


template <class T>
void Evenemnet<T>::ajouterParticipant()
{
    string resp="";
    Participant *p = new Participant();
    do
    {
          p->saisirPersonne();
          tabParticipant.push_back(p);
          cout<<"voulez vous continuer ?/n"<<endl;
          cin>>resp;
    }while(resp=="oui");
}
template <class T>
void Evenemnet<T>::supprimerParticipant(int indice)
{
    try{
    if(tabParticipant.size()<indice) throw MyException("Indice out of range");
    tabParticipant.erase(tabParticipant.begin()+indice);
    }catch(exception&e)
    {
         cout<<"L'exeception dans la fonction supprimer participant "<<e.what()<<endl;
    }
}





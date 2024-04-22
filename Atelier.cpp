#include "Atelier.h"
#include "MyException.h"
#include <string>
using namespace std;
Atelier::Atelier()
{


}
Atelier::Atelier(string nom, string emplacement ,int date):Evenemnet<int>(nom,emplacement,date)
{

    string res="oui";
    int cle;
    Creation cre ;
    do
    {
        cre.saisirCreation();
        cout<<"Donnez la clé de la créations ? \n"<<endl;
        cin>>cle;
        pair<int,Creation> r(cle,cre);
        TabCreation.insert(r);
        cout<<"vous voulez ajouter une autre création ? \n"<<endl;
        cin>>res;

    }while(res=="faux");
}
Atelier::~Atelier()
{
map <int,Creation>::iterator it;

     for(it=TabCreation.begin();it!=TabCreation.end();it++)
    {
       TabCreation.erase(it);
    }
    TabCreation.clear();
}
void Atelier::afficher()
{   map <int,Creation>::iterator it;
    Evenemnet<int>::afficher();
    cout<<"Affichage de creation presente dans l'atelier"<<endl;
    for(it=TabCreation.begin();it!=TabCreation.end();it++)
    {
        (it->second).afficher();
    }
}
void Atelier::ajouterCreation()
{
    string res="oui";
    int cle;
    Creation cre;
    do
    {
        cre.saisirCreation();
        cout<<"Donnez la clé de la créations ? \n"<<endl;
        cin>>cle;
        pair<int,Creation> r(cle,cre);
        TabCreation.insert(r);
        cout<<"vous voulez ajouter une autre création ? \n"<<endl;
        cin>>res;

    }while(res=="oui");
}
void Atelier::supprimeCreation(int indice)
{
    try{
        if(TabCreation.size()<indice) throw MyException("Indice out of range");
        TabCreation.erase(indice);
    }catch(exception&e)
    {
        cout<<"L'exeception dans la fonction supprimer creation "<<e.what()<<endl;
    }


}
ostream& operator<<(ostream& out ,Atelier& atelier)
{
    map <int,Creation>::iterator it;
    Evenemnet<int>* a =&atelier;
    out<<*a;
    if(atelier.TabCreation.empty())
    {
    cout<<"le tableau de création est vide \n"<<endl;
    }else
    {
        cout<<"le nombre de paires "<<atelier.TabCreation.size()<<endl;
        for(it=atelier.TabCreation.begin();it!=atelier.TabCreation.end();it++)
        {
            out<<"\n la cle est"<<it->first<<endl;
            out<<"\n la valeur est "<<it->second<<endl;
        }
    }

    return out;
}
istream& operator>>(istream& in ,Atelier& atelier)
{
    string resp ;
     Creation  c;
     int cle;
     map <int,Creation>::iterator it;
     Evenemnet<int> *a =&atelier;
     in>>*a;
    do
    {
        cout<<"Donnez la clé de la création ? \n"<<endl;
        cin>>cle;
        cout<<"Donnez la valeur de la création ? \n"<<endl;
        cin>>c;
        atelier.TabCreation[cle]=c;
        cout<<"Voulez vous ajouter des créations \n"<<endl;
        cin>>resp;

    }while(resp=="oui");

   return in;

}
 Atelier& Atelier::operator=(const Atelier& ate)
 {
     map <int,Creation>::iterator it;
     int cle;
     if(this!=&ate)
     {
        // artisant = ate.artisant;
         for(it=TabCreation.begin();it!=TabCreation.end();it++)
         {
             TabCreation.erase(it);
         }
         TabCreation.clear();

         for(it=TabCreation.begin();it!=TabCreation.end();it++)
         {
             cout<<"Donnez la clé de la créations ? \n"<<endl;
             cin>>cle;
             pair<int,Creation> r(cle,it->second);
             TabCreation.insert(r);
         }
     }
     return *this;
 }
 void Atelier::saisirEvenement()
 {
      string resp;
      Creation c;
      int cle;
     Evenemnet<int>::saisirEvenement();
     do
     {

         c.saisirCreation();
         cout<<"Donnez la clé de la créations ? \n"<<endl;
         cin>>cle;
         pair<int,Creation> r(cle,c);
         TabCreation.insert(r);
         cout<<"Voulez vous ajouter une autre creation\n"<<endl;
         cin>>resp;

     }while(resp=="oui");

 }
 map<int,Creation>::iterator Atelier::rechercher(int i)
 {
     map<int,Creation>::iterator it;
      it =TabCreation.find(i);
      return it;

 }
 void Atelier::modifierCreations(int i, string dimension)
 {

 map<int,Creation>::iterator it;
 it = TabCreation.find(i);
 if(it!=TabCreation.end())
 {
     (it->second).setDimensions(dimension);
 }

 }



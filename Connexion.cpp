#include <iostream>
#include "Connexion.h"
using namespace std;
Connexion::Connexion(int date,float duree)
{
    this->date=date;
    this->duree=duree;
}
Connexion::Connexion()
{
    date=0;
    duree=0;
}
Connexion::~Connexion()
{
    cout<<"Appel du destructeur de la classe connexion \n"<<endl;
}
void Connexion::saisirConnexion()
{
    string msg="Vous devez sasir une valeur entiére";
    try{
    cout<<"Donnez la date de connexion \n"<<endl;
    cin>>date;
    cout<<"Donnez la duree de connexion \n"<<endl;
    cin>>duree;
    if(cin.fail()) throw msg;
    }catch(string msg)
    {
        cout<<"Erreur!!"<<msg<<"\n"<<endl;
    }


}
void Connexion::afficher()
{
    cout<<"la date du connexion est "<<date<<" et la duree est "<<duree<<endl;
}
int Connexion::GetDate()
{
    return date;
}
float Connexion::GetDuree()
{
    return duree;
}
ostream& operator<< (ostream& out , Connexion& con)
{
    out<<"\n lecture du date "<<con.date<<endl;
    out<<"\n lecture du duree "<<con.duree<<endl;
    return out;
}
istream& operator>> (istream& in , Connexion& con)
{
    string msg="Vous devez sasir une valeur entiére";
    cout<<"Saisie de date et durre\n"<<endl;
    try{
    in>>con.date;
    in>>con.duree;
    if(in.fail()) throw msg;
    }catch(string msg )
    {
          cout<<"Erreur!!"<<msg<<"\n"<<endl;
    }

    return in;
}


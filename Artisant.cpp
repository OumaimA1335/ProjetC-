#include "Artisant.h"
using namespace std;

Artisant::Artisant():Personne()
{

}
Artisant::Artisant(string nom, string prenom ,string adresse_mail ,string specialite):Personne(nom,prenom,adresse_mail)
{
    string resp;
    this->specialite=specialite;
    do
    {
        Stand *d;
        d = new Stand();
        d->saisir();
        TabStand.push_back(d);
    cout<<"Voulez-vous ajouter un stand \n"<<endl;
    cin>>resp;
    }while(resp=="oui");

}
Artisant::Artisant(const Artisant& art):Personne(art)
{
    specialite=art.specialite;
    for(int i=0;i<art.TabStand.size();i++)
    {
       TabStand.push_back(art.TabStand[i]);
    }

}
Artisant::~Artisant()
{
    cout<<"Appel de destructeur \n"<<endl;
}
void Artisant::saisirPersonne()
{
    string resp;

    Personne::saisirPersonne();
    cout<<"Donnez la spécialité de l'artisant\n"<<endl;
    cin>>specialite;
     do
    {
        Stand *d;
         d = new Stand();
        d->saisir();
        TabStand.push_back(d);
    cout<<"Voulez-vous ajouter un stand \n"<<endl;
    cin>>resp;
    }while(resp=="oui");

}

void Artisant::afficher()
{
   Personne::afficher();
   cout<<"la spécialite de l'artisant est "<<specialite<<"\n"<<endl;
   cout<<"les informations relative au stand de ce artisant sont \n"<<endl;
   for(int i=0 ;i<TabStand.size();i++)
   {
       TabStand[i]->afficher();
   }

}

ostream& operator<<(ostream& out ,Artisant& artisant)
{
    Personne* p =&artisant;
    out<<*p;
    out<<" \n la specialite de l'artisant est "<<artisant.specialite<<endl;
   for(int i=0 ;i<artisant.TabStand.size();i++)
   {
       out<<*(artisant.TabStand[i]);
   }
    return out;

}
istream& operator>>(istream& in ,Artisant& artisant)
{
    string resp;
    Personne* p =&artisant;
    in>>*p;
    cout<<"Donnez la spécialité de l'artisant\n"<<endl;
    in>>artisant.specialite;
    do
    {
        Stand *d;
        d = new Stand();
        cin>>*d;
        artisant.TabStand.push_back(d);
    cout<<"Voulez-vous ajouter un stand \n"<<endl;
    cin>>resp;
    }while(resp=="oui");

return in;
}
Artisant& Artisant::operator=(const Artisant& art){

    if(this!=&art)
    {
        Personne::operator=(art);
        specialite=art.specialite;
        for(int i=0 ;i<TabStand.size();i++)
        {
            delete TabStand[i];
        }
        TabStand.clear();
         for(int i=0 ;i<art.TabStand.size();i++)
        {
            TabStand.push_back(art.TabStand[i]);
        }

    }
    return *this;

}
void Artisant::ajouterStand()
{
    string resp="";
    Stand *s = new Stand();
    do
    {
          s->saisir();
          TabStand.push_back(s);
          cout<<"voulez vous continuer ?/n"<<endl;
          cin>>resp;
    }while(resp=="oui");
}
void Artisant::supprimerStand(int indice)
{
    try{
    if(TabStand.size()<indice) throw MyException("Indice out of range");
    TabStand.erase(TabStand.begin()+indice);
    }catch(exception&e)
    {
         cout<<"L'exeception dans la fonction supprimer stand "<<e.what()<<endl;
    }
}
bool Artisant::findStand(const Stand& d)
{
    vector <Stand*>::iterator it;

     it = find(TabStand.begin(),TabStand.end(),&d);
     if(it!=TabStand.end()) return true;
     else return false;

}
void Artisant::TriStand()
{
    vector <Stand*>::iterator it;
    sort(TabStand.begin(),TabStand.end());
    cout<<"l'affichage de stand triee \n"<<endl;
    for(it =TabStand.begin();it!=TabStand.end();it++)
    {
        cout<<**it<<endl;
    }

}


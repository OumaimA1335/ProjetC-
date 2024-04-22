#include "StoreCreation.h"
using namespace std;

StoreCreation::StoreCreation(void)
{
    premier=NULL;
    courant=NULL;
}
StoreCreation::~StoreCreation(void)
{
    while(premier!=NULL)
        supprimer();
}
void StoreCreation::creer(fstream& f)
{
    f.open("D:\\fichierCreation.txt",ios::in | ios::out | ios::trunc);
    if(! f.is_open()) exit(-1);

}
void StoreCreation::enregistrer()
{
    fstream f;
    string nom;
    cout<<"Saisir le nom de fichier \n"<<endl;
    cin>>nom;
    f.open(nom,ios::in | ios::out | ios::trunc);
    if(!f.is_open()) exit(-1);
    f<<*this;
    f.close();
}
void StoreCreation::inserer(Creation*c)
{
    c->suivant=premier;
    premier=c;
}
void StoreCreation::supprimer()
{
    if(premier!=NULL)
    {
        courant=premier;
        premier=premier->suivant;
        delete courant;
    }
}
void StoreCreation::supprimer(fstream& file, int ligneAS) {
        vector<string> lignes;
        string ligne;
        int i=0;

        while (getline(file, ligne)) {
            if (i!=ligneAS) {
                lignes.push_back(ligne);
            }
            i++;
        }
        file.close();
        file.open("D:\\fichierCreation.txt", ios::out | ios::trunc);
       /* for (int j=0;j<lignes.size();i++) {
            file << lignes[j] << endl;
        }*/
    }
ostream& operator << (ostream& out , StoreCreation& c)
{
   c.courant =c.premier;
   while(c.courant!=NULL)
   {
       out<<*c.courant<<endl;
       c.courant=c.courant->suivant;
   }
   return out;
}
istream& operator >>(istream& in , StoreCreation& c)
{
   Creation* c1;
   string resp;
   do
   {

       c1 = new Creation();
       in>>*c1;
       c.inserer(c1);
       cout<<"Voulez vous ajouter une autre creation dans le store \n"<<endl;
       cin>>resp;
   }while(resp=="oui");
   return in;
}
istream& operator >>(istream& in , StoreCreation* c)
{
    Creation *c1;
    string resp;
    in.seekg(0);
        c1 = new Creation;
        in>>*c1;

        c->inserer(c1);

    return in;

}
ostream& operator<<(ostream& out,StoreCreation* c)
{
    out<<setw(10)<<c;
}


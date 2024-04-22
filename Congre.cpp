#include "Congre.h"
using namespace std;

Congre::Congre()
{
    local ="";
    nom="";
    date="";
}
Congre::Congre(string local,string nom,string date)
{
    this->local=local;
    this->nom=nom;
    this->date=date;
}
void Congre::RemplirTabPersonne()
{
    Personne *p;
    string res,choix;
    do
    {
        cout<<"Choissez un numero \n 1: Participant \n 2: Artisant \n"<<endl;
        cin>>choix;
        if(choix=="1")
        {
            p = new Participant();
            p->saisirPersonne();
            TabPersonne.push_back(p);
        }
        else
        {
            p=new Artisant();
            p->saisirPersonne();
            TabPersonne.push_back(p);
        }
        cout<<"Voulez-vous ajouter un autre personne \n"<<endl;
        cin>>res;
    }
    while(res=="oui");

}
Congre::Congre(const Congre& c)
{
    nom=c.nom;
    local =c.local;
    date =c.date;
    Personne *p;
    Evenemnet<int> *e;
    for(int i=0; i<c.TabPersonne.size(); i++)
    {
        if(typeid(*c.TabPersonne[i])==typeid(Artisant))
        {
            p= new Artisant( static_cast <const Artisant&>(*c.TabPersonne[i]));
            TabPersonne.push_back(p);
        }
        else
        {
            p= new Participant( static_cast <const Participant&>(*c.TabPersonne[i]));
            TabPersonne.push_back(p);
        }
    }
    for(int i=0; i<c.TabEvenemnet.size(); i++)
    {
        if(typeid(*c.TabEvenemnet[i])==typeid(Evenemnet<int>))
        {
            e = new Evenemnet<int>(*c.TabEvenemnet[i]);
        }
        else
        {
            e = new Atelier( static_cast < Atelier&>(*c.TabEvenemnet[i]));
        }
        TabEvenemnet.push_back(e);
    }

    for(auto it=c.TabResultat.begin(); it!=c.TabResultat.end(); it++)
    {
        TabResultat.push_back(*it);
    }

}
Congre::~Congre()
{
    for(int i=0; i<TabPersonne.size(); i++)
    {
        delete TabPersonne[i];
    }
    TabPersonne.clear();
    for(int i=0; i<TabEvenemnet.size(); i++)
    {
        delete TabEvenemnet[i];
    }
    TabEvenemnet.clear();
    for(auto it=TabResultat.begin(); it!=TabResultat.end(); it++)
    {
        delete *it;
    }
    TabResultat.clear();
}
void Congre::RemplirTabEvenemnet()
{
    Evenemnet<int> *e;
    string res,choix;
    do
    {
        cout<<"Choissez un numero \n 1: Evenement \n 2: Arelier \n"<<endl;
        cin>>choix;
        if(choix=="1")
        {
            e = new Evenemnet<int>();
            e->saisirEvenement();
            TabEvenemnet.push_back(e);
        }
        else
        {
            e= new Atelier();
            e->saisirEvenement();
            TabEvenemnet.push_back(e);
        }
        cout<<"Voulez-vous ajouter un autre evenement \n"<<endl;
        cin>>res;
    }
    while(res=="oui");
}
void Congre::remplirTabResultat()
{
    string resp,choix;
    do
    {
        Resultat* res;
        res=new Resultat();
        res->saisir();
        TabResultat.push_back(res);
        cout<<"Voulez-vous ajouter un autre resultat \n"<<endl;
        cin>>resp;

    }
    while (resp=="oui");


}
void Congre::afficher()
{
    cout<<"Le nomm de congres est "<<nom<<endl;
    cout<<"le local de congres est"<<local<<endl;
    cout<<"la date de congres est "<<date<<endl;
    cout<<"l'affichage de tableau personne :\n"<<endl;
    for(int i =0; i<TabPersonne.size(); i++)
    {
        TabPersonne[i]->afficher();
    }
    cout<<"l'affichage de tableau evenement :\n"<<endl;
    for(int i =0; i<TabEvenemnet.size(); i++)
    {
        TabEvenemnet[i]->afficher();
    }
    cout<<"l'affichage de tableau resultat :\n"<<endl;
    for(auto it=TabResultat.begin(); it!=TabResultat.end(); it++)
    {
        (*it)->afficher();
    }
}
istream& operator >>(istream&in,Congre& congre)
{
    cout<<"Saisie de nom et local et date de congre \n"<<endl;
    in>>congre.nom;
    in>>congre.local;
    in>>congre.date;
    Personne *p;
    Evenemnet<int> *e;
    Resultat *r;
    string resp,choix;
    cout<<"Remplissage du tableau personne \n"<<endl;
    do
    {
        cout<<"Tapez votre choix 1:Artisant 2:Participant \n"<<endl;
        cin>>choix;
        if(choix=="1")
        {
            p = new Artisant();
            in>>static_cast <Artisant&>(*p);
        }
        else
        {
            p = new Participant();
            in>>static_cast <Participant&>(*p);
        }
        congre.TabPersonne.push_back(p);
        cout<<"Voulez vous ajouter un autre personne\n"<<endl;
        cin>>resp;
    }
    while (resp=="oui");
    cout<<"Remplissage du tableau evenement \n"<<endl;
    do
    {
        cout<<"Tapez votre choix 1:Evenement 2:Atelier \n"<<endl;
        cin>>choix;
        if(choix=="1")
        {
            e = new Evenemnet<int>();
            in>>*e;
        }
        else
        {
            e = new Atelier();
            in>>static_cast <Atelier&>(*e);
        }
        congre.TabEvenemnet.push_back(e);
        cout<<"Voulez vous ajouter un autre evenemment\n"<<endl;
        cin>>resp;
    }
    while(resp=="oui");
    cout<<"Remplissage du tableau resultats \n"<<endl;
    do
    {   r = new Resultat();

        cin>>*r;
        congre.TabResultat.push_back(r);
        cout<<"Voulez vous ajouter un autre resultat\n"<<endl;
        cin>>resp;
    }
    while(resp=="oui");

    return in;
}
ostream& operator<< (ostream& out, Congre& congre)
{
    out<<"\n lecture du nom "<<congre.nom<<endl;
    out<<"\n lecture du local "<<congre.local<<endl;
    out<<"\n lecture du date "<<congre.date<<endl;
    out<<"La liste des personne  dans ce congre est  "<<endl;
    for(int i=0; i<congre.TabPersonne.size(); i++)
    {
        if(typeid(*congre.TabPersonne[i])==typeid(Artisant))
        {
            out<< static_cast <Artisant&> (*congre.TabPersonne[i]);
        }
        else
        {
            out<< static_cast <Participant&> (*congre.TabPersonne[i]);
        }
    }
    out<<" \n La liste des evenements  dans ce congre est  "<<endl;
    for(int i=0; i<congre.TabEvenemnet.size(); i++)
    {
        if(typeid(*congre.TabEvenemnet[i])==typeid(Evenemnet<int>))
        {
            out<< static_cast<Evenemnet<int>&>(*congre.TabEvenemnet[i]);
        }
        else
        {
            out<< static_cast<Atelier&>(*congre.TabEvenemnet[i]);
        }
    }
    out<<" \n La liste des avis sur les creations dans ce congre est  "<<endl;
    for(auto it=congre.TabResultat.begin(); it!=congre.TabResultat.end(); it++)
    {
        out<<**it<<endl;
    }
    return out;
}
Congre& Congre::operator= (const Congre& c)
{
    Personne *p;
    Evenemnet<int> *e;
    if(this!=&c)
    {
        nom=c.nom;
        local=c.local;
        date=c.date;
        for(int i=0; i<TabPersonne.size(); i++)
        {
            delete TabPersonne[i];
        }
        TabPersonne.clear();
        for(int i=0; i<TabEvenemnet.size(); i++)
        {
            delete TabEvenemnet[i];
        }
        TabEvenemnet.clear();
        for(auto it=TabResultat.begin(); it!=TabResultat.end(); it++)
        {
            delete *it;
        }
        TabResultat.clear();
        for(int i=0; i<c.TabPersonne.size(); i++)
        {
            if(typeid(*c.TabPersonne[i])==typeid(Artisant))
            {
                p = new Artisant(static_cast<Artisant&>(*c.TabPersonne[i]));
            }
            else
            {
                p = new Participant(static_cast<Participant&>(*c.TabPersonne[i]));
            }
            TabPersonne.push_back(p);
        }
        for(int i=0; i<c.TabEvenemnet.size(); i++)
        {
            if(typeid(*c.TabEvenemnet[i])==typeid(Evenemnet<int>))
            {
                e = new Evenemnet<int>(*c.TabEvenemnet[i]);
            }
            else
            {
                e = new Evenemnet<int>(static_cast<Evenemnet<int>&>(*c.TabEvenemnet[i]));
            }
            TabEvenemnet.push_back(e);
        }
        for(auto it=c.TabResultat.begin(); it!=c.TabResultat.end(); it++)
        {
            TabResultat.push_back(*it);
        }

    }
    return *this;
}

map<int,Creation> Congre::CreationGangants()
{
    int countt=0;
    map<int,Creation> m;

    TabResultat.sort();
    for ( auto it = TabResultat.begin(); it != TabResultat.end() && countt < 1; ++it, ++countt)
    {
        pair<int,Creation> r(countt,(*it)->getCreation());
        m.insert(r);

    }

    return m;
}
map<int,Creation>::iterator Congre::findCreationGagnante(int i)
{
    map<int,Creation> m = CreationGangants();
    map<int,Creation>::iterator it;

        it =m.find(i);
            return it;

}



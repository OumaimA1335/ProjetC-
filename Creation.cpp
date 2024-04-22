#include "Creation.h"
using namespace std;

Creation::Creation()
{
    nom="";
    dimensions="";
    photo="";
    description="";
    suivant =NULL;
    //operateur = sauf que lorsque la classe contirnt une partie dynamique ou non
}
Creation::Creation(string nom, string photo, string description , string dimensions)
{
    this->nom=nom;
    this->photo=photo;
    this->dimensions=dimensions;
    this->description=description;
    cout<<"Saisie du coordonnees du personne \n"<<endl;
    artisant.saisirPersonne();
    suivant =NULL;
}
Creation::~Creation()
{
    cout<<"Appell du destructeur \n"<<endl;

}
void Creation::afficher()
{
    cout<<"\n Le nom de l'artcile est "<<nom<<endl;
    cout<<"\n Le lien de photo de l'artcile est "<<photo<<endl;
    cout<<"\n Les dimensions de l'artcile sont "<<dimensions<<endl;
    cout<<"\n La description  de l'artcile est "<<description<<endl;
    cout<<"\n les coordonnes de l'artisant qui a ce article sont "<<endl;
    artisant.afficher();
}
void Creation::saisirCreation()
{
     cout<<"Donnez le nom de la création \n"<<endl;
     cin>>nom;
     cout<<"Donnez le photo de la création \n"<<endl;
     cin>>photo;
     cout<<"Donnez le dimensions de la création \n"<<endl;
     cin>>dimensions;
     cout<<"Donnez le description de la création \n"<<endl;
     cin>>description;
     cout<<"Saisie de les informations relatives au artisant \n"<<endl;
     artisant.saisirPersonne();
}
ostream& operator<< (ostream& out , Creation &creation)
{
    out<<"le nom de la création est \n"<<creation.nom<<endl;
    out<<"la photo de la création est \n"<<creation.photo<<endl;
    out<<"les dimensions de la créations sont"<<creation.dimensions<<endl;
    out<<" description sont "<<creation.description<<endl;
    out<<"les informations relative au artisant sont" <<creation.artisant<<endl;
    return out;
}

istream& operator>>(istream& in ,Creation &creation)
{
    cout<<"Donnez le nom de la création \n "<<endl;
    in>>creation.nom;
    cout<<"Donnez le photo de la création \n"<<endl;
    in>>creation.photo;
    cout<<"Donnez le dimensions de la création \n"<<endl;
    in>>creation.dimensions;
    cout<<"Donnez le description de la création \n"<<endl;
    in>>creation.description;
    cout<<"Saisir les informations relatives au artisant \n"<<endl;
    in>>creation.artisant;
    return in;
}
void Creation::setDimensions(string dim)
{
    dimensions=dim;
}

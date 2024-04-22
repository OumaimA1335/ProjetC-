#include <iostream>
#include "Participant.h"
#include "Connexion.h"
#include "Artisant.h"
#include "Stand.h"
#include "Evenement.h"
#include "Atelier.h"
#include "StoreCreation.h"
#include<fstream>
#include "Congre.h"
#include "Creation.h"
using namespace std;

int main()
{

    //cin>>a;
fstream f;
cout<<"**************Ecriture dans le fichier*******************\n"<<endl;
StoreCreation::creer(f);
StoreCreation s;
f<<&s;
/*cout<<"**************Tri un les stands*******************\n"<<endl;
s.TriStand();
/*map<int,Creation>::iterator it =e.rechercher(0);
cout<<"la creation rechercher a indice 0 est "<<(it->second)<<"\n"<<endl;
cout<<"**************Modification la dimensions  d une creation a indice 0 *******************\n"<<endl;
e.modifierCreations(0,"150*25");
cout<<"**************Affichage de l objet *******************\n"<<endl;
cout<<e;
/*Evenemnet<int> e2=e;
cout<<"**************Affichage de l oobjet 2*******************\n"<<endl;
cout<<e2;
/*Congre c2("congre 2","Tunisie","15072024");
c2.remplirTabResultat();
map<int,Creation> m = c2.CreationGangants();
map<int,Creation>::iterator it;
cout<<"**************Affichage des creation gagnate *******************\n"<<endl;
for(it=m.begin();it!=m.end();it++)
        {
            cout<<"\n la cle est"<<it->first<<endl;
            cout<<"\n la valeur est "<<it->second<<endl;
        }
        it=c2.findCreationGagnante(0);
cout<<"la creation gagnante a indice zero est"<<it->second<<"\n";
/*cout<<"**************rechercher une creation gagnante à indice 0*******************\n"<<endl;

cout<<"***************Affichage de l'objet2 de type congre  ******************\n"<<endl;
c2.afficher();
/*cout<<"***************Affichage de l'objet de type participant ******************\n"<<endl;
p.afficher();
cout<<"***************Saisie de l objet2 de type participant a laide operateur ******************\n"<<endl;
cin>>p2;
/*cout<<"**************Affichage de l'objet2 de type artisan a l aide operateur*******************\n"<<endl;
cout<<a2;

cout<<"**************Affectation a l aide l operateur = *******************\n"<<endl;
p2=p;
cout<<"**************Affichage de l'objet2 de type participant*******************\n"<<endl;
p2.afficher();*/










    return 0;
}

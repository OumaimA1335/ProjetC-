#include "Resultat.h"
using namespace std ;
Resultat::Resultat()
{
    note=0;
}
Resultat::Resultat(Creation Creation,Participant participant,int note)
{
    this->creation=creation;
    this->participant=participant;
    this->note=note;
}
Resultat::~Resultat()
{
    cout<<"Appel de destructeur /n"<<endl;
}
void Resultat::afficher()
{
    cout<<"les d�tails de cr�ation sont "<<endl;
    creation.afficher();
    cout<<"/n Les d�tails de participant sont "<<endl;
    participant.afficher();
    cout<<"/n La note attribue� est "<<note<<endl;
}
void Resultat::saisir()
{
    string msg="Vous devez sasir une valeur enti�re";
    cin>>creation;
    cin>>participant;
    try
    {
    cout<<"Attribuez une note � cette cr�ation /n"<<endl;
    cin>>note;
    if(note>20||note<0) throw -1;
    if(cin.fail()) throw msg;

    }catch(int i)
    {
        cout<<"Erreur!! vous devez saisir un entier dans intervalle de 0 � 20\n"<<endl;
    }catch(string msg)
    {
        cout<<"Erreur!!"<<msg<<"\n"<<endl;
    }

}
Creation Resultat::getCreation()
{
    return creation;
}
int Resultat::getNote()
{
    return note;
}
Participant Resultat::getPartcipant()
{
    return participant;
}

istream& operator>>(istream& in ,Resultat& res)
{
     cout<<"Saisie la creation \n"<<endl;
    in>>res.creation;
     cout<<"Saisie la participant \n"<<endl;
    in>>res.participant;
    cout<<"Attribuez une note � cette cr�ation \n"<<endl;
    in>>res.note;
    return in;
}
ostream& operator<<(ostream& out ,Resultat& res)
{
    out<<res.creation;
    out<<res.participant;
    out<<res.note;
    return out;
}
bool Resultat::operator<(const Resultat& res)
{
    if(note<res.note) return true;
    else return false;
}

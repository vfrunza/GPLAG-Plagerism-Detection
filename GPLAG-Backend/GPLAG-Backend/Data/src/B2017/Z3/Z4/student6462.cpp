#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <queue>

using namespace std;

enum class Boje
{
    Pik,Tref,Herc,Karo
};

list<pair<Boje,string>> KreirajSpil()
{
    list<pair<Boje,string>> Spil(52);
    auto it(Spil.begin());
    for(int i(0); i<4; i++) {
        for(int j(2); j<15; j++) {
            if(j<=10) {
                (*it).second=to_string(j);
                if(i==0)(*it).first=Boje::Pik;
                else if(i==1)(*it).first=Boje::Tref;
                else if(i==2)(*it).first=Boje::Herc;
                else if(i==3)(*it).first=Boje::Karo;
            } else if(j==11) {
                (*it).second="J";
                if(i==0)(*it).first=Boje::Pik;
                else if(i==1)(*it).first=Boje::Tref;
                else if(i==2)(*it).first=Boje::Herc;
                else if(i==3)(*it).first=Boje::Karo;
            } else if(j==12) {
                (*it).second="Q";
                if(i==0)(*it).first=Boje::Pik;
                else if(i==1)(*it).first=Boje::Tref;
                else if(i==2)(*it).first=Boje::Herc;
                else if(i==3)(*it).first=Boje::Karo;
            } else if(j==13) {
                (*it).second="K";
                if(i==0)(*it).first=Boje::Pik;
                else if(i==1)(*it).first=Boje::Tref;
                else if(i==2)(*it).first=Boje::Herc;
                else if(i==3)(*it).first=Boje::Karo;
            } else if(j==14) {
                (*it).second="A";
                if(i==0)(*it).first=Boje::Pik;
                else if(i==1)(*it).first=Boje::Tref;
                else if(i==2)(*it).first=Boje::Herc;
                else if(i==3)(*it).first=Boje::Karo;
            }
            it++;
        }
    }
    return Spil;
}

void provjeraSpila(list<pair<Boje,string>> &Kartaci_Spil)
{
    if(Kartaci_Spil.size()>52)throw logic_error("Neispravna lista!");
    for(auto it(Spil.begin());it!=Spil.end() ;it++) {
        if(it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo)throw logic_error("Neispravna lista!");
    
}

void IzbaciKarte(list<pair<Boje,string>> &Spil,multimap<Boje,string> mapaKarti)
{
    provjeraSpila(Spil);
    int i(2);
       // for(;i<15;i++){
        //if(it->first !=to_string(i))throw logic_error("Neispravna lista!");
    }
    for(auto it2(mapaKarti.begin()); it2!=mapaKarti.end(); it2++)
        for( auto it1(Spil.begin()); it1!=Spil.end(); it1++)
            if(it2->first==it1->first && it2->second==it1->second) {
                it1=Spil.erase(it1);
                it2=mapaKarti.erase(it2);
                it1--;
            }
}

queue<pair<string,string>> IzbaciKarteRazbrajanjem(list<pair<Boje,string>> &Spil,short int r,int b){
    if(r<1 || r>52 || b<1)throw logic_error("Neispravni elementi za izbacivanje!");
    provjeraSpila(Spil);
    
}

int main ()
{
    cout<<"Unesite korak razbrajanja: ";
    short int razbrajanje;
    cin>>razbrajanje;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int brojIzbacivanje;
    cin>>brojIzbacivanje;
    cout<<"U spilu trenutno ima "<<52-brojIzbacivanje<<" karata, i to:";
    list<pair<Boje,string>> Deck(KreirajSpil());
    
    return 0;
}
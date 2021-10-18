/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include<stdexcept>
#include <queue>
using namespace std;
enum class Boje
{
    Pik, Tref, Herc, Karo
};

vector<string> s {"Pik: ", "Tref: ", "Herc: ", "Karo: "};


typedef list<pair<Boje, string>> Spil;
list<pair<Boje, string>> KreirajSpil()
{
    list<pair<Boje, string>> lista;
    vector<string> brojevi {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            lista.push_back(make_pair(Boje(i),brojevi[j]));
        }
        cout<<endl;
    }
    return lista;
}
/* Funkcija izbaci karte radi prema sljedecem:
Izbaca karte iz spila koji se nalaze u mapi i brise karte iz mape*/

void IzbaciKarte(Spil &spil, multimap<Boje,string> &mapa)
{
    // if(spil.size()>52) throw logic_error("Neispravna lista!");
    for(auto it(spil.begin()); it!=spil.end(); it++) {
        for(auto it1(mapa.begin()); it1!=mapa.end(); it1++) {
            if((it->first==it1->first) && (it->second==it1->second)) {
                it=spil.erase(it);
                it1=mapa.erase(it1);
            }
        }
    }

}
/*Izbaci karte razbrajanjem izbaca b karata,
za svako r-to mjesto*/
queue<pair<string, string>> IzbaciKarteRazbrajanjem(Spil &spil, const short int &r, const int &b)
{
    auto it(spil.begin());
    queue<pair<string, string>> izbaceni_parovi;
    for(int i=0; i<b;i++) {
        for(int j=0; j<r; j++) {
            if(it!=spil.end()) {
            it++;
            }
           else if(it==spil.end()) {
               it=spil.begin();
           }
        }
        izbaceni_parovi.push(make_pair(s.at(int(it->first)), it->second));
        it=spil.erase(it);
    }
    return izbaceni_parovi;
}

void VratiPrvihNKarata(Spil &spil, queue<pair<string, string>> &izbaceni_parovi, int n)
{

    for(int i=0; i<n; i++) {
        //   spil.push_back(izbaceni_parovi.front());
        // izbaceni_parovi.pop();
    }

}

int main ()
{
    list<pair<Boje, string>>spil1(KreirajSpil());
    cout<<"Unesite korak razbrajanja: ";
    int korak;
    cin>>korak;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int broj_koliko_zelis_izbaciti;
    cin>>broj_koliko_zelis_izbaciti;
    multimap<Boje, string> mapa1;

    IzbaciKarte(spil1, mapa1);
    queue<pair<string, string>> parovi;

    parovi=IzbaciKarteRazbrajanjem(spil1, korak, broj_koliko_zelis_izbaciti);

    cout<<"U spilu trenutno ima "<<spil1.size()<<" karata, i to:"<<endl;
    for (int i=0; i<s.size(); i++) {
        cout<<s.at(i);
        for(auto it(spil1.begin()); it!=spil1.end(); it++) {
            cout<<it->second<<" ";
            if(it->second=="A") break;
        }
        cout<<endl;
    }
    cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int vrati;
    cin>>vrati;
     VratiPrvihNKarata(spil1, parovi, vrati);
    cout<<"U spilu trenutno ima"<<spil1.size()<<" karata, i to:"<<endl;
    for (int i=0; i<s.size(); i++) {
        cout<<s.at(i);
        for(auto it(spil1.begin()); it!=spil1.end(); it++) {
            cout<<it->second<<" ";
            if(it->second=="A") break;
        }
        cout<<endl;
    }

    return 0;
}

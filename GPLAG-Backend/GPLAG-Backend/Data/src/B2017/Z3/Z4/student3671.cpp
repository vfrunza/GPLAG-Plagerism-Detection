/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <map>
using namespace std;

enum class Boje
{
    Pik,Tref,Herc,Karo
};
typedef list<pair<Boje,string>>Spil;
typedef queue<pair<string,string>>Red;
vector<string>karte = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
vector<string>Boje_s= {"Pik","Tref","Herc","Karo"};

Spil KreirajSpil()
{
    Spil s;
    for(int i=0; i<4; i++) {
        for(int j=0; j<karte.size(); j++) {
            s.push_back(make_pair(static_cast<Boje>(i),karte[j]));
        }
    }
    return s;
}

template<typename Tip,typename kontejner>
int Index(Tip k,kontejner poc,kontejner kraj)
{
    int i=0;
    while(poc!=kraj) {
        if(*poc==k)
            break;
        i++;
        poc++;
    }
    return i;
}

template<typename Itertip>
bool NeispravanUlaz(Itertip it)
{
    if(find(karte.begin(),karte.end(),it->second)==karte.end())
        return true;
    for(int i=0; i<4; i++) {
        if(it->first==static_cast<Boje>(i))
            return false;
    }
    return true;
}

void Izuzeci(const Spil &s)
{
    if(s.size()>52 || NeispravanUlaz(s.begin())) {
        throw logic_error("Neispravna lista!");
    }
    typename Spil::const_iterator prvi_poslije {s.begin()},zadnji_prije {s.end()};
    prvi_poslije++;
    zadnji_prije++;
    typename Spil::const_iterator it=s.begin();
    while(it!=zadnji_prije) {
        if(static_cast<int>(it->first) > static_cast<int>(prvi_poslije->first)
                && Index(it->second,karte.begin(),karte.end())
                && Index(prvi_poslije->second,karte.begin(),karte.end()))
            throw logic_error("Neispravna lista!");
        it++;
    }
}

void IzbaciKarte(Spil &s,multimap<Boje,string>&mapa)
{
    Izuzeci(s);
    typename Spil::iterator pozicija;
    typename multimap<Boje,string>::iterator poc=mapa.begin();
    for(; poc!=mapa.end(); poc++) {
        pozicija=find_if(s.begin(),s.end(),[poc] (pair<Boje,string>element)->bool {
            if(element.first==poc->first && element.second==poc->second)
                return true;
            return false;
        });
        if(pozicija!=s.end()) {
            s.erase(pozicija);
            poc=mapa.erase(poc);
        }
    }
}

Red IzbaciKarteRazbrajanjem(Spil &s,short &r,int &b)
{
    if(r<1 || r>52 || b<1)
        throw logic_error("Neispravni elementi za izbacivanje!");
    Izuzeci(s);
    Red red;
    int i=0, br=1;
    while(s.size()!=0 && i!=b){
        for(typename Spil::iterator it=s.begin();it!=s.end();it++){
            if(++br==r){
                ++it;
                red.emplace(Boje_s[static_cast<int>(it->first)],it->second);
                it=s.erase(it);
                it--;
                br=1;
                i++;
            }
            if(i==b) break;
        }
    }
    return red;
}

void VratiPrvihNKarata(Spil &s,Red &red,int n)
{
    if(n<0 || n>52) throw domain_error("Broj n je besmislen!");
    if(n>red.size()) throw range_error("Nedovoljno karata u redu!");
    while(!red.empty()) {
        pair<string,string>neka_k=red.front();
        red.pop();
        if(find(karte.begin(),karte.end(),neka_k.second)==karte.end()
                || find(Boje_s.begin(),Boje_s.end(),neka_k.first)==Boje_s.end()) {
            throw logic_error("Neispravne karte!");
        }
    }
    Izuzeci(s);
}

void Ispisi(const Spil &s)
{
    cout<<"U spilu trenutno ima "<<s.size()<<" karata, i to:"<<endl;
    typename Spil::const_iterator it=s.begin();
    for(int i=0; i<Boje_s.size(); i++) {
        cout<<Boje_s[i]<<":";
        while(it!=s.end() && it->first==static_cast<Boje>(i)) {
            cout<<" "<<it->second;
            it++;
        }
        cout<<endl;
    }
}


int main ()
{
    cout<<"Unesite korak razbrajanja: ";
    short int n;
    cin>>n;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int br_karata;
    cin>>br_karata;
    try {
        Spil s {KreirajSpil()};
        Red f {IzbaciKarteRazbrajanjem(s,n,br_karata)};
        Ispisi(s);
        cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        cin>>br_karata;
        VratiPrvihNKarata(s,f,br_karata);
        Ispisi(s);
    } catch(const exception &x) {
        cout<<"Izuzetak: "<<x.what()<<endl;
    }
    return 0;
}

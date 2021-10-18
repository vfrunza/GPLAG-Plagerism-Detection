#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <exception>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using std::queue;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::pair;
vector<string> TipKarata {"Pik", "Tref", "Herc", "Karo"};
vector<string> Karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
enum class Boje {
    Pik=0,Tref=1,Herc=2,Karo=3
};
typedef std::multimap<Boje, std::string> MMapa;
typedef list<pair<Boje,string>> Spil;
Spil KreirajSpil() {
    Spil s;
    int TipKarte=0;
    while(TipKarte<=3) {
        for(int i=0; i<Karte.size(); i++)
            s.push_back(std::make_pair(static_cast<Boje>(TipKarte),Karte.at(i)));
        TipKarte++;
    }
    return s;
}
void SortirajSpil(Spil &s) {
    s.sort([](pair<Boje,string> x,pair<Boje,string> y) {
        return (int(x.first)<int(y.first) || (int(x.first)==int(y.first) &&
                                              std::find(Karte.begin(),Karte.end(),x.second)-Karte.begin() < std::find(Karte.begin(),Karte.end(),y.second)-Karte.begin()));
    });
}
bool ispravnoSortiranSpil(Spil a, const Spil &b) {
    SortirajSpil(a);
    Spil::const_iterator It1 {a.begin()}, It2 {b.begin()};
    for(int i=0; i<b.size(); i++,It1++,It2++)
        if(It1->first != It2->first || (It1->first==It2->first && It1->second != It2->second )) return false;
    return true;
}
bool validanSpil(const Spil &s) {
    Spil::const_iterator sIt {s.begin()};
    while(sIt!=s.end()) {
        bool validan {false};
        for(int i=0; i<Karte.size(); i++) {
            if(int(sIt->first)<0 || int(sIt->first)>3) {
                validan=false;
                break;
            }
            if(sIt->second==Karte.at(i)) {
                validan=true;
                break;
            }
        }
        if(!validan) return false;
        sIt++;
    }
    return true;
}
void IzbaciKarte(Spil &s, MMapa &m) {
    if(s.size()>52 || !ispravnoSortiranSpil(s,s) || !validanSpil(s))
        throw std::logic_error("Neispravna lista!");
    Spil::iterator sIt {s.begin()};
    vector<Spil::iterator> sbrisanje;
    vector<MMapa::iterator> mbrisanje;
    for(auto i=m.begin(); i!=m.end(); i++)
        for(auto j=s.begin(); j!=s.end(); j++)
            if(i->first == j->first && i->second== j->second) {
                s.erase(j);
                mbrisanje.push_back(i);
                break;
            }
    for(int i=0; i<mbrisanje.size(); i++) m.erase(mbrisanje.at(i));
}
bool validanRed(pair<string,string> p){
    bool validan{false};
    for(int i=0;i<TipKarata.size();i++)
    if(p.first==TipKarata.at(i)) validan=true;
    if(!validan) return false;
    for(int i=0;i<Karte.size();i++)
    if(p.second==Karte.at(i)) validan=true;
    if(!validan) return false;
    return true;
}
queue<pair<string,string>> IzbaciKarteRazbrajanjem(Spil &s, const short int &r, const int &b) {
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(s.size()>52 || !ispravnoSortiranSpil(s,s) || !validanSpil(s)) throw std::logic_error("Neispravna lista!");
    queue<pair<string,string>> q;
    Spil::iterator sIt {s.begin()};
    std::advance(sIt,r-1);
    int brojac=b;
    while(brojac!=0 && !s.empty()) {
        short int i=r-1;
        /* cout << "Brisat ce se: " << TipKarata.at(int(sIt->first)) << " " << sIt->second <<endl;*/
        q.push(std::make_pair(TipKarata.at(int(sIt->first)),sIt->second));
        sIt=s.erase(sIt);
        if(sIt==s.end()) sIt=s.begin();      
        /*cout << "Poslije brisanja: " << TipKarata.at(int(sIt->first)) << " " << sIt->second <<endl;*/
        while(i!=0) {
            sIt++;
            if(sIt==s.end()) sIt=s.begin();
            i--;
        }
        brojac--;
    }
    return q;
}
void VratiPrvihNKarata(Spil &s, queue<pair<string,string>> &q, int n) {
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    else if(n>q.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(s.size()>52 || !ispravnoSortiranSpil(s,s) || !validanSpil(s)) throw std::logic_error("Neispravna lista!");
    Spil::iterator sIt {s.begin()};
    pair<Boje,string> temp;
    while(n!=0) {
        int i;
        if(!validanRed(q.front())) throw std::logic_error("Neispravne karte");
        for(i=0; i<4; i++) if(q.front().first==TipKarata.at(i)) break;
        temp=std::make_pair(static_cast<Boje>(i),q.front().second);
        if(!std::binary_search(s.begin(),s.end(),temp)) s.push_back(temp);
        SortirajSpil(s);
        n--;
        q.pop();
    }
}
void IspisSpila(Spil &s) {
    Spil::iterator sIt(s.begin());
    int TipKarte {};
    do {
        cout << TipKarata.at(TipKarte) << ": ";
        int brojac=std::count_if(s.begin(),s.end(),[TipKarte](pair<Boje,string> x)->bool {return int(x.first)==TipKarte;});
        for(int i=0; i<brojac; i++,sIt++) cout << sIt->second << " ";
        cout << endl;
        TipKarte++;
    } while(TipKarte<=3);
}
int main () {
    int r;
    cout << "Unesite korak razbrajanja: ";
    cin >> r;
    int b;
    cout << "Unesite broj karata koje zelite izbaciti: ";
    cin >> b;
    try {
        Spil a {KreirajSpil()};
        auto q=IzbaciKarteRazbrajanjem(a,r,b);
        cout << "U spilu trenutno ima " << a.size() << " karata, i to:"<< endl;
        IspisSpila(a);
        int p;
        cout << "Unesite broj karata koje zelite vratiti u spil: ";
        cin >> p;
        VratiPrvihNKarata(a,q,p);
        cout << "U spilu trenutno ima " << a.size() << " karata, i to:"<< endl;
        IspisSpila(a);
        cout << endl;
    } catch(std::exception &ex) {
        cout << "Izuzetak: " << ex.what();
    }
    return 0;
}

/*MMapa mapa {{Boje::Pik,"2"},{Boje::Pik,"3"},{Boje::Pik,"4"},{Boje::Pik,"5"},{Boje::Pik,"6"},{Boje::Pik,"7"},
         {Boje::Pik,"8"},{Boje::Pik,"9"},{Boje::Pik,"10"},{Boje::Pik,"J"},{Boje::Pik,"K"},{Boje::Pik,"A"},{Boje::Pik,"Q"},
         {Boje::Tref,"2"},{Boje::Tref,"3"},{Boje::Tref,"4"},{Boje::Tref,"5"},{Boje::Tref,"6"},{Boje::Tref,"7"},
         {Boje::Tref,"8"},{Boje::Tref,"9"},{Boje::Tref,"10"},{Boje::Tref,"J"},{Boje::Tref,"K"},{Boje::Tref,"A"},{Boje::Tref,"Q"},
         {Boje::Herc,"2"},{Boje::Herc,"3"},{Boje::Herc,"4"},{Boje::Herc,"5"},{Boje::Herc,"6"},{Boje::Herc,"7"},
         {Boje::Herc,"8"},{Boje::Herc,"9"},{Boje::Herc,"10"},{Boje::Herc,"J"},{Boje::Herc,"K"},{Boje::Herc,"A"},{Boje::Herc,"Q"},
         {Boje::Karo,"2"},{Boje::Karo,"3"},{Boje::Karo,"4"},{Boje::Karo,"5"},{Boje::Karo,"6"},{Boje::Karo,"7"},
         {Boje::Karo,"8"},{Boje::Karo,"9"},{Boje::Karo,"10"},{Boje::Karo,"J"},{Boje::Karo,"K"},{Boje::Karo,"A"},{Boje::Karo,"Q"},
         {Boje::Karo,"Q"},{Boje::Herc,"8"},{Boje::Herc,"9"},{Boje::Herc,"10"},{Boje::Herc,"J"},{Boje::Herc,"K"},{Boje::Herc,"A"},{Boje::Herc,"Q"},
         {Boje::Karo,"2"},{Boje::Karo,"3"},{Boje::Karo,"4"},{Boje::Karo,"5"},{Boje::Karo,"6"},{Boje::Karo,"7"}};*/
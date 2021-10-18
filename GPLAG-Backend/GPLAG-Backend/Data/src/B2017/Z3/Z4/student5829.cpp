/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <queue>
using std::queue;
using std::multimap;
using std::vector;
using std::string;
using std::pair;
using std::list;
using std::cout;
using std::cin;
enum class Boje
{
    Pik, Tref, Herc, Karo
};
typedef list<pair<Boje,string>> SPIL;
typedef multimap<Boje,string> MAPA;
typedef queue<pair<string,string>> RED;

SPIL KreirajSpil()
{
    vector<string> v {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    list<pair<Boje,string>> spil;
    for(int i(0); i<13; i++) spil.push_back(std::make_pair(Boje::Pik,v[i]));
    for(int i(0); i<13; i++) spil.push_back(std::make_pair(Boje::Tref,v[i]));
    for(int i(0); i<13; i++) spil.push_back(std::make_pair(Boje::Herc,v[i]));
    for(int i(0); i<13; i++) spil.push_back(std::make_pair(Boje::Karo,v[i]));
    return spil;
}

bool TestKarte(Boje &boja,string &s)
{
    if(!(boja==Boje::Pik || boja==Boje::Tref || boja==Boje::Herc || boja==Boje::Karo)) return true;
    if(s!="2" && s!="3" && s!="4" && s!="5" && s!="6" && s!="7" && s!="8"
            && s!="9" && s!="10" && s!="J" && s!="Q" && s!="K" && s!="A") return true;
    return false;
}

bool PoBojama(Boje boja1,Boje boja2)
{
    if(boja1==boja2) return true;
    if(boja1==Boje::Pik) return true;
    if(boja1==Boje::Tref && (boja2==Boje::Herc || boja2==Boje::Karo)) return true;
    if(boja1==Boje::Herc && boja2==Boje::Karo) return true;
    return false;
}

bool PoVelicini(string s1,string s2)
{
    vector<string> vec {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int a(0),b(0);
    for(int i(0); i<vec.size(); i++) {
        if(s1==vec[i]) a=i;
        if(s2==vec[i]) b=i;
    }
    return a<=b;
}

void SortirajBoje(SPIL &spil)
{
    for(auto it(spil.begin()); it!=spil.end(); it++) {
        for(auto it1(it); it1!=spil.end(); it1++) {
            if(PoBojama(it1->first,it->first)) {
                auto pom(std::move(*it));
                *it=std::move(*it1);
                *it1=std::move(pom);
            }
        }
    }
}

void SortirajSpil(SPIL &spil)
{
    SortirajBoje(spil);
    auto it(spil.begin());
    for(; it!=spil.end() && it->first==Boje::Pik; it++) {
        for(auto it1(it); it1!=spil.end() && it1->first==Boje::Pik; it1++) {
            if(PoVelicini(it1->second,it->second)) {
                auto pom(std::move(*it));
                *it=std::move(*it1);
                *it1=std::move(pom);
            }
        }
    }
    for(; it!=spil.end() && it->first==Boje::Tref; it++) {
        for(auto it1(it); it1!=spil.end() && it1->first==Boje::Tref; it1++) {
            if(PoVelicini(it1->second,it->second)) {
                auto pom(std::move(*it));
                *it=std::move(*it1);
                *it1=std::move(pom);
            }
        }
    }
    for(; it!=spil.end() && it->first==Boje::Herc; it++) {
        for(auto it1(it); it1!=spil.end() && it1->first==Boje::Herc; it1++) {
            if(PoVelicini(it1->second,it->second)) {
                auto pom(std::move(*it));
                *it=std::move(*it1);
                *it1=std::move(pom);
            }
        }
    }
    for(; it!=spil.end() && it->first==Boje::Karo; it++) {
        for(auto it1(it); it1!=spil.end() && it1->first==Boje::Karo; it1++) {
            if(PoVelicini(it1->second,it->second)) {
                auto pom(std::move(*it));
                *it=std::move(*it1);
                *it1=std::move(pom);
            }
        }
    }
}

void TestirajSpil(SPIL &spil)
{
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    if(spil.size()==1) return;
    auto it1(spil.begin());
    if(TestKarte(it1->first,it1->second)) throw std::logic_error("Neispravna lista!");
    it1++;
    for(auto it(spil.begin()); it1!=spil.end(); it++,it1++) {
        if(!PoBojama(it->first,it1->first))
            throw std::logic_error("Neispravna lista!");
        if(TestKarte(it1->first,it1->second)) throw std::logic_error("Neispravna lista!");
    }
    it1=spil.begin();
    it1++;
    for(auto it(spil.begin()); it1!=spil.end(); it++,it1++) {
        if(!(PoVelicini(it->second,it1->second))) {
            if(!PoBojama(it->first,it1->first))
                throw std::logic_error("Neispravna lista!");
        } else if(it->second==it1->second && it->first==it1->first)
            throw std::logic_error("Neispravna lista!");
    }
    for(auto it1(spil.begin()); it1!=spil.end(); it1++) {
        auto it2(it1);
        it2++;
        for(; it2!=spil.end(); it2++) {
            if(*it1==*it2) throw std::logic_error("Neispravna lista!");
        }
    }
}

void IzbaciKarte(SPIL &spil,MAPA &mapa)
{
    TestirajSpil(spil);
    for(auto it1(mapa.begin()); it1!=mapa.end(); it1++) {
        for(auto it2(spil.begin()); it2!=spil.end(); it2++) {
            if((it1->first==it2->first) && (it1->second==it2->second)) {
                it2=spil.erase(it2);
                it1=mapa.erase(it1);
            }
        }
    }
}

RED IzbaciKarteRazbrajanjem(SPIL &spil,const short int r,const int b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    TestirajSpil(spil);
    RED red;
    auto it(spil.begin());
    for(int i(0); i<b && spil.size()!=0; i++) {
        for(int j(0); j<r-1; j++) {
            it++;
            if(it==spil.end()) it=spil.begin();
        }
        string pom;
        if(it->first==Boje::Pik) pom="Pik";
        if(it->first==Boje::Tref) pom="Tref";
        if(it->first==Boje::Herc) pom="Herc";
        if(it->first==Boje::Karo) pom="Karo";
        red.push(std::make_pair(pom,it->second));
        it=spil.erase(it);
    }
    return red;
}

void VratiPrvihNKarata(SPIL &spil,RED &red,int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    for(int i(0); i<n; i++) {
        Boje boje;
        if(red.front().first=="Pik") boje=Boje::Pik;
        if(red.front().first=="Tref") boje=Boje::Tref;
        if(red.front().first=="Herc") boje=Boje::Herc;
        if(red.front().first=="Karo") boje=Boje::Karo;
        if(TestKarte(boje,red.front().second)) throw std::logic_error("Neispravne karte!");
        spil.push_back(std::make_pair(boje,red.front().second));
        red.pop();
    }
    SortirajSpil(spil);
    TestirajSpil(spil);
}

void IspisiSpil(SPIL &spil)
{
    auto it(spil.begin());
    cout<<"Pik: ";
    for(;;) {
        if(it==spil.end()) break;
        if(it->first==Boje::Pik) cout<<it->second<<" ";
        it++;
    }
    cout<<"\nTref: ";
    it=spil.begin();
    for(;;) {
        if(it==spil.end()) break;
        if(it->first==Boje::Tref) cout<<it->second<<" ";
        it++;
    }
    cout<<"\nHerc: ";
    it=spil.begin();
    for(;;) {
        if(it==spil.end()) break;
        if(it->first==Boje::Herc) cout<<it->second<<" ";
        it++;
    }
    cout<<"\nKaro: ";
    it=spil.begin();
    for(;;) {
        if(it==spil.end()) break;
        if(it->first==Boje::Karo) cout<<it->second<<" ";
        it++;
    }
}

int main ()
{
    short int r(0);
    int b(0);
    try {
        SPIL spil(KreirajSpil());
        cout<<"Unesite korak razbrajanja: ";
        cin>>r;
        cout<<"Unesite broj karata koje zelite izbaciti: ";
        cin>>b;
        auto red(IzbaciKarteRazbrajanjem(spil,r,b));
        cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        IspisiSpil(spil);
        int n(0);
        cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        cin>>n;
        VratiPrvihNKarata(spil,red,n);
        cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        IspisiSpil(spil);
    } catch(std::domain_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::logic_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::range_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    }

    return 0;
}

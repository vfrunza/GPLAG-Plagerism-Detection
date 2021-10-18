/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <sstream>
#include <map>
#include <exception>
#include <queue>
#include <iterator>

enum class Boje
{
    Pik, Herc, Tref, Karo
};

std::map<std::string, int> Poredak
{
    {"2",0},{"3",1}, {"4",2}, {"5",3}, {"6",4} , {"7",5}, {"8",6}, {"9",7}, {"10",8}, {"J",9}, {"Q",10}, {"K",11}, {"A",12}
};

typedef std::list<std::pair<Boje, std::string>> Lista;
typedef std::pair<Boje, std::string> Par;
typedef std::multimap<Boje, std::string> MultiMapa;


Lista KreirajSpil()
{
    Lista l;
    Boje boja_karte;

    Par p;
    for(int i=0; i<4; i++) {

        if(i==0) boja_karte=Boje::Pik;
        else if (i==1) boja_karte=Boje::Herc;
        else if (i==2) boja_karte=Boje::Tref;
        else if(i==3) boja_karte=Boje::Karo;

        for(int j=2; j<=14; j++) {

            std::string s;

            if(j==14) s="A";
            else if(j==13) s="K";
            else if(j==12) s="Q";
            else if(j==11) s="J";
            else s=std::to_string(j);

            p=std::make_pair(boja_karte, s);
            l.push_back(p);

        }
    }
    return l;
}
int BrojElemenataListe(Lista l)
{
    int brojac=0;
    for(auto x:l) brojac++;
    return brojac;
}
bool DaLiJeSortirana(Lista l)
{
    typename Lista::iterator p(l.begin());
    typename Lista::iterator k(l.end());
    typename Lista::iterator pom(l.begin());
    while(p!=k) {
        pom=p;
        pom++;
        while(pom!=k) {
            if(p->first > pom->first || (p->first==pom->first && Poredak[p->second]> Poredak[pom->second])) return false;
            pom++;
        }
        p++;
    }
    return true;
}

bool DaLiJeSmislena(Lista l){
    for(auto it=l.begin(); it!=l.end(); it++){
        if(it->first != Boje::Pik && it->first != Boje::Herc && it->first != Boje::Tref && it->first != Boje::Karo) return false;
        if(!Poredak.count(it->second)) return false;
    }
    return true;
}

void IzbaciKarte(Lista &l, MultiMapa &m)
{
    if(BrojElemenataListe(l)>52 || DaLiJeSortirana(l)==false || DaLiJeSmislena(l)==false) throw std::logic_error ("Neispravna lista!");
    for(auto it= m.begin(); it!=m.end(); it++)
        for(auto it2=l.begin(); it2!=l.end(); it2++)
            if(it->first==it2->first && it->second == it2->second) {
                it2=l.erase(it2);
                m.erase(it);
            }
}
std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(Lista &l, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(BrojElemenataListe(l)>52 || DaLiJeSortirana(l)==false ||DaLiJeSmislena(l)==false)  throw std::logic_error ("Neispravna lista!");

    std::queue<std::pair<Boje, std::string>> red;

    int korak(r-1);
    for( int i=0 ; i<b; i++) {
        auto it (l.begin());
        korak = korak % BrojElemenataListe(l);
        std::advance(it, korak);

        red.push(*it);
        it=l.erase(it);
        korak--;
        korak+=r;
    }
    return red;
}
int BrojElemenataReda(std::queue<std::pair<Boje,std::string>> red)
{
    int brojac(0);
    while(!red.empty()) {
        brojac++;
        red.pop();
    }
    return brojac;
}

bool DaLiJeuListi(Lista l, std::pair<Boje, std::string> par)
{
    for(auto it=l.begin(); it!=l.end(); it++) {
        if(it->first == par.first && it->second == par.second) return true;
    }
    return false;
}
void Sortirajlistu(Lista &l)
{
    auto p(l.begin());
    auto k(l.end());
    auto pom(l.begin());
    while(p!=k) {
        pom=p;
        pom++;

        while(pom!=k) {
            if(p->first>pom->first || (p->first==pom->first && Poredak[p->second]>Poredak[pom->second])) {
                auto pomocna(*p);
                *p=*pom;
                *pom=pomocna;
            }
            pom++;
        }
        p++;
    }
}

void VratiPrvihNKarata(Lista &l, std::queue<std::pair<Boje, std::string>> &red, int n)
{
    if(n>BrojElemenataReda(red)) throw std::range_error("Nedovoljno karata u redu!");
    if(n!=int(n) || n<0) throw std::domain_error ("Broj n je besmislen!");
    if(BrojElemenataListe(l)>52 || DaLiJeSortirana(l)==false || DaLiJeSmislena(l)==false) throw std::logic_error ("Neispravna lista!");

    for(int i=0; i<n; i++ ) {
        if(DaLiJeuListi(l,red.front())==true) {
            red.pop();
            continue;
        }
        l.push_back(red.front());
        red.pop();

    }
    Sortirajlistu(l);
}


void IspisiPik(Lista l)
{
    std::cout<<"Pik: ";
    for(auto it=l.begin(); it!=l.end(); it++) {
        if(int(it->first)==0)
            std::cout<< it->second<<" ";

    }
    std::cout <<std::endl;
}
void IspisiTref (Lista l)
{
    std::cout<<"Tref: ";
    for(auto it=l.begin(); it!=l.end(); it++) {
        if(int(it->first)==1)
            std::cout<< it->second<<" ";
    }
    std::cout <<std::endl;
}

void IpisiHerc (Lista l)
{
    std::cout<<"Herc: ";
    for(auto it=l.begin(); it!=l.end(); it++) {
        if(int(it->first)==2)
            std::cout<< it->second<<" ";
    }
    std::cout <<std::endl;
}

void IspisiKaro (Lista l)
{
    std::cout<<"Karo: ";
    for(auto it=l.begin(); it!=l.end(); it++) {
        if(int(it->first)==3)
            std::cout<< it->second<<" ";
    }
    std::cout <<std::endl;
}
void IpisiListu (Lista l)
{

    IspisiPik(l);
    IspisiTref(l);
    IpisiHerc(l);
    IspisiKaro(l);
}



int main ()
{
    try {
        Lista l(KreirajSpil());
        
        int korak;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>> korak;
        int broj;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>> broj;
        std::queue<std::pair<Boje, std::string>> red(IzbaciKarteRazbrajanjem(l, korak, broj));
        std::cout<<"U spilu trenutno ima "<< BrojElemenataListe(l)<<" karata, i to: "<<std::endl;
        IpisiListu(l);
        int vrati;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>vrati;
        VratiPrvihNKarata(l,red,vrati);
        std::cout<<"U spilu trenutno ima "<<BrojElemenataListe(l)<<" karata, i to: "<<std::endl;
        IpisiListu(l);
    } catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what() << std::endl;
    } catch(std::range_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }

    return 0;
}

#include <iostream>
#include <map>
#include <queue>
#include <iostream>
#include <list>
#include <string>
#include <deque>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <utility>

enum class Boje {Pik, Tref, Herc, Karo};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor* sljedeci;
};

std::string Pretvoriti (std::string s) {
    std::string z;
    if (s=="10") z=":";
    else if (s==":") z="10";
    else if (s=="A") z="a";
    else if (s=="a") z="A";
    else if (s=="K") z="R";
    else if (s=="R") z="K";
    else z=s;
    return z;
}

std::list<std::pair<Boje, std::string>> KreirajSpil () {
    std::list<std::pair<Boje, std::string>> spil (52);
    std::vector<std::string> niz={"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    auto it=spil.begin();
    for (int j=0; j<13; j++) {
        it->first=Boje::Pik;
        it->second=niz.at(j);
        it++;
    }
    for (int j=0; j<13; j++) {
        it->first=Boje::Tref;
        it->second=niz.at(j);
        it++;
    }
    for (int j=0; j<13; j++) {
        it->first=Boje::Herc;
        it->second=niz.at(j);
        it++;
    }
    for (int j=0; j<13; j++) {
        it->first=Boje::Karo;
        it->second=niz.at(j);
        it++;
    }
    return spil;
}

bool ImaLiSmisla (std::queue<std::pair<Boje, std::string>> b) {
    auto a=KreirajSpil();
    auto n=b.size();
    int brejk(0);
    for (int i=0; i<n; i++) {
        int brejk=0;
        auto it=a.begin();
        for (int j=0; j<a.size(); j++) {
            if (b.front()==*it) {brejk=1; break;}
            it++;
        }
        if (brejk==0) return false;
    }
    return true;
}

bool SmijemSeBezSmisla (std::list<std::pair<Boje, std::string>> b) {
    auto a=KreirajSpil();
    auto n=b.size();
    int brejk(0);
    auto ti=b.begin();
    for (int i=0; i<n; i++) {
        int brejk=0;
        auto it=a.begin();
        for (int j=0; j<a.size(); j++) {
            if (it->first==ti->first and it->second==ti->second) {brejk=1; break;}
            it++;
        }
        ti++;
        if (brejk==0) return false;
    }
    return true;
}

void IzbaciKarte (std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &mlti) {
    if (spil.size()>52 or SmijemSeBezSmisla(spil)==0) throw std::logic_error("Neispravna lista");
    auto n=mlti.size();
    auto m=spil.size();
    auto it=mlti.begin();
    auto ti=spil.begin();
    for (int i=0; i<n; i++) {
        ti=spil.begin();
        for (int j=0; j<m; j++) {
            if (ti->first==it->first and ti->second==it->second) {
                spil.erase(ti);
                mlti.erase(it);
            }
            ti++;
        }
        it++;
    }
}

std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje, std::string>> &spil, const short int &r, const int &b) {
    std::queue<std::pair<Boje, std::string>> red;
    if (spil.size()>52 or SmijemSeBezSmisla(spil)==0) throw std::logic_error("Neispravna lista");
    if (r<1 or r>52 or b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    int k=1, brojac=0;
    auto it=spil.begin();
    int krug=spil.size();
    for (;;) {
        if (k%r==0) {
            red.push(*it);
            it=spil.erase(it);
            brojac++;
        }
        else it++;
        if (brojac==b) break;
        k++;
        if (it==spil.end()) it=spil.begin();
        if (spil.size()==0) break;
    }
    return red;
}

void VratiPosljednjihNKarata (std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<Boje, std::string>> &red, int n) {
    auto m=red.size();
    if (n<0) throw std::domain_error("Broj n je besmislen!");
    if (n>m) throw std::range_error("Nedovoljno karata u redu!");
    if (ImaLiSmisla(red)==false) throw std::logic_error("Neispravne karte");
    for (int i=0; i<n; i++) {
        spil.push_back(red.back());
        red.pop();
    }
    spil.sort( [] (const std::pair<Boje, std::string> &jedan, const std::pair<Boje, std::string> &dva) { return (jedan.first < dva.first) or (jedan.first==dva.first and Pretvoriti(jedan.second) < Pretvoriti(dva.second));});
}

void IspisiSpil (std::list<std::pair<Boje, std::string>> spil) {
    auto it=spil.begin();
    std::cout << "Pik: ";
    for (int i=0; i<spil.size(); i++) {
        if (it->first==Boje::Pik) std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
    it=spil.begin();
    std::cout << "Tref: ";
    for (int i=0; i<spil.size(); i++) {
        if (it->first==Boje::Tref) std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
    it=spil.begin();
    std::cout << "Herc: ";
    for (int i=0; i<spil.size(); i++) {
        if (it->first==Boje::Herc) std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
    it=spil.begin();
    std::cout << "Karo: ";
    for (int i=0; i<spil.size(); i++) {
        if (it->first==Boje::Karo) std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
}

int main ()
{
    try {
        int b, n;
        short int r;
        auto spil=KreirajSpil();
        std::cout << "Unesite korak razbrajanja: ";
        std::cin >> r;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> b;
        auto red=IzbaciKarteRazbrajanjem(spil, r, b);
        auto t=52-red.size();
        std::cout << "U spilu trenutno ima " << t << " karata, i to:" << std::endl;
        IspisiSpil(spil);
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPosljednjihNKarata(spil, red, n);
        auto k=t+n;
        std::cout << "U spilu trenutno ima " << k << " karata, i to:" << std::endl;
        IspisiSpil(spil);
    }
    catch (std::logic_error izuzetak1) {
        std::cout << "Izuzetak: " << izuzetak1.what() << std::endl;
    }
    catch (std::range_error izuzetak2) {
        std::cout << "Izuzetak: " << izuzetak2.what() << std::endl;
    }
    catch (std::domain_error izuzetak3) {
        std::cout << "Izuzetak: " << izuzetak3.what() << std::endl;
    }
    return 0;
}

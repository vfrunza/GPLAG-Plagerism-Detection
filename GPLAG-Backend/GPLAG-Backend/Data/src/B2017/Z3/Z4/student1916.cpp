/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

typedef std::pair<Boje, std::string> Karta;
typedef std::list<Karta> Spil;

void IspisiSpil(const Spil &spil)
{
    int broj_karata(0);
    for(auto i(spil.begin()); i!=spil.end(); i++) broj_karata++;
    std::cout << "U spilu trenutno ima " << broj_karata << " karata, i to:\n";
    for(int i(0); i<4; i++) {
        if(i==0) std::cout << "Pik: ";
        if(i==1) std::cout << "Tref: ";
        if(i==2) std::cout << "Herc: ";
        if(i==3) std::cout << "Karo: ";
        std::for_each(spil.begin(), spil.end(), [i](Karta a) {
            if(a.first==Boje(i)) std::cout << a.second << " ";
        });
        std::cout << std::endl;
    }
}

Spil KreirajSpil()
{
    Spil spil;
    for(int i(0); i<4; i++) {
        std::string broj;
        for(int j(2); j<=14; j++) {
            broj=" ";
            broj.at(0)=char(j+'0');
            if(j==10) broj="10";
            if(j==11) broj="J";
            if(j==12) broj="Q";
            if(j==13) broj="K";
            if(j==14) broj="A";
            Karta a;
            a.first=Boje(i);
            a.second=broj;
            spil.push_back(a);
        }
    }
    return spil;
}

int StringUBroj(std::string a)
{
    int broj(0);
    broj+=a.at(0)-'0';
    if(a=="10") broj=10;
    if(a=="J") broj=11;
    if(a=="Q") broj=12;
    if(a=="K") broj=13;
    if(a=="A") broj=14;
    return broj;
}

std::string BojaUString(Boje boja)
{
    if(boja==Boje::Pik) return "Pik";
    if(boja==Boje::Tref) return "Tref";
    if(boja==Boje::Herc) return "Herc";
    return "Karo";
}

bool ManjaBoja(Boje a, Boje b)
{
    if((a==Boje::Pik && b!=Boje::Pik) || (a==Boje::Tref && (b==Boje::Herc || b==Boje::Karo)) || (a==Boje::Herc &&  b==Boje::Karo)) return true;
    return false;
}

bool IstaBoja(Boje a, Boje b)
{
    if((a==Boje::Pik && b==Boje::Pik) || (a==Boje::Tref && b==Boje::Tref) || (a==Boje::Herc && b==Boje::Herc)
            || (a==Boje::Karo && b==Boje::Karo)) return true;
    return false;
}

bool ManjaKarta(Karta a, Karta b)
{
    if(ManjaBoja(a.first, b.first)) return true;
    if(IstaBoja(a.first, b.first)) return StringUBroj(a.second)<StringUBroj(b.second);
    return false;
}

void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> mapa)
{
    int broj_karata(0);
    for(auto x(spil.begin()); x!=spil.end(); x++) broj_karata++;
    bool dobro_sortirana(true);
    auto pom(spil.end());
    pom--;
    for(auto x(spil.begin()); x!=pom; x++) {
        auto po(x);
        po++;
        if(ManjaKarta(*po, *x)) {
            dobro_sortirana=false;
            break;
        }
    }
    if(broj_karata>52 || !dobro_sortirana) throw std::logic_error("Neispravna lista!");
    auto it(mapa.begin());
    while(it!=mapa.end()) {
        Karta karta;
        karta.first=it->first;
        karta.second=it->second;
        auto p=std::remove(spil.begin(), spil.end(), karta);
        if(p!=spil.end()) {
            p=spil.end();
            p--;
            p=spil.erase(p);
            it=mapa.erase(it);
            continue;
        }
        it++;
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbiranjem(Spil &spil, const short int &korak_razbrajanja, const int &broj_karata)
{
    if(korak_razbrajanja<1 || korak_razbrajanja>52 || broj_karata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    int broj(0);
    auto it(spil.begin());
    for(; it!=spil.end(); it++) broj++;
    it=spil.begin();
    auto kraj(spil.end());
    kraj--;
    bool dobro_sortirana(true);
    while(it!=kraj) {
        auto pom(it);
        pom++;
        if(ManjaKarta(*pom, *it)) {
            dobro_sortirana=false;
            break;
        }
        it++;
    }
    if(broj>52 || !dobro_sortirana) throw std::logic_error("Neispravna lista!");
    it=spil.begin();
    std::queue<std::pair<std::string, std::string>> red_karata;
    for(int i(0); i<broj_karata && spil.size()!=0; i++) {
        broj=korak_razbrajanja;
        while(broj>spil.size()) broj-=spil.size();
        for(int j(0); j<broj-1; j++) {
            it++;
            if(it==spil.end()) it=spil.begin();
        }
        std::pair<std::string, std::string> karta(std::make_pair(BojaUString(it->first), it->second));
        red_karata.push(karta);
        it=spil.erase(it);
        if(it==spil.end()) it=spil.begin();
    }
    return red_karata;
}

bool IspravnaKartaURedu(std::pair<std::string, std::string> karta)
{
    std::string a;
    a=karta.first;
    if(!(a=="Pik" || a=="Tref" || a=="Herc" || a=="Karo")) return false;
    a=karta.second;
    if(!(a=="2" || a=="3" || a=="4" || a=="5" || a=="6" || a=="7" || a=="8" || a=="9"
            || a=="10" || a=="J" || a=="Q" || a=="K" || a=="A")) return false;
    return true;
}

Karta KartaIzRedaUListu(std::pair<std::string, std::string> a)
{
    Karta karta;
    karta.first=Boje::Pik;
    if(a.first=="Tref") karta.first=Boje::Tref;
    if(a.first=="Karo") karta.first=Boje::Karo;
    if(a.first=="Herc") karta.first=Boje::Herc;
    karta.second=a.second;
    return karta;
}

void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string, std::string>> &red_karata, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red_karata.size()) throw std::range_error("Nedovoljno karata u redu!");
    bool ispravne_karte(true);
    for(int i(0); i<red_karata.size(); i++) {
        std::pair<std::string, std::string> karta(red_karata.front());
        red_karata.pop();
        red_karata.push(karta);
        if(!IspravnaKartaURedu(karta)) {
            ispravne_karte=false;
            break;
        }
    }
    if(!ispravne_karte) throw std::logic_error("Neispravne karte!");
    for(int i(0); i<n; i++) {
        std::pair<std::string, std::string> a(red_karata.front());
        red_karata.pop();
        Karta karta(KartaIzRedaUListu(a));
        auto it(spil.begin());
        for(; it!=spil.end() && ManjaKarta(*it, karta); it++);
        spil.insert(it, karta);
    }
}

int main ()
{
    Spil spil;
    try {
        spil=KreirajSpil();
        std::cout << "Unesite korak razbrajanja: ";
        int korak_razbrajanja;
        std::cin >> korak_razbrajanja;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        int broj_karata;
        std::cin >> broj_karata;
        std::queue<std::pair<std::string, std::string>> red_karata=IzbaciKarteRazbiranjem(spil, static_cast<short int>(korak_razbrajanja), broj_karata);
        IspisiSpil(spil);
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> broj_karata;
        VratiPrvihNKarata(spil, red_karata, broj_karata);
        IspisiSpil(spil);
    } catch(std::logic_error p) {
        std::cout << "Izuzetak: " << p.what() << std::endl;
    } catch(std::range_error p) {
        std::cout << "Izuzetak: " << p.what() << std::endl;
    } catch(std::domain_error p) {
        std::cout << "Izuzetak: " << p.what() << std::endl;
    }
    return 0;
}

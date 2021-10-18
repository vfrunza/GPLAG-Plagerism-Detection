/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <iterator>
enum class Boje {Pik, Tref, Herc, Karo};
typedef std::pair<Boje,std::string> Karta;
typedef std::list<Karta> Spil;
typedef std::multimap<Boje,std::string> DioSpila;
Spil KreirajSpil() {
    static const std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    Spil spil;
    for (int i=0;i<4;i++) {
        for (int j=0;j<13;j++) {
            Karta karta = {static_cast<Boje>(i), v.at(j)};
            spil.push_back(karta);
        }
    }
    return spil;
}
bool DaLiJeDobroSortiran(const Spil &spil) {
    static const std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto it1(spil.begin()), it2(spil.begin());
    it1++;
    while(it1!=spil.end()) {
        if (it1->first<it2->first || ( it1->first==it2->first && std::find(v.begin(),v.end(),it1->second)<std::find(v.begin(),v.end(),it2->second)))
            return false;
        it1++;it2++;
    }
    return true;
}
bool DaLiJeIspravan(const Spil &spil) {
    static const std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto it(spil.begin());
    while (it!=spil.end()) {
        if (!std::count(v.begin(),v.end(),it->second)) return false;
        if (std::count(spil.begin(),spil.end(),*it)>1) return false;
        it++;
    }
    return true;
}
void IzbaciKarte(Spil &spil, DioSpila &diospila) {
    if (spil.size()>52 || !DaLiJeIspravan(spil) || !DaLiJeDobroSortiran(spil)) throw std::logic_error("Neispravna lista!");
    auto it(diospila.begin());
    while(it!=diospila.end()) {
        bool loga=false;
        std::pair<Boje,std::string> par=std::make_pair(it->first, it->second);
        if (std::count(spil.begin(), spil.end(), par)) {
            spil.erase(std::find(spil.begin(), spil.end(), par));
            it=diospila.erase(it);
            loga=true;
        }
        if(!loga) it++;
    }
}
std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(Spil &spil, const short int &r,const int &b) {
    if (r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (spil.size()>52 || !DaLiJeIspravan(spil) || !DaLiJeDobroSortiran(spil)) throw std::logic_error("Neispravna lista!");
    static const std::vector<std::string> v{"Pik", "Tref", "Herc", "Karo"};
    std::queue<std::pair<std::string,std::string>> stek;
    int brojac(0), brrazmaka(1);
    auto it(spil.begin());
    while (spil.size() && brojac<b) {
        if (brrazmaka==r) {
            std::pair<std::string,std::string> karta={v[static_cast<int>(it->first)],it->second};
            stek.push(karta);
            it=spil.erase(it);
            it--; brojac++; brrazmaka=0;
        }
        it++; brrazmaka++;
        if (it==spil.end()) it=spil.begin();
    }
    return stek;
}

void UbaciKartu(Karta karta, Spil &spil) {
    static const std::vector<std::string> v2{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto it=spil.begin();
    while (it!=spil.end() && ((static_cast<int>(it->first) < static_cast<int>(karta.first)))) it++;
    while (it!=spil.end() && (static_cast<int>(it->first) == static_cast<int>(karta.first)) && (std::find(v2.begin(),v2.end(),it->second) < std::find(v2.begin(),v2.end(),karta.second))) it++;
    spil.insert(it, karta);
}
void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string,std::string>> &red, int n) {
    if (n<0) throw std::domain_error("Broj n je besmislen!");
    if (n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if (spil.size()>52 || !DaLiJeIspravan(spil) || !DaLiJeDobroSortiran(spil)) throw std::logic_error("Neispravna lista!");
    static const std::vector<std::string> v{"Pik", "Tref", "Herc", "Karo"};
    static const std::vector<std::string> v2{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int brojac(0);
    while (red.size() && brojac<n) {
        if (!std::count(v.begin(),v.end(),red.front().first) || !std::count(v2.begin(),v2.end(),red.front().second)) throw std::logic_error("Neispravne karte!");
        auto karta=std::make_pair(static_cast<Boje>(std::find(v.begin(),v.end(),red.front().first)-v.begin()),red.front().second);
        if (std::count(spil.begin(), spil.end(), karta)) continue;
        UbaciKartu(karta, spil);
        red.pop();
        brojac++;
    }
}
void IspisiSpil(const Spil &spil) {
    static const std::vector<std::string> v{"Pik","Tref","Herc","Karo"};
    for (int i=0;i<4;i++) {
        std::cout<<std::endl<<v.at(i)<<": ";
        auto it(spil.begin());
        while (it!=spil.end()) {
            if (it->first==static_cast<Boje>(i)) 
                std::cout<<it->second<<" ";
            it++;
        }
    }
}
int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    short int r;
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin>>b;
    auto spil=KreirajSpil();
    try {
        auto red=IzbaciKarteRazbrajanjem(spil, r, b);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: ";
        IspisiSpil(spil);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int brojkarata;
        std::cin>>brojkarata;
        VratiPrvihNKarata(spil,red,brojkarata);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: ";
        IspisiSpil(spil);
    }
    catch(std::exception &e) {
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}

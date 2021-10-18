/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <new>
#include <map>
#include <stack>
#include <memory>
#include <sstream>
enum class Boje { Pik,Tref,Herc,Karo };
typedef std::multimap<Boje,std::string> DioSpila;
struct Karta {
    Boje boja;
    std::string vrijednost;
};
struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci=nullptr;
};
std::shared_ptr<Cvor> KreirajSpil() {
    static const std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::shared_ptr<Cvor> pocetak=nullptr, prethodni;
    for (int i=0;i<4;i++) {
        for (int j=0;j<13;j++) {
            Cvor kartica;
            kartica.karta.boja=static_cast<Boje>(i); kartica.karta.vrijednost=v.at(j);
            kartica.sljedeci=nullptr;
            auto novi=std::make_shared<Cvor>(kartica);
            if (!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
}
int BrojKarata(std::shared_ptr<Cvor> pocetak) {
    if (pocetak==nullptr) return 0;
    int brojac(0);
    std::shared_ptr<Cvor> pok=pocetak;
    do {
        brojac++;
        pok=pok->sljedeci;
    } while(pok!=pocetak);
    return brojac;
}
std::shared_ptr<Cvor> PronadjiKartu(std::shared_ptr<Cvor> pocetak, std::pair<Boje,std::string> kartauspilu) {
    std::shared_ptr<Cvor> pok=pocetak;
    if (pocetak==nullptr) return nullptr;
    do {
        if (pok->karta.boja==kartauspilu.first && pok->karta.vrijednost==kartauspilu.second) return pok;
        pok=pok->sljedeci;
    }while(pok!=pocetak);
    return nullptr;
}
std::shared_ptr<Cvor> PronadjiKartuZaIzbaciti(std::shared_ptr<Cvor> pocetak, std::pair<Boje,std::string> kartauspilu) {
    std::shared_ptr<Cvor> pok=pocetak, prethodni=nullptr;
    if (pocetak==nullptr) return nullptr;
    for (prethodni=pocetak;prethodni->sljedeci!=pocetak;prethodni=prethodni->sljedeci);
    do {
        if (pok->karta.boja==kartauspilu.first && pok->karta.vrijednost==kartauspilu.second) return prethodni;
        prethodni=pok;
        pok=pok->sljedeci;
    }while(pok!=pocetak);
    return nullptr;
}
int BrojPonavljanja(std::shared_ptr<Cvor> pocetak, std::pair<Boje,std::string> kartauspilu) {
    int brojac(0);
    std::shared_ptr<Cvor> pok=pocetak;
    if (pocetak==nullptr) return 0;
    do {
        if (pok->karta.boja==kartauspilu.first && pok->karta.vrijednost==kartauspilu.second) brojac++;
        pok=pok->sljedeci;
    }while(pok!=pocetak);
    return brojac;
}
bool DaLiJeDobroSortiran(std::shared_ptr<Cvor> pocetak) {
    static const std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::shared_ptr<Cvor> pok(pocetak);
    if (pocetak==nullptr) return true;
    std::shared_ptr<Cvor> pok2(pocetak->sljedeci);
    while (pok2!=pocetak) {
        if (pok2->karta.boja<pok->karta.boja || ( pok2->karta.boja==pok->karta.boja && std::find(v.begin(),v.end(),pok2->karta.vrijednost)<std::find(v.begin(),v.end(),pok->karta.vrijednost)))
            return false;
        pok=pok->sljedeci;pok2=pok2->sljedeci;
    }
    return true;
}
bool DaLiJeIspravan(std::shared_ptr<Cvor> pocetak) {
    static const std::vector<std::string> v{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto test=pocetak;
    if (pocetak==nullptr) return true;
    do {
        if (!std::count(v.begin(),v.end(),test->karta.vrijednost)) return false;
        if (BrojPonavljanja(pocetak,std::make_pair(test->karta.boja,test->karta.vrijednost))>1) return false;
        test=test->sljedeci;
    }while(test!=pocetak);
    return true;
}
void IzbaciKarte(std::shared_ptr<Cvor> &pocetak, DioSpila &diospila) {
    if (BrojKarata(pocetak)>52 || !DaLiJeDobroSortiran(pocetak) || !DaLiJeIspravan(pocetak)) throw std::logic_error("Neispravna lista");
    auto it(diospila.begin());
    while (it!=diospila.end()) {
        auto par=std::make_pair(it->first,it->second);
        bool loga=false;
        if (BrojPonavljanja(pocetak, par)) {
            std::shared_ptr<Cvor> it2=PronadjiKartuZaIzbaciti(pocetak, par);
            std::shared_ptr<Cvor> temp=it2->sljedeci;
            if (temp==pocetak) pocetak=pocetak->sljedeci;
            if (temp==it2) {
                it2->sljedeci=nullptr;
                it2=nullptr;
                pocetak=nullptr;
            }
            else {
                it2->sljedeci=it2->sljedeci->sljedeci;
                temp->sljedeci=nullptr;
            }
            temp=nullptr;
            it=diospila.erase(it);
            loga=true;
        }
        if(!loga) it++;
    }
}
std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pocetak, const short int &r, const int &b) {
    if (r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (BrojKarata(pocetak)>52 || !DaLiJeIspravan(pocetak) || !DaLiJeDobroSortiran(pocetak)) throw std::logic_error("Neispravna lista!");
    static const std::vector<std::string> v{"Pik","Tref","Herc","Karo"};
    std::stack<std::pair<std::string,std::string>> stek;
    int brojac(0), brrazmaka(1);
    std::shared_ptr<Cvor> pok=pocetak;
    while(BrojKarata(pocetak) && brojac<b) {
        bool loga=false;
        if (brrazmaka==r) {
            auto karta=std::make_pair(v[static_cast<int>(pok->karta.boja)], pok->karta.vrijednost);
            stek.push(karta);
            auto pok2=PronadjiKartuZaIzbaciti(pocetak, std::make_pair(pok->karta.boja,pok->karta.vrijednost));
            std::shared_ptr<Cvor> temp=pok2->sljedeci;
            if (temp==pocetak) pocetak=pocetak->sljedeci;
            if (temp==pok2) {
                pok2->sljedeci=nullptr;
                pok2=nullptr;
                pocetak=nullptr;
                pok=nullptr;
            }
            else {
                pok2->sljedeci=pok2->sljedeci->sljedeci;
                pok=pok->sljedeci;
                temp->sljedeci=nullptr;
            }
            temp=nullptr;
            loga=true;
            brojac++; brrazmaka=0;
        }
        if (!loga) pok=pok->sljedeci;
        brrazmaka++;
    }
    return stek;
}
void IspisiSpil(std::shared_ptr<Cvor> pocetak) {
    static const std::vector<std::string> v{"Pik", "Tref", "Herc", "Karo"};
    for(int it=0;it<4;it++) {
        std::cout << std::endl;
        std::cout << v.at(it) << ": ";
        std::shared_ptr<Cvor> test=pocetak;
        do {
            if(test == nullptr) break;
            if(test->karta.boja == static_cast<Boje>(it))
                    std::cout << test->karta.vrijednost << " ";
            test=test->sljedeci;
        }while(test!=pocetak);
    }
}
void UbaciKartu(std::shared_ptr<Cvor> &pocetak, std::pair<Boje,std::string> karta) {
    static const std::vector<std::string> v2{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::shared_ptr<Cvor> pok=pocetak;
    if (pocetak==nullptr) {
        Cvor kartica;
        kartica.karta.boja=karta.first; kartica.karta.vrijednost=karta.second;
        kartica.sljedeci=nullptr;
        pocetak=std::make_shared<Cvor>(kartica);
        pocetak->sljedeci=pocetak;
    }
    else {
        while (pok->sljedeci!=pocetak && ((static_cast<int>(pok->karta.boja) < static_cast<int>(karta.first)))) pok=pok->sljedeci;
        while ((static_cast<int>(pok->karta.boja) == static_cast<int>(karta.first)) && (std::find(v2.begin(),v2.end(),pok->karta.vrijednost) < std::find(v2.begin(),v2.end(),karta.second))) pok=pok->sljedeci;
        pok=PronadjiKartuZaIzbaciti(pocetak,std::make_pair(pok->karta.boja,pok->karta.vrijednost));
        Cvor kartica;
        kartica.karta.boja=karta.first; kartica.karta.vrijednost=karta.second;
        kartica.sljedeci=pok->sljedeci;
        auto novi=std::make_shared<Cvor>(kartica);
        if (pok->sljedeci==pocetak && ((std::find(v2.begin(),v2.end(),karta.second) < std::find(v2.begin(),v2.end(),pocetak->karta.vrijednost)) || (static_cast<int>(karta.first) < static_cast<int>(pok->karta.boja)))) pocetak=novi;
        pok->sljedeci=novi;
    }
}
void VratiPosljednjihNKarata(std::shared_ptr<Cvor> &pocetak, std::stack<std::pair<std::string,std::string>> &red, int n) {
    if (n<0) throw std::domain_error("Broj n je besmislen!");
    if (n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if (BrojKarata(pocetak)>52 || !DaLiJeIspravan(pocetak) || !DaLiJeDobroSortiran(pocetak)) throw std::logic_error("Neispravna lista!");
    static const std::vector<std::string> v{"Pik", "Tref", "Herc", "Karo"};
    static const std::vector<std::string> v2{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int brojac(0);
    while (red.size() && brojac<n) {
        if (!std::count(v.begin(),v.end(),red.top().first) || !std::count(v2.begin(),v2.end(),red.top().second)) throw std::logic_error("Neispravne karte!");
        auto karta=std::make_pair(static_cast<Boje>(std::find(v.begin(),v.end(),red.top().first)-v.begin()),red.top().second);
        if (BrojPonavljanja(pocetak,karta)) continue;
        UbaciKartu(pocetak, karta);
        red.pop();
        brojac++;
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
    auto pocetak=KreirajSpil();
    try {
        auto red=IzbaciKarteRazbrajanjem(pocetak, r, b);
        std::cout<<"U spilu trenutno ima "<<BrojKarata(pocetak)<<" karata, i to: ";
        IspisiSpil(pocetak);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int brojkarata;
        std::cin>>brojkarata;
        VratiPosljednjihNKarata(pocetak,red,brojkarata);
        std::cout<<"U spilu trenutno ima "<<BrojKarata(pocetak)<<" karata, i to: ";
        IspisiSpil(pocetak);
    }
    catch(std::exception &e) {
        std::cout<<"Izuzetak: "<<e.what();
    }
    int brojel=BrojKarata(pocetak);
    for (int i=0;i<brojel;i++) {
        std::shared_ptr<Cvor> temp=pocetak->sljedeci;
        pocetak->sljedeci=nullptr;
        pocetak=temp;
    }
    pocetak=nullptr;
	return 0;
}

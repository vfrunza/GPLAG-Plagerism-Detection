/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <queue>
#include <stack>
#include <iterator>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::pair<Boje, std::string> Par;

std::list<std::pair<Boje, std::string>> KreirajSpil()
{
    //Da sam lud - lud sam, cim sam ovako ovu funkciju uradio
    std::pair<Boje, std::string> karta;
    std::list<std::pair<Boje, std::string>> Lista;
    int i(0), j(0), brojac(0);
    for(;;) {
        if(j % 9 == 0 && brojac != 0) i++;
        if(i == 0) karta.first = Boje::Pik;
        else if(i == 1) karta.first = Boje::Tref;
        else if(i == 2) karta.first = Boje::Herc;
        else karta.first = Boje::Karo;
        if(50 + j < 58) karta.second = 50 + j;
        else karta.second = "10";
        // auto it(Lista.begin());
        Lista.push_back(karta);
        //karta = {};
        j++;
        if(j == 9) {
            karta.second = 'J';
            Lista.push_back(karta);
            karta.second = 'Q';
            Lista.push_back(karta);
            karta.second = 'K';
            Lista.push_back(karta);
            karta.second = 'A';
            Lista.push_back(karta);
            j = 0;
            brojac++;
            karta = {};
            if(brojac == 4) break;
        }
    }

    return Lista;
}

void IzbaciKarte(Spil &spil, std::multimap<Boje,std::string> &m_mapa)
{
    if(spil.empty()) return;
    if(spil.size() > 52 || spil != KreirajSpil()) throw std::logic_error("Neispravna lista!");
    //treba sada pronaci elemente spila, koji se nalaze u mapi, te ih obrisati
    //iz oba kontejnera
    for(auto it(spil.begin()); it != spil.end(); it++) {
        for(auto it2(m_mapa.begin());  it2 != m_mapa.end(); it2++) {
            if(it->first == it2->first && it->second == it2->second) {
                it = spil.erase(it);
                // std::remove(m_mapa.begin(), m_mapa.end(), *it2);
                it2 = m_mapa.erase(it2);
                if(m_mapa.empty() || spil.empty()) break;
            }
            if(m_mapa.empty() || spil.empty()) break;
        }
        if(m_mapa.empty() || spil.empty()) break;
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Spil &spil,const short int &r, int &b)
{
    std::queue<std::pair<std::string, std::string>> prazan;
    if(spil.empty()) return prazan;
    if(r < 1 || r > 52 || b < 1) throw std::logic_error("Izuzetak: Neispravni elementi za izbacivanje!");
    if(spil.size() > 52 || spil != KreirajSpil()) throw std::logic_error("Neispravna lista!");
    std::queue<std::pair<std::string, std::string>> red;
    int krug(1), br_karata(0);
    for(auto it(spil.begin()); ; /*it++*/) {
START:
        if(krug == r) {
            std::pair<std::string, std::string> par;
            std::string pik = "Pik";
            std::string tref = "Tref";
            std::string herc = "Herc";
            std::string karo = "Karo";
            if(it->first == Boje::Pik) par.first = pik;
            else if(it->first == Boje::Tref) par.first = tref;
            else if(it->first == Boje::Herc) par.first = herc;
            else if(it->first == Boje::Karo) par.first = karo;

            //par.first = boja;
            par.second = it->second;
            red.push(par);
            //Nakon sto smo je sacuvali, brisemo kartu iz spila
            it = spil.erase(it);
            br_karata++;
            krug = 1;
            if(br_karata == b) break;
            if(it == spil.end()) it = spil.begin();
            goto START;
        }
        if(br_karata == b) break;
        krug++;
        it++;
        if(it == spil.end()) it = spil.begin();
    }
    return red;
}

bool jeLiRavnoOvooo(std::queue<std::pair<std::string, std::string>> red)
{
    while(!red.empty()) {
        if(red.front().first != "Pik" && red.front().first != "Tref" && red.front().first != "Karo" && red.front().first != "Herc") return true;
        red.pop();
        if(red.empty()) return false;
    }
}

void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string, std::string>> red, int n)
{
    if(n < 0 || n > 52) throw std::domain_error("Broj n je besmislen!");
    if(n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(spil.size() > 52) throw std::logic_error("Neispravna lista!");
    if(jeLiRavnoOvooo(red)) throw std::logic_error("Neispravne karte!");
    int br(0);
    while (br < n) {
        auto temp(red.front());
        Boje poredi;
        if(temp.first == "Pik") poredi = Boje::Pik;
        else if(temp.first == "Tref") poredi = Boje::Tref;
        else if(temp.first == "Herc") poredi = Boje::Herc;
        else if(temp.first == "Karo") poredi = Boje::Karo;
        std::pair<Boje, std::string> trazi (poredi, temp.second);
        if(std::count(spil.begin(), spil.end(), trazi) == 0) {
            spil.insert(spil.begin(), trazi);
        }
        br++;
        // if(br == n) break;
        red.pop();
    }
    spil.sort( [] (const Par &x, const Par &y) -> bool {
        if(x.first == y.first) {
            if(x.second == "10" && (y.second == "J" || y.second == "Q" || y.second == "K" || y.second == "A" )) return true;
            else if(x.second  == "10" && (y.second == "2" || y.second == "3" || y.second == "4" || y.second == "5" || y.second == "6" || y.second == "7" || y.second == "8" || y.second == "9")) return false;
            else if(y.second  == "10" && (x.second == "2" || x.second == "3" || x.second == "4" || x.second == "5" || x.second == "6" || x.second == "7" || x.second == "8" || x.second == "9")) return true;
            else if(x.second == "A" && (y.second == "J" || y.second == "K" || y.second == "Q" || y.second == "10")) return false;
            else if(x.second == "K" && y.second == "A") return true;
            else if(x.second == "K" && (y.second == "Q" || y.second == "J" || y.second == "10")) return false;
            else if(x.second == "Q" && (y.second == "J" || y.second == "10")) return false;
            else if(x.second == "Q" && (y.second == "A" || y.second == "K")) return true;
            else if(x.second == "J" && y.second == "10") return false;
            else if(x.second == "J" && (y.second == "A" || y.second == "K" || y.second == "Q")) return true;
            return x.second < y.second;
        } else return x.first < y.first;
    } );
}


int main ()
{
    std::cout << "Unesite korak razbrajanja: ";
    short int korak(0);
    std::cin >> korak;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int br_za_izbaciti(0);
    std::cin >> br_za_izbaciti;
    //std::cout << "U spili trenutno ima"
    auto spil(KreirajSpil());
    std::queue<std::pair<std::string, std::string>> spilNakonIzbacivanja {};
    int br(0);
    try {
        spilNakonIzbacivanja = IzbaciKarteRazbrajanjem(spil, korak, br_za_izbaciti);
        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
        std::cout << std::endl << "Pik: " ;
        //Pik
        auto it(spil.begin());
        for(; it != spil.end(); it++, br++) {
            if(it->first == Boje::Pik) std::cout << it->second;
            if(it->first != Boje::Pik) break;
            if(br != spil.size()-1)  std::cout << " ";
        }
        br = 0;
        //Tref
        std::cout << std::endl << "Tref: ";
        for(; it != spil.end(); it++, br++) {
            if(it->first == Boje::Tref) std::cout << it->second;
            if(it->first != Boje::Tref) break;
            if(br != spil.size()-1)  std::cout << " ";
        }
        br = 0;
        //Herc
        std::cout << std::endl << "Herc: ";
        for(; it != spil.end(); it++, br++) {
            if(it->first == Boje::Herc) std::cout << it->second;
            if(it->first != Boje::Herc) break;
            if(br != spil.size()-1)  std::cout << " ";
        }
        br = 0;
        //Karo
        std::cout << std::endl << "Karo: ";
        for(; it != spil.end(); it++, br++) {
            if(it->first == Boje::Karo) std::cout << it->second;
            if(it->first != Boje::Karo) break;
            if(br != spil.size()-1)  std::cout << " ";
        }
    } catch(std::logic_error izuzetak) {
        std::cout << izuzetak.what();
        return 0;
    }

    std::cout << std::endl << "Unesite broj karata koje zelite vratiti u spil: ";
    int br_vratiti(0);
    std::cin >> br_vratiti;
    try {
        VratiPrvihNKarata(spil, spilNakonIzbacivanja, br_vratiti);
        //VRACAMO KARTE U SPIL


        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
        std::cout << std::endl << "Pik: " ;
        br = 0;
        //Pik
        auto it2(spil.begin());
        for(; it2 != spil.end(); it2++, br++) {
            if(it2->first == Boje::Pik) std::cout << it2->second;
            if(it2->first != Boje::Pik) break;
            if(br != spil.size()-1)  std::cout << " ";
        }
        br = 0;
        //Tref
        std::cout << std::endl << "Tref: ";
        for(; it2 != spil.end(); it2++, br++) {
            if(it2->first == Boje::Tref) std::cout << it2->second;
            if(it2->first != Boje::Tref) break;
            if(br != spil.size()-1)  std::cout << " ";
        }
        br = 0;
        //Herc
        std::cout << std::endl << "Herc: ";
        for(; it2 != spil.end(); it2++, br++) {
            if(it2->first == Boje::Herc) std::cout << it2->second;
            if(it2->first != Boje::Herc) break;
            if(br != spil.size()-1)  std::cout << " ";
        }
        br = 0;
        //Karo
        std::cout << std::endl << "Karo: ";
        for(; it2 != spil.end(); it2++, br++) {
            if(it2->first == Boje::Karo) std::cout << it2->second;
            if(it2->first != Boje::Karo) break;
            if(br != spil.size()-1)  std::cout << " ";
        }
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: "<< izuzetak.what();
        return 0;
    }catch(std::range_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }

    return 0;
}

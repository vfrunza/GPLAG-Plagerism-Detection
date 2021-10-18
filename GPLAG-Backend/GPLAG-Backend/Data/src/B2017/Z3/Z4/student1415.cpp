/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

typedef std::list<std::pair<Boje,std::string>> Spil;
typedef std::queue<std::pair<std::string, std::string>> RedParova;

std::vector<std::string> MoguceKarte { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
std::vector<std::string> NaziviBojaKarata {"Pik", "Tref", "Herc", "Karo"};

bool IspravnostListe (Spil karte)
{

    auto it (karte.begin());


    if(karte.size() > 52) return false;

    while (it != karte.end()) {
        if(std::find(MoguceKarte.begin(), MoguceKarte.end(), it->second) == MoguceKarte.end()) return false;

    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {


            it++;

        }
    }

}

void IspisiKarte (Spil karte)
{

    auto it (karte.begin());
    std::cout << "Pik: ";
    while(it->first == Boje::Pik) {
        std::cout << it->second << " ";
        it++;
    }

    std::cout << std::endl;

    std::cout << "Tref: ";
    while(it->first == Boje::Tref) {
        std::cout << it->second << " ";
        it++;
    }

    std::cout << std::endl;

    std::cout << "Herc: ";
    while(it->first == Boje::Herc) {
        std::cout << it->second << " ";
        it++;
    }

    std::cout << std::endl;

    std::cout << "Karo: ";
    while(it->first == Boje::Karo) {
        std::cout << it->second << " ";
        it++;
    }

    std::cout << std::endl;



}

Spil KreirajSpil ()
{
    Spil karte(52);
    auto it (karte.begin());

    Boje trenutne (Boje::Pik);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            it->first = trenutne;
            it->second = MoguceKarte.at(j);

            it++;
        }
        trenutne = Boje(i + 1);
    }
    return karte;
}

void IzbaciKarte (Spil &karte, std::multimap<Boje, std::string> &mapa)
{
    if(karte.size() > 52) throw std::logic_error("Neispravna lista!");
    int brojac(0);

    for(auto t = mapa.begin(); t != mapa.end(); t++) {
        std::remove_if(karte.begin(), karte.end(), [t, &brojac](std::pair<Boje, std::string> x) {
            if (t->first == x.first && t->second == x.second) {
                brojac++;
                return true;
            }

        });

    }
    auto velicina (karte.size());
    karte.resize(velicina - brojac);

}


RedParova IzbaciKarteRazbrajanjem (Spil &karte, const short int &korak, const int &broj_izbacivanja)
{
    if(korak < 1 || korak > 52 || broj_izbacivanja < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");

    RedParova rezultat;
    auto it (karte.begin());

    for(int i = 0; i < broj_izbacivanja; i++) {
        for(int j = 0; j < korak; j++) {

            it++;

        }

        

        if(it == karte.end()) it = karte.begin();
        rezultat.push (std::make_pair(NaziviBojaKarata[int(it->first)] , it->second));
        it = karte.erase(it);
        it--;


    }
    return rezultat;
}

void VratiPrvihNKarata (Spil &karte, RedParova &red, int n)
{
    for(int i = 0; i < n; i++) {
        auto temp (red.front());

        for(int j = 0; j < 4; j++) {
            if(NaziviBojaKarata.at(j) == temp.first)
                karte.push_back(std::make_pair(static_cast<Boje> (j), temp.second));

        }
        red.pop();
    }

    karte.sort();
}

int main ()
{

    auto karte (KreirajSpil());

    std::cout << "Unesite korak razbrajanja: ";
    int korak;
    std::cin >> korak;

    std::cout << "Unesite broj karata koje zelize izbaciti: ";
    int n;
    std::cin >> n;

    auto red (IzbaciKarteRazbrajanjem(karte, korak, n));

    std::cout << "U spilu trenutno ima " << karte.size() << " karata, i to: " << std::endl;
    IspisiKarte(karte);

    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    int vrati;
    std::cin >> vrati;

    VratiPrvihNKarata(karte, red, vrati);

    std::cout << "U spilu trenutno ima " << karte.size() << " karata i to: " << std::endl;
    IspisiKarte(karte);



    return 0;
}

/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};


typedef std::list<std::pair<Boje, std::string>> Spil;

Spil KreirajSpil()
{
    Spil rezultat;
    const std::string vrijednosti[13] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            rezultat.push_back(std::make_pair(Boje(i), vrijednosti[j]));
        }
    }
    return rezultat;
}

void ValidacijaSpila (Spil spil)
{
    const std::string vrijednosti[13] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    auto iter(spil.begin());
    while (iter != spil.end()) {

        int i, j;
        for(i=0; i<4; i++) {
            for(j=0; j<13; j++) {
                if(iter->first == Boje(i) && iter->second == vrijednosti[j]) break;
            }
            if(j!=13) break;
        } 
        if(i==4 && j==13) throw std::logic_error ("Neispravna lista!");
    

        if(iter != spil.begin() && iter != --spil.end()) {
            auto i1(iter); auto i2(iter);
            i1--; i2++;
            i=(std::find(vrijednosti, vrijednosti+13, iter->second)-vrijednosti);
            j=(std::find(vrijednosti, vrijednosti+13, i1->second)-vrijednosti);
            int k(std::find(vrijednosti, vrijednosti+13, i2->second)-vrijednosti);
            if(!(((iter->first == i1->first && i>j ) || (iter->first > i1->first)) && ((iter->first == i2->first && i<k) || (iter->first < i2->first)))) throw std::logic_error("Neispravna lista!");
        } else if(iter == spil.begin()) {
            auto i2(iter);
            i2++;
            i=(std::find(vrijednosti, vrijednosti+13, iter->second)-vrijednosti);
            int k(std::find(vrijednosti, vrijednosti+13, i2->second)-vrijednosti);
            if(!((iter->first == i2->first && i<k) || (iter->first < i2->first))) throw std::logic_error("Neispravna lista!");
        } else if(iter == --spil.end()) {
            auto i1(iter);  
            i1--;
            i=(std::find(vrijednosti, vrijednosti+13, iter->second)-vrijednosti);
            j=(std::find(vrijednosti, vrijednosti+13, i1->second)-vrijednosti);
            if(!((iter->first == i1->first && i>j ) || (iter->first > i1->first))) throw std::logic_error("Neispravna lista!");
        }

        iter++;
    }
    if(iter != spil.end()) throw std::logic_error ("Neispravna lista!");
}


void IzbaciKarte (Spil &spil, std::multimap <Boje, std::string> &za_izbaciti)
{
    try {
        ValidacijaSpila(spil);
    } catch (...) {
        throw;
    }

    auto it(za_izbaciti.begin());
    while (it != za_izbaciti.end()) {
        auto pozicija = std::find_if(spil.begin(), spil.end(), [=](std::pair<Boje, std::string> p) {
            return (((*it).first == p.first) && ((*it).second == p.second));
        });

        if(pozicija != spil.end()) {
            spil.erase(pozicija);
            za_izbaciti.erase(it);
        }
        it++;
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Spil &spil, const short int &r, const int &b)
{
    if(r < 1 || r > 52 || b < 1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    try {
        ValidacijaSpila(spil);
    } catch (...) {
        throw;
    }

    const std::string boje[4] {"Pik", "Tref", "Herc", "Karo"};

    int izbaceno(0); 
    auto it(spil.begin());
    std::queue<std::pair<std::string, std::string>> izbaceni_parovi;
    while(izbaceno != b && (spil.begin() != spil.end())) {
        int r_tmp;
        for(r_tmp=0; r_tmp<r; r_tmp++) {
            if(it != --spil.end()) it++;
            else it=spil.begin();
        }
        if(it == spil.begin()) it=--spil.end();
        else it--;
        izbaceni_parovi.push(make_pair(boje[int((*it).first)], (*it).second));
        it = spil.erase(it);
        if(it == spil.end()) it = spil.begin(); 
        izbaceno++;
    }
    return izbaceni_parovi;
}

void VratiPrvihNKarata (Spil &spil,  std::queue<std::pair<std::string, std::string>> &izbaceni_parovi, int n )
{
    if(n<0) throw std::domain_error ("Broj n je besmislen!");
    if(n> izbaceni_parovi.size()) throw std::range_error ("Nedovoljno karata u redu!");
    

    const std::string vrijednosti[13] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const std::string boje[4] {"Pik", "Tref", "Herc", "Karo"};


    try {
        ValidacijaSpila(spil);
    } catch (...) {
        throw;
    }

    int brojac(0);
    while (brojac != n) {
        std::pair<std::string, std::string> tmp(make_pair(izbaceni_parovi.front().first, izbaceni_parovi.front().second));
        std::pair<Boje, std::string> tmp1;
        tmp1.second = tmp.second;

        int i;
        for(i=0; i<4; i++) {
            if(boje[i] == tmp.first) {
                tmp1.first = Boje(i);
                break;
            }
        }
        if(i==4) throw std::logic_error("Neispravne karte!");
        //validacija podataka u redu
        int j;
        for(i=0; i<4; i++) {
            for(j=0; j<13; j++) {
                if(tmp1.second == vrijednosti[j]) break;
            }
            if(j!=13) break;
        }
        if(i==4 && j==13) throw std::logic_error ("Neispravne karte!");

        auto pozicija = std::find_if(spil.begin(), spil.end(), [=](std::pair<Boje, std::string> p) {
            int i(std::find(vrijednosti, vrijednosti+13, p.second)-vrijednosti);
            int j(std::find(vrijednosti, vrijednosti+13, tmp1.second)-vrijednosti);
            return((p.first == tmp1.first && i>j) || p.first > tmp1.first);
        });
        spil.insert(pozicija, tmp1);
        izbaceni_parovi.pop();
        brojac++;
    }

}




int main ()
{
    try {
        const std::string boje[4] {"Pik", "Tref", "Herc", "Karo"};

        std::cout << "Unesite korak razbrajanja: ";
        short int r;
        std::cin >>  r;

        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin >> b;

        Spil spil(KreirajSpil());
        auto red = IzbaciKarteRazbrajanjem(spil, r, b);

        std::cout << "U spilu trenutno ima " << spil.size() <<" karata, i to: " << std::endl;
        for(int i=0; i<4; i++) {
            std::cout << boje[i] << ": ";
            for(auto e: spil) {
                if(int(e.first) == i) std::cout << e.second << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin >> n;

        VratiPrvihNKarata(spil, red, n);

        std::cout << "U spilu trenutno ima " << spil.size() <<" karata, i to: " << std::endl;
        for(int i=0; i<4; i++) {
            std::cout << boje[i] << ": ";
            for(auto e: spil) {
                if(int(e.first) == i) std::cout << e.second << " ";
            }
            std::cout  << std::endl;
        }

    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::logic_error izuzetak) {
        std::cout <<  "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::range_error izuzetak) { 
        std::cout <<  "Izuzetak: " << izuzetak.what() << std::endl;
    }

    return 0;
}
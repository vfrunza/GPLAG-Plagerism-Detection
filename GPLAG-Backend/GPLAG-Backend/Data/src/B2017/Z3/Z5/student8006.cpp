#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <stack>

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::stack<std::pair<Boje, std::string>> Stek;

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};

int VrijednostKarte(const std::string &karta) {
    if (karta == "2") return 1;
    else if (karta == "3") return 2;
    else if (karta == "4") return 3;
    else if (karta == "5") return 4;
    else if (karta == "6") return 5;
    else if (karta == "7") return 6;
    else if (karta == "8") return 7;
    else if (karta == "9") return 8;
    else if (karta == "10") return 9;
    else if (karta == "J") return 10;
    else if (karta == "Q") return 11;
    else if (karta == "K") return 12;
    else if (karta == "A") return 13;
    return 0;
}

void UnistiSpil(Cvor *spil) {
    if (!spil) return;
    auto prvi(spil);
    for (;;) {
        auto trenutni(spil->sljedeci);
        delete spil;
        spil = trenutni;
        if (spil == prvi) break;
    }
}

Cvor *KreirajSpil() {
    const std::string vrijednost[13]{"2", "3", "4", "5", "6", "7", "8", "9",
        "10", "J", "Q", "K", "A"};
    Cvor *spil(nullptr), *karta(nullptr);
    try {
        for (int i = 0; i < 52; i++) {
            Cvor *nova = new Cvor();
            if (!spil) spil = nova;
            else karta->sljedeci = nova;
            if (i < 13) nova->karta.boja = Boje::Pik;
            else if (i < 26) nova->karta.boja = Boje::Tref;
            else if (i < 39) nova->karta.boja = Boje::Herc;
            else nova->karta.boja = Boje::Karo;
            nova->karta.vrijednost = vrijednost[i%13];
            karta = nova;
            karta->sljedeci = spil;
        }
    }
    catch (...) {
        UnistiSpil(spil);
        throw;
    }
    return spil;
}

void ProvjeriSpil(Cvor *spil) {
    if (!spil) return;
    Cvor *karta(spil);
    for (int i = 0; i <= 52; i++) {
        if (!VrijednostKarte(karta->karta.vrijednost))
            throw std::logic_error("Neispravna lista!");
        if (karta->sljedeci == spil) return;
        if (karta->karta.boja > karta->sljedeci->karta.boja
            || (karta->karta.boja == karta->sljedeci->karta.boja
            && VrijednostKarte(karta->karta.vrijednost) >= VrijednostKarte(karta->sljedeci->karta.vrijednost)))
            throw std::logic_error("Neispravna lista!");
        karta = karta->sljedeci;
    }        
    throw std::logic_error("Neispravna lista!");
}

void IzbaciKarte(Cvor *&spil, std::multimap<Boje, std::string> &red) {
    ProvjeriSpil(spil);
    for (auto it = red.begin(); it != red.end(); it++) {
        if (!spil) return;
        auto prethodna(spil), trenutna(prethodna->sljedeci), naredna(trenutna->sljedeci);
        for (;;) {
            if (trenutna->karta.boja == it->first && VrijednostKarte(trenutna->karta.vrijednost) == VrijednostKarte(it->second)) {
                if (prethodna == trenutna) {
                    delete trenutna; spil = nullptr;
                }    
                else delete trenutna;
                if (spil == trenutna) spil = naredna;
                prethodna->sljedeci = naredna;
                trenutna = naredna;
                red.erase(it);
            }
            if (trenutna == spil) break;
            prethodna = trenutna; 
            trenutna = naredna;
            naredna = naredna->sljedeci;
        }
    }
}

Stek IzbaciKarteRazbrajanjem(Cvor *&spil, short int r, int b) {
    try {
        ProvjeriSpil(spil);
        if (r < 1 || r > 52 || b < 1) throw std::logic_error("Izuzetak");
    }
    catch (std::logic_error e) {
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    }
    Stek izbacene;
    auto prethodni(spil);
    while (prethodni->sljedeci != spil) prethodni = prethodni->sljedeci;
    auto trenutni(spil), naredni(trenutni->sljedeci);
    for (int br_izbacenih = 0; br_izbacenih < b; br_izbacenih++) {
        if (prethodni == trenutni) {
            izbacene.push(std::make_pair(trenutni->karta.boja, trenutni->karta.vrijednost));
            delete trenutni;
            spil = nullptr; break;
        }
        for (short int korak = 1; korak < r; korak++) {
            prethodni = trenutni; trenutni = naredni; naredni = naredni->sljedeci;
        }
        izbacene.push(std::make_pair(trenutni->karta.boja, trenutni->karta.vrijednost));
        delete trenutni;
        prethodni->sljedeci = naredni; trenutni = naredni; naredni = naredni->sljedeci;
    }
    return izbacene;
}

void ProvjeriStek(Stek s) {
    while (!s.empty()) {
        if (!VrijednostKarte(s.top().second)) 
            throw std::logic_error("Neispravne karte!");
        s.pop();
    }
}

void VratiPosljednjihNKarata(Cvor *&spil, Stek &stek, int n) {
    if (n < 0) throw std::domain_error("Broj n je besmislen!");
    if (n > stek.size()) throw std::range_error("Nedovoljno karata u steku!");
    ProvjeriStek(stek); ProvjeriSpil(spil);
    for (int i = 0; i < n; i++) {
        auto prethodni(spil);
        while (prethodni->sljedeci != spil) prethodni = prethodni->sljedeci;
        auto trenutni(spil);
        for (;;) {
            if (!spil || trenutni->karta.boja > stek.top().first 
            || (trenutni->karta.boja == stek.top().first
            && VrijednostKarte(trenutni->karta.vrijednost) >= VrijednostKarte(stek.top().second))) break;
            prethodni = trenutni; trenutni = trenutni->sljedeci;
            if (trenutni == spil) break;
        }
        if (!spil) {
            spil = new Cvor();
            spil->sljedeci = spil;
            spil->karta.boja = stek.top().first;
            spil->karta.vrijednost = stek.top().second;
            stek.pop(); continue;
        }
        if (trenutni->karta.boja == stek.top().first
        && VrijednostKarte(trenutni->karta.vrijednost) == VrijednostKarte(stek.top().second)) continue;
        trenutni = new Cvor();
        if (prethodni->sljedeci == spil && (spil->karta.boja > stek.top().first 
            || (spil->karta.boja == stek.top().first
            && VrijednostKarte(spil->karta.vrijednost) >= VrijednostKarte(stek.top().second))))
                spil = trenutni;
        trenutni->karta.boja = stek.top().first;
        trenutni->karta.vrijednost = stek.top().second;
        trenutni->sljedeci = prethodni->sljedeci; prethodni->sljedeci = trenutni;
        stek.pop();
    }
}

int BrojKarata(Cvor *spil) {
    if (!spil) return 0;
    auto trenutna(spil);
    int i(1);
    while (trenutna->sljedeci != spil) {
        trenutna = trenutna->sljedeci; i++;
    }
    return i;
}

void IspisiZaBoju(Cvor *spil, Boje b) {
    auto trenutna(spil);
    for (;;) {
        if (trenutna->karta.boja == b) std::cout << trenutna->karta.vrijednost << " ";
        if (trenutna->sljedeci == spil) break;
        trenutna = trenutna->sljedeci;
    }
    std::cout << std::endl;
}

void IspisiSpil(Cvor *spil) {
    std::cout << "Pik: "; IspisiZaBoju(spil, Boje::Pik);
    std::cout << "Tref: "; IspisiZaBoju(spil, Boje::Tref);
    std::cout << "Herc: "; IspisiZaBoju(spil, Boje::Herc);
    std::cout << "Karo: "; IspisiZaBoju(spil, Boje::Karo);
}

int main ()
{
    short int r;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    int b;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    Cvor *spil(nullptr);
    try {
        spil = KreirajSpil();
        auto izbacene(IzbaciKarteRazbrajanjem(spil, r, b));
        std::cout << "U spilu trenutno ima " << BrojKarata(spil) << " karata, i to:" 
            << std::endl;
        IspisiSpil(spil);
        int n;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPosljednjihNKarata(spil, izbacene, n);
        std::cout << "U spilu trenutno ima " << BrojKarata(spil) << " karata, i to:"
            << std::endl;
        IspisiSpil(spil);
    }
    catch (std::domain_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    catch (std::range_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    catch (...) {}
    UnistiSpil(spil);
	return 0;
}

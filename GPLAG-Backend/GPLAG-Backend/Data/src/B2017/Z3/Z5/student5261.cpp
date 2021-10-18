#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <stack>
#include <new>
//Provjereno, poslano.
enum class Boje { Pik, Tref, Herc, Karo };
std::string _karte_[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
std::string _boje_[4]{"Pik", "Tref", "Herc", "Karo"};
struct Karta
{
    Boje boja;
    std::string vrijednost;
};
struct Cvor
{
    Karta karta;
    Cvor *sljedeci;
};
bool manji(const Karta &a, const Karta &b)
{
    return int(a.boja) < int(b.boja) || (a.boja == b.boja && std::find(_karte_, _karte_ + 13, a.vrijednost) < std::find(_karte_, _karte_ + 13, b.vrijednost));
}
bool jednaki(const Karta &a, const Karta &b) { return a.boja == b.boja && a.vrijednost == b.vrijednost; }
int velicina(Cvor *spil)
{
    int vel(0);
    for (Cvor *c(spil); c != nullptr && (c != spil || vel == 0); c = c->sljedeci) ++vel;
    return vel;
}
Cvor *zadnji_element(Cvor *spil)
{
    for (Cvor *c(spil); c != nullptr; c = c->sljedeci)
        if (c->sljedeci == spil) return c;
    return nullptr;
}
void provjeri_spil(Cvor *spil)
{
    Cvor *c(spil);
    for (int i(0); i < 52 && c != nullptr && (i != 0 && c != spil); ++i, c = c->sljedeci)
        if (!c->sljedeci || (c->sljedeci != spil && (manji(c->sljedeci->karta, c->karta) || jednaki(c->karta, c->sljedeci->karta)))
        || std::find(_karte_, _karte_+13, c->karta.vrijednost) == _karte_+13)
            throw std::logic_error("Neispravna lista!");
    if (c != spil) throw std::logic_error("Neispravna lista!");
}
void izbaci(Cvor *&prvi, Cvor *&zadnji, Cvor *&prije)
{
    Cvor *&zrtva(prije->sljedeci);
    if (zadnji == nullptr) zadnji = zadnji_element(prvi);
    Cvor *pom(zrtva->sljedeci);
    delete zrtva;
    if (prvi == zadnji) { prije->sljedeci = prvi = zadnji = nullptr; return; } //Ako izbacujemo jedini element
    if (zrtva == prvi) zadnji->sljedeci = prvi = pom; //Ako izbacujemo prvi element
    else if (zrtva == zadnji) zadnji = prije; //Ako izbacujemo zadnji element
    prije->sljedeci = pom;
}
void ubaci(Cvor *&prvi, Cvor *&zadnji, Cvor *&prije, const Karta &k)
{
    if (zadnji == nullptr) zadnji = zadnji_element(prvi);
    Cvor *pom(prije->sljedeci), *&novi(prije->sljedeci);
    novi = new Cvor{ k, pom };
    if (prije == zadnji) zadnji = novi; //Ako ubacujemo element na kraj
    else if (pom == prvi) prvi = novi; //Ako ubacujemo element na pocetak
    if (!zadnji) zadnji = prvi; //Ako je spil prethodno bio prazan
    zadnji->sljedeci = prvi;
}
void ispisi(Cvor *spil)
{
    std::cout << "U spilu trenutno ima " << velicina(spil) << " karata, i to:";
    Cvor *c(spil);
    bool prvi(true);
    for (int i(0); i < 4; ++i)
    {
        std::cout << '\n' << _boje_[i] << ':';
        for (; c != nullptr && (c != spil || prvi) && c->karta.boja == Boje(i); c = c->sljedeci)
        {
            if (prvi) prvi = false;
            std::cout << ' ' << c->karta.vrijednost;
        }
    }
}
//?Da li azuriramo spil na nullptr
void UnistiSpil(Cvor *spil)
{
    bool prvi(true);
    for (Cvor *c(spil); c != nullptr && (c != spil || prvi); )
    {
        if (prvi) prvi = false;
        Cvor *pom(c->sljedeci);
        delete c;
        c = pom;
    }
}
Cvor *KreirajSpil()
{
    Cvor *cvor(new Cvor), *c(cvor);
    try
    {
        for (int i(0); i < 4; ++i)
            for (int j(0); j < 13; ++j, c = c->sljedeci)
                *c = { { Boje(i), _karte_[j] }, (i == 3 && j == 12 ? cvor : new Cvor) };
    }
    catch (...) { UnistiSpil(cvor); throw; }
    return cvor;
}
void IzbaciKarte(Cvor *&spil, std::multimap<Boje, std::string> &m)
{
    provjeri_spil(spil);
    Cvor c{ {}, spil }, *prije(&c), *zadnji(zadnji_element(spil));
    for (; prije->sljedeci && prije != zadnji; )
    {
        auto j(std::find(m.begin(), m.end(), std::pair<const Boje, std::string> { prije->sljedeci->karta.boja, prije->sljedeci->karta.vrijednost }));
        if (j != m.end())
        {
            izbaci(spil, zadnji, prije);
            auto x(*j);
            for (auto k(j = m.erase(j)); k != m.end() && (k = std::find(k, m.end(), x)) != m.end();) k = m.erase(k);
        }
        else prije = prije->sljedeci;
    }
}
std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Cvor *&spil, const short int &r, const int &b)
{
    if (r < 1 || r > 52 || b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    provjeri_spil(spil);
    std::stack<std::pair<std::string, std::string>> stek;
    if (!spil) return stek;
    Cvor c{ {}, spil }, *prije(&c), *zadnji{};
    int pozicija(0), br(b), vel(velicina(spil));
    for (int i((r-1) % vel); prije->sljedeci && br > 0; --br, i = (i + r-1) % vel)
    {
        if (i > pozicija)
            for (; pozicija < i; ++pozicija) prije = prije->sljedeci;
        else if (i < pozicija)
            for (pozicija = 0, (prije = &c)->sljedeci = spil; pozicija < i; ++pozicija) prije = prije->sljedeci;
        stek.push( { _boje_[int(prije->sljedeci->karta.boja)], prije->sljedeci->karta.vrijednost } );
        izbaci(spil, zadnji, prije);
        if (--vel == 0) break;
    }
    return stek;
}
//?Sta uraditi ako alokacija ne uspije?
void VratiPosljednjihNKarata(Cvor *&spil, std::stack<std::pair<std::string, std::string>> &stek, int n)
{
    if (n < 0) throw std::domain_error("Broj n je besmislen!");
    if (n > stek.size()) throw std::range_error("Nedovoljno karata u steku!");
    provjeri_spil(spil);
    Cvor *zadnji(zadnji_element(spil));
    for (int i(0); i < n; ++i)
    {
        if (std::find(_boje_, _boje_+4, stek.top().first) == _boje_+4 || std::find(_karte_, _karte_+13, stek.top().second) == _karte_+13)
            throw std::logic_error("Neispravne karte!");
        Karta karta{ Boje(std::find(_boje_, _boje_+4, stek.top().first) - _boje_), stek.top().second };
        Cvor c{ {}, spil }, *za_ubaciti(&c);
        bool prvi(true);
        for (Cvor *c(spil); c != nullptr && (c != spil || prvi); c = c->sljedeci)
        {
            if (prvi) prvi = false;
            if (jednaki(c->karta, karta)) goto preskok;
            if (manji(c->karta, karta)) za_ubaciti = c;
        }
        ubaci(spil, zadnji, za_ubaciti, karta);
        preskok:
        stek.pop();
    }
}
int main()
{
    int r, b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    Cvor *spil;
    try
    {
        spil = KreirajSpil();
        auto izbacene(IzbaciKarteRazbrajanjem(spil, r, b));
        ispisi(spil);
        std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
        std::cin >> b;
        VratiPosljednjihNKarata(spil, izbacene, b);
        ispisi(spil);
    }
    catch (const std::exception &e) { std::cout << "Izuzetak: " << e.what(); }
    catch (...) {}
    UnistiSpil(spil);
	return 0;
}
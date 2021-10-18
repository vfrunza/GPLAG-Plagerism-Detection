/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <algorithm>

#include <string>
#include <list>
#include <queue>
#include <map>

#include <stdexcept>

enum class Boje { Pik, Tref, Herc, Karo };
std::string BojeSlovno[]{"Pik", "Tref", "Herc", "Karo"};
std::string Vrijednosti[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

typedef std::pair<Boje, std::string> Karta;
typedef std::pair<std::string, std::string> StrPar;

// PROTOTIPI
void validateDeck(const std::list<Karta>&);

void IspisiSpil(const std::list<Karta>&);

std::list<Karta> KreirajSpil();
void IzbaciKarte(std::list<Karta>&, std::multimap<Boje, std::string>&);
std::queue<StrPar> IzbaciKarteRazbrajanjem(std::list<Karta>&, const short int&, const int&);
void VratiPrvihNKarata(std::list<Karta>&, std::queue<StrPar>&, int);

int main ()
{
    auto spil = std::move(KreirajSpil());
    
    try {
        short int r;
        std::cout << "Unesite korak razbrajanja: ";
        std::cin >> r;
        
        int n;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> n;
        
        auto redVracanja = std::move(IzbaciKarteRazbrajanjem(spil, r, n));
        IspisiSpil(spil);
        
        int brVracanja;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> brVracanja;
        
        VratiPrvihNKarata(spil, redVracanja, brVracanja);
        IspisiSpil(spil);
    }
    catch (const std::exception &ex) {
        std::cout << "Izuzetak: " << ex.what() << std::endl;
    }
    auto spil = std::move(KreirajSpil());
    
    
    
	return 0;
}

std::list<Karta> KreirajSpil()
{
    std::list<Karta> res;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            res.push_back({Boje(i), Vrijednosti[j]});
            
    return res;
}

void IzbaciKarte(std::list<Karta> &spil, std::multimap<Boje, std::string> &zaIzbaciti)
{
    validateDeck(spil);
    
    for (auto it = zaIzbaciti.begin(); it != zaIzbaciti.end(); it++)
    {
        auto nadjena = std::find(spil.begin(), spil.end(), std::pair<Boje, std::string>(*it));
        if (nadjena != spil.end())
        {
            spil.erase(nadjena);
            zaIzbaciti.erase(it--);
        }
    }
}

std::queue<StrPar> IzbaciKarteRazbrajanjem(std::list<Karta> &spil, const short int &korak, const int &brZaIzbaciti)
{
    if (korak < 1 || korak > 52 || brZaIzbaciti < 1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
        
    validateDeck(spil);
    
    std::queue<StrPar> res;
    
    auto pozicija = spil.begin();
    for (int koliko = 0; koliko < brZaIzbaciti && spil.size() > 0; koliko++)
    {
        for (int koracanje = 1; koracanje < korak; koracanje++)
        {
            pozicija++;
            if (pozicija == spil.end())
                pozicija = spil.begin();
        }
        
        res.push(std::make_pair(BojeSlovno[int(pozicija->first)], pozicija->second));
        spil.erase(pozicija++);
        if (pozicija == spil.end())
            pozicija = spil.begin();
    }
    
    return res;
}

void VratiPrvihNKarata(std::list<Karta> &spil, std::queue<StrPar> &zaUbaciti, int n)
{
    bool isValidCard(const Karta&);
    bool cmpCards(const Karta&, const Karta&);
    
    if (n > int(zaUbaciti.size())) // Poredjenje dovodi da n "postane" unsigned
        throw std::range_error("Nedovoljno karata u redu!");
        
    if (n < 0)
        throw std::domain_error("Broj n je besmislen!");
    
    validateDeck(spil);
    
    for (int i = 0; i < n; i++)
    {
        Karta ubacanje{
            Boje(std::find(BojeSlovno, BojeSlovno + 4, zaUbaciti.front().first) - BojeSlovno),
            zaUbaciti.front().second
        };
        
        if (!isValidCard(ubacanje))
            throw std::logic_error("Neispravne karte!");
          
        auto gdjeUbaciti = std::lower_bound(spil.begin(), spil.end(), ubacanje, cmpCards);
        if (gdjeUbaciti == spil.end() || *gdjeUbaciti != ubacanje)
            spil.insert(gdjeUbaciti, ubacanje);
        
        zaUbaciti.pop();
    }
}

void IspisiSpil(const std::list<Karta> &spil)
{
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;
    
    
    auto poz = spil.begin();
    for (int i = 0; i < 4; i++)
    {
        std::cout << BojeSlovno[i] << ": ";
        
        while (poz != spil.end() && poz->first == Boje(i))
        {
            std::cout << poz->second << " ";
            poz++;
        }
        std::cout << std::endl;
    }
}

void validateDeck(const std::list<Karta> &deck)
{
    bool validCards(const std::list<Karta>&);
    bool isSorted(const std::list<Karta>&);
    
    if (deck.size() > 52 || !validCards(deck) || !isSorted(deck))
        throw std::logic_error("Neispravna lista!");
}

bool validCards(const std::list<Karta> &deck)
{
    bool isValidCard(const Karta&);
    
    for (const auto &card : deck)
        if (!isValidCard(card))
            return false;
    
    return true;
}

bool isValidCard(const Karta &card)
{
    return !(int(card.first) < 0 ||
             int(card.first) > 3 ||
             std::find(Vrijednosti, Vrijednosti + 13, card.second) == Vrijednosti + 13);
}

bool isSorted(const std::list<Karta> &deck)
{
    bool cmpCards(const Karta&, const Karta&);
    
    auto next(deck.begin());
    next++;
    
    for (auto it = deck.begin(); next != deck.end(); it++, next++)
        if (!cmpCards(*it, *next) || *it == *next)
            return false;
                
    return true;
}

bool cmpCards(const Karta &card1, const Karta &card2)
{
    return card1.first < card2.first || (card1.first == card2.first && 
        std::find(Vrijednosti, Vrijednosti + 13, card1.second) < std::find(Vrijednosti, Vrijednosti + 13, card2.second));
}
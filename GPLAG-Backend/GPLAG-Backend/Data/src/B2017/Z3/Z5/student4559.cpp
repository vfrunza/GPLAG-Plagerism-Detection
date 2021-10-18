/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <utility>
#include <algorithm>

#include <stack>
#include <map>

#include <stdexcept>

enum class Boje { Pik, Tref, Herc, Karo };
std::string BojeSlovno[]{"Pik", "Tref", "Herc", "Karo"};
std::string Vrijednosti[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

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

typedef std::pair<std::string, std::string> StrPar;

void validateDeck(Cvor*);
unsigned int size(Cvor*);
Cvor *ending(Cvor*);

void deleteFrom(Cvor*&, Cvor*&, Cvor*);

void IspisiSpil(Cvor*);

Cvor *KreirajSpil();
void IzbaciKarte(Cvor*&, std::multimap<Boje, std::string>&);
std::stack<StrPar> IzbaciKarteRazbrajanjem(Cvor*&, const short int&, const int&);
void VratiPosljednjihNKarata(Cvor*&, std::stack<StrPar>&, int);

void UnistiSpil(Cvor*);

int main ()
{
    Cvor *spil = nullptr;
    try {
        spil = KreirajSpil();
        
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
        
        VratiPosljednjihNKarata(spil, redVracanja, brVracanja);
        IspisiSpil(spil);
        
    }
    catch (const std::exception &ex) {
        std::cout << "Izuzetak: " << ex.what() << std::endl;
    }
    
    UnistiSpil(spil);
    
	return 0;
}

Cvor *KreirajSpil()
{
    Cvor *begin{nullptr}, *previous;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
        {
            Cvor *node{nullptr};
            try {
                node = new Cvor{{Boje(i), Vrijednosti[j]}, begin};
            }
            catch (...) {
                //Izbrisi sto vec postoji
                throw;
            }
            
            if (!begin)
                begin = node;
            else
                previous->sljedeci = node;
                
            previous = node;
        }
        
    return begin;
}

void IzbaciKarte(Cvor *&spil, std::multimap<Boje, std::string> &zaIzbaciti)
{
    if (!spil)
        return ;
    
    validateDeck(spil);
    
    auto pret = ending(spil);
    auto trenutna = spil;
    do
    {
        auto nadjena = std::find(zaIzbaciti.begin(), zaIzbaciti.end(), std::pair<const Boje, std::string>(trenutna->karta.boja, trenutna->karta.vrijednost));
        if (nadjena != zaIzbaciti.end())
        {
            deleteFrom(spil, pret, trenutna);
            zaIzbaciti.erase(nadjena);
            if (!spil)
                return ;
        }
        else
            pret = trenutna;
            
        trenutna = pret->sljedeci;
    }
    while (trenutna != spil);
}

std::stack<StrPar> IzbaciKarteRazbrajanjem(Cvor *&spil, const short int &korak, const int &brZaIzbaciti)
{
    if (korak < 1 || korak > 52 || brZaIzbaciti < 1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
        
    validateDeck(spil);
    
    std::stack<StrPar> res;
    
    auto pret = ending(spil);
    auto pozicija = spil;
    for (int koliko = 0; koliko < brZaIzbaciti; koliko++)
    {
        for (int koracanje = 1; koracanje < korak; koracanje++) {
            pret = pozicija;
            pozicija = pozicija->sljedeci;
        }
            
        res.push(std::make_pair(BojeSlovno[int(pozicija->karta.boja)], pozicija->karta.vrijednost));
        deleteFrom(spil, pret, pozicija);
        if (!spil)
            return res;
        
        pozicija = pret->sljedeci;
    }
    
    return res;
}

void VratiPosljednjihNKarata(Cvor *&spil, std::stack<StrPar> &zaUbaciti, int n)
{
    bool isValidCard(const Karta&);
    bool cmpCards(const Karta&, const Karta&);
    Cvor *lower_bound(Cvor*, const Karta&);
    
    if (n > int(zaUbaciti.size()))
        throw std::range_error("Nedovoljno karata u steku!");
        
    if (n < 0)
        throw std::domain_error("Broj n je besmislen!");
        
    validateDeck(spil);
    
    for (int i = 0; i < n; i++)
    {
        Karta ubacanje{
            Boje(std::find(BojeSlovno, BojeSlovno + 4, zaUbaciti.top().first) - BojeSlovno),
            zaUbaciti.top().second
        };
        
        if (!isValidCard(ubacanje))
            throw std::logic_error("Neispravne karte!");
            
        if (spil == nullptr)
        {
            spil = new Cvor{ubacanje, nullptr};
            spil->sljedeci = spil;
        }
        else
        {
            auto gdjeUbaciti = lower_bound(spil, ubacanje);
            if (gdjeUbaciti->karta.boja != ubacanje.boja ||
                gdjeUbaciti->karta.vrijednost != ubacanje.vrijednost)
                {
                    auto pret = ending(gdjeUbaciti);
                    
                    auto noviCvor = new Cvor{ubacanje, gdjeUbaciti};
                    pret->sljedeci = noviCvor;
                    
                    if (gdjeUbaciti == spil && cmpCards(ubacanje, spil->karta))
                        spil = noviCvor;
                }
        }
            
        zaUbaciti.pop();
    }
}

Cvor *lower_bound(Cvor *deck, const Karta &card)
{
    bool cmpCards(const Karta&, const Karta&);
    
    if (!deck)
        return deck;
    
    auto it = deck;
    do
    {
        if (!cmpCards(it->karta, card))
            break;
        it = it->sljedeci;
    }   
    while (it != deck);
    
    return it;
}

void IspisiSpil(Cvor *spil)
{
    std::cout << "U spilu trenutno ima " << size(spil) << " karata, i to:" << std::endl;
    
    auto it = spil;
    for (int i = 0; i < 4; i++)
    {
        std::cout << BojeSlovno[i] << ": ";
        do {
            if (!it || it->karta.boja != Boje(i))
                break;
            
            std::cout << it->karta.vrijednost << " ";
            it = it->sljedeci;
        }
        while (it != spil);
        
        std::cout << std::endl;
    }
}

void validateDeck(Cvor *deck)
{
    bool validCards(Cvor*);
    bool isSorted(Cvor*);
    
    if (size(deck) > 52 || !validCards(deck) || !isSorted(deck))
        throw std::logic_error("Neispravna lista!");
    return ;
}

bool validCards(Cvor *deck)
{
    bool isValidCard(const Karta&);
    
    if (!deck)
        return true;
    
    auto it = deck;
    do {
        if (!isValidCard(it->karta))
            return false;
            
        it = it->sljedeci;
    }
    while (it != deck);
    
    return true;
}

bool isValidCard(const Karta &card)
{
    return !(int(card.boja) < 0 ||
             int(card.boja) > 3 ||
             std::find(Vrijednosti, Vrijednosti + 13, card.vrijednost) == Vrijednosti + 13);
}

bool isSorted(Cvor *deck)
{
    bool cmpCards(const Karta&, const Karta&);
    
    if (!deck)
        return true;
    
    auto next = deck->sljedeci;
    auto end = ending(deck);
    
    for (auto it = deck; next != end; it = it->sljedeci, next = next->sljedeci)
        if (!cmpCards(it->karta, next->karta))
            return false;
            
    return true;
}

bool cmpCards(const Karta &card1, const Karta &card2)
{
    return card1.boja < card2.boja || (card1.boja == card2.boja &&
        std::find(Vrijednosti, Vrijednosti + 13, card1.vrijednost) < std::find(Vrijednosti, Vrijednosti + 13, card2.vrijednost));
}

unsigned int size(Cvor *deck)
{
    if (deck == nullptr)
        return 0;
    
    unsigned int res{};
    
    auto it = deck;
    do {
        res++;
        it = it->sljedeci;
    }
    while (it != deck && res <= 52);
    
    return res;
}

Cvor *ending(Cvor *deck)
{
    if (!deck)
        return deck;
    
    auto it = deck;
    do
        it = it->sljedeci;
    while (it->sljedeci != deck);
    
    return it;
}

void deleteFrom(Cvor *&deck, Cvor *&previous, Cvor *current)
{
    previous->sljedeci = current->sljedeci;
    
    if (deck == deck->sljedeci)
        deck = nullptr;
    else if (current == deck)
        deck = current->sljedeci;
        
    delete current;
}

void UnistiSpil(Cvor *spil)
{
    auto pret = ending(spil);
    
    while (spil)
    {
        //std::cout << int(spil->karta.boja) << ": " << spil->karta.vrijednost << std::endl;
        auto it = spil;
        deleteFrom(spil, pret, it);
    }
}
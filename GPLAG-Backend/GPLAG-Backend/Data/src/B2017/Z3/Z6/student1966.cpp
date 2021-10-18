/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <utility>
#include <algorithm>

#include <stack>
#include <map>

#include <stdexcept>
#include <memory>

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
    std::shared_ptr<Cvor>sljedeci;
};

typedef std::pair<std::string, std::string> StrPar;

void validateDeck(std::shared_ptr<Cvor>);
unsigned int size(std::shared_ptr<Cvor>);
std::shared_ptr<Cvor>ending(std::shared_ptr<Cvor>);

void deleteFrom(std::shared_ptr<Cvor>&, std::shared_ptr<Cvor>&, std::shared_ptr<Cvor>);

void IspisiSpil(std::shared_ptr<Cvor>);

std::shared_ptr<Cvor> KreirajSpil();
void IzbaciKarte(std::shared_ptr<Cvor>&, std::multimap<Boje, std::string>&);
std::stack<StrPar> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor>&, const short int&, const int&);
void VratiPosljednjihNKarata(std::shared_ptr<Cvor>&, std::stack<StrPar>&, int);

int main ()
{
    std::shared_ptr<Cvor> spil;
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
    
    spil->sljedeci = nullptr;
    spil = nullptr;
    
	return 0;
}

std::shared_ptr<Cvor>KreirajSpil()
{
    std::shared_ptr<Cvor> begin{nullptr}, previous;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
        {
            std::shared_ptr<Cvor> node;
            try {
                node = std::make_shared<Cvor>();
                node->karta.boja = Boje(i);
                node->karta.vrijednost = Vrijednosti[j];
                node->sljedeci = begin;
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

void IzbaciKarte(std::shared_ptr<Cvor>&spil, std::multimap<Boje, std::string> &zaIzbaciti)
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

std::stack<StrPar> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor>&spil, const short int &korak, const int &brZaIzbaciti)
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

void VratiPosljednjihNKarata(std::shared_ptr<Cvor>&spil, std::stack<StrPar> &zaUbaciti, int n)
{
    bool isValidCard(const Karta&);
    bool cmpCards(const Karta&, const Karta&);
    std::shared_ptr<Cvor>lower_bound(std::shared_ptr<Cvor>, const Karta&);
    
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
            spil = std::make_shared<Cvor>();
            spil->karta = ubacanje;
            spil->sljedeci = spil;
        }
        else
        {
            auto gdjeUbaciti = lower_bound(spil, ubacanje);
            if (gdjeUbaciti->karta.boja != ubacanje.boja ||
                gdjeUbaciti->karta.vrijednost != ubacanje.vrijednost)
                {
                    auto pret = ending(gdjeUbaciti);
                    
                    auto noviCvor = std::make_shared<Cvor>();
                    noviCvor->karta = ubacanje;
                    noviCvor->sljedeci = gdjeUbaciti;
                    pret->sljedeci = noviCvor;
                    
                    if (gdjeUbaciti == spil && cmpCards(ubacanje, spil->karta))
                        spil = noviCvor;
                }
        }
            
        zaUbaciti.pop();
    }
}

std::shared_ptr<Cvor>lower_bound(std::shared_ptr<Cvor>deck, const Karta &card)
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

void IspisiSpil(std::shared_ptr<Cvor>spil)
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

void validateDeck(std::shared_ptr<Cvor>deck)
{
    bool validCards(std::shared_ptr<Cvor>);
    bool isSorted(std::shared_ptr<Cvor>);
    
    if (size(deck) > 52 || !validCards(deck) || !isSorted(deck))
        throw std::logic_error("Neispravna lista!");
    return ;
}

bool validCards(std::shared_ptr<Cvor>deck)
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

bool isSorted(std::shared_ptr<Cvor>deck)
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

unsigned int size(std::shared_ptr<Cvor>deck)
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

std::shared_ptr<Cvor>ending(std::shared_ptr<Cvor>deck)
{
    if (!deck)
        return deck;
    
    auto it = deck;
    do
        it = it->sljedeci;
    while (it->sljedeci != deck);
    
    return it;
}

void deleteFrom(std::shared_ptr<Cvor>&deck, std::shared_ptr<Cvor>&previous, std::shared_ptr<Cvor>current)
{
    previous->sljedeci = current->sljedeci;
    
    if (deck == deck->sljedeci)
        deck = nullptr;
    else if (current == deck)
        deck = current->sljedeci;
}
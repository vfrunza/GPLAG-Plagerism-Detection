/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <memory>

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};
typedef Boje Suit;

const string CARDS[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const int NUMBER_OF_COLORS = 4, NUMBER_OF_VALUES = 13;
const int MAX_NUMBER_OF_CARDS = 52;

struct Karta
{
    Boje boja;
    string vrijednost;
};

struct Cvor
{
    Karta karta;
    shared_ptr<Cvor> sljedeci;
};

int getCardValue(string card)
{
    auto result = find(CARDS, CARDS + NUMBER_OF_VALUES, card);
    return result - CARDS;
}

string getSuit(Suit suit)
{
    if(suit == Suit::Pik)
    {
        return "Pik";
    }
    else if(suit == Suit::Tref)
    {
        return "Tref";
    }
    else if(suit == Suit::Herc)
    {
        return "Herc";
    }
    else
    {
        return "Karo";
    }
}

Suit getSuitValue(string suit)
{
    if(suit == "Pik")
    {
        return Suit::Pik;
    }
    else if(suit == "Tref")
    {
        return Suit::Tref;
    }
    else if(suit == "Herc")
    {
        return Suit::Herc;
    }
    else
    {
        return Suit::Karo;
    }
}

void printSuit(Suit suit)
{
    cout << getSuit(suit) << ": ";
}

void printDeck(shared_ptr<Cvor> deck)
{
    if(deck == nullptr)
    {
        return;
    }
    Suit suit;
    suit = deck->karta.boja;
    printSuit(suit);
    shared_ptr<Cvor> last = deck;
    for(shared_ptr<Cvor> it = deck; it->sljedeci != deck; it = it->sljedeci)
    {
        if(it->karta.boja != suit)
        {
            suit = it->karta.boja;
            cout << endl;
            printSuit(suit);
        }
        cout << it->karta.vrijednost << " ";
        last = it;
    }
    cout << last->sljedeci->karta.vrijednost << " ";
}

bool checkDeck(shared_ptr<Cvor> deck)
{
    shared_ptr<Cvor> it = deck;
    shared_ptr<Cvor> prethodni = it;
    int i = 0;
    for(;;)
    {
        if(i > MAX_NUMBER_OF_CARDS)
        {
            return false;
        }
        
        if(i > 1 && it == deck)
        {
            return true;
        }
        
        if(it->karta.vrijednost.length() < 1 || it->karta.vrijednost.length() > 2)
        {
            return false;
        }
        else if(it->karta.vrijednost.length() == 2)
        {
            if(it->karta.vrijednost != "10")
            {
                return false;
            }
        }
        else if(it->karta.vrijednost.length() == 1)
        {
            if(!((it->karta.vrijednost[0] >= '2' && it->karta.vrijednost[0] <= '9') || 
            it->karta.vrijednost == "J" ||  it->karta.vrijednost == "Q" || it->karta.vrijednost == "K" || it->karta.vrijednost == "A"))
            {
                return false;
            }
        }
        
        if(int(it->karta.boja) * 13 + getCardValue(it->karta.vrijednost) < int(prethodni->karta.boja) * 13 + getCardValue(prethodni->karta.vrijednost))
        {
            return false;
        }
        ++i;
        prethodni = it;
        it = it->sljedeci;
    }

    return true;
}

bool checkCard(pair<string, string> card)
{
    if(card.first != "Pik" && card.first != "Tref" && card.first != "Herc" && card.first != "Karo")
    {
        return false;
    }
    if(card.second.length() < 1 || card.second.length() > 2)
    {
        return false;
    }
    else if(card.second.length() == 2)
    {
        if(card.second != "10")
        {
            return false;
        }
    }
    else if(card.second.length() == 1)
    {
        if(!((card.second[0] >= '2' && card.second[0] <= '9') || card.second == "J" ||  card.second == "Q" || card.second == "K" || card.second == "A"))
        {
            return false;
        }
    }
    
    return true;
}

void insertCard(shared_ptr<Cvor>& deck, pair<string, string> card)
{
    pair<string, string> lastCard = make_pair("", "");
    shared_ptr<Cvor> it = deck, prethodni = deck;
    
    for(;prethodni->sljedeci != deck;)
    {
        prethodni = prethodni->sljedeci;
    }
    for(;;)
    {
        //cout << card.first << " " << card.second << "; ";
        if(int(getSuitValue(card.first)) * 13 + getCardValue(card.second) < int(it->karta.boja) * 13 + getCardValue(it->karta.vrijednost))
        {
            if(!(card.first == lastCard.first && card.second == lastCard.second))
            {
                shared_ptr<Cvor> temp(new Cvor);
                temp->karta.boja = getSuitValue(card.first);
                temp->karta.vrijednost = card.second;
                temp->sljedeci = it;
                prethodni->sljedeci = temp;
                if(it == deck)
                {
                    deck = temp;
                }
                //cout << "Inserted " << card.first << " " << card.second << "; ";
            }
            return;
        }
        lastCard = make_pair(getSuit(it->karta.boja), it->karta.vrijednost);
        if(it->sljedeci == deck)
        {
            prethodni = it;
            it = it->sljedeci;
            break;
        }
        prethodni = it;
        it = it->sljedeci;
    }

    if(!(card.first == lastCard.first && card.second == lastCard.second))
    {

        shared_ptr<Cvor> temp(new Cvor);
        temp->karta.boja = getSuitValue(card.first);
        temp->karta.vrijednost = card.second;
        temp->sljedeci = it;
        prethodni->sljedeci = temp;
    }
}

shared_ptr<Cvor> KreirajSpil()
{
    shared_ptr<Cvor> prvi(new Cvor);
    shared_ptr<Cvor> trenutni, prethodni;
    
    for(int i = 0; i < NUMBER_OF_COLORS; ++i)
    {
        for(int j = 0; j < NUMBER_OF_VALUES; ++j)
        {
            if(!(i == 0 && j == 0))
            {
                trenutni = make_shared<Cvor>();
                trenutni->karta.boja = Boje(i);
                trenutni->karta.vrijednost = CARDS[j];
                prethodni->sljedeci = trenutni;
                prethodni = trenutni;
            }
            else // i == 0 && j == 0
            {
                prvi->karta.boja = Boje(i);
                prvi->karta.vrijednost = CARDS[j];
                prethodni = prvi;
            }
        }
    }
    trenutni->sljedeci = prvi;
    
    return prvi;
}

void IzbaciKarte(shared_ptr<Cvor>& deck, multimap<Suit, string>& cardList)
{
    if(!checkDeck(deck))
    {
        throw logic_error("Izuzetak: Neispravna lista!");
    }
    
    for(auto it1 = cardList.begin(); it1 != cardList.end(); ++it1)
    {
        pair<Suit, string> card = *it1;
        shared_ptr<Cvor> it2 = deck;
        shared_ptr<Cvor> prethodni = deck;
        for(;prethodni->sljedeci != deck;)
        {
            prethodni = prethodni->sljedeci;
        }
        for(;;)
        {
            if(card.first == it2->karta.boja && card.second == it2->karta.vrijednost)
            {
                cardList.erase(it1);
                if(deck == deck->sljedeci)
                {
                    deck->sljedeci = deck;
                    deck = nullptr;
                }
                else if(it2 == deck)
                {
                    deck = deck->sljedeci;
                }
                prethodni->sljedeci = it2->sljedeci;
                it2.reset();
                it2 = prethodni->sljedeci;
            }
        }
    }
}


stack<pair<string, string>> IzbaciKarteRazbrajanjem(shared_ptr<Cvor>& deck, const short int &r, const int &b)
{
    if(r < 1 || r > 52 || b < 1)
    {
        throw logic_error("Izuzetak: Neispravni elementi za izbacivanje!");
    }
    if(!checkDeck(deck))
    {
        throw logic_error("Izuzetak: Neispravna lista!");
    }
    int left = b;
    stack<pair<string, string>> result;
    shared_ptr<Cvor> it = deck, prethodni = it;
    while(deck != nullptr && left > 0)
    {
        if(r == 1)
        {
            for(;prethodni->sljedeci != deck;)
            {
                prethodni = prethodni->sljedeci;
            }
        }
        for(int i = 1; i < r; ++i)
        {
            prethodni = it;
            it = it->sljedeci;
        }
        result.push(make_pair(getSuit(it->karta.boja), it->karta.vrijednost));
        
        if(deck == deck->sljedeci)
        {
            deck->sljedeci = nullptr;
            deck.reset();
            return result;
        }
        else if(it == deck)
        {
            deck = deck->sljedeci;
        }
        prethodni->sljedeci = it->sljedeci;
        it.reset();
        it = prethodni->sljedeci;
        
        --left;
    }
    return result;
}

void VratiPosljednjihNKarata(shared_ptr<Cvor>& deck, stack<pair<string, string>>& thrownCards, int n)
{
    if(n > 0 && n > thrownCards.size())
    {
        throw range_error("Izuzetak: Nedovoljno karata u redu!");
    }
    else if(n < 0)
    {
        throw domain_error("Izuzetak: Broj n je besmislen!");
    }
    if(!checkDeck(deck))
    {
        throw logic_error("Izuzetak: Neispravna lista!");
    }

    for(int i = 0; i < n; ++i)
    {
        /*printDeck(deck);
        cout << endl;
        int a; cin >> a;*/
        auto card = thrownCards.top();
        if(!checkCard(card))
        {
            throw logic_error("Izuzetak: Neispravne karte!");
        }
        thrownCards.pop();
        insertCard(deck, card);
    }
}

int main()
{
    int m;
    short int n;
    auto deck = KreirajSpil();
    cout << "Unesite korak razbrajanja: ";
    cin >> n;
    cout << "Unesite broj karata koje zelite izbaciti: ";
    cin >> m;
    try
    {
        auto thrownCards = IzbaciKarteRazbrajanjem(deck, n, m);
        cout << "U spilu trenutno ima "<< 52 - m << " karata, i to:" << endl;
        printDeck(deck);
        
        int k;
        cout << endl << "Unesite broj karata koje zelite vratiti u spil: ";
        cin >> k;
        VratiPosljednjihNKarata(deck, thrownCards, k);
        cout << "U spilu trenutno ima "<< 52 - m + k << " karata, i to: " << endl;
        printDeck(deck);
        
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(std::range_error e){
        std::cout<<e.what()<<std::endl;
    }
    shared_ptr<Cvor> it = deck;
    for(;it->sljedeci != deck;)
    {
        it = it->sljedeci;
    }
    it->sljedeci = nullptr;
    return 0;
}
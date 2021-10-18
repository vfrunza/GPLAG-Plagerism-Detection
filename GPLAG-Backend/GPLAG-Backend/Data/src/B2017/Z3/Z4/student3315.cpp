/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};
typedef Boje Suit;

const string CARDS[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const int NUMBER_OF_COLORS = 4, NUMBER_OF_VALUES = 13;
const int MAX_NUMBER_OF_CARDS = 52;

int getCardValue(string card)
{
    auto result = find(CARDS, CARDS + NUMBER_OF_VALUES, card);
    return result - begin(CARDS);
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

void printDeck(list<pair<Suit, string>> deck)
{
    Suit suit;
    if(!deck.empty())
    {
        suit = deck.front().first;
        printSuit(suit);
    }
    for(auto it = deck.begin(); it != deck.end(); ++it)
    {
        if(it->first != suit)
        {
            suit = it->first;
            cout << endl;
            printSuit(suit);
        }
        cout << it->second << " ";
    }
}

bool checkDeck(const list<pair<Suit, string>>& deck)
{
    if(deck.size() > 52)
    {
        return false;
    }
    for(auto it = deck.begin(); it != deck.end(); ++it)
    {
        if(it->second.length() < 1 || it->second.length() > 2)
        {
            return false;
        }
        else if(it->second.length() == 2)
        {
            if(it->second != "10")
            {
                return false;
            }
        }
        else if(it->second.length() == 1)
        {
            if(!((it->second[0] >= '2' && it->second[0] <= '9') || it->second == "J" ||  it->second == "Q" || it->second == "K" || it->second == "A"))
            {
                return false;
            }
        }
    }
    if(!is_sorted(deck.begin(), deck.end(), [](pair<Suit, string> card1, pair<Suit, string> card2) { return int(card1.first) * 13 + getCardValue(card1.second) < int(card2.first) * 13 + getCardValue(card2.second); }))
    {
        return false;
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

void insertCard(list<pair<Suit, string>>& deck, pair<string, string> card)
{
    pair<string, string> lastCard = make_pair("", "");
    for(auto it = deck.begin(); it != deck.end(); ++it)
    {
        if(int(getSuitValue(card.first)) * 13 + getCardValue(card.second) < int(it->first) * 13 + getCardValue(it->second))
        {
            if(!(card.first == lastCard.first && card.second == lastCard.second))
            {
                deck.insert(it, make_pair(getSuitValue(card.first), card.second));
            }
            return;
        }
        lastCard = make_pair(getSuit(it->first), it->second);
    }
    if(!(card.first == lastCard.first && card.second == lastCard.second))
    {
        deck.insert(deck.end(), make_pair(getSuitValue(card.first), card.second));
    }
}



list<pair<Suit, string>> KreirajSpil()
{
    list<pair<Suit, string>> deck;
    for(int i = 0; i < NUMBER_OF_COLORS; ++i)
    {
        for(int j = 0; j < NUMBER_OF_VALUES; ++j)
        {
            //deck.push_back(make_pair(Suit::Pik, "A"));
            deck.push_back(make_pair(Suit(i), CARDS[j]));
            //deck.insert(make_pair(i, getCard(j)));
        }
    }
    return deck;
}

void IzbaciKarte(list<pair<Suit, string>>& deck, multimap<Suit, string>& cardList)
{
    if(!checkDeck(deck))
    {
        throw logic_error("Izuzetak: Neispravna lista!");
    }
    
    for(auto it1 = cardList.begin(); it1 != cardList.end(); ++it1)
    {
        pair<Suit, string> card = *it1;
        auto found = find(deck.begin(), deck.end(), card);
        if(found != deck.end())
        {
            cardList.erase(it1);
            deck.erase(found);
        }
    }
}

queue<pair<string, string>> IzbaciKarteRazbrajanjem(list<pair<Suit, string>>& deck, const short int &r, const int &b)
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
    queue<pair<string, string>> result;
    auto it = deck.begin();
    while(!deck.empty() && left > 0)
    {
        for(int i = 1; i < r; ++i)
        {
            ++it;
            if(it == deck.end())
            {
                it = deck.begin();
            }
        }
        result.push(make_pair(getSuit(it->first), it->second));
        auto tempIt = it;
        ++it;
        deck.erase(tempIt);
        if(it == deck.end())
        {
            it = deck.begin();
        }
        --left;
    }
    return result;
}

void VratiPrvihNKarata(list<pair<Suit, string>>& deck, queue<pair<string, string>>& thrownCards, int n)
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
        auto card = thrownCards.front();
        if(!checkCard(card))
        {
            throw logic_error("Izuzetak: Neispravne karte!");
        }
        thrownCards.pop();
        insertCard(deck, card);
    }
}

/*
int main ()
{
    int m;
    short int n;
    list<pair<Suit, string>> deck = KreirajSpil();
    //printDeck(deck);
    multimap<Suit, string> cardList;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>n;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>m;
    
    try{
        auto q=IzbaciKarteRazbrajanjem(deck,n,m);
    
        int broj_karata=52-m;
    
        std::cout<<"U spilu trenutno ima "<<broj_karata<<" karata, i to: " << std::endl;
        
        printDeck(deck);
        
        int k = 4;
        std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        //std::cin>>k;
        cout << "Herda";
        VratiPrvihNKarata(deck, q, k);
        cout << "Herda";
        std::cout<<"U spilu trenutno ima "<<broj_karata+k<<" karata, i to: " << std::endl;
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
}
*/

int main()
{
    int m;
    short int n;
    auto deck = KreirajSpil();
    //multimap<Suit, string> cardList;
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
        VratiPrvihNKarata(deck, thrownCards, k);
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
    return 0;
}
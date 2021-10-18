// updating, solved locally
#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

// predefined data
enum class Boje { Pik, Tref, Herc, Karo };

constexpr int DECK_SIZE(52);
const std::vector<std::string> cardValues { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
const std::vector<std::string> cardNames { "Pik", "Tref", "Herc", "Karo" };

auto cardNumIndex = [](const std::string& _str) {
     return std::find(cardValues.cbegin(), cardValues.cend(), _str);
};

typedef std::pair<Boje, std::string>                   Card;
typedef std::pair<std::string, std::string>            RemovedCards;
typedef std::list<Card>                                Spil;
typedef std::multimap<Boje, std::string>               KarteMapa;
typedef std::queue<RemovedCards>                       ObrisaneRed;

// print cards function
void ispisiDeck(const Spil& _deck) {
     for (int i(0); i < cardNames.size(); ++i) {
          std::cout << std::endl << cardNames.at(i) << ": ";
          for (auto it(_deck.begin()); it != _deck.end(); ++it)
               if(it->first == static_cast<Boje>(i + int(Boje::Pik))) std::cout << it->second << " ";
     }
}

// sort function
bool sortFunction(const Card& a, const Card& b) {
     return (a.first < b.first) || ((a.first == b.first) && (cardNumIndex(a.second) < cardNumIndex(b.second)));
}

// check if given card is valid
bool validCard(const std::string& str, std::vector<std::string> _arr = cardValues) {
     return std::any_of(_arr.begin(), _arr.end(), [=](const std::string& _val) { return _val == str; });
}

// check validity of elements in deck
template <class container> 
bool invalidDeck(const container& _deck) {
     return std::any_of(_deck.begin(), _deck.end(), [](const Card& a) {
          return (a.first < Boje::Pik || a.first > Boje::Karo || !validCard(a.second));
     });
}

// validate entire card deck
void checkDeckValidity(const Spil& _deck) {
     if ( _deck.size() > DECK_SIZE || invalidDeck<Spil>(_deck) ||
          (std::adjacent_find(_deck.begin(), _deck.end(), [](const Card& a, const Card& b) { 
               return !sortFunction(a, b); 
          }) != _deck.end()))
          throw std::logic_error("Neispravna lista!");
}

// validate queue cards
void validateCardQueue(ObrisaneRed _deck) {
     for (; !_deck.empty();) {
          auto _card (_deck.front());
          if(!(validCard(_card.first, cardNames) && validCard(_card.second)))
               throw std::logic_error("Neispravne karte!");
          _deck.pop();
     }
}

/*   functions to implement   */
Spil KreirajSpil() {
     Spil _output;
     for (auto _znak(static_cast<int>(Boje::Pik)); _znak <= static_cast<int>(Boje::Karo); ++_znak)
          std::for_each(cardValues.begin(), cardValues.end(), [&_output, _znak](std::string _val) {
               _output.push_back(std::make_pair(static_cast<Boje>(_znak), _val));
          });
     return _output;
}

void IzbaciKarte(Spil& _deck, KarteMapa &_dmap) {
     checkDeckValidity(_deck);  // validity check

     for (bool _exist(false);;) {
          std::for_each(_deck.begin(), _deck.end(), [&_dmap, &_exist, &_deck](Card& karta) {
               _exist = false;
			auto _it(_dmap.find(karta.first));
			if (_it != _dmap.end() && _it->second == karta.second) {
				_it = _dmap.erase(_it);
				_exist = true;
			}
               if (_exist) _deck.remove(karta);
          });
          if (!_exist) break; 
     }
}

ObrisaneRed IzbaciKarteRazbrajanjem(Spil& _deck, const short int& r, const int& b) {
     // validity checks
     if (r < 1 || r > DECK_SIZE || b < 1)
          throw std::logic_error("Neispravni elementi za izbacivanje!");
     checkDeckValidity(_deck);
     
     ObrisaneRed output;
     int _erased (0);
     auto karta (_deck.begin());
     
     for (int _currentPos (1); !_deck.empty() && _erased < b; ++_currentPos) {
          if (_currentPos == r) {
               ++_erased;
               output.push(std::make_pair(cardNames.at(int(karta->first) + int(Boje::Pik)), karta->second));
               karta = std::prev(_deck.erase(karta));
               _currentPos = 0;
          }
          ++karta;
          if (karta == _deck.end()) karta = _deck.begin();
     }
     return output;
}

void VratiPrvihNKarata(Spil& _deck, ObrisaneRed& _removedCards, int n) {
     // validations
     if (n < 0) throw std::domain_error("Broj n je besmislen!");
     else if (n > _removedCards.size()) throw std::range_error("Nedovoljno karata u redu!");
     validateCardQueue(_removedCards);
     checkDeckValidity(_deck);
     
     for (; n > 0; --n) {
          auto _card (_removedCards.front());
          // map card accordingly from (string, string) to (Boje, string)
          int _pos (std::find(cardNames.begin(), cardNames.end(), _card.first) - cardNames.begin());
          
          auto _add (std::make_pair(static_cast<Boje>(_pos + int(Boje::Pik)), _card.second));
          if(_deck.size() < DECK_SIZE && std::find(_deck.begin(), _deck.end(), _add) == _deck.end())
               _deck.insert(_deck.begin(), _add);
          _removedCards.pop();
     }
     // sort list
     _deck.sort(sortFunction);
}

// main program logic
int main() {
     short int r;
     int b, n;
     Spil _deck (KreirajSpil());
     try {
		std::cout << "Unesite korak razbrajanja: "; std::cin >> r;
		std::cout << "Unesite broj karata koje zelite izbaciti: "; std::cin >> b;
		auto _removed (IzbaciKarteRazbrajanjem(_deck, r, b));
		
		std::cout << "U spilu trenutno ima " << _deck.size() << " karata, i to: "; ispisiDeck(_deck);
		
		std::cout << std::endl << "Unesite broj karata koje zelite vratiti u spil: "; std::cin >> n;
		VratiPrvihNKarata(_deck, _removed, n);
		std::cout << "U spilu trenutno ima " << _deck.size() << " karata, i to: "; ispisiDeck(_deck);
     }
     catch (const std::exception& e) {
		std::cout << "Izuzetak: " << e.what();
	}
     return 0;
}

int main() {
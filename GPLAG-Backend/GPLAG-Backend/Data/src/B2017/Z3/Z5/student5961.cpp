// updating, solved locally
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

// predefined data
enum class Boje { Pik, Tref, Herc, Karo };

constexpr int DECK_SIZE(52);
const std::vector<std::string> cardValues { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
const std::vector<std::string> cardNames { "Pik", "Tref", "Herc", "Karo" };
auto cardNumIndex = [](const std::string& _str) { return std::find(cardValues.cbegin(), cardValues.cend(), _str); };

/// defining classes
struct Karta {
	Boje boja;
	std::string vrijednost;
};
struct Cvor {
	Karta karta;
	Cvor* sljedeci = nullptr;
};

typedef std::pair<Boje, std::string>                   Card;
typedef std::pair<std::string, std::string>            RemovedCards;
typedef Cvor*                                          Spil;
typedef Cvor*                                          PointCvor;
typedef std::multimap<Boje, std::string>               KarteMapa;
typedef std::stack<RemovedCards>                       ObrisaneRed;

/*   functions for list  */
Karta toKarta(Card _card) { return { _card.first, _card.second }; }
int size_list(Spil);
bool _empty(Spil);
bool _equal(PointCvor, PointCvor);
void _increment(PointCvor&);
PointCvor _prevMember(Spil, PointCvor);
PointCvor _insert(Spil&, Card);
PointCvor _remove(Spil&, PointCvor&);

/**
		Validation functions
**/
bool sortFunction(PointCvor a, PointCvor b) {
	return a != nullptr && b != nullptr &&
		((a->karta.boja < b->karta.boja) || ((a->karta.boja == b->karta.boja) && (cardNumIndex(a->karta.vrijednost) < cardNumIndex(b->karta.vrijednost))));
}

// check if given card is valid
bool validCard(const std::string& str, std::vector<std::string> _arr = cardValues) {
     return std::any_of(_arr.begin(), _arr.end(), [=](const std::string& _val) { return _val == str; });
}

// check validity of elements in deck
bool invalidDeck(Spil _deck) {
     if(_deck == nullptr) return false;
     auto karta (_deck);
     do {
          if (karta->karta.boja < Boje::Pik || karta->karta.boja > Boje::Karo || !validCard(karta->karta.vrijednost)) 
			return true;
          _increment(karta);
     } while (karta != nullptr && karta != _deck);
     return false;
}

// check sort validity
bool sortiranaLista(Spil _deck) {
     if(_deck == nullptr) return true;
     auto karta (_deck);
     do {
          if(karta->sljedeci == _deck) break;
          auto card (karta->sljedeci);
          do {
               if (!sortFunction(karta, card)) return false;
               _increment(card);
          } while (card != nullptr && card != _deck);
          _increment(karta);
     } while (karta != nullptr && karta != _deck);
     return true;
}

// validate entire card deck
void checkDeckValidity(Spil _deck) {
     if (_deck != nullptr) 
          if (size_list(_deck) > DECK_SIZE || invalidDeck(_deck) || !sortiranaLista(_deck))
               throw std::logic_error("Neispravna lista!");
}

// validate queue cards
void validateCardQueue(ObrisaneRed _deck) {
     for (; !_deck.empty();) {
          auto _card (_deck.top());
          if(!(validCard(_card.first, cardNames) && validCard(_card.second)))
               throw std::logic_error("Neispravne karte!");
          _deck.pop();
     }
}

// print cards function
void ispisiDeck(const Spil& _deck) {
     for (int i(0); i < cardNames.size(); ++i) {
          std::cout << std::endl << cardNames.at(i) << ": ";
		auto karta(_deck);
          do {
               if(karta == nullptr) break;
               if(karta->karta.boja == static_cast<Boje>(i + int(Boje::Pik))) 
                    std::cout << karta->karta.vrijednost << " ";
               _increment(karta);
          } while (karta != nullptr && karta != _deck);
     }
}

/*   functions to implement   */
Spil KreirajSpil() {
     PointCvor _start(nullptr), _prev (nullptr);
     for (auto _znak(static_cast<int>(Boje::Pik)); _znak <= static_cast<int>(Boje::Karo); ++_znak) {
          for(int i(0); i < cardValues.size(); ++i) {
               PointCvor _new = new Cvor;
               _new->karta = {static_cast<Boje>(_znak), cardValues.at(i)};
               _new->sljedeci = nullptr;
               if (!_start) _start = _new;
               else _prev->sljedeci = _new;
               _prev = _new;
          }
     }
     _prev->sljedeci = _start;
     return _start;
}

void IzbaciKarte(Spil& _deck, KarteMapa &_dmap) {
     checkDeckValidity(_deck);  // validity check

     for (bool _exist(false);;) {
          auto karta (_deck);
          do {
               _exist = false;
			auto _it(_dmap.find(karta->karta.boja));
			if (_it != _dmap.end() && _it->second == karta->karta.vrijednost) {
				_it = _dmap.erase(_it);
				_exist = true;
			}
               if (_exist) _remove(_deck, karta);
               _increment(karta);
          }  while (karta != nullptr && karta != _deck);
          if (!_exist) break;
     }
}

ObrisaneRed IzbaciKarteRazbrajanjem(Spil& _deck, const short int& r, const int& b) {
     // validity checks
     if (r < 1 || r > DECK_SIZE || b < 1)
          throw std::logic_error("Neispravni elementi za izbacivanje!");
     checkDeckValidity(_deck);
     
     ObrisaneRed output;
     int _erased (0), _size (size_list(_deck));
     
	auto karta (_deck);
     for(int _currentPos (1); karta != nullptr && _size > 0 && _erased < b; ++_currentPos, _increment(karta)) {
          if (_currentPos == r) {
               ++_erased; --_size;
               output.push(std::make_pair(cardNames.at(int(karta->karta.boja) + int(Boje::Pik)), karta->karta.vrijednost));
               karta = _remove(_deck, karta);
               _currentPos = 0;
          }
     }

     return output;
}


void VratiPosljednjihNKarata(Spil& _deck, ObrisaneRed& _removedCards, int n) {
     // validations
     if (n < 0) 
          throw std::domain_error("Broj n je besmislen!");
     else if (n > _removedCards.size()) 
          throw std::range_error("Nedovoljno karata u steku!");
     validateCardQueue(_removedCards);
     checkDeckValidity(_deck);
     
     int _size(size_list(_deck));
     for (; n > 0; --n) {
          auto _card (_removedCards.top());
          // map card accordingly from (string, string) to (Boje, string)
          int _pos (std::find(cardNames.begin(), cardNames.end(), _card.first) - cardNames.begin());
          if(_size < DECK_SIZE)
               _insert(_deck, std::make_pair(static_cast<Boje>(_pos + int(Boje::Pik)), _card.second));
          _removedCards.pop();
          ++_size;
     }
}

void UnistiSpil(Spil _deck) {
	do {
		auto karta(_deck);
		_remove(_deck, karta);
	} while (_deck != nullptr);
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
		
		std::cout << "U spilu trenutno ima " << size_list(_deck) << " karata, i to: "; ispisiDeck(_deck);
		
		std::cout << std::endl << "Unesite broj karata koje zelite vratiti u spil: "; std::cin >> n;
		VratiPosljednjihNKarata(_deck, _removed, n);
		std::cout << "U spilu trenutno ima " << size_list(_deck) << " karata, i to: "; ispisiDeck(_deck);
     }
     catch (const std::exception& e) {
		std::cout << "Izuzetak: " << e.what();
	}
	UnistiSpil(_deck);
     return 0;
}

/*  implementation of list functions  */
int size_list(Spil _deck) {
     if (_deck == nullptr) return 0;
     int _size (0);
     auto _prev(_deck);
     do { ++_size; _increment(_prev); } while (_prev != nullptr && _prev != _deck);
     return _size;
}
PointCvor _prevMember(Spil _deck, PointCvor _card) {
     PointCvor _pos(nullptr);
     for (_pos = _deck; _pos != nullptr && _pos->sljedeci != _card && _pos->sljedeci != _deck; _increment(_pos));
     if (_pos == nullptr) return nullptr;
     return (_pos->sljedeci == _card ? _pos : nullptr);
}
bool _empty(Spil _deck) { return _deck == nullptr; }
void _increment(PointCvor& _point) { _point = _point!=nullptr ? _point->sljedeci : nullptr; }
PointCvor _insert(Spil &_deck, Card _card) {
     PointCvor _new (new Cvor);
     _new->karta = toKarta(_card);
     if (_empty(_deck) || _deck->sljedeci == nullptr) {
          _new->sljedeci = _new;
          _deck = _new;
          return _new;
     }
     auto _next (_deck);
     do {
          if(sortFunction(_new, _next) && !_equal(_new, _next)) {
               _new->sljedeci = _next->sljedeci;
               _next->sljedeci = _new;
               std::swap(_new->karta, _next->karta);
               return _new;
          }
          _increment(_next);
     } while (_next != nullptr && _next != _deck);
	/// ubaci na kraj liste
	auto _mem(_prevMember(_deck, _deck));
	if(_equal(_new, _mem)) return nullptr;
	_mem->sljedeci = _new;
	_new->sljedeci = _deck;
	return _new;
}
PointCvor _remove(Spil &_deck, PointCvor &_card) {
     auto prev (_prevMember(_deck, _card));
     if (_empty(_deck) || _card == nullptr || prev == nullptr)
          return nullptr;
     if (_deck == _card) _deck = _deck->sljedeci;
     prev->sljedeci = _card->sljedeci;
     if (size_list(_deck) == 1 && _deck == _card) _deck = nullptr;
     delete _card;
     _card = nullptr;
     return prev;
}
bool _equal(PointCvor a, PointCvor b) {
     return (a != nullptr && b != nullptr && 
          a->karta.boja == b->karta.boja && a->karta.vrijednost == b->karta.vrijednost);
}
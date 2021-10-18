/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <queue>

enum class Boje {Pik, Tref, Herc, Karo};
 std::vector<std::string> pomocni {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

std::list<std::pair<Boje, std::string>> KreirajSpil () {
    std::list<std::pair<Boje, std::string>>spil;
    for (int i = 0; i < 13; i++) {
        spil.push_back (std::make_pair (Boje::Pik, pomocni[i]));
    }
    for (int i = 0; i < 13; i++) {
        spil.push_back (std::make_pair (Boje::Tref, pomocni[i]));
    } 
    for (int i = 0; i < 13; i++) {
        spil.push_back (std::make_pair (Boje::Herc, pomocni[i]));
    }
    for (int i = 0; i < 13; i++) {
        spil.push_back (std::make_pair (Boje::Karo, pomocni[i]));
    }
    return spil;
}

bool SpilSortiran (const std::list<std::pair<Boje, std::string>> &spil) {
    for (auto it = spil.begin(); it!=spil.end(); it++) {
        bool nalazise (false);
        for (auto it2 = pomocni.begin(); it2 != pomocni.end(); it2++) {
            if (it->second == *it2) nalazise = true;
        }
        if (!nalazise) return false;
    }
    for (auto it = spil.begin(); it != spil.end(); it++) {
        Boje b = it->first;
        while (it != spil.end() && b == it->first) {
            auto pozicijait = std::find(pomocni.begin(), pomocni.end(), it->second);
            auto it2 = it;
            it2++;
            std::vector<std::string>::iterator pozicijait2;
            if (it2 != spil.end() && it2->first == b) {
                pozicijait2 = std::find(pomocni.begin(), pomocni.end(), it2->second);
                if (pozicijait2<pozicijait) 
                    return false;
            }
            it++;
        }
        it--;
    }
    for (auto it = spil.begin(); it != spil.end(); it++) {
        for (auto it2 = it; it2 != spil.end(); it2++) {
            if (it2 == it) it2++;
            if(it2 == spil.end()) break;
            if (it->first > it2->first) return false;
        }
    }
    return true;
}

void IzbaciKarte (std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &elementi) {
     int vel(0);
     for (auto it = spil.begin(); it != spil.end(); it++) vel++; // brojanje elemenata liste
     if (vel>52 || !SpilSortiran(spil)) throw std::logic_error ("Neispravna lista!");
     for (auto it = elementi.begin(); it!=elementi.end();) {
         bool nalazise(false);
         for (auto it2 = spil.begin(); it2!=spil.end();) {
             if ((it->first == it2->first) && (it->second == it2->second)) {
                 nalazise = true;
                 it2 = spil.erase (it2); // brisanje elementa iz liste
                 it = elementi.erase (it); // brisanje iz multimape
                 if(elementi.size() == 0 || spil.size() == 0) return;
                 break;
             }
             else it2++;
         }
         if(!nalazise) it++;
     }
     
 }
 
std::string BojaUString(Boje boja) {
    if(boja == Boje::Pik) return "Pik";
    else if(boja == Boje::Tref) return "Tref";
    else if(boja == Boje::Herc) return "Herc";
    return "Karo";
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje, std::string>> &spil, const short int &r, const int &b) {
    if (r<1 || r>52 || b<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<std::string, std::string>> red;
    auto it = spil.begin();
    int novi;
    if (b > spil.size()) novi = spil.size();
    else novi = b;
    for (int i = 0; i < novi; i++) {
        for(int j = 0; j < r - 1; j++) {
            it++;
            if(it == spil.end()) it = spil.begin();
        }
        std::string boja = BojaUString(it->first);
        red.push (std::make_pair(boja, it->second));
        it = spil.erase(it);
    }
    return red;
}
bool SmisleneKarte (std::queue<std::pair<std::string, std::string>> red) {
    while (!red.empty()) {
        bool nalazise (false);
        for (auto it = pomocni.begin(); it != pomocni.end(); it++) {
            if ((red.front()).second == *it) nalazise = true;
        }
        if (!nalazise) return false;
        std::string boja = (red.front()).first;
        if (boja != "Pik" && boja != "Tref" && boja != "Karo" && boja != "Herc") return false;
        red.pop();
    }
    return true;
}

Boje StringUBoju (std::string s) {
    if (s == "Pik") return Boje::Pik;
    if (s == "Tref") return Boje::Tref;
    if (s == "Herc") return Boje::Herc;
    if (s == "Karo") return Boje::Karo;
}

void VratiPrvihNKarata (std::list<std::pair<Boje, std::string>>&spil, std::queue<std::pair<std::string, std::string>>&red, int n) {
    if (n < 0) throw std::logic_error ("Broj n je besmislen!");
     if (n > red.size()) throw std::range_error ("Nedovoljno karata u redu!");
     if (!SmisleneKarte(red)) throw std::logic_error ("Neispravne karte!");
     if (spil.size() > 52 || !SpilSortiran(spil)) throw std::logic_error ("Neispravna lista!");
     for (int i = 0; i < n; i++) {
        Boje boja = StringUBoju ((red.front()).first);
        for (auto it = spil.begin(); it != spil.end(); it++) {
            if (it->first == boja) {
               auto pozicijaizspila = std::find (pomocni.begin(), pomocni.end(), it->second);
                auto pozicijaizreda = std::find (pomocni.begin(), pomocni.end(), (red.front()).second);
                while (it != spil.end() && pozicijaizspila != pomocni.end() && pozicijaizspila < pozicijaizreda) {
                    if (it->second == *pozicijaizspila) it++;
                    pozicijaizspila++;
                }
            spil.insert (it, std::make_pair(boja, (red.front()).second));
            red.pop();
            break;
            }
        }
    }
}

int main ()
{
    std::cout << "Unesite korak razbrajanja: ";
    short int r;
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin >> b;
    auto spil = KreirajSpil();
    std::queue<std::pair<std::string, std::string>> red;
    try {
      red = IzbaciKarteRazbrajanjem (spil, r, b);
    } catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
        return 0;
    }
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: ";
    std::cout << std::endl << "Pik: ";
    for (auto it = spil.begin(); it != spil.end(); it++) {
        if (BojaUString(it->first) == "Pik") std::cout << it->second << " ";
    }
    std::cout << std::endl << "Tref: ";
    for (auto it = spil.begin(); it != spil.end(); it++) {
        if (BojaUString(it->first) == "Tref") std::cout << it->second << " ";
    }
    std::cout << std::endl << "Herc: ";
    for (auto it = spil.begin(); it != spil.end(); it++) {
        if (BojaUString(it->first) == "Herc") std::cout << it->second << " ";
    }
    std::cout << std::endl << "Karo: ";
    for (auto it = spil.begin(); it != spil.end(); it++) {
        if (BojaUString(it->first) == "Karo") std::cout << it->second << " ";
    }
    std::cout << std::endl << "Unesite broj karata koje zelite vratiti u spil: ";
    int n;
    std::cin >> n;
   try {
        VratiPrvihNKarata (spil, red, n);
   } catch (std::logic_error e) {
       std::cout << "Izuzetak: " << e.what();
       return 0;
   } catch (std::range_error r) {
       std::cout << "Izuzetak: " << r.what();
       return 0;
   }
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: ";
    std::cout << std::endl << "Pik: ";
    for (auto it = spil.begin(); it != spil.end(); it++) {
        if (BojaUString(it->first) == "Pik") std::cout << it->second << " ";
    }
    std::cout << std::endl << "Tref: ";
    for (auto it = spil.begin(); it != spil.end(); it++) {
        if (BojaUString(it->first) == "Tref") std::cout << it->second << " ";
    }
    std::cout << std::endl << "Herc: ";
    for (auto it = spil.begin(); it != spil.end(); it++) {
        if (BojaUString(it->first) == "Herc") std::cout << it->second << " ";
    }
    std::cout << std::endl << "Karo: ";
    for (auto it = spil.begin(); it != spil.end(); it++) {
        if (BojaUString(it->first) == "Karo") std::cout << it->second << " ";
    }
	return 0;
}

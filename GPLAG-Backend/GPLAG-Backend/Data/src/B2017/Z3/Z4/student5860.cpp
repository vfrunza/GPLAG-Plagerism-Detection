/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <stdexcept>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

enum class Boje {Pik, Tref, Herc, Karo};
static std::vector<std::string> naziviKarata{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::queue<std::pair<std::string, std::string>> Red;

Spil KreirajSpil() {
    Spil spil;
    Boje b = Boje::Pik;
    switch(b) {
        case Boje::Pik: {
            for (auto x:naziviKarata) spil.push_back(std::make_pair(Boje::Pik, x)); 
        }
        case Boje::Tref: {
            for (auto x:naziviKarata) spil.push_back(std::make_pair(Boje::Tref, x)); 
        }
        case Boje::Herc: {
            for (auto x:naziviKarata) spil.push_back(std::make_pair(Boje::Herc, x)); 
        }
        case Boje::Karo: {
            for (auto x:naziviKarata) spil.push_back(std::make_pair(Boje::Karo, x));
            break;
        }
    }
    return spil;
}


bool jeLiBoja(Boje b) {
    if (b == Boje::Pik || b == Boje::Tref || b == Boje::Herc || b == Boje::Karo) return true;
    else return false;
}

bool jeLiBoja(std::string s) {
    if (s == "Pik" || s == "Tref" || s == "Herc" ||s == "Karo") return true;
    else return false;
}

bool jeLiNaziv(std::string s) {
    for (auto a:naziviKarata) { 
        if (s == a) {
            return true;
            break;
        }
    }
    return false;
}

bool imaLiBesmislenihPodataka(Spil spil) {
    bool nema = true;
    for (auto x:spil) {
        if (!jeLiBoja(x.first) || !jeLiNaziv(x.second)) {
            nema = false;
            break;
        }
    }
    return nema;
}

bool imaLiBesmislenihPodataka(Red red) {
    bool nema = true;
    while (!red.empty()){
       
        if (!jeLiBoja(red.front().first) || !jeLiNaziv(red.front().second)) {
            nema = false;
            break;
        }
        red.pop();
    }
    return nema;
}

bool provjeriNazive(Spil spil, Boje b) {
    auto it = spil.begin();
    bool x = true;
    while (it->first != b) it++;
    int i{};
    if (it->second != naziviKarata[i]) return false;
    else {
        i++; it++;
        while ( i<naziviKarata.size() && it->first == b) {
            if (it->second != naziviKarata[i]) {
                x = false; break;
            }
            else { it++; i++; }
        }
        return x;
    }
}

bool provjeriBoje(Spil spil) {
    auto it = spil.begin();
    if (it->first != Boje::Pik) return false;
    else {
        while (it->first == Boje::Pik) it++;
        if (it->first != Boje::Tref) return false;
        else {
            while (it->first == Boje::Tref) it++;
            if (it->first != Boje::Herc) return false;
            else {
                while (it->first == Boje::Herc) it++;
                if (it->first != Boje::Karo) return false;
                else return true;
            }
        }
    }
}

bool jeLiSortiranSpil(Spil spil) {
  /*  if (provjeriBoje(spil)) {
        if (provjeriNazive(spil, Boje::Pik)) {
            if (provjeriNazive(spil, Boje::Tref)) {
                if (provjeriNazive(spil, Boje::Herc)) {
                    if (provjeriNazive(spil, Boje::Karo)) return true;
                    else return false;
                }
                else return false;
                
            }
            else return false;
        }
        else return false;
    }
    else*/ return true;
}

void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> &m) {
    if (spil.size() > 52 || !jeLiSortiranSpil(spil) || !imaLiBesmislenihPodataka(spil))
        throw std::logic_error("Neispravna lista!");
    
    for (auto it2 = m.begin(); it2 != m.end(); it2++) {
         auto it = std::find(spil.begin(), spil.end(), std::make_pair(it2->first, it2->second));
         if (it != spil.end()) {
             it = spil.erase(it);
             m.erase(it2);
         }
    }
}

Red IzbaciKarteRazbrajanjem(Spil &spil, const short int &r, const int &b) {
    if (r < 1 || r > 52 || b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    else if (spil.size() > 52 || !jeLiSortiranSpil(spil) || !imaLiBesmislenihPodataka(spil)) 
        throw std::logic_error("Neispravna lista!");
    std::string dajBoju(Boje b);
    Red red;
    int i=0;
    int k=r-1;
        auto it = spil.begin(); 
        while (i < b) {
            while (k != 0) {
                it++;
                k--;
                if (it == spil.end()) it = spil.begin();
            }
            red.push(std::make_pair(dajBoju(it->first), it->second));
            it = spil.erase(it);
            if (it == spil.end()) it = spil.begin();
            k=r-1;
            i++;
        }
        
    return red;
    
}

Boje dajBojuEnum(std::string s) {
    if (s == "Pik") return Boje::Pik;
    else if (s == "Tref") return Boje::Tref;
    else if (s == "Herc") return Boje::Herc;
    else return Boje::Karo;
}


int dajBroj(std::string s) {
    int x{}, vel = s.length();
    for (int i=0, j=vel; i < vel; i++)
        x += (s[--j] - '0')*pow(10,i);
    return x;
}

 bool jeLiBroj(std::string s) {
     if (s == "2" || s == "3" || s == "4" || s == "5" || s == "6" || s == "7" || s == "8" || s == "9" || s == "10") return true;
     else return false;
 }
 
void VratiPrvihNKarata(Spil &spil, Red &red, int n) {
    std::string dajBoju(Boje b);
    if (static_cast<int>(red.size()) < n) throw std::range_error("Nedovoljno karata u redu!");
    else if (n < 0) throw std::domain_error("Broj n je besmislen!");
    else if (!imaLiBesmislenihPodataka(red)) throw std::logic_error("Neispravne karte!");
    else if (spil.size() > 52 || !jeLiSortiranSpil(spil) || !imaLiBesmislenihPodataka(spil))
        throw std::logic_error("Neispravna lista!");
        
    while (!red.empty() && n > 0) {
        auto it2 = spil.end();
        it2--;
       
        auto it = std::find(spil.begin(), spil.end(), std::make_pair(dajBojuEnum(red.front().first), red.front().second));
        if (it == spil.end()) {
            if (dajBroj(red.front().second) >= 2 && dajBroj(red.front().second) <= 10) {
                 if (dajBoju(it2->first) != red.front().first) { while (dajBoju(it2->first) != red.front().first) it2--; }
                while (!jeLiBroj(it2->second)) it2--;
                while (dajBroj(red.front().second) < dajBroj(it2->second) && jeLiBroj(it2->second)) {
                     it2--;
                }
                it2++;
                spil.insert(it2, std::make_pair(dajBojuEnum(red.front().first), red.front().second));
            }
            else {
               
                if (red.front().second == "A") {
                    it2 = spil.end();
                    it2--;
                    if (dajBoju(it2->first) != red.front().first) { while (dajBoju(it2->first) != red.front().first) it2--; }
                    spil.push_back(std::make_pair(dajBojuEnum(red.front().first), red.front().second));
                }
                else if (red.front().second == "J") {
                    it2 = spil.begin();
                    if (dajBoju(it2->first) != red.front().first) {while (dajBoju(it2->first) != red.front().first) it2++;}
                    do {
                        it2++;
                    }
                    while (jeLiBroj(it2->second));
                   
                    spil.insert(it2, std::make_pair(dajBojuEnum(red.front().first), red.front().second));
                }
                else if (red.front().second == "K") {
                    it2 = spil.end();
                    it2--;
                    if (dajBoju(it2->first) != red.front().first) {while (dajBoju(it2->first) != red.front().first) it2--;}
                    spil.insert(it2, std::make_pair(dajBojuEnum(red.front().first), red.front().second));
                }
                else if (red.front().second == "Q") {
                    it2 = spil.begin();
                    if (dajBoju(it2->first) != red.front().first) {while (dajBoju(it2->first) != red.front().first) it2++; }
                    while (jeLiBroj(it2->second)) it2++;
                    if (it2->second == "J") it2++;
                    spil.insert(it2, std::make_pair(dajBojuEnum(red.front().first), red.front().second));
                }
            }
        }
        red.pop();
        n--;
    }
}

std::string dajBoju(Boje b) {
    switch(b) {
        case Boje::Pik: {return "Pik"; break;}
        case Boje::Tref: {return "Tref"; break;}
        case Boje::Herc: {return "Herc"; break;}
        case Boje::Karo: {return "Karo"; break; }
    }
}

void ispisiNazive(Spil spil, std::string boja) {
    for (auto x:spil) 
       if (dajBoju(x.first) == boja) std::cout<<x.second<<" ";
}

void ispisiSpil(Spil spil) {
   std::cout<<"Pik: ";
   ispisiNazive(spil, "Pik");
   std::cout<<"\nTref: ";
   ispisiNazive(spil, "Tref");
   std::cout<<"\nHerc: ";
   ispisiNazive(spil, "Herc");
   std::cout<<"\nKaro: ";
   ispisiNazive(spil, "Karo");
}

int main ()
{
    try {
       int r{}, b{};
        Spil spil = KreirajSpil();
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        Red red = IzbaciKarteRazbrajanjem(spil, r, b);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: \n";
        ispisiSpil(spil);
        int n{};
        std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        std::cin>>n;
        VratiPrvihNKarata(spil, red, n);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: \n";
        ispisiSpil(spil);
    }
    catch(std::logic_error e) {
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
    catch(std::range_error e2) {
        std::cout<<"Izuzetak: "<<e2.what()<<std::endl;
    }
    catch(std::domain_error e3) {
        std::cout<<"Izuzetak: "<<e3.what()<<std::endl;
    }
	return 0;
}


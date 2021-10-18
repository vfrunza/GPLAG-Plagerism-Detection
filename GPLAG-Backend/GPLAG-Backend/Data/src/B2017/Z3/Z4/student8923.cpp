/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

enum class Boje{Pik, Tref, Herc, Karo};

typedef std::list<std::pair<Boje,std::string>> Spil;
typedef std::queue<std::pair<std::string,std::string>> Red;

bool DaLiJeRedIspravan(Red red)
{
    std::vector<std::string> boje{"Pik", "Tref", "Herc", "Karo"};
    std::vector<std::string> imena{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    bool ispravno(false);
    while(!red.empty()) {
        
        ispravno = false;
        for(int j = 0; j < boje.size(); j++) {
            if(red.front().first == boje[j]) {
                ispravno = true; break;
            }
        }
        if(!ispravno) return false;
        
        ispravno = false;
        for(int i = 0; i < imena.size(); i++) {
            if(red.front().second == imena[i]) {
                ispravno = true; break;
            }
        }
        if(!ispravno) return false;

        red.pop();
    }
    return ispravno;
}

bool DaLiJeListaIspravna(Spil &spil)
{
    if(spil.size() > 52) return false;
    if(spil.size() == 0) return true;
    std::vector<std::string> S{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    bool ispravno(false);
    auto it(spil.begin());
    for(int i = 0; i < spil.size(); i++) {
        if(std::count(spil.begin(), spil.end(), *it) > 1) return false;
        ispravno = false;
        for(int j = 0; j < S.size(); j++) {
            if(it->second == S[j]) {
                ispravno = true; break;
            }
        }
        if(!ispravno) return false;
        
        ispravno = false;
        for(int k = 0; k < 4; k++) {
            if(it->first == Boje(k)) {
                ispravno = true; break;
            }
        }
        if(!ispravno) return false;
        it++;
    }
    int index1(0),index2(0),index3(0),index4(0);
    if(spil.size() > 1) {
        it = spil.begin();
        auto it1(it);
        it1++;
        for(int i = 0; i < spil.size()-1; i++) {
            while(it->first != Boje(index1)) index1++;
            while(it->second != S[index2]) index2++;
            while(it1->first != Boje(index3)) index3++;
            while(it1->second != S[index4]) index4++;
            if(index1 == index3) {
                if(index2 > index4) return false;
            }
            it++; it1++;
            index1 = 0; index2 = 0; index3 = 0; index4 = 0;
        }
    }
    return ispravno;
}

void PrintajSpil(const Spil &spil) 
{
    int brojac(0);
    auto it(spil.begin());
    for(int i = 0; i < spil.size(); i++) {
        if(it->first == Boje(0)) { 
            std::cout << "Pik: ";
            while(it->first == Boje(0)) {
                std::cout << it->second << " ";
                brojac++;
                it++;
            }
            std::cout << std::endl;
        }
        else if(it->first == Boje(1)) { 
            std::cout << "Tref: ";
            while(it->first == Boje(1)) {
                std::cout << it->second << " ";
                brojac++;
                it++;
            }
            std::cout << std::endl;
        }
        else if(it->first == Boje(2)) { 
            std::cout << "Herc: ";
            while(it->first == Boje(2)) {
                std::cout << it->second << " ";
                brojac++;
                it++;
            }
            std::cout << std::endl;
        }
        else if(it->first == Boje(3)) { 
            std::cout << "Karo: ";
            while(it->first == Boje(3)) {
                std::cout << it->second << " ";
                brojac++;
                it++;
            }
            std::cout << std::endl;
        }
        i += brojac - 1;
        brojac = 0;
    }
}

Spil KreirajSpil()
{
    Spil spil2;
    int brojac(0);
    int index(0);
    int karte[14] = {'2','3','4','5','6','7','8','9','0','J','Q','K','A'};
    
    //pravim listu petlja
    for(int i = 0; i < 52; i++) {
        if(index == 13) index -= 13;
        if(i != 0 && i % 13 == 0) brojac++;
        std::pair<Boje, std::string> par;
        std::string tmp;
        if(index != 8) {
          tmp.push_back(karte[index]);
        } else {
            tmp.push_back('1');
            tmp.push_back('0');
            }
        par = std::make_pair(Boje(brojac), tmp);
        spil2.push_back(par);
        
        index++;
    }
    return spil2;
}

void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> &mapa)
{
    if(!DaLiJeListaIspravna(spil)) throw std::logic_error("Neispravna lista!");
    auto it(spil.begin());
    bool ima(false);
    for(auto it = mapa.begin(); it != mapa.end();) {
        for(auto it1 = spil.begin(); it1 != spil.end(); it1++) {
            if(it->first == it1->first && it->second == it1->second) {
               it1 = spil.erase(it1);
                ima = true;
                auto karta_iz_mape(*it);
                it++;
                for(auto it2 = mapa.begin(); it2 != mapa.end(); it2++) {
                    if(*it2 == karta_iz_mape) {
                       it2 = mapa.erase(it2);
                       if(mapa.size() == 0) break; 
                    }
                }
            }
        }
        if(!ima) it++;
        ima = false;
    }
    
}

Red IzbaciKarteRazbrajanjem(Spil &spil, short int n, int x)
{
    if(n < 1 || n > 52 || x < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(!DaLiJeListaIspravna(spil)) throw std::logic_error("Neispravna lista!");
    
    Red red;
    
    auto it(spil.begin());
    for(int i = 0; i < x; i++) {
        if(spil.size() == 0) break;
        if(it==spil.end())  it = spil.begin();
        for(int j = 0; j < n - 1; j++) {
            it++;
            if(it==spil.end())  it = spil.begin();
            
        }
        std::pair<std::string, std::string> par;
        if(it->first == Boje(0)) {
            par.first = "Pik"; par.second = it->second;
        } else if(it->first == Boje(1)) {
            par.first = "Tref"; par.second = it->second;
        } else if(it->first == Boje(2)) {
            par.first = "Herc"; par.second = it->second;
        } else {
            par.first = "Karo"; par.second = it->second;
        }
        red.push(par);
        it = spil.erase(it);
    }
    return red;
}

void VratiPrvihNKarata(Spil &spil, Red &red, int n)
{
    if(n < 0) throw std::domain_error("Broj n je besmislen!");
    if(n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(!DaLiJeRedIspravan(red)) throw std::logic_error("Neispravne karte!");
    if(!DaLiJeListaIspravna(spil)) throw std::logic_error("Neispravna lista!");
   
    std::vector<std::string> boje{"Pik", "Tref", "Herc", "Karo"};
    std::vector<std::string> imena{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int index(0);
    for(int i = 0; i < n; i++) {
            auto it = std::find_if(spil.begin(), spil.end(), [&spil,&red] (std::pair<Boje,std::string> par) -> bool {
                std::vector<std::string> boje{"Pik", "Tref", "Herc", "Karo"};
                std::vector<std::string> imena{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
                int index_red(0),index_boje(0),index_lista(0);
                
                while(red.front().second != imena[index_red]) index_red++;
                while(red.front().first != boje[index_boje]) index_boje++;
                while(par.second != imena[index_lista]) index_lista++;
                
                if((par.first >= Boje(index_boje) && index_lista > index_red) || (par.first >= Boje(index_boje + 1) && index_lista > index_red) 
                || (par.first >= Boje(index_boje + 1) && index_lista < index_red)) return true;
    
                return false;
                
            });
            
             while(red.front().first != boje[index]) index++;
             std::pair<Boje,std::string> par{Boje(index), red.front().second};
             index = 0;
             red.pop();
             if(std::count(spil.begin(), spil.end(), par)) continue;
             spil.insert(it, par);
    }
    
}

int main ()
{
   
    Spil spil1(KreirajSpil());
    int n,x;
    try {
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> n;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> x;
    Red red(IzbaciKarteRazbrajanjem(spil1,n,x));
    std::cout << "U spilu trenutno ima " << spil1.size() << " karata, i to: \n";
    PrintajSpil(spil1);
    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    std::cin >> n;
    VratiPrvihNKarata(spil1, red, n);
    std::cout << "U spilu trenutno ima " << spil1.size() << " karata, i to: \n";
    PrintajSpil(spil1);
    } catch (std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    } catch (std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    } catch (std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}

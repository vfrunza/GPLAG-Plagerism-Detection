/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include<utility>
#include<map> 
#include<iterator>
#include<stdexcept>
#include<queue>
#include <vector>
#include <string>
#include <algorithm>

enum class Boje{Pik,Tref,Herc,Karo};
std::vector<std::string> nazivi{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

std::string PretvoriBojuUString(Boje b) {
    if(b == Boje::Pik) return "Pik";
    else if(b == Boje::Tref) return "Tref";
    else if(b == Boje::Herc) return "Herc";
    else return "Karo";
}

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    std::list<std::pair<Boje,std::string>> rezultat;
    for(int i(0); i < 4 * nazivi.size(); i++) {
        if(i >= 0 && i < 13) {
            rezultat.push_back(std::make_pair(Boje::Pik, nazivi.at(i)));
        }
        else if(i >= 13 && i < 26) {
            rezultat.push_back(std::make_pair(Boje::Tref, nazivi.at(i - 13)));
        }
        else if(i >= 26 && i < 39) {
            rezultat.push_back(std::make_pair(Boje::Herc, nazivi.at(i - 26)));
        }
        else rezultat.push_back(std::make_pair(Boje::Karo, nazivi.at(i - 39)));
    }
    return rezultat;
}

void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &izbaci)
{
    if(spil.size()>52) 
        throw std::logic_error("Neispravna lista!");
    for(auto it(spil.begin()); it != spil.end(); it++) {
        auto pomocni = std::find(nazivi.begin(), nazivi.end(), it->second);
        if(pomocni == nazivi.end()) 
            throw std::logic_error("Neispravna lista!");
    }
    std::list<std::pair<Boje, std::string>> sortirani(spil);
    sortirani.sort([] (const std::pair<Boje, std::string> &a, const std::pair<Boje, std::string> &b) { if(a.first < b.first) return true;
                                                                                                                                      else if(a.first == b.first) {
                                                                                                                                            auto itA = std::find(nazivi.begin(), nazivi.end(), a.second);
                                                                                                                                            auto itB = std::find(nazivi.begin(), nazivi.end(), b.second);
                                                                                                                                            if(itA < itB) return true;
                                                                                                                                            return false;
                                                                                                                                      }
                                                                                                                                      return false; });
    if(!std::equal(spil.begin(), spil.end(), sortirani.begin(), [] (const std::pair<Boje, std::string> &a, const std::pair<Boje, std::string> &b) { if(a.first == b.first && a.second == b.second) return true; return false; })) throw std::logic_error("Neispravna lista!");
    for(auto it(izbaci.begin()); it != izbaci.end();) {
        auto itLista = std::find_if(spil.begin(), spil.end(), [it] (const std::pair<Boje, std::string> &a) { if(a.first == it->first && a.second == it->second) return true; return false; });
        if(itLista != spil.end()) {
            spil.erase(itLista);
            it = izbaci.erase(it);
        }
        else it++;
    } 
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil,const short int &r,const int &b)
{
    if(r<1 || r>52 || b<1) 
       throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(spil.size()>52) 
        throw std::logic_error("Neispravna lista!");
    for(auto it(spil.begin()); it != spil.end(); it++) {
        auto pomocni = std::find(nazivi.begin(), nazivi.end(), it->second);
        if(pomocni == nazivi.end()) 
            throw std::logic_error("Neispravna lista!");
    }
    std::list<std::pair<Boje, std::string>> sortirani(spil);
    sortirani.sort([] (const std::pair<Boje, std::string> &a, const std::pair<Boje, std::string> &b) { if(a.first < b.first) return true;
                                                                                                                                      else if(a.first == b.first) {
                                                                                                                                            auto itA = std::find(nazivi.begin(), nazivi.end(), a.second);
                                                                                                                                            auto itB = std::find(nazivi.begin(), nazivi.end(), b.second);
                                                                                                                                            if(itA < itB) return true;
                                                                                                                                            return false;
                                                                                                                                      }
                                                                                                                                      return false; });
    if(!std::equal(spil.begin(), spil.end(), sortirani.begin(), [] (const std::pair<Boje, std::string> &a, const std::pair<Boje, std::string> &b) { if(a.first == b.first && a.second == b.second) return true; return false; })) throw std::logic_error("Neispravna lista!");
    int brojac = 0;
    auto it = spil.begin();
    std::queue<std::pair<std::string,std::string>> rezultat;
    while(brojac != b && spil.size() != 0) {
        for(int i(0); i < r - 1; i++) {
            it++;
            if(it == spil.end()) it = spil.begin();
        }
        rezultat.push(std::make_pair(PretvoriBojuUString(it->first), it->second));
        it = spil.erase(it);
        if(it == spil.end()) it = spil.begin();
        brojac++;
    }
    return rezultat;
}

void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil, std::queue<std::pair<std::string,std::string>> &red, int n)
{
    if(n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(n < 0) throw std::domain_error("Broj n je besmislen!");
    for(int i(0); i < red.size(); i++) {
        std::pair<std::string, std::string> par = red.front();
        red.pop();
        if(par.first != "Pik" && par.first != "Tref" && par.first != "Herc" && par.first != "Karo") throw std::logic_error("Neispravne karte!");
        auto it = std::find(nazivi.begin(), nazivi.end(), par.second);
        if(it == nazivi.end()) throw std::domain_error("Neispravne karte!");
        red.push(par);
    }
    if(spil.size()>52) 
        throw std::logic_error("Neispravna lista!");
    for(auto it(spil.begin()); it != spil.end(); it++) {
        auto pomocni = std::find(nazivi.begin(), nazivi.end(), it->second);
        if(pomocni == nazivi.end()) 
            throw std::logic_error("Neispravna lista!");
    }
    std::list<std::pair<Boje, std::string>> sortirani(spil);
    sortirani.sort([] (const std::pair<Boje, std::string> &a, const std::pair<Boje, std::string> &b) { if(a.first < b.first) return true;
                                                                                                       else if(a.first == b.first) {
                                                                                                             auto itA = std::find(nazivi.begin(), nazivi.end(), a.second);
                                                                                                             auto itB = std::find(nazivi.begin(), nazivi.end(), b.second);
                                                                                                             if(itA < itB) return true;
                                                                                                             return false;
                                                                                                       }
                                                                                                       return false; });
    if(!std::equal(spil.begin(), spil.end(), sortirani.begin(), [] (const std::pair<Boje, std::string> &a, const std::pair<Boje, std::string> &b) { if(a.first == b.first && a.second == b.second) return true; return false; })) throw std::logic_error("Neispravna lista!");
    for(int i(0); i < n; i++) {
        std::pair<std::string, std::string> par = red.front();
        red.pop();
        std::pair<Boje, std::string> karta;
        if(par.first == "Pik") karta.first = Boje::Pik;
        else if(par.first == "Tref") karta.first = Boje::Tref;
        else if(par.first == "Herc") karta.first = Boje::Herc;
        else karta.first = Boje::Karo;
        karta.second = par.second;
        auto iter = std::find_if(spil.begin(), spil.end(), [karta] (const std::pair<Boje, std::string> &par) { if(karta.first == par.first && karta.second == par.second) return true; return false; });
        if(iter == spil.end()) {
            spil.push_back(karta);
        }
        else {
            i--;
        }
    }
    spil.sort([] (const std::pair<Boje, std::string> &a, const std::pair<Boje, std::string> &b) { if(a.first < b.first) return true;
                                                                                                  else if(a.first == b.first) {
                                                                                                        auto itA = std::find(nazivi.begin(), nazivi.end(), a.second);
                                                                                                        auto itB = std::find(nazivi.begin(), nazivi.end(), b.second);
                                                                                                        if(itA < itB) return true;
                                                                                                        return false;
                                                                                                  }
                                                                                                  return false; });    
}

int main () {
    try{
    std::list<std::pair<Boje, std::string>> spil=KreirajSpil();
    std::cout<<"Unesite korak razbrajanja: ";
    int r;
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin>>b;
    auto red=IzbaciKarteRazbrajanjem(spil,r,b);
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: ";
    std::cout<<std::endl;
    std::cout<<"Pik: ";
    auto it=spil.begin();
   while(PretvoriBojuUString(it->first) == "Pik"){
     std::cout<<it->second<<" ";
     it++;
   }
    std::cout<<std::endl;
    std::cout<<"Tref: ";
   while(PretvoriBojuUString(it->first) == "Tref"){
       std::cout<<it->second<<" ";
       it++;
   }
   std::cout<<std::endl;
    std::cout<<"Herc: ";
   while(PretvoriBojuUString(it->first) == "Herc"){
       std::cout<<it->second<<" ";
       it++;
   }
   std::cout<<std::endl;
    std::cout<<"Karo: ";
   while(PretvoriBojuUString(it->first) == "Karo" && it!=spil.end()){
       std::cout<<it->second<<" ";
       it++;
   }
   
   std::cout<<std::endl;
    
std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
 int n;
 std::cin>>n;
VratiPrvihNKarata(spil,red,n);
 std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: ";
  std::cout<<std::endl;
   std::cout<<"Pik: ";
   it=spil.begin();
   while(PretvoriBojuUString(it->first) == "Pik"){
     std::cout<<it->second<<" ";
     it++;
   }
    std::cout<<std::endl;
    std::cout<<"Tref: ";
   while(PretvoriBojuUString(it->first)== "Tref"){
       std::cout<<it->second<<" ";
       it++;
   }
   std::cout<<std::endl;
    std::cout<<"Herc: ";
   while(PretvoriBojuUString(it->first)== "Herc"){
       std::cout<<it->second<<" ";
       it++;
   }
   std::cout<<std::endl;
    std::cout<<"Karo: ";
   while(PretvoriBojuUString(it->first)== "Karo" && it!=spil.end()){
       std::cout<<it->second<<" ";
       it++;
   }
}
   
catch (std::range_error e)
{
    std::cout<<"Izuzetak: "<<e.what();
}
catch (std::domain_error e)
{
    std::cout<<"Izuzetak: "<<e.what();
}
catch (std::logic_error e)
{
    std::cout<<"Izuzetak: "<<e.what();
}


return 0;
}

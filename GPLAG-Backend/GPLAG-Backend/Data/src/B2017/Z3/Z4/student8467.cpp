/B2017/2018: Zadaća 3, Zadatak 4
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <iterator>
#include <queue>
#include <vector>
#include <map>
#include <list>

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::list<std::pair<Boje,std::string>> Spil;
typedef std::pair<Boje,std::string> Karta;
typedef std::queue<std::pair<std::string,std::string>> Red;

//Vektor koji sadrži imena karata
std::vector<std::string> imena_karata({"2","3","4","5","6","7","8","9","10","J","Q","K","A"});
std::vector<std::string> boje_karata({"Pik", "Tref", "Herc", "Karo"});

//Kriteriji usporedbi karata;
//auto kriteriji = [](par p1, par p2){return p1.first < p2.first;};

bool Veci(Karta k1, Karta k2){
    auto it1(std::find(imena_karata.begin(), imena_karata.end(), k1.second));
    auto it2(std::find(imena_karata.begin(), imena_karata.end(), k2.second));
    return (std::make_pair(int(k1.first), it1) > std::make_pair(int(k2.first), it2));
}

bool Manji(Karta k1, Karta k2){
    auto it1(std::find(imena_karata.begin(), imena_karata.end(), k1.second));
    auto it2(std::find(imena_karata.begin(), imena_karata.end(), k2.second));
    return (std::make_pair(int(k1.first), it1) < std::make_pair(int(k2.first), it2));
}

Karta toKarta(std::string boja, std::string ime){
    auto it(std::find(boje_karata.begin(), boje_karata.end(), boja));
    int i = std::distance(boje_karata.begin(), it);
    return(std::make_pair(static_cast<Boje>(i), ime));
}

bool Neispravan(const Spil &spil){
    if(spil.size() > 52) return true;
    //Provjera pogresnog podatka;
    for(Karta i : spil){
        //Samo string može biti progresan ????????sa
        if(std::find(imena_karata.begin(), imena_karata.end(), i.second) == imena_karata.end()) return true;
    }
    //Provjera dobrog redoslijeda
    for(auto it(spil.begin()); it != spil.end(); ++it){
        auto temp(it);
        ++temp;
        if(temp == spil.end()) break;
        if(Veci(*it, *temp)){
            std::cout << int(it->first) << " " << int(temp->first);
            return true;
        }
    }
    return false;
}

void IspisiSpil(Spil spil){
    if(Neispravan(spil)) throw std::domain_error("Neispravna lista!");
    
    std::cout << "U spilu trenutno ima "<< spil.size() << " karata, i to:" << std::endl;
    std::cout << "Pik:";
    auto it(spil.begin());
    while(it != spil.end() && it->first == Boje::Pik){
        std::cout << " " << it->second;
        it++;
    }
    std::cout << std::endl;
    std::cout << "Tref:";
    while(it != spil.end() && it->first == Boje::Tref){
        std::cout << " " << it->second;
        it++;
    }
    std::cout << std::endl;
    std::cout << "Herc:";
    while(it != spil.end() && it->first == Boje::Herc){
        std::cout << " " << it->second;
        it++;
    }
    std::cout << std::endl;
    std::cout << "Karo:";
    while(it != spil.end() && it->first == Boje::Karo){
        std::cout << " " << it->second;
        it++;
    }
    
}

bool NeispravanRed(Red red){
    while (!red.empty()){
        //std::cout << red.front().first << red.front().second << std::endl;
        auto boja(find(boje_karata.begin(), boje_karata.end(), red.front().first));
        auto broj(find(boje_karata.begin(), boje_karata.end(), red.front().second));
        if(boja == boje_karata.end() || broj == imena_karata.end()) return true;
        red.pop();
    }
    return false;
}

Spil KreirajSpil(){
    Spil kreiran_spil;
    Boje boja(Boje::Pik);
    
    for(int i = 1; i <= 4; i++){
        for(int j = 0; j < imena_karata.size(); j++){
            kreiran_spil.push_back(std::make_pair(boja, imena_karata.at(j)));
        }
        boja = static_cast<Boje>(i);
    }
    return kreiran_spil;
}

void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> &izbacit){
    //Provjera validnosti proslijeđenog špila
    if(Neispravan(spil)) throw std::logic_error("Neispravna lista!");
    //Izbacivanje
    for(auto it = izbacit.begin(); it != izbacit.end(); ++it){
        //Ako pronađe kartu u špilu, izbaci ju iz špila i izbriši iz multimape
        auto karta = std::find_if(spil.begin(), spil.end(), [it](Karta p1){   return ((p1.first == it->first) && (p1.second == it->second));   });
        if(karta != spil.end()){
            spil.erase(karta);
            izbacit.erase(it);
        }
    }
}

Red IzbaciKarteRazbrajanjem(Spil &spil,const short int &korak,const int &broj){
    //Provjera validnosti proslijeđenog špila
    if(Neispravan(spil)) throw std::logic_error("Neispravna lista!");
    if(korak < 1 || korak > 52 || broj < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    //Deklaracija reda
    Red za_vratit;
    //Postavlja na kartu koju prvo treba izbaciti
    auto it = spil.begin();
    if(korak < spil.size()) std::advance(it, korak - 1);
    
    int broj_izbacenih(0);
    while(broj_izbacenih < broj && spil.size() > 0){
        bool pomjeren = false;
        if(it == spil.end() && !pomjeren){
            it = spil.begin();
            pomjeren = true;   
        }
        
        za_vratit.push({boje_karata.at(int(it->first)), it->second});
        
        it = spil.erase(it);
        broj_izbacenih++;
        
        //Zaduzeno za pomjeranje! Sumnjivo doboga!
        for(int i = 0; i < korak - 1; i++){
            if(broj_izbacenih == broj || spil.size() == 0) break;
            if(it == spil.end()){
                it = spil.begin();
                pomjeren = true;
                if(broj_izbacenih == broj) break;
            }
            
            it++;
        }
    }
    //Vraćanje popunjenog reda
    return za_vratit;
}

void VratiPrvihNKarata(Spil &spil, Red &red, int n){
    if(n < 0) throw std::domain_error("Broj n je besmislen!");
    if(n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(NeispravanRed(red)) throw std::logic_error("Neispravne karte!");
    if(Neispravan(spil)) throw std::domain_error("Neispravna lista!");
    
    int i(1);
    while (!red.empty() && i <= n){
        auto pok(std::lower_bound(spil.begin(), spil.end(), toKarta(red.front().first, red.front().second), Manji));
        //Koristi se za vraćanje karte na pravo mesto
        if(!Neispravan(spil) || spil.size() <= 1){ // Ako karta iz reda postoji, pok je karta iznad karte iz reda. 
            spil.insert(pok, toKarta(red.front().first, red.front().second));
            i++;
        }
        red.pop();
    }
}


int main ()
{
    Spil spil(KreirajSpil());
    short int korak;
    int broj_karata;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> korak;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> broj_karata;
    
    try{
        auto red1(IzbaciKarteRazbrajanjem(spil, korak, broj_karata));
        IspisiSpil(spil);
        std::cout << std::endl;
        int vrati;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> vrati;
        
        VratiPrvihNKarata(spil, red1, vrati);
        IspisiSpil(spil);
        
    }catch(std::exception &e){
        std::cout << "Izuzetak: " << e.what() << std::endl;
        return 0;
    }
    
	return 0;
}
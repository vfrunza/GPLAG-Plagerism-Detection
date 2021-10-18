/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <map>
#include <iterator>
#include <algorithm>
#include <queue>
#include <stdexcept>

enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje, std::string>> KreirajSpil(){
    std::list<std::pair<Boje, std::string>> spil;
    for(int i=0; i<4; i++){
        for(int j=2; j<=10; j++){
            spil.push_back(std::make_pair(Boje(i), std::to_string(j)));
        }
        spil.push_back(std::make_pair(Boje(i), "J"));
        spil.push_back(std::make_pair(Boje(i), "Q"));
        spil.push_back(std::make_pair(Boje(i), "K"));
        spil.push_back(std::make_pair(Boje(i), "A"));
    }
    return spil;
}

bool ProvjeriSpil(std::list<std::pair<Boje, std::string>> &spil){
    if(spil.size()>52)return true;
    auto pomocni_spil(KreirajSpil());
    auto it2(pomocni_spil.begin());
    bool ima_u_deku(false);
    for(auto it=spil.begin(); it!=spil.end(); it++){
        for(it2; it2!=pomocni_spil.end(); it2++){
            if(it->first==it2->first && it->second==it2->second){
                ima_u_deku=true;
                it2++;
                break;
            }
        }
        if(!ima_u_deku)return true;
        ima_u_deku=false;
    }
    return false;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> za_izbacit){
    if(ProvjeriSpil(spil))throw std::logic_error("Neispravna lista!");
    for(auto it = za_izbacit.begin(); it!=za_izbacit.end(); it++){
        std::list<std::pair<Boje, std::string>>::iterator nadji_it (std::find(spil.begin(), spil.end(), std::make_pair(it->first, it->second)));
        if(nadji_it!=spil.end()){
            za_izbacit.erase(it);
            spil.erase(nadji_it);
        }
    }
}

std::queue<std::pair<Boje, std::string>>  IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int &r, const int &b){
    if(r<1 || r>52 || b<1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(ProvjeriSpil(spil))throw std::logic_error("Neispravna lista!");
    std::queue<std::pair<Boje, std::string>> izbacene_karte;
    
    int brojac_koraka(0), brojac_izbrisanih(0);
    bool gotovo(false);
    for(;;){
        //std::cout << "\nbrojac_koraka=" << brojac_koraka << " brojac_izbrisanih=="
        auto it(spil.begin());
        if(spil.begin()==spil.end())break;
        for(it; it!=spil.end(); it++){
            //std::cout << "\ntusam\n";
            brojac_koraka++;
            if(brojac_izbrisanih==b){
                gotovo=true;
                break;
            }
            if(brojac_koraka==r){// treba izbacit kartu
                //std::cout << "\nnesto se desava\n";
                izbacene_karte.push(std::make_pair(it->first, it->second));
                it=spil.erase(it);
                it--;
                brojac_koraka=0;
                brojac_izbrisanih++;
            }
        }
        if(gotovo)break;
    }
    
    return izbacene_karte;
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<Boje, std::string>> &izbacene_karte, int n){
    //std::cout << "\nn=" << n << "  izbacene_karte.size=" << izbacene_karte.size() << "\n";
    if(n<0)throw std::domain_error("Broj n je besmislen!");
    if(n>izbacene_karte.size())throw std::range_error("Nedovoljno karata u redu!"); // size vrati unsigned int pa se moze poredit samo sa pozitivnim brojevima zato cu ispred stavit ovaj uslov gdje je n<1
    if(ProvjeriSpil(spil))throw std::logic_error("Neispravna lista!");
    
    //provjera reda dal su karte uredu DODATI
    
    
    int brojac_ubacenih(0);
    while(brojac_ubacenih<n){
        auto element_koji_se_ubacuje (izbacene_karte.front());
        
        //moram uradit ako vec ima u spilu taj element da ide continue ovde prije brojac_ubacenih++ a da se izbaci valjda iz reda i taj...
        bool uradi_continue(false);
        for(auto it=spil.begin(); it!=spil.end(); it++){
            if(it->first==element_koji_se_ubacuje.first && it->second==element_koji_se_ubacuje.second){// onda vec ima u spilu
                izbacene_karte.pop();
                uradi_continue=true;
                break;
            }
        }
        if(uradi_continue)continue;
        
        auto pomocni_spil(KreirajSpil());
        auto it_pozicija(spil.begin());
        for(auto it=pomocni_spil.begin(); it!=pomocni_spil.end(); it++){
            
            if(it->first==element_koji_se_ubacuje.first && it->second==element_koji_se_ubacuje.second){
                it_pozicija++;//posto on se ubaci na mjesto na koje pokazuje ovaj iterator a ono sto je bilo sve desno pomjeri od sebe...
                spil.insert(it_pozicija, element_koji_se_ubacuje);
                break;
            }
            
            for(auto it2=spil.begin(); it2!=spil.end(); it2++){
                if(it->first==it2->first && it->second==it2->second)it_pozicija=it2;
            }
           
        }
        
        
        izbacene_karte.pop();
        brojac_ubacenih++;
    }
    
}

void IspisiSpil(std::list<std::pair<Boje, std::string>> &spil){
    Boje pomocna(Boje::Karo);
    std::vector<std::string>boje_pomoc{"Pik", "Tref", "Herc", "Karo"};
    for(auto it=spil.begin(); it!=spil.end(); it++){
        if(it->first!=pomocna){
            std::cout << "\n" << boje_pomoc[int(it->first)] << ": ";
            pomocna=it->first;
        }
        std::cout << it->second << " ";
    }
    
}

//PROVJERITI OVU FUNKCIJU IZBRISI OBICNU...

int main ()
{
    int r, b, n;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    auto spil(KreirajSpil());
    std::queue<std::pair<Boje, std::string>> izbacene_karte;
    try{
        izbacene_karte = IzbaciKarteRazbrajanjem(spil, r, b);
    }    
    catch(std::logic_error &e){
        std::cout << "Izuzetak: " << e.what();
        return 0;
    }
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
    IspisiSpil(spil);
    std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
    std::cin >> n;
    try{
        VratiPrvihNKarata(spil, izbacene_karte, n);
        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
        IspisiSpil(spil);
    }
    catch(std::domain_error &e){
        std::cout << "Izuzetak: " << e.what();
    }
    catch(std::range_error &e){
        std::cout << "Izuzetak: " << e.what();
    }
    catch(std::logic_error &e){
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}

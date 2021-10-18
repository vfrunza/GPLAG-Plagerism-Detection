/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <map>
#include <queue>
#include <stdexcept>

enum class Boje{Pik, Tref, Herc, Karo};

std::list<std::pair<Boje,std::string>> KreirajSpil(){
    std::vector<Boje> v_Boje{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    std::vector<std::string> v_Br{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::list<std::pair<Boje, std::string>> spil;
    for(auto &r:v_Boje)
       for(auto &t:v_Br)
          spil.push_back(std::make_pair(r,t));
    return spil;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> mp){
    //Da li je lista ispravna
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    std::vector<std::string> v_Br{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::vector<Boje> v_Boje{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
   
    auto it_s(spil.begin());
    auto it_br(v_Br.begin());
    auto it_boje(v_Boje.begin());
    
    while(it_s != spil.end()){
        if(it_s->first != *it_boje) throw std::logic_error("Neispravna lista!");
            if(it_s->second == *it_br) it_s++;
            it_br++;
            if(it_br==v_Br.end()) {
                it_boje++;
                it_br=v_Br.begin();
            }
    }
    
    auto it_mp(mp.begin());
    while(it_mp!=mp.end()){
        auto it_s(spil.begin());
        while(it_s!=spil.end()){
            if((it_s->first==it_mp->first) && (it_s->second==it_mp->second)){
                it_s=spil.erase(it_s);
                it_mp=mp.erase(it_mp);
                it_s--;
                it_mp--;
                break;
            }
            it_s++;
        }
        it_mp++;
    }
}

std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int r, const int b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    //Da li je lista ispravna
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    std::vector<std::string> v_Br{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::vector<Boje> v_Boje{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
   
    auto it_s(spil.begin());
    auto it_br(v_Br.begin());
    auto it_boje(v_Boje.begin());
    
    while(it_s != spil.end()){
        if(it_s->first != *it_boje) throw std::logic_error("Neispravna lista!");
            if(it_s->second == *it_br) it_s++;
            it_br++;
            if(it_br==v_Br.end()) {
                it_boje++;
                it_br=v_Br.begin();
            }
    }
    auto it=spil.begin();
    int i=1, br=0;
    std::queue<std::pair<Boje, std::string>> red;
    while(br!=b){
        if(i==r){
            red.push(*it);
            it=spil.erase(it);
            i=1;
            br++;
            //if(it!=spil.begin()) it--;
        }
    i++;
    it++;
    if(it==spil.end()) it=spil.begin();
    }
    return red;
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<Boje, std::string>> &red, int n){
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
    //Da li je lista ispravna
    
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    std::vector<std::string> v_Br{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::vector<Boje> v_Boje{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
   
    auto it_s(spil.begin());
    auto it_br(v_Br.begin());
    auto it_boje(v_Boje.begin());
    /*
    while(it_s != spil.end()){
        if(it_s->first != *it_boje) throw std::logic_error("Neispravna lista!");
            if(it_s->second == *it_br) it_s++;
            it_br++;
            if(it_br==v_Br.end()) {
                it_boje++;
                it_br=v_Br.begin();
            }
    }
    */
    //Da li su ispravne karte
    
    
    //Actual funkcija
    for(int i=0; i<n; i++){
        std::pair<Boje, std::string> karta = red.front();
        auto it_s=spil.begin();
        auto it_br=v_Br.begin();
        while(it_s!=spil.end()){
            if(karta.first == it_s->first){
                if(*it_br!=it_s->second){
                    if(*it_br==karta.second){
                        spil.insert(it_s, karta);
                        red.pop();
                        break;
                    }
                    else it_s--;
                }
                it_br++;
            }
            it_s++;
        }
    }
}


int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    short int r;
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin>>b;
    std::list<std::pair<Boje,std::string>> spil = KreirajSpil();
    
    try{
    std::queue<std::pair<Boje, std::string>> red = IzbaciKarteRazbrajanjem(spil,r,b);
    
    //Ispisivanje
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
    std::cout<<"Pik:";
    for(auto x:spil){
        if(x.first == Boje::Pik) std::cout<<" "<<x.second;
    } 
    std::cout<<" "<<std::endl<<"Tref:";
     for(auto x:spil){
        if(x.first == Boje::Tref) std::cout<<" "<<x.second;
    } 
    std::cout<<" "<<std::endl<<"Herc:";
     for(auto x:spil){
        if(x.first == Boje::Herc) std::cout<<" "<<x.second;
    } 
    std::cout<<" "<<std::endl<<"Karo:";
     for(auto x:spil){
        if(x.first == Boje::Karo) std::cout<<" "<<x.second;
    } 
    std::cout<<" ";
    
    //Vracanje karata
    std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
    int n;
    std::cin>>n;
    VratiPrvihNKarata(spil, red, n);
    }
    catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
		
	}
	catch(std::range_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
	catch(std::logic_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
    //Ispisivanje
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
    
    
    std::cout<<"Pik:";
    for(auto x:spil){
        if(x.first == Boje::Pik) std::cout<<" "<<x.second;
    } 
    std::cout<<" "<<std::endl<<"Tref:";
     for(auto x:spil){
        if(x.first == Boje::Tref) std::cout<<" "<<x.second;
    } 
    std::cout<<" "<<std::endl<<"Herc:";
     for(auto x:spil){
        if(x.first == Boje::Herc) std::cout<<" "<<x.second;
    } 
    std::cout<<" "<<std::endl<<"Karo:";
     for(auto x:spil){
        if(x.first == Boje::Karo) std::cout<<" "<<x.second;
    } 
    std::cout<<" ";
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <queue>
#include <iterator>
typedef std::vector<std::string> VS;
enum class Boje {Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje,std::string>> LP;
typedef std::queue<std::pair<std::string,std::string>> RedKarata ;
void ispravna_lista(const LP &spil){
    VS karte={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
   
    auto it1(spil.begin());
    for ( int i = 0; i < 4; i++) {
        auto it2(karte.begin());
        if(Boje(i)>it1->first)
            throw std::logic_error("Neispravna lista!");
        while (it1!=spil.end() && it1->first==Boje(i)) {
            bool ispravan(false);
            while (*it2!=it1->second && it2!=karte.end())
                it2++;
            if(it2!=karte.end() && *it2==it1->second)
                ispravan=true;
            if(!ispravan)
                throw std::logic_error("Neispravna lista!");
            it1++;
        }
     }    
}
LP KreirajSpil(){
    VS karte={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    LP spil;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            spil.push_back(std::pair<Boje,std::string>{Boje(i),karte[j]});
        }
    }
    return spil;
}
void IzbaciKarte(LP &spil, std::multimap<Boje,std::string> &za_izbaciti){
     ispravna_lista(spil);
      if(spil.size()==0)
        throw std::logic_error("Neispravna lista!");
    int  velicina=za_izbaciti.size();
    auto it1=spil.begin();
    for (int i = 0; i < 4; i++) {
        while ( (it1->first) !=Boje(i)&& it1!=spil.end()) it1++;
        while (it1->first==Boje(i)) { 
            auto it2=za_izbaciti.find(Boje(i));
            while (it2!=za_izbaciti.end()&& (it2->second) != (it1->second) && (it2->first)==Boje(i) ) it2++;
            while (it2!=za_izbaciti.end()&& (it2->second) == (it1->second) && (it2->first)==Boje(i)) {
                it2=za_izbaciti.erase(it2);
            }
            if(velicina>za_izbaciti.size()){
                it1=spil.erase(it1);
                velicina=za_izbaciti.size();
            }
            else 
                it1++;
        }
    }
}
RedKarata IzbaciKarteRazbrajanjem(LP &spil,const short int &r,const int &b ){
    RedKarata izbacene;
     if(spil.size()==0)
        throw std::logic_error("Neispravna lista!");
    VS boje={"Pik","Tref","Herc","Karo"};
    auto it=spil.begin();
    if(r<1 or b<1 or r>52)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    for (int i = 0; i < b; i++) {
        if(spil.size()==0) break;
        for (int j = 0; j < r-1; j++) {
            it++;
            //auto it2(std::advance(it1,i));
            if(it==spil.end())
                it=spil.begin();
        }
      izbacene.push(make_pair(boje[int(it->first)],it->second));  
    //    spil.push_back(*it);
        it=spil.erase(it);
    }
    return izbacene;
}
void VratiPrvihNKarata(LP &spil, RedKarata &vratiti, const int &n){
    VS karte={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    VS boje={"Pik","Tref","Herc","Karo"};
    if(n<0)
        throw std::domain_error("Broj n je besmislen!");
    if(n>vratiti.size())
        throw std::range_error("Nedovoljno karata u redu!");
    ispravna_lista(spil);
    for (int i = 0; i < n; i++) {
        auto it=spil.begin();
        auto it1=std::find(boje.begin(),boje.end(),vratiti.front().first);
        auto it3=std::find(karte.begin(),karte.end(),vratiti.front().second);
        if(it3==karte.end())
            throw std::logic_error("Neispravne karte!");
        if(it1==boje.end())
            throw std::logic_error("Neispravne karte!");
        int boja=it1-boje.begin();
        if(std::find(spil.begin(),spil.end(),make_pair(Boje(boja),*it3))==spil.end()){
        while ( it != spil.end() && int (it->first)< boja  ) it++;
        while( it != spil.end() &&  it -> first ==Boje(boja) && std::find(karte.begin(),karte.end(),it->second)<it3)
            it++;
        spil.insert(it,make_pair(Boje(boja),*it3));
        }
        vratiti.pop();
    }
}
int main (){
    int r,b,n;
    LP spil=KreirajSpil();
    std::cout << "Unesite korak razbrajanja: " ;
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: " ;
    std::cin >> b;
    RedKarata red;
    try{
    red=IzbaciKarteRazbrajanjem(spil,r,b);
    }
    catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    std::cout << "U spilu trenutno ima "<<spil.size() <<" karata, i to: " << std::endl;
    auto it=spil.begin();
    for (int i = 0; i < 4; i++) {
        VS boje={"Pik: ","Tref: ","Herc: ","Karo: "};
        std::cout << boje[i];
        while (it!=spil.end() && it->first==Boje(i)) std::cout << (it++)->second<<" ";
        std::cout  << std::endl;
    }
    std::cout << "Unesite broj karata koje zelite vratiti u spil: " ;
    std::cin >> n;
    try{
    VratiPrvihNKarata(spil,red,n);
    }
    catch(std::domain_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    catch(std::range_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
        return 0;
    }
    std::cout << "U spilu trenutno ima "<<spil.size()<<" karata, i to: " << std::endl;
    it=spil.begin();
    for (int i = 0; i < 4; i++) {
        VS boje={"Pik: ","Tref: ","Herc: ","Karo: "};
        std::cout << boje[i];
        while (it!=spil.end() && it->first==Boje(i)) std::cout << (it++)->second<<" ";
        std::cout  << std::endl;
    }
	return 0;
}


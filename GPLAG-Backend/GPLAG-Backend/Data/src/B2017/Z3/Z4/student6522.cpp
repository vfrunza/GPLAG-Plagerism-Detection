/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <queue>
#include <utility>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
enum class Boje {Pik, Tref, Herc, Karo};
std::vector<std::string> bojekarata{"Pik", "Tref", "Herc", "Karo"};

std::list<std::pair<Boje, std::string>> KreirajSpil(){
    std::vector<std::string> ImenaKarata{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::list<std::pair<Boje, std::string>> lista;
    for(int i(0); i<4; i++){
        for(int j(0); j<13; j++){
            if(i==0)
            lista.push_back(std::make_pair(Boje::Pik,ImenaKarata.at(j)));
            else if(i==1)
            lista.push_back(std::make_pair(Boje::Tref,ImenaKarata.at(j)));
            else if(i==2)
            lista.push_back(std::make_pair(Boje::Herc,ImenaKarata.at(j)));
            else if(i==3)
            lista.push_back(std::make_pair(Boje::Karo,ImenaKarata.at(j)));
        }
    }
    return lista;
}
bool Poredak(std::list<std::pair<Boje,std::string>>::iterator it, std::list<std::pair<Boje,std::string>>::iterator it2){
    if(int(it->first)>int(it2->first)) return false;
    else if(int(it->first)==int(it2->first)){
    if((it->second=="2" || it->second=="3" || it->second=="4" || it->second=="5" || it->second=="6" || it->second=="7" || it->second=="8" || it->second=="9") && (it2->second=="2" || it2->second=="3" || it2->second=="4" || it2->second=="5" || it2->second=="6" || it2->second=="7" || it2->second=="8" || it2->second=="9") && (it->second>it2->second)) return false;
    else if((it->second=="10" || it->second=="J" || it->second=="K" || it->second=="Q" || it->second=="A") && (it2->second=="2" || it2->second=="3" || it2->second=="4" || it2->second=="5" || it2->second=="6" || it2->second=="7" || it2->second=="8" || it2->second=="9")) return false;
    else if((it->second=="J") && (it2->second=="10")) return false;
    else if((it->second=="Q") && (it2->second=="10" || it2->second=="J")) return false;
    else if((it->second=="K") && (it2->second=="10" || it2->second=="J" || it2->second=="Q")) return false;
    else if((it->second=="A") && (it2->second=="10" || it2->second=="J" || it2->second=="K" || it2->second=="Q")) return false;
    }
    return true;
}
bool KonacnoPoredjenje(const std::pair<Boje, std::string> &p1, const std::pair<Boje, std::string> &p2){
    if(int(p1.first)>int(p2.first)) return false;
    else if(int(p1.first)==int(p2.first)){
    if((p1.second=="2" || p1.second=="3" || p1.second=="4" || p1.second=="5" || p1.second=="6" || p1.second=="7" || p1.second=="8" || p1.second=="9") && (p2.second=="2" || p2.second=="3" || p2.second=="4" || p2.second=="5" || p2.second=="6" || p2.second=="7" || p2.second=="8" || p2.second=="9")) return p1.second<p2.second;
    else if((p1.second=="10" || p1.second=="J" || p1.second=="K" || p1.second=="Q" || p1.second=="A") && (p2.second=="2" || p2.second=="3" || p2.second=="4" || p2.second=="5" || p2.second=="6" || p2.second=="7" || p2.second=="8" || p2.second=="9")) return false;
    else if((p1.second=="J") && (p2.second=="10")) return false;
    else if((p1.second=="Q") && (p2.second=="10" || p2.second=="J")) return false;
    else if((p1.second=="K") && (p2.second=="10" || p2.second=="J" || p2.second=="Q")) return false;
    else if((p1.second=="A") && (p2.second=="10" || p2.second=="J" || p2.second=="K" || p2.second=="Q")) return false;
    }
    return true;
}
void IzbaciKarte(std::list<std::pair<Boje, std::string>> &lista, std::multimap<Boje, std::string> &multimapa){
    if(lista.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it(lista.begin()); it!=lista.end(); it++){
        if(it->first!=Boje::Pik && it->first!=Boje::Herc && it->first!=Boje::Karo && it->first!=Boje::Tref) throw std::logic_error("Neispravna lista!");
        if(it->second!="2" && it->second!="3" && it->second!="4" && it->second!="5" && it->second!="6" && it->second!="7" && it->second!="8" && it->second!="9" && it->second!="10" && it->second!="J" && it->second!="K" && it->second!="Q" && it->second!="A") throw std::logic_error("Neispravna lista!");
    }
    auto pomocni1(lista.begin());
    auto pomocni2(lista.begin());
    pomocni2++;
    for(int i(0); i<lista.size(); i++){
        if(pomocni2==lista.end()) break;
        if(!Poredak(pomocni1,pomocni2)) throw std::logic_error("Neispravna lista!");
        pomocni1++;
        pomocni2++;
    }
    for(auto it(lista.begin()); it!=lista.begin(); it++){
        for(auto it2(multimapa.begin()); it2!=multimapa.end(); it2++){
            if(int(it->first)==int(it2->first) && it->second==it2->second){
                it=lista.erase(it);
                if(it!=lista.begin()) it--;
                multimapa.erase(it2);
            }
        }
    }
}
std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &lista, const short int &razbrajanje, const int &brojkarata){
    if(razbrajanje<1 || razbrajanje>52 || brojkarata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
     for(auto it(lista.begin()); it!=lista.end(); it++){
        if(it->first!=Boje::Pik && it->first!=Boje::Herc && it->first!=Boje::Karo && it->first!=Boje::Tref) throw std::logic_error("Neispravna lista!");
        if(it->second!="2" && it->second!="3" && it->second!="4" && it->second!="5" && it->second!="6" && it->second!="7" && it->second!="8" && it->second!="9" && it->second!="10" && it->second!="J" && it->second!="K" && it->second!="Q" && it->second!="A") throw std::logic_error("Neispravna lista!");
    }
    auto pomocni1(lista.begin());
    auto pomocni2(lista.begin());
    pomocni2++;
    for(int i(0); i<lista.size(); i++){
        if(pomocni2==lista.end()) break;
        if(!Poredak(pomocni1,pomocni2)) throw std::logic_error("Neispravna lista!");
        pomocni1++;
        pomocni2++;
    }
    std::queue<std::pair<std::string, std::string>> red;
    auto it(lista.begin());
    int brojac(1);
    int izbaceni(0);
    for(; ;){
        if(lista.size()==0 || izbaceni==brojkarata) break;
        if(it==lista.end()) it=lista.begin();
        if(brojac%razbrajanje==0){
            if(it->first==Boje::Pik) red.push(std::make_pair("Pik",it->second));
            else if(it->first==Boje::Karo) red.push(std::make_pair("Karo", it->second));
            else if(it->first==Boje::Herc) red.push(std::make_pair("Herc", it->second));
            else if(it->first==Boje::Tref) red.push(std::make_pair("Tref", it->second));
            it=lista.erase(it);
            izbaceni++;
        }
        else
        it++;
        brojac++;
        }
        return red;
}
void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &lista, std::queue<std::pair<std::string, std::string>> &red, int n){
    if(int(n)>int(red.size()))
        throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(lista.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it(lista.begin()); it!=lista.end(); it++){
        if(it->first!=Boje::Pik && it->first!=Boje::Herc && it->first!=Boje::Karo && it->first!=Boje::Tref) throw std::logic_error("Neispravna lista!");
        if(it->second!="2" && it->second!="3" && it->second!="4" && it->second!="5" && it->second!="6" && it->second!="7" && it->second!="8" && it->second!="9" && it->second!="10" && it->second!="J" && it->second!="K" && it->second!="Q" && it->second!="A") throw std::logic_error("Neispravna lista!");
    }
    auto pomocni1(lista.begin());
    auto pomocni2(lista.begin());
    pomocni2++;
    for(int i(0); i<lista.size(); i++){
        if(pomocni2==lista.end()) break;
        if(!Poredak(pomocni1,pomocni2)) throw std::logic_error("Neispravna lista!");
        pomocni1++;
        pomocni2++;
    }
    
    while((!red.empty()) && (n>0)){
        if((red.front()).first!="Karo" && (red.front()).first!="Herc" && (red.front()).first!="Pik" && (red.front()).first!="Tref") throw std::logic_error("Neispravne karte!");
        else if((red.front()).second!="2" && (red.front()).second!="3" && (red.front()).second!="4" && (red.front()).second!="5" && (red.front()).second!="6" && (red.front()).second!="7" && (red.front()).second!="8" && (red.front()).second!="9" && (red.front()).second!="10" && (red.front()).second!="J" && (red.front()).second!="K" && (red.front()).second!="Q" && (red.front()).second!="A") throw std::logic_error("Neispravne karte!");
        if((red.front()).first=="Karo"){
        auto it(std::find(lista.begin(), lista.end(), std::make_pair(Boje::Karo,(red.front()).second)));
        if(it==lista.end()) lista.push_back(std::make_pair(Boje::Karo, (red.front()).second)); 
        }
        else if((red.front()).first=="Herc"){
            auto it(std::find(lista.begin(), lista.end(), std::make_pair(Boje::Herc,(red.front()).second)));
            if(it==lista.end()) lista.push_back(std::make_pair(Boje::Herc, (red.front()).second)); 
        }
        else if((red.front()).first=="Pik"){
            auto it(std::find(lista.begin(), lista.end(), std::make_pair(Boje::Pik,(red.front()).second)));
            if(it==lista.end()) lista.push_back(std::make_pair(Boje::Pik, (red.front()).second)); 
        }
        else if((red.front()).first=="Tref"){
            auto it(std::find(lista.begin(), lista.end(), std::make_pair(Boje::Tref,(red.front()).second)));
            if(it==lista.end()) lista.push_back(std::make_pair(Boje::Tref, (red.front()).second)); 
        }
        red.pop();
        n--;
    }
    lista.sort(KonacnoPoredjenje);
}
int main ()
{
    try{
    short int korak_razbrajanja;
    int broj_karata_za_izbaciti;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>korak_razbrajanja;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>broj_karata_za_izbaciti;
    if((korak_razbrajanja<1 || korak_razbrajanja>52) || (broj_karata_za_izbaciti<1)) throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::list<std::pair<Boje, std::string>> lista(KreirajSpil());
    try{
    auto red(IzbaciKarteRazbrajanjem(lista,korak_razbrajanja,broj_karata_za_izbaciti));
    std::cout<<"U spilu trenutno ima "<<lista.size()<<" karata, i to: ";
    auto it(lista.begin());
    int i(0);
    for(i=0; i<4; i++){
        std::cout<<"\n"<<bojekarata.at(i)<<": ";
        while((it!=lista.end()) && (int(it->first)==i)) std::cout<<(*it++).second<<" "; 
    }    
    try{
        int broj_karata_za_vratiti;
        std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        std::cin>>broj_karata_za_vratiti;
        VratiPrvihNKarata(lista,red, broj_karata_za_vratiti);
        std::cout<<"U spilu trenutno ima "<<lista.size()<<" karata, i to: ";
        it=lista.begin();
        int i(0);
        for(i=0; i<4; i++){
        std::cout<<"\n"<<bojekarata.at(i)<<": ";
        while((it!=lista.end()) && (int(it->first)==i)) std::cout<<(*it++).second<<" "; 
        }
    }catch(std::range_error rang1){
        std::cout<<"Izuzetak: "<<rang1.what();
    }catch(std::domain_error  domena1){
        std::cout<<"Izuzetak: "<<domena1.what();
    }catch(std::logic_error logika1){
        std::cout<<"Izuzetak: "<<logika1.what();
    }  
    }catch(std::logic_error logika2){
        std::cout<<"Izuzetak: "<<logika2.what();
    }
    }catch(std::logic_error logika3){
        std::cout<<"Izuzetak: "<<logika3.what();
    }
	return 0;
}

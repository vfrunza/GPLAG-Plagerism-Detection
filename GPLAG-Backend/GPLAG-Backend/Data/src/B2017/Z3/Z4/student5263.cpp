/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <iterator>
#include <stdexcept>
enum class Boje{Pik, Tref, Herc, Karo};
void IspisiListu(std::list<std::pair<Boje,std::string>> lista){
    std::cout<<std::endl;
    std::cout<<"Pik: ";
    for(auto it=lista.begin(); it!=lista.end(); it++){
        if((*it).first==Boje::Pik) std::cout<<(*it).second<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Tref: ";
    for(auto it=lista.begin(); it!=lista.end(); it++){
        if((*it).first==Boje::Tref) std::cout<<(*it).second<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Herc: ";
    for(auto it=lista.begin(); it!=lista.end(); it++){
        if((*it).first==Boje::Herc) std::cout<<(*it).second<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Karo: ";
    for(auto it=lista.begin(); it!=lista.end(); it++){
        if((*it).first==Boje::Karo) std::cout<<(*it).second<<" ";
    }
}
std::list<std::pair<Boje,std::string>> KreirajSpil(){
    std::list<std::pair<Boje,std::string>> spil;
    std::vector<std::string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(int i=0; i<v.size(); i++)    spil.push_back(std::make_pair(Boje::Pik, v.at(i)));
    for(int i=0; i<v.size(); i++)    spil.push_back(std::make_pair(Boje::Tref, v.at(i)));
    for(int i=0; i<v.size(); i++)    spil.push_back(std::make_pair(Boje::Herc, v.at(i)));
    for(int i=0; i<v.size(); i++)    spil.push_back(std::make_pair(Boje::Karo, v.at(i)));
    return spil;
}
void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil, std::multimap<Boje,std::string> &mapa){
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    if(KreirajSpil()!=spil) throw std::logic_error("Neispravna lista!");
    std::multimap<Boje,std::string>::iterator it;
    std::list<std::pair<Boje,std::string>>::iterator it1;
    for(it=mapa.begin(); it!=mapa.end(); ++it){
        for(it1=spil.begin(); it1!=spil.end(); ++it1){
            if((*it1).first==(*it).first && (*it1).second==(*it).second) spil.erase(it1--);
        }
    }
}
std::queue<std::pair<Boje,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil, const short int &r, const int &b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    std::list<std::pair<Boje,std::string>>::iterator it=spil.begin();
    std::queue<std::pair<Boje,std::string>> red;
    int broj=b;
    while(broj!=0){
        int velicina=r;
        while(velicina!=0){
            velicina--;
            if(it==spil.end()){
                it=spil.begin();
            }
            it++;
        }
        it--;
        red.push(*it);
        if(it==spil.begin()){
            spil.erase(it);
            
            it=spil.end();
        } 
        else{
            spil.erase(it--);
        }  
        broj--;
        it++;
    }
    return red;
}
bool KriterijSortiranja(std::pair<Boje,std::string> p1, std::pair<Boje,std::string> p2){
    std::vector<std::string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    bool vrati=false;
    if(p1.first==Boje::Pik){
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
            if(p1.second==v.at(i) && p2.second==v.at(j)) return i<j;
            }
        }
    }
    if(p1.first==Boje::Tref){
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
            if(p1.second==v.at(i) && p2.second==v.at(j)) return i<j;
            }
        }
    }
    if(p1.first==Boje::Herc){
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
            if(p1.second==v.at(i) && p2.second==v.at(j)) return i<j;
            }
        }
    }
    if(p1.first==Boje::Karo){
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
            if(p1.second==v.at(i) && p2.second==v.at(j)) return i<j;
            }
        }
    }
    return vrati;
}
void VratiPrvihNClanova(std::list<std::pair<Boje,std::string>> &spil, std::queue<std::pair<Boje,std::string>> &red, int n){
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    std::list<std::pair<Boje,std::string>>::iterator it1=spil.begin();
//    if(ima==false) throw std::logic_error("Neispravna lista!");
    int broj=n;
    while (broj!=0) {
        it1=spil.begin();
        for(auto it=spil.begin(); it!=spil.end(); it++)
        if(red.front().first!=(*it).first && red.front().second!=(*it).second){ spil.insert(it1,red.front()); break;}
        red.pop();
        broj--;
    }
    spil.sort(KriterijSortiranja);
}

int main ()
{
    int n, m, m1;
    std::cout<<"Unesite korak razbrajanja: ";
    try{
        std::cin>>n;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>m;
        auto lista=KreirajSpil();
        auto red=IzbaciKarteRazbrajanjem(lista,n,m);
        std::cout<<"U spilu trenutno ima "<<52-m<<" karata, i to: ";
        //std::multimap<Boje,std::string> mapa;
        //mapa.insert ( std::pair<Boje,std::string>(Boje::Pik,"A"));
        //IzbaciKarte(lista,mapa);
        IspisiListu(lista);
/*        while (!red.empty()) {
            std::cout<<int(red.front().first)<<"-"<<red.front().second<<" ";
            red.pop();
        }*/
        std::cout<<std::endl;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>m1;
        VratiPrvihNClanova(lista,red,m1);
        std::cout<<"U spilu trenutno ima "<<52-m+m1<<" karata, i to: ";
        IspisiListu(lista);
    }catch(std::logic_error Izuzetak){
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
    }catch(std::range_error Izuzetak){
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
    }
	return 0;
}

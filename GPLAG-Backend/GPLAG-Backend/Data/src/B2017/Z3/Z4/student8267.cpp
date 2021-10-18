/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <stdexcept>
#include <queue>
#include <utility>
#include <algorithm>
#include <iterator>
#include <vector>
enum class Boje {Pik, Tref, Herc, Karo};

int dajBroj(std::string broj){
    if(broj=="10")
        return 10;
    else
        return broj[0]-'0';
}

int dajPoziciju(std::pair<Boje,std::string> par){
    int pozicija=0;
    if(par.first==Boje::Pik)
        pozicija+=100;
    else if(par.first==Boje::Tref)
        pozicija+=200;
    else if(par.first==Boje::Herc)
        pozicija+=300;
    else
        pozicija+=400;
    
    if(par.second=="10"){
        pozicija+='9'-'0'+1;
        return pozicija;
    }
    if(par.second=="A"){
        pozicija+=65;
    }
    else if(par.second=="J"){
        pozicija+=60;
    }
    else if(par.second=="Q"){
        pozicija+=61;
    }
    else if(par.second=="K"){
        pozicija+=62;
    }
    else{
        pozicija+=par.second[0]-'0';
    }
    return pozicija;
}

std::list<std::pair<Boje,std::string>> KreirajSpil(){
    std::list<std::pair<Boje,std::string>> spil;
    std::pair<Boje,std::string> pom_par;
    std::string pom_string;
    Boje boje=Boje::Pik;
      for(int j(0);j<4;j++){
            if(j==1) boje=Boje::Tref;
            if(j==2) boje=Boje::Herc;
            if(j==3) boje=Boje::Karo;
            for(int i(2);i<15;i++){
                    if(i==11) pom_string='J';
                    if(i==12) pom_string='Q';
                    if(i==13) pom_string='K';
                    if(i==14) pom_string='A';
                       if(i<11){
                            pom_string=std::to_string(i);
                            pom_par=std::make_pair(boje,pom_string);
                            spil.push_back(pom_par);
                        }
                        if(i>=11){
                             pom_par=std::make_pair(boje,pom_string);
                             spil.push_back(pom_par);
                        }
                    }
        }
    return spil;
}
bool DaLiJeBesmislena(std::pair<Boje,std::string> x){
    std::string pom_string;
    Boje boje=Boje::Pik;
    for(int i(2);i<15;i++){
        if(i<11)  pom_string=std::to_string(i);;
        if(i==11) pom_string='J';
        if(i==12) pom_string='Q';
        if(i==13) pom_string='K';
        if(i==14) pom_string='A';
        for(int j(0);j<4;j++){
            if(j==0) boje=Boje::Pik;
            if(j==1) boje=Boje::Tref;
            if(j==2) boje=Boje::Herc;
            if(j==3) boje=Boje::Karo;
                if(x.first==boje&&x.second==pom_string) return true;
        }
    }
    return false;
}
int DaLiSuSortiraniIspravno(std::list<std::pair<Boje,std::string>> spil){
    try{
    int brojac(0);
    auto it=spil.begin();
    std::string pom_string;
    Boje boje=Boje::Pik;
    std::pair<Boje,std::string> pom;
      for(int j(0);j<4;j++){
            if(j==0) boje=Boje::Pik;
            if(j==1) boje=Boje::Tref;
            if(j==2) boje=Boje::Herc;
            if(j==3) boje=Boje::Karo;
            for(int i(2);i<15;i++){
                    if(i<11)  pom_string=std::to_string(i);;
                    if(i==11) pom_string='J';
                    if(i==12) pom_string='Q';
                    if(i==13) pom_string='K';
                    if(i==14) pom_string='A';
                        pom=std::make_pair(boje,pom_string);
                        if(*it==pom){
                             brojac++;
                             it++;
                        }
                    }
        }
    return brojac;
    }
    catch(...){
        throw;
    }
}
void IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil,std::multimap<Boje,std::string> &mapa){
    try{
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto pom=spil.begin();pom!=spil.end();pom++){
       if(!DaLiJeBesmislena(*pom)) throw std::logic_error("Neispravna lista!");
    }
    int brojac=0;
    auto it2=spil.begin();
    while(brojac!=mapa.size()){
    it2=spil.begin();
    for(auto it=mapa.begin();it!=mapa.end();it++)
    {
        while(it2!=spil.end()){
           if((*it).first==(*it2).first&&(*it).second==(*it2).second){
                 it2=spil.erase(it2);
                 it=mapa.erase(it);
            }
            it2++;
        }
    
    }
    brojac++;
    }
    }
    catch(...){
        throw;
    }
}
std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil,const short int &r,const int &b){
    try{
    if(r<1||r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto pom=spil.begin();pom!=spil.end();pom++){
        if(!DaLiJeBesmislena(*pom)) throw std::logic_error("Neispravna lista!");
    }
    if(DaLiSuSortiraniIspravno(spil)!=spil.size()) throw std::logic_error("Neispravna lista!");
    std::queue<std::pair<std::string,std::string>> rez;
    int brojac(0);
    int d(b);
    std::string pom_string;
    std::pair<std::string,std::string> par;
    while(d!=0){
    for(auto it=spil.begin();it!=spil.end();it++){
        brojac++;
        if(brojac==r){
            if(d==0) break;
            if((*it).first==Boje::Pik) pom_string="Pik";
            if((*it).first==Boje::Tref) pom_string="Tref";
            if((*it).first==Boje::Herc) pom_string="Herc";
            if((*it).first==Boje::Karo) pom_string="Karo";
            par=std::make_pair(pom_string,(*it).second);   
            rez.push(par);
            it=spil.erase(it);
            d--;
            brojac=1;
        }
    }
    }
    return rez;
    }
    catch(...){
        throw;
    }
}
void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil,std::queue<std::pair<std::string,std::string>> &red,int n){
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(int(n)!=n||n<0) throw std::domain_error("Broj n je besmislen!");
    /*while(!red.empty()){
        if(!DaLiJeBesmislena(red.front())) throw std::logic_error("Neispravne karte!");
        red.pop();
    }*/
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto pom=spil.begin();pom!=spil.end();pom++){
        if(!DaLiJeBesmislena(*pom)) throw std::logic_error("Neispravna lista!");
    }
    if(DaLiSuSortiraniIspravno(spil)!=spil.size()) throw std::logic_error("Neispravna lista!");
    std::string pom_string;
    std::pair<std::string,std::string>  pom_par;
    std::pair<Boje,std::string> pravi_par;
    Boje boja=Boje::Pik;
    while(n>0){
       pom_par=red.front();
       if(pom_par.first=="Pik") boja=Boje::Pik;
       if(pom_par.first=="Tref") boja=Boje::Tref;
       if(pom_par.first=="Herc") boja=Boje::Herc;
       if(pom_par.first=="Karo") boja=Boje::Karo;
       pom_string=pom_par.second;
       pravi_par=std::make_pair(boja,pom_string);
       int poz=dajPoziciju(pravi_par);
       for(auto it=spil.begin();it!=spil.end();it++){
           int trenutni=dajPoziciju(*it);
           auto pom=it;
           pom++;
           pom++;
           if(trenutni==poz){
               break;
           }
           if(trenutni>poz){
               spil.insert(it,pravi_par);
               break;
           }
       }
    
       red.pop();
       n--;
       
    }
    
}
int main ()
{
    try{
        std::list<std::pair<Boje,std::string>> spil;
        spil=KreirajSpil();
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        int b;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        std::queue<std::pair<std::string,std::string>> red;
        int d(b);
        //red=IzbaciKarteRazbrajanjem(spil,r,b);
        std::cout<<"U spilu trenutno ima "<<52-d<<" karata, i to: ";
        std::cout<<std::endl;
        std::multimap<Boje,std::string> mapa={{Boje::Karo,"2"},{Boje::Tref,"10"}};
        IzbaciKarte(spil,mapa);
        
        auto pom=spil.begin();
       
            if((*pom).first==Boje::Pik){
                std::cout<<"Pik: ";
                while((*pom).first==Boje::Pik&&pom!=spil.end()){
                    std::cout<<(*pom).second<<" ";
                    pom++;
                }
                std::cout<<std::endl;
        }
             if((*pom).first==Boje::Tref){
                std::cout<<"Tref: ";
                while((*pom).first==Boje::Tref&&pom!=spil.end()){
                    std::cout<<(*pom).second<<" ";
                    pom++;
                }
                std::cout<<std::endl;
        }
             if((*pom).first==Boje::Herc){
                std::cout<<"Herc: ";
                while((*pom).first==Boje::Herc&&pom!=spil.end()){
                    std::cout<<(*pom).second<<" ";
                    pom++;
                }
                std::cout<<std::endl;
        }
         if((*pom).first==Boje::Karo){
                std::cout<<"Karo: ";
                while((*pom).first==Boje::Karo&&pom!=spil.end()){
                    std::cout<<(*pom).second<<" ";
                      pom++;
                }
        }
        std::cout<<std::endl;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(spil,red,n);
        std::cout<<"U spilu trenutno ima "<<52-d+n<<" karata, i to: ";
        std::cout<<std::endl;       
        pom=spil.begin();
        if((*pom).first==Boje::Pik){
                std::cout<<"Pik: ";
                while((*pom).first==Boje::Pik&&pom!=spil.end()){
                    std::cout<<(*pom).second<<" ";
                    pom++;
                }
                std::cout<<std::endl;
        }
        if((*pom).first==Boje::Tref){
                std::cout<<"Tref: ";
                while((*pom).first==Boje::Tref&&pom!=spil.end()){
                    std::cout<<(*pom).second<<" ";
                    pom++;
                }
                std::cout<<std::endl;
        }
        if((*pom).first==Boje::Herc){
                std::cout<<"Herc: ";
                while((*pom).first==Boje::Herc&&pom!=spil.end()){
                    std::cout<<(*pom).second<<" ";
                    pom++;
                }
                std::cout<<std::endl;
        }
        if((*pom).first==Boje::Karo){
                std::cout<<"Karo: ";
                while((*pom).first==Boje::Karo&&pom!=spil.end()){
                    std::cout<<(*pom).second<<" ";
                      pom++;
                }
        }
         
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch(std::range_error e1){
        std::cout<<"Izuzetak: "<<e1.what();
    }
    catch(std::domain_error e2){
        std::cout<<"Izuzetak: "<<e2.what();
    }
    
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <string>

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::list<std::pair<Boje,std::string>> ListaParova;
typedef std::pair<Boje,std::string> Par;
typedef std::multimap<Boje,std::string> MultiMapa;

std::vector<std::string> vs{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

void IspisiKarte(const ListaParova &lp){
    Boje b;
    for(int i(0);i<4;i++){
        if(i==0) {b=Boje::Pik; std::cout<<"Pik: ";}
        if(i==1) {b=Boje::Tref; std::cout<<"Tref: ";}
        if(i==2) {b=Boje::Herc; std::cout<<"Herc: ";}
        if(i==3) {b=Boje::Karo; std::cout<<"Karo: ";}
        for(auto it(lp.begin());it!=lp.end();it++)
            if(b==it->first) std::cout<<it->second<<" ";
        std::cout<<std::endl;    
    }    
}

bool ProvjeraSpila(ListaParova &lp){
    Boje b;
    int brojac(0);
    int index(-1);
  
    auto iterr(lp.end());
    lp.insert(iterr,par);
    for(int i(0);i<4;i++){
        
        std::vector<std::string> pom;
        if(i==0) {b=Boje::Pik; std::cout<<"Pik: ";}
        if(i==1) {b=Boje::Tref; std::cout<<"Tref: ";}
        if(i==2) {b=Boje::Herc; std::cout<<"Herc: ";}
        if(i==3) {b=Boje::Karo; std::cout<<"Karo: ";}
        for(auto it(lp.begin());it!=lp.end();it++){
           //  pom.push_back(lp(b)->second);
            brojac++;
        }
        index=-1;
        for(int j(0);j<pom.size();j++){
                for(int k(0);k<vs.size();k++){
                    if(vs[k]==pom[j]){
                    if(k<index) return false;
                    else index=k;
                }
            }
        }
    } 
    
    return true;
}

ListaParova KreirajSpil(){
    
    ListaParova lista_parova;
    Boje b;
    for(int j(0);j<4;j++){
        if(j==0) b=Boje::Pik;
        if(j==1) b=Boje::Tref;
        if(j==2) b=Boje::Herc;
        if(j==3) b=Boje::Karo;
        Par par;
        for(int i(0);i<vs.size();i++) {
            par=std::make_pair(b,vs[i]);
            lista_parova.push_back(par);
        }
    }
    
    return lista_parova;
}

void IzbaciKarteRazbrajanjem(ListaParova &lp, short int r, int b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Nesipravni elementi za izbacivanje!");
    
}

int main ()
{
   ListaParova lp(KreirajSpil());
   std::cout<<ProvjeraSpila(lp);
    return 0;
}

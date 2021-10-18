/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <list>

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> igraci,int broj_timova) {
    
    int broj_igraca=igraci.size();
    int brojac_timova=0;
    int korak=0; 
    int br_igraca=igraci.size();
    std::vector<std::set<std::string>> timovi;
    std::vector<int> clanovi_po_timu;
    timovi.resize(broj_timova);
 
    for(int i=0;i<broj_timova;i++) {
        int dodaj=br_igraca/broj_timova;
        clanovi_po_timu.push_back(dodaj);
        
    }
    
    for(int i=0;i<(broj_igraca%broj_timova);i++) {
        clanovi_po_timu[i]++;
    }
    
    
    korak=0;
    while (brojac_timova<broj_timova) {
        
        for(int j=0; j<clanovi_po_timu[brojac_timova];j++) {
            while(korak>=broj_igraca) {
                korak=korak-broj_igraca;
            }
            std::string ime=igraci[korak];
            timovi[brojac_timova].insert(ime);
           
            for(int i=korak;i<broj_igraca-1;i++) {
                igraci[i]=igraci[i+1];
            }
            
            broj_igraca--;
            korak=korak+ime.size()-1;
            
        }
        brojac_timova++;
    }
  
    return timovi;
}


int main (){
    
    int broj_djece,tim;
    std::string imena_djece;
    std::vector<std::set<std::string>> v;
    std::vector<std::string> v1;
    
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    
    std::cout<<"Unesite imena djece:";
    for (int i=0; i<broj_djece; i++) {
        do {
            std::cin >> imena_djece;
            v1.push_back(imena_djece);
        } while(imena_djece != ' ');
        
    }
    std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    std::cin>>tim;
    v=Razvrstavanje(v1,tim);
    for(int i=0;i<v.size();i++) {
        int j=0;
        for(std::string x: v[i] ) {
            if(j==0){
                std::cout<<"Tim "<<i+1<<": "<<x;
                j++;
            }
            else
            std::cout<<", "<<x;
        }
        std::cout<<std::endl;
    }
    
	return 0;
}
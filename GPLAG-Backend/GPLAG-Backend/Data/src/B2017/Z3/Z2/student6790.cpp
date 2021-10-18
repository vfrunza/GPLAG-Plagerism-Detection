/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <set>
#include <algorithm>
#include <utility>

typedef std::map<std::string,std::vector<std::string>> Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string,int,int>>> Mapa;

bool DaLiJeSlovoIliBroj(char znak) {
    if((znak>='a'&& znak<='z')||(znak>='A'&& znak<='Z')||(znak>='0'&& znak<='9'))
        return true;
    return false;
}

void KreirajIndeksPojmova (Knjiga k) {
    
    Mapa mapa;
    
    //Prolazak kroz poglavlja knjige
    for(auto it=k.begin();it!=k.end();it++) {
        
        std::string ime_poglavlja(it->first);
        
        //Prolazak kroz stranice jednog poglavlja
        for(int i(0);i<(it->second.size());i++) {

            //Prolazak kroz jednu stranicu(jedan el. vektora)
          // for(int j(0);j<(it->second[i].size());j++){
                auto pozicija(it->second[i].begin());
                int x(0);
                while(x<it->second[i].size()-1){
                    
           //         if(x==it->second[i].size()-1) break;
                    
                    auto pocetak=pozicija;
                    auto kraj=pocetak;

                    
                    if(!DaLiJeSlovoIliBroj(*pocetak)) {
                        pocetak++;
                        x++;
                    }
                
                    while((*kraj>='a'&& *kraj<='z')||(*kraj>='A'&& *kraj<='Z')||(*kraj>='0'&&*kraj<='9')) {
                   
                
                       kraj++;
                       x++;
                    }
                    
                 //   std::cout<<"Kr"<<*kraj;
                    
                    std::string rijec;
                    while(pocetak!=kraj) {
                    //    std::string slovo(*pocetak);
                        rijec+=*pocetak;
                        pocetak++;
                        
                    }
                    pozicija=pocetak;
                    pozicija++;
                    std::cout<<rijec<<std::endl; 
                 //   x++;
                 rijec.clear();
                }
          //  }
        }
        
        
    }
    
 //   return mapa;
}


int main () {
    
    Knjiga knjiga;
    
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string naziv_poglavlja;
        std::getline(std::cin,naziv_poglavlja);
        if(naziv_poglavlja==".") break;
        
        std::vector<std::string> v_stranicaa;
        
        for(int i(0);;i++) {
            std::cout<<"Unesite sadrzaj stranice "<<i+1<<":";
            std::string stranica;
            std::getline(std::cin,stranica);
            if(stranica==".") break;
            v_stranicaa.push_back(stranica);
        }
        
        std::pair<std::string,std::vector<std::string>> par;
        par.first=naziv_poglavlja;
        par.second=v_stranicaa;
        
        knjiga.insert(par);
    }
   
    KreirajIndeksPojmova(knjiga);
    
	return 0;
}

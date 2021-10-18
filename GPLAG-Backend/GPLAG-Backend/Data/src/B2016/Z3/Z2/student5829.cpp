/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <set>
#include <cstring>
#include <vector>
#include <cctype>

std::string Pretvori_u_mala (std::string s){
    std::string finalni;
    for(int i=0; i<s.size(); i++){
        finalni.push_back(tolower(s[i]));
    }
    return finalni;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    bool razmak(true);
    int pocetak;
    int kraj;
    for(int i=0; i<s.size(); i++){
        if (s[i]==' ' || s[i]=='"') razmak=true;
        else if (razmak==true){
            razmak=false;
            pocetak=i;
            while(s[i]!=' ' && s[i]!='"' && i<s.size()){
                i++;
            }
            kraj=i;
            i--;
            
            std::string rijec(s.substr(pocetak, kraj-pocetak));
            rijec=Pretvori_u_mala(rijec);
            
            auto it(mapa.find(rijec));
            if(it==mapa.end()) mapa.insert(std::make_pair(rijec, std::set<int> {pocetak}));
            else it->second.insert(pocetak);
        }
        
    }
    
    
  
    return mapa;
}
    
std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa){
    bool pronadjena(0);
    std::set<int> skup;
    rijec=Pretvori_u_mala(rijec);
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        if((it->first)==rijec) pronadjena = 1;
    }
    
    if (pronadjena==0) throw std::domain_error("Unesena rijec nije nadjena!");
    
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        if((it->first)==rijec) skup=it->second;;
    }
    return skup;
     
}



void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<< ": ";
        int max=*it->second.begin();
        for(int x: it->second){
            if(x>max) max=x;
        }
        
        for(int x: it->second){
            if(x!=max) std::cout<<x<<",";
            else std::cout<<x;
        }
        std::cout<<std::endl;
    }
}
    

int main ()
{
    std::set<int> skup;
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    
    std::getline(std::cin, tekst);
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst));
    
    std::string rijec;
    
    for(;;){
        
        std::cout<< "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try{
        
        skup=PretraziIndeksPojmova(rijec, KreirajIndeksPojmova(tekst));
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            std::cout<<std::endl;
            continue;
        }
        for (int x : skup) std::cout<<x<<" ";
        std::cout<<std::endl;
    }
 
	return 0;
}
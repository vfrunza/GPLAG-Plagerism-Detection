/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <set>

typedef std::map<std::string, std::vector<std::string>>Knjiga;
char maloslovo(char c){
    if(c>='A' && c<='Z'){
        return c+'a'-'A';
    }
    return c;
}
std::string malaslova(std::string a){
    
    std::string b;
    for(int i=0; i<a.size();i++)b.push_back(maloslovo(a[i]));
    return b;
}
bool JeLiSlovo(char c){
    
    return (c>='a' && c<='z') ||(c>='A' && c<='Z')||(c>='0' && c<='9');
    
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>>KreirajIndeksPojmova(Knjiga ime_objekta){
    std::string stranica;
    std::string rijec;
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> rezultat;
    
    for(auto it=ime_objekta.begin();it!=ime_objekta.end();it++){
        for(int i=0; i<(it->second).size();i++){
            
            stranica=(it->second)[i];
            int j=0;
            int pozicija;
            
            while(j<stranica.size()){
                pozicija=-1;
                rijec="";
                while(j<stranica.size() && JeLiSlovo(stranica[j])==false)j++;
                
                if(j<stranica.size())
                    pozicija=j;
              
                while(j<stranica.size() && JeLiSlovo(stranica[j])){
                    rijec.push_back(stranica[j]);
                    j++;
                }
                if(rijec.size()>0){
                    rijec=malaslova(rijec);
                    auto iter=rezultat.find(rijec);
                    if(rezultat.size()>0 && iter!=rezultat.end()){
                     auto skup=iter->second;
                     std::tuple<std::string, int, int> t;
                     t=std::make_tuple(it->first,i+1,pozicija);
                     skup.insert(t);
                     rezultat.erase(rijec);
                     rezultat.insert({rijec,skup});
                     
                        
                        
                    }else{
                      std::set<std::tuple<std::string, int, int>> a;
                      std::tuple<std::string, int, int> t;
                      t=std::make_tuple(it->first,i+1,pozicija);
                      a.insert(t);
                      rezultat.insert({rijec,a});
                    }
                }
                
            }
        }
        
    }
    
    
    
    return rezultat;
}
std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec,std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa){
    std::set<std::tuple<std::string, int, int>> rez;
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        if(it->first==rijec) {
            return it->second;
        }
    }
    throw std::logic_error ("Pojam nije nadjen");
    return rez;
}

void IspisiIneksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>>mapa) {
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<< it->first << ":";
        auto skup=it->second;
        int i=0;
        int brel=skup.size();
        for(auto it1=skup.begin(); it1!=skup.end(); it1++) {
            std::cout << " " << std::get <0> (*it1) <<  "/" << std::get<1> (*it1) << "/" << std::get<2> (*it1);
            if(i<brel-1)std::cout<<",";
            i++;
        }
        std::cout<< std:: endl;
        
    }
    
}
int main () {
    std::string naziv_poglavlja;
    Knjiga k;
    std::string s;
    while (1) {
        naziv_poglavlja="";
        std::cout<< "Unesite naziv poglavlja: ";
        std::getline(std::cin,naziv_poglavlja);
        
        if(naziv_poglavlja==".")break;
        std::vector<std::string> stranice;
        int i=1;
        while(1){
            s="";
           std::cout<<"Unesite sadrzaj stranice "<<i<<": "; 
           std::getline(std::cin,s);
           if(s!="." && s.size()>0){stranice.push_back(s);}
            if(s==".")break;
           i++;
        }
        k.insert({naziv_poglavlja,stranice});
    }
    std::cout<<std::endl<<"Kreirani indeks pojmova: "<<std::endl;
    auto ind=KreirajIndeksPojmova(k);
    IspisiIneksPojmova(ind);
    std::string rijec;
    while(1){
        std::cout<<"Unesite rijec: ";
        rijec="";
        std::getline(std::cin,rijec);
        if(rijec==".")break;
        try{
            auto p=PretraziIndeksPojmova(rijec,ind);
            for(auto it=p.begin();it!=p.end();it++)
                std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
        }catch(std::logic_error a){std::cout<<"Unesena rijec nije nadjena!";}
        
        std::cout<<std::endl;
        
    }
	return 0;
}

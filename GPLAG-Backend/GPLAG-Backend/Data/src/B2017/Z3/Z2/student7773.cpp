/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stdexcept>
#include <vector>
#include <tuple>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Mapa;

void PretvoriUMala(std::string &s) {
    
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
    }
    return;
}

Mapa KreirajIndeksPojmova(Knjiga k){
	Mapa indeks_pojmova;
	for(auto itr=k.begin(); itr!=k.end(); itr++){
	    std::string poglavlje(itr->first);
		std::vector<std::string> &v=itr->second;
		for(int i=0;i<v.size();i++){
		    int stranica(i+1);       //ili i+1?
		    std::string s=v[i];
		    for(int j=0; j<s.length();j++) {
               std::string rijec;
                int pozicija(j);
                while( (s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9') ) {
                   rijec.push_back(s[j]);
                   j++;
                }
            if(rijec.length()==0) continue;
            PretvoriUMala(rijec);
            auto it(indeks_pojmova.find(rijec));
            if(it==indeks_pojmova.end()) {
            std::set<std::tuple<std::string, int, int>> skup;
            skup.insert(std::make_tuple(poglavlje,stranica,pozicija));
            indeks_pojmova.insert(std::make_pair(rijec,skup));
            }
        
            else {
            (it->second).insert(std::make_tuple(poglavlje,stranica,pozicija));
            }
	
		}
		}
	}
		
		return indeks_pojmova;
		
	}
	
	std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, Mapa indeks_pojmova) {
    auto it(indeks_pojmova.find(rijec));
    if(it==indeks_pojmova.end())
        throw std::logic_error ("Pojam nije nadjen");
    else {
        return it->second;
    }
}

void IspisiIndeksPojmova(Mapa indeks_pojmova) {
    auto it(indeks_pojmova.begin());
    
    while(it!=indeks_pojmova.end()) {
        std::cout<<it->first<<": ";
        auto poc((it->second).begin());
         while(poc!=(it->second).end()){
             std::tuple<std::string, int, int> t=*poc;
             if((++poc)--==(it->second).end()) std::cout << std::get<0>(t) << "/" << std::get<1>(t)<<"/"<<std::get<2>(t);
             else std::cout << std::get<0>(t) << "/" << std::get<1>(t)<<"/"<<std::get<2>(t)<<", ";
             
             poc++;
         }
        std::cout<<std::endl;
        it++;
    }
  
}
	
	int main(){
	    Knjiga knjiga;
	    std::string poglavlje;
	    std::string sadrzaj;
	    std::vector<std::string> stranice;
	    for(;;){
	    std::cout<<"Unesite naziv poglavlja: ";
	    std::getline(std::cin, poglavlje);
	    if(poglavlje==".") break;
	    int i(1);
	    for(;;){
	        std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
	        std::getline(std::cin,sadrzaj);
	        if(sadrzaj==".") break;
	        stranice.push_back(sadrzaj);
	        i++;
	    }
	    knjiga.insert(std::make_pair(poglavlje,stranice));
	    }
	    Mapa indeks_pojmova=KreirajIndeksPojmova(knjiga);
	    std::cout<<"\nKreirani indeks pojmova:"<<std::endl;
	    IspisiIndeksPojmova(indeks_pojmova);
	    for(;;) {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") return 0;
        try {
            std::set<std::tuple<std::string, int, int>> skup(PretraziIndeksPojmova(rijec, indeks_pojmova));
            for(auto it=skup.begin(); it!=skup.end();it++){
            std::cout << std::get<0>(*it) << "/" << std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
            }
        }
        catch(...) {
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
        }
	    return 0;
	}
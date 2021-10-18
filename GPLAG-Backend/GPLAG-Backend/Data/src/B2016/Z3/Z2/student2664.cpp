/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>

std::map<std::string ,int > KreirajIndeksPojmova (std::string s){
    std::map<std::string , int > mapa_pojmova;
    std::string novi, pomocni;
    int i = 0 ; 
    int d = s.size();
    while ( i < d && s.at(i) != ' ') novi+= s.at(i++);
    while( i < d && s.at(i) != ' '){
        pomocni+=s.at(i++);
        mapa_pojmova.insert(std::make_pair(pomocni,i));
    }
    return mapa_pojmova;   
} 

std::set<int> PretraziIndeksPojmova (std::string rijeci , std::map<std::string,int> mapa_pozicija){
    int i = 0 ; 
    int d = rijeci.size();
    std::set<int> skup_indeksa;
    
    while(i < d && rijeci.at(i) != ' '){
        for( auto it = mapa_pozicija.begin(); it != mapa_pozicija.end(); it++){
            if(rijeci == it->first) skup_indeksa.insert(it->second);
            else throw std::logic_error("Pojam nije nadjen");
        }
    }
    
    return skup_indeksa;
}

void IspisiIndeksPojmova (std::map<std::string,int> mapa_pojmova){
    for(auto it = mapa_pojmova.begin(); it != mapa_pojmova.end(); it++){
        std::cout<<it->first<<": "<<it->second<<",";
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s ;
	std::getline(std::cin,s);
	std::map<std::string,int> mapa(KreirajIndeksPojmova(s));
	IspisiIndeksPojmova(mapa);
	for(auto it = mapa.begin(); it != mapa.end(); it++){
	    try{
	        std::cout<<it->first<<": "<<it->second<<" ";
	    } catch (std::logic_error){
	        std::cout<<"Unesena rijec nije nadjena!";
	    }
	    
	}
/*	auto it;
	do( it != mapa.end()){
	    std::cout<<"Unesite rijec: ";
	    IspisiIndeksPojmova(PretraziIndeksPojmova(mapa));
	    if(it == '.') break;
	    it++;
	}while ( it == '.');*/
	
	
	for(auto it = mapa.begin(); it != mapa.end(); it++){
	    if ( std::cout<<".") break;
	    else {
	        std::cout<<"Unesite rijec: \n";
	        std::set<int> noviskup (PretraziIndeksPojmova(s,mapa));
	        IspisiIndeksPojmova(mapa);
	    }
	}

	
	
	//std::map<std::string,int> mapa(KreirajIndeksPojmova(s,))
	//IspisiIndeksPojmova()
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <vector> 
#include <set>

std::map <std::string,std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map <std::string, std::set<int>> pomocna;
    
    std::string pom;
    
    for (int i=0; i<s.size();i++) {
        
        if(s[i]==' ')  {
            int pozicija;
            pozicija=i-pom.size();
            pomocna[pom].insert(pozicija);
            while (s[i]==' ') {
                i++;
            }
            if(i!=s.size())
            i--;
            pom="";
        }
        else {
            pom=pom+s[i];
            if(i==s.size()-1){
                int pozicija;
                pozicija=i-pom.size()+1;
                
                pomocna[pom].insert(pozicija);
            }
        }
    }
    return pomocna;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map <std::string,std::set<int>>mapa) {
    if(mapa[s].size()==0) {
        throw std::logic_error ("Unesena rijec nije nadjena!");
    }
    return mapa[s];
}

void IspisiIndeksPojmova(std::map <std::string,std::set<int>>mapa) {
    for (auto x: mapa) {
	    std::cout<<x.first<<": ";
	    int i=0;
	    for(int y: x.second){
    	    if(i==0){
    	        std::cout<<y;
    	        i++;
    	    }
    	    else std::cout<<","<<y;
	    }
	    std::cout<<std::endl;
	        
	}
}

int main () {
    
    std::map <std::string,std::set<int>> neka_mapa;
    std::string unos_rijeci;
    
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, unos_rijeci);
    
    neka_mapa=KreirajIndeksPojmova(unos_rijeci);
	for (auto x:neka_mapa) {
	    std::cout<<x.first<<": ";
	    int i=0;
	    for(int y: x.second){
    	    if(i==0){
    	        std::cout<<y;
    	        i++;
    	    }
    	    else std::cout<<","<<y;
	    }
	    std::cout<<std::endl;
	        
	}
	
	std::cout<<"Unesite rijec: ";
	std::string neka_rijec;
	std::cin>>neka_rijec;
	while (neka_rijec!=".") {
    	try{
        	std::set<int> v;
        	v=PretraziIndeksPojmova(neka_rijec, neka_mapa);
        	int i=0;
        	
        	for(int x: v){
        	    if(i==0){
        	        std::cout<<x;
        	        i++;
        	    }
        	    else{
        	        std::cout<<" "<<x;
        	    }
        	}
        }
        catch (std::logic_error g) {
            std::cout<<g.what ();
        }
        std::cout<<std::endl<<"Unesite rijec: ";
        std::cin>>neka_rijec;
	}
	return 0;
}
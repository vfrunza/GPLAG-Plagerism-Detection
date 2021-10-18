#include <iostream>
#include <string>
#include <iterator>
#include <set>
#include <map>
#include <utility>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> rez;
    for(auto it = s.begin(); it != s.end(); it++){
        auto it_pom1 = s.begin();
        auto it_pom2 = s.end();
        std::string rijec;
        int n,poc;
        if((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z') || (*it >= '0' && *it <= '9')){
            it_pom1 = it;
            for(auto i = it_pom1; i != s.end(); i++){
                if(!((*i >= 'a' && *i <= 'z') || (*i >= 'A' && *i <= 'Z') || (*i >= '0' && *i <= '9'))){
                    it_pom2 = i;
                    break;
                }
            }
            n = std::distance(it_pom1,it_pom2);
            poc = std::distance(s.begin(),it_pom1);
            rijec = s.substr(poc,n);
            if(rez.count(rijec) == 0){
                std::set<int> set1;
                set1.insert(std::distance(s.begin(),it_pom1));
                rez.insert(std::make_pair(rijec,set1));
            }
            else{
                auto it_lok = rez.find(rijec);
                (it_lok->second).insert(std::distance(s.begin(),it_pom1));
            }
            it_pom2--;
            it = it_pom2;
        }
    }
    return rez;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>> indeks){
    if(indeks.count(rijec) == 0) throw std::logic_error("Pojam nije nadjen");
    auto it = indeks.find(rijec);
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> indeks){
    for(auto it = indeks.begin(); it != indeks.end(); it++){
	    std::cout << it->first;
	    std::cout << ": ";
	    int n = (it->second).size();
	    int i(0);
	    for(auto x : it->second) {
	        i++;
	        std::cout << x;
	        if(i != n) std::cout << ",";
	    }
	    std::cout << std::endl;
	}
}

int main ()
{
    std::string tekst;
	std::cout << "Unesite tekst: ";
	std::getline(std::cin,tekst);
	std::map<std::string,std::set<int>> indeks = KreirajIndeksPojmova(tekst);
	IspisiIndeksPojmova(indeks);
	while(true){
	    std::string rijec;
	    std::cout << "Unesite rijec: ";
	    std::getline(std::cin,rijec);
	    if(rijec == ".") break;
	    try{
	        std::set<int> rez = PretraziIndeksPojmova(rijec,indeks);
	        int n = rez.size();
	        int i(0);
	        for(auto x : rez) {
	            i++;
	            std::cout << x;
	            if(i != n) std::cout << " ";
	        }
	        std::cout << std::endl;
	    }
	    catch(...){
	        std::cout << "Unesena rijec nije nadjena!" << std::endl;
	    }
	    
	}
	return 0;
}
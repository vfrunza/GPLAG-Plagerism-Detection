/B2016/2017: Zadaća 3, Zadatak 2.
#include <iostream>
#include <set>
#include <map>
#include <string>

void uMala(std::string &s) {
    for(auto i=s.begin(); i!=s.end(); i++)  if(*i<='Z' && *i>='A') *i+=32;
}

bool DioRijeci(char c) {
    if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) return true;
    return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>>M;
    for(auto i=s.begin(); i!=s.end(); ) {
        while(i!=s.end() && !DioRijeci(*i)) i++;
        std::string temp; int poz=i-s.begin();
        while(i!=s.end() && DioRijeci(*i)) temp+=*i++;
        uMala(temp);
        if(!temp.length()) break;
        M[temp].insert(poz);
    }
    return M;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>>M) {
    uMala(s);
    auto i=M.find(s);
    if(i==M.end()) throw std::logic_error("Pojam nije nadjen");
    return i->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>>M) {
    for(auto i=M.begin(); i!=M.end(); i++) {
        std::cout << i->first << ": ";
        int brojac=0;
        for(auto j=(i->second).begin(); j!=(i->second).end(); j++) {
            if(brojac+1==(i->second).size()) std::cout << *j;
            else std::cout << *j << ",";
            brojac++;
        }
        std::cout << "\n";
    }
}

int main () {
	std::cout << "Unesite tekst: ";
	std::string tekst;
	std::getline(std::cin, tekst);
	auto M=KreirajIndeksPojmova(tekst);
	IspisiIndeksPojmova(M);
	for(;;) {
	    std::cout << "Unesite rijec: ";
	    std::string temp;
	    std::getline(std::cin, temp);
	    if(temp==".") break;
	    uMala(temp);
	    try {
	        auto S=PretraziIndeksPojmova(temp, M);
	        for(auto i=S.begin(); i!=S.end(); i++) {
	            std::cout << *i << " ";
	        }
	        std::cout << "\n";
	    } 
	    catch(std::logic_error izuzetak) {
	        std::cout << "Unesena rijec nije nadjena!\n";
	    }
	}
	return 0;
}
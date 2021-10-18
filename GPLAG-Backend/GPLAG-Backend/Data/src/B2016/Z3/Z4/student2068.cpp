/B2016/2017: Zadaća 3, Zadatak 4.
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <stdexcept>

int broj_slova(std::string s) {
    int broj=0;
    for(auto c : s) if( (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') ) broj++;
    return broj;
}

int uKojiSet(int n, int k, int redni) {
    int broj_u_vecim=(n%k)*int(n/k+1);
    if(redni < broj_u_vecim ) {
        return redni/int(n/k+1);
    }
    else return (redni-broj_u_vecim)/(int(n/k))+n%k;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>v, int broj_timova) {
    if(broj_timova<1 || broj_timova>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string>L;
    for(auto s : v) L.push_back(s);
    
    std::vector<std::set<std::string>>krajnji(broj_timova);
    
    int brojac=0;
    for(auto i=L.begin(); ; brojac++) {
        krajnji[uKojiSet(v.size(), broj_timova, brojac)].insert(*i);
        int pomak=broj_slova(*i);
        i=L.erase(i); if(L.size()==0) break;
        if(i==L.end()) i=L.begin();
        for(int j=0; j<pomak-1; j++) {
            i++;
            if(i==L.end()) i=L.begin();
        }
    }
    return krajnji;
}

int main () {
	std::cout << "Unesite broj djece: ";
	int broj_djece; std::cin >> broj_djece;
	std::vector<std::string>v(broj_djece);
	std::cout << "Unesite imena djece: ";
	std::cin.ignore(10000, '\n');
	for(auto &s : v) std::getline(std::cin, s);
	std::cout << "\nUnesite broj timova: ";
	int broj_timova; std::cin >> broj_timova;
	try {
	    auto krajnji=Razvrstavanje(v, broj_timova);
	    for(int i=0; i<broj_timova; i++) {
	        std::cout << "Tim " << i+1 << ": ";
	        int velicina=krajnji[i].size(), k=0;
	        for(auto s : krajnji[i]) {
	            if(k==velicina-1) std::cout << s << "\n";
	            else std::cout << s << ", ";
	            k++;
	        }
	    }
	}
	catch(std::logic_error izuzetak) {
	    std::cout << "Izuzetak: " << izuzetak.what();
	}
	return 0;
}
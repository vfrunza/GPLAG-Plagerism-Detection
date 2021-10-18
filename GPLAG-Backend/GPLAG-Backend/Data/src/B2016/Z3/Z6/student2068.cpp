/B2016/2017: Zadaća 3, Zadatak 4.
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci=nullptr;
};

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
    
    std::shared_ptr<Dijete> prvi=nullptr, prethodni;
    
    for(int i=0; i<v.size(); i++) {
        std::shared_ptr<Dijete> novi(std::make_shared<Dijete>());
        novi->ime=v[i];
        if(!prvi) prvi=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    std::vector<std::set<std::string>>krajnji(broj_timova);
    
    if(!v.size()) return krajnji;
    prethodni->sljedeci=prvi;
    
    
    int brojac=0;
    std::shared_ptr<Dijete> trailing=prethodni;
    
    for(std::shared_ptr<Dijete> p=prvi; ; brojac++) {
        krajnji[uKojiSet(v.size(), broj_timova, brojac)].insert(p->ime);
        int pomak=broj_slova(p->ime);
        
        if(p==trailing) {
            trailing=nullptr;
            p->sljedeci=nullptr; p=nullptr;
            break;
        }
        
        p=p->sljedeci;
        trailing->sljedeci=p;
        
        for(int j=0; j<pomak-1; j++) {
            p=p->sljedeci;
            trailing=trailing->sljedeci;
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
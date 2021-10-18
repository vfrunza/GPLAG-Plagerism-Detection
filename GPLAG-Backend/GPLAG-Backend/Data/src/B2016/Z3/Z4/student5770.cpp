#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

typedef std::vector<std::set<std::string>> VektorSet;

int Korak(std::string s){
    int rez(0);
    for(auto it = s.begin(); it != s.end(); it++){
        if((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z') || (*it >= '0' && *it <= '9')){
            rez++;
        }
    }
    return rez;
}

VektorSet Razvrstavanje(std::vector<std::string> imena, int broj_ekipa){
    if(broj_ekipa < 1 || broj_ekipa > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n = imena.size() % broj_ekipa;
    int vel = imena.size() / broj_ekipa;
    VektorSet rezultat;
    std::list<std::string> lista;
    for(auto x : imena) lista.push_back(x);
    auto it = lista.begin();
    auto it_pom = lista.begin();
    std::set<std::string> grupa;
    int korak;
    while(it != lista.end() && lista.size() != 0){
        if(it == it_pom){
            grupa.insert(*it);
            if(grupa.size() == (vel + (n > 0))){
                rezultat.push_back(grupa);
                n--;
                grupa.clear();
            }
            korak = Korak(*it);
            lista.erase(it);
            it_pom = it;
            for(int i = 0; i < korak; i++){
                it_pom++;
                if(it_pom == lista.end()) it_pom = lista.begin();
            }
        }
        it++;
        if(it == lista.end()) it = lista.begin();
    }
    if(grupa.size() != 0) rezultat.push_back(grupa);
    return rezultat;
}

int main ()
{
	int broj_djece,broj_ekipa;
	std::string ime;
	std::vector<std::string> imena;
	std::cout << "Unesite broj djece: ";
	std::cin >> broj_djece;
	std::cout << "Unesite imena djece:" << std::endl;
	std::cin.ignore(10000,'\n');
	for(int i = 0; i < broj_djece; i++){
	    std::getline(std::cin,ime);
	    imena.push_back(ime);
	}
	std::cout << "Unesite broj timova: ";
	std::cin >> broj_ekipa;
	try{
    	VektorSet rezultat = Razvrstavanje(imena,broj_ekipa);
    	for(int i = 0; i < rezultat.size(); i++){
    	    std::cout << "Tim " << i+1 << ": ";
    	    std::set<std::string> skup = rezultat[i];
    	    int m(0);
    	    for(auto x : skup) {
    	        std::cout << x;
    	        if(m != skup.size() - 1) std::cout << ", ";
    	        m++;
    	    }
    	    std::cout << std::endl;
    	}
	}
	catch(std::exception &e){
	    std::cout << e.what();
	}
	return 0;
}
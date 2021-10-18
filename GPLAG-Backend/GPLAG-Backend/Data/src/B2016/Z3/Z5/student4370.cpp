#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

typedef std::vector<std::set<std::string>> VektorSet;

struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

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
    Dijete *pocetak(nullptr) , *trenutni , *predhodni(nullptr) ;
    for (int i = 0; i < imena.size(); i++) {
        trenutni = new Dijete ;
        trenutni->ime = imena[i] ;
        if ( pocetak == nullptr ) {
            pocetak = trenutni ;
            predhodni = trenutni ;
        }
        else {
            predhodni->sljedeci = trenutni ;
            predhodni = trenutni;
        }
    }
    trenutni->sljedeci = pocetak;
    std::set<std::string> grupa;
    int korak(0);
    int br(0) ;
    int velicina(imena.size());
    for (Dijete *p = pocetak ; velicina != 0 ; p = p->sljedeci ) {
        br++;
        if(br == 1 && velicina == imena.size()){
            Dijete *temp = p;
            trenutni->sljedeci = p->sljedeci;
            grupa.insert(p->ime);
            if(grupa.size() == (vel + (n > 0))){
                rezultat.push_back(grupa);
                n--;
                grupa.clear();
            }
            korak = Korak(p->ime);
            velicina--;
            br = 0;
            delete temp;
        }
        if (br == korak - 1) {
            Dijete *temp = p->sljedeci;
            p->sljedeci = (p->sljedeci)->sljedeci;
            grupa.insert(temp->ime);
            if(grupa.size() == (vel + (n != 0))){
                rezultat.push_back(grupa);
                n--;
                grupa.clear();
            }
            korak = Korak(temp->ime);
            velicina--;
            delete temp ;
            br = 0;
        }
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
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

int BrojacSlova(std::string s){
    int brojac(0);
    for(int i=0; i<s.length(); i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) brojac++;
    }
    return brojac;
}

std::vector<int> Timovi(int broj_djece, int broj_timova){
    if(broj_timova < 1 || broj_timova > broj_djece) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<int> v;
    v.resize(broj_timova);
    for(int i=0; i<v.size(); i++) v[i]=broj_djece/broj_timova;
    int ostatak = broj_djece - (broj_djece/broj_timova)*broj_timova;
    int i(0);
    while(ostatak != 0){
        v[i]++;
        ostatak--;
        i++;
    }
    return v;
}

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::shared_ptr<Dijete> NapraviListu(std::vector<std::string> v, std::shared_ptr<Dijete> &prethodni){
    std::shared_ptr<Dijete> pocetak(nullptr);
    for(int i=0; i<v.size(); i++){
        Dijete a;
        auto novo(std::make_shared<Dijete> (a));
        novo->ime = v[i]; novo->sljedeci = nullptr;
        if(!pocetak) pocetak = novo;
        else prethodni->sljedeci = novo;
        prethodni = novo;
    }
    prethodni->sljedeci = pocetak;
    return pocetak;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int broj){
    auto timovi(Timovi(v.size(), broj));
    std::shared_ptr<Dijete> prethodni;
    auto trenutni(NapraviListu(v,prethodni));
    std::vector<std::set<std::string>> rez;
    rez.resize(broj);
    for(int i=0; i<rez.size(); i++){
        for(int j=0; j<timovi[i]; j++){
            int br(BrojacSlova(trenutni->ime));
            rez[i].insert(trenutni->ime);
            prethodni->sljedeci=trenutni->sljedeci;
            trenutni = nullptr;
            trenutni = prethodni->sljedeci;
            for(int k=0; k<br-1; k++){
                trenutni = trenutni->sljedeci;
                prethodni = prethodni->sljedeci;
            }
        }
    }
    trenutni->sljedeci=nullptr;
    //trenutni = nullptr; prethodni = nullptr;
    return rez;
}

void IspisiLijepo(std::vector<std::set<std::string>> v){
    for(int i=0; i<v.size(); i++){
        std::cout << "Tim " << i+1 << ": ";
        auto it(v[i].begin());
        while(it != v[i].end()){
            if(v[i].size()==1){
                std::cout << *it;
                break;
            }
            std::cout << *it << ", ";
            it=v[i].erase(it);
        }
        std::cout << std::endl;
    }
}

int main ()
{
	std::vector<std::string> v;
	int broj_djece;
	std::cout << "Unesite broj djece: " ;
	std::cin >> broj_djece;
	std::cout << "Unesite imena djece: " << std::endl;
	std::string ime;
	std::cin >> std::ws;
	for(int i=0; i<broj_djece; i++){
	    std::cin >> std::ws;
	    std::getline(std::cin, ime);
	    v.push_back(ime);
	}
	int broj_timova;
	std::cout << "Unesite broj timova: " ;
	std::cin >> broj_timova;
	try{
	    auto rezultat(Razvrstavanje(v,broj_timova));
	    IspisiLijepo(rezultat);
	}
	catch(std::logic_error e){
	    std::cout <<"Izuzetak: "<< e.what() << std::endl;
	}
	return 0;
}
//Damir, Ana, Muhamed, Marko, Ivan, Mirsad, Nikolina, Alen, Jasmina i Merima
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <list>
#include <set>

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
    while(ostatak!=0){
        v[i]++;
        ostatak--;
        i++;
    }
    return v;
}

std::list<std::string> PrebaciUListu(std::vector<std::string> &v){
    std::list<std::string> lista;
    for(int i=0; i<v.size(); i++) lista.push_back(v[i]);
    return lista;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int broj){
    auto timovi(Timovi(v.size(), broj));
    auto lista(PrebaciUListu(v));
    auto it(lista.begin());
    std::vector<std::set<std::string>> rez;
    rez.resize(broj);
    for(int i=0; i<rez.size(); i++){
        for(int j=0; j<timovi[i]; j++){
            int br(BrojacSlova(*it));
            rez[i].insert(*it);
            it=lista.erase(it);
            for(int k=0; k<br-1; k++){
                if(it==lista.end()) it=lista.begin();
                it++;
            }
            if(it==lista.end()) it=lista.begin();
        }
    }
    return rez;
}

void IspisiLijepo(std::vector<std::set<std::string>> v){
    for(int i=0; i<v.size(); i++){
        std::cout << "Tim " << i+1 << ": "; 
	    auto it(v[i].begin());
	    while(it != v[i].end()){
	        if(v[i].size() == 1){ 
	            std::cout << *it; 
	            break;
	        }
	        std::cout<< *it << ", ";
	        it=v[i].erase(it);
	    }
	    std::cout<< std::endl;
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
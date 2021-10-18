/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>

int duzina_imena(std::string ime){
    int brojac(0);
    for(int i=0; i<ime.size(); i++){
        if((ime[i] >= '0' && ime[i] <= '9') || (ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <= 'Z'))
            brojac++;
        
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Imena_djece, int broj_timova){
    
    if(broj_timova < 2 || broj_timova > Imena_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> rezon;
    
    std::list<std::string> pomocna_lista;
    int velicina_pomocne_liste = Imena_djece.size();
    for(int i=0; i<Imena_djece.size(); i++)
        pomocna_lista.push_back(Imena_djece[i]);
    
    
    int j=0;
    auto it(pomocna_lista.begin());
    
    for(int i=0; i<broj_timova; i++){
        while( j < velicina_pomocne_liste%broj_timova){
         rezon[i].insert(*it);
         j++;   
        }
    }
    
    return rezon;
}

int main (){
    
    std::cout << "Unesite broj djece: ";
    int broj_djece;
    std::cin >> broj_djece;
    
    std::cout << "Unesite imena djece: ";
    std::string ime;
    std::vector < std::string> Imena_djece;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    for(int i=0; i<broj_djece; i++){
        std::getline(std::cin, ime);
        Imena_djece.push_back(ime);
    }
    
    std::cout << "Unesite broj timova: ";
    int broj_timova;
    std::cin >> broj_timova;
    
    try{
        std::vector<std::set<std::string>> Razvrstani;
        Razvrstani = Razvrstavanje(Imena_djece, broj_timova);
        for(int i=0; i<Razvrstani.size(); i++){
            std::cout << "Tim " << i+1 << ": ";
            for(auto it = Razvrstani[i].begin(); it != Razvrstani[i].end(); it++){
                if(it == prev(Razvrstani[i].end())) std::cout << *it;
                std::cout << *it << ", ";
            }
        }
    }
    
    catch(std::logic_error e){
        std::cout << "Izuzetak:" << e.what();
    }
	return 0;
}
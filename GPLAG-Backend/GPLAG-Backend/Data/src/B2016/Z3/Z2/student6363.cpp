/B2016/2017: Zadaća 3, Zadatak 2

#include <iostream>
#include<string>
#include<set>
#include<stdexcept>
#include<algorithm>
#include<map>

void DodajPar(std::map<std::string, std::set<int>> &pojmovi,std::string &pojam, int pozicija){
    if(pojam.begin() == pojam.end()) return;
    std::map<std::string, std::set<int>>::iterator it;
    if((it = pojmovi.find(pojam))!= pojmovi.end()) pojmovi[pojam].insert(pozicija);
    else pojmovi.insert(std::make_pair(pojam, std::set<int>{pozicija}));
}


std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s){
    std::map<std::string, std::set<int>> retvalue;
    std::string temp;
    int velicina{0}, obrisano{0};
    while((velicina = s.find_first_of(" ,.()/;:")) != std::string::npos){
        temp = s.substr(0, velicina);
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        s.erase(0, velicina+1);
        DodajPar(retvalue, temp, obrisano);
        obrisano += velicina+1;
    }
    DodajPar(retvalue, s, obrisano);
    return retvalue;
}

std::set<int> PretraziIndeksPojmova(std::string pojam, std::map<std::string, std::set<int>> pojmovi) {
    std::transform(pojam.begin(), pojam.end(), pojam.begin(), ::tolower);
    std::map<std::string, std::set<int>>::iterator it;
    if((it = pojmovi.find(pojam))!=pojmovi.end()) return pojmovi[pojam];
    else throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova( std::map<std::string,  std::set<int>> pojmovi) {
    for(auto it = pojmovi.begin(); it != pojmovi.end(); it++){
        std::cout << it->first<<": ";
        for(int x : it->second){
                std::cout << x;
                if(x!= *(it->second.rbegin())) std::cout<<",";
            }
        std::cout<<std::endl;
    }
}

int main ()
{
    
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    std::string pojam{"temp"};
    while(true){
        std::cout<<"Unesite rijec: ";
        std::cin>>pojam;
        if(pojam==".") return 0;
        try{
            std::set<int> rezultat(PretraziIndeksPojmova(pojam, mapa));
            for(int x : rezultat){
                std::cout << x;
                if(x!= *(rezultat.rbegin())) std::cout<<" ";
            }
            std::cout<<std::endl;
        }
        catch(std::exception e) {std::cout<<"Unesena rijec nije nadjena!" <<std::endl;}
        
    }
	return 0;
}
/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::vector<std::tuple<std::string, int, int>>> KreirajIndeksPojmova (Knjiga objekat){
    auto it=objekat.begin();
    auto nazivpoglavlja = it->first;
    auto vektorstringova = it->second;
    //auto 
    std::vector<std::string> unikati;
    for(int i = 0; i < vektorstringova.size(); i++){
    auto pocetak = vektorstringova[i].begin();
    auto kraj = vektorstringova[i].begin();
    }
}

//PretraziIndeksPojmova(string rijec)

int main ()
{
    Knjiga prvopoglavlje;
    std::vector<std::string> vektorstringova;
    std::string nazivpoglavlja, sadrzajstranice;
    std::cout << "Unesite naziv poglavlja: ";
    std::cin >> nazivpoglavlja;
    //prvopoglavlje(nazivpoglavlja);
    for(int i = 0;; i++){
        std::cout << "Unesite sadrzaj stranice " << i+1 << ": ";
        std::cin >> sadrzajstranice;
        vektorstringova.push_back(sadrzajstranice);
        //prvopoglavlje(nazivpoglavlja).push_back(sadrzajstranice);
    //    prvopoglavlje.insert(nazivpoglavlja, vektorstringova);
        if(sadrzajstranice==".") break;
        sadrzajstranice.clear();
    }
    prvopoglavlje.insert(std::pair<std::string, std::vector<std::string>>(nazivpoglavlja, vektorstringova));
    KreirajIndeksPojmova(prvopoglavlje);
	return 0;
}

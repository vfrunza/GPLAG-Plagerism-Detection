/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <math.h>
#include <string>
#include<map>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool PotencijalnaRijec (char c)
{
    c = std::tolower(c);
    if (c>='a' && c<= 'z') return true;
    else if(c >= '0' && c<='9') return true;
    else return false;

}

std::map<std::string, std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova (Knjiga roman)
{

    std::map<std::string, std::set<std::tuple<std::string,int,int>>> IndeksPojmova;
    std::tuple<std::string,int,int> tupl;
    std::set<std::tuple<std::string,int,int>> set_umrli;
    std::string mecanje;

    for(auto it = roman.begin(); it != roman.end(); it++) {
        if (it->first == " ") continue;
        auto stranice =  it->second;
        int brojstranica = stranice.size();

        for (int i = 0; i < brojstranica; i++) {

            std::string temp;

            std::string sadrzaj;
            int indeks(0);
            for (int j = 0; j < stranice[i].size(); j++) {
                temp = stranice[i];
                std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                if (temp[j] == ' ') continue;
                std::string pomocni;
                indeks = j;
                while ((PotencijalnaRijec(temp[j])) && j<temp.length()) {
                    pomocni += temp[j];
                    j++;
                }
                mecanje = pomocni;
                if (!IndeksPojmova.count(mecanje)) {
                    int broj,lokacija;
                    std::string ime_poglavlja;
                    ime_poglavlja = it->first;
                    broj = i+1;
                    tupl = (std::tie(ime_poglavlja,broj,indeks));
                    set_umrli.insert(tupl);
                    std::set<std::tuple<std::string,int,int>> *pomoc = &IndeksPojmova[mecanje];
                    pomoc->insert(tupl);
                } else {
                    int broj, lokacija;
                    std::string ime_poglavlja;
                    ime_poglavlja = it->first;
                    broj = i+1;
                    tupl = (std::tie(ime_poglavlja,broj,indeks));
                    std::set<std::tuple<std::string,int,int>> *pomoc = &IndeksPojmova[mecanje];
                    pomoc->insert(tupl);
                }
            }
        }
    }
    return IndeksPojmova;
}


void IspisiIndeksPojmova (std::map<std::string, std::set<std::tuple<std::string,int,int>>> IndeksPojmova )
{

    for (auto it (IndeksPojmova.begin()); it != IndeksPojmova.end(); it++) {
        std::cout << it->first << ": ";
        int brojac = it->second.size();
        for (auto x: it->second) {

            if (brojac != 1)
                std::cout << std::get<0>(x) << "/" << std::get<1>(x) << "/" << std::get<2>(x) << ", ";
            else
                std::cout << std::get<0>(x) << "/" << std::get<1>(x) << "/" << std::get<2>(x);
            brojac--;

        }

        std::cout << std::endl;
    }

}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<std::tuple<std::string,int,int>>> IndeksPojmova)
{
    if (IndeksPojmova.find(rijec)==IndeksPojmova.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    return IndeksPojmova.find(rijec)->second;

}


int main ()

{
    std::map<std::string, std::set<std::tuple<std::string,int,int>>> IndexPojmova;
    Knjiga heripoter;
    while (1) {
        std::cout << "Unesite naziv poglavlja: ";
        std::string stringy;
        std::getline(std::cin,stringy);
        std::vector<std::string> temp;

        if (stringy == ".") break;
        int i(1);
        while (1) {

            std::cout << "Unesite sadrzaj stranice " << i <<": " ;
            std::string stringy2;
            std::getline(std::cin,stringy2);
            if (stringy2==".") break;
            temp.push_back(stringy2);
            i++;
        }
        heripoter.insert(std::make_pair(stringy,temp));
    }

    IndexPojmova=KreirajIndeksPojmova(heripoter);
    std::cout << "\nKreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(IndexPojmova);

    while (1) {

        std::cout << "Unesite rijec: ";
        std::string stringy1;
        std::getline(std::cin,stringy1);

        if (stringy1==".") break;

        try {
            std::set<std::tuple<std::string,int,int>> ispisni;
            ispisni = PretraziIndeksPojmova(stringy1, IndexPojmova);
            int brojac(ispisni.size());

            for (auto x: ispisni) {

                if (brojac != 1)
                    std::cout << std::get<0>(x) << "/" << std::get<1>(x) << "/" << std::get<2>(x) << " ";
                else
                    std::cout << std::get<0>(x) << "/" << std::get<1>(x) << "/" << std::get<2>(x) << " ";
                brojac--;

            }
            std::cout << std::endl;

        } catch (const std::logic_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}

/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>
typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::tuple<std::string,int,int> Pridruzeni_el;

//KreirajIndeksPojmova
std::map<std::string,std::set<Pridruzeni_el>> KreirajIndeksPojmova(Knjiga k){
    std::map<std::string,std::set<Pridruzeni_el>> mapa;
    return mapa;
}

//PretraziIndeksPojmova
std::set<Pridruzeni_el> PretraziIndeksPojmova(const std::string &s, std::map<std::string, std::set<Pridruzeni_el>> mapa){
    auto p(mapa.find(s));
    if(p==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    return p->second;
}

int main ()
{
	return 0;
}

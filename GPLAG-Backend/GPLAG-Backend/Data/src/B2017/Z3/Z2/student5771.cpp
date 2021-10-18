/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <set>
typedef std::map<std::string, std::vector<std:: string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> MapaIndexPojmova;
typedef std::set<std::tuple<std::string, int, int>> SkupPozicijaRijeci;
//MapaIndexPojmova KreirajIndeksPojmova(Knjiga tekst){
    
//}
SkupPozicijaRijeci PretraziIndeksPojmova(std::string s, MapaIndexPojmova mapa){
    SkupPozicijaRijeci skup;
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else skup.insert(it->second);
    return skup;
}

void IspisiIndeksPojmova(MapaIndexPojmova mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout<<it->first<<": ";
        auto skup(PretraziIndeksPojmova(it->first, mapa));
        for(auto it1=skup.begin();it1!=skup.end();it1++){
            std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"std::get<2>(*it);
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite naziv poglavlja: ";
    std::string poglavlje;
    std::cin>>poglavlje;
    std::cout<<"Unesite sadrzaj stranice 1: ";
    std::string stranica1;
    std::cout<<"Unesite naziv poglavlja: ";
    std::string naziv_poglavlja;
    std::cin>>naziv_poglavlja;
    IspisiIndeksPojmova(KreirajIndeksPojmova)
	return 0;
}

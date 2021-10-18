/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <vector>
typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> MapaPojmova;
MapaPojmova KreirajIndeksPojmova(Knjiga mapa){
    MapaPojmova mapa_pojmova;
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::set<std::tuple<std::string,int, int>> skup;
        auto v(it->second);
        for(int i=0; i<v.size(); i++){
            std::string s(v.at(i));
            for(int j=0; j<v.at(i).size(); j++) s[j]=std::tolower(s[j]);
            for(int j=0; j<s.size(); j++){
                int l=j+1; 
                if(s[j]=='\\' && s[l]=='n')s.replace(j,2,"@");
            }
            for(int j=0; j<s.size(); j++){
                std::string tekst;
                int k=0;
                std::tuple<std::string, int, int> ntorka;
                while(j!=s.length() && (s[j]<'0' || (s[j]>'9' && s[j]<'A') || (s[j]>'Z'&& s[j]<'a') || s[j]>'z')){
                    //U slučaju da ne bude dobro tj da padada vise autotestova probati
                    //if(s[j]=='\\') s.erase(j,1);
                    j++;
                }
                while(j!=s.length() && ((s[j]>='0' && s[j]<='9') || ( s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z'))){
                    tekst+=s[j];
                    j++;
                    k++;
                }
            if(tekst=="") break;
            ntorka=std::make_tuple(it->first,i+1,j-k);
            skup.insert(ntorka);
            mapa_pojmova[tekst].insert(ntorka);
            mapa_pojmova.insert(std::make_pair(tekst,skup));
            }
            
        }
    }
    
    return mapa_pojmova;
}
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec, MapaPojmova mapa_pojmova){
    std::set<std::tuple<std::string,int,int>> skup;
    std::string pom(rijec);
    for(int i=0; i<pom.length(); i++) pom[i]=std::tolower(pom[i]);
    if(!mapa_pojmova.count(pom)) throw std::logic_error("Pojam nije nadjen!");
    if(mapa_pojmova.count(pom)) skup=mapa_pojmova[pom];
    return skup;
}
void izlaz(std::tuple<std::string, int, int> ntorka){
    std::cout<<std::get<0>(ntorka)<<"/"<<std::get<1>(ntorka)<<"/"<<std::get<2>(ntorka)<<", ";
}
void izlaz1(std::tuple<std::string, int, int> ntorka){
    std::cout<<std::get<0>(ntorka)<<"/"<<std::get<1>(ntorka)<<"/"<<std::get<2>(ntorka)<<" ";
}
void IspisiIndeksPojmova(MapaPojmova mapa_pojmova){
    for(auto it=mapa_pojmova.begin(); it!=mapa_pojmova.end(); it++){
        std::cout<<it->first<<": ";
        if((*it).second.begin()==(*it).second.end()){
            std::cout<<std::endl;
            continue;
        }
        std::for_each((*it).second.begin(), (--(*it).second.end()), izlaz);
        std::for_each(--(it->second).end(), (it->second).end(), izlaz1);
        std::cout<<std::endl;
    }
}
int main ()
{
    //try{
    Knjiga knjiga;
    for(;;){
        int broj=0;
        std::string naziv_poglavlja;
        std::vector<std::string> vektor;
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin, naziv_poglavlja);
        if(naziv_poglavlja==".") break;
        for(;;){
            broj++;
            std::string sadrzaj_prve_stranice;
            std::cout<<"Unesite sadrzaj stranice "<<broj<<": ";
            std::getline(std::cin, sadrzaj_prve_stranice);
            if(sadrzaj_prve_stranice==".") break;
            if(sadrzaj_prve_stranice!=".")vektor.push_back(sadrzaj_prve_stranice);
            
        }
        knjiga.insert(std::make_pair(naziv_poglavlja,vektor));
    }
    std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova: "<<std::endl;
    //knjiga.insert({"I",{{"abc qwe stsda abc abc dhi qwe hrkw dhi"}}});
    auto pojmovi=KreirajIndeksPojmova(knjiga);
    IspisiIndeksPojmova(pojmovi);
    for(;;){
    try{
    std::string rijec;
    std::cout<<"Unesite rijec: ";
    std::getline(std::cin, rijec);
    if(rijec==".") break;
    auto skup=PretraziIndeksPojmova(rijec, pojmovi);
    for(auto it=skup.begin(); it!=skup.end(); it++){
        std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
    }
    std::cout<<std::endl;
    
    }catch(std::logic_error Izuzetak){
        std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
    }
    }
	return 0;
}

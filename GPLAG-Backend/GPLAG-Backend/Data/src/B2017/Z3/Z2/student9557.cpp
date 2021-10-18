/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tuple>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int , int>>> IndeksPojmova;

bool Slovo (char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

std::vector<std::string> IzdvojiRijeci (std::string s)
{
    std::vector<std::string> v;
    std::string pomocni;
    int i(0);
    while (i < s.length()) {
        while(Slovo(s.at(i))) {
            pomocni.push_back(s.at(i));
            i++;
        }
        v.push_back(pomocni);
        pomocni.resize(0);
        i++;
    }
    return v;
}

std::vector<int> IndeksRijeci (std::string s)
{
    std::vector<int> v;
    v.push_back(0);
    int i(1);
    while (i < s.length()) {
        if(Slovo(s.at(i)) && !Slovo(s.at(i-1))) v.push_back(i);
        i++;
    }
    return v;
}

IndeksPojmova KreirajIndeksPojmova(Knjiga k){
    IndeksPojmova index;
    std::string poglavlje = k.begin()->first;
    for(auto it=k.begin(); it!=k.end(); it++){
    std::vector<std::string> stranice=IzdvojiRijeci(it.second);
    
    for(int i=0; i<stranice.size(); i++){
    std::string pomocni = stranice[i];
    for(int j=0; j < pomocni.size(); j++){
        int indeks = IndeksRijeci(pomocni.at(j));
        auto ubaci = std::make_tuple(poglavlje, i, indeks);
        index[pomocni].insert(ubaci);
    }
    }
    return index;
}

void IspisiIndeksPojmova(IndeksPojmova index){
    for(auto it:index){
        std::cout << it.first << ": ";
        int br, vel;
        br=0; vel= std::distance(it.second.begin(),it.second.end());
        for(auto i: it.second){
            br++;
            if(br==vel) std::cout << std::get<0>(i) << "/" << std::get<1>(i) << "/" << std::get<2>(i);
            else std::cout << std::get<0>(i) << "/" << std::get<1>(i) << "/" << std::get<2>(i) << ", ";
        }
        std::cout << std::endl;
    }
}

/*
IndeksPojmova KreirajIndeksPojmova (Knjiga k)
{
    IndeksPojmova index;
    std::string naziv_poglavlja;
    int broj_stranice, pocetak_rijeci;
    std::tuple<std::string, int, int> indeksacija;
  //  auto it=k.begin();
    naziv_poglavlja = (k.begin())->first;
    std::vector<std::string>v;
    for(auto i = 0; i<(k.begin()->second).size(); i++) {
        v = IzdvojiRijeci((k.begin()->second)[i]);
    }
    
    auto indeks_rijeci = IndeksRijeci(k.begin()->first);
    for(int i=0; i<(k.begin()->second).size(); i++) {
        for(int j=0; j<v.size(); j++) {
            broj_stranice = i+1;
            pocetak_rijeci=indeks_rijeci[j];
            indeksacija = std::make_tuple(naziv_poglavlja, broj_stranice, pocetak_rijeci);
            index[v.at(j)].insert(indeksacija);
        }
    }
    return index;
}

void IspisiIndeksPojmova(IndeksPojmova index){
    for(auto it: index){
        std::cout << it.first << ": ";
        for(auto it1: it.second){
           std::cout << std::get<0>(it1) << "/" << std::get<1>(it1) << "/" << std::get<2>(it1) << std::endl; 
        }
    }
}
*/

int main()
{
    Knjiga k;
    k.insert({"I", {"abc  qwe ert abc"}});
    IspisiIndeksPojmova(KreirajIndeksPojmova(k));
    return 0;
}
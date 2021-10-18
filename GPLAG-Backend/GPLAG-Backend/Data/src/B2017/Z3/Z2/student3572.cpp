/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <set>
#include <utility>
#include <stdexcept>
#include <cctype>
typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks_pojmova;
typedef std::set<std::tuple<std::string,int,int>> pozicije;

indeks_pojmova KreirajIndeksPojmova(Knjiga &knjiga){
    indeks_pojmova pojmovi;
    for(auto it=knjiga.begin();it!=knjiga.end();it++){
        for(int i=0;i<it->second.size();i++){
            for(int j=0;j<it->second[i].size();j++){
                while(!std::isalnum(it->second[i][j])&&j!=it->second[i].size())j++;
                int indeks(j);
                std::string pojam;
                while(std::isalnum(it->second[i][j])&&j!=it->second[i].size()){
                    pojam.push_back(std::tolower(it->second[i][j]));
                    j++;
                }
                auto t(std::make_tuple(it->first,i+1,indeks));
                pojmovi[pojam].insert(t);
            
        }
    }
    
}
return pojmovi;
}

pozicije PretraziIndeksPojmova(std::string rijec, indeks_pojmova pojmovi){
    if(!pojmovi.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    else return pojmovi[rijec];
}

void IspisiIndeksPojmova(const indeks_pojmova &pojmovi){
    for(auto it=pojmovi.begin();it!=pojmovi.end();it++){
        std::cout<<it->first<<": ";
        for(auto i=it->second.begin();i!=it->second.end();i++)
        {std::cout<<std::get<0>(*i)<<"/"<<std::get<1>(*i)<<"/"<<std::get<2>(*i); if(i!=--it->second.end()) std::cout<<", ";}
        std::cout<<std::endl;
    }
}

int main ()
{
    /*Knjiga a;
    std::vector<std::string> k {"abc qwe stsda abc abc dhi qwe hrkw dhi ab/123 A12 a12"};
    a.insert(std::make_pair("I",k));
    indeks_pojmova b(KreirajIndeksPojmova(a));
    IspisiIndeksPojmova(b);*/
    Knjiga knjiga;
    for(;;){
    std::cout<<"Unesite naziv poglavlja: ";
    std::string poglavlje;
    std::cin>>poglavlje;
    if(poglavlje==".") break;
    std::cin.ignore(10000,'\n');
    std::vector<std::string> stranice;
    int brojac{1};
    for(;;){
        std::cout<<"Unesite sadrzaj stranice "<<brojac<<": ";
        brojac++;
        std::string stranica;
        std::getline(std::cin, stranica);
        if(stranica==".") break;
        stranice.push_back(stranica);
        }
        knjiga.insert(std::make_pair(poglavlje,stranice));
    }
    indeks_pojmova b(KreirajIndeksPojmova(knjiga));
    std::cout<<std::endl<<"Kreirani indeks pojmova: "<<std::endl;
    IspisiIndeksPojmova(b);
    for(;;){
        std::cout<<std::endl<<"Unesite rijec: ";
        std::string rijec;
        std::cin>>rijec;
        if(rijec==".")break;
        std::cin.ignore(10000,'\n');
        if(!b.count(rijec)) std::cout<<"Unesena rijec nije nadjena!";
        else{
            for(auto it=b[rijec].begin();it!=b[rijec].end();it++)
            std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
        }
    }
	return 0;
}

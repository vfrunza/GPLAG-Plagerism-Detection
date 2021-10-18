/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
std::map<std::string,std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga knjiga){
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> finalna;
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++)
        for(int j(0); j<(it->second).size(); j++)
            for(int k(0); k<(it->second).at(j).length(); k++)
                if((it->second).at(j).at(k)>='A' && (it->second).at(j).at(k)<='Z') (it->second).at(j).at(k)+='a'-'A';
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++){
        int redni_broj_stranice(1);
        for(int j(0); j<(it->second).size(); j++){
            for(int k(0); k<(it->second).at(j).length(); k++){
            int s(k);
            while(s<(it->second).at(j).length() && (((it->second).at(j).at(s)>='a' && (it->second).at(j).at(s)<='z') || ((it->second).at(j).at(s)>='0' && (it->second).at(j).at(s)<='9'))) s++;
            std::string pomocni((it->second).at(j).substr(k,s-k));
            auto it2(std::find_if(finalna.begin(), finalna.end(), [pomocni] (std::pair<std::string, std::set<std::tuple<std::string, int, int>>> par) { return par.first==pomocni;}));
            if(it2==finalna.end()){
                finalna[pomocni].insert(std::make_tuple(it->first,redni_broj_stranice,k));
                k=s;
                
            }
            else{
                it2->second.insert(std::make_tuple(it->first,redni_broj_stranice,k));
                k=s;
            }
            if(k==(it->second).at(j).length()) break;
            }
            redni_broj_stranice++;
        }
    }
    return finalna;
}
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova){
    auto it(std::find_if(indeks_pojmova.begin(), indeks_pojmova.end(), [rijec] (std::pair<std::string, std::set<std::tuple<std::string, int, int>>> par) { return par.first==rijec;}));
    if(it==indeks_pojmova.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return it->second;
}
    
    
void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> finalna){
    for(auto it(finalna.begin()); it!=finalna.end(); it++){
        std::cout<<it->first<<": ";
        for(auto it2((it->second).begin()); it2!=(it->second).end(); it2++){
        std::cout << std::get<0>(*it2) << "/"<< std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
        it2++;
        if(it2!=(it->second).end()) std::cout<<", ";
        it2--;
    }
    std::cout<<std::endl;
    }
}
int main ()
{
    Knjiga knjiga;
    do{
        std::string s;
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin,s);
        std::vector<std::string> stranice;
        if(s==".") break;
        int i(1);
        do{
            std::string recenica;
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline(std::cin,recenica);
            if(recenica==".") break;
            stranice.push_back(recenica);
            i++;
        }while(true);
        knjiga.insert(std::make_pair(s,stranice));
    }while(true);
    std::cout<<"\nKreirani indeks pojmova:\n";
    IspisiIndeksPojmova(KreirajIndeksPojmova(knjiga));
    do{
        std::string s;
        std::cout<<"\nUnesite rijec: ";
        std::getline(std::cin, s);
        if(s==".") break;
        try{
            std::set<std::tuple<std::string,int,int>> skup(PretraziIndeksPojmova(s,KreirajIndeksPojmova(knjiga)));
            for(auto it(skup.begin()); it!=skup.end(); it++)
                std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
        }catch(std::logic_error logika){
            std::cout<<logika.what();
        }
    }while(true);
    return 0;
}

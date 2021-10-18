/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

bool JeLiDioRijeci(char c)
{
    if((c>='a' && c<='z') || (c>='0' && c<='9')) return true;
    else return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> Mapa;
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z')s[i]+=32;
    }
    std::string rijec="";
    int  duzina=0, pocetak=0,kraj=0;
    std::set<int> K;
    for(int i=0; i<s.length();) {
        while(i<s.length() && JeLiDioRijeci(s[i])==false) {
            i++;
        }
        pocetak=i;
        while(i<s.length() && JeLiDioRijeci(s[i])==true) {
            i++;
        }
        kraj=i;
        duzina=kraj-pocetak;
        rijec=s.substr(pocetak, duzina);
        std::set<int> P;
        for(auto it(Mapa.begin()); it!=Mapa.end(); it++) {

            if(it->first==rijec) {
                P=it->second;
            }
        }
        if(P.size()!=0) {
            P.insert(pocetak);
            Mapa.erase(rijec);
            Mapa.insert(std::make_pair(rijec, P));
        } else {
            P.insert(pocetak);
            Mapa.insert(std::make_pair(rijec, P));
        }
    }
    return Mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int> > Mapa)
{
    std::set<int> S;
    for(auto it(Mapa.begin()); it!=Mapa.end(); it++) {
        if(it->first==rijec) {
            S=it->second;
        }
    }
    if(S.size()==0) {
        throw std::logic_error ("Pojam nije nadjen");
    }
    return S;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int> > Mapa)
{
    std::set<int> S;
    for(auto it(Mapa.begin()); it!=Mapa.end(); it++) {
        std::cout<<it->first<<": ";
        S=it->second;
        std::set<int>::iterator is(S.begin());
        for(int i=0; i<S.size(); i++) {
            if(i!=(S.size()-1))
                std::cout<<(*is)<<",";
            else  std::cout<<(*is);
            is++;
        }
        std::cout<<"\n";
    }
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string string;
    std::getline (std::cin, string);
    std::map<std::string, std::set<int> > M;
    M=KreirajIndeksPojmova(string);
    IspisiIndeksPojmova(M);
    std::string zeljenineki;
    std::set<int> pomocset;

    while(zeljenineki!=".") {
        std::cout<<"Unesite rijec: ";
        std::getline (std::cin, zeljenineki);
        if(zeljenineki==".") break;
        pomocset= {};
        for(auto it(M.begin()); it!=M.end(); it++) {

            if(it->first==zeljenineki) {
                pomocset=it->second;
                std::set<int>::iterator at(pomocset.begin());
                for(int i=0; i<pomocset.size(); i++) {
                    std::cout<<*at<<" ";
                    at++;
                }
                std::cout<<"\n";
            }
        }
        if(pomocset.size()==0) std::cout<<"Unesena rijec nije nadjena!\n";
    }
    return 0;
}
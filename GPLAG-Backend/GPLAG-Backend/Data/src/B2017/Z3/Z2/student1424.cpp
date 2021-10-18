/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string,int,int>>> Mapica;
Mapica KreirajIndeksPojmova(Knjiga book)
{
    Mapica mapa;

    for(auto it=book.begin(); it!=book.end(); it++) {

        for(int i=0; i<(it->second).size(); i++) {
            std::string recenica((it->second)[i]);
            for(int j=0; j<recenica.size(); j++) {
                std::string rijec;
                int indeks;
                if(recenica[j]!=' ') {
                    indeks=j;
                    while(recenica[j]!=' ' && j<recenica.size()) {
                        if(recenica[j]>='A' && recenica[j]<='Z') recenica[j]+='a'-'A';
                        rijec.push_back(recenica[j]);
                        j++;
                    }
                  mapa[rijec].insert(std::make_tuple(it->first, i+1, indeks));
              }
            }
        }
    }
    return mapa;
}
std::set<std::tuple<std::string, int, int >> PretraziIndeksPojmova(std::string rijec, Mapica mapa){
    for(int i=0; i<rijec.size();i++) if(rijec[i]>='A' && rijec[i]<='Z') rijec[i]+='a'-'A';
    if(!mapa.count(rijec)) throw std::logic_error("Unesena rijec nije nadjena!");
    return mapa[rijec];
}

void IspisiIndeksPojmova(Mapica mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<":";int i=0;
        for(auto m: it->second) { if(i!=0 && i!=(it->second).size())std:: cout<<", "; else std::cout<<" ";
            std::cout<<std::get<0>(m)<<"/"<<std::get<1>(m)<<"/"<<std::get<2>(m);
        i++;}
        std::cout<<std::endl;
    }
}

int main ()
{
   Knjiga book;

    for(;;) {
       std::string s;
        std::cout<<"Unesite naziv poglavlja: ";
        std:: getline(std::cin, s);
        int i=0;

        if(s!=std::string(".")) {
            for(;;) {
                std:: string s2;
                std::cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
                std::getline(std::cin, s2);
                if(s2!=std::string(".")) book[s].push_back(s2);
                else break;
                i++;
            }
        }

        else break;
    }
std::cout<<std::endl<<"Kreirani indeks pojmova: "<<std::endl;
    IspisiIndeksPojmova(KreirajIndeksPojmova(book));
   
    for(;;){
        std::string s;
        std::cout<<"Unesite rijec: ";
        std::cin>>s;
        if(s!=std::string(".")) {
        try{    
            for(std::tuple<std::string, int, int> trojka:  PretraziIndeksPojmova(s, KreirajIndeksPojmova(book))) std::cout<<std::get<0>(trojka)
            <<"/"<<std::get<1>(trojka)<<"/"<<std::get<2>(trojka)<<" ";
            std::cout<<std::endl;}
            catch(std::logic_error izuzetak){
                std::cout<<izuzetak.what()<<std::endl;
            }
            
        }
        else break;
    }

    return 0;
}

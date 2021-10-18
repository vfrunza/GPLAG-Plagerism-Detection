#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <new>
#include <utility>
#include <stdexcept>
#include <memory>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <tuple>
typedef typename std::map<std::string, std::vector<std::string>> Knjiga;
typedef typename std::map<std::string, std::set<std::tuple<std::string,int,int>>> Bukvar;
Bukvar KreirajIndeksPojmova(Knjiga k){
    
    Bukvar citab;

for(auto it=k.begin();it!=k.end();it++){
        for(int i=0;i<it->second.size();i++){
        std::string &m=it->second[i];
        std::transform(m.begin(), m.end(), m.begin(), ::tolower);}}
    for(auto it=k.begin();it!=k.end();it++){
        for(int i=0;i<it->second.size();i++){
        std::string m=it->second[i];
        std::string jedan;
        bool a=false;
        for(auto s=m.begin();s!=m.end();s++){
            if((*s>='0' && *s<='9') || (*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
                a=true;
                jedan.push_back(*s);
        }
        if((*s<'0')  || (*s>'9' && *s<'A') || (*s>'Z' && *s<'a') || ((*s>'Z') && (a==true))) {
            std::tuple<std::string,int,int> skup{it->first,i+1,10};
            std::set<std::tuple<std::string,int,int>> nekakav;
            nekakav.insert(skup);
            citab.insert(std::make_pair(jedan,nekakav));
        }
    }
}}
    return citab;
}
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string neki,Bukvar b){
    std::set<std::tuple<std::string,int,int>> klinac;
    for(auto it=b.begin();it!=b.end();it++){
        std::string m=it->first;
        if(m==neki){
            auto as=it->second.begin();
            klinac.insert(*as);
        }
    }
    return klinac;
}
void IspisiIndeksPojmova(Bukvar b){
    
    for(auto it=b.begin();it!=b.end();it++){
        std::cout << it->first <<" : ";
        auto motor=it->second.begin();
            std::tuple<std::string,int,int> nesto(*motor);
            std::cout << std::get<0>(nesto) <<"/"<< std::get<1>(nesto) <<"/" << std::get<2>(nesto);
            std::cout <<"\n";
}
}


int main ()
{
    Knjiga b;
    for(;;){
        std::cout << "Unesite naziv poglavlja: ";
        std::string m;
        std::getline(std::cin,m);
        if(m==".") break;
         int brojac=0;
         std::vector<std::string> v;
         std::cin.clear();
         std::cin.ignore(1000,'\n');
        for(;;){
        std::cout << "Unesite sadrzaj stranice " << brojac+1 <<": ";
        std::string s;
        std::getline(std::cin,s);
        brojac++;
        if(s=="."){
          b.insert(std::make_pair(m,v));
          break;
        } 
        v.push_back(s);
                   std::cin.clear();
         std::cin.ignore(1000,'\n');
   } }
   Bukvar k=KreirajIndeksPojmova(b);
   std::cout << "Kreirani indeks pojmova: ";
   std::cout <<"\n";
   IspisiIndeksPojmova(k);
   std::cout <<"Unesite rijec: ";

   return 0;
}

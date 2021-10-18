/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
typedef std::map<std::string,std::set<int>> Mapa;
bool alfanum(char x){
    if((x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x>='0' && x<='9'))return true;
    return false;
}
Mapa KreirajIndeksPojmova (std::string s){
    Mapa izlaz;
    auto it(s.begin());
    while(it!=s.end()){
        *it=tolower(*it);
        it++;
    }
    it=s.begin();
    while(it!=s.end()){
        while(it!=s.end()){
            if(!alfanum(*it))it++;
            else break;
        }
        if(it==s.end())continue;
        auto pocetak(it);
        while(it!=s.end()){
            if(alfanum(*it))it++;
            else break;
        }
        auto rijec(s.substr(pocetak-s.begin(),it-pocetak));
        if(izlaz.find(rijec)==izlaz.end()){
            izlaz.insert(std::make_pair(rijec,std::set<int>{int(pocetak-s.begin())}));
        }
        else izlaz.find(rijec)->second.insert(pocetak-s.begin());
    }
    return izlaz;
}
std::set<int> PretraziIndeksPojmova(std::string rijec, Mapa indeks){
    if(indeks.find(rijec)==indeks.end()) throw std::logic_error("Pojam nije nadjen");
    else return indeks.find(rijec)->second;
}
void IspisiIndeksPojmova(Mapa indeks){
    auto p1(indeks.begin());
    while(p1!=indeks.end()){
        std::cout<<p1->first<<": ";
        auto p2(p1->second.begin());
        for(int i=0;i<p1->second.size()-1;i++) std::cout<<*p2++<<",";
        std::cout<<*p2<<std::endl;
        p1++;
    }
}
int main (){
    std::cout<<"Unesite tekst: ";
    std::string s;    
    std::getline(std::cin,s);
    auto m(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    std::string rijec="";
    while(true){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") return 0;
        try{
            auto skup(PretraziIndeksPojmova(rijec,m));
            for(auto x:skup)std::cout<<x<<" ";
        }catch(std::logic_error a){std::cout<<"Unesena rijec nije nadjena!";}
        std::cout<<std::endl;
    }
	return 0;
}
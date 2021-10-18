#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <stdexcept>
bool SlovoIliCifra(char s){
    return s>='a' && s<= 'z' || s >= '0' && s <= '9';
}
std::set<int> NadjiMjestoPonavljanja(const std::string &tekst,std::string rijec){
    int i(0);
    std::set<int> a;
    while(i < tekst.length()){
        while(i < tekst.length() && !SlovoIliCifra(tekst[i]))i++;
        if(rijec == tekst.substr(i,rijec.size()) && (i+rijec.size() == tekst.length() || (i +rijec.length() < tekst.length() && !SlovoIliCifra(tekst[i+rijec.size()]))))
            a.insert(i);
        while(i < tekst.length() && SlovoIliCifra(tekst[i]))i++;
    }
    return a;
}
void IspisiIndeksPojmova(const std::map<std::string,std::set<int>> &indeks_pojmova){
    for(auto it(indeks_pojmova.begin());it != indeks_pojmova.end();it++){
        std::cout << it->first << ": ";
        auto it1(it->second.begin());
        if(it1 != it->second.end())std::cout << *it1++;
        else{ std::cout << std::endl;continue;}
        while(it1 != it->second.end())std::cout << "," << *it1++;
        std::cout << std::endl;
    }
}
std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>> indeks_pojmova){
    for(int i(0);i < rijec.length();i++)
        if(rijec[i] >= 'A' && rijec[i] <= 'Z') rijec[i]+=32;
    auto it(indeks_pojmova.find(rijec));
    if(it != indeks_pojmova.end())return indeks_pojmova[rijec];
    else throw std::logic_error("Pojam nije nadjen");
    
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst){
    for(int i(0);i < tekst.length();i++)
        if(tekst[i] >= 'A' && tekst[i] <= 'Z') tekst[i]+=32;
    std::map<std::string,std::set<int>> indeks_pojmova;
    auto it(tekst.begin());
    while(it != tekst.end()){
        auto it_na_razmak(std::find_if(it,tekst.end(),[](char s){return !SlovoIliCifra(s);}));
        if(it_na_razmak != it){
            indeks_pojmova.insert({tekst.substr(it-tekst.begin(),it_na_razmak-it),NadjiMjestoPonavljanja(tekst,tekst.substr(it-tekst.begin(),it_na_razmak-it))});
            it+=it_na_razmak-it;
        }else it++;
    }
    return indeks_pojmova;
}
int main ()
{
   std::string s;
   std::cout << "Unesite tekst: ";
   std::getline(std::cin,s);
   auto indeks_pojmova(KreirajIndeksPojmova(s));
   IspisiIndeksPojmova(indeks_pojmova);
   for(;;){
       std::cout << "\nUnesite rijec: ";
       std::cin >> s;
       if(s == ".")return 0;
       try{
           auto set(PretraziIndeksPojmova((s),indeks_pojmova));
           for(auto x : set)std::cout << x << " ";
       }catch(std::logic_error){
           std::cout << "Unesena rijec nije nadjena!";
       }
   }
	return 0;
}
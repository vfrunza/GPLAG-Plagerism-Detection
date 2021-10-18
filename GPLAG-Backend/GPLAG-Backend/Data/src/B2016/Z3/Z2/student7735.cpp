 #include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <cctype>

std::string PretvoriuMala(std::string t){
    for(int i=0;i<t.size();i++)t[i]=std::tolower(t[i]);
    return t;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst){
    tekst=PretvoriuMala(tekst);
     std::map<std::string,std::set<int>> indeks_pojmova; 
    for(int i=0;i<tekst.size();i++){
        std::string s;
        int indeks=i;
        while((tekst[i]>='A' && tekst[i]<='Z')||(tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9')){
            s.push_back(tekst[i]);
            i++;
            if(i==tekst.size())break;
        }
        if(s!=""){
            std::set<int> skup;
            skup.insert(indeks);
            auto it=indeks_pojmova.find(s);
            if(it==indeks_pojmova.end())indeks_pojmova.insert(std::make_pair(s,skup));
            else{ (indeks_pojmova[s]).insert(indeks);
            }
        }
    }
   return indeks_pojmova;}
std::set<int> PretraziIndeksPojmova (std::string pojam,std::map<std::string,std::set<int>> indeks_pojmova){
    pojam=PretvoriuMala(pojam);
     std::set<int> skup;
     auto it=indeks_pojmova.find(pojam);
     if(it==indeks_pojmova.end()) throw std::logic_error("Pojam nije nadjen");
     skup=(indeks_pojmova.find(pojam))->second;
     return skup;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> indeks_pojmova){
    for(auto x=indeks_pojmova.begin();x!=indeks_pojmova.end();x++){
        std::cout << x->first<<": ";
        for(auto t=((x->second).begin());t!=((x->second).end());t++){
            auto kraj=(x->second).rbegin();
            if(*t!=*kraj)std::cout<<*t<<",";
            if(*t==*kraj)std::cout << *t;
        }
        std::cout  << std::endl;
    }
}

int main (){
 std::cout << "Unesite tekst: ";
 std::string t;
 std::getline(std::cin,t);
 IspisiIndeksPojmova(KreirajIndeksPojmova(t));
 for(;;){
     try{
 std::cout << "Unesite rijec: ";
 std::string rijec;
 std::getline(std::cin,rijec);
 if(rijec==".")break;
 std::set<int> skup;
 skup=PretraziIndeksPojmova(rijec,KreirajIndeksPojmova(t));
 for(auto x:skup)std::cout << x<<" ";
 std::cout  << std::endl;
    }
    catch(std::logic_error e){
   std::cout << "Unesena rijec nije nadjena!"<< std::endl;
   }
 }
}
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>

bool JelZnak(char znak){
     return !( znak < '0' || (znak > '9' && znak < 'A') || (znak > 'Z' && znak < 'a') || znak > 'z');
}

std::string PretvoriVelikaUMala(std::string tekst){
    for(int i=0; i<tekst.size(); i++){
        if(tekst[i] >= 'A' && tekst[i]  <= 'Z') tekst[i]+=('a'-'A');
    }
    return tekst;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst) {
     std::map<std::string, std::set<int>> ind_pojmova;
     tekst=PretvoriVelikaUMala(tekst);
    
     for(int i{0}; i<tekst.length(); i++){
     while( i<tekst.length() && !JelZnak(tekst[i]) ){
         i++;
         } 
         int n{i};
         std::string rec;
     while(i<tekst.length() && JelZnak(tekst[i]) ){ 
         rec += tekst[i];
         i++;
     }
     
     if(!ind_pojmova.count(rec)){ 
        
        std::set<int> redosled{n};
        ind_pojmova[rec] = redosled;
        
     }
         
    else{
        std::map<std::string, std::set<int>>::iterator it1(ind_pojmova.find(rec));
    it1->second.insert(n);
    }   
    }
     return ind_pojmova;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> ind_pojmova){
    for(auto it2(ind_pojmova.begin()); it2 != (ind_pojmova.end()); it2++){
        std::cout << it2->first << ": ";
        int i(it2->second.size());
        for(auto it3(it2->second.begin()); it3 !=it2->second.end(); it3++){
            
            if(i == 1) std::cout << *it3;
            
            else std::cout<< *it3 <<",";
            i--;
        }
           
   
    std::cout<<std::endl; 
    }
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> ind_pojmova){
    std::map<std::string, std::set<int>>::iterator it(ind_pojmova.find(rijec));
    if( it == ind_pojmova.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
    }



int main ()
{
    std::string tekst="";
    std::map<std::string, std::set<int>> ind_pojmova;
    
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    
    ind_pojmova=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(ind_pojmova);
    
    
    for(;;){
        try{
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec== ".") break;
        
        std::set<int> skup;
        skup =PretraziIndeksPojmova(rijec, ind_pojmova);
        for(auto n : skup ){
            std::cout<< n << " ";}
            std::cout << std::endl;
            }
    catch(std::logic_error){
    std::cout << "Unesena rijec nije nadjena!" << std::endl;
    }   
}
	return 0;
}
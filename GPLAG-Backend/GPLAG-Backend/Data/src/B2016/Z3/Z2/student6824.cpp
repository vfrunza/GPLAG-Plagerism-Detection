/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iterator>
#include <stdexcept>
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    std::set<int> skup;
    std::set<int> skup1;
    int prekid{0}, start{0}, pocetak{0}, pocetak1{0}, kraj{0}, kraj1{0}, pokaz1{0}, brojac{0}, pokaz2{0}, ind{0};
    std::string prva, druga;
    while(prekid!=1){
      brojac=0; 
      for(int i=start; i<s.size(); i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
          if(pokaz1==0){
            if(brojac==0) {pocetak=i; kraj=i;}
            pocetak1=i;
            kraj1=i;
            pokaz1=1;
            if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32; 
            prva.push_back(s[i]);
          }
          else{
            if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
            if(brojac==0) kraj=i;
            kraj1=i;
            prva.push_back(s[i]);
          }
        }
        else{
          if(pokaz1==1){
            pokaz1=0;
            if(brojac==0){
                skup.insert(pocetak);
                druga=prva;
                brojac++;
            }
            else{
                if(prva==druga){
                  skup.insert(pocetak1);    
                  brojac++;
                }
            }
          }    
        for(int j=0; j<prva.size(); j++) prva.erase(j);
        }
       }
       if(prva==druga) skup.insert(pocetak1);
       ind=0;
       for(int i=0; i<pocetak; i++){
           if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
               if(pokaz2==0){
                   pokaz2=1;
                   prva.push_back(s[i]);
               }
               else{
                   prva.push_back(s[i]);
               }
           }
           else{
               if(pokaz2==1){
                   if(prva==druga) ind=1;
                   pokaz2=0;
               }
           }
       }
      if(ind==0) {mapa.insert(std::make_pair(druga, skup));}
      skup=skup1;
      start=kraj+1;
      pokaz1=0;
      if(kraj==s.size()-1) prekid=1;
    }
 return mapa;    
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    int poz{0};
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        poz=0;
        std::cout <<it->first<<": ";
        for(int x : it->second) {
            if((poz<it->second.size()-1)) std::cout <<x<<","; 
            else std::cout<<x;
            poz++;
        }
        std::cout <<std::endl;
    }
}
std::set<int>PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa){
     std::map<std::string, std::set<int>>::iterator it;
     int ind{0};
     try{
      for(it=mapa.begin(); it!=mapa.end(); it++){
       if(it->first==s) {ind=1; return it->second;}
    }
    if(ind==0) throw std::logic_error("Unesena rijec nije nadjena!");
    }
    catch(std::logic_error izuzetak){
        std::cout <<izuzetak.what();
    }
   if(ind!=0) 
   return it->second;
}
int main (){
     std::string s, s1;
     std::set<int> skup;
     std::cout <<"Unesite tekst: ";
     std::getline(std::cin, s);
     std::map<std::string, std::set<int>> mapa;
     mapa=KreirajIndeksPojmova(s);
     IspisiIndeksPojmova(mapa);
     while(s1[0]!='.'){
        std::cout <<"Unesite rijec: ";
        std::getline(std::cin, s1);
        if(s1[0]=='.') return 0;
        skup=PretraziIndeksPojmova(s1,mapa);
        for(int x : skup) std::cout <<x<<" ";
        std::cout<<std::endl;
     }
	return 0;
}
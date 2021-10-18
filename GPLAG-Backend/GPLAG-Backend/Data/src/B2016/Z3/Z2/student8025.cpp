#include <map>
#include <utility>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
 std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
 for(int i=0; i<s.length(); i++){
  if(s[i]>='A' && s[i]<='Z') s[i]+=32;
 }
     std::map<std::string,std::set<int>> mapa;
     std::pair<std::string,std::set<int>> parovi{"ovo", {1,2,3}};
     std::string novi[100];
     std::vector<std::set<int>> d(30);
    int v[30];
     int brojac(0);
     for(int i=0; i<s.length(); i++){
         while(!(s[i]>='a'&& s[i]<='z') && !(s[i]>='0'&& s[i]<='9')) i++; 
          v[brojac]=i;
         while(((s[i]>='a'&& s[i]<='z') || (s[i]>='0'&& s[i]<='9') ) && i<s.length()){
          novi[brojac].push_back(s[i]);
          i++;
          if(!(s[i]>='a'&& s[i]<='z') && !(s[i]>='0'&& s[i]<='9')) brojac++;
         }
     }
     int dojava(0);
     int n(0);
     for(int i=0; i<=brojac; i++){
      for(int j=i+1; j<=brojac; j++){
       if(novi[i]==novi[j]){
        dojava=1;
        parovi.first=novi[i];
        d[n].insert(v[i]);
        d[n].insert(v[j]);
       }
      
      }
      if(dojava==0){
       parovi.first=novi[i];
        d[n].insert(v[i]);
        parovi.second=(d[n]);
       mapa.insert(parovi);
       n++;
      }
       if(dojava==1){
        parovi.second=d[n];
       mapa.insert(parovi);
       dojava=0;
       n++;
       }
     }
       auto it=mapa.begin();
  it=mapa.erase(it);
     return mapa;
 }
 std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa){
  for(auto it=mapa.begin(); it!=mapa.end(); it++) {
   if(rijec==it->first) return it->second;
  }
  throw std::logic_error("Pojam nije nadjen");
 }
 void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
  for(auto it=mapa.begin(); it!=mapa.end(); it++){
   std::cout<<it->first<<": ";
   std::set<int> skup=it->second;
   int brojac(0);
   int n(0);
   for(auto pok=skup.begin(); pok!=skup.end(); pok++) brojac++;
   for(auto pok=skup.begin(); pok!=skup.end(); pok++){
    std::cout<<*pok;
    n++;
  if(n==brojac) break;
    std::cout<<",";
   }
   std::cout<<std::endl;
  }
  
  
 }
 
 
 
 
 
int main ()
{
 std::string recenica;
 std::string rijec;
 std::map<std::string, std::set<int>> mapa;
 std::set<int> skup;
 std::cout<<"Unesite tekst: ";
 std::getline(std::cin, recenica);
  mapa=KreirajIndeksPojmova(recenica);
  IspisiIndeksPojmova(mapa);
 
for(;;){
  std::cout<<"Unesite rijec: ";
  std::getline(std::cin,rijec);
  for(int i=0; i<rijec.length(); i++){
   if(rijec[i]=='.') return 0;
  }
 
 try{
   skup=PretraziIndeksPojmova(rijec,mapa);
   for(auto pok=skup.begin(); pok!=skup.end(); pok++){
    std::cout<<*pok<<" ";
    
   }
   std::cout<<std::endl;
  }catch(...){
   std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
  }
 
 } ;
	return 0;
}
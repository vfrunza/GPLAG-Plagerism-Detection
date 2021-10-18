/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <stdexcept>
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string str){
    std::set<int> skup;
    std::map<std::string, std::set<int>> mapa;
 int poc_ind=0;
 std::vector<std::string> vektor;
for(int i=0; i<str.size(); i++){
    if(str[i]>='A'&&str[i]<='Z'){
        str[i]=std::tolower(str[i]);
    }
     
    if(!(str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z' || str[i]>='0'&&str[i]<='9' )){
       std::string rijec=str.substr(poc_ind, i-poc_ind);
             if(mapa.count(rijec)!=1){
             mapa[rijec].insert(poc_ind);
             } 
             else {
                 mapa[rijec].insert(poc_ind);
                 
             }
             poc_ind = i+1;
    }
   
   
}

    std::string rijec=str.substr(poc_ind, str.size()-poc_ind);
    if(mapa.count(rijec)!=1){
        mapa[rijec].insert(poc_ind);
    } else {
        mapa[rijec].insert(poc_ind);
    }
    
    std::string rijec1="";
      if(mapa.count(rijec1)==1){
          mapa.erase("");
      }

  return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa){
    std::set<int> novi_skup;
    int brojac=0;
        for(auto it=mapa.begin(); it!=mapa.end(); it++){
            if(it->first==rijec){
        for(auto i=it->second.begin(); i!=it->second.end(); i++){
            novi_skup.insert(*i);
            brojac++;
        }
    } 
            
}
if( brojac==0) throw std::logic_error ("Unesena rijec nije nadjena!");
    
    return novi_skup;
   
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>>mapa ){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        int brojac =0;
        std::cout<<it->first<<": ";
        
        for(auto j=it->second.begin(); j!=it->second.end(); j++){
            brojac ++;
            
        }
        int i=0;
        for(auto x=it->second.begin(); x!=it->second.end(); x++){
            if(i<brojac-1){
                std::cout<<*x<<",";
                i++;
            } else {
                std::cout<<*x;
                std::cout<<std::endl;
            }
        }
    
    
    
    }
   
    
}

int main ()
{

    std::map<std::string, std::set<int>> mapa;
    std::set<int> skup;
    std::string tekst;
    std::string rijec;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, tekst);
   auto k=KreirajIndeksPojmova(tekst);
   
   IspisiIndeksPojmova(k);
   for(;;){
   std::cout<<"Unesite rijec: ";
   std::getline(std::cin, rijec);
   if(rijec==".") break;
   try{
       
   auto u(PretraziIndeksPojmova(rijec, k));
   for(auto x:u){
     std::cout<<x<<" ";
    
   }
   std::cout<<std::endl;
   
   
   
   }
   catch(std::logic_error izuzetak){
       std::cout<<izuzetak.what()<<std::endl;;
   }}
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <set>
#include <cctype>
#include <cstring>
#include <stdexcept> 

char NapraviMalo(char znak) {
 return std::tolower(znak);
}


std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    int pozicija=0,j=0;
    std::map<std::string,std::set<int>> mapa;
    std::string pomocni;
    int i=0;
    while(i<s.length()){
        
        
        j=i;
        pomocni="";
        if(s[i]<'0' || (s[i]>'9' && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z'){
            
                while(s[i]<'0' || (s[i]>'9' && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z'){
            if(i==s.length()) break;
            i++;}
        }
        else{
            
       while((s[i]>='0' && s[i]<='9') ||(s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
       pozicija=j;
       pomocni.push_back(NapraviMalo(s[i]));
       if(i==s.length()) break;
     i++;
  }
 
  auto it(mapa.find(pomocni));
  if(it==mapa.end()){
     mapa[pomocni].insert(pozicija); 
  }else{
    
     mapa[pomocni].insert(pozicija); 
  }
   
    }
        
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>>mapa){
    
   std::string pomocni;
   for(int i=0;i<s.length();i++){
       pomocni.push_back(NapraviMalo(s[i]));
   }
    auto it(mapa.find(pomocni));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else
     return mapa[pomocni];
    
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>>mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout<<it->first<<": ";
        std::string hasan;
        std::set<int> skup;
        skup=it->second;
        for(auto it1=skup.begin();it1!=skup.end();){
             std::cout<<*it1++;
            if(it1==skup.end()) break;
            std::cout<<",";
        }std::cout<<std::endl;
    }
    
}
int main()
{
    std::set<int> skup;
    std::cout<<"Unesite tekst: ";
    std::string s,rijec;
    std::getline(std::cin,s);

    std::map<std::string, std::set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    std::cout<<"Unesite rijec: ";
    std::getline(std::cin,rijec);
    if(rijec==".") return 0;
    
    while(rijec!="."){
        if(rijec==".") break;
        
        
     try{ skup=PretraziIndeksPojmova(rijec,mapa);
        
         for(auto it=skup.begin();it!=skup.end();){
          std::cout<<*it++;
          if(it==skup.end()) break;
          std::cout<<" ";
      }std::cout<<std::endl;}
      catch(std::logic_error izuzetak){
          std::cout<<izuzetak.what()<<std::endl;
      }
        std::cout<<"Unesite rijec: ";
       std::getline(std::cin,rijec); 
        
         if(rijec==".") return 0;
    }
    return 0;
}

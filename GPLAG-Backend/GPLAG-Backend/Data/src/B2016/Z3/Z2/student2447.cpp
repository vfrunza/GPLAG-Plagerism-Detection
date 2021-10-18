#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <set>
#include <algorithm>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    
    std::map<std::string, std::set<int>> mapa;
    
    for(int i=0;i<s.length();i++){
        std::string rijec;
        int brojac(0);
        brojac=i;
        
        while((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
           rijec.push_back(s[i]);
           i++;
        }
           
          for(int i=0;i<rijec.length();i++){
               if(rijec[i]>='A' && rijec[i]<='Z'){
                  rijec[i]=rijec[i]+32;
              }
          } 
          if(rijec.size()!=0)
           {
            auto it(mapa.find(rijec));
            if(it==mapa.end()) {
                std::set<int> skup;
                skup.insert(brojac);
                mapa.insert(std::make_pair(rijec,skup));
            }else{
                
                (it->second).insert(brojac);
                
            }
           }
    }
    return mapa;
}


std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string, std::set<int>>mapa){
    
    std::set<int>set;
    std::string rijec;
    
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]+32;
        }
    }
    
        auto it(mapa.find(s));
        if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
        else{
            
           return it->second;
            
        }
}


void IspisiIndeksPojmova(std::map<std::string, std::set<int>>mapa){
    
    for(auto it1=mapa.begin(); it1!=mapa.end(); it1++){
        std::cout<< it1->first <<": ";
        for(std::set<int>::iterator it2=it1->second.begin(); it2!=it1->second.end(); ++it2){
           if((++it2)--==it1->second.end())
            std::cout<<*it2;
            else 
            std::cout<<*it2<<",";
    
        }
        std::cout<<std::endl;
    }
    
}


int main ()
{
    bool a(false);
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    std::string rijec;
    
    
    std::map<std::string, std::set<int>> mapa;
    
  try{
      
      mapa=KreirajIndeksPojmova(s);
      IspisiIndeksPojmova(mapa);
      
      
      for(;;){
          try{
          std::cout<<"Unesite rijec: ";
          std::getline(std::cin, rijec);
          
              if(rijec==".") {a=true;}
              if(a){ return 0;}
              
              auto Ime_seta(PretraziIndeksPojmova(rijec,mapa));
              for(auto it=Ime_seta.begin();it!=Ime_seta.end();it++) std::cout<<*it<<" ";
              
              std::cout<<std::endl;}
              catch(...){
                  std::cout<<"Unesena rijec nije nadjena!\n";
              }
              
          }
          
   
     

  }
  
  catch(...){
      std::cout << "Parametar nije pronadjen" << std::endl;
  }
    
	return 0;
}
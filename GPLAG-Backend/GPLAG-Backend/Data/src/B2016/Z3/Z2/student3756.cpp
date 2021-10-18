/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <memory>
#include <cstring>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst){
  std::map<std::string,std::set<int>> mapa;
  
   for(int i=0;i<tekst.length();i++) tekst[i]=std::tolower(tekst[i]);
   
    for(int i=0;i<tekst.size();i++){
     std::string rijec;
     int index=i;
        while(((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]<='Z' && tekst[i]>='A') || (tekst[i]<='9' && tekst[i]>='0')) && i<int(tekst.length())){
            rijec.push_back(tekst[i]);
            i++;
        }
        if(rijec.length()>0)
         mapa[rijec].insert(index);
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>> mapa){
 
    for(auto i=mapa.begin();i!=mapa.end();i++){
        if(i->first.find(rijec)){
        if(mapa[rijec].size()>0)
        return mapa[rijec];
        else throw std::logic_error("Unesena rijec nije nadjena!");
        }
    }
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
     for(auto &x: mapa){
      std::cout<<x.first<<": ";
      for(auto i=(x.second).begin();i!=(x.second).end();i++) 
      if(i!=--(x.second).end()) 
      std::cout<<(*i)<<",";
      else std::cout<<(*i);
      std::cout<<"\n";
  } 
}

int main ()
{
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, tekst);
    
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst));
    std::string rijec;
    
    do{
    std::cout<<"\nUnesite rijec: ";
    std::cin>>rijec;
    if(rijec==".") return 0;
    try{
    std::set<int> skup;
    skup=PretraziIndeksPojmova(rijec,KreirajIndeksPojmova(tekst));
    if(skup.size()>0){
    for(int x: skup) std::cout<<x<<" ";}
    }catch(std::logic_error izuz){std::cout<<izuz.what();}
    }while(rijec!=".");
 
	return 0;
}
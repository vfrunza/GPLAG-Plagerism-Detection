/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<utility>
#include<stdexcept>

typedef std::map<std::string, std::set<int>> map;
typedef std::set<int> set;

map KreirajIndeksPojmova(std::string a){
    map mapa;
    set skup;
    std::vector<std::string> rijeci;
    std::string pomocni;
    std::string novi;
    if(a.length() == 0) return mapa;
    for(int i=0; i<=a.length()-1; i++){
        if(a[i]>64 && a[i]<91) pomocni.push_back(a[i]+32);
        else if((a[i]>96 && a[i]<123)||(a[i]>='0' && a[i]<='9')) pomocni.push_back(a[i]);
        else { 
            if(pomocni.length() != 0)
        rijeci.push_back(pomocni);
        pomocni.resize(0);
        }
      if(i==a.length()-1){
        if(pomocni.length() != 0)   
        rijeci.push_back(pomocni);
      }
    }
    
    for(int i=0;i<rijeci.size();i++)
        mapa.insert(std::pair<std::string,std::set<int>>(rijeci[i], {}));
    
    std::string prepravljeni=a;    
    for(int i=0; i<=prepravljeni.length()-1;i++){
        if(prepravljeni[i]>64 && prepravljeni[i]<91) {
            prepravljeni[i]+=32;
            
        }
        }
    for(int i=0;i<=prepravljeni.length()-1;i++){
        if((prepravljeni[i]>96 && prepravljeni[i]<123)||(prepravljeni[i]>='0' && prepravljeni[i]<='9')){
        while(((prepravljeni[i]>96 && prepravljeni[i]<123)||(prepravljeni[i]>='0' && prepravljeni[i]<='9'))&& i<prepravljeni.length())
        {
        novi.push_back(prepravljeni[i]);
        i++;
        }
        
        
            auto it=mapa.find(novi);
            (it->second).insert(i-novi.length());
            novi.resize(0); 
        }
    }
    return mapa;
        
}
std::set<int> PretraziIndeksPojmova(std::string a, map b){
    for(int i=0;i<a.length();i++){
        if(a[i]>=65 && a[i]<=90) a[i]+=32;
    }
    auto it(b.find(a));
    if(it==b.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova (map a){
    for( auto i=a.begin();i!=a.end();i++){
        std::cout<<i->first<<": ";
        auto k=--(i->second).end();
        for(auto j=(i->second).begin(); j!=(i->second).end();j++){
            std::cout<< (*j);
            if(j!=k) std::cout<<",";
            
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string a;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,a);
    map mapa= KreirajIndeksPojmova(a);
    IspisiIndeksPojmova(mapa);
    
    do {
        std::cout<<"Unesite rijec: ";
        std::cin>>a;
    if(a==".") return 0;
       try{
    std::set<int> pozicije=PretraziIndeksPojmova(a,mapa);
            
            for(auto it=pozicije.begin();it!=pozicije.end();it++){
                std::cout<<*it<<" ";
               }
        std::cout<<std::endl;}
    
        
        catch(...) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    while(1);
    
   
	return 0;
}



/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <stdexcept>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst){
    
    for (int i(0);i<tekst.size();i++){
        
        if(tekst[i]>=65 && tekst [i]<=90)
            tekst[i]=tekst[i]+32;
    }
    
    int brojac(0);
    
    std::map<std::string,std::set<int>> mapa;
    
    for(int i(0);i<tekst.size();i++){
        
        std::string pom;
        brojac=i;
        
        while((tekst[i]>=97 && tekst[i]<=122) || (tekst[i]>='0' && tekst[i]<='9')){
            
            pom.push_back(tekst[i]);
            i++;
        }
        
        bool ima(false);
        
        for(auto it=mapa.begin();it!=mapa.end();it++){
            
            if(it->first==pom){
                it->second.insert(brojac);
            }
        }
        
        if(!(ima) && pom.size()!=0)
            mapa[pom].insert(brojac);
    }
    
    return mapa;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    
    for(auto it=mapa.begin();it!=mapa.end();it++){
        
        std::cout<<it->first<<": ";
        
        for(auto it1=it->second.begin();it1!=it->second.end();it1++){
            
            if(it1==--(it->second.end()))
                std::cout<<*it1;
                
            else
            std::cout<<*it1<<",";
        }
        
        std::cout<<std::endl;
    }
    
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> mapa){
    
    std::set<int> skup;
    bool nadjena(false);
    
    for(int i(0);i<s.size();i++){
        if (s[i]>=65 && s[i]<=90)
        s[i]=s[i]+32;
    }
        
    
    for(auto it=mapa.begin();it!=mapa.end();it++){
        
        if(it->first==s){
            nadjena=true;
            skup=it->second;
        }
    }
    
    if(!(nadjena))
        throw std::logic_error ("Unesena rijec nije nadjena!");
    
    return skup;
}
int main ()
{
    std::string tekst;
    
    std::cout<<"Unesite tekst: ";
    getline(std::cin,tekst);
    
    auto mapa=KreirajIndeksPojmova(tekst);
    
    IspisiIndeksPojmova(mapa);
    
    
    
    for(;;){
        
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        
        getline(std::cin,rijec);
        
        
        if(rijec==".") break;
        
        else {
            
            try{
            auto skup=PretraziIndeksPojmova(rijec,mapa);
            
            for(auto i:skup) std::cout<<i<<" ";
            
            }
            
            catch(std::logic_error e){
                std::cout<<e.what();
            }
        }
        
        std::cout<<std::endl;
        
    }
    
	return 0;
}
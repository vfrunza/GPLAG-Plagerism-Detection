/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<string>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<stdexcept>
typedef std::map<std::string,std::set<int>> mapa;
mapa KreirajIndeksPojmova (std::string s){
    
    std::vector<std::pair<std::string,int>> v;
    int j;
    int k(0);
    for(int i=0;i<s.length();i++){
        
        if((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
           j=i;
           v.resize(k+1);
           v[k].second=j;
        }else continue;
        
        // std::cout<<j;
        
          // v[k].second=j;
         int br(0);
         for(;;){
           if((s[j]>='0' && s[j]<='9') || (s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')){
               
               v[k].first.push_back(std::tolower(s[j]));
               j++;
               br++;
               
           }else break;
           
         }
           k++;
    
        
        i=i+br-1;
        
    }
    
    mapa m;
    
  
        
    
    for(int i=0;i<v.size();i++){
        
        std::set<int> pomocni;
       int k(-1);
        pomocni.insert(v[i].second);
        for(int j=i+1;j<v.size();j++){
            
            
            if(v[i].first==v[j].first){
                
                
                pomocni.insert(v[j].second);
                k=j;
                
            }
        }
        if(i!=k){
        m.insert(std::make_pair(v[i].first,pomocni));
        
        }
    }
    
    return m;
    
}

std::set<int> PretraziIndeksPojmova(std::string s,mapa m){
    
    for(int i=0;i<s.length();i++){
        s[i]=std::tolower(s[i]);
    }
    
    
    auto it(m.find(s));
    
    if(it==m.end()) throw std::logic_error("Pojam nije nadjen");

    return it->second;
}

void IspisiIndeksPojmova(mapa m){
    for(auto it=m.begin();it!=m.end();it++){
       
        std::cout<<it->first<<": ";
        auto k(it->second.end());
        k--;
        for(auto p=it->second.begin();p!=it->second.end();p++){
            
            
            std::cout<<*p;
            if(k!=p)
            std::cout<<",";
           
        }
        std::cout<<std::endl;
        
    }
    
}



int main ()
{
    
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    auto m(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    
  for(;;){
    try{
    std::cout<<"Unesite rijec: ";
    std::string a;
    std::getline(std::cin,a);
    if(a!="."){
        auto p(PretraziIndeksPojmova(a,m));
        
        for(int x:p) std::cout<<x<<" ";
        std::cout<<std::endl;
        
        
    }else break;
    }catch(std::logic_error ){
        
        std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        
    }
    
 }
    
  
	return 0;
}
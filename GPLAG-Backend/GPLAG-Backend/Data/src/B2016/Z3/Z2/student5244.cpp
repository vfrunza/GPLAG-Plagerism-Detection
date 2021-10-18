/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector> 
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s){
    std::transform(s.begin(),s.end(),s.begin(),tolower);
    std::map<std::string, std::set<int>> mapa;
    std::vector<std::string> rijeci;
    int razmak(1);
    int i(0);
    while(i<s.length()){
        std::string temp;
        if(s[i]==' ') razmak=1;
        else if(razmak==1){
            razmak=0;
        }
        while(s[i]!=' ' &&  i<s.length() && ((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))){
            temp+=s[i];
            i++;
        }
        bool b(false);
        for(int i=0;i<rijeci.size();i++){
            if(rijeci[i]==temp){
                b=true;
                break;
            }
        }
        if(b==false && temp!=""){
            rijeci.push_back(temp);
        }
        i++; 
    }
    for(int i=0;i<rijeci.size();i++){
        std::set<int> indexi;
        for(int j=0;j<s.length();j++){
            std::string temp;
            int h=j;
            while((s[h]>='a' && s[h]<='z') || (s[h]>='0' && s[h]<='9')){
                temp+=s[h];
                h++;
                j++;
            }
            if(temp==rijeci[i]) indexi.insert(h-rijeci[i].length());
        }
        mapa.insert(std::make_pair(rijeci[i], indexi));
    }
    
   
    return mapa;
}

std::set<int>  PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa){
     std::transform(s.begin(),s.end(),s.begin(),tolower);
      auto it(mapa.find(s));
     if(!mapa.count(s)) throw std::logic_error("Pojam nije nadjen");
      return it->second;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa){
    auto it(mapa.begin());
    for(it=mapa.begin();it!=mapa.end();++it){
        std::cout<<it->first<<": ";
        std::set<int> set(it->second);
        std::set<int>::iterator ite;
        for(ite=set.begin();ite!=set.end();++ite){
            if(ite!=--set.end()) std::cout<<*ite<<",";
            else std::cout<<*ite;
        }
        std::cout<<std::endl;
    }
    /*for(auto x:mapa){
        std::cout<<x.first<<": ";
        auto it2=x.second.end();
        it2--;
        for(auto it=x.second.begin();it!=it2;it++){
            std::cout<<*it<<",";
        }
        std::cout<<*it2<<std::endl;
    }*/
}

int main ()
{  
        std::string s, rijec;
        std::cout<<"Unesite tekst: ";
        std::getline(std::cin, s);
        
        IspisiIndeksPojmova(KreirajIndeksPojmova(s));
        for(;;){
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, rijec);
            if(rijec==".") break;
            try{
                std::set<int> set(PretraziIndeksPojmova(rijec, KreirajIndeksPojmova(s)));
                std::set<int>::iterator it;
                for(it=set.begin();it!=set.end();++it){
                    if(it!=--set.end()) std::cout<<*it<<" ";
                    else std::cout<<*it<<std::endl;
                }
            }
            catch(std::logic_error e){
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
            
        }
    
    
	return 0;
}

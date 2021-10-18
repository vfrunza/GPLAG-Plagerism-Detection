/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <set>
#include <stdexcept>
void Pretvori(std::string &s){
    for(auto i=s.begin();i<s.end();i++){
        if(*i>='A' && *i<='Z')*i=*i+'a'-'A';
    }
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> m;

    auto poc=s.begin(),kraj=s.begin();
    while(*poc<'0' || (*poc>'9' && *poc<'A') || (*poc>'Z' && *poc<'a') || *poc>'z')poc++;
    for(auto p=s.begin();p<s.end();p++){
        if(p!=s.begin() && (*(p-1)<'0' || (*(p-1)>'9' && *(p-1)<'A') || (*(p-1)>'Z' && *(p-1)<'a') || *(p-1)>'z') && ((*p>='0' && *p<='9') || (*p>='A' && *p<='Z') || (*p>='a' && *p<='z')))poc=p;
        if(( ((*p>='0' && *p<='9') || (*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))  && p+1==s.end())   ||   ( ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z') || (*p>='0' && *p<='9'))  &&  (*(p+1)<'0' || (*(p+1)>'9' && *(p+1)<'A') || (*(p+1)>'Z' && *(p+1)<'a') || *(p+1)>'z'))){
            kraj=p;
                std::string pomocni;
                pomocni.resize(kraj-poc+1);
                    std::copy(poc,kraj+1,pomocni.begin());
                    int x(poc-s.begin());
                    Pretvori(pomocni);
                        if(!m.count(pomocni))m.insert(std::make_pair(pomocni,std::set<int>{x}));
                        else m[pomocni].insert(x);
        }    
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> m){
    if(!m.count(s))throw std::logic_error("Pojam nije nadjen");
    else return m[s];
}

void IspisiIndeksPojmova(const std::map<std::string,std::set<int>> &m){
    for(auto it=m.begin(); it!=m.end() ;it++){
        std::cout << it->first << ": ";
        int br(0);
        for(auto const i: it->second){
            if(br!=it->second.size()-1)std::cout << i <<",";
            else std::cout << i ;
            br++;
        }    
        std::cout << std::endl; 
    }
}

int main ()
{
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin,s);
        
        std::map<std::string,std::set<int>> map ;
        map=KreirajIndeksPojmova(s);
        
            IspisiIndeksPojmova(map);
                
                while(1){
                    std::string pomocni;
                    std::cout << "Unesite rijec: ";
                    std::cin >> pomocni;
                    if(pomocni==".")break;
                        try{
                            int br(0);
                            std::set<int> c;
                            c=PretraziIndeksPojmova(pomocni,map);
                            for(int const &i:c){
                                if(br==c.size()-1)std::cout << i ;
                                else std::cout << i << " ";
                                br++;
                            }    
                        }
                        catch(...){
                            std::cout << "Unesena rijec nije nadjena!";
                        }
                    std::cout << std::endl;    
                }
    return 0;
}
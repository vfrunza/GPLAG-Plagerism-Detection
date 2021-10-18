/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <set>
#include <algorithm>

bool slovoilibroj(char c) {
    if( (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') ) return true;
    return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(const std::string &s) {
    std::string s1;
    s1.resize(s.size());
    for(int i=0; i<s.size(); i++) {
        if(s[i]<'A' || s[i]>'Z') s1[i]=s[i];
        else s1[i]=s[i]+32;
    }
    std::map<std::string, std::set<int>> mapa;
    std::string rijec; int poc;
    for(int i=0; i<s1.size(); i++) { std::set<int> sk;
        if(slovoilibroj(s1[i])) { rijec.resize(0); poc=i; rijec.push_back(s1[i]); i++; 
            while(i<s.size() && slovoilibroj(s1[i])) { rijec.push_back(s1[i]); i++;
           // rijec=s.substr(poc, i);
            } 
            auto nadji(mapa.find(rijec));
                    if(nadji!=mapa.end()) {
                        nadji->second.insert(poc);
            }
            else {
                sk.insert(poc);
                mapa.insert(std::pair<std::string, std::set<int>>(rijec, sk));
            }
                }
                    }
return mapa;
}

std::set<int> PretraziIndeksPojmova(const std::string &s, std::map<std::string, std::set<int>> mapa) {
    std::set<int> skup;
    auto nadji(mapa.find(s));
    if(nadji==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!\n");
        skup=nadji->second;
        return skup;
}
    
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
        for(auto it=mapa.begin(); it!=mapa.end(); it++) {
            std::cout<<it->first<<": ";
            int i=0;
                for(auto x=it->second.begin(); x!=it->second.end(); x++) {
                    if(i!=it->second.size()-1) std::cout<<*x<<",";
                        else std::cout<<*x; i++;
                } std::cout<<std::endl;
                }
        }
int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
        
        for(;;) {
            std::string s1;
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, s1);
            if(s1==".") break;
                try {
                    auto nadji=PretraziIndeksPojmova(s1, mapa);
                        for(int x : nadji) std::cout<<x<<" ";
                        std::cout<<std::endl;
                        
                }
            catch(std::logic_error msg) {
                std::cout<<msg.what();
            }
            
            
        }
        return 0; }

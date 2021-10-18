/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <set>
#include <stdexcept>
int br_slova(std::string s){
    return std::count_if(s.begin(),s.end(),[](char x){bool vrati(false); if((x>='0' && x<='9') || (x>='A' && x<='Z') || (x>='a' && x<='z'))vrati=true; return vrati;});
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n){
    if(n<1 || n>v.size())throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    auto it(lista.begin());
    
    for(int i=0;i<v.size();i++){
        while(it!=lista.end())it++;
        lista.insert(it,v[i]);
    }
        int br(0),br_clanova(v.size()/n+1);
        std::vector<std::set<std::string>> v1;
        auto it1(lista.begin());  
        
        for(int i=0;i<n;i++){
            std::set<std::string> skup;
            if(br==v.size()%n)br_clanova--;
            
            for(int i=0;i<br_clanova;i++){
                skup.insert(*it1);
                auto it2(it1);
                int x=br_slova(*it1);
                
                for(int i=0;i<x;i++){
                    if(lista.size()==1){
                        skup.insert(*it1);
                        lista.erase(it1);
                        break;
                    }
                    it1++;
                    if(it1==lista.end())it1=lista.begin();
                    if(*it1==*it2)x++;
                }
                if(lista.size()!=0)lista.erase(it2);
                else break;
            }
            br++;
            v1.push_back(skup);
        }
    return v1;    
}

int main ()
{
    int n(0);
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    
        std::vector<std::string> v(n);
        std::cout << "Unesite imena djece: " << std::endl;
        std::cin.ignore(100,'\n');
        for(int i=0;i<n;i++) std::getline(std::cin,v[i]);
        
            int br_timova(0);
            std::cout << "Unesite broj timova: ";
            std::cin >> br_timova;
            try{
                std::vector<std::set<std::string>> v1;
                v1=Razvrstavanje(v,br_timova);
                
                    for(int i=0;i<v1.size();i++){
                        std::cout << "Tim " << i+1 << ": ";
                        int br(0);
                        for(auto x : v1[i]){
                            if(br==v1[i].size()-1)std::cout << x ;
                            else std::cout << x << ", ";
                            br++;
                        }    
                        std::cout << std::endl;
                    }
            }
            catch(std::logic_error e){
                std::cout << "Izuzetak: " <<  e.what();
            }
	return 0;
}
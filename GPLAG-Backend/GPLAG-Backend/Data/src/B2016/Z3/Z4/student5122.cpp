#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include <list>
#include <utility>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> s, int k){
    std::vector<std::set<std::string>> v;
    std::list<std::string> l;
    v.resize(k);
    auto it(l.begin());
    for(int i=0; i<s.size(); i++){
        ++it;
        l.push_back(s[i]);
        
    }
    int mod(s.size()%k);
    int n(s.size()/k);
    for(int i=0; i<k; i++){
        auto it(l.begin());
        if(i<mod){
            for(int j=0; j<n+1; j++){
                v[i].insert(*it);
                it=l.erase(it);
                if(it==l.end()){
                    it=l.begin();
                }
                int brojac=0, q=0;
                 for(int br=0; br<(*it).length(); br++){
                    it++; brojac++;
                    if(it==l.end()){
                    it=l.begin();
                    }
                }   
                }
        
            }else{
            for(int p=0; p<n; p++){
                v[i].insert(*it);
                it=l.erase(it);
                if(it==l.end()){
                    it=l.begin();
                }
                for(int br=0; br<((*it).length()); br++){
                    it++;
                    if(it==l.end()){
                        it=l.begin();
                    }
                }
            }
            }
        }return v;
    }
    

int main ()
{
    int n,k;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::vector<std::string> v;
    std::string rijec;
    for(int i=0; i<n; i++){
        std::cin>>rijec;
        v.push_back(rijec);
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>k;
    std::vector<std::set<std::string>> novi;
    novi=Razvrstavanje(v,k);
    int i=0;
    for(std::set<std::string> x:novi){
        i++;
        std::cout<<"Tim "<<i<<":";
        for(std::string y:x){
        std::cout<<y<<" ";
        }std::cout<<std::endl;
    }
	return 0;
}
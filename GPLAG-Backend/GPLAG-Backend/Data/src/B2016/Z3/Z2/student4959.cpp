/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> mapa;
    std::set<int> skup;
    auto it=s.begin();
    int br=0;
    for(int i=0;i<s.length();i++)
    {
    while(*it==' ') {it++;
    i++;
        br++;
    }
    auto it2=it;
    while(*it!=' '){
        i++;
        it++;
        
    }
        mapa.insert(std::make_pair(s.substr(*it2,*it),insert(br));
        continue;
    }
    
}
int main ()
{
	return 0;
}
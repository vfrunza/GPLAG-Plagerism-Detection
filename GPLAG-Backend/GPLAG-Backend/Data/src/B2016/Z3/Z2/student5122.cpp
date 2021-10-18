/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    std::set<int> skup{2,1};
    int brojac(0);
    int temp(0);
    for(int i=0; i<s.length(); i++){
        if(s[i]!=' '){ 
        brojac++;
        }
        if(s[i]==' ' || s[i]=='\n'){
        mapa.insert(std::make_pair(s.substr(temp,brojac),skup));
        temp=i;
        }
    }
    return mapa;
    
}

int main ()
{
    std::map<std::string, std::set<int>> mapa;
    std::string s;
    std::getline(std::cin,s);
    mapa=KreirajIndeksPojmova(s);
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first;
    }
	return 0;
}
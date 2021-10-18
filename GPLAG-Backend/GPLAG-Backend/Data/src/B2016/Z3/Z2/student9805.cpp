/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <iterator>

std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string string){
    std::map<std::string,std::set<int>> mapa;
    auto it=mapa.begin();
    std::string s;
    int poc=0;
    std::set<int> skup;
    for(int i=0;i<string.length();i++){
        if(s[i]==' '){
            s=s.substr(poc,s[i]);
            poc=s[i];
            it=mapa.find(s);
            mapa.insert (std::pair<std::string,std::set<int>>(s,skup));
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s1,std::map<std::string,std::set<int>> mapa){
    std::map<std::string,std::set<int>>::iterator iter=mapa.begin();
    iter=mapa.find(s1);
    return iter->second;
}
void IspisiIndeksPojmova (std::map<std::string,std::set<int>>mapa){
    std::map<std::string,std::set<int>>::iterator iter=mapa.begin();
    for(iter=mapa.begin();iter!=mapa.end();iter++){
        std::cout<<iter->first<<":";//<<":"<<iter->second<<std::endl;
    }
}

int main ()
{
    std::string string;
    std::cout<<"Unesite tekst: ";
    std::cin>>string;
    std::map<std::string,std::set<int>> mapa=KreirajIndeksPojmova(string);
    PretraziIndeksPojmova(string,mapa);
    //mapa.insert(std::pair<std::string,std::set<int>>("Sarajevo",{1,2,3}));
    //mapa.insert(std::pair<std::string,std::set<int>>("Mostar",{4,5,6,7}));
    IspisiIndeksPojmova(mapa);
	return 0;
}
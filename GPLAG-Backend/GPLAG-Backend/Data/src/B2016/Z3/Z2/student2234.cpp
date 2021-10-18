/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>

std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>>mapa;
    for(int i(0);i<s.length();i++){
        if(s[i]==' ')continue;
        std::string rijec;
        int br;
        if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) br=i;
        while((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
            if(s[i]>='A' && s[i]<='Z')s[i]=s[i]+32;
            rijec+=s[i];
            i++;
            if(i==s.length())break;
        }
        if(rijec!=""){
        auto it(mapa.find(rijec));
        if(it==mapa.end()){
        std::set<int>skup;
        skup.insert(br);
        mapa.insert(std::make_pair(rijec,skup));
        }
        else{
            it->second.insert(br);
        }
    }
    }
    return mapa;
}
std::set<int>PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>>mapa){
    std::set<int>skup;
    auto iterator(mapa.find(s));
    if(iterator==mapa.end())throw std::logic_error("Unesena rijec nije nadjena!");
    else{
        skup=iterator->second;
    }
    return skup;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    for(auto iterator=mapa.begin();iterator!=mapa.end();iterator++){
        std::cout<<iterator->first<<": ";
        std::set<int>skup(iterator->second);
        auto it(skup.begin());
        auto slon(skup.end());
        slon--;
        while(it!=slon){
            std::cout<<*it<<",";
            it++;
        }
        std::cout<<*it<<std::endl;
    }
}
int main ()
{   
    std::cout<<"Unesite tekst: ";
    std::string recenica;
    std::getline(std::cin,recenica);
    std::map<std::string,std::set<int>>pojmovi(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(pojmovi);
    while(1){
    std::cout<<"Unesite rijec: ";
    std::string rijec;
    std::getline(std::cin,rijec);
    if(rijec==".")break;
    std::set<int>grupa;
    try{
        grupa=PretraziIndeksPojmova(rijec,pojmovi);
        for(auto iterator=grupa.begin();iterator!=grupa.end();iterator++){
            std::cout<<*iterator<<" ";
        }
        std::cout<<std::endl;
    }
    catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    }
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <utility>

std::map<std::string, std::set<int> > KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int> > mapa;
    for (int i=0;i<s.size();i++){
        if (s[i]>='A' && s[i]<='Z')
            s[i]+=('a'-'A');
    }
    for (int i=0;i<s.size();i++){
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            int index(i);
            std::string pom;
            while ((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                pom.push_back(s[i]);
                i++;
            }
            auto it(mapa.find(pom));
            if (it==mapa.end())
                mapa.insert(std::pair<std::string,std::set<int>>(pom,{index}));
            else{
                (it->second).insert(index);
            }
        }
    }
    return mapa;
}



std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> ipojmova){
    std::set<int> skup;
    auto it(ipojmova.find(s));
    if (it == ipojmova.end())
        throw std::logic_error ("Pojam nije naden");
    else{
        skup=it->second;
    }
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string,std::set<int>> map){
    for(auto it=map.begin();it!=map.end();it++){
        std::cout << it->first << ": ";
        for (auto x=(it->second).begin();x!=(it->second).end();x++){
            if (x==--(it->second).end())
                std::cout << *x << " ";
            else std::cout << *x << ",";
        }
        std::cout << std::endl;
    }
}

int main ()
{   try{
        std::string tekst;
        std::cout << "Unesite tekst: ";
        std::getline(std::cin,tekst);
        auto m (KreirajIndeksPojmova(tekst));
      /*  for (auto x : m){
            std::cout << x.first << ": ";
            for (auto y : x.second)
                std::cout << y << " ";
            std::cout << std::endl;
        }*/
        IspisiIndeksPojmova(m);
        while(true){
            try{
            std::cout << "Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin,rijec);
            if (rijec==".")
                break;
            auto skup=PretraziIndeksPojmova(rijec,m);
            for (auto x : skup)
                std::cout << x << " ";
            std::cout << std::endl;
            } catch(std::logic_error e){
                std::cout << "Unesena rijec nije nadjena!" << std::endl;
            }
        }
    }
    catch(std::logic_error el){
        std::cout << el.what() << std::endl;
    }
	return 0;
}


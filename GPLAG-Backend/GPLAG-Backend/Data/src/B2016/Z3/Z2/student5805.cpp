#include <iostream>
#include <string>
#include<map>
#include <set>
#include <cctype>
#include <stdexcept>
bool NijeCh(char c){
    if((c>='a'&&c<='z')||(c>='0'&&c<='9'))  return false;
    return true;
    
}
std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> vrati;
    for(int i=0;i<s.length();i++){
        std::string pom;
        if(NijeCh(std::tolower(s[i])))    continue;
        int k(i);
        while(!NijeCh(std::tolower(s[i]))&&i!=s.length()){
            pom+=char(std::tolower(s[i]));
            i++;
        }
        vrati[pom].insert(k);
    }
    return vrati;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> mapa){
    for(int i=0;i<s.length();i++)
        s[i]=char(std::tolower(s[i]));
    if(!mapa.count(s))   throw std::logic_error("Pojam nije nadjen");
    return mapa[s];
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout<<it->first<<": ";
        auto k=it->second.begin();
        while(k!=it->second.end()){
            std::cout<<*k;
            k++;
            if(k==it->second.end()) break;
            std::cout<<",";
        }
        std::cout<<std::endl;
        
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::string pom;
    std::getline(std::cin, s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    do{
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, pom);
        if(pom==".") break;
        try{
            auto skupic(PretraziIndeksPojmova(pom,mapa));
            auto it(skupic.begin());
            while(it!=skupic.end())
                std::cout<<*it++<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error izuzetak){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }while(pom!=".");
	return 0;
}
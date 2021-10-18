/B2016/2017: Zadaća 3, Zadatak 2
#include <map>
#include <set>
#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>
bool slovoilicifra(char c){
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='1'&&c<='9')) return true;
    return false;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string const &s){
    std::map<std::string,std::set<int>> pojmovi;
    for(int i=0;i<s.size();i++){
        if(slovoilicifra(s[i])){
            int poc{i};
            std::string rijec;
            while(i<s.size()&&slovoilicifra(s[i])){
                if(s[i]>='A'&&s[i]<='Z') rijec.push_back(s[i]+('a'-'A'));
                else rijec.push_back(s[i]);i++;
            }
            auto it=pojmovi.find(rijec);
            if(it!=pojmovi.end()) it->second.insert(poc);
            else{
                std::set<int> skup; skup.insert(poc);
                pojmovi.insert(std::make_pair(rijec,skup));
            }
        }
    }
    return pojmovi;
}
std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>> pojmovi){
    auto it=pojmovi.find(rijec);
    if(it==pojmovi.end()) throw std::logic_error("Rijec nije nadjena!");
    else return it->second;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> pojmovi){
    auto it=pojmovi.begin();
    while(it!=pojmovi.end()){
        std::cout<<it->first<<": ";
        auto it2=it->second.begin();
        int i{};
        while(i!=it->second.size()-1){
            std::cout<<*it2++<<","; i++;
        }
        std::cout<<*it2<<std::endl;
        it++;
    }
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s; std::getline(std::cin,s);
    auto pojmovi=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(pojmovi);
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::string tmp; std::getline(std::cin,tmp);
        if(tmp==".") break;
        for(int i=0;i<tmp.size();i++) if(tmp[i]>='A'&&tmp[i]<='Z') tmp[i]+='a'-'A';
        try{
            auto s=PretraziIndeksPojmova(tmp,pojmovi);
            auto it=s.begin();
            while(it!=s.end())std::cout<<*it++<<" ";
            std::cout<<std::endl;
        } catch(std::logic_error e){
           std::cout<<e.what()<<std::endl;
        }
    }
    
    return 0;
}
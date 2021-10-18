/B2016/2017: Zadaća 3, Zadatak 2
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<iterator>
#include<stdexcept>

//prva funkcija
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<s.length(); i++){
        while(i<s.length() && !((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='1' && s[i]<='9')))
            i++;
        int pozicija(i);
        std::string pomocni;
        while(i<s.length() && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='1' && s[i]<='9'))){
            if(s[i]>='A' && s[i]<='Z')
                pomocni+=s[i++]+' ';
            else
                pomocni+=s[i++];
        }
        if(!mapa.count(pomocni)){
            mapa[pomocni];
            auto it(mapa.find(pomocni));
            it->second.insert(pozicija);
        }
        else{
            auto it(mapa.find(pomocni));
            it->second.insert(pozicija);
        }
    }
    return mapa;
}
//druga funkcija
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>>mapa){
    std::set<int> skup;
    auto it(mapa.find(s));
    if(it==mapa.end()){
        throw std::logic_error("Pojam nije nadjen");
    }
    else{
        skup=it->second;
    }
    return skup;
}
//treca funkcija
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto x: mapa){
        std::cout<<x.first<<": ";
        std::set<int>::iterator it(x.second.begin());
        for(; it!=--x.second.end(); it++)
            std::cout<<*it<<",";
        std::cout<<*it<<std::endl;
    }
}
int main (){
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> provjera(KreirajIndeksPojmova(s));
    try{
        for(auto x: provjera){
            std::set<int>skup (PretraziIndeksPojmova(x.first, provjera));
        }
        IspisiIndeksPojmova(provjera);
        std::string rijec;
        for(;;){
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, rijec);
            if(rijec==".")
                break;
            try{
                std::set<int> dodatni(PretraziIndeksPojmova(rijec, provjera));
                for(auto x: dodatni)
                    std::cout<<x<<" ";
                std::cout<<std::endl;
            }
            catch(...){
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;   
            }
        }
    }
    catch(...){
    }
	return 0;
}
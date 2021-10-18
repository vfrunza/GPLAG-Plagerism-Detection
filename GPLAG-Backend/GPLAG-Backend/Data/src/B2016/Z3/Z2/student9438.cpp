/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    std::string::iterator it(s.begin());
    int brojac(0);
    while(it!=s.end()){
        while(!(*it<='9'&&*it>='0')&&!(*it>='a'&&*it<='z')&&!(*it>='A'&&*it<='Z')){
            it++;
            if(it==s.end()) break;
            brojac++;
        }
        int pozicija(brojac);
        while((*it>='a'&&*it<='z')||(*it>='A'&&*it<='Z')||(*it>='0'&&*it<='9')){
            brojac++;
            it++;
        }
        std::string rijec(s.substr(pozicija,brojac-pozicija));
        mapa[rijec].insert(pozicija);
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa){
    if(mapa.find(rijec)==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    return mapa.find(rijec)->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto x: mapa){
        std::cout<<x.first<<": ";
        int i=0;
        for(int a: x.second){
            std::cout<<a;
            i++;
            if(i!=x.second.size()) std::cout<<",";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
   /* for(auto x: mapa){
        std::cout<<x.first<<": ";
        int i(0);
        for(int a: x.second){
            i++;
            std::cout<<a;
            if(i!=x.second.size()) std::cout<<",";
        }
        std::cout<<std::endl;
    }*/
    std::string rijec;
    while(rijec!="."){
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        if(rijec==".") break;
        try{
            std::set<int> skup(PretraziIndeksPojmova(rijec, mapa));
            for(auto x: skup) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch(...){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}
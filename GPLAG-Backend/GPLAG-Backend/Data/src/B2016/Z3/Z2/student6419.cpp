/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>
#include <utility>
std::string UMala(std::string tekst) {
    std::string str;
    for(int i(0); i<tekst.length(); i++) {
        if(tekst[i]>='A' && tekst[i]<='Z')
            str.push_back(tekst[i]+'a'-'A');
        else
            str.push_back(tekst[i]);
    }
    return str;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst1) {
    std::map<std::string, std::set<int>> mapa;
    auto tekst(UMala(tekst1));
    std::string pomocni;
    std::set<int> skup;
    for(int i(0); i<tekst.length(); i++) {
        if((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9')) 
            pomocni.push_back(tekst[i]);
        else if (pomocni.length()>0){
            skup.insert(i-pomocni.length());
            auto it(mapa.find(pomocni));
            if(it==mapa.end()) mapa.insert(std::make_pair(pomocni, skup));  //ako nema rijeci u mapi, ubacuje 
            else {                                                          //u suprotnom modificiramo samo skup
                it->second.insert(i-pomocni.length());
            }
            pomocni.clear();
            skup.clear();
        }
        if(i==tekst.length()-1) {
            skup.insert(i-pomocni.length()+1);
            auto at(mapa.find(pomocni));
            if(at==mapa.end()) mapa.insert(std::make_pair(pomocni, skup));
            else {
                at->second.insert(i-pomocni.length()+1);                    //dodao sam plus jedan kad je sama rijec izbacuje -1
            }
        }
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa) {
    std::set<int> skup;
    if(!mapa.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    else {
        auto it(mapa.find(rijec));                                              //for(auto x: mapa[rijec]) skup.insert(x), mozda moze
        for(auto x: it->second) skup.insert(x);
    }
    return skup;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {                           //std::map<std::string, std::set<int>>::iterator it = map.begin()
        int brojac(0); 
        std::cout << it->first << ": ";
        for(auto x: it->second) {
            brojac++;
            if(brojac==it->second.size())
                std::cout << x;
            else 
                std::cout << x << ",";
        }
        std::cout << std::endl;
    }
}
int main (){
    std::string tekst;
    std::map<std::string, std::set<int>> mapa;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    for(;;) {
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try {
            std::set<int> skup;
            rijec=UMala(rijec);
            skup=PretraziIndeksPojmova(rijec, mapa);
            for(auto x: skup) std::cout << x << " ";
            std::cout << std::endl;
        }
        catch(std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!";
            std::cout << std::endl;
        }
    }
	return 0;
}
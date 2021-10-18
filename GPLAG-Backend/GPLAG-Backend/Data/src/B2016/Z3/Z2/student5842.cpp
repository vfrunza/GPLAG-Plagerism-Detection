/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
typedef std::map<std::string, std::set<int>> IndeksMapa;
typedef std::set<int> IntSkup;

void PretvoriUMalaSlova (std::string &pom) {
    auto it=pom.begin();
    while(it!=pom.end()) {
        if((*it>='A') && (*it<='Z')) *it-='A'-'a';
        it++;
    }
}
IntSkup IndeksiRijeci(std::string recenica, std::string rijec) {
    IntSkup skup;
    for(int i(0); i<recenica.length(); i++) {
        int k(0);
        if(rijec[k]==recenica[i]) {
            while(rijec[k]==recenica[i+k]) {
                k++;
                if(k==rijec.length()) break;
            }
        }
        if(k==rijec.length() && (i==0 || (!(recenica[i-1]>='a' && recenica[i-1]<='z') && !(recenica[i-1]>='0' && recenica[i-1]<='9'))) && (i+k==recenica.length() || (!(recenica[i+k]>='a' && recenica[i+k]<='z') && !(recenica[i+k]>='0' && recenica[i+k]<='9')))) {
            skup.insert(i);
            i+=k;
        }
    }
    return skup;
}
IndeksMapa KreirajIndeksPojmova(std::string recenica) {
    PretvoriUMalaSlova(recenica);
    IndeksMapa indeks_pojmova;
    for(int i(0); i<recenica.length(); i++) {
        if((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='0' && recenica[i]<='9')) {
            std::string rijec;
            while((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='0' && recenica[i]<='9')) {
                rijec.push_back(recenica[i]);
                i++;
            }
            IntSkup skup=IndeksiRijeci(recenica, rijec);
            if(!indeks_pojmova.count(rijec)) indeks_pojmova.insert(std::make_pair(rijec, skup));
        }   
        if(i<recenica.length()) {
            while(!(recenica[i]>='a' && recenica[i]<='z') && !(recenica[i]>='0' && recenica[i]<='9')) {
                i++;
                if(i>=recenica.length()) break;
            }
            i--;
        }    
    }
    return indeks_pojmova;
}
IntSkup PretraziIndeksPojmova(std::string rijec, IndeksMapa mapa) {
    //PretvoriUMalaSlova(rijec);
    if(!mapa.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    IntSkup skup=mapa[rijec];
    return skup;    
}
void IspisiIndeksPojmova(IndeksMapa mapa) {
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        for(auto it2=(it->second).begin(); it2!=(it->second).end(); it2++) {
            std::cout<<*it2;
            auto it3=it2;
            if((++it3)!=(it->second).end()) std::cout<<",";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    try {
        std::string recenica;
        std::cout<<"Unesite tekst: ";
        std::getline(std::cin, recenica);
        IndeksMapa mapa=KreirajIndeksPojmova(recenica);
        IspisiIndeksPojmova(mapa);
        std::string rijec;
        for(;;) {
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, rijec);
            PretvoriUMalaSlova(rijec);
            if(rijec==".") break;
            if(!mapa.count(rijec)) std::cout<<"Unesena rijec nije nadjena!";
            else {
                IntSkup skup=PretraziIndeksPojmova(rijec, mapa);
                for(int x : skup) std::cout<<x<<" ";
            }
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}
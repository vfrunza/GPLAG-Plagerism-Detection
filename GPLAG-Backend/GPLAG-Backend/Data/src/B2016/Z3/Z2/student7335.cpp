/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>

int DaLiJePrekid(const char &slovo){
    if(!(slovo>='a' && slovo<='z') && !(slovo>='A' && slovo<='Z') && !(slovo>='0' && slovo<='9')) return -1; return 1;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string recenica){
    std::map<std::string, std::set<int>> index_pojmova;
    bool neslovo(1);
    for(int i=0; i<recenica.size(); i++){
        if(recenica.at(i)==' ') neslovo = true;
        else if(neslovo){
            neslovo = false;
            std::string rijec;
            int j(i);
            while(DaLiJePrekid(recenica.at(i)) > 0){
                rijec.push_back(recenica.at(i));
                i++;
                if(i==recenica.size()) break;
            }
            index_pojmova[rijec].insert(j);
            rijec.clear();
            i--;
        }
    }
    return index_pojmova;
}
std::set<int> PretraziIndeksPojmova(std::string kljuc, std::map<std::string, std::set<int>> mapa){
    auto it(mapa.find(kljuc));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    std::set<int> skup(it->second);
    return skup;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> index){
    for(auto it=index.begin(); it!=index.end(); it++){
        std::cout << it->first << ": ";
        auto it1(it->second.begin());
        for(int i=0; i<it->second.size(); i++){
            if(i==0) std::cout << *it1;
            else std::cout <<","<< *it1;
            it1++;
        }
        std::cout << std::endl;
    }
}
int main ()
{
    std::cout << "Unesite tekst: ";
    std::string recenica; std::getline(std::cin, recenica);
    std::map<std::string, std::set<int>> index(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(index);
    do{
        std::cout << "Unesite rijec: ";
        std::string rijec; std::getline(std::cin, rijec);
        for(int i=0; i<rijec.size(); i++) {if(rijec.at(i)=='.') return 0;}
        try{
            std::set<int> skup(PretraziIndeksPojmova(rijec, index));
            for(auto x:skup) std::cout << x<<" ";
            std::cout << std::endl;
            rijec.clear();
        }catch(std::logic_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
            rijec.clear();
        }
    }while(1);
	return 0;
}
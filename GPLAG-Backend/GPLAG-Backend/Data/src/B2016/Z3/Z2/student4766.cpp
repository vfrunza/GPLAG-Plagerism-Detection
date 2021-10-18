#include <iostream>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

bool isValid(char c){
    return ((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')); 
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string ss){
    std::map<std::string,std::set<int>> ret;
    std::string s(ss);
    std::for_each(s.begin(),s.end(), [](char &c){if(c >= 'A' && c <= 'Z') c+= 'a' - 'A';});
    for(int i = 0; i < s.length(); i++){
        while(i < s.length() && !isValid(s[i])) i++; int p(i);
        while(i < s.length() && isValid(s[i])) i++; int q(i);
        if(q-p)ret[s.substr(p,q-p)].insert(p);
    }
    return ret;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> m){
    std::for_each(s.begin(), s.end(), [](char &c){if(c >= 'A' && c <= 'Z') c += 'a'-'A';});
    if(m.find(s) == m.end()) throw std::logic_error("Pojam nije nadjen");
    return m[s];
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> m){
    for(auto it = m.begin(); it != m.end(); it++){
        std::cout << (*it).first << ": ";
        for(auto iter = (*it).second.begin(); iter != (*it).second.end(); iter++){
            auto tmp(iter); tmp++;
            if(tmp != (*it).second.end()) std::cout << *iter << ",";
            else std::cout << *iter;
        }    
        std::cout << std::endl;
    }
}
int main () {
    std::cout << "Unesite tekst: ";
    std::string s; std::getline(std::cin, s);
    auto indeks(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(indeks);
    for(;;){
        std::cout << "Unesite rijec: ";
        std::string tmp; std::getline(std::cin, tmp);
        if(tmp == std::string(".")) break;
        try{
            auto skup(PretraziIndeksPojmova(tmp,indeks));
            std::for_each(skup.begin(), skup.end(), [](int x){std::cout << x << " ";});
            std::cout << std::endl;
        }catch(std::logic_error err){
            std::cout << "Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}
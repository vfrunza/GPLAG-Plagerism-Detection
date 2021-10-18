/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>

std::string PretvoriUMalaSlova(std::string s){
    for(int i=0; i<s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
    return s;
}

std::map< std::string, std::set<int> > KreirajIndeksPojmova(std::string s){
    std::map< std::string, std::set<int> > m;
    bool a(true);
    for(int i=0; i<s.length(); i++){
        if(!((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')||(s[i]>='1' && s[i]<='9'))){
            a = true;
        }else if(a==true){
            a = false;
            int j;
            for(j=i; j<s.length(); j++){
                if(!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j]>='1' && s[j]<='9'))) break;
            }
            std::string pomocni(s.substr(i, j-i));
            pomocni = PretvoriUMalaSlova(pomocni);
            m[pomocni].insert(i);
            i = j-1;
        }
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m){
    auto it(m.begin());
    while(it != m.end()){
        if(it->first == s) break;
        it++;
    }
    if(it == m.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(std::map< std::string, std::set<int> > m){
    for(auto it = m.begin(); it != m.end(); it++){
        std::cout << it->first << ": ";
        for(auto p = it->second.begin(); p != it->second.end(); p++){
            if(p != --it->second.end()) std::cout << *p << ",";
            else std::cout << *p;
        }
        std::cout << std::endl;
    }
    
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    std::map < std::string, std::set<int> > m(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    while(true){
        try{
            std::cout << "Unesite rijec: ";
            std::string s1;
            std::getline(std::cin, s1);
            if(s1 == ".") break;
            std::set<int> skup(PretraziIndeksPojmova(s1, m));
            for(int x : skup) std::cout << x << " ";
        }catch(std::logic_error){
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout << std::endl;
    }
	return 0;
}
/B2017/2018: Zadaca 3, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <map>
#include <set>
#include <tuple>
#include <string>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

Knjiga PretvoriUMalaSlova(Knjiga s){
    for(auto it(s.begin()); it != s.end(); it++) {
        for(int i(0); i < it->second.size(); i++) {
            for(int j(0); j < it->second.at(i).length(); j++) {
                if(it->second.at(i).at(j) >= 'A' && it->second.at(i).at(j) <= 'Z') 
                    return s;
            }
        }
    }
}

std::map < std::string, std::set<std::tuple<std::string, int, int>> > KreirajIndeksPojmova(Knjiga s) {
    std::map <std::string, std::set<std::tuple<std::string, int, int>>> m;
    bool a(true);
    for(int i = 0; i < s.length(); i++) {
        if(!((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')||(s[i] >= '1' && s[i] <='9'))) {
                a = true;
        }else if( a == true){
            a = false;
            int j;
            for(j = i; j < s.length(); j++){
                if(!((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')||(s[i] >= '1' && s[i] <='9'))) break;
            }
            std::string pomocni(s.substr(i,j-i));
            pomocni = PretvoriUMalaSlova(pomocni);
            m[pomocni].insert(i);
            i = j-1;
            }
        }
        return m;
    }
    
std::set<int>PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int> > m){
    auto it(m.begin());
    while(it!=m.end()){
        if(it->first == s) break;
        it++;
    }
    if(it == m.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}


void IspisiIndeksPojmova(std::map< std::string, std::set<int> > m){
    for(auto it = m.begin(); it!= m.end(); it++){
        std::cout << it-> first << ":";
        for(auto p = it->second.begin(); p != it->second.end(); p++){
            if(p != --it-> second.end()) std::cout << *p << ",";
            else  std::cout << *p;
            
        }    
            std::cout << std::endl;
        
    }
}
int main (){
    std::cout <<"Unesite naziv poglavlja: ";
    std::string s;
    std::getline(std::cin,s);
    std::map < std::string, std::set<int> >m(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    while(true){
        try{
            std::cout << "Unesite rijec";
            std::string s1;
            std::getline(std::cin,s1);
            if(s1 == ".") break;
            std::set<int>skup(PretraziIndeksPojmova(s1,m));
            for(int x:skup) std::cout << x <<" ";
        }catch(std::logic_error){
            std::cout << "Unesena rijec nije nadjena!";
        }
           std::cout <<std::endl; 
            
        }
        return 0;
    }
    
	

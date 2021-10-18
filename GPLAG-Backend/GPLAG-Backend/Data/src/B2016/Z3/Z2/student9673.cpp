/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stdexcept>

std::string DajMala (std::string s){
    for(int i = 0; i < s.length(); i++) s[i]=std::tolower(s[i]);
    return s;
}

bool SlovoIliBroj(char znak){
    return (((znak>='a' && znak<='z') || (znak>='A' && znak<='Z')) || (znak>='0' && znak<='9'));
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> m;
    std::string rijec;
    bool TraziKraj(false), PomocniKraj(false), Iste(false);
    int pocetak, kraj;
    
    for(int i = 0; i < s.length(); i++){
        
        if(!TraziKraj && SlovoIliBroj(s[i]) && (i == 0 || !SlovoIliBroj(s[i-1]))){
            pocetak = i; TraziKraj = true;
            std::set<int> indexi;
            
            while(SlovoIliBroj(s[i]) && i < s.length()){
                rijec.push_back(s[i]); i++;
            }
            
            kraj = i;
            TraziKraj = false;
            auto it (m.find(rijec));
            
            if(it == m.end()){
                std::string pomoc;
                for (int j = kraj; j < s.length(); j++) {
                    int mjesto(0);
                
                    if(!PomocniKraj && SlovoIliBroj(s[j]) && (j == 0 || !SlovoIliBroj(s[j-1]))){
                        mjesto = j;
                        PomocniKraj = true;
            
                        while(SlovoIliBroj(s[j]) && j < s.length()){
                            pomoc.push_back(s[j]); j++;
                        }
                        
                        PomocniKraj = false; 
                        if (DajMala(rijec) == DajMala(pomoc)) {
                            Iste = true;
                            indexi.insert(mjesto); indexi.insert(pocetak);
                        }
                        pomoc.resize(0);
                    }
                    if(j == s.length()) break;
                }
                if(Iste) { m.insert(std::make_pair(DajMala(rijec), indexi)); Iste = false; }
                else { indexi.insert(pocetak); m.insert(std::make_pair(DajMala(rijec), indexi)); }
            }
            rijec.resize(0); 
        }
        if(i == s.length()) break;
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m){
    auto it (m.find(s));
    if(it == m.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m){
    
        for (auto it = m.begin(); it != m.end(); it++) {
            std::cout << it -> first << ": ";
            auto kraj (it -> second.end()); kraj--;
                for (auto it1 = it -> second.begin(); it1 != it -> second.end(); it1++) {
                    if(it1 == kraj) std::cout << *it1;
                    else std::cout << *it1 << ",";
                }
        std::cout << std::endl;
    }
}

int main(){
    std::string s;

    std::cout << "Unesite tekst: ";
    std::getline(std::cin, s);
    auto m(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    
    while(1){
        try{
            std::string t;
            std::cout << "Unesite rijec: ";
            std::getline(std::cin, t);
            if(t == ".") break;
            auto b (PretraziIndeksPojmova(t,m));
            for(auto x : b) std::cout << x << " "; 
            std::cout << std::endl;
        }
        catch(std::logic_error e){
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
    return 0;
}
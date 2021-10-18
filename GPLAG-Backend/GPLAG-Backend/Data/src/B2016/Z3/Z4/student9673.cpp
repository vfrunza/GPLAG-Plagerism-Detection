/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <list>
#include <stdexcept>

bool SlovoIliBroj(char znak){
    return (((znak>='a' && znak<='z') || (znak>='A' && znak<='Z')) || (znak>='0' && znak<='9'));
}

int BrojSlova(std::string s){
    int brojac(0);
    for(int i = 0; i < s.length(); i++) if(SlovoIliBroj(s[i])) brojac++;
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> s, const int k){
    if(k < 1 || k > s.size()) throw std::logic_error("Razvrstavanje nemoguce");

    std::list<std::string> raja;
    std::vector<std::set<std::string>> timovi(k);
    std::vector<int> velicine(k);
    int n(s.size()), v(n%k), krug(0), t(0);

    for(int i = 0; i < velicine.size(); i++) { if(i < v) velicine[i] = n/k + 1; else velicine[i] = n/k; }
    
    for(int i = 0; i < s.size(); i++) raja.push_back(s[i]);
    auto it (raja.begin());
    auto zadnji(raja.begin());
    
    while(1){
        if(timovi[0].size() == 0) { 
            timovi[t].insert(*it);
            krug = BrojSlova(*it) - 1;
            it = raja.erase(it);
        }
        if(timovi[t].size() == velicine[t]) t++;
        
        auto p(raja.begin()); 
        while(p != raja.end()) zadnji = p++; 
        
        for (int i = 0; i < krug; i++){
            if(it == zadnji) it = raja.begin(); 
            else it++; 
        }
        
        timovi[t].insert(*it);
        krug = BrojSlova(*it) - 1; 
        
        if(it == zadnji) {
            it = raja.erase(it); 
            it = raja.begin();
        }
        else it = raja.erase(it); 
        
        if(timovi[t].size() == velicine[t]) t++;
        if(raja.size() == 0) break;
    }
    
    return timovi;
}

int main ()
{
    std::vector<std::string> raja(0); 
    int n(0), br(0);
    
    std::cout << "Unesite broj djece: ";
    std::cin >> n; raja.resize(n);
    
    std::cin.ignore(1000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    for(int i = 0; i < n; i++) std::getline(std::cin, raja[i]);
    
    std::cout << "Unesite broj timova: "; std::cin >> br;
    try{
        auto timovi (Razvrstavanje(raja, br)); 
        for(int i = 0; i < timovi.size(); i++){
            std::cout << "Tim " << i+1 << ": ";
            for(auto it = timovi[i].begin(); it != timovi[i].end(); it++){
                auto kraj = timovi[i].end(); kraj--; 
                if(it != kraj) std::cout << *it << ", "; 
                else std::cout << *it;
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
	return 0;
}
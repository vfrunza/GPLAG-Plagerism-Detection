/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> mapa;
    int i{};
    for(int j = 0; j < s.length(); j++) {
        if(s[j] >= 'A' && s[j] <= 'Z') s[j] = s[j] + 32;
    }
    while(i < s.length()) {
        std::string pom;
        //if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'a' && s[i] <= 'z')) {
        while(((s[i] >= '!' && s[i] <= '/') || (s[i] > 'Z' && s[i] < 'a') || (s[i] > 'z' && s[i] <= '~' )) && i <s.length()) i++;
        while(((s[i] >= 'a' && s[i] <='z') || (s[i] >= '0' && s[i] <= '9')) && i < s.length()) {
            pom.push_back(s[i]);
            i++;
        }
        auto it(mapa.find(pom));
        if(it == mapa.end()) {
            std::set<int> skup;
            skup.insert(i - pom.length());
            mapa.insert(std::make_pair(pom, skup));
        }
        else{
            auto it(mapa.find(pom));
            it->second.insert(i - pom.length());
        }
        //std::cout << pom << std::endl;
        i++;
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa) {
    int nadjena{};
    std::set<int> skup;
    for(int j = 0; j < rijec.length(); j++) {
        if(rijec[j] >= 'A' && rijec[j] <= 'Z') rijec[j] = rijec[j] + 32;
    }
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
        if(it->first == rijec) {
            nadjena++;
            return it->second;
        }
    }
    if(nadjena == 0) throw std::logic_error("Unesena rijec nije nadjena!");
    return skup;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
        std::cout << it->first << ": ";
        int br{};
        for(int x : it->second) {
            if(br < it->second.size() - 1) std::cout << x << ",";
            else std::cout << x;
            br++;
              
        }
        std::cout << std::endl;
    }
}


int main ()
{
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    for(;;){
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::cin >> rijec;
        if(rijec == ".") break;
        try{
        std::set<int> skup(PretraziIndeksPojmova(rijec, mapa));
        for(int x: skup) std::cout << x << " ";
        std::cout << std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    //AT16 (zamger): random stuff 
    /*auto m = KreirajIndeksPojmova("cvbkn34m5.n,34r67fgudbsc$%&/I()HVBNBn/&/&n///z&asdb23rgf87baew bfcQN3RCG3BR83O4NZTH");
    IspisiIndeksPojmova(m);
    auto skup = PretraziIndeksPojmova("n", m);
    for (const auto &c : skup) std::cout << c << " ";*/
	return 0;
}
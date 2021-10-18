/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int BrojSlova(std::string s){
    int i(0), brojac(0);
    while(i!=s.length()){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            brojac++;
        i++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> s, int brojTimova) {
    if(brojTimova<1 || brojTimova>s.size()) {
        throw std::logic_error ("Razvrstavanje nemoguce");
    }
    
    std::list<std::string> l(s.begin(), s.end());
    std::vector<std::set<std::string>> p(brojTimova);

    int razvrstano(0), korak(0), tim(0), max;
    std::list<std::string>::iterator klizac(l.begin());
    while (razvrstano != s.size()) {
        while (korak != 0) {
            korak--;
            klizac++;
            if (klizac == l.end()) {
                klizac = l.begin();
            } 
        }
        p[tim].insert(*klizac);
        
        if ((tim+1) <= (s.size() % brojTimova)) {
            max = s.size() / brojTimova + 1;
        } else {
            max = s.size() / brojTimova ;
        }
        
        if (p[tim].size() == max) {
            tim++;
        }
        razvrstano++;

        korak = BrojSlova(*klizac) - 1;
        auto pom(klizac);
        klizac++;
        if (klizac == l.end()) {
            klizac = l.begin();
        }
        l.erase(pom);
    }
    return p;
}

int main ()
{
    try {
        int n, m;
        std::vector<std::string> s;
        std::cout<<"Unesite broj djece: ";
        std::cin>> n;
        std::cin.ignore(100, '\n');
        std::cout<<"Unesite imena djece: "<<std::endl;
        s.resize(n);
        for(int i=0; i<n; i++){
            getline(std::cin,s[i]);
        }
        std::cout<<"Unesite broj timova: ";
        std::cin>> m;
        std::vector<std::set<std::string>> p = Razvrstavanje(s, m);
        for (int i = 0; i < p.size(); i++) {
            std::string ispis = "Tim " + std::to_string(i+1) + ": ";
            for (auto x : p[i]) {
                ispis += x + ", ";
            }
            std::cout << ispis.substr(0, ispis.length()-2) << std::endl;
        }
        
    } catch(std::logic_error error) {
        std::cout<<"Izuzetak: "<<error.what();
    }
	return 0;
}
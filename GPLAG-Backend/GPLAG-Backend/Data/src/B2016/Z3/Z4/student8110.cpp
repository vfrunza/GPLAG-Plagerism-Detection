/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stdexcept> 

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int k) {
    std::vector<int> clanovi;
    int n = imena.size();
    if(k < 1 || k > n) throw std::logic_error("Razvrstavanje nemoguce");
    int x = n%k, y=n/k;
    for(int i=0; i<x; i++) clanovi.push_back(y+1);
    for(int i=x; i<k; i++) clanovi.push_back(y);
    
    std::list<std::string> djeca;
    for(auto x : imena) djeca.push_back(x);
    
    std::vector<std::set<std::string>> timovi;
    std::set<std::string> tim;
    
    auto it = djeca.begin();
    tim.insert(*it);
    clanovi[0]--;
    
    for(int i=0; i<k; i++) {
        if(i!=0) tim = {};
        for(int j=0; j<clanovi[i]; j++) {
            int duzina_imena(0);
            std::string ime = *it;
            for(int l=0; l<ime.length(); l++) 
                if((ime[l]>='a' && ime[l]<='z') || (ime[l]>='A' && ime[l]<='Z') || (ime[l]>='0' && ime[l]<='9')) duzina_imena++;
            it = djeca.erase(it);
            it--;
            while(duzina_imena!=0) {
                it++;
                duzina_imena--;
                if(it == djeca.end()) it = djeca.begin();
            }
            tim.insert(*it);
        }
        timovi.push_back(tim);
    }
    return timovi;
}

int main () {
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> imena;
    for(int i=0; i<n; i++) {
        std::string ime;
        std::cin >> std::ws;
        std::getline(std::cin, ime);
        imena.push_back(ime);
    }
    int k;
    std::cout << "Unesite broj timova: ";
    std::cin >> k;
    try{
    auto timovi = Razvrstavanje(imena, k);
    for(int i=0; i<k; i++) {
        std::cout << "Tim " << i+1 << ": ";
        auto it2 = timovi[i].end();
        it2--;
        for(auto it = timovi[i].begin(); it!=it2; it++) std::cout << *it << ", ";
        std::cout << *it2;
        std::cout << std::endl;
    }
    } catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
	return 0;
}
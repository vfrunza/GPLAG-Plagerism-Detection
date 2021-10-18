/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int brojtimova) {
    std::vector<std::set<std::string>> timovi;
    std::list<std::string> listaimena;
    std::set<std::string> skup;
    for(int i(0); i<imena.size(); i++) 
        listaimena.push_back(imena[i]);
    if(brojtimova<1 || brojtimova>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int mod(imena.size()%brojtimova);
    int cijeli(imena.size()/brojtimova);
    auto it=listaimena.begin();
    for(int i(0); i<mod; i++) {
        timovi.push_back(skup);
        for(int j(0); j<cijeli+1; j++) {
            std::string imeduzina(*it);
            int duzina(0);
            for(int i(0); i<imeduzina.length(); i++) 
                if((imeduzina[i]>='A' && imeduzina[i]<='Z') || (imeduzina[i]>='a' && imeduzina[i]<='z') || (imeduzina[i]>='0' && imeduzina[i]<='9')) duzina++;
            if(listaimena.size()==imena.size()) {
                timovi[i].insert(*it);
                it=listaimena.erase(it);
                if(it==listaimena.end()) {
                    while(it!=listaimena.begin()) it--;
                }
                do {
                    duzina--;
                    it++;
                    if(it==listaimena.end()) {
                        while(it!=listaimena.begin()) it--;
                    }
                }while(duzina>1);
            }
            else {
                timovi[i].insert(*it);
                it=listaimena.erase(it);
                if(it==listaimena.end()) {
                    while(it!=listaimena.begin()) it--;
                }
                do {
                    duzina--;
                    it++;
                    if(it==listaimena.end()) {
                        while(it!=listaimena.begin()) it--;
                    }
                }while(duzina>1);
            }
        }
    }
    if(mod>cijeli) {
        for(int i(mod); i<brojtimova; i++){
            timovi.push_back(skup);
            for(int j(0); j<cijeli; j++) {
                std::string imeduzina(*it);
                int duzina(0);
                for(int i(0); i<imeduzina.length(); i++)
                    if((imeduzina[i]>='A' && imeduzina[i]<='Z') || (imeduzina[i]>='a' && imeduzina[i]<='z') || (imeduzina[i]>='0' && imeduzina[i]<='9')) duzina++;
                if(listaimena.size()==imena.size()) {
                    timovi[i].insert(*it);
                    it=listaimena.erase(it);
                    if(it==listaimena.end()) {
                        while(it!=listaimena.begin()) it--;
                    }
                    do {
                        duzina--;
                        it++;
                        if(it==listaimena.end()) {
                            while(it!=listaimena.begin()) it--;
                        }
                    }while(duzina>1);
                }
                else {
                    timovi[i].insert(*it);
                    it=listaimena.erase(it);
                    if(it==listaimena.end()) {
                        while(it!=listaimena.begin()) it--;
                    }
                    do {
                        duzina --;
                        it++;
                        if(it==listaimena.end()) {
                            while(it!=listaimena.begin()) it--;
                        }
                    }while(duzina>1);
                }
            }
        }
    }
    else if(mod==0) {                                                           //potrebno jos dodat uslov ukliko je modulo veci cijelog dijela...dodao
        for(int i(mod); i<brojtimova-mod; i++) {
            timovi.push_back(skup);
            for(int j(0); j<cijeli; j++) {
                std::string imeduzina(*it);                                     // uveo, ukoliko imena imaju razmak 
                int duzina(0);
                for(int i(0); i<imeduzina.length(); i++)
                    if((imeduzina[i]>='A' && imeduzina[i]<='Z') || (imeduzina[i]>='a' && imeduzina[i]<='z') || (imeduzina[i]>='0' && imeduzina[i]<='9')) duzina++;
                if(listaimena.size()==imena.size()) {
                    timovi[i].insert(*it);
                    it=listaimena.erase(it);
                    if(it==listaimena.end()) {                                      //dodao
                        while(it!=listaimena.begin()) it--;
                    }   
                    do {
                        duzina--;
                        it++;
                        if(it==listaimena.end()) {
                            while(it!=listaimena.begin()) it--;
                        }
                    }while(duzina>1);
                }
                else {
                    timovi[i].insert(*it);
                    it=listaimena.erase(it);
                    if(it==listaimena.end()) {                                      //dodao
                        while(it!=listaimena.begin()) it--;
                    }
                    do {
                        duzina--;
                        it++;
                        if(it==listaimena.end()) {
                            while(it!=listaimena.begin()) it--;
                        }
                    }while(duzina>1);
                }
            }
        }
    }
    else {
        for(int i(mod); i<brojtimova-mod+1; i++) {
            timovi.push_back(skup);
            for(int j(0); j<cijeli; j++) {
                std::string imeduzina(*it);
                int duzina(0);
                for(int i(0); i<imeduzina.length(); i++)
                    if((imeduzina[i]>='A' && imeduzina[i]<='Z') || (imeduzina[i]>='a' && imeduzina[i]<='z') || (imeduzina[i]>='0' && imeduzina[i]<='9')) duzina++;
                if(listaimena.size()==imena.size()) {
                    timovi[i].insert(*it);
                    it=listaimena.erase(it);
                    if(it==listaimena.end()) {
                        while(it!=listaimena.begin()) it--;
                    }
                    do {
                        duzina--;
                        it++;
                        if(it==listaimena.end()) {
                            while(it!=listaimena.begin()) it--;
                        }
                    }while(duzina>1);
                }
                else {
                    timovi[i].insert(*it);
                    it=listaimena.erase(it);
                    if(it==listaimena.end()) { 
                        while(it!=listaimena.begin()) it--;
                    }
                    do {
                        duzina--;
                        it++;
                        if(it==listaimena.end()) {
                            while(it!=listaimena.begin()) it--;
                        }
                    }while(duzina>1);
                }
            }
        }
    }
    return timovi;
}
int main (){
    int brojdjece, brojtimova;
    std::string ime;
    std::vector<std::string> imena;
    std::cout << "Unesite broj djece: ";
    std::cin >> brojdjece;
    std::cout << "Unesite imena djece: " << std::endl;
    std::cin.ignore(10000,'\n');
    for(int i(0); i<brojdjece; i++) {
        std::getline(std::cin, ime);
        imena.push_back(ime);
        ime.clear();
    }
    std::cout << "Unesite broj timova: ";
    std::cin >> brojtimova;
    try {
        auto timovi=Razvrstavanje(imena, brojtimova);
        for(int i(0); i<timovi.size(); i++) {
            int brojac(0);
            std::cout << "Tim " << i+1 << ": ";
            for(auto x: timovi[i]) {
                brojac++;
                if(brojac==timovi[i].size()) 
                    std::cout << x;
                else
                    std::cout << x << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}
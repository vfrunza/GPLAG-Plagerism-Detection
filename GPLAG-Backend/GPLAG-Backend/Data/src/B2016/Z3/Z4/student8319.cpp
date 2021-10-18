/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k) {
    if(k < 1 || k > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n(v.size());
    std::vector<std::set<std::string>> rezz(k);
    int prvi(n%k);
    int broj(n/k);
    //std::cout << prvi << std::endl;
    //std::cout << broj;
    std::list<std::string> lista;
    for(int i = 0; i < n; i++) {
        std::string pom;
        pom = v[i];
        lista.push_back(pom);
    }
    //for(auto it=lista.begin(); it != lista.end(); it++) std::cout << it->size() << " ";
    int velicina(1);
    auto it = lista.begin();
    for(int i = 0; i < rezz.size(); i++) {
        std::set<std::string> pom;
        if(prvi == 0) {
            for(int j = 0; j < broj; j++) {
                for(int k = 0; k < velicina - 1; k++) {
                    it++;
                    if(it == lista.end()) {
                        it = lista.begin();
                    }
                }
                //std::cout << "Upisuje se: " << *it << " ";
                pom.insert(*it);
                velicina = it->size();
                std::string pomocni;
                pomocni = *it;
                //std::cout << pomocni << std::endl;
                for(int l = 0; l < pomocni.size(); l++) {
                    if(pomocni[l] == ' ' || pomocni[l] == '-' || pomocni[l] == '/') velicina--;
                }
                auto pom(lista.begin());
                //for(std::string s:lista) std::cout << s << " ";
                //std::cout << std::endl;
                for(int s = 1; s < lista.size(); s++) {
                    if(s > lista.size()) break;
                    pom++;
                    //std::cout << *pom << std::endl;
                }
                if(*it == *pom) {
                    //std::cout << "aa: " << *pom << " " << *it << std::endl;
                    it = lista.erase(it);
                    it = lista.begin();
                    //velicina--;
                    //std::cout << "na pocetku liste: " << *it << std::endl;
                }
                else{
                    it = lista.erase(it);
                }
                //std::cout << velicina << std::endl;
            }
        }
        if(i >= 0 && i < prvi) {
            for(int j = 0; j < broj + 1; j++) {
                for(int k = 0; k < velicina - 1; k++) {
                    //if(broj < lista.size()) break;
                    it++;
                    if(it == lista.end()) {
                        it = lista.begin();
                        //k++;
                    }
                }
                //std::cout << *it << " ";
                pom.insert(*it);
                velicina = it->size();
                std::string pomocni;
                pomocni = *it;
                for(int l = 0; l < pomocni.size(); l++) {
                    if(pomocni[l] == ' ' || pomocni[l] == '-' || pomocni[l] == '/') velicina--;
                }
                auto pom(lista.begin());
                //std::cout << lista.size() << std::endl;
                for(int s = 1; s < lista.size(); s++) {
                    if(s > lista.size()) break;
                    pom++;
                }
                //std::cout << "zadnji u listi: " << *pom << std::endl;
                if(*it == *pom) {
                    //std::cout << "aaaa";
                    it = lista.erase(it);
                    it = lista.begin();
                }
                else {
                    it=lista.erase(it);
                }
                //std::cout << *it << std::endl;
            }
        }
        //std::cout << *it << std::endl;
        
        if(i >= prvi && i < rezz.size() && prvi != 0) {
            for(int j = 0; j < broj; j++) {
                for(int k = 0; k < velicina - 1; k++) {
                    it++;
                    if(it == lista.end()) {
                        it = lista.begin();
                        //k++;
                    }
                }
                //std::cout << "Upisuje se: " << * it << std::endl;
                pom.insert(*it);
                velicina = it->size();
                std::string pomocni;
                pomocni = *it;
                for(int l = 0; l < pomocni.size(); l++) {
                   if(pomocni[l] == ' ' || pomocni[l] == '-' || pomocni[l] == '/') velicina--;
                }
                auto pom(lista.begin());
                for(int s = 1; s < lista.size(); s++) {
                    if(s > lista.size()) break;
                    pom++;
                }
                if(*it == *pom) {
                    //std::cout << "aaaa";
                    it = lista.erase(it);
                    it = lista.begin();
                }
                else {
                    it=lista.erase(it);
                }
            }
        }
        rezz[i] = pom;
    }
        return rezz;
}

int main ()
{
    try{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    std::cout << "Unesite imena djece: " << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    for(int i = 0; i < v.size(); i++) {
        std::string ime;
        std::getline(std::cin, ime);
        //std::cout << ime << std::endl;
        v[i] = ime;
    }
    //for(std::string s:v) std::cout << s << std::endl;
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin >> k;
        std::vector<std::set<std::string>> timovi(Razvrstavanje(v, k));
        for(int i = 0; i < timovi.size(); i++) {
            std::cout << "Tim " << i + 1 << ": ";
            int br{};
            for(std::string s: timovi[i]) {
                if(br < timovi[i].size() - 1) std::cout << s << ", ";
                else std::cout << s;
                br++;
            }
        std::cout << std::endl;
        }
    }
    catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}
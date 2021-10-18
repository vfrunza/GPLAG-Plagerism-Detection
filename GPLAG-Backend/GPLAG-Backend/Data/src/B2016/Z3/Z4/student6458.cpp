/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <vector>
#include <set>

bool RijecBrojProvjera (char s) {
    if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) return true;
    return false;
}

bool OstaoJedan(std::list<std::string> l) {
    if (l.size() == 1) return true;
    return false;
}

int DajBrojSlova (std::string ime) {
    std::string::iterator it(ime.begin());
    int brojac(0);
    while (it != ime.end()) {
        if (RijecBrojProvjera(*it)) brojac++;
        it++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> spisak_imena, int timovi) {
    std::list<std::string> imena(spisak_imena.size());
    std::vector<std::set<std::string>> skup_timova(timovi);
    std::list<std::string>::iterator it(imena.begin());
    for (int i = 0; i < spisak_imena.size(); i++) {
        *it = spisak_imena[i];
        it++;
    }
    it = imena.begin();
    if (timovi < 1 || imena.size() < timovi) throw std::logic_error ("Razvrstavanje nemoguce");
    int regularnost(imena.size() % timovi);
    int br_clanova(0);
    int uk_djece(imena.size());
    int br_slova(0);
    for (int i = 0; i < timovi; i++) {
        if (regularnost != 0) {
            if (i < regularnost) br_clanova = uk_djece / timovi + 1;
            else br_clanova = uk_djece / timovi;
            while (br_clanova > 0) {
                if (OstaoJedan(imena)) {
                    it = imena.begin();
                    skup_timova[i].insert(*it);
                    it = imena.erase(it);
                    break;
                }
                skup_timova[i].insert(*it);
                br_slova = DajBrojSlova(*it);
                it = imena.erase(it);
                if (it == imena.end()) it = imena.begin();
                for (int j = 0; j < br_slova - 1; j++) {
                    it++;
                    if (it == imena.end()) it = imena.begin();
                }
                br_clanova--;
            }
        }
        else {
            br_clanova = uk_djece / timovi;
            while (br_clanova > 0) {
                if (OstaoJedan(imena)) {
                    it = imena.begin();
                    skup_timova[i].insert(*it);
                    it = imena.erase(it);
                    break;
                }
                skup_timova[i].insert(*it);
                br_slova = DajBrojSlova(*it);
                it = imena.erase(it);
                if (it == imena.end()) it = imena.begin();
                for (int j = 0; j < br_slova - 1; j++) {
                    it++;
                    if (it == imena.end()) it = imena.begin();
                }
                br_clanova--;
            }
        }
        //else br_clanova = uk_djece / timovi;
        
        /*while (br_clanova > 0) {
            if (imena.size() == 1) {
                it = imena.begin();
                skup_timova[i].insert(*it);
                it = imena.erase(it);
                break;
            }
            br_slova = DajBrojSlova(*it);
            std::cout << *it << "   " << br_slova << std::endl;
            skup_timova[i].insert(*it);
            it = imena.erase(it);
            while (br_slova > 0) {
                it++;
                br_slova--;
                if (it == imena.end() && br_slova >= 1) {
                    it = imena.begin();
                    br_slova--;
                }
            }
            br_clanova--;
        }*/
    }
    return skup_timova;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> v;
    std::string s;
    std::cin.ignore(10000, '\n');
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, s);
        v.push_back(s);
    }
    std::cout << std::endl;
    std::cout << "Unesite broj timova: ";
    int br_timova;
    std::cin >> br_timova;
    try {
        //std::cout << "U Mainu: " << v.size() << std::endl;
        std::vector<std::set<std::string>> timovi(Razvrstavanje(v, br_timova));
        for (int i = 0; i < br_timova; i++) {
            int brojac(0);
            std::cout << "Tim " << i+1 << ": ";
            for (auto x : timovi[i]) {
                brojac++;
                if (brojac == timovi[i].size()) std::cout << x;
                else std::cout << x << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error e) {
        std::cout << e.what();
    }
    
	return 0;
}
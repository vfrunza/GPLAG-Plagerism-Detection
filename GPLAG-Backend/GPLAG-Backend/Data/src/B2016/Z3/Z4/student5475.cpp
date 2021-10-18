#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
#include <iterator>

typedef std::vector<std::string> VStringova;
typedef std::vector<std::multiset<std::string>> VSkupova;

int BrKoraka(std::string s) {
    if(s.size() == 0) return 0;
    int br(0);
    for(char c : s) {
        c = std::toupper(c);
        if((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) br++;
    }
    if(br != 0) br--;
    return br;
}
VSkupova Razvrstavanje(const VStringova &imena, int br_timova) {
    if(br_timova < 1 || br_timova > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> l;
    for(std::string x : imena)
        if(x.size() != 0) l.push_back(x);
    auto it(l.begin());
    VSkupova v;
    int koraci(0), k(imena.size() / br_timova), ima_prvih(imena.size() % br_timova);
    while(br_timova-- != 0) {
        int kapacitet(k);
        if(ima_prvih) {
            kapacitet++; ima_prvih--;
        }
        std::multiset<std::string> skup;
        while(!l.empty() && skup.size() != kapacitet) {
            while(koraci != 0) {
                it++; koraci--;
                if(it == l.end()) it = l.begin();
            }
            skup.insert(*it);
            koraci = BrKoraka(*it);
            it = l.erase(it);
            if(!l.empty() && it == l.end()) it = l.begin();
        }
        v.push_back(skup);
    }
    return v;
}
void Ispisi(std::multiset<std::string> skup) {
    for(auto it = skup.begin(); it != skup.end(); it++) {
        if(it == --skup.end()) std::cout << *it;
        else std::cout << *it << ", ";
    }
    std::cout << std::endl;
}
int main () {
    int n, br_timova;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cin.ignore(1000, '\n');
    VStringova imena(n);
    std::cout << "Unesite imena djece: " << std::endl;
    for(std::string &ime : imena) std::getline(std::cin, ime);
    std::cout << "Unesite broj timova: ";
    std::cin >> br_timova;
    try {
        VSkupova v(Razvrstavanje(imena, br_timova));
        for(int i=0; i<v.size(); i++) {
            std::cout << "Tim " << i+1 << ": ";
            Ispisi(v[i]);
        }
    }
    catch(std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}
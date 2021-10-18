#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <iterator>

typedef std::vector<std::string> VStringova;
typedef std::vector<std::multiset<std::string>> VSkupova;

struct Dijete {
    std::string ime;
    Dijete *sljedeci = nullptr;
};
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
VSkupova Razvrstavanje(const VStringova &vs, int br_timova) {
    if(br_timova < 1 || br_timova > vs.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *poc(nullptr), *temp(nullptr);
    VSkupova v;
    VStringova imena;
    for(int i=0; i<vs.size(); i++) 
        if(vs[i].size()) imena.push_back(vs[i]);
    if(!imena.size()) return v;
    for(int i=0; i<imena.size(); i++) {
        Dijete *novi(new Dijete);
        novi->ime = imena[i]; novi->sljedeci = nullptr;
        if(!poc) poc = novi;
        else temp->sljedeci = novi;
        temp = novi;
    }
    temp->sljedeci = poc;
    auto it(poc);
    int koraci(0), k(imena.size() / br_timova), ima_prvih(imena.size() % br_timova);
    while(br_timova-- != 0) {
        int kapacitet(k);
        if(ima_prvih) {
            kapacitet++; ima_prvih--;
        }
        std::multiset<std::string> skup;
        while(kapacitet != skup.size()) {
            if(it->sljedeci == it) {
                skup.insert(it->ime);
                v.push_back(skup);
                delete it;
                return v;
            }
            while(koraci != 0) {
                it = it->sljedeci; 
                koraci--;
            }
            skup.insert(it->ime);
            koraci = BrKoraka(it->ime);
            auto pok(it);
            while(pok->sljedeci != it) 
                pok = pok->sljedeci;
            pok->sljedeci = it->sljedeci;
            delete it;
            it = pok->sljedeci;
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
        for(int i=0; i<br_timova; i++) {
            std::cout << "Tim " << i+1 << ": ";
            if(i < v.size()) Ispisi(v[i]);
            std::cout << std::endl;
        }
    }
    catch(std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}
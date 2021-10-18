/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <algorithm>
#include <list>

using std::logic_error;

int brojslova(std::string s) {
    return std::count_if(s.begin(), s.end(), [](char c){return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');});
}

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};

Dijete *dajprethodni(Dijete *poc, Dijete *koji){
    for (;;poc = poc -> sljedeci) {
        if (poc -> sljedeci == koji) return poc;
    }
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vs, int k) {
    if (k > vs.size() || k < 1) throw logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> vss(k);
    if (vs.size() == 0) return vss;
    Dijete *poc, *sadasnji;
    poc = new Dijete {vs[0], nullptr};
    sadasnji = poc;
    for (int i = 1; i < vs.size(); i++) {
        sadasnji -> sljedeci = new Dijete {vs[i], nullptr};
        sadasnji = sadasnji -> sljedeci;
    }
    sadasnji -> sljedeci = poc;
    sadasnji = poc;
    int trenutnitim(0), velicina(vs.size() / k);
    if (trenutnitim < vs.size() % k) velicina++;
    int b(0);
    while (b < vs.size()) {
        if(vss[trenutnitim].size() == velicina) {
            trenutnitim++;
            velicina = vs.size() / k;
            if (trenutnitim < vs.size() % k) velicina++;
        }
        vss[trenutnitim].insert(sadasnji -> ime);
        int bslova(brojslova(sadasnji -> ime));
        Dijete *prethodni = dajprethodni(sadasnji, sadasnji);
        prethodni -> sljedeci = sadasnji -> sljedeci;
        delete sadasnji;
        if (b + 1 < vs.size()) {
            sadasnji = prethodni -> sljedeci;
            for (int i = 1; i < bslova; i++) {
                sadasnji = sadasnji -> sljedeci;
            }
        }
        b++;
    }
    return vss;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> vs(n);
    for (int i = 0; i < n; i++)
        std::getline(std::cin, vs[i], '\n');
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin >> k;
    try {
        std::vector<std::set<std::string>> vss=Razvrstavanje(vs, k);
        int b(1);
        for (auto i = vss.begin(); i != vss.end(); i++, b++) {
            std::cout << "Tim " << b << ":";
            auto it (i->begin());
            if (it != (i->end())) it++;
            for (auto j = (i -> begin()); j != (i -> end()); j++) {
                std::cout << " " << *j;
                if (it != (i->end())) {
                    it++;
                    std::cout << ",";
                }
            }
            std::cout << std::endl;
        }
    }
    catch(logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}
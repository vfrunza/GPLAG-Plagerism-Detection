/B2016/2017: Zadaća 3, Zadatak 4
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

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vs, int k) {
    if (k > vs.size() || k < 1) throw logic_error("Razvrstavanje nemoguce");
    std::list<std::string> l(vs.size());
    std::copy(vs.begin(), vs.end(), l.begin());
    std::vector<std::set<std::string>> vss(k);
    auto it=l.begin();
    int trenutnitim(0), velicina(vs.size() / k);
    if (trenutnitim < vs.size() % k) velicina++;
    while (l.size()) {
        if(vss[trenutnitim].size() == velicina) {
            trenutnitim++;
            velicina = vs.size() / k;
            if (trenutnitim < vs.size() % k) velicina++;
        }
        vss[trenutnitim].insert(*it);
        int bslova(brojslova(*it));
        it = l.erase(it);
        if (it == l.end()) it = l.begin();
        if (l.empty()) break;
        for (int i = 1; i < bslova; i++) {
            it++;
            if (it == l.end()) it = l.begin();
        }
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
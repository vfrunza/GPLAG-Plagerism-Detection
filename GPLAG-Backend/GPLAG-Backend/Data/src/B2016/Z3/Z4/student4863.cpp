/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <stdexcept>

int DuzinaImena(std::string ime) {
    int brojac(0);
    for(int i = 0; i < ime.length(); i++)
        if((ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <='Z') || (ime[i] >= '0' && ime[i] <= '9'))
            brojac ++;
    return brojac;
    
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int k) {
    if(k < 1 || k > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> v(k);
    int n(imena.size());
    std::list<std::string> lista (n);
    std::copy(imena.begin(), imena.end(), lista.begin());
    int brojac (DuzinaImena(*lista.begin())), br_tima(0), br_clana(0);
    auto it(lista.begin());
    while(lista.size()) {
        v[br_tima].insert(*it);
        br_clana++;
        if((br_tima <= n%k -1 && br_clana == n/k +1) || (br_tima>n%k-1 && br_clana == n/k)) {
            br_tima++;
            br_clana = 0;
        }
        it = lista.erase(it);
        if(!lista.size())
            break;
        if(it == lista.end()) it = lista.begin();
        for(int i = 0; i < brojac-1; i++) {
            if(it == lista.end())
                it = lista.begin();
            it++;
        }
        if(it == lista.end()) it = lista.begin();
        if(lista.size()) brojac = DuzinaImena(*it);
    }
   return v;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite imena djece:\n";
    for(int i = 0; i < n; i++) 
        getline(std::cin, v[i]);
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin >> k;
    try {
        auto timovi (Razvrstavanje(v, k));
        for(int i = 0; i < k; i++) {
            std::cout << "Tim " << i+1 << ": ";
            auto it(timovi[i].begin());
            while(it != timovi[i].end()) {
                std::cout << *it;
                if(++it != timovi[i].end())
                    std::cout<<", ";
            }
            std::cout << std::endl;
        }
    }
    catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();    
    }
	return 0;
}
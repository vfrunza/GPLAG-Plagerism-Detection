/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <new>
#include <stdexcept>

struct Dijete {
    std::string ime;
    Dijete* sljedeci;
};

int DuzinaImena(std::string ime) {
    int brojac(0);
    for(int i = 0; i < ime.length(); i++)
        if((ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <= 'Z') || (ime[i] >= '0' && ime[i] <= '9'))
            brojac++;
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int k) {
    if(k < 1 || k > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> v(k);
    int n (imena.size());
    Dijete* pocetak(nullptr), *prosli;
    try{
        for(int i = 0; i < n; i++) {
           Dijete *novo(new Dijete);
            novo->ime = imena[i];
            novo->sljedeci = nullptr;
            if(!pocetak) pocetak = novo;
            else prosli->sljedeci = novo;
            if(i == n-1) novo->sljedeci = pocetak;
            prosli = novo;
        }
        int brojac(DuzinaImena(pocetak->ime)), br_tima(0),  br_clana(0), br_djece(n);
        auto pok(pocetak);
        for(int i = 0; i < n; i++) {
            v[br_tima].insert(pok->ime);
            br_clana++;
            if((br_tima <= n%k -1 && br_clana == n/k +1) || (br_tima > n%k -1 && br_clana == n/k)) {
                br_tima++;
                br_clana = 0;
            }
            auto tmp(pok), tmp2(pok);
            for(int j = 0; j < br_djece-1; j++)
                tmp = tmp->sljedeci;
            tmp -> sljedeci = pok -> sljedeci;
            br_djece--;
            for(int i = 0; i < brojac; i++)
               pok = pok -> sljedeci;
            if(!brojac) pok = pok-> sljedeci;
            brojac = DuzinaImena(pok->ime);
            delete tmp2;
        }
        return v;
        }
    catch(std::bad_alloc) {
        while(pocetak) {
            auto pok(pocetak);
            pocetak = pocetak->sljedeci;
            delete pok;
        }
        throw;
    }
}
int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    std::vector<std::string> v(n);
    std::cout << "Unesite imena djece:\n";
    for(int i = 0; i < n; i++)
        getline(std::cin, v[i]);
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin >> k;
    try {
        auto timovi(Razvrstavanje(v, k));
        for(int i = 0; i < k; i++) {
            std::cout << "Tim "<< i+1 << ": ";
            auto it(timovi[i].begin());
            while(it != timovi[i].end()) {
                std::cout << *it;
                if(++it != timovi[i].end())
                    std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    catch(std::bad_alloc) {
        
    }
	return 0;
}
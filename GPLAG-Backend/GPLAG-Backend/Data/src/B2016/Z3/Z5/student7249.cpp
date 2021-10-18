/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>

struct Dijete {
    std::string ime;
    Dijete* sljedeci;
};

int BrojSlovaImena(const std::string &s) {
    int br(0);
    for(auto it=s.begin(); it!=s.end(); it++) {
        if((*it>='A' && *it<='Z') || (*it>='a' && *it<='z') || (*it>='0' && *it<='9')) br++;
    }
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &v, const int &k) {
    if(k<1 || k>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr), *prethodni(nullptr);
    for(int i=0; i<v.size(); i++) {
        Dijete *novi(new Dijete);
        novi->ime=v[i]; novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    int modul(v.size()%k), cio_dio(v.size()/k);
    std::vector<std::set<std::string>> izbor;
    while(izbor.size()<k) {
        auto p(pocetak);
        auto ppom(pocetak);
        while(ppom->sljedeci!=pocetak) ppom=ppom->sljedeci;
        for(int i=1; i<=k; i++) {
            std::set<std::string> tim;
            if(i<=modul) {
                int broj_clanova(cio_dio+1);
                while(1) {
                    if(tim.size()==broj_clanova) break;
                    int br(BrojSlovaImena(p->ime));
                    tim.insert(p->ime);
                    auto pom(p);
                    p=p->sljedeci;
                    ppom->sljedeci=pom->sljedeci;
                    delete pom;
                    for(int j=0; j<br-1; j++) {
                        p=p->sljedeci;
                        ppom=ppom->sljedeci;
                    }
                }
                izbor.push_back(tim);
            }
            else {
                int broj_clanova(cio_dio);
                while(1) {
                    if(tim.size()==broj_clanova) break;
                    int br(BrojSlovaImena(p->ime));
                    tim.insert(p->ime);
                    auto pom(p);
                    if(p==ppom) {
                        delete p;
                        break;
                    }
                    p=p->sljedeci;
                    ppom->sljedeci=pom->sljedeci;
                    delete pom;
                    for(int j=0; j<br-1; j++) {
                        p=p->sljedeci;
                        ppom=ppom->sljedeci;
                    }
                }
                izbor.push_back(tim);
            }
        }
    }
    return izbor;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    std::vector<std::string> v;
    std::cout << "Unesite imena djece: ";
    for(int i=0; i<n; i++) {
        std::string s;
        std::getline(std::cin, s);
        v.push_back(s);
    }
    std::cout << std::endl << "Unesite broj timova: ";
    int k;
    std::cin >> k;
    try {
        auto V(Razvrstavanje(v, k));
        for(int i=0; i<V.size(); i++) {
            std::cout << "Tim " << i+1 << ": ";
            for(auto it=V[i].begin(); it!=V[i].end(); it++) {
                if(it!=V[i].begin()) std::cout << ", ";
                std::cout << *it;
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>
#include <list>
#include <set>

int BrojSlovaImena(const std::string &s) {
    int br(0);
    for(auto it=s.begin(); it!=s.end(); it++) {
        if((*it>='A' && *it<='Z') || (*it>='a' && *it<='z') || (*it>='0' && *it<='9')) br++;
    }
    return br;
}

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &v, const int &k) {
    if(k<1 || k>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> l;
    for(int i=0; i<v.size(); i++) {
        l.push_back(v[i]);
    }
    int modul(v.size()%k), cio_dio(v.size()/k);
    std::vector<std::set<std::string>> izbor;
    while(izbor.size()<k) {
        auto it(l.begin());
        for(int i=1; i<=k; i++) {
            std::set<std::string> tim;
            if(i<=modul) {
                int broj_clanova(cio_dio+1);
                while(it!=l.end()) {
                    if(tim.size()==broj_clanova) break;
                    int br(BrojSlovaImena(*it));
                    tim.insert(*it);
                    it=l.erase(it);
                    if(it==l.end()) it=l.begin();
                    for(int j=0; j<br-1; j++) {
                        if(it==l.end()) {
                            it=l.begin();
                        }
                        else {
                            it++;
                            if(it==l.end()) it=l.begin();
                        }
                    }
                }
                izbor.push_back(tim);
            }
            else {
                int broj_clanova(cio_dio);
                while(it!=l.end()) {
                    if(tim.size()==broj_clanova) break;
                    int br(BrojSlovaImena(*it));
                    tim.insert(*it);
                    it=l.erase(it);
                    if(it==l.end()) it=l.begin();
                    for(int j=0; j<br-1; j++) {
                        if(it==l.end()) {
                            it=l.begin();
                        }
                        else {
                            it++;
                            if(it==l.end()) it=l.begin();
                        }
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
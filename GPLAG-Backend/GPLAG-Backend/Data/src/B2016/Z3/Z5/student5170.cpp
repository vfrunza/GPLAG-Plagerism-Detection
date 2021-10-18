/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> vektor, int k)
{
    int n(vektor.size());
    std::vector<int> broj_igraca(k);
    if(k<1 || k>n) throw std::logic_error ("Razvrstavanje nemoguce");
    for (int i=0; i<n%k; i++) broj_igraca[i]=n/k+1;
    for (int i=n%k; i<k; i++) broj_igraca[i]=n/k;
    Dijete *pocetak(nullptr), *prethodni;
    for (int i=0; i!=vektor.size(); i++) {
        Dijete *novi(new Dijete);
        novi->ime = vektor[i];
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci =novi;
        prethodni=novi;
        if (i==vektor.size()-1)
            novi->sljedeci = pocetak;
    }
    std::vector<std::set<std::string>> povratni(k);
    int duzina(0);
    povratni[0].insert(pocetak->ime);
    for (auto it=pocetak; pocetak->sljedeci!=nullptr; it=it->sljedeci) {
        duzina = 0;
        for (auto iter=it->ime.begin(); iter!=it->ime.end(); iter++)
        if(*iter!=' ') duzina++;
        auto brisati(it);
        it=it->sljedeci;
        pocetak=pocetak->sljedeci;
        delete brisati;
        if(it==nullptr) break;
        auto prethodni(it);
        for (int i=0; i<duzina-1; i++) {
        it=it->sljedeci;
        if (it==nullptr) break;
        if (i!=0) prethodni=prethodni->sljedeci;
        }
        if (it==nullptr) break;
        for (int i=0; i<k; i++) {
            if (povratni[i].size()<broj_igraca[i]) {
                povratni[i].insert(it->ime);
                break;
            }
        }
        it=prethodni;
    }
    for (int i=0; i<povratni.size(); i++) {
    for (auto it=povratni[i].begin(); it!=povratni[i].end(); it++) 
    std::cout << *it << std::endl;
    std::cout << "KRAAAAJ " << std::endl;}
    /*for (Dijete *it=pocetak; it!=nullptr; it=it->sljedeci) {
        std::cout << it->ime << std::endl;
        if(it->sljedeci==nullptr) it=pocetak;
    }*/
    return povratni;
}

int main ()
{
    std::vector<std::string> vek {"Milan", "Mahir", "Alma", "Harun"};
    Razvrstavanje(vek, 2);
    return 0;
}
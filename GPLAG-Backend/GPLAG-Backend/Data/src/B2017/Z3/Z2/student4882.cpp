#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Mapa;

std::string PretvoriUMala (std::string s) {
    std::string z;
    for (int i=0; i<s.length(); i++) {
        if (s.at(i)<='Z' and s.at(i)>='A') z.push_back(s.at(i)+32);
        else z.push_back(s.at(i));
    }
    return z;
}

bool JeLiIspravno (char s) {
    if ((s>='A' and s<='Z') or (s>='a' and s>='z') or (s<='9' and s>='0')) return true;
    return false;
}

Mapa KreirajIndexPojmova (Knjiga k) {
    Mapa m;
    int ulazio=0;
    auto it=k.begin();
    while (it!=k.end()) {
        for (int j=0; j<it->second.size(); j++) {
            std::set<std::tuple<std::string, int, int>> s;
            for (int k=0; k<it->second.at(j).length(); k++) {
                int p;
                if (JeLiIspravno(it->second.at(j).at(k))==true) {
                    p=k;
                    std::string r;
                    ulazio=0;
                    while (JeLiIspravno(it->second.at(j).at(p))==true) {
                        r.push_back(it->second.at(j).at(p));
                        p++;
                        ulazio=1;
                    }
                    int znak=0;
                    auto itt=m.begin();
                    for (int i=0; i<m.size(); i++) {
                        if (PretvoriUMala(r)==PretvoriUMala(itt->first)) {
                            znak=1;
                            break;
                        }
                        itt++;
                    }
                    if (znak==0) {
                        s.insert(std::make_tuple(r, j+1, k));
                    }
                    auto duzina=r.size();
                    for(int g=0; g<duzina; g++) {
                        r.erase(0);
                    }
                }
                if (ulazio==1) k=p;
            }
            m.insert({it->second.at(j), s});
            auto its=s.begin();
            auto vel=s.size();
            for (int ii=0; ii<vel; ii++) {
                s.erase(*its);
                its++;
            }
        }
        it++;
    }
    return m;
}

std::set<std::tuple<std::string, int, int>> PretraziIndexPojmova (std::string s, Mapa m) {
    std::set<std::tuple<std::string, int, int>> t;
    auto n=m.size();
    auto it=m.begin();
    for (int i=0; i<n; i++) {
        auto its=it->second.begin();
        for (int j=0; j<it->second.size(); j++) {
            if (std::get<0>(*its)==s) t.insert(std::make_tuple(it->first, std::get<1>(*its), std::get<2>(*its)));
            its++;
        }
        it++;
    }
    if (t.size()==0) std::cout << "Unesena rijec nije nadjena!";
    return t;
}

void IspisiIndexPojmova (Mapa m) {
    auto n=m.size();
    auto it=m.begin();
    for (int i=0; i<n; i++) {
        auto its=it->second.begin();
        std::cout << PretvoriUMala(it->first) << ": ";
        for (int j=0; j<it->second.size(); j++) {
            std::cout << std::get<0>(*its) << "/" << std::get<1>(*its) << "/" << std::get<2>(*its);
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::string naziv, stranica;
    Knjiga k;
    std::vector<std::string> v;
    auto it=k.begin();
    int i(0);
    for (;;) {
        std::cout  << "Unesite naziv poglavlja: ";
        std::getline(std::cin, naziv);
        if (naziv==".") break;
        int j=0;
        for (;;) {
            j++;
            std::cout << "Unesite sadrzaj stranice " << j << ": ";
            std::getline(std::cin, stranica);
            if (stranica==".") break;
            v.push_back(stranica);
        }
        k.insert({naziv, v});
        i++;
        it++;
    }
    std::cout << std::endl << "Kreirani indeks pojmova: " << std::endl;
    auto m=KreirajIndexPojmova(k);
    IspisiIndexPojmova(m);
    std::string rec;
    for (;;) {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rec);
        if (rec==".") break;
        auto t=PretraziIndexPojmova(rec, m);
        auto tt=t.begin();
        for (int i=0; i<t.size(); i++) {
            std::cout << std::get<0>(*tt) << "/" << std::get<1>(*tt) << "/" << std::get<2>(*tt);
            if (i!=t.size()-1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
	return 0;
}

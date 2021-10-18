#include <iostream>
#include <list>
#include <set>
#include <stdexcept>
#include <iterator>
#include <string>
#include <vector>

int duzina (std::string s) {
    int brojac=0;
    for(int i=0;i<s.length();i++) if( (s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9') ) brojac++;
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int n) {
    std::list<std::string> lista ;
    if(n<1 or n>v.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> k;
    int broj_clanova[1000];
    int d=v.size()%n;
    for(int i=0;i<n;i++) {
        if(i<d) broj_clanova[i]=(v.size()/n) +1 ;
        else broj_clanova[i]=v.size()/n ;
    }
    for(int i=0;i<v.size();i++) {
        lista.push_back(v[i]);
    }
    std::list<std::string>::iterator it1(lista.begin());
    for(int j=0;j<n;j++) {
        std::set<std::string> skup;
        for(int i=0;i<broj_clanova[j];i++) {
            skup.insert(*it1);
            int velicina=duzina(*it1);
            it1=lista.erase(it1);
            it1--;
            for(int i=0;i<velicina;i++) {
                it1++;
                if(it1==lista.end()) it1=lista.begin();
            }
        }
        k.push_back(skup);
    }
    return k;
}

int main () {
    try {
        std::cout << "Unesite broj djece: ";
        int n;
        std::cin >> n ;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::vector<std::string> v;
        std::cout << "Unesite imena djece: ";
        for(int i=0;i<n;i++) {
            std::string s;
            std::getline(std::cin,s);
            v.push_back(s);
        }
        std::cout << std::endl <<"Unesite broj timova: ";
        int t;
        std::cin >> t;
        std::vector<std::set<std::string>> k=Razvrstavanje(v,t);
        for(int i=0;i<t;i++) {
            std::cout << "Tim " << i+1 << ": ";
            int vel=std::distance(k[i].begin(),k[i].end());
            for(auto it=k[i].begin(); it!=k[i].end();it++) {
                vel--;
                if(vel==0) std::cout << *it;
                else std::cout << *it << ", " ;
            }
            std::cout << std::endl;
        }
    }
    catch (std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() ;
    }
    return 0;
}
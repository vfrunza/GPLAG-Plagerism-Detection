/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <list>

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> vektor, int k)
{
    int n(vektor.size());
    std::vector<int> broj_igraca(k);
    if (k<1 || k>n) throw std::logic_error ("Razvrstavanje nemoguce");
    for (int i=0; i<n%k; i++) broj_igraca[i]=n/k+1;
    for (int i=n%k; i<k; i++) broj_igraca[i]=n/k;
    std::list<std::string> lista;
    for (int i=0; i!=vektor.size(); i++)
        lista.push_back(vektor[i]);
    std::vector<std::set<std::string>> povratni(k);
    int duzina(0);
    povratni[0].insert(*(lista.begin()));
    for (auto it=lista.begin(); it!=lista.end(); it++) {
        duzina=0;
        for (auto iter=it->begin(); iter!=it->end(); iter++)
            if(*iter!=' ' && *iter!='-' && *iter!='.') duzina++;
        it=lista.erase(it);
        if (it==lista.end()) it=lista.begin();
        for (int i=0; i<duzina-1; i++) {
            it++;
            if(it==lista.end()) it=lista.begin();
        }
        for (int i=0; i<k; i++) {
            if (povratni[i].size()<broj_igraca[i]) {
                povratni[i].insert(*it);
                break;
            }
        }
        it--;
    }
    return povratni;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite imena djece: \n";
    std::vector<std::string> vektor(n);
    std::cin.ignore(10000, '\n');
    for(int i=0; i<n; i++) 
        std::getline(std::cin, vektor[i]);
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin >> k;
   try { auto vraceni (Razvrstavanje(vektor, k));
    for (int i=0; i<vraceni.size(); i++) {
        std::cout << "Tim " << i+1<< ": ";
        for (auto it=vraceni[i].begin(); it!=vraceni[i].end(); it++){
            if (it!=--vraceni[i].end())
        std::cout << *it<< ", ";
            else std::cout << *it << std::endl;
        }
    }
   }
   catch (std::logic_error izuzetak) {
       std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
   }
    return 0;
}
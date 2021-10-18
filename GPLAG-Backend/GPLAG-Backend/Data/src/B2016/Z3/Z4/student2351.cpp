/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::endl;
using std::cout;
using std::cin;

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> v, int broj_timova) {
    for (int i=0; i<v.size(); i++) {
        if (broj_timova<1 ) throw std::logic_error ("Razvrstavanje nemoguce");
    }
    
    std::list<std::string> lista;
    std::vector<std::set<std::string>> vektor_skupova;
    std::copy (v.begin(), v.end(), std::back_inserter(lista));
    int brojac(0);
    
    for (auto it=lista.begin(); it!=lista.end(); it++) {
        vektor_skupova.push_back(*it);
        it=lista.erase(it);
        
        
        
        
    }
    
  return vektor_skupova;  
}


int main ()
{
    cout << "Unesite broj djece: ";
    int n;
    cin >> n;
    cout << "Unesite imena djece: ";
    std::vector<std::string> imena(n);
    for (int i=0; i<n; i++) {
        cin >> imena[i];
    }
    cout << "\nUnesite broj timova: ";
    int br_timova;
    cin >> br_timova;
    
    std::vector<std::set<std::string >> vektor = Razvrstavanje(imena, br_timova);
    
    for (int i=0; i<vektor.size(); i++) {
        for (auto x: vektor[i]) cout << "Tim " << i+1 << ": " << x << " " << endl;
    }
    
	return 0;
}
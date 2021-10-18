/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>
using namespace std;

//funckija koja računa dužinu stringa
int duzina_imena(string ime) {
    int brojac{0};
    for(int i{0}; i < ime.length(); i++) {
        if((ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <= 'Z') || (ime[i] >= '0' && ime[i] <= '9'))
            brojac++;
    }
    return brojac;
}

vector<set<string>> Razvrstavanje (vector<string> imena_djece, int k) {
    int n = imena_djece.size();
    if(k < 1 || k > n) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> timovi(k);
    vector<int> broj_mjesta(k);
    for(int i{0}; i < n%k; i++) {
        broj_mjesta[i] = n / k + 1;
    }
    for(int i{n%k}; i < k; i++) {
        broj_mjesta[i] = n / k;
    }
    list<string> lista_imena(n);
    auto it = lista_imena.begin();
    int indeks = 0;
    while(it != lista_imena.end()) {
        *it = imena_djece[indeks];
        it++;
        indeks++;
    }
    it = lista_imena.begin();
    int trenutni_tim = 0;
    while(!lista_imena.empty()) {
        if(it == lista_imena.end()) it = lista_imena.begin();
        if(broj_mjesta[trenutni_tim] == 0) trenutni_tim++;
        timovi[trenutni_tim].insert(*it);
        int pomjeranje = duzina_imena(*it);
        it = lista_imena.erase(it);
        it--;
        broj_mjesta[trenutni_tim]--;
        while(pomjeranje > 0) {
            it++;
            if(it == lista_imena.end()) it = lista_imena.begin();
            pomjeranje--;
        }
    }
    return timovi;
}
int main ()
{
    try {
    cout << "Unesite broj djece: ";
    int broj_djece;
    cin >> broj_djece;
    cin.ignore(100, '\n');
    cout << "Unesite imena djece:" << endl;
    vector<string> imena_djece(broj_djece);
    for(int i{0}; i < broj_djece; i++) {
        getline(cin, imena_djece[i]);
    }
    cout << "Unesite broj timova: ";
    int broj_timova;
    cin >> broj_timova;
    auto timovi = Razvrstavanje(imena_djece, broj_timova);
    for(int i{0}; i < timovi.size(); i++) {
        cout << "Tim " << i+1 << ": ";
        auto it_kraja = timovi[i].end();
        it_kraja--;
        for(auto it = timovi[i].begin(); it != it_kraja; it++) {
            cout << *it << ", ";
        }
        cout << *it_kraja << endl;
    }
    }
    catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <stdexcept>
using namespace std;

struct Dijete {
    string ime;
    shared_ptr<Dijete>sljedeci;
};
//funckija koja računa dužinu stringa
int duzina_imena(string ime) {
    int brojac{0};
    for(int i{0}; i < ime.length()-1; i++) {
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
    shared_ptr<Dijete>pocetak = nullptr; shared_ptr<Dijete>cvor_prije = nullptr;
    for(int i{0}; i < imena_djece.size(); i++) {
        shared_ptr<Dijete> novi = make_shared<Dijete>();
        novi->ime = imena_djece[i];
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else cvor_prije->sljedeci = novi;
        cvor_prije = novi;
    }
    cvor_prije->sljedeci = pocetak;

    int trenutni_tim = 0;
    shared_ptr<Dijete>iterator = pocetak;
    for(;;) {
        if(broj_mjesta[trenutni_tim] == 0) trenutni_tim++;
        timovi[trenutni_tim].insert(iterator->ime);
        int pomjeranje = duzina_imena(iterator->ime);
        if(iterator == iterator->sljedeci) {
            iterator->sljedeci = nullptr;
            break;
        }
        
        cvor_prije -> sljedeci = iterator->sljedeci;
        iterator = cvor_prije->sljedeci;
        broj_mjesta[trenutni_tim]--;
        while(pomjeranje > 0) {
            iterator = iterator->sljedeci;
            cvor_prije = cvor_prije->sljedeci;
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
    catch(logic_error izuzetak) {
        cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}
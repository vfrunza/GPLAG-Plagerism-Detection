/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
typedef std::vector<std::string> Vektor_imena;
typedef std::vector<std::set<std::string>> Vektor_timova;
typedef std::vector<int> DjecaUTimu;

struct Dijete {
    string ime;
    Dijete *sljedeci;
};

int Duzina_imena(string s)
{
    int neslovo(0);
    for(int i = 0; i < s.length(); i++)
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
            neslovo ++;
    int duzina = s.length() - neslovo;
    return duzina;
}

Dijete *Obrisi(Dijete *pocetak, string s) {
    Dijete *pp(nullptr), *pt(pocetak), *ps(nullptr); 
    for(;;){
        if(pt->sljedeci->ime == s){
            pp = pt;
//            pt = pt->sljedeci;
            ps = pt->sljedeci->sljedeci;
            pp->sljedeci = ps;
            delete pt;
            break;
        }
        else pt = pt->sljedeci;
        delete pp; delete ps;
    }
    return pp->sljedeci;
}

Vektor_timova Razvrstavanje (Vektor_imena &v, int k)
{
    if(k < 1 || k > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n(v.size());
    Vektor_timova tim(k);
    
    DjecaUTimu broj(k);
    for(int i = 0; i < broj.size(); i++) {
        if(i < n%k) broj[i] = n/k + 1;
        else broj[i] = n/k;
    }
    
    Dijete *pocetak(nullptr), *prethodni;    
    for(int i = 0; i < n; i++) {
        Dijete *novi(new Dijete);
        novi->ime = v[i];
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
        delete novi;
    }
    prethodni->sljedeci = pocetak;
    
    Dijete *p(pocetak);
    while(n != 0) {
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < broj[i]; j++) {
                string s (p->ime);
                tim[i].insert(s);
                int pomjeri(Duzina_imena(s)), br(0);
                p = Obrisi(pocetak, s);
                n--;
                while(br != pomjeri - 1) {
                    p = p->sljedeci;
                    br++;
                }
            }
        }
    }

    pocetak = nullptr;
    return tim;
}

int main ()
{
    cout << "Unesite broj djece: ";
    int n;
    cin >> n;
    cin.ignore(1000, '\n');
    cout << "Unesite imena djece: " << endl;
    Vektor_imena v;
    for(;;) {
        string ime;
        std::getline(cin, ime);
        v.push_back(ime);
        if(v.size() == n) break;
    } 
    cout << "Unesite broj timova: ";
    int k;
    cin >> k;

    try {
        Vektor_timova timovi(Razvrstavanje(v, k));
        for(int i = 0; i < timovi.size(); i++) {
            cout << "Tim " << i + 1 <<": ";
            int brojac(0);
            auto it(timovi[i].begin());
            while(it != timovi[i].end()) {
                cout << *it;
                it++;
                brojac++;
                if(brojac < timovi[i].size()) cout << ", ";
            }
            cout << endl;
        }
    } catch(std::logic_error e) {
        cout << "Izuzetak: " << e.what();
    }
    return 0;
}
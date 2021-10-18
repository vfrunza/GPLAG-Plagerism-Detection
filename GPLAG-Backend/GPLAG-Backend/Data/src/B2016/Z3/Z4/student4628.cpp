/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
typedef std::vector<std::string> Vektor_imena;
typedef std::vector<std::set<std::string>> Vektor_timova;
typedef std::list<std::string> Lista;

int Duzina_imena(string s)
{
    int neslovo(0);
    for(int i = 0; i < s.length(); i++)
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
            neslovo ++;
    int duzina = s.length() - neslovo;
    return duzina;
}

Vektor_timova Razvrstavanje (Vektor_imena &v, int k)
{
    if(k < 1 || k > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    Lista ucenici;
    for(int i = 0; i < v.size(); i++) {
        ucenici.push_back(v[i]);
    }
    
    std::vector<int> broj(k);
    for(int i = 0; i < broj.size(); i++) {
        if(i < v.size()%k) broj[i] = v.size()/k + 1;
        else broj[i] = v.size()/k;
    }
    
    auto it(ucenici.begin());
    Vektor_timova tim(k);
    while(ucenici.size() > 0) {
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < broj[i]; j++) {
                tim[i].insert(*it);
                int pomjeri(Duzina_imena(*it)), br(0);
                it = ucenici.erase(it);
                if(it == ucenici.end()) it = ucenici.begin();
                while(br != pomjeri - 1) {
                    it++;
                    if(it == ucenici.end()) it = ucenici.begin();
                    br++;
                }
            }
        }
    }

    return tim;
}

int main ()
{
    int n;
    cout << "Unesite broj djece: ";
    cin >> n;
    cin.ignore(1000, '\n');
    cout << "Unesite imena djece: ";
    Vektor_imena v;
    string ime;
    for(int i = 0; i < n; i++) {
        std::getline(cin, ime);
        v.push_back(ime);
    } 

    int k;
    cout << endl << "Unesite broj timova: ";
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
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
typedef std::set<int> Skup;
typedef std::map<std::string, std::set<int>> Mapa;

Mapa KreirajIndeksPojmova (string s)
{
    Mapa pozicija;
    bool neslovo(true);
    for(int i = 0; i != s.length(); i++) {

        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
            neslovo = true;
        else if(neslovo) {
            neslovo = false;
            int index(i);

            string temp;
            while((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
                temp.push_back(s[i]);
                i++;
            }
            i--;

            pozicija[temp].insert(index);
            temp.clear();
        }
    }
    return pozicija;
}

Skup PretraziIndeksPojmova (string s, Mapa pozicije)
{
    Skup indexi;
    if(!pozicije.count(s)) throw std::logic_error("Pojam nije nadjen");
    else {
        indexi = pozicije[s];
    }
    return indexi;
}

void IspisiIndeksPojmova (Mapa pozicije)
{
    for(auto it = pozicije.begin(); it != pozicije.end(); it++) {
        cout << it->first <<": ";
        int vel(it->second.size());
        for(auto x: it->second) {
            cout << x;
            if(vel != 1) cout << ",";
            vel--;
        }
        cout << endl;
    }
}

int main ()
{
    string s;
    cout << "Unesite tekst: ";
    std::getline(cin, s);
    auto mapa_indeksa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa_indeksa);

    for(;;) {
        try {
            string rijec;
            cout << "Unesite rijec: ";
            std::getline(cin, rijec);
            if(rijec == ".") break;
            Skup s(PretraziIndeksPojmova(rijec, mapa_indeksa));
            for(auto x: s) cout << x << " ";
            cout << endl;
        } catch(std::logic_error e) {
            cout << "Unesena rijec nije nadjena!" <<endl;
        }
    }
    return 0;
}
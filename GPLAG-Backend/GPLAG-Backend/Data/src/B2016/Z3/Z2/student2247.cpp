#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
using namespace std;

map<string, set<int>> KreirajIndeksPojmova (string tekst) {
    map<string, set<int>> indeks_pojmova;
    tekst=tekst+" ";
    for(int i=0; i<=tekst.length(); i++) tekst[i]=tolower(tekst[i]);
    string pomocni_str="\0";
    for(int i=0; i<tekst.length(); i++) {
        if((tekst[i]>=65 && tekst[i]<=90) || (tekst[i]>=97 && tekst[i]<=122) || (tekst[i]>=48 && tekst[i]<=57)) {
            pomocni_str.push_back(tekst[i]);
        }

        else if(pomocni_str.empty()) {
            continue;
        }
        else if(!(pomocni_str.empty())) {
            set<int> pomocni_skup;
            int ubacen(0);
            for(auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++) {
                if(it->first==pomocni_str) {
                    it->second.insert(i-pomocni_str.length());
                    ubacen=1;
                    break;
                }
            }
            if(ubacen==0) {
                pomocni_skup.insert(i-pomocni_str.length());
                indeks_pojmova.insert(make_pair(pomocni_str, pomocni_skup));
            }
            pomocni_str="\0";
        }
    }

    return indeks_pojmova;
}

set<int> PretraziIndeksPojmova (string rijec, map<string, set<int>> indeks_pojmova) {
    for(auto par : indeks_pojmova) {
        if(par.first==rijec) return par.second;
    }
    throw logic_error("Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova (map<string, set<int>> indeks_pojmova) {
    for(auto par : indeks_pojmova) {
        cout << par.first << ": ";
        for(auto it=par.second.begin(); ; ) {
            cout << *it;
            it++;
            if(it==par.second.end()) break;
            else cout << ",";
        }
        cout << endl;
    }
}

int main ()
{
    
        cout << "Unesite tekst: ";
        string tekst;
        getline(cin, tekst);
        auto indeks_pojmova(KreirajIndeksPojmova(tekst));
        IspisiIndeksPojmova(indeks_pojmova);
        for(;;) {
            cout << "Unesite rijec: ";
            string rijec;
            getline(cin, rijec);
            if(rijec==".") break;
            try {
                set<int> pozicije=PretraziIndeksPojmova(rijec, indeks_pojmova);
                for(auto poz : pozicije) {
                    cout << poz << " ";
                }
            }
            catch (logic_error nema) {
                cout << nema.what();
            }
            cout << endl;
        }

	return 0;
}
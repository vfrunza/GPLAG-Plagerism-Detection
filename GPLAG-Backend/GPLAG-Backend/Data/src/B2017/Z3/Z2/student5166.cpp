/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>
using namespace std;

typedef map<string,set<int>> Objekat;

int BrojSlova(string s, int index){
    int brojac = 0;
    for (int i=index; i<s.length(); i++){
        if ((s[i] < 'A' && s[i] > '9') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z' || s[i] < '0') break;
        brojac++;
    }
    return brojac;
}

Objekat KreirajIndeksPojmova (string s){
    Objekat mapa;
    for (int i=0; i<s.length(); i++){
        if ((s[i]<'A' && s[i]>'9') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z' || s[i] < '0') continue;
        else {
            string s2 (s.substr(i, BrojSlova(s, i)));
            transform (s2.begin(), s2.end(), s2.begin(), ::tolower);
            mapa[s2].insert(i);
            i+=BrojSlova(s,i)-1;
        }
    }
    return mapa;
}

set<int> PretraziIndeksPojmova (string s, Objekat mapa){
    for (auto it = mapa.begin(); it!=mapa.end(); it++){
        if (it->first == s) return mapa[it -> first];
    }
    throw logic_error ("Pojam nije nadjen");
}

void IspisiIndeksPojmova (Objekat mapa){
    for (auto it = mapa.begin(); it!=mapa.end(); it++){
        
        cout << it -> first << ": ";
        int brojac = 0;
        for (auto x : mapa[it -> first]){
            if (brojac == (mapa[it->first]).size()-1) cout << x;
            else cout << "I/1/" << x << ",";
            brojac++;
        }
        cout << endl;
    }
}

int main (){
    string poglavlje;
    cout << "Unesite naziv poglavlja:";
    getline(cin, poglavlje);
    
    
    cout << "Unesite sadrzaj stranice 1: ";
    string sadrzaj1;
    getline(cin, sadrzaj1);
    
    cout << "Unesite sadrzaj stranice 2: ";
    string sadrzaj2;
    getline(cin, sadrzaj2);
    
    cout << "Unesite tekst:\n";
    string s;
    getline(cin, s);
    
    Objekat mapa (KreirajIndeksPojmova(s));
    cout << "Kreirani index pojmova: ";
    IspisiIndeksPojmova(mapa);
    
    do {
        cout << "Unesite rijec: ";
        string s2;
        getline (cin, s2);
        if (s2 == ".") break;
        try {
            for (auto x : PretraziIndeksPojmova(s2,mapa)) cout << x << " ";
        }
        catch (logic_error Izuzetak){
            cout << "Unesena rijec nije nadjena!";
        }
        cout << endl;
    } while(1);
    
	return 0;
}

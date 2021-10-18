/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>

using std::string;
using std::set;
using std::map;

typedef map<string, set<int>> Mapa;

char slovo(char c) {
    if (('a' <= c and c <= 'z') or ('0' <= c and c <= '9')) 
        return c;
    
    if ('A' <= c and c <= 'Z') 
        return c - 'A' + 'a';
    
    return 0;
}

string mala(string s) {
    for (char &x : s)
        if (slovo(x))
            x = slovo(x);
    return s;
}

Mapa KreirajIndeksPojmova(string s) {
    Mapa m;
    for (int i = 0; i < s.size(); i++) {
        if (!slovo(s.at(i))) continue;
        
        int poc = i;
        while (i < s.size() && slovo(s.at(i))) i++;
        int kraj = i;
        string rijec(s.substr(poc, kraj - poc));
        m[mala(rijec)].insert(poc);
    }
    return m;
}

set<int> PretraziIndeksPojmova(string s, Mapa m) {
    s = mala(s);
    if (m.count(s)) return m[s];
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(Mapa m) {
    using std::cout;
    for (auto p : m) {
        cout << p.first << ": ";
        auto it = p.second.begin();
        if (it == p.second.end()) continue;
        cout << *it;
        for (it++; it != p.second.end(); it++)
            cout << ',' << *it;
        cout << '\n';
    }
}

int main() {
    using std::cout;
    using std::cin;
    
    cout << "Unesite tekst: ";
    string s;
    std::getline(cin, s);
    auto m(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    
    for (;;) {
        cout << "Unesite rijec: ";
        try {
            string r;
            cin >> r;
            if (r == ".") break;
            for (int x : PretraziIndeksPojmova(r, m))
                cout << x << ' ';
            cout << '\n';
        } catch (std::logic_error e) {
            cout << "Unesena rijec nije nadjena!\n";
            
        }
    }
	return 0;
}
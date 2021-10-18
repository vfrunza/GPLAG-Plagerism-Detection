/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

using std::vector;
using std::list;
using std::set;
using std::string;

int slova(string s) {
    int br = 0;
    for (char c : s)
        if ( ('a' <= c && c <= 'z') ||
             ('A' <= c && c <= 'Z') ||
             ('0' <= c && c <= '9') )
            br++;
    return br;
}

vector<set<string>> Razvrstavanje(vector<string> vs, int t) {
    int n = vs.size();
    if (t < 1 || t > n)
        throw std::logic_error("Razvrstavanje nemoguce");
    
    list<string> in;
    for (string str : vs)
        in.push_back(str);
    
    vector<set<string>> rez(t);
    
    auto it = in.begin();
    for (int tim = 0; tim < t; tim++) {
        for (int i = 0; i < n/t + (tim < n%t ? 1 : 0); i++) {  
            int ecipeci = slova(*it);
            rez[tim].insert(*it);
            it = in.erase(it);
            if (it == in.end())
                it = in.begin();
            while (ecipeci-- - 1) { //sta ako je duzina 0???
                it++;
                if (it == in.end()) it = in.begin();
            }
        }
    }
    
    return rez;
}

int main() {
    using std::cin;
    using std::cout;
    try {
        cout << "Unesite broj djece: ";
        int n;
        cin >> n;
        string xx;
        std::getline(cin, xx);
        cout << "Unesite imena djece: \n";
        vector<string> vs(n);
        for (string &s : vs)
            std::getline(cin, s);
        cout << "Unesite broj timova: ";
        int t;
        cin >> t;
        int broj = 1;
    
        for (auto &tim : Razvrstavanje(vs, t)) {
            cout << "Tim " << broj++ << ": ";
            auto it = tim.begin();
            cout << *it; // nikad nece biti prazan tim
            for (it++; it != tim.end(); it++)
                cout << ", " << *it;
            cout << '\n';
        }
    } catch (std::logic_error e) {
        cout << "Izuzetak: " << e.what();
    } catch (...) {
        //njam    
    }
    
	return 0;
}
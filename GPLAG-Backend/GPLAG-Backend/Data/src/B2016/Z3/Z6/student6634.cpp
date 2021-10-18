/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

using std::vector;
using std::set;
using std::string;
using std::shared_ptr;
using std::make_shared;

int slova(string s) {
    int br = 0;
    for (char c : s)
        if ( ('a' <= c && c <= 'z') ||
             ('A' <= c && c <= 'Z') ||
             ('0' <= c && c <= '9') )
            br++;
    return br;
}


struct Dijete {
    string ime;
    shared_ptr<Dijete> sljedeci;
};

typedef shared_ptr<Dijete> pok;


vector<set<string>> Razvrstavanje(vector<string> vs, int t) {
    int n = vs.size();
    if (t < 1 || t > n)
        throw std::logic_error("Razvrstavanje nemoguce");
    //sad znamo da ima bar jedno dijete
    pok prvo = nullptr;
    try {
        prvo = make_shared<Dijete>();
        prvo->ime = vs[0];
        prvo->sljedeci = prvo;
        pok proslo = prvo;
        for (int i = 1; i < vs.size(); i++) {
            //if (i == 3) throw std::bad_alloc();
            pok novo = make_shared<Dijete>();
            novo->ime = vs[i];
            novo->sljedeci = prvo;
            proslo->sljedeci = novo;
            proslo = novo;
        }
    } catch (std::bad_alloc e) {
        if (prvo)
            prvo->sljedeci = nullptr;
        throw;
    }
    vector<set<string>> rez(t);
    
    pok it = prvo;
    for (int tim = 0; tim < t; tim++) {
        for (int i = 0; i < n/t + (tim < n%t ? 1 : 0); i++) {  
            int ecipeci = slova(it->ime);
            rez[tim].insert(it->ime);
            pok proslo = it;
            while (proslo->sljedeci != it) 
                proslo = proslo->sljedeci;
            proslo->sljedeci = it->sljedeci;
            while (ecipeci--)  //sta ako je duzina 0???
                it = it->sljedeci;
        }
    }
    
    it->sljedeci = nullptr;
    
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
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

using namespace std;

vector<pair<string, int>> explode(string s, const vector<char> delim){
    s.push_back('\0');
    vector<pair<string, int>> rez;
    string rijec;
    int index(0);
    for(auto it(s.begin()); it != s.end(); it++, index++){
        if((find(delim.begin(), delim.end(), *it) != delim.end() || *it == '\0') && !rijec.empty()){
            rez.push_back(pair<string, int> {rijec, index - (int)rijec.size()});
            rijec.clear();
        }
        while(find(delim.begin(), delim.end(), *it) != delim.end()) it++, index++;
        rijec.push_back(*it);
    }
    return rez;
}

bool istiZnak(const char c1, const char c2){
    if(c1 >= 'A' && c1 <= 'Z')
        return c2 == c1 + 32 || c2 == c1;
    if(c2 >= 'A' && c2 <= 'Z')
        return c1 == c2 + 32 || c2 == c1;
    if(c1 >= 'a' && c1 <= 'z')
        return c2 == c1 - 32 || c2 == c1;
    if(c2 >= 'a' && c2 <= 'z')
        return c1 == c2 - 32 || c2 == c1;
    return c1 == c2;
}

bool porediStringove(const string s1, const string s2){
    bool isti(true);
    auto it2(s2.begin());
    for(auto it(s1.begin()); it != s1.end(); it++, it2++){
        if(it2 == s2.end() || !istiZnak(*it, *it2)){
            isti = false;
            break;
        }
    }
    return isti;
}

string sveUMala(string s){
    string rez;
    for(char c : s)
        c >= 'A' && c <= 'Z' ? rez.push_back(c + 32) : rez.push_back(c);
    return rez;
}

map<string, set<int>> KreirajIndeksPojmova(string s){
    map<string, set<int>> rez;
    vector<char> delim;
    for(char c(32); c < 127; c++){
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) continue;
        else delim.push_back(c);
    }
    for(pair<string, int> p : explode(s, delim)) rez[sveUMala(p.first)].insert(p.second);
    return rez;
}

set<int> PretraziIndeksPojmova(string s, map<string, set<int>> pojmovi){
    set<int> skup;
    bool postoji(false);
    for(auto x : pojmovi){
        if(porediStringove(x.first, s)){
            postoji = true;
            skup = x.second;
            break;
        }
    }
    if(!postoji) throw logic_error("Pojam nije nadjen");
    return skup;
}

void IspisiIndeksPojmova(map<string, set<int>> pojmovi){
    for(auto x : pojmovi){
        cout << x.first << ": ";
        auto kraj(x.second.end()); kraj--;
        for(auto it(x.second.begin()); it != kraj; it++) cout << *it << ",";
        cout << *kraj << endl;
    }
}

int main ()
{
    string tekst;
    cout << "Unesite tekst: ";
    getline(cin, tekst);
    auto pojmovi = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(pojmovi);
    while(1){
        string s;
        cout << "Unesite rijec: ";
        cin >> s;
        if(s == ".") break;
        try{
            for(int a : PretraziIndeksPojmova(s, pojmovi)) cout << a << " ";
            cout << endl;
        }catch(logic_error e){
            cout << "Unesena rijec nije nadjena!" << endl; 
        }
    }
	return 0; 
}
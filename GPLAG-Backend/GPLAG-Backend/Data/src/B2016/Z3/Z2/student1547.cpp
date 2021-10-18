/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <string>

using std::cout;
using std::cin;

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<s.length(); i++) {
        if(s[i]==' ') continue;
        if(!((s[i]>='0' and s[i]<='9') or (s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z'))) continue;
        int j(i);
        while(((s[j]>='0' and s[j]<='9') or (s[j]>='A' and s[j]<='Z') or (s[j]>='a' and s[j]<='z')) and j<s.length()) j++;
        std::string temp(s.substr(i, j-i));
        for(int k=0; k<j-i; k++) if(temp[k]>='A' and temp[k]<='Z') temp[k]+='a'-'A';
        mapa[temp].insert(i);
        i=j;
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa)
{
    if(!mapa.count(s)) throw std::logic_error ("Pojam nije nadjen");
    else return mapa[s];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        cout << it->first <<": ";
        int i(0);
        for(int x: it->second) {
            cout << x;
            if(i<(it->second).size()-1) cout << ",";
            i++;
        }
        cout << std::endl;
    }
}

int main ()
{
    std::string s;
    cout<< "Unesite tekst: ";
    std::getline(cin, s);
    std::map<std::string, std::set<int>> index(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(index);
    for(;;) {
        cout << "Unesite rijec: ";
        std::string x;
        std::getline(cin, x);
        if(x==".") break;
        try {
            std::set<int> skup(PretraziIndeksPojmova(x, index));
            for(int y: skup) cout << y << " ";
        } catch (std::logic_error izuzetak) {
            cout << "Unesena rijec nije nadjena!";
        }
        cout << std::endl;
    }
    return 0;
}
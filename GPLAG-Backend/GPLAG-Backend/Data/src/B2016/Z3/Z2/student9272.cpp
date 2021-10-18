/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
using namespace std;

void IspisiIndeksPojmova(map<string,set<int>> mapa){
        for(auto it=mapa.begin(); it!=mapa.end(); it++){
            auto skup(it->second);
            int brojac(0);
            cout << it->first << ": ";
            for (auto x : skup) {
                brojac++;
                if (brojac!=skup.size()) cout << x << ",";
                else cout << x;
                
        } 
        cout << endl; }  
}

set<int> PretraziIndeksPojmova(string s, map<string,set<int>> mapa){
    set<int> skup;
    int brojac(0);
    for (auto it=mapa.begin(); it!=mapa.end(); it++){
        if (it->first==s){ skup=it->second; brojac++; } 
    }
    if (brojac==0) throw std::logic_error("Pojam nije nadjen");
    return skup;
}

int main ()
{
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map> //zbog tipa "map"
#include <set>
#include <stdexcept>

using std::string; using std::set; using std::cout;
typedef std::map<string, set<int>> TipMapa;

TipMapa KreirajIndeksPojmova(string s){
    TipMapa mapa;
    for(int i{}; i < s.length(); i++){
        string rijec;
        int j(i);
        while(i < s.length() && ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))){
            rijec.push_back(tolower(s[i])); //u rijec ubaci MALO!!! slovo
            i++;
        }
        if(rijec != string()) mapa[rijec].insert(j);
    }
    return mapa;
}

set<int> PretraziIndeksPojmova(string rijec, TipMapa mapa){ //mapa koja predst indeks pojmova
    set<int> skup;
    auto it2(mapa.find(rijec));
        if(it2 == mapa.end()) throw std::logic_error("Pojam nije nadjen");
        else skup = mapa[rijec];
    return skup;
}

void IspisiIndeksPojmova(TipMapa mapa){
    for(auto it(mapa.begin()); it != mapa.end(); it++){
        cout << it -> first << ": ";
        for(auto it2((it -> second).begin()); it2 != (it -> second).end(); it2++){
            if(it2 != --(it -> second).end()) cout << *it2 << ",";
            else cout << *it2;
        }
        cout << std::endl;
    }
}

int main (){
    cout << "Unesite tekst: ";
    string s;
    getline(std::cin, s);
    IspisiIndeksPojmova(KreirajIndeksPojmova(s));
    string rijec;
    for(;;){
        cout << "Unesite rijec: ";
        std::cin >> rijec;
        if (rijec == ".") break;
        try{
            set<int> skup(PretraziIndeksPojmova(rijec, KreirajIndeksPojmova(s)));
            if(skup.size()) {
                for(int x: skup) cout << x << " ";
                cout << std::endl;
            }
        }
        catch(...){
            cout << "Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}

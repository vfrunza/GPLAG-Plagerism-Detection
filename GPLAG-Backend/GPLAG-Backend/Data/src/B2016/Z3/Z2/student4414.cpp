/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <stdexcept>


using namespace std;

bool slovo(char c) {
    if(c>'a' && c<='z') return true;
    else return false;
}

map<string, set<int>> KreirajIndeksPojmova(string s) {
    map<string, set<int>> m;
    string pom;
    int index=0;
    for(int i=0; i<int(s.length()); i++){
        if(slovo(s[i]) && i<int(s.length())) {
            index = i;
            while(slovo(s[i]) && i<int(s.length())) {
                pom.push_back(s[i]);
                i++;
            }
            m[pom].insert(index);
            pom.resize(0);
        }
    }
    
    return m;
}

set<int> PretraziIndeksPojmova(string s, map<string, set<int>> m) {
    if(!m.count(s)) throw logic_error ("Unesena rijec nije nadjena!\n");
    else return m[s];
}

void IspisiIndeksPojmova(map<std::string, set<int>> mapa) {
    for(auto i1=mapa.begin(); i1!=mapa.end(); i1++) {
        std::cout<<(*i1).first<<": ";
        auto i2=(i1->second).begin();
        while(i2!=--(i1->second).end()) {
            cout<<*i2<<",";
            i2++;
        }
        std::cout<<*i2<<std::endl;
    }
}
int main ()
{
    
    cout<<"Unesite tekst:"<<std::endl;
    string s;
    getline(std::cin, s);
    map<std::string, set<int>> mapa = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    string tacka = {"."};
    for(;;) {
        cout<<"Unesite rijec: ";//<<std::endl;
        string p;
        getline(std::cin, p);
        if(p==tacka) break;
        try {
            set<int> pretraga = PretraziIndeksPojmova(p,mapa);
            for(int x : pretraga) cout<<x<<" ";
        }
        catch(logic_error t) {
            cout<<t.what();
        }
    }
	return 0;
}
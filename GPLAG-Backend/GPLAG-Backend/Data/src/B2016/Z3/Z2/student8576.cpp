/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <map>
#include <set>

using namespace std;

string MakniInterpunkcijuMaloSlovo(string tekst){
    string s = tekst;
    for(int i=0; i<s.size(); i++){
        s[i] = tolower(s[i]);
        if((s[i]<'a' || s[i]>'z') && (s[i]<'0' || s[i]>'9'))
            s[i] = ' ';
    }
    return s;
}

map<string, set<int>> KreirajIndeksPojmova(string tekst) {
    map<string, set<int>> mapa;
    string s = MakniInterpunkcijuMaloSlovo(tekst);
    for(int i=0; i<s.size(); i++) {
        if(s[i]!=' ' && s[i]!='\0'){
            
            int prvi = i;
            while(s[i]!= ' ' && i<s.size())
                i++;
            int j=i;
            string rijec = s.substr(prvi, j-prvi);
            auto it(mapa.find(rijec));
            if(it!=mapa.end()){
                (it->second).insert(prvi);
            }
            else{
                set<int> skup;
                skup.insert(prvi);
                mapa.insert(make_pair(rijec,skup));
            }
        }
    }
    
    return mapa;
}

set<int> PretraziIndeksPojmova(string tekst, map<string,set<int>> pojmovi){
    auto it(pojmovi.find(tekst));
    if(it!=pojmovi.end()){
        return it->second;
    }
    else{
        throw logic_error("Pojam nije nadjen");
    }
}

void IspisiIndeksPojmova(map <string, set<int>> pojmovi){
    for(auto it = pojmovi.begin(); it!=pojmovi.end(); it++){
        cout << it->first << ": ";
        for(auto x=(it->second).begin(); x!=(it->second).end(); x++){
            cout <<*x;
            if(distance(x,(it->second).end())!=1) cout << ",";
        }
        //if(distance(x, (it->second).end())!=1) cout << endl;
        cout << endl;
    }
}

int main ()
{
    string tekst;
    cout << "Unesite tekst: ";
    getline(cin, tekst);
    auto mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    
    while(true) {
        string unos;
        cout << "Unesite rijec: ";
        cin >> unos;
        if(unos==".") break;
        try{
            auto skup = PretraziIndeksPojmova(unos,mapa);
            for(int x : skup) cout <<  x << " ";
            cout << endl;
        }
        catch(logic_error e){
            cout << "Unesena rijec nije nadjena!" << endl;
        }
    }
	return 0;
}
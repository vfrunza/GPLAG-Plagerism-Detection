/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 
map<string, set<int>> KreirajIndeksPojmova(string s){
    map<string, set<int>> izlaz; 
    for(int i=0; i<s.size(); i++){
        s[i]=tolower(s[i]); 
    }
    int pocetak=0; 
    string pomocni; 
    for(int i=0; i<s.size(); i++){
        while(!((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))) i++; 
        if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) pocetak=i; 
        while((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            pomocni.push_back(s[i]);
            i++;
        }
            izlaz[pomocni].insert(pocetak); 
            pomocni.resize(0);
    }
     return izlaz;
}
set<int> PretraziIndeksPojmova(string rijec, map<string, set<int>> mapa){
    set<int> izlaz; 
    for(int i=0; i<rijec.size(); i++){
            rijec[i]=tolower(rijec[i]);
        }
    if(mapa.count(rijec)==1){
        auto it=mapa.find(rijec);
        izlaz=it->second;
    }
    else throw logic_error ("Unesena rijec nije nadjena!"); 
    return izlaz; 
}
void IspisiIndeksPojmova(map<string, set<int>> mapa){
    for(auto i=mapa.begin(); i!=mapa.end(); i++){
        cout << i->first << ": ";
        auto pocetak=i->second.begin(); 
        auto kraj=i->second.end(); 
        kraj--; 
        for(auto j=pocetak; j!=i->second.end(); j++){
            if(j==kraj) cout << *(j); 
            else cout << *(j) << ","; 
        }
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
    string rijec; 
    do{
        cout << "Unesite rijec: "; 
        cin >> rijec; 
        for(int i=0; i<rijec.size(); i++){
            rijec[i]=tolower(rijec[i]);
        }
        if(rijec==".") return 0; 
        try{
            auto skup=PretraziIndeksPojmova(rijec, mapa); 
            auto krajs=skup.end(); 
            krajs--;
            for(auto i=skup.begin(); i!=skup.end(); i++){
                if(i==krajs) cout << *i;
                else cout << *i << " ";
            }
            cout << endl; 
        }
        catch(logic_error poruka){
            cout << poruka.what() << endl;
        }
    }
    while(rijec!=".");
	return 0;
}
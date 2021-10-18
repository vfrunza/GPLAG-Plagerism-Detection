/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>
using namespace std;
map<string,set<int>> KreirajIndeksPojmova(string s)
{
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
    map<string,set<int>> mapa;
    vector<string> rijeci;
    for(int i=0; i<s.length(); i++) {
        string rijec;
        while(s[i]==' ' && i<s.length())i++;
        while(s[i]!=' ' && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>=48 && s[i]<=57))  && i<s.length()) {
            rijec.push_back(s[i]);
            i++;
        }
        bool logicka(true);
        for(int k=0; k<rijeci.size(); k++) if(rijec==rijeci[k]) {
                logicka=false;
                break;
            }
        if(logicka && rijec.size()!=0) {
            rijeci.push_back(rijec);
        }
    }
    for(int i=0; i<rijeci.size(); i++) {
        set<int> skup;
        for(int j=0; j<s.length(); j++) {
            string trazena;
            int a=j;
            while(s[j]!=' ' && ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>=48 && s[j]<=57))  && j<s.length()) {
                trazena.push_back(s[j]);
                j++;
            }
            if(trazena==rijeci[i]) {
                skup.insert(a);
            }
        }
        mapa.insert(make_pair(rijeci[i],skup));
    }
    return mapa;
}

set<int> PretraziIndeksPojmova(string rijec,map<string,set<int>> mapa)
{
    bool logicka(true);
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        if(rijec==it->first) {
            return it->second;
        }
    }
    if(logicka) throw std::logic_error("Unesena rijec nije nadjena!");
}


void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        cout<<it->first<<": ";
        for(auto element: it->second) if(element!=*max_element(it->second.begin(),it->second.end()))cout<<element<<",";
            else cout<<element;
        cout<<endl;
    }
}
int main ()
{
    cout<<"Unesite tekst: ";
    string s;
    getline(cin,s);
    map<string,set<int>> mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    for(;;) {
        cout<<"Unesite rijec: ";
        string rijec;
        getline(cin,rijec);
        if(rijec==".") break;
        try {
            set<int> skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto element: skup)cout<<element<<" ";
        } catch(std::logic_error izuzetak) {
            cout<<izuzetak.what();
        }
        cout<<endl;
    }
    return 0;
}
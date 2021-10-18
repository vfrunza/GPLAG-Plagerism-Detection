/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

using namespace std;

set<int> VratiSkup(string s, string trazeni) {
     
    set<int> skup;
    int i(0);
    while(i<s.size()) {
        int br=0;
        while(((s[i]>='0' && s[i]<='9') ||  (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) && i<s.length()) { 
            if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
            br++;
            i++; 
        }
        if(s.substr(i-br,br)==trazeni) {
            skup.insert(i-br);
        }
        i++;
    }
    return skup;
}

map<string, set<int> > KreirajIndeksPojmova(string tekst) {
    map<string, set<int> > mapa;
    int i(0);
    while(i<tekst.length()){
        int br=0;
        while (((tekst[i]>='0' && tekst [i]<='9') ||  (tekst[i]>='A' && tekst [i]<='Z') || (tekst[i]>='a' && tekst [i]<='z')) && i<tekst.length()) { 
            if(tekst[i]>='A' && tekst[i]<='Z') tekst[i]=tekst[i]+32;
            br++; i++; 
            
        }
        if(br==0) { i++; continue; }
        
        auto it=mapa.begin();
        bool ima=false;
        while(it!=mapa.end()){
            if(it->first==tekst.substr(i-br,br)) ima=true;
            it++;
        }
        
        if(ima) { i++; continue; }
        mapa.insert(make_pair(tekst.substr(i-br,br),VratiSkup(tekst,tekst.substr(i-br,br))));
        i++;
    }
    
    return mapa;
}

set<int> PretraziIndeksPojmova(string rijec, map<string, set<int> > IndeksPojmova) {
    auto it=IndeksPojmova.begin();
    while(it!=IndeksPojmova.end()) {
        if(it->first==rijec) return it->second;
        it++;
    }
    throw logic_error ("Pojam nije nadjen");
}

void IspisiIndeksPojmova(map<string, set<int> > IndeksPojmova) {
    auto it=IndeksPojmova.begin();
    while(it!=IndeksPojmova.end()) {
        cout<<it->first << ": ";
        auto it3=it->second.end();
        it3--;
        for(auto it2=it->second.begin();it2!=it->second.end(); it2++){
            if(it2==it3) cout<<*it2;
            else cout<<*it2<<",";
        }
        cout<<endl;
        it++;
    }
}
int main ()
{
    string tekst;
    cout<<"Unesite tekst: ";
    getline(cin,tekst);
    
    map<string, set<int> > IP=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(IP);
    while(true) {
        cout<< "Unesite rijec: ";
        string rijec;
        getline(cin,rijec);
        if(rijec==".") return 0;
        try{
            set<int> indeksi=PretraziIndeksPojmova(rijec,IP);
            for(auto a=indeksi.begin();a!=indeksi.end();a++){
                cout<<*a<<" ";
            }
        }catch(logic_error e) { cout<<"Unesena rijec nije nadjena!"<<endl; continue; }
        cout<<endl;
    }
    
	return 0;
}
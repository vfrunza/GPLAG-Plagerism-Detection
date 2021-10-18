/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>

using namespace std;

void PretvoriUMala(string &s1){
    for(int i=0;i<s1.length();i++)
    if(s1[i]>='A' && s1[i]<='Z') s1[i]+=32;
}

bool Pomocna(char x){
    if(x>='a' && x<='z') return true;
    if(x>='A' && x<='Z') return true;
    if(x>='0' && x<='9') return true;
    return false;
}
map<string,set<int>>KreirajIndeksPojmova(string s){
    map<string,set<int>>m;
    int i=0;
    while(i<s.length()){
        while(i<s.length() && !Pomocna(s[i])) i++;
        int j=i;
        while(j<s.length() && Pomocna(s[j])) j++;
        if(i==j) return m;
        string efikasnost(s.substr(i,j-i));
        PretvoriUMala(efikasnost);
        if(!m.count(efikasnost)) { m.insert({efikasnost,{i}});}
        else {
            m[efikasnost].insert(i);
        }
        i=j;
    }
    return m;
}

set<int>PretraziIndeksPojmova(string s,map<string,set<int>>m){
    PretvoriUMala(s);
    if(!m.count(s)) { throw logic_error("Unesena rijec nije nadjena!");}
    else return m[s];
}

void IspisiIndeksPojmova(const map<string,set<int>>&m){
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<": ";
        for(auto a=it->second.begin();a!=it->second.end();a++){
            cout<<*a;
            auto x=a;
            x++;
            if(x!=it->second.end()) cout<<',';
        }
        cout<<endl;
    }
}
int main(){
    cout<<"Unesite tekst: ";
    string tekst;
    getline(cin,tekst);
    auto m=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(m);
    while(true){
        string unos;
        cout<<"Unesite rijec: ";
        getline(cin,unos);
        if(unos==".") break;
        try{
            auto kiki(PretraziIndeksPojmova(unos,m));
            for(auto k:kiki) cout<<k<<" ";
            cout<<endl;
        }
        catch(logic_error e){
            cout<<e.what()<<endl;
        }
    }
    return 0;
}
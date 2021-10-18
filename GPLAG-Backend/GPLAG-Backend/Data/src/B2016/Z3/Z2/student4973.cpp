/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>

using namespace std;

map<string,set<int>>KreirajIndeksPojmova(string s)
{
    map<string,set<int>>rijeci;
    vector<string>v;
    string x=(",");
    vector<int>v1;
    int br=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
    for(int i=0; i<s.size(); i++) {
        if(s[i]==' ') {
            br++;
            if(x!=",") {
                v.push_back(x);
                x=",";
            }
            continue;
        }
        if(br!=0) v1.push_back(br);
        if(br==0 && i==0) v1.push_back(0);
        br=0;
        if(x==",") x=s[i];
        else x.push_back(s[i]);
        if(i==s.size()-1 && x!=",") {
            v.push_back(x);
            x=",";
        }
    }
    int suma=0;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(j==0) rijeci[v[i]];
            if(v[i]==v[j]) {
                for(int k=0; k<j; k++) suma+=v[k].size()+v1[k];
                suma+=v1[j];
                rijeci[v[i]].insert(suma);
                suma=0;
            }
        }
    }
    return rijeci;
}

set<int>PretraziIndeksPojmova(string s,map<string,set<int>>rijeci)
{
    set<int>skup;
    auto it=rijeci.begin();
    while(it!=rijeci.end()) {
        if((it->first)==s) {
            return it->second;
        }
        it++;
    }
    throw logic_error(" Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova(map<string,set<int>>rijeci)
{
    for(auto it=rijeci.begin(); it!=rijeci.end(); it++) {
        cout<< it->first <<": ";
        for(auto johi=(it->second).begin(); johi!=(it->second).end(); johi++) {
            if(johi!=(it->second).begin()) cout<<",";
            cout<<*johi;
        }
        cout<<endl;
    }
}

int main ()
{
    string s;
    cout<<"Unesite tekst: ";
    getline(cin,s);
    map<string,set<int>>rijeci=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(rijeci);
    string a;
    set<int>skup;
    bool ima=false;
    for(;;) {
        cout<<"Unesite rijec:";
        getline(cin,a);
        for(auto it=a.begin(); it!=a.end(); it++) {
            if(*it=='.') ima=true;
        }
        if(ima) break;
        try {
            skup=PretraziIndeksPojmova(a,rijeci);
            for(auto it1=skup.begin(); it1!=skup.end(); it1++) {
                if(it1!=skup.end()) cout<<" ";
                cout<<*it1;
            }
            cout<<endl;
        } catch(logic_error tekst) {
            cout<<tekst.what()<<endl;
        }
    }
    return 0;
}
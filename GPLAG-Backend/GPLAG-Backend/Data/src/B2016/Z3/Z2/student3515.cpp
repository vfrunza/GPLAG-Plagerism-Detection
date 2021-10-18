/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <stdexcept>

using namespace std;
map<string,set<int>> KreirajIndeksPojmova(string s)
{
    for(int i=0;i<s.length();i++) {
    if(s[i]>='A' && s[i]<='Z') s[i]+=32; }
    map<string,set<int>> mapa;
    int j;
    vector<string> v;
    for(int i(0);i<s.length();i++)
    {
        string pom; 
        while((s[i]<'a' || s[i]>'z') && (s[i]<'0' || s[i]>'9') ) {if(i==s.length()-1) break; i++; } 
        int h(i);
        while((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            pom+=s[i];
            i++;
            if(i==s.length()-1) break;
        }
        if(i==(s.length()-1)) pom+=s[i];
        bool a=false;
        for(int k=0;k<v.size();k++)
        {
            if(pom==v[k]) { a=true; break;}
        }
        if(a==false) {
        set<int> skup;
        skup.insert(h);
        j=i;
        v.push_back(pom);
        while(i<s.length())
        {
            if(pom==s.substr(i, pom.size()) && (((s[i-1]<'a' || s[i-1]>'z') && (s[i+pom.size()]<'a' || s[i+pom.size()]>'z')) && ((s[i-1]<'0' || s[i-1]>'9') && (s[i+pom.size()]<'0' || s[i+pom.size()]>'9') )))
            { skup.insert(i);}
            i++;
        }
        mapa.insert(make_pair(pom,skup));
        i=j;}
    }
    return mapa;
}
void IspisiIndeksPojmova(map<string,set<int>> mapa)
{
     for(auto it=mapa.begin();it!=mapa.end();it++)
    {
        cout<<it->first<<": ";
        set<int>::iterator p=(it->second).end(); p--;
        for(set<int>::iterator x=(it->second).begin();x!=(it->second).end();x++) { cout<<*x; if(x!=p) cout<<","; }
        cout<<endl;
    }
}
set<int> PretraziIndeksPojmova(string rijec,map<string,set<int>> mapa)
{
    bool a=false;
    set<int> skup;
    for(auto it=mapa.begin();it!=mapa.end();it++)
    {
        if(it->first==rijec) {
            a=true;
            auto pom=(it->second).end(); pom--;
            for(auto x=(it->second).begin();x!=(it->second).end();x++) skup.insert(*x);
        }
    }
    if(!a) throw logic_error("Pojam nije nadjen");
    return skup;
}
int main ()
{
    string s;
    cout<<"Unesite tekst: ";
    getline(cin,s);
    map<string,set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    try{
        string rijec;
    for(;;) {
        cout<<"Unesite rijec: ";
        cin>>rijec;
        if(rijec==".") break;
        set<int> skup=PretraziIndeksPojmova(rijec,mapa);
        set<int>::iterator y=skup.end(); y--;
        for(set<int>::iterator x=skup.begin();x!=skup.end();x++) { cout<<*x; if(x!=y) cout<<" ";}
        cout<<endl;
    }
    }
    catch(logic_error)
    {
        string rijec;
        cout<<"Unesena rijec nije nadjena!"<<endl;;
        cout<<"Unesite rijec: ";
        cin>>rijec;
    } 
   
	return 0;
}
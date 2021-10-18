/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<utility>
using std::vector;
using std::set;
using std::string;
using std::map;
using std::cout;
using std::cin;

string PretvoriUString(vector<char> v){
    string s;
    s.resize(v.size());
    for(int i(0);i<v.size();i++){
        s[i]=v[i];
    }
    return s;
}

void RastaviString(string s,vector<string> &v,vector<int> &h){
    for(int i(0);i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z')
        s[i]=s[i]+32;
    }
    for(int i(0);i<s.length();i++){
        vector<char> v1;
        if(s[i]>='a' && s[i]<='z' && i<s.length()){
            h.push_back(i);
            while(s[i]>='a' && s[i]<='z' && i<s.length()){
                v1.push_back(s[i]);
                i++;
            }
            v.push_back(PretvoriUString(v1));
            v1.resize(0);
        }
    }
}

map<string,set<int>> KreirajIndeksPojmova(string s){
    map<string,set<int>> mapa;
    vector<string> v1,c;
    vector<int> v2;
    RastaviString(s,v1,v2);
    for(int i(0);i<v1.size();i++)
    c.push_back(v1[i]);
    for(int i(0);i<v1.size();i++){
        for(int j(i+1);j<v1.size();j++){
            if(v1[i]==v1[j]){
                for(int g(j);g<v1.size()-1;g++)
                v1[g]=v1[g+1];
                v1.resize(v1.size()-1);
                j--;
            }
        }
    }
    for(int i(0);i<v1.size();i++){
        set<int> skup;
        for(int j(0);j<c.size();j++){
            if(v1[i]==c[j]){
                skup.insert(v2[j]);
            }
        }
        mapa[v1[i]]=skup;
    }
    return mapa;
}

void IspisiIndeksPojmova(map<string,set<int>> mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        cout<<it->first<<": ";
        for(auto x((it->second).begin());x!=(it->second).end();x++){
            auto y(x);
            y++;
            if(y==(it->second).end()) cout<<*x;
            else cout<<*x<<",";
        }
        cout<<"\n";
    }
}

set<int> PretraziIndeksPojmova(string s,map<string,set<int>> mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
                if(it->first==s){
                    return it->second;
                }
            }
    throw std::logic_error("Unesena rijec nije nadjena!");
}
    
   int main ()
{
    string s;
    cout<<"Unesite tekst: ";
    getline(cin,s);
    map<string,set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    string rijec1;
    while(rijec1!="."){
        string rijec;
        cout<<"Unesite rijec: ";
        getline(cin,rijec);
        rijec1=rijec;
        if(rijec!="."){
            set<int> indeksi;
            try{
            indeksi=PretraziIndeksPojmova(rijec,mapa);
            }
            catch(std::logic_error poruka){
                cout<<poruka.what();
            }
            for(auto x:indeksi) cout<<x<<" ";
            cout<<"\n";
        }
    }
    
    
    
	return 0;
}
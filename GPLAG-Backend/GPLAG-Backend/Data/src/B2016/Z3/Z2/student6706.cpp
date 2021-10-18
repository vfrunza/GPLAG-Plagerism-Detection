#include <iostream>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<stdexcept>
using namespace std;
map<string,set<int>> KreirajIndeksPojmova(string s){
    int i=0;
    map<string,set<int>> m;
    while(i!=s.length()){
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+'a'-'A';
        i++;
    }
    i=0;
    while(i<s.length()){
        set<int> c;
        string pomocni;
        pair<string,set<int>> p;
        if(i==0 || (!((s[i-1]>='a' && s[i-1]<='z')||(s[i-1]>='0' && s[i-1]<='9')) && ((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')))){
            int pozicija=i;
            pomocni.push_back(s[i]);
            i++;
            while(((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')) && i<s.length()){ 
                pomocni.push_back (s[i]);
                i++;
            }
            c.insert(pozicija);
            int pomocna=i;
            while(pomocna<s.length()){
                int j=0;
                if(s[pomocna]==pomocni[j] && !((s[pomocna-1]>='a' && s[pomocna-1]<='z')||(s[pomocna-1]>='0' && s[pomocna-1]<='9'))){
                    int poz=pomocna;
                    while(j<pomocni.length() && pomocna<s.length()){
                        j++;
                        pomocna++;
                        if(s[pomocna]!=pomocni[j]) break;
                    }
                    if(j==pomocni.length() && (!((s[pomocna]>='a' && s[pomocna]<='z')||(s[pomocna]>='0' && s[pomocna]<='9')) || pomocna==s.length())){ c.insert(poz);}
                }
                if(pomocna==s.length()-1) break;
                pomocna++;
            }
        }
       if(pomocni.length()!=0){ p=make_pair(pomocni,c);
        m.insert(p);}
        i++;
    }
    return m;
}

set<int> PretraziIndeksPojmova(string s,map<string,set<int>> m){
    auto it=m.begin();
    set<int>a;
    for(it=m.begin(); it!=m.end(); it++){
        if(it->first==s){
            auto i=it->second.begin();
            while(i!=it->second.end()){
                a.insert(*i);
                i++;
            }
            break;
        }
    }
    if(it==m.end()) throw logic_error("Unesena rijec nije nadjena!");
    return a;
}
void IspisiIndeksPojmova(map<string,set<int>> m){
    auto it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<": ";
        auto i=it->second.begin();
        int brojac=0;
        while(i!=it->second.end()){
            if(brojac==it->second.size()-1) cout<<*i;
            else cout<<*i<<",";
            i++;
            brojac++;
        }
        cout<<endl;
        it++;
    }
}
int main (){
    string s;
    cout<<"Unesite tekst: ";
    getline(cin,s);
    map<string,set<int>> m=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    while(1){
        cout<<"Unesite rijec: ";
        string q;
        getline(cin,q);
        if(q==".") break;
        try{
        set<int> a=PretraziIndeksPojmova(q,m);
        for(auto i=a.begin(); i!=a.end(); i++) cout<<*i<<" ";
        }
        catch(logic_error izuzetak){
        cout<<izuzetak.what();
    }
        cout <<endl;
    }
	return 0;
}

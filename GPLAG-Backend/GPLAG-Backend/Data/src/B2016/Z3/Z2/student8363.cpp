/B2016/2017: Zadaća 3, Zadatak 2

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using std::string;
using std::set;
using std::cin;
using std::cout;
using std::map;
using std::endl;

typedef map<string,set<int>> Mapa;

bool notlorn(char a){
    return (!((a>='0' && a<='9') || (a>='a' && a<='z') || (a>='A' && a<='Z')));
}
map<string,set<int>> KreirajIndeksPojmova(string text){
    map<string,set<int>> izlaz;
    for (int i = 0; i < text.size(); i++) {
        if(!notlorn(text[i])){
            int poz=i;
            string tmp;
            for(;i<text.size();i++){
                if (notlorn(text[i])) {
                    break;
                } else {
                    tmp.push_back(std::tolower(text[i]));
                }
            }
            izlaz[tmp].insert(poz);
        }
    } 
    return izlaz;
}
set<int> PretraziIndeksPojmova(string s, Mapa m){
    for (int i = 0; i < s.size(); i++) {
        s[i]=tolower(s[i]);
    }
    auto i = m.begin();
    for(;i!=m.end();i++)
        if(i->first==s)break;
    if(i==m.end())
        throw std::logic_error("Pojam nije nadjen");
    return m[s];
}
void IspisiIndeksPojmova(Mapa m){
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->first<<": ";
        for(auto e=(i->second).begin();e!=(i->second).end();){
            cout<<*e;
            e++;
            if(e!=(i->second).end())cout<<',';
        }
        cout<<endl;
    }
}
int main (){
    string ts;
    cout<<"Unesite tekst: ";
    std::getline(cin,ts);
    auto m = KreirajIndeksPojmova(ts);
    IspisiIndeksPojmova(m);
    while (true) {
        cout<<"Unesite rijec: ";
        cin>>ts;
        if(ts==".")break;
        try{
            auto q = PretraziIndeksPojmova(ts,m);
            for(auto i = q.begin();i!=q.end();i++)
                cout<<*i<<" ";
            cout<<endl;
        }catch(std::logic_error e){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }
	return 0;
}
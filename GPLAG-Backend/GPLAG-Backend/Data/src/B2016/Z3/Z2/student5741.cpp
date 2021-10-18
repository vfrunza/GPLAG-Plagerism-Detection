/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::logic_error;
using std::set;
using std::make_pair;
using std::vector;

map<string,set<int>> KreirajIndeksPojmova(string s){
    map<string,set<int>> mapa;
    for(int i=0;i<s.length();i++){
        string s1;
        int broj(i);
        while(i<s.length() && ((s[i]>='a' && s[i]<='z') || (s[i]>='1' && s[i]<='9') || (s[i]>='A' && s[i]<='Z'))){
            auto slovo(s[i]);
            if(slovo>='A' && slovo<='Z'){
                slovo=slovo+'a'-'A';
            }
            s1.push_back(slovo);
            i++;
        }
        if(broj!=i){
            auto it(mapa.find(s1));
            if(it==mapa.end()){
                mapa.insert(make_pair(s1,set<int>{broj}));
            }
            else{
                it->second.insert(broj);
            }
        }
    }
    return mapa;
}

void IspisiIndeksPojmova(map<string,set<int>> mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        cout<<it->first<<": ";
        set<int> skup(it->second);
        for(auto it1=skup.begin();it1!=skup.end();it1++){
            auto it2(skup.end());
            it2--;
            if(it1!=it2){
                cout<<*it1<<",";
            }
            else cout<<*it1;
        }
        cout<<endl;
    }
}

set<int> PretraziIndeksPojmova(string s1,map<string,set<int>> mapa){
    for(int i=0;i<s1.length();i++){
        if(s1[i]>='A' && s1[i]<='Z'){
            s1[i]=s1[i]+'a'-'A';
        }
    }
    auto it(mapa.find(s1));
    if(it!=mapa.end()){
        return it->second;
    }
    else{
        throw logic_error("Pojam nije nadjen");
    }
}

int main ()
{
    string s;
    cout<<"Unesite tekst: ";
    std::getline(cin,s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    string s1;
    while(s1!="."){
        cout<<"Unesite rijec: ";
        getline(cin,s1);
        if(s1=="."){
            break;
        }
        try{
            auto skup(PretraziIndeksPojmova(s1,mapa));
            for(auto it=skup.begin();it!=skup.end();it++){
                cout<<*it<<" ";
            }
        }
        catch(logic_error izuzetak){
            cout<<"Unesena rijec nije nadjena!";
        }
        cout<<endl;
    }
    return 0;
}
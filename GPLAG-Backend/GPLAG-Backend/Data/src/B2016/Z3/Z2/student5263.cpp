/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::make_pair;
using std::logic_error;
string Uvecu (string s){
    string novi;
    for(int i=0;i<s.length();i++) novi.push_back(toupper(s[i]));
    return novi;
}
string Umanju (string s){
    string novi;
    for(int i=0;i<s.length();i++) novi.push_back(tolower(s[i]));
    return novi;
}
bool SlovoIliBroj (char c){
    return (((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')));
}
map<string,set<int>> KreirajIndeksPojmova (string s){
    vector<string> v;
    bool prva(true);
    for(int i=0;i<s.length();i++){
        if(!SlovoIliBroj(s[i])) continue;
        else{
            string rijec;
            while(SlovoIliBroj(s[i])){
                rijec.push_back(s[i]); i++;
            }
            if(prva) {v.push_back(rijec);}
            else{
                bool ima(false);
                for(int j=0;j<v.size();j++){
                    if(Uvecu(v[j])==Uvecu(rijec)) {ima=true;break;}
                }
                if (!ima) v.push_back(Umanju(rijec));
            }
            prva=false;
        }
    }
    vector<set<int>> ves(v.size());
    for(int i=0;i<v.size();i++){
        for(int j=0;j<s.length();j++){
            if(!SlovoIliBroj(s[j])) continue;
            else{
                int poc(j);
                string rijec;
                while(SlovoIliBroj(s[j])){
                    rijec.push_back(s[j]);
                    j++;
                }
                if(Uvecu(rijec)==Uvecu(v[i])){
                    ves[i].insert(poc);
                }
            }
        }
    }
    map<string,set<int>> mapa;
    for(int i=0;i<v.size();i++){
        mapa.insert(std::make_pair(v[i],ves[i]));
    }
    return mapa;
}
set<int> PretraziIndeksPojmova (string s,map<string,set<int>> mapa){
    auto it(mapa.begin());
    for(it=(mapa.begin());it!=mapa.end();it++){
        if((it->first)==s) break;
    }
    if(it==mapa.end()) throw logic_error ("Pojam nije nadjen");
    else {return (it->second);}
}
void IspisiIndeksPojmova (map<string,set<int>> mapa){
    for(auto it(mapa.begin());it!=mapa.end();it++){
        cout<<it->first<<": ";
        for(auto it1((it->second).begin());it1!=(it->second).end();it1++){
            if(it1==(it->second).begin()) cout<<*it1;
            else cout<<","<<*it1;
        }
        cout<<endl;
    }
}
int main ()
{
    cout<<"Unesite tekst: ";
    string s;
    getline(cin,s);
    map<string,set<int>> mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    for(;;){
        cout<<"Unesite rijec: ";
        string str;
        getline(cin,str);
        if(str==".") break;
        try{
            set<int> skup(PretraziIndeksPojmova(str,mapa));
            for(auto it(skup.begin());it!=skup.end();it++) cout<<*it<<" ";
            cout<<endl;
        }
        catch(logic_error izuzetak){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }
	return 0;
}
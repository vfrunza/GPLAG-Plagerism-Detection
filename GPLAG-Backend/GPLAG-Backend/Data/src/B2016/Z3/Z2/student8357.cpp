#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <set>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::set;
set<int> DajSkup(string s,string rijec){
    set<int> skup;
    for(int i=0;i<s.length();i++){
        while((s[i]<'A' && s[i]>'Z') || (s[i]<'a' && s[i]>'z') || (s[i]<'0' && s[i]>'9')){
            i++;
            if(i==s.length()) break;
        }
        int broj_slova(0),pozicija(i);
        while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            i++;
            broj_slova++;
            if(i==s.length()) break;
        }
        string pomocni(s.substr(pozicija,broj_slova));
        if(rijec==pomocni) skup.insert(pozicija);
    }
    return skup;
}

map<string,set<int>> KreirajIndeksPojmova(string s){
    map<string,set<int>> Rezultat;
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
    for(int i=0;i<s.length();i++){
        while((s[i]<'A' && s[i]>'Z') || (s[i]<'a' && s[i]>'z') || (s[i]<'0' && s[i]>'9')){
            i++;
            if(i==s.length()) break;
        }
        int broj_slova(0),pozicija(i);
        while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            i++;
            broj_slova++;
            if(i==s.length()) break;
        }
        string pomocni(s.substr(pozicija,broj_slova));
        set<int> skup;
        if(pomocni!=""){
        skup=DajSkup(s,pomocni);
        Rezultat.insert(std::make_pair(pomocni,skup));
        }
    }
    return Rezultat;
}

set<int> PretraziIndeksPojmova(string s,map<string,set<int>> pojmovi){
    auto it(pojmovi.begin());
    while(it!=pojmovi.end()){
        if(it->first==s){
            return it->second;
        }
        it++;
    }
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(map<string,set<int>> pojmovi){
    auto it(pojmovi.begin());
    while(it!=pojmovi.end()){
        cout<<(it->first)<<": ";
        auto it1((it->second).begin());
        int i(1);
        while(it1!=(it->second).end()){
            cout<<*it1++;
            if(i++!=std::distance((it->second).begin(),(it->second).end())) cout<<",";
        }
        cout<<endl;
        it++;
    }
}
int main ()
{
    cout<<"Unesite tekst: ";
    string s;
    getline(cin,s);
    map<string,set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    string unos;
    do{
        cout<<"Unesite rijec: ";
        getline(cin,unos);
        if(unos==".") break;
        else{
            set<int> skup;
            try{
            skup=PretraziIndeksPojmova(unos,mapa);
            }catch(...){
                cout<<"Unesena rijec nije nadjena!";
            }
            auto it(skup.begin());
            while(it!=skup.end()){
                cout<<*it++<<" ";
            }
        }
        cout<<endl;
    }while(unos!=".");
	return 0;
}
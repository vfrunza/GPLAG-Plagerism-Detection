/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <stdexcept>
#include <cstring>
using namespace std;

set<int>pozicija(string recenica,string rijec){
    set<int>skup_pozicija;
    int i=0;
    while(i<recenica.size()){
        if(recenica[i]==rijec[0] && (i==0 || recenica[i-1]==' ')){ 
            int j=0;
            int pozicija=i;
            while(j<rijec.size() && i<recenica.size()){
                if(rijec[j]!=recenica[i]) break;
                j++;
                i++;
            }
            if(j==rijec.size()) skup_pozicija.insert(pozicija);
        }
        else i++;
    }
    return skup_pozicija;
}

map<string,set<int>>KreirajIndeksPojmova(string s){
    int j=0;
    //pretvaranje velikih slova u mala
    while(j<s.size()){
        if(s[j]>='A' && s[j]<='Z') { s[j]+=32; }
        else j++;
    }
    map<string,set<int>>mapa;
    int i=0;
    while(i<s.size()){  
        if((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            int pocetak=i; 
            while((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')) i++;
            int kraj=i+1;
            string rijec;
            while(pocetak!=kraj-1){ rijec+=s[pocetak]; pocetak++; }
            set<int>skup;
            skup=pozicija(s,rijec);
            mapa.insert(make_pair(rijec,skup));
    }
    else i++;
    } 
    return mapa;
}

set<int>PretraziIndeksPojmova(string rijec, map<string,set<int>>indeks_pojmova){ 
    set<int>skup;
    for(auto it=indeks_pojmova.begin();it!=indeks_pojmova.end();it++){
        if(rijec==it->first){
            for(auto x:it->second) skup.insert(x);
        }
    }
    if(skup.size()==0) throw logic_error("Unesena rijec nije nadjena!");
    return skup;
}

void IspisiIndeksPojmova(map<string,set<int>>indeks_pojmova){
    for(auto it=indeks_pojmova.begin();it!=indeks_pojmova.end();it++){
        cout<<it->first<<": ";
        int brojac=0;
        for(auto x:it->second){
            if(brojac==it->second.size()-1)cout<<x;
         else cout<<x<<",";
         brojac++;}
        cout<<endl;
    }
}

int main(){
    try{
        string tekst;
        cout<<"Unesite tekst: ";
        getline(cin,tekst);
        map<string,set<int>>mapa;
        mapa=KreirajIndeksPojmova(tekst);
        IspisiIndeksPojmova(mapa);
        for(;;){
            string rijec;
            set<int>skup;
            cout<<"Unesite rijec: ";
            getline(cin,rijec);
            if(rijec==".") break;
            skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto x:skup)cout<<x<<" ";
            cout<<endl;
        }
    }
    catch(logic_error izuzetak){
        cout<<izuzetak.what()<<endl<<"Unesite rijec: ";
    }
	return 0;
}

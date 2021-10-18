/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>
#include <utility>

using namespace std;

bool Slovo(char slovo){
    if((slovo>='a' && slovo<'z') || (slovo>='A' && slovo<='Z') || (slovo>='0' && slovo<='9'))return true;
    return false;
}

vector<int> VratiIndeks(string s1,string s2){
    vector<int>vrati;
    string::iterator it=s1.begin();string::iterator it1=s1.begin();
    int indeks;
    while(it!=s1.end()){
        string::iterator p=it;
        string::iterator q=s2.begin();
        if(*p==*q)indeks=p-it1;
        while(*p++==*q++){if(q==s2.end() && p-s2.size()==s1.begin() && Slovo(*p)==false){vrati.push_back(indeks);} else if(q==s2.end() && p==s1.end() && Slovo(*(p-s2.size()-1))==false)vrati.push_back(indeks);else if(q==s2.end() && Slovo(*p)==false && Slovo(*(p-s2.size()-1))==false)vrati.push_back(indeks);if(p==s1.end())break;}
        it++;
    }
    return vrati;
}

string PretvoriUMalaSlova(string s){
    string vrati(s);
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z')vrati[i]=s[i]+32;
    }
    return vrati;
}

map<string,set<int>> KreirajIndeksPojmova(string tekst){
    map<string,set<int>>rezultat;
    vector<string>vs(0);
    for(int i=0;i<tekst.length();i++){
        string pomocni;
        bool a(false);
        while((tekst[i]>='a' && tekst[i]<='z' && i!=tekst.length()) || (tekst[i]>='A' && tekst[i]<='Z' && i!=tekst.length()) || (tekst[i]>='0' && tekst[i]<='9' && i!=tekst.length())){pomocni.push_back(tekst[i]);a=true;i++;}
        if (a==true)vs.push_back(pomocni);
        else continue;
    }
    for(int i=0;i<tekst.length();i++){
        int brojac(0);int trenutna_pozicija=i;
        while((tekst[i]>='a' && tekst[i]<='z' && i!=tekst.length()) || (tekst[i]>='A' && tekst[i]<='Z' && i!=tekst.length()) || (tekst[i]>='0' && tekst[i]<='9' && i!=tekst.length())){brojac++;i++;}
        for(int j=0;j<vs.size();j++){
        string rijec=vs[j];
        if(tekst.substr(trenutna_pozicija,brojac)==vs[j]){
        vector<int>v_ind=VratiIndeks(PretvoriUMalaSlova(tekst),PretvoriUMalaSlova(vs[j]));
        set<int>skup;
        for(int k=0;k<v_ind.size();k++)
            skup.insert(v_ind[k]);
        rezultat.insert(make_pair(PretvoriUMalaSlova(vs[j]),skup));
        } 
        }
    }
    return rezultat;
}

set<int> PretraziIndeksPojmova(string rijec,map<string,set<int>>IndeksPojmova){
    set<int>vrati_skup;bool a(false);
    for(auto it=IndeksPojmova.begin();it!=IndeksPojmova.end();it++){
        if(it->first==PretvoriUMalaSlova(rijec)){a=true;vrati_skup= it->second;return vrati_skup;}
    }
    if(a==false)throw logic_error("Pojam nije nadjen");
    return vrati_skup;
}

void IspisiIndeksPojmova(map<string,set<int>>indekspojmova){
    for(auto it=indekspojmova.begin();it!=indekspojmova.end();it++){
        cout<<it->first<<": ";
        int vel(it->second.size()),brojac(0);
        for(int x:it->second){brojac++;if(brojac<vel)cout<<x<<',';else cout<<x;}
        cout<<endl;
    }
}

int main ()
{
    cout<<"Unesite tekst: ";
    string s;
    getline(cin,s);
    map<string,set<int>>rez=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(KreirajIndeksPojmova(s));
    string rijec;
    do {
       cout<<"Unesite rijec: ";
       //cin.ignore(1000,'\n');
       getline(cin,rijec);
       if(rijec==".")break;
       try {
       set<int>ispisi=PretraziIndeksPojmova(rijec,rez);
       for(int x:ispisi)cout<<x<<" ";
       cout<<endl;
           
       }
       catch(logic_error l){
           cout<<"Unesena rijec nije nadjena!"<<endl;
       }
    } while(rijec!=".");
   

	return 0;
}
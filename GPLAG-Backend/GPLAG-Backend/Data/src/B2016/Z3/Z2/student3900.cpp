/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <iterator>
using namespace std;

void Pretvori(string &s){
    for(int i=0; i<s.length(); i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
}

map<string, set<int>> KreirajIndeksPojmova(string s){
    
    map<string, set<int>>mapa;
    string s1;
    int in=0;
    Pretvori(s);
    for(int i=0; i<s.length(); i++){

        if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') && i<s.length()){
            in=i;
            while(((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && i<s.length()){
            
            s1.push_back(s[i]);
           i++;
            
        }
        mapa[s1].insert(in);
        s1.clear();
        
    }
    
    }
return mapa;
}
set<int> PretraziIndeksPojmova(string s1, map<string,set<int>>mapa){
   if(!mapa.count(s1)) throw logic_error("Pojam nije nadjen");
    else return mapa[s1];
}
void IspisiIndeksPojmova(map<string, set<int>>mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        cout<<it->first<<": ";
        auto it2=it->second.begin();
        while(it2!=--(it->second.end())){
            cout<<*it2<<",";
            it2++;
        }
        cout<<*it2<<"";
        cout<<endl;
    }
}
int main ()
{
   cout<<"Unesite tekst: ";
   string s;
   string s2;
   getline(cin, s);
   map<string, set<int>>mapa=KreirajIndeksPojmova(s);
   IspisiIndeksPojmova(mapa);
   int i=0;
   for(;;){
       cout<<"Unesite rijec: ";
       getline(cin, s2);
       if(s2==".") break;
       try{
           set<int>nadji=PretraziIndeksPojmova(s2, mapa);
           for(int x:nadji) cout<<x<<" ";
           cout<<endl;
       }
       catch(logic_error poruka){
           cout<<"Unesena rijec nije nadjena!"<<endl;
       }
       i++;
   }
   return 0;
}
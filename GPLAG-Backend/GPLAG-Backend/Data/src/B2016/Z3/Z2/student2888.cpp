/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
map<string,set<int>>KreirajIndeksPojmova(string s){
    map<string,set<int>>m;
    set<int>skup;
    string rijec;
    int pocetni_index=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
        
            while(s[i]!=' ' && i<s.size()) i++;
                pocetni_index=i;
            rijec=s.substr(pocetni_index,i-pocetni_index);
            cout<<rijec;
            skup.insert(pocetni_index);
           int temp=i;
           while(temp<s.size()){
               if(s[temp]==' ') temp++;
               int k=0;
               if(s[temp]==rijec[k]){
                   int a=temp;
                   while(s[temp]==rijec[k]){
                       temp++;
                       k++;
                   }
                   if(s[temp]==' ' || temp==s.size()) skup.insert(a);
               }
               temp++;
           }
           auto it=m.find(rijec);
           if(it!=m.end())
           m[rijec]=skup;
        }
    }
    return m;
}

void IspisiIndeksPojmova(map<string,set<int>> IndeksPojmova)
{
    for(auto it(IndeksPojmova.begin()); it != IndeksPojmova.end(); it++)
    {
        cout << it->first << ": ";
        int br(it->second.size());
        for(auto x: it->second)
        {
            if(br != 1)
                cout << x <<",";
            else
                cout << x;
            br--;
        }
        cout << endl;
    }
}

set<int> PretraziIndeksPojmova(string s,map<string, set<int>> IndeksPojmova)
{
    auto it(IndeksPojmova.find(s));
    if(it == IndeksPojmova.end()) throw logic_error("Pojam nije nadjen!");
    else    return it->second;
}

int main ()
{
    string s, rijec;
    cout <<"Unesite tekst: ";
    getline(cin, s);
    
    auto mapa = (KreirajIndeksPojmova(s));
    
    IspisiIndeksPojmova(mapa);
    
    for(;;) {
        set<int> skup_indeksa;
        cout << "\nUnesite rijec: ";
        getline(cin, rijec);
        if(rijec == ".") break;
        try {
       skup_indeksa = (PretraziIndeksPojmova(rijec, mapa));
        } catch(logic_error izuzetak) {
        cout<< izuzetak.what();
    }
        for(auto x: skup_indeksa) cout << x << " ";
    }
   
	return 0;
}
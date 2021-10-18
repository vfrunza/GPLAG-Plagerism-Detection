/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
#include <stdexcept>
using namespace std;

map<string,set<int>> KreirajIndeksPojmova (string s){
    map<string,set<int>> mapa;
    vector<string> rijeci;
    vector<int> indexi;
    
     for(auto &x: s) x=tolower(x);
     
     for (int i = 0; i < s.size(); i++){
                        int pocetni_index=0;
                        while(((s[i]>='0' and s[i]<='9') or (s[i]>='a' and  s[i]<='z'))and i<s.size()){
                            pocetni_index++;
                            i++;
                        }
                        
                             rijeci.push_back(s.substr(i-pocetni_index, pocetni_index));
                             
                             indexi.push_back(i-pocetni_index);
                            
                        
                
     }
    
    for(int i=0;i<rijeci.size();i++){
        set<int> ind;
        for(int j=i+1;j<rijeci.size();j++){
            
            if(rijeci[i]!=" "){
            
            ind.insert(indexi[i]);
            if(rijeci[i]==rijeci[j]){
                ind.insert(indexi[j]);
                rijeci[j]=" ";
            }
        
                
            }
        }
        if(rijeci[i].length()!=0 and rijeci[i]!=" "){
        mapa.insert(make_pair(rijeci[i],ind));
        ind.clear();
        }
    }
   

    return mapa;

}

set<int> PretraziIndeksPojmova(string s, map<string, set<int>> mapa){
    bool nadjen=false;
    for(auto &x: s) x=tolower(x);
    
    for(auto it=mapa.begin(); it!=mapa.end();it++){
        if(s==it->first){
            return mapa[s];
        }
    }
    throw logic_error ("Pojam nije nadjen");
}

void IspisiIndeksPojmova(map<string,set<int>> mapa){
    
    for(auto rijec: mapa){
       if(rijec.first==" ")continue;
        cout<<rijec.first<<": ";
        int vel=rijec.second.size(), br=0;
            
            for(int skup: rijec.second){
                cout<<skup;
                if(br!=vel-1) cout<<",";
                br++;
            }
            cout<<endl;
    }
    
}

int main (){
    try{
    cout<<"Unesite tekst: ";
    string s;
    getline(cin,s);
    IspisiIndeksPojmova(KreirajIndeksPojmova(s));
    for(;;){
        try{
        cout<<"Unesite rijec: ";
        string s1;
        getline(cin,s1);
        if(s1==".") return 0;
        
        set<int> berinabratmoj=PretraziIndeksPojmova(s1,KreirajIndeksPojmova(s));
        
        for(auto x: berinabratmoj) cout<<x<<" ";
        cout<<endl;
        }catch(logic_error e){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
        
    }
    
    }catch(domain_error hi){
        cout<<hi.what();
    }
	return 0;
}
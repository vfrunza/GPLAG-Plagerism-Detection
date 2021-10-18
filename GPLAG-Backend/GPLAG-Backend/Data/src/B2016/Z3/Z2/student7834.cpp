/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::vector;
using std::set;
using std::make_pair;


map<string, set<int>> KreirajIndeksPojmova(string s) {
    vector<string> v;
    map<string, set<int>> mapa;
    int br(0);
    string n;
    s+=" ";
    for(int i=0; i<s.size(); i++) {
        
        if( (s[i]>='0' && s[i]<='9') || isalpha(s[i])  ) n.push_back(s[i]);
      else  if(n.size()!=0)
           { v.push_back(n);
           n.clear();
            
        }
    }

    for(int k=0; k<v.size(); k++) {
     
    for(int i=0; i<s.size(); i++) {
        int j(0);
        int f=i;
        while(s[i]==v[k][j] ) {
            if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32; 
            if(v[k][j]>='A' && v[k][j]<='Z') v[k][j]=v[k][j]+32; 
            i++;
            j++;
        }
        
        if( isalpha(s[i])==false && j==v[k].size() && (f==0 || isalpha(s[f-1])==false )) {
            
            br=i-j;
            mapa[v[k]].insert(br);
            
        }
    }
    
    }
    
    return mapa;
}


set<int> PretraziIndeksPojmova(string s, map<string, set<int>> mapa) {
    
    set<int> skup;
    for(int i=0; i<s.size(); i++) if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
    
    int br(0);
    for(auto it=mapa.begin(); it!=mapa.end(); it++) 
        
        if(s==it->first) {
            skup=it->second;
            br++;
        }
        

    if(br==0) throw std::logic_error("Unesena rijec nije nadjena!");
    
    return skup;
    
}


void IspisiIndeksPojmova (map<string,set<int>> mapa) {
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        cout<<it->first<<": ";
        int br(0);
        for(int x: it->second) {
            if(br==(it->second).size()-1) cout<<x;
            else cout<<x<<",";
            
            br++;
        }
        cout<<endl;
    }
}


int main ()
{
    string s;
    
    cout<<"Unesite tekst: ";
    
    std::getline(cin,s);
    
    map<string, set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    
    string rijec,znak(".");
    
    for(;;){
    try{
    cout<<"Unesite rijec: ";
    std::getline(cin,rijec);
    
    if(rijec==znak) break;
    set<int> skup;
    skup=PretraziIndeksPojmova(rijec,mapa);
    for(int x: skup) cout<<x<<" ";
    cout<<endl;
    }
    catch(std::logic_error i) {
        cout<<i.what()<<endl;
    }
    }

    
	return 0;
}





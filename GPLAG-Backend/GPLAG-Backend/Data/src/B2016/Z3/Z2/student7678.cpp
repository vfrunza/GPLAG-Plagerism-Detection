/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <stdexcept>
#include <iomanip>

using std::set;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::make_pair;
using std::logic_error;
using std::setw;
using std::getline;

map<string, set<int>> KreirajIndeksPojmova(string s){
    map<string,set<int>> mapa;
    
    for(int i=0; i<s.length(); i++){
        if(s[i]>='A'&& s[i]<='Z')s[i]=s[i]+32;
    }
    
    for(int i=0; i<s.length(); i++){
        int j;
        for(j=i;j<s.length() ;j++){
            if((s[j]>='a' && s[j]<='z') || (s[j]>'0' && s[j]<'9'))continue;
            else break;
            
        }
        if(i==j)continue;
        string rijec = s.substr(i,j-i);
        
        if(mapa.count(rijec)==0){
            mapa.insert(make_pair(rijec,set<int>{i}));
        }
        else{
            mapa[rijec].insert(i);
        };
        
        i=j;
        
        
    }
    
    return mapa;
}

set<int> PretraziIndeksPojmova(string rijec, map<string,set<int>> ipojmova){
    
    
    auto it (ipojmova.find(rijec));
    if(it == ipojmova.end())throw logic_error("Pojam nije nadjen");
    
    return it->second;

    
}

void IspisiIndeksPojmova( map<string,set<int>> ipojmova){
    
    for (auto it=ipojmova.begin(); it!=ipojmova.end(); it++){
        cout<<it->first<<": ";
        set<int> skup;
        skup = it->second;
        
        for(auto x:skup){
            if(x==*(--skup.end())){cout<<x;break;}
            cout<<x<<",";
        }
        
        cout<<endl;
    }
}
int main ()
{
    
        string s;
        cout<<"Unesite tekst: ";
        
        getline(cin,s);
        
        IspisiIndeksPojmova(KreirajIndeksPojmova(s));
        
        
        for(;;){
            string rijec;
            cout<<"Unesite rijec: ";
            getline(cin,rijec);
            if(rijec == ".")break;
            set<int> skup;
            
            try{
                skup =PretraziIndeksPojmova(rijec,KreirajIndeksPojmova(s));
                
            }
            
            catch(logic_error i){
                cout<<"Unesena rijec nije nadjena!"<<endl;
                continue;
            }
            
            for(auto x:skup)cout<<x<<" ";
            cout<<endl;
            
        }
    
    
        
    
    
    
    
    
    
	return 0;
}
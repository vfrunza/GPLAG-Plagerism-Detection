/B2016/2017: Zadaća 3, Zadatak 2
/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <cctype>
using namespace std;

 bool JeLiRijec (char c){
     if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) return true;
     return false;
 }


map<string, set<int>> KreirajIndeksPojmova (string s){
    string temp;
     for(int i=0; i<s.size(); i++)
      s[i]=tolower(s[i]);
      
    map<string, set<int>> nova;
    int index;
    for(int i=0; i<s.size(); i++){
       if(JeLiRijec(s[i])==1){
           index=i;
           while(JeLiRijec(s[i]) && i<s.size())  i++;
           temp=s.substr(index, i-index);
           if(nova.count(temp)) {
           auto i=nova.find(temp);
           i->second.insert(index);
           }
           else nova.insert(make_pair(temp, set<int> {index}));
           
       } 
    }
    return nova;
}


    set<int> PretraziIndeksPojmova (string s, map<string, set<int>> mapa){
       if( mapa.count(s)){
           auto i=mapa.find(s);
           return i->second;
    }
    throw logic_error("Pojam nije nadjen");
    }
    
    void IspisiIndeksPojmova(map<string, set<int>> mapa){
            for(auto i=mapa.begin(); i!=mapa.end(); i++){
        cout<<i->first<<": ";
        for(auto j=i->second.begin(); j!=i->second.end(); ){
        cout<<*j;
        j++;
        if(j!=i->second.end()) cout<<",";
        
    }
      cout<<endl;  
    }
    }
    
   void IspisiSkup (set <int> skup){
             for(auto j=skup.begin(); j!=skup.end(); ){
        cout<<*j;
        j++;
        if(j!=skup.end()) cout<<" ";
        
    }
      cout<<endl;  
    }
    

int main(){
    cout<<"Unesite tekst: ";
    string s;
    getline(cin, s);
    map<string, set<int>> mapa;
    
    mapa=KreirajIndeksPojmova(s);
    //mapa=KreirajIndeksPojmova("abc qwe stsda abc abc dhi qwe hrkw dhi");
 IspisiIndeksPojmova(mapa);
 set <int> skup;
    string rijec;
    while(1){
        cout<<"Unesite rijec: ";
        cin>>rijec;
        if(rijec==".") break;
        try{skup=PretraziIndeksPojmova(rijec, mapa);
        IspisiSkup(skup);
        }
        catch(logic_error){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
        
    }
    return 0;
}
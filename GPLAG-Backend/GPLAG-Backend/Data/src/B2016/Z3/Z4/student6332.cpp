/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<vector>
#include<string>
#include<set>
#include<list>
#include<stdexcept>
using namespace std;

int KolikoSlova(string s){
    int brojac=0;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) brojac++;
    }
    
    return brojac;
}


vector<set<string>> Razvrstavanje(vector<string> v, int k){
    if(k<1 || k>v.size()) throw logic_error("Razvrstavanje nemoguce");
    
    list<string> lista;
    for(int i=0;i<v.size();i++) lista.push_back(v[i]);
    int n=0;
    for(string x: lista) n++;
    
    vector<set<string>> skup(k);
    int x=n%k, x1=int(n/k)+1;
    int y1=int(n/k);
    
int p=1;
    auto it=lista.begin();
    for(int i=0;i<x;i++){
        for(int j=0;j<x1;j++){
            int m=0;
            while(m<p-1){  
                it++; m++;
                if(it==lista.end()) it=lista.begin();
                
            }
          
          
            p=KolikoSlova(*it);
            (skup[i]).insert(*it); 
            
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
            
        }
       
    }
    
    
    for(int i=x;i<k;i++){
        for(int j=0;j<y1;j++){
            int m=0;
            while(m<p-1){
                it++; m++;
                if(it==lista.end()) it=lista.begin();
                
            }
            p=KolikoSlova(*it);
            skup[i].insert(*it);
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
        }
        
    }
    
    return skup;
    
}


int main ()
{
    
    cout<<"Unesite broj djece: ";
    int n;
    cin>>n;
    cout<<"Unesite imena djece: \n";
    vector<string> v(n);
    cin.ignore(1000,'\n');
    for(int i=0;i<n;i++) getline(cin,v[i]);
    cout<<"Unesite broj timova: ";
    int k;
    cin>>k;
    try{
    vector<set<string>> skup;
    skup=Razvrstavanje(v, k);
    
    for(int i=0;i<skup.size();i++){
        cout<<"Tim "<<i+1<<": ";
        auto it=skup[i].begin();
        int x=distance(skup[i].begin(), skup[i].end());
        
        for(int i=0;i<x-1;i++){ cout<<*it<<", "; it++;}
        cout<<*it;
        cout<<endl;
    }
    }
    catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include<string>
#include<stdexcept>
#include<set>
#include<vector>
#include<memory>
using namespace std;

struct Dijete{
string ime;
shared_ptr<Dijete> sljedeci;
    
};

shared_ptr<Dijete> KreirajListu(vector<string> v){
    shared_ptr<Dijete> pocetak=nullptr, prethodni=nullptr;
    for(int i=0;i<v.size();i++){
        shared_ptr<Dijete> novi(new Dijete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        
        if(pocetak==novi) prethodni=novi;
        else prethodni->sljedeci = novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
    }


int KolikoSlova(string s){
    int brojac=0;
    for(int i=0;i<s.size();i++)
    if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) brojac ++;
    return brojac;
}

vector<set<string>> Razvrstavanje(vector<string> v, int k){
    if(k<1 || k>v.size()) throw logic_error("Razvrstavanje nemoguce");
    auto pok=KreirajListu(v);
    int n=v.size();
    
    auto pomoc=pok->sljedeci;
    while(pomoc->sljedeci != pok) pomoc=pomoc->sljedeci;
    
    vector<set<string>> skup(k);
    int x=n%k, x1=int(n/k)+1;
    int y1=int(n/k);
    int p=1;
    
    for(int i=0;i<x;i++){
        for(int j=0;j<x1;j++){
            int m=0;
            while(m<p-1){
                pomoc=pok;
                pok=pok->sljedeci;
                m++;
            }
            
            p=KolikoSlova(pok->ime);
            skup[i].insert(pok->ime);
            auto pom=pok;
            pok=pok->sljedeci;
            pomoc->sljedeci=pok;
           
            pom=nullptr;
            
            
            
        }
    }
    
    for(int i=x; i<k;i++){
        for(int j=0;j<y1;j++){
            int m=0;
            
            while(m<p-1){
                pomoc=pok;
                pok=pok->sljedeci;
                m++;
            }
            p=KolikoSlova(pok->ime);
            skup[i].insert(pok->ime);
            auto pom=pok;
            pok=pok->sljedeci;
            pomoc->sljedeci=pok;
            
            if(pom!=nullptr){
            pom->sljedeci=nullptr;
            pom=nullptr;
            
            }
            pom=nullptr;
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
    cin.ignore(1000, '\n');
    for(int i=0;i<n;i++) getline(cin, v[i]);
    cout<<"Unesite broj timova: ";
    int k;
    cin>>k;
    try{
        vector<set<string>> skup;
        skup=Razvrstavanje(v,k);
        
        for(int i=0;i<skup.size();i++){
            cout<<"Tim "<<i+1<<": ";
            auto it=skup[i].begin();
            int x=distance(skup[i].begin(), skup[i].end());
            for(int i=0;i<x-1;i++){
                cout<<*it<<", ";
                it++;
            }
            cout<<*it;
            cout<<endl;
        }
    }
    catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
        
    
	return 0;
}
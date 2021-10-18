#include <iostream>
#include <cstring>
#include <set>
#include <list>
#include <stdexcept>
#include<vector>
using namespace std;
struct Dijete{
    string ime;
    Dijete* sljedeci;
    shared_ptr<Dijete> sljedeci;
};
vector<set<string>>Razvrstavanje(vector<string>c, int timovi){
    try{
    Dijete *novi=new Dijete [c.size()];
    for(int i=0;i<c.size()-1;i++){
        novi[i].ime=c[i];
        novi[i].sljedeci=&novi[i+1];
    }
    novi[c.size()-1].ime=c[c.size()-1];
    novi[c.size()-1].sljedeci=&novi[0];
    int djeca=0;
 for(int i=0; i<c.size(); i++) djeca++; //brojim koliko djece ima
 int brcl=djeca/timovi; //broj clanova svakog tima
 int plus1=djeca%timovi; // broj timova koji imaju brcl+1 (broj clanova plus 1)
 int ostali=timovi-plus1; //broj ostalih timova
 vector<set<string>>a;
 set<string> s;
 int n=c.size();
int pozicija=0;
if(plus1!=0){ 
   while(plus1!=0){ 
    set<string>s; 
    int i=0;
    while(i<brcl+1){ 
    if(pozicija==n)pozicija=0;
    s.insert(novi[pozicija].ime); 
    int brojac=0;
    int t=0;
    while(t++!=(novi[pozicija].ime.length())) {
    if((novi[pozicija].ime)[t]==' '||(novi[pozicija].ime)[t]=='.'||(novi[pozicija].ime)[t]==','||(novi[pozicija].ime)[t]=='-'||(novi[pozicija].ime)[t]==':'||(novi[pozicija].ime)[t]==';') continue; //znakovi se ne pikaju
    brojac++; //broj slova
    }  
    for(int k=pozicija;k<n-1;k++){
            novi[k].ime=novi[k+1].ime;}
                    novi[n-1].sljedeci=&novi[0];
                    n--;
    while(brojac!=1){
    if(pozicija==n) pozicija=0;
     pozicija++;
     brojac--;}
        i++;
}
    plus1--;
    a.push_back(s); 
    if(plus1==0)break;
            }
        }
if(plus1==0){ 
while(ostali!=0){
set<string>s;
  int i=0;
    while(i<brcl){
    if(pozicija==n)pozicija=0;
    s.insert(novi[pozicija].ime);
    int brojac=0;
    int t=0;
while(t++!=(novi[pozicija].ime.length())) {
  if((novi[pozicija].ime)[t]==' '||(novi[pozicija].ime)[t]=='.'||(novi[pozicija].ime)[t]==','||(novi[pozicija].ime)[t]=='-'||(novi[pozicija].ime)[t]==':'||(novi[pozicija].ime)[t]==';') continue; //znakovi se ne pikaju
  brojac++;} //broj slova
    for(int k=pozicija;k<n-1;k++){
    novi[k].ime=novi[k+1].ime;
                    }
    novi[n-1].sljedeci=&novi[0];
    n--;
    if(n==0)break;
    while(brojac!=1){
    if(pozicija==n) pozicija=0;
     pozicija++;
     brojac--;}
    i++;
        }
    ostali--;
    a.push_back(s); 
            }
        }
        
    return a;
}
catch(...){
throw logic_error("Nedovoljno memorije");}
}

int main (){
    try{
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cout<<"Unesite imena djece: ";
    vector<string>c(n);
    for(int i=0; i<n; i++) cin>>c[i];
    int k;
    cout<<endl;
    cout<<"Unesite broj timova: ";
    cin>>k;
    vector<set<string>> a(Razvrstavanje(c,k));
    for(int i=0; i<a.size(); i++){
        cout<<"Tim "<<i+1<<": ";
        set<string> f=a[i];
         int brojac=0;
        for(string x: f) {
            if(brojac==f.size()-1) cout<<x;
            else cout<<x<<", ";
            brojac++;
        }
        cout<<endl;
    }
    }
    catch(logic_error izuzetak){
        cout<<izuzetak.what();
    }
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<vector>
#include<cstring>
#include<set>
#include<list>
#include<stdexcept>
using namespace std;
vector<set<string>> Razvrstavanje(vector<string> c, int timovi){
 int djeca=0;
 for(int i=0; i<c.size(); i++) djeca++; //brojim koliko djece ima
 if(timovi<1 || timovi>djeca) throw logic_error("Razvrstavanje nemoguce");
 list<string>l; 
 auto it=l.begin();
 for(int i=0; i<c.size();i++) l.push_back(c[i]); //iz vectora ubacujemo u listu
 
 int brcl=djeca/timovi; //broj clanova svakog tima
 int plus1=djeca%timovi; // broj timova koji imaju brcl+1 (broj clanova plus 1)
 int ostali=timovi-plus1; //broj ostalih timova
 vector<set<string>>a;
 set<string> s;
 int pomocnabrcl;
//prvo dijete
  it=l.begin();
  s.insert(*it); //ubacila u tim
  brcl--;//prvi od djece ide u prvi tim, i brcl se smanjuje za 1
  int jeste=1;
  int brojac=0;
  int i=0;
  while(i++!=(*it).length()) {
    if((*it)[i]==' '||(*it)[i]=='.'||(*it)[i]==','||(*it)[i]=='-'||(*it)[i]==':'||(*it)[i]==';') continue; //znakovi se ne pikaju
    brojac++; //broj slova
    }
     it=l.erase(it); //brisemo iz liste dijete koje smo ubacili u tim
     
//ostala djeca
     it=l.begin();
     while(1){
     if(ostali==0 && plus1==0) break;
     if(plus1!=0){ //ako imamo timova sa +1 clanom
     while(plus1!=0){
         if(jeste==1);
                else{
                set<string>ludo;
                s=ludo;}
         if(jeste==0) {pomocnabrcl=brcl+2;}//plus jedan clan i ako smo vec unijeli jedno dijete tj prvo
         else {pomocnabrcl=brcl+1; jeste=0;} //dalji timovi nemaju prvo dijete pa moraju imati pravi broj clanova
         jeste=0;
        while(pomocnabrcl!=0){
        int pomocnibrojac=brojac;
        while(pomocnibrojac!=1) { //idemo kroz listu onoliko koliko je prethodno dijete imalo slova u svom imenu
         it++;
         if(it==l.end()) it=l.begin();//ako je dosao do kraja da se vrati na pocetak "kruzna lista"
         pomocnibrojac--;
     }
     s.insert(*it);
     brojac=0;
     i=0;
    while(i++!=(*it).length()) {
    if((*it)[i]==' '||(*it)[i]=='.'||(*it)[i]==','||(*it)[i]=='-'||(*it)[i]==':'||(*it)[i]==';') continue; //znakovi se ne pikaju
    brojac++; //broj slova
    }
     auto provjera=it;
    provjera++;
    if(provjera==l.end()){it=l.erase(it);it=l.begin();}
    else
     it=l.erase(it); //brisemo to ime
     pomocnabrcl--; //smanjujemo broj clanova
     }
     a.push_back(s); //ubacujemo tim u vector timova
     plus1--; // smanjujemo broj plus1 tima
     set<string>s;
     }
     }
     
     if(plus1==0 && ostali!=0){ //ako nemamo vise plus1 clanova ili ako prvobitno nismo imali
     while(ostali!=0){
         if(jeste==1);
                else{
                set<string>ludo;
                s=ludo;}
        if(jeste==0) {pomocnabrcl=brcl+1;}//ako smo vec unijeli jedno dijete tj prvo i jeste ostalo 1 ako nema plus1 tima
        else {pomocnabrcl=brcl; jeste=0;}//dalji timovi nemaju prvo dijete pa moraju imati pravi broj clanova
        jeste=0;
        while(pomocnabrcl!=0){
        int pomocnibrojac=brojac;
        while(pomocnibrojac!=1) { //idemo kroz listu onoliko koliko je prethodno dijete imalo slova u svom imenu
         it++;
         if(it==l.end()) it=l.begin();
         pomocnibrojac--;
     }
     s.insert(*it); 
     brojac=0;
     i=0;
    while(i<(*it).length()) { 
    if((*it)[i]==' '||(*it)[i]=='.'||(*it)[i]==','||(*it)[i]=='-'||(*it)[i]==':'||(*it)[i]==';') {i++; continue;} //znakovi se ne pikaju
    brojac++;//broj slova
    i++;
    }
     auto provjera=it;
    provjera++;
    if(provjera==l.end()){it=l.erase(it);it=l.begin();}
    else
     it=l.erase(it); //brisemo to ime 
     pomocnabrcl--; //smanjujemo broj clanova
     }
     a.push_back(s); //ubacimo tim u vektor
     ostali--; //smanjujemo broj ostalih timova
     set<string>s;
     }
     }
 }
 return a;
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
        cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}
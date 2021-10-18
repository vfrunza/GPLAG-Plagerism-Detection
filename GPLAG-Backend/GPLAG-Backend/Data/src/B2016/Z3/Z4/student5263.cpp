/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;
using std::getline;
using std::set;
using std::list;
using std::logic_error;
struct cvor{
    string ime;
    cvor *veza;
};
int brojznakova (string s){
    int br(0);
    for(int i=0;i<s.size();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) br++;
    }
    return br;
}
vector<set<string>> Razvrstavanje (vector<string> s, int n){
    if(n<1 || n>s.size()) throw logic_error ("Razvrstavanje nemoguce");
    list<string> imena;
    for(int i=0;i<s.size();i++){
        imena.push_back(s[i]);
    }
    auto it(imena.begin());
    vector<set<string>> timovi(n);
    int p(0);
    for(int i=0;i<(s.size()%n);i++){
        for(int j=0;j<(s.size()/n)+1;j++){
            timovi[i].insert(*it);
            int ponavljanje(brojznakova(*it));
            it=imena.erase(it);if(it==imena.end()) it=imena.begin();
            for(int k=1;k<ponavljanje;k++) {it++; if(it==imena.end()) it=imena.begin();}
        }
        p++;
    } 
    for(int i=p;i<n;i++){
        for(int j=0;j<(s.size()/n);j++){
            timovi[i].insert(*it);
            int ponavljanje(brojznakova(*it));
            it=imena.erase(it); if(it==imena.end()) it=imena.begin();
            for(int k=1;k<ponavljanje;k++) {it++; if(it==imena.end()) it=imena.begin();}
        }
    }
    return timovi;
}
int main ()
{
    cout<<"Unesite broj djece: ";
    int broj_djece;
    cin>>broj_djece;
    cin.ignore(1000,'\n');
    cout<<"Unesite imena djece: "<<endl;
    vector<string> imena_djece(broj_djece);
    for(int i=0;i<broj_djece;i++){
        getline(cin,imena_djece[i]);
    }
    cout<<"Unesite broj timova: ";
    int broj_timova;
    cin>>broj_timova;
    try{
        auto rezultat(Razvrstavanje(imena_djece,broj_timova));
        for(int i=0;i<rezultat.size();i++){
            cout<<"Tim "<<i+1<<": ";
            for(auto x(rezultat[i].begin());x!=rezultat[i].end();x++) if(x==rezultat[i].begin()) cout<<*x; else cout<<", "<<*x;
            cout<<endl;
        }
    }
    catch(logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}
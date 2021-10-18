/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <stdexcept>
using namespace std;
struct Dijete{
    string ime;
    Dijete *sljedeci;
};
void IzbrisiDijete(Dijete *prije,Dijete *brisat){
    auto pomocna=brisat;
    prije->sljedeci=brisat->sljedeci;
    brisat=brisat->sljedeci;
    delete pomocna;
}
int VelicinaImena(string s){
    int velicinaimena(0);
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>=48 && s[i]<=57)) velicinaimena++;
    }
    return velicinaimena;
}
vector<set<string>> Razvrstavanje(vector<string> s, int n)
{
    Dijete *pocetak(nullptr),*prethodni,*pomocna;
    for(int i=0; i<s.size(); i++) {
        Dijete *novi(new Dijete);
        novi->ime=s[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        pomocna=novi;
        if(i==s.size()-1)novi->sljedeci=pocetak;
    }
    vector<set<string>> razvrstani(n);
    Dijete *p=pocetak;
    string prvi=p->ime;
    razvrstani[0].insert(prvi);
    int velicinaimena=VelicinaImena(prvi);
    IzbrisiDijete(pomocna,p);
    int brojac(0);
    int brojacubacenih(1);
    int ukupno=s.size();
        int t=(s.size())%n;
    for(int i=0; i<n; i++) {
        if(ukupno>2){while(true) {
            brojac++;
            string imence=p->ime;
            if(brojac==velicinaimena) {
                brojacubacenih++;
                razvrstani[i].insert(imence);
                brojac=0;
                velicinaimena=VelicinaImena(imence);
                IzbrisiDijete(pomocna,p);
                ukupno--;
            } else {
                p=p->sljedeci;
                pomocna=pomocna->sljedeci;
            }
            if(ukupno==2 && ((i<t && brojacubacenih<s.size()/n+1) || (i>=t && brojacubacenih<s.size()/n))){
                if(velicinaimena%2==1){razvrstani[i].insert(p->ime);auto pomocna2=p; p=p->sljedeci;delete pomocna2; brojacubacenih++; if((i<t && brojacubacenih<s.size()/n+1) || (i>=t && brojacubacenih<s.size()/n)) razvrstani[i].insert(p->ime); else {i++; razvrstani[i].insert(p->ime); delete p;}}
                else{
                    auto pomocna3=p;
                    p=p->sljedeci;
                    razvrstani[i].insert(p->ime);
                    brojacubacenih++;
                    delete p;
                    if((i<t && brojacubacenih<s.size()/n+1) || (i>=t && brojacubacenih<s.size()/n)){ razvrstani[i].insert(pomocna3->ime); delete pomocna3;}
                    else{
                        i++;
                        razvrstani[i].insert(pomocna3->ime); delete pomocna3;
                    }
                }
                break;
            }
            if(ukupno==2 && ((i<t && brojacubacenih==s.size()/n+1) || (i>=t && brojacubacenih==s.size()/n))){
                brojacubacenih=0;
                i++;;
                if(velicinaimena%2==1){razvrstani[i].insert(p->ime);auto pomocna2=p; p=p->sljedeci;delete pomocna2; brojacubacenih++; if((i<t && brojacubacenih<s.size()/n+1) || (i>=t && brojacubacenih<s.size()/n)) razvrstani[i].insert(p->ime); else {i++; razvrstani[i].insert(p->ime); delete p;}}
                else{
                    auto pomocna3=p;
                    p=p->sljedeci;
                    razvrstani[i].insert(p->ime);
                    brojacubacenih++;
                    delete p;
                    if((i<t && brojacubacenih<s.size()/n+1) || (i>=t && brojacubacenih<s.size()/n)){ razvrstani[i].insert(pomocna3->ime); delete pomocna3;}
                    else{
                        i++;
                        razvrstani[i].insert(pomocna3->ime); delete pomocna3;
                    }
                }
                break;
            }
            if(i<t && brojacubacenih==s.size()/n+1){ brojacubacenih=0; break;}
            if(i>=t && brojacubacenih==s.size()/n){ brojacubacenih=0; break;}
        }}
    }
    return razvrstani;
}
int main ()
{
    try {
          int n;
        cout<<"Unesite broj djece: ";
        cin>>n;
        cin.ignore(1000,'\n');
        vector<string> imena;
        cout<<"Unesite imena djece: ";
        for(int i=0; i<n; i++) {
            string ime;
            getline(cin,ime);
            imena.push_back(ime);
        }
        cout<<"Unesite broj timova: ";
        int m;
        cin>>m;
        if(m<1 || m>n) throw std::logic_error("Razvrstavanje nemoguce");
        vector<set<string>> razvrstani=Razvrstavanje(imena,m);
        for(int i=0; i<m; i++) {
            cout<<"Tim "<<i+1<<": ";
            for(auto element:razvrstani[i]) {
                if(element!=*max_element(razvrstani[i].begin(),razvrstani[i].end())) {
                    cout<<element<<", ";
                } else {
                    cout<<element;
                }
            }
            cout<<endl;
        }
    } catch(std::logic_error izuzetak) {
        cout<<izuzetak.what();
    }
    return 0;
}
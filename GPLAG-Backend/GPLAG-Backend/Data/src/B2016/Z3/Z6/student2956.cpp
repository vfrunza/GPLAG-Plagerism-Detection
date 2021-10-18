/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>

using namespace std;

struct Dijete{
    string ime;
    shared_ptr<Dijete>sljedeci;
};

int brojslova(string s){
    int brojac(0);
    for(int i=0;i<s.length();i++){
        if(s[i]!=' ' && s[i]!='-') brojac++;
    }
    return brojac;
}

vector<set<string>>Razvrstavanje(vector<string>imena,int broj_timova){
    int n=imena.size();
    int prvih_koliko_timova=n%broj_timova;
    int koliko_igraca=(n/broj_timova)+1;
    if(broj_timova<1 || broj_timova>imena.size()) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>>timovi(broj_timova);
    
    shared_ptr<Dijete>pocetak=nullptr;
    shared_ptr<Dijete>x;
    for(int i=0;i<n;i++){
        shared_ptr<Dijete>novi(new Dijete);
        if(pocetak==nullptr) pocetak=novi;
        else x->sljedeci=novi;
        novi->ime=imena[i];
        novi->sljedeci=pocetak;
        x=novi;
    }
    string iduci("");
    shared_ptr<Dijete>it=pocetak;
    for(int i=0;i<broj_timova;i++){
        if(i<prvih_koliko_timova){
            int brojac=0;
            while(brojac!=koliko_igraca){
                iduci=it->ime;
                timovi[i].insert(iduci);
                if(x!=it){
                    if(it==pocetak) pocetak=it->sljedeci;
                    x->sljedeci=it->sljedeci;
                    it=x->sljedeci;
                }
                else{
                    it->sljedeci=nullptr;pocetak=nullptr;x=nullptr;
                }
                int broj_koraka=brojslova(iduci)-1;
                while(broj_koraka>0){
                    x=it;
                    it=it->sljedeci;
                    broj_koraka--;
                }
                brojac++;
            }
        }
        else {
            int brojac=0;
            while(brojac!=koliko_igraca-1){
                iduci=it->ime;
                timovi[i].insert(iduci);
                if(x!=it){
                    if(it==pocetak) pocetak=it->sljedeci;
                    x->sljedeci=it->sljedeci;
                    it=x->sljedeci;
                }
                else{
                    it->sljedeci=nullptr;pocetak=nullptr;x=nullptr;return timovi;
                }
                int broj_koraka=brojslova(iduci)-1;
                while(broj_koraka>0){
                    x=it;
                    it=it->sljedeci;
                    broj_koraka--;
                }
                brojac++;
            }
        }
    }
    return timovi;
}

int main(){
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    vector<string>v(n);
    cout<<"Unesite imena djece: "<<endl;
    cin.ignore(10000,'\n');
    for(int i=0;i<n;i++){
        getline(cin,v[i]);
    }
    cout<<"Unesite broj timova: ";
    int k;
    cin>>k;
    try{
        auto x=Razvrstavanje(v,k);
        for(int i=0;i<x.size();i++){
        cout<<"Tim "<<i+1<<": ";
        for(auto y=x[i].begin();y!=x[i].end();y++){
            cout<<*y;
            auto ka=y;
            ka++;
            if(ka!=x[i].end()) cout<<", ";
        }
        cout<<endl;
    }
}
catch(logic_error e){
    cout<<"Izuzetak: "<<e.what();
}
return 0;
}
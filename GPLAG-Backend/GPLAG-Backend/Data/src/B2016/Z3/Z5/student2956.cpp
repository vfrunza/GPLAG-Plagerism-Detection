/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};

using namespace std;

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
    
    Dijete* pocetak=nullptr;
    Dijete* prethodni;
    Dijete* kraj;
    for(int i=0;i<n;i++){
        Dijete* novi=new Dijete;
        kraj=novi;
        if(pocetak==nullptr) pocetak=novi;
        else prethodni->sljedeci=novi;
        novi->ime=imena[i];
        novi->sljedeci=pocetak;
        prethodni=novi;
    }
    string iduci("");
    Dijete* it=pocetak;
    Dijete* x=kraj;
    
    for(int i=0;i<broj_timova;i++){
        if(i<prvih_koliko_timova){
            int brojac=0;
            while(brojac!=koliko_igraca){
                iduci=it->ime;
                timovi[i].insert(iduci);
                if(x!=it){
                    x->sljedeci=it->sljedeci;
                    delete it;
                    it=x->sljedeci;
                }
                else{
                    delete it;pocetak=nullptr;
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
        else{
            int brojac=0;
            while(brojac!=koliko_igraca-1){
                iduci=it->ime;
                timovi[i].insert(iduci);
                if(x!=it){
                    x->sljedeci=it->sljedeci;
                    delete it;
                    it=x->sljedeci;
                }
                else {
                    delete it;
                    pocetak=nullptr;
                    return timovi;
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
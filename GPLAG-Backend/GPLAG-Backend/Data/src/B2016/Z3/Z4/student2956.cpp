/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <stdexcept>


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
    list<string>lista;
    for(int i=0;i<n;i++) lista.push_back(imena[i]);
    string iduci("");
    auto it=lista.begin();
    for(int i=0;i<broj_timova;i++){
        if(i<prvih_koliko_timova){
            int brojac=0;
            while(brojac!=koliko_igraca){
                iduci=*it;
                timovi[i].insert(iduci);
                it=lista.erase(it);
                if(it==lista.end()) it=lista.begin();
                int broj_koraka=brojslova(iduci)-1;
                while(broj_koraka>0){
                    it++;
                    if(it==lista.end()) it=lista.begin();
                    broj_koraka--;
                }
                brojac++;
            }
        }
        else {
            int brojac=0;
            while(brojac!=koliko_igraca-1){
                iduci=*it;
                timovi[i].insert(iduci);
                it=lista.erase(it);
                if(it==lista.end()) it=lista.begin();
                int broj_koraka=brojslova(iduci)-1;
                while(broj_koraka>0){
                    it++;
                    if(it==lista.end()) it=lista.begin();
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
    cin.ignore(1000,'\n');
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
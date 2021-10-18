/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::logic_error;
using std::getline;

struct Dijete{
    string ime;
    std::shared_ptr<Dijete> sljedeci;
};
int brojznakova(string s){
    int brojac(0);
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) brojac++;
    }
    return brojac;
}

vector<set<string>> Razvrstavanje(vector<string> s, int n){
    if(n>s.size() || n<1) throw  logic_error ("Razvrstavanje nemoguce");
    std::shared_ptr<Dijete>pocetak(nullptr), prethodni;
    for(int i=0;i<s.size();i++){
        std::shared_ptr<Dijete> novo(new Dijete);
        novo->ime=s[i];novo->sljedeci=nullptr;
        if(!pocetak) pocetak=novo;
        else prethodni->sljedeci=novo;
        prethodni=novo;
    }
    prethodni->sljedeci=pocetak;
    vector<set<string>> timovi(n);
    int nastavak(0);
    int brdjece(s.size());
    for(int i=0;i<(s.size()%n);i++){
        for(int j=0;j<(s.size()/n)+1;j++){
            timovi[i].insert(pocetak->ime);
            int ponavljanje(brojznakova(pocetak->ime));
            prethodni->sljedeci=pocetak->sljedeci;
            pocetak=nullptr; pocetak=prethodni->sljedeci;
            for(int k=1;k<ponavljanje;k++){
                pocetak=pocetak->sljedeci;
                prethodni=prethodni->sljedeci;
            }
            brdjece--;
        }
        nastavak++;
    }
    for(int i=nastavak;i<n;i++){
        for(int j=0;j<(s.size()/n);j++){
            if(brdjece!=1){
                timovi[i].insert(pocetak->ime);
                int ponavljanje(brojznakova(pocetak->ime));
                prethodni->sljedeci=pocetak->sljedeci;
                pocetak=nullptr; pocetak=prethodni->sljedeci;
                for(int k=1;k<ponavljanje;k++){
                    pocetak=pocetak->sljedeci;
                    prethodni=prethodni->sljedeci;
                }
            }
            else {
                 timovi[i].insert(pocetak->ime);
                 pocetak->sljedeci=nullptr;
                 pocetak=nullptr;
            }
            brdjece--;
        }
    }

    return timovi;
}
int main ()
{
    cout<<"Unesite broj djece: ";
    int broj_djece;
    cin>>broj_djece;
    cin.ignore(10000,'\n');
    cout<<"Unesite imena djece: "<<endl;
    vector<string> imena_djece(broj_djece);
    for (int i=0;i<broj_djece;i++){
        getline(cin,imena_djece[i]);
    }
    cout<<"Unesite broj timova: ";
    int broj_timova;
    cin>>broj_timova;
    try{
        auto rezultat(Razvrstavanje(imena_djece,broj_timova));
        for(int i=0;i<rezultat.size();i++){
            cout<<"Tim "<<i+1<<": ";
            for(auto x(rezultat[i].begin());x!=rezultat[i].end();x++) 
            {if(x==rezultat[i].begin()) cout<<*x; else cout<<", "<<*x;}
            cout<<endl;
        }
    }
    catch (logic_error izuzetak){
        cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}
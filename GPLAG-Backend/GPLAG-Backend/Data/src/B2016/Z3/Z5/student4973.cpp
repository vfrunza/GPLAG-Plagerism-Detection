/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>

using namespace std;

struct Dijete {
    string ime;
    Dijete *sljedeci;
};


int BrojSlova(string s)
{
    int br=0;
    for(char c : s) {
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) br++;
    }
    return br;
}
Dijete *KreirajCvor(vector<string> djeca)
{
    Dijete *poc=nullptr;
    Dijete *tren=nullptr;

    for(int i=0; i<djeca.size(); i++) {
        Dijete *novo=new Dijete;
        novo->ime=djeca[i];

        if(i<1) {
            poc=novo;
            tren=novo;
        } else {
            tren->sljedeci=novo;
            tren=novo;
        }
        if(i==djeca.size()-1) novo->sljedeci=poc;
    }
    return poc;
}

vector<set<string>>Razvrstavanje(vector<string>djeca,int broj_timova)
{
    if(!broj_timova || !djeca.size() ||broj_timova>djeca.size()) throw logic_error("Razvrstavanje nemoguce");
    for(int i=0; i<djeca.size(); i++) {
        if(BrojSlova(djeca[i])==0) throw "Greska";
    }
    Dijete *l=KreirajCvor(djeca);
    set<string>pomocna;
    vector<set<string>>timovi;
    timovi.resize(broj_timova);
    vector<int>velicina_timova;
    velicina_timova.resize(broj_timova);
    for(int i=0; i<velicina_timova.size(); i++)
        velicina_timova[i]=djeca.size()/broj_timova;
    int preostali_broj_djece=djeca.size()%broj_timova;
    for(int i=0; i<preostali_broj_djece; i++)
        velicina_timova[i]++;
    int k=djeca.size();
    Dijete *it=l;
    Dijete *pom=l;
    while(pom->sljedeci!=it)pom=pom->sljedeci;
    vector<set<string>>::iterator it_timovi=timovi.begin();
    int broj_slova_prethodnog=0,index_tima=0,br_djece_u_timu=0;
    while(k>0) {
        br_djece_u_timu++;
        for(int i=broj_slova_prethodnog; i>0; i--) {
            it=it->sljedeci;
            pom=pom->sljedeci;

        }
        pomocna.insert(it->ime);
        k--;
        broj_slova_prethodnog=BrojSlova(it->ime)-1;
        if(k!=0) {
            pom->sljedeci=it->sljedeci;
            it->sljedeci=nullptr;
            delete it;
            it=pom->sljedeci;
        } else {
            it->sljedeci=nullptr;
            delete pom;
        }
        if(velicina_timova[index_tima]==br_djece_u_timu) {
            *it_timovi++=pomocna;
            pomocna.clear();
            index_tima++;
            br_djece_u_timu=0;
        }
    }
    return timovi;
}

int main ()
{
    try {
        int broj_djece,broj_timova;
        string ime;
        vector<string>djeca;
        cout<<"Unesite broj djece: ";
        cin>>broj_djece;
        cout<<"Unesite imena djece: "<<endl;
        cin.ignore(1000,'\n');
        cin.clear();
        for(int i=0; i<broj_djece; i++) {
            getline(cin,ime);
            djeca.push_back(ime);
        }
        cout<<"Unesite broj timova: ";
        cin>>broj_timova;
        vector<set<string>>timovi=Razvrstavanje(djeca,broj_timova);
        vector<set<string>>::iterator it1=timovi.begin();
        int br=0;
        for(auto i=it1; i!=timovi.end(); i++) {
            br++;
            set<string>l=*i;
            set<string>::iterator itl;
            set<string>::iterator itl1=l.end();
            itl1--;
            cout<<"Tim " << br <<": ";
            for(itl=l.begin(); itl!=l.end(); itl++) {
                if(itl!=itl1) cout<<*itl<<", ";
                else cout<<*itl <<endl;
            }
        }
    } catch(logic_error tekst) {
        cout<<"Izuzetak: "<<tekst.what()<<endl;
    }
    return 0;
}

/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <set>
#include <string>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <vector>
#include <memory>

using namespace std;

struct Dijete{
    string ime;
    shared_ptr<Dijete> sljedeci;
};

int BrojElemenata(shared_ptr<Dijete> pocetak)
{
    if(!pocetak) return 0;
    if(pocetak==pocetak->sljedeci) return 1;
    int broj_el{0};
    bool naPocetkuSmo{true};
    for(shared_ptr<Dijete> p=pocetak;p!=pocetak || naPocetkuSmo;p=p->sljedeci)
    {
        broj_el++;
        naPocetkuSmo=false;
    }
    return broj_el;
}

/*void UnistiCvor(shared_ptr<Dijete> &prijasnji)
{
    if(prijasnji==prijasnji->sljedeci) { prijasnji=nullptr; return; }
    prijasnji->sljedeci=prijasnji->sljedeci->sljedeci;
}*/

vector<set<string>> Razvrstavanje(vector<string> imena_djece, int br_timova)
{
    if(br_timova<1 || (unsigned int)br_timova>imena_djece.size()) 
        throw logic_error("Izuzetak: Razvrstavanje nemoguce");
    int brojDjece{int(imena_djece.size())};
    
    int brojVecihTimova{brojDjece % br_timova};
    int brojManjihTimova{br_timova-brojVecihTimova};
    
    int br_veciTim{ 1+brojDjece/br_timova};
    int br_manjiTim{ brojDjece/br_timova};
    int duzinaStringa (const string &s);
    
    shared_ptr<Dijete> pocetak(nullptr), trenutni(nullptr);
    
    for(unsigned int i=0;i<imena_djece.size();i++)
    {
        string el{imena_djece[i]};
        
        if(!pocetak)
        {
            pocetak=make_shared<Dijete> ();
            pocetak->ime=el;
            pocetak->sljedeci=pocetak;
            trenutni=pocetak;
        }
        else
        {
            trenutni->sljedeci=make_shared<Dijete> ();
            trenutni->sljedeci->ime=el;
            trenutni->sljedeci->sljedeci=pocetak;
            trenutni=trenutni->sljedeci;
        }
    }
    
    vector<set<string>> rez;
    string trenutnoDijete{imena_djece[0]};
    int brojacVelikih{0};
    int brojacManjih{0};
    shared_ptr<Dijete> it{trenutni};
    
    while(brojacVelikih<brojVecihTimova)
    {
        set<string> a;
        for(int velSkupa=0;velSkupa<br_veciTim;velSkupa++)
        {
            a.insert(trenutnoDijete);
            if(it==it->sljedeci) {it->sljedeci=nullptr; break; }
            it->sljedeci=it->sljedeci->sljedeci;
            int pomaci{duzinaStringa(trenutnoDijete)};
            for(int i=1;i<pomaci;i++)
            {
                it=it->sljedeci;
            }
            trenutnoDijete=it->sljedeci->ime;
        }
        brojacVelikih++;
        rez.push_back(a);
        a.clear();
    }
    while(brojacManjih<brojManjihTimova)
    {
        set<string> a;
        for(int velSkupa=0;velSkupa<br_manjiTim;velSkupa++)
        {
            a.insert(trenutnoDijete);
            if(it==it->sljedeci) {it->sljedeci=nullptr; break; }
            it->sljedeci=it->sljedeci->sljedeci;
            int pomaci{duzinaStringa(trenutnoDijete)};
            if(!it) {break; }
            
            for(int i=1;i<pomaci;i++) {it=it->sljedeci; }
            trenutnoDijete = it->sljedeci->ime;
        }
        brojacManjih++;
        rez.push_back(a);
        a.clear();
    }
    return rez;
}

int duzinaStringa(const string &s)
{
    int duzina{0};
    for(char c: s)
    {
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'))
            duzina++;
    }
    return duzina;
}

int main ()
{
    cout<<"Unesite broj djece: ";
    int br_djece;
    cin>>br_djece;
    cin.ignore(10000,'\n');
    cout<<"Unesite imena djece: "<<endl;
    vector<string> imena;
    string s;
    for(int i=0;i<br_djece;i++)
    {
        getline(cin,s);
        imena.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    int br_timova;
    cin>>br_timova;
    try{
        vector<set<string>> timovi=Razvrstavanje(imena,br_timova);
        
        for(int i=0;i<br_timova;i++)
        {
            auto tim=timovi[i];
            cout<<"Tim "<<i+1<<": ";
            int j{0};
            for(string s :tim)
            {
                cout<<s;
                j++;
                if((unsigned int)j!=tim.size()) cout<<", ";
            }
            cout<<endl;
        }
    }
    catch(logic_error e){
        cout<<e.what()<<endl;
    }
    
    return 0;

}
/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>
#include <list>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: set;
using std:: list;
using std:: string;
using std:: shared_ptr;

struct Dijete
{
    string ime;
    shared_ptr<Dijete> sljedeci;
};

vector<set<string>> Razvrstavanje (vector<string> imena, int broj_timova)
{
    if(broj_timova<1 || broj_timova>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    vector<set<string>>timovi;
    shared_ptr<Dijete> pocetakListe = nullptr, trenutnoDijete = nullptr, zadnjeDijete=nullptr;
    int brTimovaSaClanomVise = imena.size() % broj_timova;
    int brTima = 1;
    int brClanova = imena.size() / broj_timova;
    int korak = 0;
    int brElemenata = imena.size();
    // Kreiranje Liste
    for(int i=0; i<imena.size(); i++)
    {
        if(!pocetakListe) {
            pocetakListe = std::make_shared<Dijete>();
            pocetakListe -> ime = imena[i];
            pocetakListe -> sljedeci = nullptr;
        }
        else {
            trenutnoDijete = pocetakListe;
            while(trenutnoDijete->sljedeci!=nullptr)
                trenutnoDijete = trenutnoDijete->sljedeci;
            shared_ptr<Dijete> tmp = std::make_shared<Dijete>();
            tmp -> ime = imena[i];
            if(i==imena.size()-1) 
                tmp->sljedeci = pocetakListe;
            else tmp ->sljedeci = nullptr;
            trenutnoDijete->sljedeci = tmp;
            if(i==imena.size()-1)
                zadnjeDijete = tmp;
            tmp=nullptr;
        }
    }
    set<string> tim;
    trenutnoDijete = pocetakListe;
    while(brElemenata>0)
    {
        korak = 0;
        string tDijete = trenutnoDijete -> ime;
        tim.insert(tDijete);
        if(brTima <= brTimovaSaClanomVise && tim.size() == brClanova + 1) {
            timovi.push_back(tim);
            tim.clear();
            brTima++;
        }
        else if(brTima > brTimovaSaClanomVise && tim.size() == brClanova) {
            timovi.push_back(tim);
            tim.clear();
            brTima++;
        }
        for(int i(0); i<tDijete.length();i++)
            if( (tDijete[i]>='a' && tDijete[i]<='z') || (tDijete[i]>='A' && tDijete[i]<='Z')
                 || (tDijete[i]>='0' && tDijete[i]<='9') )
                korak++;
        // Brisanje trenutnog djeteta
        shared_ptr<Dijete> prethodni = pocetakListe;
        while(prethodni->sljedeci!=trenutnoDijete)
            prethodni = prethodni->sljedeci;
        if(pocetakListe == trenutnoDijete && pocetakListe==zadnjeDijete) {
            
            trenutnoDijete->sljedeci=nullptr;
            pocetakListe = trenutnoDijete = zadnjeDijete = prethodni = nullptr;
            break;
        }
        else if(trenutnoDijete == pocetakListe) {
            prethodni = zadnjeDijete;
            prethodni ->sljedeci = trenutnoDijete ->sljedeci;
            pocetakListe = trenutnoDijete -> sljedeci;
            //delete trenutnoDijete;
            trenutnoDijete = prethodni;
        }
        else if(trenutnoDijete== zadnjeDijete) {
            prethodni -> sljedeci = pocetakListe;
            zadnjeDijete = prethodni;
            //delete trenutnoDijete;
            trenutnoDijete = prethodni;
        }
        else {
            prethodni -> sljedeci = trenutnoDijete -> sljedeci;
            //delete trenutnoDijete;
            trenutnoDijete = prethodni;
        }
        prethodni = nullptr;
        brElemenata--;
        while(korak!=0) {
            korak--;
            trenutnoDijete = trenutnoDijete -> sljedeci;
        }
    }
    return timovi;
}


int main ()
{
     cout<<"Unesite broj djece: ";
    int br_djece;
    cin>>br_djece;
    vector<string>imena;
    string dijete;
    cout<<"Unesite imena djece: "<<endl;
    cin.ignore(10000,'\n');
    for(int i=0; i<br_djece; i++)
    {
        std::getline(cin, dijete);
        imena.push_back(dijete);
        dijete="";
    }
    cout<<"Unesite broj timova: ";
    int br_timova;
    cin>>br_timova;
    try
    {
        auto timovi(Razvrstavanje(imena, br_timova));
        
        for(int i=0; i<timovi.size(); i++)
        {
            cout<<"Tim "<<i+1<<": ";
            vector<string>vektor;
            for(auto it=timovi[i].begin(); it!=timovi[i].end(); it++)
            {
                vektor.push_back(*it);
            }
            for(int i=0; i<vektor.size(); i++)
            {
                if(i==vektor.size()-1) cout<<vektor[i]<<endl;
                else cout<<vektor[i]<<", ";
            }
            vektor.resize(0);
        }
    }
    catch(std::logic_error izuzetak)
    {
        cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}
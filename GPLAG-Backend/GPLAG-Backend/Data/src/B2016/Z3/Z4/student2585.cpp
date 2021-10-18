/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include<string>
#include <set>
#include<stdexcept>
#include<list>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: string;
using std:: list;
using std:: vector;
using std:: set;


vector<set<string>> Razvrstavanje (vector<string> imena, int broj_timova)
{
    if(broj_timova<1 || broj_timova>imena.size()) 
        throw std::logic_error("Razvrstavanje nemoguce");
        
    vector<set<string>>timovi;
    list<string>lista_imena;
    for(int i=0; i<imena.size(); i++)
    {
        lista_imena.push_back(imena[i]);
    }
    int brTimovaSaClanomVise = imena.size() % broj_timova;
    int brTima = 1;
    int brClanova = imena.size() / broj_timova;
    auto it = lista_imena.begin();
    int korak = 0;
    set<string> tim;
    int brElemenata = lista_imena.size();
    while(brElemenata>0)
    {
        korak = 0;
        string trenutnoDijete = *it;
        tim.insert(trenutnoDijete);
        if(brTima <= brTimovaSaClanomVise && tim.size() == brClanova + 1) {
            timovi.push_back(tim);
            tim.clear();
            brTima++;
            if(brTima==broj_timova+1) break;
        }
        else if(brTima > brTimovaSaClanomVise && tim.size() == brClanova) {
            timovi.push_back(tim);
            tim.clear();
            brTima++;
            if(brTima==broj_timova+1) break;
        }
        for(int i(0); i<trenutnoDijete.length();i++)
            if( (trenutnoDijete[i]>='a' && trenutnoDijete[i]<='z') || (trenutnoDijete[i]>='A' && trenutnoDijete[i]<='Z')
                 || (trenutnoDijete[i]>='0' && trenutnoDijete[i]<='9') )
                korak++;
        it = lista_imena.erase(it);
        it--;
        brElemenata--;
        while(korak!=0) {
            korak--;
            it++;
            if(it == lista_imena.end())
                it = lista_imena.begin();
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
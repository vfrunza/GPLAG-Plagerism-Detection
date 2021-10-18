/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>
#include <algorithm>

using namespace std; 

int DuzinaImena (string ime)
{
    int duzina(0);
    for(int i=0; i<ime.size();i++)
    {
       if((ime.at(i)>='0' and ime.at(i)<='9') or (ime.at(i)>='a' and ime.at(i)<='z') or (ime.at(i)>='A' and ime.at(i)<='Z')) 
            duzina++;
    }
    return duzina;
}

void SrediListu(list<string> &lista)
{
    list<string>pomocna;
    bool jelprvi(true);
    int pomijeranje_za(0);
    auto it(lista.begin());
    while(!lista.empty()) // prolazi kroz elemente liste dok lista ne bude prazna
    {
        if(jelprvi) // sreduje prvo dijete u nizu
        {
             pomocna.push_back(*it); // stavit ce prvo dijete u pomocni
             jelprvi=false;
             pomijeranje_za=DuzinaImena(*it) - 1;
             it = lista.erase(it);
             if(it==lista.end()) it=lista.begin();
        }
        
        while(pomijeranje_za!=0) // dolazi do trazenog djeteta
        {
            pomijeranje_za--;
            it++;
            if(it==lista.end()) it=lista.begin(); // ako dode do kraja imena, nek ga prebaci naprijed opet
        }
        
        pomocna.push_back(*it);
        pomijeranje_za=DuzinaImena(*it) - 1;
        it = lista.erase(it);
        if(it==lista.end()) it=lista.begin();
    }
    
    copy(pomocna.begin(), pomocna.end(), back_inserter(lista));
}

void RasporediUTimove(vector<set<string>> &timovi, list<string> lista)
{
    int sa_vise_clanova((lista.size())%(timovi.size()));
    int min_br_clanova((lista.size())/(timovi.size()));
    auto it(lista.begin());
    
    while(it!=lista.end()){
    for(int i=0; i<sa_vise_clanova; i++) // oni timovi sto imaju +1 clanova
    {
        for(int j=0; j<min_br_clanova+1; j++)
        {
            timovi.at(i).insert(*it);
            it++;
        }
    }
    
    
    for(int i=sa_vise_clanova; i<timovi.size(); i++)
    {
        for(int j=0; j<min_br_clanova; j++)
        {
            timovi.at(i).insert(*it);
            it++;
        }
    }
    }
}

vector<set<string>> Razvrstavanje (vector<string>imena, int broj_timova)
{
    if(broj_timova<0 or broj_timova>imena.size()) throw logic_error("Razvrstavanje nemoguce");
    
    vector<set<string>> timovi(broj_timova);
    list<string> lista;
    copy(imena.begin(), imena.end(), back_inserter (lista));
    SrediListu(lista);
    RasporediUTimove(timovi,lista);
    return timovi;
}

void IspisiSet1(set<string> setic)
{
    int brojac(1);
    for(auto i = setic.begin(); i!=setic.end(); i++)
    {
        if(brojac==setic.size()) cout << *i;
        else cout << *i << ", ";
        brojac++;
    }
}


void IspisiTimove (vector<set<string>> timovi)
{
    for(int i=0; i<timovi.size(); i++)
    {
        cout << "Tim " << i+1 << ": ";
        IspisiSet1(timovi.at(i));
        cout << endl;
        
    }
}

int main ()
{   
    try{
    cout << "Unesite broj djece: ";
    int broj_djece(0);
    cin >> broj_djece;
    vector<string> imena (broj_djece);
    cout << "Unesite imena djece: ";
    cin.ignore(10000, '\n');
    for(int i=0; i<broj_djece; i++)
    {
        string ime;
        getline(cin, ime);
        imena.at(i)=ime;
    }
    cout << endl<< "Unesite broj timova: ";
    int broj_timova(0);
    //cin.ignore(1000, '\n');
    
    cin >> broj_timova;
    
    IspisiTimove(Razvrstavanje(imena, broj_timova));
    } catch(logic_error e){
        cout << e.what();
    }
    
	return 0;
}
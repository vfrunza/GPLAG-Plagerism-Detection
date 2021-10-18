/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <iterator>
#include <memory>
#include <new>

using namespace std;

struct Dijete
{
    string ime;
    shared_ptr<Dijete> sljedeci;
};

int BrojPom(string s)
{
    int brojac(0);
    
    for(int i=0; i<s.length(); i++)
        if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) brojac++;
    
    return brojac;
}

// Funkcija Razvrstavanje vrsi kruzno razvrstavanje imena(stringova) po duzini stringova
// u odredjeni broj timova
vector<set<string>> Razvrstavanje(vector<string> imena, int broj_tim)
{
    if(broj_tim<1 || broj_tim>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    int broj_djece(imena.size());
    shared_ptr<Dijete> pocetak(nullptr), prethodni(nullptr), novi(nullptr);
    for(int i=0; i<broj_djece; i++)
    {
        novi=make_shared<Dijete>();
        novi->ime=imena[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    int broj_prvih_clan, broj_preo_clan, broj_prv_tim, broj_drug_tim;
    
    vector<set<string>> timovi;
    shared_ptr<Dijete> p(pocetak);
    if(broj_djece%broj_tim==0)
    {
        broj_prvih_clan=broj_djece/broj_tim;
        for(int i=0; i<broj_tim; i++)
        {
            set<string> skup;
            for(int j=0; j<broj_prvih_clan; j++)
            {
                int korak(BrojPom(p->ime));
                skup.insert(p->ime);
                
                p=p->sljedeci;
                prethodni->sljedeci=p;
                
                broj_djece--;
                
                if(broj_djece==1)
                {
                    p->sljedeci=nullptr;
                    prethodni->sljedeci=nullptr;
                }
                if(broj_djece==0) break;
                korak--;
                while(broj_djece>1)
                {
                    p=p->sljedeci;
                    prethodni=prethodni->sljedeci;
                    korak--;
                    if(korak==0) break;
                }
            }
            timovi.push_back(skup);
            if(broj_djece==0) break;
        }
    }
    else 
    {
        broj_prvih_clan=(broj_djece/broj_tim)+1;
        broj_preo_clan=broj_prvih_clan-1;
        broj_prv_tim=broj_djece%broj_tim;
        broj_drug_tim=broj_tim-broj_prv_tim;
    
        for(int i=0; i<broj_prv_tim; i++)
        {
            set<string> skup;
            for(int j=0; j<broj_prvih_clan; j++)
            {
                int korak(BrojPom(p->ime));
                skup.insert(p->ime);
                
                p=p->sljedeci;
                prethodni->sljedeci=p;
                
                broj_djece--;
                
                if(broj_djece==1)
                {
                    p->sljedeci=nullptr;
                    prethodni->sljedeci=nullptr;
                }
                if(broj_djece==0) break;
                korak--;
                while(broj_djece>1)
                {
                    p=p->sljedeci;
                    prethodni=prethodni->sljedeci;
                    korak--;
                    if(korak==0) break;
                }
            }
            timovi.push_back(skup);
            if(broj_djece==0) break;
        }
        for(int i=0; i<broj_drug_tim; i++)
        {
            set<string> skup;
            for(int j=0; j<broj_preo_clan; j++)
            {
                int korak(BrojPom(p->ime));
                skup.insert(p->ime);
                
                p=p->sljedeci;
                prethodni->sljedeci=p;
                
                broj_djece--;
                
                if(broj_djece==1)
                {
                    p->sljedeci=nullptr;
                    prethodni->sljedeci=nullptr;
                }
                if(broj_djece==0) break;
                korak--;
                while(broj_djece>1)
                {
                    p=p->sljedeci;
                    prethodni=prethodni->sljedeci;
                    korak--;
                    if(korak==0) break;
                }
            }
            timovi.push_back(skup);
            if(broj_djece==0) break;
        }
    }
    
    return timovi;
}

int main ()
{
    try
    {
        int br_djece;
        
        cout << "Unesite broj djece: ";
        cin >> br_djece;
        
        cin.ignore(1000, '\n');
        
        vector<string> imena;
        cout << "Unesite imena djece: " << endl;
        for(int i=0; i<br_djece; i++)
        {
            string ime;
            getline(cin, ime);
            imena.push_back(ime);
        }
    	
    	int br_timova;
    	cout << "Unesite broj timova: ";
    	cin >> br_timova;
    
    	vector<set<string>> timovi(Razvrstavanje(imena, br_timova));
    	for(int i=0; i<timovi.size(); i++)
    	{
    	    cout << "Tim " << i+1 << ": ";
    	    auto it(timovi[i].begin());
    	    for(it=timovi[i].begin(); it!=timovi[i].end(); it++)
    	    {
    	        if(std::distance(it, timovi[i].end())==1) break;
    	        cout << *it << ", ";
    	    }
    	    cout << *it << endl;
    	}
    }
    catch(std::logic_error izuzetak)
    {
        cout << "Izuzetak: " << izuzetak.what() << endl;
    }
	
	return 0;
}

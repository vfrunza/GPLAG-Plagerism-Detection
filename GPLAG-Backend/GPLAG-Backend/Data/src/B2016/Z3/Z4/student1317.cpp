/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <iterator>

using namespace std;

int BrojPom(string s)
{
    int brojac(0);
    
    for(int i=0; i<s.length(); i++)
        if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) brojac++;
    
    return brojac;
}

// Funkcija Razvrstavanje vrsi kruzno razvrstavanje stringova po duzini stringova
// u odredjeni broj timova
vector<set<string>> Razvrstavanje(vector<string> ime, int broj_tim)
{
    if(broj_tim<1 || broj_tim>ime.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    list<string> lista;
    for(int i=0; i<ime.size(); i++)
        lista.push_back(ime[i]);
    
    int broj_prvih_clan, broj_preo_clan, broj_prv_tim, broj_drug_tim;
    
    vector<set<string>> timovi;
    auto it(lista.begin());
    if(lista.size()%broj_tim==0)
    {
        broj_prvih_clan=lista.size()/broj_tim;
        for(int i=0; i<broj_tim; i++)
        {
            set<string> skup;
            for(int j=0; j<broj_prvih_clan; j++)
            {
                int korak(BrojPom(*it));
                skup.insert(*it);
                it=lista.erase(it);
                if(it==lista.end()) it=lista.begin();
                if(lista.size()==0) break;
                korak--;
                while(1)
                {
                    if(it!=lista.end()) it++;
                    if(it==lista.end()) it=lista.begin();
                    korak--;
                    if(korak==0) break;
                }
            }
            timovi.push_back(skup);
            if(lista.size()==0) break;
        }
    }
    else 
    {
        broj_prvih_clan=(lista.size()/broj_tim)+1;
        broj_preo_clan=broj_prvih_clan-1;
        broj_prv_tim=lista.size()%broj_tim;
        broj_drug_tim=broj_tim-broj_prv_tim;
    
        for(int i=0; i<broj_prv_tim; i++)
        {
            set<string> skup;
            for(int j=0; j<broj_prvih_clan; j++)
            {
                int korak(BrojPom(*it));
                skup.insert(*it);
                it=lista.erase(it);
                if(it==lista.end()) it=lista.begin();
                if(lista.size()==0) break;
                korak--;
                while(1)
                {
                    if(it!=lista.end()) it++;
                    if(it==lista.end()) it=lista.begin();
                    korak--;
                    if(korak==0) break;
                }
            }
            timovi.push_back(skup);
            if(lista.size()==0) break;
        }
        for(int i=0; i<broj_drug_tim; i++)
        {
            set<string> skup;
            for(int j=0; j<broj_preo_clan; j++)
            {
                int korak(BrojPom(*it));
                skup.insert(*it);
                it=lista.erase(it);
                if(it==lista.end()) it=lista.begin();
                if(lista.size()==0) break;
                korak--;
                while(1)
                {
                    if(it!=lista.end()) it++;
                    if(it==lista.end()) it=lista.begin();
                    korak--;
                    if(korak==0) break;
                }
            }
            timovi.push_back(skup);
            if(lista.size()==0) break;
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

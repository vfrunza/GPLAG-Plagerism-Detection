/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <stdexcept>

using namespace std ;

int BrojSlova(string s)
{
    int broj = 0 ; 
    for(int i=0 ; i<s.size() ; i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            broj++ ;
    }
    return broj ;
}

vector<set<string>> Razvrstavanje(vector<string> imena, int timovi)
{
    if(timovi<1 || imena.size()<timovi)
       throw logic_error("Razvrstavanje nemoguce");
    list<string> lista ; 
    vector<set<string>> povratni ;
    copy(imena.begin(), imena.end(), back_inserter(lista));
    // timovi sa n/k + 1 clanova
    auto it(lista.begin());
    for(int i=0 ; i<imena.size()%timovi ; i++)
    {
        set<string> skup ; 
        int broj_clanova = imena.size()/timovi + 1 ; 
        for(int j=0 ; j<broj_clanova ; j++)
        {
            skup.insert(*it);
            int velicina = BrojSlova(*it);
            it = lista.erase(it);
            if(it==lista.end())
                it=lista.begin();
            if(distance(it,lista.end())>velicina)
                advance(it,velicina-1);
            else
            {
                int brojac = 0 ; 
                while(brojac < velicina-1)
                {
                    if(distance(it,lista.end())==1)
                        it=lista.begin();
                    else it++ ; 
                    brojac++ ; 
                }
            }
        }
        povratni.push_back(skup);
    }
    //timovi sa n/k clanova
    for(int i=0 ; i<(timovi-imena.size()%timovi) ; i++)
    {
        set<string> skup ; 
        int broj_clanova = imena.size()/timovi ; 
        for(int j=0 ; j<broj_clanova ; j++)
        {
            skup.insert(*it);
            int velicina = BrojSlova(*it);
            it = lista.erase(it);
            if(it==lista.end())
                it=lista.begin();
            if(distance(it,lista.end())>velicina)
                advance(it,velicina-1);
            else
            {
                int brojac = 0 ; 
                while(brojac < velicina-1)
                {
                    if(distance(it,lista.end())==1)
                        it= lista.begin();
                    else it++ ; 
                    brojac++ ;
                }
            }
        }
        povratni.push_back(skup);
    }
    return povratni ; 
}

int main ()
{
    cout << "Unesite broj djece: " ; 
    int broj_djece ; 
    cin>> broj_djece;
    cin.ignore(10000, '\n');
    cout << "Unesite imena djece: " << endl ;
    vector<string> imena ; 
    for(int i=0 ; i<broj_djece ; i++)
    {
        string ime ; 
        getline(cin, ime);
        imena.push_back(ime);
    }
    cout << "Unesite broj timova: " ;
    int broj_timova ; 
    cin >> broj_timova ;
    try
    {
        vector<set<string>> rezultat = Razvrstavanje(imena, broj_timova);
        for(int i=0 ; i<rezultat.size() ; i++)
        {
            cout << "Tim " << i+1 << ": " ;
            for(set<string>::iterator x = rezultat[i].begin() ; x!=rezultat[i].end(); x++)
            {
                cout << *x ; 
                if(distance(x,rezultat[i].end())!=1)
                    cout << ", " ;
            }
            cout << endl ; 
        }
    }
    catch(logic_error m)
    {
        cout << "Izuzetak: " << m.what() << endl ;
    }
	return 0;
}
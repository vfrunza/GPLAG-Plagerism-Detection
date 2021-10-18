/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::vector;
using std::set;
using std::map;
using std::logic_error;
using std::string;


int Prebroji (string rijec)
{
    int broj(0);
    
    for (int i=0; i<rijec.length(); i++)
    {
        if ((rijec[i]>='A'&&rijec[i]<='Z')||(rijec[i]>='a'&&rijec[i]<='z')||(rijec[i]>='0'&&rijec[i]<='9'))
        {
            broj++;
        }
    }
    
    return broj;
}

vector<set<string>> Razvrstavanje (vector<string> grupa, int k)
{
    vector<set<string>> rez;
    vector<int> granice;
    list<string> kopija;
    set<string> temp, prazno;
    int vel, prvi, n, brojac(0), g(0), pravo(0);
    
    n=grupa.size();
    
    prvi=n%k;
    
    for (int i=0; i<k; i++)
    {
        if (i<prvi)
        {
            granice.push_back((n/k)+1);
        }
        
        else
        {
            granice.push_back(n/k);
        }
    }
    
    for (int i=0; i<n; i++)
    {
        kopija.push_back(grupa[i]);
    }
    
    auto x=kopija.begin();
    auto y(x);
    while (pravo!=grupa.size())
    {
        vel=Prebroji(*x);
    
        temp.insert(*x);
        y=x;
        if (x==--kopija.end())
        {
            x=kopija.erase(y);
            x++;
        }
        else
        {
            x=kopija.erase(y);
        }
        
  
        brojac++;
        
        if (brojac==granice[g])
        {
            rez.push_back(temp);
            g++;
            brojac=0;
            temp=prazno;
        }
        
        for (int d=1; d<vel; d++)
        {
            if (x==--kopija.end())
            {
                x=kopija.begin();
            }
            else
            {
                x++;
            }
        }
        
        pravo++;
    }
    
    return rez;
}


int main ()
{
    int n,k;
    string temp;
    vector<string> grupa;
    vector<set<string>> rez;
    try
    {
        cout<<"Unesite broj djece: ";
        cin>>n;
    
        std::cin.ignore(10000, '\n');
        cout<<"Unesite imena djece: ";
        for (int i=0; i<n; i++)
        {
            getline(cin,temp);
            grupa.push_back(temp);
        }
        cout<<endl;
    
        cout<<"Unesite broj timova: ";
        cin>>k;
        
        if (k>n||k<1)throw logic_error("Izuzetak: Razvrstavanje nemoguce");
    
        rez=Razvrstavanje(grupa,k);

        for (int j=0; j<rez.size(); j++)
        {
            cout<<"Tim "<<j+1<<": ";
            for (auto x=rez[j].begin(); x!=rez[j].end(); x++)
            {
                cout<<*x;
                if (x!=--rez[j].end())
                {
                    cout<<", ";
                }
            }
            cout<<endl;
        }
    }
    
    catch (logic_error izuzetak)
    {
        cout<<izuzetak.what();
    }

	return 0;
}
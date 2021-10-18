#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <list>
#include <set>

using std::cin;
using std::cout;
using std::vector;
using std::list;
using std::string;
using std::set;

struct Dijete
{
    string ime;
    Dijete *sljedeci;
};

vector<set<string>> Razvrstavanje(vector<string> djeca, int bt)
{
    if(bt<1 || bt>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    vector<set<string>> timovi(bt);
    
    Dijete *poc;
    Dijete *kr;
    poc=new Dijete;
    poc->ime=djeca[0];
    poc->sljedeci=nullptr;
    kr=poc;
    for(int i=1;i<djeca.size();i++)
    {
        Dijete *t;
        t=new Dijete;
        t->ime=djeca[i];
        t->sljedeci=nullptr;
        kr->sljedeci=t;
        kr=t;
    }
    kr->sljedeci=poc;
    
    int brc=djeca.size()%bt;
    int brct=0;
    int vel;
    if(brc) vel=djeca.size()/bt+1; else vel=djeca.size()/bt;
    int velt=0;
    
    while(1)
    {
        if(velt!=vel)
        {
            timovi[brct].insert(poc->ime);
            velt++;
        }
        else
        {
            velt=1;
            brct++;
            if(brct==brc) vel--;
            timovi[brct].insert(poc->ime);
        }
        if(poc->sljedeci!=poc)
        {
            int pomak=0;
            for(int i=0;i<poc->ime.length();i++) if((poc->ime[i]>='A' && poc->ime[i]<='Z') || (poc->ime[i]>='a' && poc->ime[i]<='z') || (poc->ime[i]>='0' && poc->ime[i]<='9')) pomak++;
            Dijete *t=poc;
            while(t->sljedeci!=poc) t=t->sljedeci;
            t->sljedeci=poc->sljedeci;
            t=poc;
            poc=poc->sljedeci;
            delete t;
            for(int i=1;i<pomak;i++) poc=poc->sljedeci;
        }
        else
        {
            delete poc;
            break;
        }
    }
    return timovi;
}

int main ()
{
    int n;
    cout << "Unesite broj djece: ";
    cin >> n;
    cin.ignore(1000, '\n');
    cout << "Unesite imena djece:\n";
    vector<string> d(n);
    for(string &a : d) std::getline(cin, a);
    int b;
    cout << "Unesite broj timova: ";
    cin >> b;
    try
    {
        vector<set<string>> tm=Razvrstavanje(d, b);
        for(int i=0;i<tm.size();i++)
        {
            cout << "Tim " << i+1 << ": ";
            int brc=tm[i].size()-1;
            for(string x : tm[i])
            {
                cout << x;
                if(brc) cout << ",";
                brc--;
                cout << " ";
            }
            cout << "\n";
        }
    }
    catch(std::logic_error ero)
    {
        cout << "Izuzetak: " << ero.what() << "\n";
    }
	return 0;
}
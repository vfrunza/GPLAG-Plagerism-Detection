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

vector<set<string>> Razvrstavanje(vector<string> djeca, int bt)
{
    if(bt<1 || bt>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    vector<set<string>> timovi(bt);
    list<string> ls;
    for(string a : djeca) ls.push_back(a);
    int brc=djeca.size()%bt;
    int brct=0;
    int vel;
    if(brc) vel=djeca.size()/bt+1; else vel=djeca.size()/bt;
    int velt=0;
    auto p=ls.begin();
    while(ls.size())
    {
        if(velt!=vel)
        {
            timovi[brct].insert(*p);
            velt++;
        }
        else
        {
            velt=1;
            brct++;
            if(brct==brc) vel--;
            timovi[brct].insert(*p);
        }
        int pomak=0;
        for(int i=0;i<(*p).length();i++) if(((*p)[i]>='A' && (*p)[i]<='Z') || ((*p)[i]>='a' && (*p)[i]<='z') || ((*p)[i]>='0' && (*p)[i]<='9')) pomak++;
        p=ls.erase(p);
        if(p==ls.end()) p=ls.begin();
        for(int i=1;i<pomak;i++)
        {
            p++;
            if(p==ls.end()) p=ls.begin();
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
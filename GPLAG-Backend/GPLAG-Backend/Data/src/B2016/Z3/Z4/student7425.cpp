/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>

using namespace std;

void prebroj(int &slova, string s)
{
    slova=0;
    for(int i=0; i<s.size(); i++)
        if((s[i]>='0'&&s[i]<='9')||(tolower(s[i])>='a'&&tolower(s[i])<='z')) slova++;
    slova--;
}

vector<set<string>> Razvrstavanje(vector<string> v, int n)
{
    list<string> djeca;
    vector<set<string>> timovi;
    if(v.size()<n || 1>n) throw logic_error("Razvrstavanje nemoguce");
    for(int i=0; i<v.size(); i++) djeca.push_back(v[i]);
    int slova;
    auto it=djeca.begin();
    int jednom=1;
    if(n==v.size())
    {
        for(auto x:djeca) { set<string> s; s.insert(x); timovi.push_back(s);}
        return timovi;
    }
    bool jest=false;
    for(int i=0; i<v.size()%n; i++)
    {
        set<string> s;
        jest=true;
        if(i==0) {prebroj(slova,*it);}
        //if(i==0) { skup.insert(*djeca.begin()); it=djeca.erase(it); a--; brs--;}
        for(int j=0; j<(v.size()/n)+1; j++)
        {
            if(i==0 && jednom==1) { jednom=0; s.insert(*it); it=djeca.erase(it); j++; }
            while(slova>0) 
            { 
               it++;
               slova--;
               if(it==djeca.end()) it=djeca.begin();
            }
            prebroj(slova,*it);
            s.insert(*it);
            it=djeca.erase(it);
            if(it==djeca.end()) it=djeca.begin();
        }
        timovi.push_back(s);
    }
    int hel=9999;
    if(jest) hel=slova;
    
    for(int i=0; i<n-v.size()%n; i++)
    {
        set<string> s;
        if(hel!=9999 && i==0) { slova=hel; hel=9999;}
        else if(i==0) prebroj(slova,*it);
        //if(i==0 && jednom==1) { jednom=0; skup.insert(*djeca.begin()); it=djeca.erase(it); a--; brs--;}
        for(int j=0; j<(v.size()/n); j++)
        {
            if(i==0 && jednom==1) { jednom=0; s.insert(*it); it=djeca.erase(it); if(n!=v.size())j++; }
            while(slova!=0) 
            { 
               it++;
               slova--;
               if(it==djeca.end()) it=djeca.begin();
            }
            prebroj(slova,*it);
            s.insert(*it);
            it=djeca.erase(it);
            if(it==djeca.end()) it=djeca.begin();
        }
        timovi.push_back(s);
    }
    return timovi;
}

void Ispisi(vector<set<string>> timovi)
{
    try
    {
        for(int i=0; i<timovi.size(); i++)
        {
            cout<<"Tim "<<i+1<<": ";
            auto cl=timovi[i].size()-1;
            for(auto it: timovi[i])
            {
                if(cl==0) cout<<it;
                else cout<<it<<", ";
                cl--;
            }
            cout<<endl;
        }
    }
    catch(logic_error izuz) {throw izuz;}
}

int main ()
{
	cout<<"Unesite broj djece: ";
	int br; cin>>br;
	vector<string> djeca; 
	cout<<"Unesite imena djece: "<<endl;
	cin.clear(); cin.ignore(100000, '\n');
	for(int i=0; i<br; i++) { string p; getline(cin,p); djeca.push_back(p);}
	int brt;
	cout<<"Unesite broj timova: ";
	cin>>brt;
	try
	{
	    vector<set<string>> timovi=Razvrstavanje(djeca,brt);
	    Ispisi(timovi);
	    return 0;
	}
	catch(logic_error izuz) {cout<<"Izuzetak: "<<izuz.what();}
	return 0;
}
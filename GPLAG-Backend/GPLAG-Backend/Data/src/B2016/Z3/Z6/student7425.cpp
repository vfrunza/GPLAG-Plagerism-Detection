/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <memory>
using namespace std;

struct Dijete
{
    string ime;
    shared_ptr<Dijete> sljedeci;
};

shared_ptr<Dijete> lista(vector<string> v)
{
   shared_ptr<Dijete> pocetak=nullptr; shared_ptr<Dijete> temp=nullptr;
    for(int i=0; i<v.size(); i++)
    {
        shared_ptr<Dijete> temp2 = make_shared<Dijete>();
        temp2->ime=v[i];
        if(i!=0)
        {
            temp->sljedeci=temp2;
            temp=temp2;
        }
        else { pocetak=temp2; temp=temp2;}
        if(i==v.size()-1) temp2->sljedeci=pocetak;
    }
    return pocetak;
}

void prebroj(int &slova, string s)
{
    slova=0;
    for(int i=0; i<s.size(); i++)
        if((s[i]>='0'&&s[i]<='9')||(tolower(s[i])>='a'&&tolower(s[i])<='z')) slova++;
    slova--;
}

vector<set<string>> Razvrstavanje(vector<string> v, int n)
{
    vector<set<string>> timovi;
    if(v.size()<n || 1>n) throw logic_error("Razvrstavanje nemoguce");
    shared_ptr<Dijete> djeca=lista(v);
    shared_ptr<Dijete> poc=djeca;
    shared_ptr<Dijete> kraj=djeca;
    while(kraj->sljedeci!=poc) kraj=kraj->sljedeci;
    int slova;
    shared_ptr<Dijete> it=poc;
    int jednom=1;
    if(n==v.size())
    {
        while(it->sljedeci!=poc) { 
            set<string>s; s.insert(it->ime); timovi.push_back(s); it=it->sljedeci;}
        set<string>s1; s1.insert(it->ime); timovi.push_back(s1); it=poc;
        while(it->sljedeci!=poc) {
            kraj->sljedeci=it->sljedeci;
            it->sljedeci=nullptr; 
            it=kraj->sljedeci;
        }
        
        return timovi;
    } 
    bool jest=false;
    for(int i=0; i<v.size()%n; i++)
    {
        set<string> s;
        jest=true;
        if(i==0) {prebroj(slova,it->ime);}
        for(int j=0; j<(v.size()/n)+1; j++)
        {
            if(i==0 && jednom==1) { jednom=0; s.insert(it->ime); kraj->sljedeci=it->sljedeci;
            it->sljedeci=nullptr; 
            it=kraj->sljedeci; j++; }
            while(slova>0) 
            { 
               it=it->sljedeci;
               kraj=kraj->sljedeci;
               slova--;
            }
            prebroj(slova,it->ime);
            s.insert(it->ime);
            kraj->sljedeci=it->sljedeci;
            it->sljedeci=nullptr; 
            it=kraj->sljedeci;
            
        }
        timovi.push_back(s);
    }
    int hel=9999;
    if(jest) hel=slova;
    for(int i=0; i<n-v.size()%n; i++)
    {
        set<string> s;
        if(hel!=9999 && i==0) { slova=hel; hel=9999;}
        else if(i==0) prebroj(slova,it->ime);
        //if(i==0 && jednom==1) { jednom=0; skup.insert(*djeca.begin()); it=djeca.erase(it); a--; brs--;}
        for(int j=0; j<(v.size()/n); j++)
        {
            if(i==0 && jednom==1) { jednom=0; s.insert(it->ime); if(j==(v.size()/n)-1 && i==n-v.size()%n-1) { it->sljedeci=nullptr; }
            else
            {
                kraj->sljedeci=it->sljedeci;
            it->sljedeci=nullptr; 
            it=kraj->sljedeci;
            } j++; }
            while(slova!=0) 
            { 
               it=it->sljedeci;
               kraj=kraj->sljedeci;
               slova--;
            }
            prebroj(slova,it->ime);
            s.insert(it->ime);
            if(j==(v.size()/n)-1 && i==n-v.size()%n-1) { it->sljedeci=nullptr; }
            else
            {
                kraj->sljedeci=it->sljedeci;
            it->sljedeci=nullptr; 
            it=kraj->sljedeci;
            }
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
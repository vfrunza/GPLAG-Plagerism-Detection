#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <memory>
using namespace std;


struct Dijete
{
    string ime;
    shared_ptr<Dijete>sljedeci; 
};


vector<int> broji(vector<string>s, int n)
{
    vector<int>v(n);
    if((s.size()%n)==0)
    {
        for(int i=0;i<n;i++)
        v[i]=s.size()/n;
    }
    else
    {
        for(int i=0;i<(s.size()%n);i++)
        v[i]=(s.size()/n)+1;
        for(int i=s.size()%n;i<n;i++)
        v[i]=s.size()/n;
    }
    return v;
}

int BrojanjeRijeci(string s)
{
    int br=0;
    for(const auto &i:s)
    if((toupper(i)>='A' && toupper(i)<='Z') || (i>='0' && i<='9'))
    br++;
    return br;
}
int prebrojitim(set<string> tim)
{
    int br=0;
    for(auto i: tim)
    br++;
    return br;
}

vector<set<string>> Razvrstavanje(vector<string>s, int n)
{
    if(n>s.size() || n<1)throw logic_error("Razvrstavanje nemoguce");
    vector<int>timovi=broji(s,n);
    vector<set<string>> poziv;
    set<string>tim;
    int velicina=s.size();
    shared_ptr<Dijete>pocetak(nullptr), prethodni;
   try
    {
        for(const auto &i:s)
        {
        
            shared_ptr<Dijete>novi(new Dijete);
            novi->ime=i; novi->sljedeci=nullptr;
            if(!pocetak)pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
         }
         
        prethodni->sljedeci=pocetak; 
        shared_ptr<Dijete>pom=pocetak;
        
        for(int i=0;i<n;i++)
        {
            int vel=timovi[i];
            set<string>tim;
            while(1)
            {
                if(prebrojitim(tim)<vel)
                {
                tim.insert(pom->ime);
                velicina--;
                if(velicina==0){pom->sljedeci=nullptr;break;}
                }
                else break;
                int duzina=BrojanjeRijeci(pom->ime);
            
                shared_ptr<Dijete>pom1=pom->sljedeci;
                
                while(pom1->sljedeci!=pom)
                pom1=pom1->sljedeci;
                pom1->sljedeci=pom->sljedeci;
                if(pom!=nullptr)
                pom=nullptr;
                pom=pom1;
                    for(int i=0;i<duzina;i++)
                pom=pom->sljedeci;
                
            }
        poziv.push_back(tim);
    }
    
    return poziv;
    }
    catch(bad_alloc)
    {
        throw;
    }
    
}
int main ()
{
    vector<string>djeca;
    vector<set<string>>poziv;
    cout<<"Unesite broj djece: ";
    int br_djece=0;
    cin>>br_djece;
    cout<<"Unesite imena djece: "<<endl;
    string s;
    getline(cin,s);
    for(int i=0;i<br_djece;i++)
    {
        getline(cin,s),
        djeca.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    int br_timova=0;
    cin>>br_timova;
    try
    {
        poziv=Razvrstavanje(djeca,br_timova);
        for(int j=0;j<poziv.size();j++)
        {
            cout<<"Tim "<<j+1<<": ";
            for(auto i=poziv[j].begin();i!=poziv[j].end();)
            {
                cout<<*i;
                i++;
             if(i!=poziv[j].end())
             cout<<", ";
            }
            cout<<endl;
        }
    }
    catch(logic_error Izuzetak)
    {
    cout<<"Izuzetak: "<<Izuzetak.what();
    }
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
using namespace std;

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
    int BrojSlova=0;
    vector<set<string>> vrati ;
    list<string>imena;
    set<string>tim;
    for(const auto &i : s){
     imena.push_back(i);
    }
    vector<int>timovi=broji(s,n);
    auto i=imena.begin();
    for(int j=0;j<n;j++)
    {
        int vel=timovi[j];
        set<string>tim;
                 for(;;)
                    {     
                        if(prebrojitim(tim)<vel)  
                        tim.insert(*i);
                        else break;
                        BrojSlova=BrojanjeRijeci(*i);
                        i=imena.erase(i);
                        if(i==imena.end())i=imena.begin();
                        if(imena.size()==0)break;
                        for(int b=1;b<BrojSlova;b++)
                        {
                            i++;
                            if(i==imena.end())i=imena.begin();
                        }
                    }
         vrati.push_back(tim);
    }
     return vrati;
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
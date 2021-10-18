/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>
#include <iterator>
#include <new>
#include <memory>
using namespace std;
struct Dijete {
    string ime;
    shared_ptr<Dijete> sljedeci;
};

vector<set<string>> Razvrstavanje(vector<string> v, int n)
{
    if(n<1 || n>v.size()) throw logic_error("Razvrstavanje nemoguce");
    shared_ptr<Dijete> pocetak(nullptr);
    shared_ptr<Dijete> prethodni;
    for(int i=0;i<v.size();i++)
    {
        shared_ptr<Dijete> novi(new Dijete);
        novi->ime=v[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==v.size()-1) prethodni->sljedeci=pocetak;
    }
     vector<set<string>> v1(n);
     int c(v.size()%n);
     shared_ptr<Dijete> pom (pocetak);
     int duz(0);
     for(int i=0;i<n;i++)
     {
         
         if(c!=0)
         {
             int p((v.size()/n)+1);
             c--;
             while(p!=0)
             {
                 p--; 
                 int k(0);
                 shared_ptr<Dijete>ut;
                for(;;)
                {
                    if(k==(duz-1) || k==duz) break;
                    if(k==(duz-2)){ ut=pom;}
                    k++;
                    pom=pom->sljedeci;
                }
                   for(int h=0;h<(pom->ime).length();h++)
                {
                    if(h==0) duz=0;
                    if(((pom->ime)[h]>='A' && (pom->ime)[h]<='Z') || ((pom->ime)[h]>='a' && (pom->ime)[h]<='z') || ((pom->ime)[h]>='0' && (pom->ime)[h]<='9')) duz++;
                }
                v1[i].insert(pom->ime);
                if(pom==pocetak && pom!=prethodni) { prethodni->sljedeci=pocetak->sljedeci; pocetak=pocetak->sljedeci;}
                else if(pom==prethodni && pom!=pocetak) {ut->sljedeci=pom->sljedeci; prethodni=ut;}
                else {ut->sljedeci=pom->sljedeci;}
                if(pom==pocetak && pom==prethodni)
                pom->sljedeci=nullptr;
                else pom=pom->sljedeci;
             }
         }
         else {
             int q(v.size()/n);
             while(q!=0)
             {
                 q--;
                  int k(0);
                 shared_ptr<Dijete> ut;
                for(;;)
                {
                    if(k==(duz-1) || k==duz) break;
                    if(k==(duz-2)){ ut=pom;}
                    k++;
                    pom=pom->sljedeci;
                }
                   for(int h=0;h<(pom->ime).length();h++)
                {
                    if(h==0) duz=0;
                    if(((pom->ime)[h]>='A' && (pom->ime)[h]<='Z') || ((pom->ime)[h]>='a' && (pom->ime)[h]<='z') || ((pom->ime)[h]>='0' && (pom->ime)[h]<='9')) duz++;
                }
                v1[i].insert(pom->ime);
                if(pom==pocetak && pom!=prethodni) { prethodni->sljedeci=pocetak->sljedeci; pocetak=pocetak->sljedeci;}
                else if(pom==prethodni && pom!=pocetak){ ut->sljedeci=pocetak; prethodni=ut;}
                else {ut->sljedeci=pom->sljedeci;}
                if(pom==pocetak && pom==prethodni)
                pom->sljedeci=nullptr;
                else pom=pom->sljedeci;
             }
         }
     }
     return v1;
}
int main ()
{
       int n,tim;
    cout<<"Unesite broj djece: ";
    cin>>n;
    vector<string> v(n);
    cout<<"Unesite imena djece: "<<endl;
    string a;
    cin.ignore(10000,'\n');
    for(int i=0;i<n;i++)
    {
        
         getline(cin,a);
         for(int h=0;h<a.length();h++)
         v[i].push_back(a[h]);
         
    }
    cout<<"Unesite broj timova: ";
    cin>>tim;
    vector<set<string>> v1;
    try {
    v1=Razvrstavanje(v,tim);
    for(int i=0;i<tim;i++)
    {
        cout<<"Tim "<<i+1<<": ";
        auto it12=v1[i].end(); it12--;
        for(set<string>::iterator x=v1[i].begin();x!=v1[i].end();x++)
        {
            cout<<*x;
            if(x!=it12) cout<<", ";
            
        }
        cout<<endl;
    }
}
    catch(logic_error e)
    {
        cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>
#include <iterator>

using namespace std;

auto Postavi(list<string>::iterator iter,list<string> &l,int n) -> decltype (iter) {
    for(int i=0;i<n-1;i++)
    {
        auto pom=l.end(); pom--;
        auto pom1=l.begin();
        if(iter==pom) iter=pom1; 
        else iter++;
    
    }
    return iter; 
} 
vector<set<string>> Razvrstavanje(vector<string> v, int n)
{
    if(n<1 || n>v.size()) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> v1(n);
    list<string> lista;
    for(auto x: v) lista.push_back(x);
    int b(v.size());
    auto it=lista.begin();
    v1[0].insert(*it);
    int c(v.size()%n);
    for(int i=0;i<n;i++)
    {
        
        if(c!=0)
        {
            int p((b/n)+1);
            c--;
            if(i==0) p--;
            while(p!=0)
            {
                p--;
                //int duz((it)->length());
                string s(*it); int duz(0);
                for(int h=0;h<s.length();h++)
                {
                    if((s[h]>='A' && s[h]<='Z') || (s[h]>='a' && s[h]<='z') || (s[h]>='0' && s[h]<='9')) duz++;
                }
                auto pom1=lista.end(); pom1--;
                auto pom2=lista.begin();
                if(it==pom1){auto itt=it; lista.erase(itt); it=pom2;}
                else it=lista.erase(it);
                if(pom1==pom2) { v1[i].insert(*it); break;}
                auto it2=it;
                it=Postavi(it2,lista,duz);
                v1[i].insert(*it);
            }
        }
        else
        {
            int q(b/n);
            
            if(i==0) q--;
            while(q!=0)
            {
                q--;
              //  int d((*it).size());
                string s(*it); int d(0);
                for(int h=0;h<s.length();h++)
                {
                    if((s[h]>='A' && s[h]<='Z') || (s[h]>='a' && s[h]<='z') || (s[h]>='0' && s[h]<='9')) d++;
                }
                auto pom1=lista.end(); pom1--;
                auto pom2=lista.begin();
                if(it==pom1){auto itt=it; lista.erase(itt); it=pom2;}
                else it=lista.erase(it);
                if(pom1==pom2) { v1[i].insert(*it); break;}
                auto it1=it;
                it=Postavi(it1,lista,d);
                v1[i].insert(*it); 
             
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
/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>

using namespace std;

vector<int> PobrojiTimove(int n,int k)
{
    vector<int> v(k);
    for(int i=0;i<v.size();i++)
    {
        if(i<n%k)
            v[i]=(n/k)+1;
        else v[i]=n/k;
        
    }
    return v;
}

vector<set<string>> Razbrajanje(vector<string> Djeca,int k)
{
    int n=Djeca.size();
    vector<set<string>> v(n);
    vector<int> br=PobrojiTimove(n,k);
    
    list<string> l;
    for(int i=0;i<Djeca.size();i++)
        l.insert(Djeca[i]);
        
    auto p=l.begin();auto q=l.end();
    for(int i=0;i<v.size();i++)
    {   
        set<string> pom;
        for(int j=0;j<br[i];j++)
        {
            pom.insert(*p);int k=p->size();
            p=l.erase(p);if(p==q)p=l.begin();
            
            auto m=p;
            for(;k!=0;k--)
                m++;
            p=m;
        }
        v.push_back(pom);
    }
    return v;
}



int main ()
{
	return 0;
}
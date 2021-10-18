/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>

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

vector<set<string>> Razvrstavanje(vector<string> Djeca,int k)
{   
    int n=Djeca.size();
    if(k>n || n<1) throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> v(k);
    vector<int> br=PobrojiTimove(n,k);
    list<string> l;
    for(int i=0;i<Djeca.size();i++)
         l.push_back(Djeca[i]);
    auto p=l.begin();auto q=l.end();
    for(int i=0;i<v.size();i++)
    {
        set<string> pom;
        for(int j=0;j<br[i];j++)
        {
            pom.insert(*p);int k=0;
            
            for(auto g:*p)
            {
                if((g>='A' && g<='Z') ||(g>='a' && g<='z')||(g>='0' && g<='9'))
                        k++;
            }
            k-=1;
            
            p=l.erase(p);if(p==q)p=l.begin();
            auto m=p;
            for(;k!=0;k--)
            {m++;if(m==q)m=l.begin();}
            p=m;
        }
        v[i]=pom;
    }
    
    return v;
}



int main ()
{
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    vector<string>v(n);
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"Unesite imena djece: "<<endl;
    for(int i=0;i<v.size();i++)
	    getline(cin,v[i]);
	cout<<"Unesite broj timova: ";
	cin>>n;
	try{
	vector<set<string>> Timovi=Razvrstavanje(v,n);
	for(int i=0;i<Timovi.size();i++)
	{   
	    cout<<"Tim "<<i+1<<": ";int br=0;
	    for(auto p:Timovi[i]){
	        if(br==Timovi[i].size()-1) cout<<p<<endl;
	            else cout<<p<<", ";
	        br++;
	    }
	}
	}
	catch(logic_error e){cout<<"Izuzetak: "<<e.what();}
	return 0;
}
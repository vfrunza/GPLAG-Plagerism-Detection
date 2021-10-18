/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <list>
#include <set>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::set;
using std::list;
int DuzinaStringa(string s)
{
    int i(0),br(0);
    while(i<s.length()) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            br++;
        i++;
    }
    return br;
}
vector<set<string>> Razvrstavanje(vector<string> v,int k)
{
    if(k<1 || k>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    list<string> l;
    for(int i=0; i<v.size(); i++) {
        l.push_back(v[i]);
    }
    vector<set<string>> a(k);
    if(v.size()==0)
        return a;
    auto it(l.begin());
    int t(0);
    for(int m=0; m<v.size()%k; m++) {
        for(int i=0; i<(v.size()/k)+1; i++) {
            a[t].insert(*it);
            string ime(*it);
            auto n(DuzinaStringa(ime));
            it= l.erase(it);
            if(it==l.end()) it=l.begin();
            for(int j=0; j<n-1; j++) {
                it++;
                if(it==l.end()) it=l.begin();
            }
        }
        t++;
    }
    while(1) {
        for(int i=0; i<v.size()/k; i++) {
            a[t].insert(*it);
            auto n(DuzinaStringa(*it));
            it=l.erase(it);
            if(l.size()==0) continue;
            if(it==l.end()) it=l.begin();
            for(int j=0; j<n-1; j++) {
                 it++;
                if(it==l.end())
                    it=l.begin();
               
            }
            
        }
        if(l.size()==0) break;
        t++;
    }
    return a;
}
int main ()
{
    string s;
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cin.ignore(10000,'\n');
    vector<string> v;
    cout<<"Unesite imena djece: \n";
    for(int i=0; i<n; i++) {
        std::getline(cin,s);
        v.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    int k;
    cin>>k;
    try
    {
        vector<set<string>> x(Razvrstavanje(v,k));
    
    for(int i=0; i<k; i++) {
        int br(0);
        cout << "Tim " << i+1 << ": ";
        for(auto a: x[i]){
            if(br==x[i].size()-1) cout << a;
            else cout << a << ", ";
            br++;
        }
        cout << std::endl;
    }
    }
    catch(std::logic_error izuzetak)
    {
        cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    return 0;
}
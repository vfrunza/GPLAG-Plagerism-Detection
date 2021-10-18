/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>
using std::string;
using std::cout;
using std::set;
using std::vector;
using std::list;
int DuzinaStringa(string s)
{
    int br(0);
    for(int i = 0 ; i < s.size() ; i++ ) {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            br++;
    }
    return br;
}

vector<set<string>> Razvrstavanje(vector<string> v , int k)
{
    vector<set<string>> vs;
    int n(int( v.size()));
    if(k<1 || k>n) throw std::logic_error ("Razvrstavanje nemoguce");
    int s(n/k);
    int ostatak(n%k);

    list<string> l;
    vector<int> br_clanova(k);
    for(int i=0 ; i<k ; i++) {
        br_clanova[i]=s;
        if(ostatak!=0 ) {
            br_clanova[i]++;
            ostatak--;
        }

    }
    for(int i = 0 ; i < v.size() ; i++ ) {
        l.push_back(v[i]);
    }
    int i(0);
    auto it = l.begin();


    while(it!=l.end() && l.begin()!=l.end()) {
        while(i<k) {
            set<string> skup;

            for(int j=0; j<br_clanova[i] ;  j++) {
                skup.insert(*it);
                int m;
                m=DuzinaStringa(*it);
                m--;
                it=l.erase(it);
                if(it==l.end())  it=l.begin();
                while(m>0) {

                    it++;
                    m--;
                    if(it==l.end())  it=l.begin();

                }

            }

            vs.push_back(skup);

            i++;
        }

    }




    return vs;
}
void IspisiSkupImena(set<string> skup)
{
    auto it(skup.begin());
    for(int i = 0; i < skup.size()-1 ; i++)
        std::cout << *it++ << ", ";
    std::cout << *it  ;
}
int main ()
{

    int n;
    cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cin.ignore(10000, '\n');
    cout<<"Unesite imena djece: ";

    vector<string> v;
    for(int i= 0 ; i<n ; i++) {
        string rijec;
        std::getline(std::cin, rijec);
        v.push_back(rijec);


    }
    cout<<std::endl;
    int k;
    cout<<"Unesite broj timova: ";
    std::cin>>k;
    try {
        vector<set<string>> vs;
        vs.resize(k);
        vs=Razvrstavanje(v,k);
        for(int i = 0 ; i < k ; i++ ) {
            cout<<"Tim "<<i+1<<": ";
            IspisiSkupImena(vs[i]);
            cout<<std::endl;
        }
    } catch(std::logic_error a) {
        cout<<"Izuzetak: "<<a.what()<<std::endl;
    }

    return 0;
}
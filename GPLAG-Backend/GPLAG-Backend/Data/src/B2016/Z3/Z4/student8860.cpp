/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <stdexcept>
using namespace std;
int VelicinaImena(string s){
    int velicinaimena(0);
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>=48 && s[i]<=57)) velicinaimena++;
    }
    return velicinaimena;
}
vector<set<string>> Razvrstavanje(vector<string> s, int n)
{
    list<string> lista;
    for(int i=0; i<s.size(); i++) {
        lista.push_back(s[i]);
    }
    vector<set<string>> razvrstani(n);
    auto it(lista.begin());
    razvrstani[0].insert(*it);
    string prvi=*it;
        int velicinaimena=VelicinaImena(prvi);
    it=lista.erase(it);
    int brojac(0);
    int t=(s.size())%n;
     int brojacubacenih(1);
    for(int i=0; i<n; i++) {
        while(it!=lista.end()) {
            brojac++;
            string ime=*it;
            if(brojac==velicinaimena) {
                brojacubacenih++;
                razvrstani[i].insert(ime);
                brojac=0;
                velicinaimena=VelicinaImena(ime);
                it=lista.erase(it);
            } else {
                it++;
            }
            if(it==lista.end()) it=lista.begin();
            if(i<t && brojacubacenih==s.size()/n+1){ brojacubacenih=0; break;}
            if(i>=t && brojacubacenih==s.size()/n){ brojacubacenih=0; break;}
        }
    }
    return razvrstani;
}
int main ()
{
    try {
        cout<<"Unesite broj djece: ";
        int n;
        cin>>n;
        cin.ignore(1000,'\n');
        vector<string> imena;
        cout<<"Unesite imena djece: ";
        for(int i=0; i<n; i++) {
            string ime;
            getline(cin,ime);
            imena.push_back(ime);
        }
        cout<<"\nUnesite broj timova: ";
        int m;
        cin>>m;
        if(m<1 || m>n) throw std::logic_error("Razvrstavanje nemoguce");
        vector<set<string>> razvrstani=Razvrstavanje(imena,m);
        for(int i=0; i<m; i++) {
            cout<<"Tim "<<i+1<<": ";
            for(auto element:razvrstani[i]) {
                if(element!=*max_element(razvrstani[i].begin(),razvrstani[i].end())) {
                    cout<<element<<", ";
                } else {
                    cout<<element;
                }
            }
            cout<<endl;
        }
    } catch(std::logic_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    }
    return 0;
}
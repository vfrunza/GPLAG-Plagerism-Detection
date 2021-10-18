/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <set>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::string;
using std::set;

int brojKoraka(string s){
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if((s[i]>='0' && s[i]<='9')||(s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
        c++;
    }
    return c-1;
} 
list<string>::iterator dajSljedeceg(list<string> &a, list<string>::iterator poz){
    int u = brojKoraka(*poz);
    poz = a.erase(poz);
    for (int i = 0; i < u; i++) {
        if(poz==a.end()){ 
            poz=a.begin();
            i--;
            if(a.begin()==a.end())return a.begin();
            continue;
        }
        poz++;
    }
    if(poz==a.end())poz=a.begin();
    return poz;
}
vector<set<string>> Razvrstavanje(vector<string> imena, int b){
    if(b<1 || b>imena.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    list<string> listaImena;
    for (int i = 0; i < imena.size(); i++) {
        listaImena.push_back(imena[i]);
    }
    auto poz = listaImena.begin();
    vector<set<string>> izlaz;
    int prvih = imena.size()%b;
    int clanova = imena.size()/b;
    for (int i = 0; i < b; i++) {
        set<string> tmp;
        for (int j = 0; ((j<clanova ) || (j<clanova+1 && i<prvih)); j++) {
            //cout<<"Ubacujem u "<<i<<". tim "<<*poz<<endl;
            tmp.insert(*poz);
            poz = dajSljedeceg(listaImena,poz);
        }
        izlaz.push_back(tmp);
    }
    return izlaz;
}
int main ()
{
    vector<string> test;
    int n=0;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cin.ignore(1);
    cout<<"Unesite imena djece: \n";
    for (int i = 0; i < n; i++) {
        if(cin.peek()=='\n')cin.ignore(1);
        string s;
        std::getline(cin,s);
        test.push_back(s);
    }
    cout<<"Unesite broj timova: ";
    cin>>n;
    try{
        auto rez = Razvrstavanje(test,n);
        for (int i = 0; i < rez.size(); i++) {
            cout<<"Tim "<<i+1<<": ";
            auto r = rez[i].begin();
            for (int j = 0; j < rez[i].size(); j++) {
                    cout<<*r;
                    if(j!=rez[i].size()-1)cout<<", ";
                    r++;
            }
            cout<<endl;
        }
    }catch(std::logic_error e){
        cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}
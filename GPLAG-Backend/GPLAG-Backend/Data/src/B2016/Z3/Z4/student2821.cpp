/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <utility>
#include <set>
#include <stdexcept>

using std::cin;
using std::cout;

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece,int x)
{
    std::list<std::string> lista;
    std::vector<std::set<std::string>> timovi;
    std::copy(imena_djece.begin(),imena_djece.end(),std::back_inserter(lista));
    int broj_djece(0);
    int n(0);
    for(auto it(lista.begin()); it!=lista.end(); it++) {
        broj_djece++;
    }
    if(x<1 or broj_djece<x) throw std::logic_error("Razvrstavanje nemoguce");
    auto it(lista.begin());
    while(!lista.empty()) {
        n=broj_djece/x;
        std::set<std::string> tim;
        for(int i=0; i<n+bool(broj_djece%x); i++) {
            int broj_slova(0);
            tim.insert(*it);
            for(int i=0; i<(*it).length(); i++) {
                if((((*it)[i])>='0' and ((*it)[i])<='9') or (((*it)[i])>='A' and ((*it)[i])<='Z') or (((*it)[i])>='a' and ((*it)[i])<='z')) broj_slova++;
            }
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
            for(int i=0; i<broj_slova-1; i++) {
                it++;
                if(it==lista.end()) it=lista.begin();
            }
        }
        timovi.push_back(tim);
        int v(tim.size());
        broj_djece=broj_djece-v;
        x=x-1;
    }
    return timovi ;

}

int main ()
{
    int n;
    cout<<"Unesite broj djece: ";
    cin>>n;
    cin.ignore(10000,'\n');
    cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string> imena_djece;
    std::string s;
    for(int i=0; i<n; i++) {
        std::string s;
        std::getline(cin,s);
        imena_djece.push_back(s);
    }
    int x;
    cout<<"Unesite broj timova: ";
    cin>>x;
    cin.ignore(10000,'\n');
    std::vector<std::set<std::string>> timovi;
    try {
        timovi=Razvrstavanje(imena_djece,x);
        int i(1);
        for(auto m: timovi) {
            std::string najveci {};
            cout<< "Tim "<<i<<": ";
            for(auto p: m) {
                if(p>najveci) najveci=p;
            }
            for(auto p: m) {
                if(p==najveci) cout<<p;
                else cout<<p<<", ";
            }
            cout<<std::endl;
            i++;
        }
    } catch(std::logic_error izuzetak) {
        cout<< "Izuzetak: " <<izuzetak.what();
    }
    return 0;
}
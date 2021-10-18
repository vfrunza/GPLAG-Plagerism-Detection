/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <utility>
#include <iterator>
#include <stdexcept>
#include <vector>

using std::string;
using std::map;
using std::cout;
using std::set;

map<string,set<int>> KreirajIndeksPojmova (string s)
{


    for(int i=0 ; i<s.size() ; i++) {
        if(s[i]>='A' && s[i]<='Z') s[i] += 'a'-'A';

    }

    map<string,set<int>> mapa;


    for(int i=0 ; i<s.size() ; i++) {
        int j(0);

        string pomocni;
        for(int k=i ; k<s.size() ; k++) {
            if((s[k]>='a' && s[k]<='z') || (s[k]>='0' && s[k]<='9')) {
                pomocni.push_back(s[k]);
                j++;

            } else break;
        }



        if(j>0) {
            if(mapa.find(pomocni)==mapa.end()) {
                set<int> skup;
                skup.insert(i);
                mapa.insert(std::make_pair(pomocni, skup));
            } else {
                auto t(mapa.find(pomocni));
                t->second.insert(i);
            }
        }

        i = i+j;




    }
    return mapa;
}


void IspisiSkupBrojeva(set<int> s)
{
    auto it(s.begin());
    for(int i = 0; i < s.size()-1 ; i++)
        std::cout << *it++ << ",";
    std::cout << *it  ;

}


void IspisiIndeksPojmova (map<string,set<int>> m)
{
    for(auto it = m.begin(); it != m.end(); it++) {
        cout<<it->first <<": ";
        IspisiSkupBrojeva(it->second);
        cout<<std::endl;
    }
}


set<int> PretraziIndeksPojmova(string s, map<string,set<int>> m)
{
    auto it(m.find(s));
    if(it == m.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    return it->second;
}


int main ()
{
    std::string s;
    map<string,set<int>> m;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    m=KreirajIndeksPojmova(s);

    IspisiIndeksPojmova(m);

    while(1) {
        string rijennc;
        cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        else {
            try {
                set<int> skup=PretraziIndeksPojmova(rijec,m);
                for(auto x : skup ) cout<<x<<" ";
                cout<<std::endl;
            } catch(std::logic_error a) {
                cout<<a.what()<<std::endl;
            }
        }

    }

    return 0;
}
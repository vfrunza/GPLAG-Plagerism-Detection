/B2017/2018: Zadaća 3, Zadatak 2
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
using std::vector;
using std::tuple;

typedef map<string, vector<string>> Knjiga;

map<string, set<tuple<string, int, int>>> KreirajIndeksPojmova(Knjiga k)
{
    map<string, set<tuple<string, int, int>>> m;
    for(auto it=k.begin() ; it!=k.end() ; it++) {
        vector<string> v(it->second);
        for(int i=0 ; i<v.size() ; i++) {
            int j(0);
            string s(v.at(i));
            while(j!=s.length()) {
                int duz(0);
                while((s.at(j)<'0' || (s.at(j)>'9' && s.at(j)<'A') || ( s.at(j)>'Z' && s.at(j)<'a' ) || s.at(j)>'z' ) && j!=s.length() ) j++;
                if(j==s.length()) break;
                string pomocni;

                while((s.at(j)>='0' && s.at(j)<='9') || (s.at(j)>='A' && s.at(j)<='Z') || (s.at(j)>='a' && s.at(j)<='z') ) {
                    if(s.at(j)>='A' && s.at(j)<='Z') s.at(j) += 'a'-'A';
                    pomocni.push_back(s.at(j));
                    j++;
                    duz++;
                    if(j==s.length()) break;
                }

                int pog(i+1), index(j-duz);
                auto ik(m.find(pomocni));
                if(m.size()==0 || ik==m.end() ) {
                    set<tuple<string, int, int>> skup;
                    skup.insert(std::make_tuple(it->first, pog, index));
                    m.insert(std::make_pair(pomocni,skup));
                } else ik->second.insert(std::make_tuple(it->first, pog, index));
                if(j==s.length()) break;

            }
        }

    }
    return m;
}

set<tuple<string, int, int>> PretraziIndeksPojmova(string s, map<string, set<tuple<string, int, int>>> m)
{
    auto it(m.find(s));
    if(it == m.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    return it->second;
}

void IspisiSkupBrojeva(set<tuple<string, int, int>> s)
{
    auto it(s.begin());
    for(int i = 0; i < s.size()-1 ; i++) {
        std::cout << std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it) <<", ";
        it++;
    }

    std::cout <<  std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)  ;

}

void IspisiIndeksPojmova (map<string, set<tuple<string, int, int>>> m)
{
    for(auto it = m.begin(); it != m.end(); it++) {
        cout<<it->first <<": ";
        IspisiSkupBrojeva(it->second);
        cout<<std::endl;
    }
}
int main ()
{
    Knjiga k;

    while(1) {
        string naziv;
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin, naziv);
        if(naziv==".") break;
        vector<string> v;

        int i=1;
        while(1) {
            string stranice;
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline(std::cin, stranice);
            if(stranice==".") break;
            v.push_back(stranice);

            i++;

        }
        k.insert(std::make_pair(naziv,v));
    }

    map<string, set<tuple<string, int, int>>> m;

    m=KreirajIndeksPojmova(k);
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(m);

    while(1) {
        string rijec;
        cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        else {
            try {
                set<tuple<string, int, int>> skup=PretraziIndeksPojmova(rijec,m);
                for(auto x : skup ) cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<" ";
                cout<<std::endl;
            } catch(std::logic_error a) {
                cout<<a.what()<<std::endl;
            }
        }

    }



    return 0;
}

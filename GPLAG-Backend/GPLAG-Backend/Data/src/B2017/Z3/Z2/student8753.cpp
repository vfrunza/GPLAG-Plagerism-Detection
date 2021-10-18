/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <set>
#include <vector>
#include <stdexcept>
using std::vector;
using std::set;
using std::string;
using std::tuple;
using std::map;
using std::cout;
using std::cin;
typedef map<string,vector<string>> Knjiga;
typedef map<string,set<tuple<string,int,int>>> Mapa;

void PretvoriUMala(vector<string> &vec)
{
    for(int i(0); i<vec.size(); i++) {
        for(int j(0); j<vec[i].length(); j++)
            if(vec[i][j]>='A' && vec[i][j]<='Z') vec[i][j]-='A'-'a';
    }
}

vector<vector<string>> Rastavi(vector<string> vec)
{
    vector<vector<string>> mat;
    vector<string> RastaviString(string s);
    for(int i(0); i<vec.size(); i++) {
        mat.push_back(RastaviString(vec[i]));
    }
    return mat;
}

vector<string> RastaviString(string s)
{
    vector<string> vec;
    for(int i(0); i<s.length(); i++) {
        if(!((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))) {
            string pom;
            for(int j(i); j<s.length() && (!((s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9'))); j++) {
                pom.push_back(s[j]);
                i++;
            }
            vec.push_back(pom);
            i--;
        } else {
            string pom;
            for(int j(i); j<s.length() && ((s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')); j++) {
                pom.push_back(s[j]);
                i++;
            }
            vec.push_back(pom);
            i--;
        }
    }
    return vec;
}

Mapa KreirajIndeksPojmova(Knjiga knjiga)
{
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++) PretvoriUMala(it->second);
    map<string,vector<vector<string>>> pomocna_knjiga;
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++)
        pomocna_knjiga[it->first]=Rastavi(it->second);
    set<string> rijeci;
    for(auto it(pomocna_knjiga.begin()); it!=pomocna_knjiga.end(); it++) {
        for(auto &y : it->second)
            for(auto &x : y)
                if((x[0]>='a' && x[0]<='z') || (x[0]>='0' && x[0]<='9')) rijeci.insert(x);
    }
    Mapa mapa;
    for(auto it(rijeci.begin()); it!=rijeci.end(); it++) {
        for(auto it1(pomocna_knjiga.begin()); it1!=pomocna_knjiga.end(); it1++) {
            for(int i(0); i<it1->second.size(); i++) {
                int brojac(0);
                for(int j(0); j<it1->second[i].size(); j++) {
                    if(it1->second[i][j]==*it) {
                        mapa[*it].insert(std::make_tuple(it1->first,i+1,brojac));
                    }
                    brojac+=it1->second[i][j].length();
                }
            }
        }
    }
    return mapa;
}

set<tuple<string,int,int>> PretraziIndeksPojmova(string s,Mapa &mapa)
{
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return it->second;
}

void IspisiIndeksPojmova(Mapa &mapa)
{
    for(auto it1(mapa.begin()); it1!=mapa.end(); it1++) {
        cout<<it1->first<<": ";
        for(auto it2(it1->second.begin()); it2!=it1->second.end(); it2++) {
            auto it3(it2);
            it3++;
            if(it3==it1->second.end())
                cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
            else cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2)<<", ";
        }
        cout<<std::endl;
    }
}

int main ()
{
    Knjiga knjiga;
    for(;;) {
        int i(1);
        string poglavlje;
        cout<<"Unesite naziv poglavlja: ";
        getline(cin,poglavlje);
        if(poglavlje==".") break;
        knjiga.insert({poglavlje,{}});
        for(;;) {
            string text;
            cout<<"Unesite sadrzaj stranice "<<i<<": ";
            getline(cin,text);
            if(text==".") break;
            knjiga[poglavlje].push_back(text);
            i++;
        }
    }
    Mapa mapa(KreirajIndeksPojmova(knjiga));
    cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(mapa);
    cout<<std::endl;
    for(;;) {
        string rijec;
        cout<<"Unesite rijec: ";
        getline(cin,rijec);
        if(rijec==".") break;
        try {
            set<tuple<string,int,int>> skup(PretraziIndeksPojmova(rijec,mapa));
            for(auto it(skup.begin()); it!=skup.end(); it++)
                cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
        } catch(std::logic_error izuzetak) {
            cout<<izuzetak.what();
        }
        cout<<std::endl;
    }

    return 0;
}

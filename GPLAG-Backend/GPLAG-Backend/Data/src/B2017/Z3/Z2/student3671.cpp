/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <cctype>
using namespace std;

typedef map<string,vector<string>>Knjiga;
typedef map<string,set<tuple<string,long,long>>>IndeksPojmova;

IndeksPojmova KreirajIndeksPojmova(Knjiga k)
{
    IndeksPojmova indeks;
    string rijec {""};
    int pozicija;
    for(auto const &strana : k)
        for(int i=0; i<strana.second.size(); i++)
            for(int j=0; j<strana.second[i].length(); j++) {
                if(isalpha(strana.second[i][j]) || isdigit(strana.second[i][j])) {
                    pozicija=j;
                    while(j!=strana.second[i].length() && (isalpha(strana.second[i][j]) || isdigit(strana.second[i][j]))) {
                        rijec+=strana.second[i][j++];
                    }
                } else continue;
                transform(rijec.begin(),rijec.end(),rijec.begin(),::tolower);
                int str_rij=i+1;

                indeks[rijec].insert(tie(strana.first,str_rij,pozicija));
                rijec="";
            }
    return indeks;
}

set<tuple<string,long,long>> PretraziIndeksPojmova(string rijec, IndeksPojmova pojmovi)
{
    IndeksPojmova::iterator it {pojmovi.find(rijec)};
    if(it==pojmovi.end()) {
        throw logic_error("Unesena rijec nije nadjena!");
    }
    return it->second;
}

void IspisiIndeksPojmova(IndeksPojmova pojmovi)
{
    for(auto const &pojam : pojmovi) {
        cout<<pojam.first<<":";
        unsigned long velicina=pojam.second.size() , i=0;
        for(const tuple<string,int,int> &t : pojam.second) {
            cout<<" "<<get<0>(t)<<"/"<<get<1>(t)<<"/"<<get<2>(t);
            if(++i==velicina) cout<<endl;
            else cout<<",";
        }
    }
}

int main ()
{
    string poglavlje,rijec;
    Knjiga k;
    for(;;) {
        cout<<"Unesite naziv poglavlja: ";
        getline(cin,poglavlje);
        if(poglavlje==".")
            break;
        for(int i=1;; i++) {
            cout<<"Unesite sadrzaj stranice "<<i<<": ";
            getline(cin,rijec);
            if(rijec==".")
                break;
            k[poglavlje].push_back(rijec);
        }
    }

    IndeksPojmova index=KreirajIndeksPojmova(k);

    cout<<"\nKreirani indeks pojmova:"<<endl;
    IspisiIndeksPojmova(index);
    
    typedef set<tuple<string,long,long>> Poz;
    Poz p;
    for(;;) {
        cout<<"Unesite rijec: ";
        getline(cin,rijec);
        if(rijec==".")
            break;
        transform(rijec.begin(),rijec.end(),rijec.begin(),::tolower);
        try {
            p=PretraziIndeksPojmova(rijec,index);
        } catch(logic_error e) {
            cout<<e.what()<<endl;
            continue;
        }
        for(const tuple<string,long,long> &t : p)
            cout<<get<0>(t)<<"/"<<get<1>(t)<<"/"<<get<2>(t)<<" ";
        cout<<endl;
    }
    return 0;
}
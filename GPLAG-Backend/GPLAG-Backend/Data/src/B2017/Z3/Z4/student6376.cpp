/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <utility>
#include <vector>
#include <stdexcept>
#include <map>

enum class Boje
{
    Pik,Tref,Herc,Karo
}boja;
 
typedef std::list<std::pair<Boje,std::string>> Lista;
typedef std::multimap<Boje,std::string> Multimapa;

Lista KreirajSpil ()
{
    Lista ret;
    std::pair<Boje,std::string> par;
    
    boja=Boje::Pik;
    std::vector<std::string> v {"2","3","4","5","6","7","8","9","10","J","K","Q","A"};
    for (int i(0);i<4;i++) {
        par.first=boja;
        for (int j=0;j<13;j++) {
            par.second=v[i];
            ret.push_back(par);
        }
        boja=Boje(int(boja)+1);
    }
     return ret;
}

void Izuzetak (Lista l) {
    
    if (l.size()>52) throw std::logic_error ("Neispravna lista");
    auto it2=l.begin();
    it2++;
    for (auto it (l.begin());it2!=l.end();it++) {
        if (it->first>it2->first || it->second>it2->second) throw std::logic_error ("Neispravna lista");
        it2++;
    }
    std::vector<std::string> v {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for (auto it(l.begin());it!=l.end();it++) {
    if (int(it->first)!=int(Boje::Pik) && int(it->first)!=int(Boje::Tref) && int(it->first)!=int(Boje::Herc) && int(it->first)!=int(Boje::Karo))  throw std::logic_error ("Neispravna lista");
    for (int i(0);i<12;i++) {
        if (it->second!=v.at(i)) throw std::logic_error ("Neispravna lista");
    }
    }
}

void IzbaciKarte (Lista l,Multimapa m) {
    
}
 





    int main () {
std::list<std::pair<Boje,std::string>> list;
for (int i(0);i<KreirajSpil().size();i++) {
    list.push_back(KreirajSpil());
    KreirajSpil()++;
}
for (auto x : list) std::cout<<x<<" ";
        return 0;
    }

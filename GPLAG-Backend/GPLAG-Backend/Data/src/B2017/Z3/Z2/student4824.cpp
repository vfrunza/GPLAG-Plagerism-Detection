/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
typedef std::map<std::string,std::vector<std::string>> Knjiga;

std::string PretvoriUMala(std::string s)
{
    std::string novi;
    for( int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') {
            novi.push_back(s[i]-('A'-'a'));
        } else {
            novi.push_back(s[i]);

        }
    }
    return novi;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>>KreirajIndeksPojmova(Knjiga neka_knjiga)
{
    std::multimap<std::string, std::tuple<std::string,int, int>> p_indeks_pojmova;
    std::set<std::string> rijeci;
    int prekid(1);
    std::string pomocna;
    for(auto it=neka_knjiga.begin(); it!=neka_knjiga.end(); it++) {
        std::vector<std::string> p(it->second);
        for( int i=0; i<p.size(); i++) {
            for( int j=0; j<p[i].size(); j++) {
                if(!(((p[i][j]>='a' && p[i][j]<='z') || (p[i][j]>='A' && p[i][j]<='Z') || (p[i][j]>='0' && p[i][j]<='9'))) && i<p.size()) {
                    prekid=1;
                } else if(prekid==1) {
                    prekid=0;
                    while(((p[i][j]>='a' && p[i][j]<='z') || (p[i][j]>='A' && p[i][j]<='Z') || (p[i][j]>='0' && p[i][j]<='9')) && j<p[i].size() && i<p.size()) {
                        pomocna.push_back(p[i][j]);
                        j++;
                    }
                    if(pomocna.length()>0) {
                        rijeci.insert(pomocna);
                        pomocna="";
                        j--;
                    }
                }

            }
            prekid=1;

        }
        p.resize(0);
    }

    std::string r_p="";
    int broj_razlicitih(std::distance(rijeci.begin(),rijeci.end()));
    std::vector<std::string>novi(broj_razlicitih);
    std::copy(rijeci.begin(),rijeci.end(),novi.begin());
    std::tuple<std::string, int, int> pomocni_t;
    for(auto it=neka_knjiga.begin(); it!=neka_knjiga.end(); it++) {
        std::vector<std::string>pom=(it->second);
        for( int i=0; i<pom.size(); i++) {
            int j(0);
            while(j<pom[i].size()) {
                while(((pom[i][j]>='a' && pom[i][j]<='z') || (pom[i][j]>='A' && pom[i][j]<='Z') || (pom[i][j]>='0' && pom[i][j]<='9')) && j<pom[i].size() && i<pom.size()) {
                    r_p.push_back(pom[i][j]);
                    j++;
                }
                if(r_p.length()>0) {
                    int k(0);
                    while(k<novi.size()) {
                        if(r_p==novi[k]) {
                            int pozicija=(j-novi[k].size());
                            int stranica=i+1;
                            std::string naziv_p(it->first);
                            pomocni_t=make_tuple(naziv_p, stranica, pozicija);
                            p_indeks_pojmova.insert(make_pair(novi[k], pomocni_t));
                            r_p="";
                            k=novi.size();
                        } else if(r_p!=novi[k]) {
                            k++;
                        }
                    }
                }
                j++;
                if(j>=pom[i].size()) {
                    j=pom[i].size();
                    }
                }
            }
            pom.resize(0);
        }
    
    std::set<std::tuple<std::string, int, int>> pomocni_s;
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova;
    for( auto it1=p_indeks_pojmova.begin(); it1!=p_indeks_pojmova.end(); it1++) {

        auto novi3=PretvoriUMala(it1->first);
        auto itp=it1;
        itp++;
        if (itp!=p_indeks_pojmova.end()) {
            auto it2=itp;
            while(it2!=p_indeks_pojmova.end() && it1!=p_indeks_pojmova.end()) {
                pomocni_s.insert(it1->second);
                std::string novi1=PretvoriUMala(it1->first);
                std::string novi2=PretvoriUMala(it2->first);
                if(novi1==novi2) {
                    pomocni_s.insert(it2->second);
                }
                it2++;
                if(it2==p_indeks_pojmova.end() && it1!=p_indeks_pojmova.end() ) {
                    indeks_pojmova.insert(std::make_pair(novi1, pomocni_s));
                    for(auto i:pomocni_s) {
                        pomocni_s.erase(i);
                    }

                }
            }

        } else {
            pomocni_s.insert(it1->second);
            indeks_pojmova.insert(std::make_pair(novi3, pomocni_s));


        }
    }



    return indeks_pojmova;

}
std::set<std::tuple<std::string, int , int>> PretraziIndeksPojmova( std::string rijec ,std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova)
{
    std::string s=".";
    std::set<std::tuple<std::string, int ,int>> pomoc;
    for( auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++) {
        if(rijec==it->first) {
            std::set<std::tuple<std::string, int, int>> pomoc(it->second);
            return pomoc;

        }
        it++;
        if(it==indeks_pojmova.end() && rijec!=s ) {
            throw std::logic_error("Unesena rijec nije nadjena!");
        }
        it--;

    }


}
void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> &indeks_pojmova)
{
    for( auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++) {
        std::cout<<it->first<<": ";
        auto p=it->second;
        for( auto it1=p.begin(); it1!=p.end(); it1++) {
            auto itp=it1;
            itp++;
            if(itp==p.end()) {
                std::cout<<std::get<0>(*it1)<<"/"<<std::get<1>(*it1)<<"/"<<std::get<2>(*it1);
            } else {
                std::cout<<std::get<0>(*it1)<<"/"<<std::get<1>(*it1)<<"/"<<std::get<2>(*it1)<<", ";

            }
        }
        std::cout<<std::endl;
    }



}
void IspisiSkup(std::set<std::tuple<std::string, int, int>> &skup)
{
    for( auto it=skup.begin(); it!= skup.end(); ++it) {
        std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
    }
    std::cout<<std::endl;

}
int main ()
{
    std::string naziv;
    std::string prekid1=".";
    std::string prekid2="\n";
    std::vector<std::string>sadrzaj;
    std::string element;
    Knjiga neka_knjiga;
    do {
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin, naziv);
        if(naziv==prekid1) break;
        int j(0);
        while(naziv!=prekid1) {
            std::cout<<"Unesite sadrzaj stranice "<<j+1<<": ";
            std::getline(std::cin, element);
            if(element==prekid1) break;
            sadrzaj.push_back(element);
            j++;
        }
        neka_knjiga.insert(make_pair(naziv,sadrzaj));
        sadrzaj.resize(0);
    } while(naziv!=prekid1);
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> rez(KreirajIndeksPojmova(neka_knjiga));
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(rez);
    std::string s;
    for(;;) {
        std::cout<<"Unesite rijec: ";
        try {
            std::getline(std::cin, s);
            if(s!=prekid1) {
                auto skup_p(PretraziIndeksPojmova(s, rez));
                IspisiSkup(skup_p);
            }
            else if(s==prekid1) break;
        } catch(std::logic_error e) {
            std::cout<<e.what()<<std::endl;
        }

    }
    return 0;
}

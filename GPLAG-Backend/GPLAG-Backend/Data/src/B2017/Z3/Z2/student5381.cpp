/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>

typedef std::map <std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;
void malo(char &a)
{
    if(a>='A' && a<='Z') a+='a'-'A';
}
std::string sva_mala(std::string &s)
{
    std::for_each(s.begin(), s.end(), malo);
   return s;
}
bool znak(char a)
{
    if ((a>='a' && a<='z')||(a>='A' && a<='Z') ||(a>=0 && a<=9)) return true;
    else return false;
}

IndeksPojmova KreirajIndeksPojmova(Knjiga knjiga)
{
    std::vector<std::string> spisak_rijeci;
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++) {
        auto vektor(it->second);
        for(int i(0); i<vektor.size(); i++) vektor[i]=sva_mala(vektor[i]);
        for(int i(0); i<vektor.size(); i++) {
            for(int j(0); j<vektor[i].length(); j++) {
                            std::string rijec;
                          //  if(vektor[i].length()==1) rijec.push_back(vektor[i][0]); 
                while(znak(vektor[i][j]) && j<vektor[i].length()) {
                    rijec.push_back(vektor[i][j]);
                    j++;
                }
                if (rijec.length()!=0) spisak_rijeci.push_back(rijec);
            }
        }
    }
    // for(int i=0;i<spisak_rijeci.size(); i++) spisak_rijeci[i]=sva_mala(spisak_rijeci[i]);
    std::sort(spisak_rijeci.begin(), spisak_rijeci.end());
    for(int i=0; i<spisak_rijeci.size(); i++) {
        for(int j=i+1; j<spisak_rijeci.size(); j++) if(spisak_rijeci[i]==spisak_rijeci[j]) {
                spisak_rijeci.erase(spisak_rijeci.begin()+j);
                j--;
            }
    }
    IndeksPojmova indeks;
    for(int i=0; i<spisak_rijeci.size(); i++) {
        std::pair<std::string, std::set<std::tuple<std::string, int, int>>> clan;
        clan.first=spisak_rijeci[i];
        for(auto it=knjiga.begin(); it!=knjiga.end(); it++) {
            auto vektor(it->second);
            auto poglavlje(it->first);
            for(int k(0); k<vektor.size(); k++) {
                int poz(0);
                for(int j=0; j<vektor[k].length(); j++) {
                    vektor[k]=sva_mala(vektor[k]);
                    poz=vektor[k].find(spisak_rijeci[i],j);
                    if(poz==std::string::npos) break;
                    auto q(vektor[k].begin()+poz+spisak_rijeci[i].length());
                    if((poz!=0 && znak(*(vektor[k].begin()+poz-1))) || (q!=vektor[k].end() && znak(*q))) continue;
                    std::tuple<std::string, int, int> trio;
                    trio=std::make_tuple(poglavlje,k+1,poz);
                    clan.second.insert(trio);
                }
            }
        }
        indeks.insert(clan);
    }
    return indeks;
}


std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, IndeksPojmova indeks)
{
    auto it(indeks.find(sva_mala(rijec)));
    if(it==indeks.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}
void IspisiTuple(std::tuple<std::string, int, int> t)
{
    std::cout << std::get<0>(t) <<"/" << std::get<1>(t) <<"/" << std::get<2>(t);
}
void IspisiIndeksPojmova(IndeksPojmova indeks)
{
    for(auto it(indeks.begin()); it!=indeks.end(); it++) {
        std::cout << it->first <<": ";
        auto poc(it->second.rend());
        poc--;
        for(auto p(poc); p!=it->second.rbegin(); p--) {
            IspisiTuple(*p);
            std::cout <<", ";
            poc--;
        }
        IspisiTuple(*poc);
        std::cout << std::endl;
    }
}
int main ()
{
    Knjiga knjiga;
    for(;;) {
        std::cout << "Unesite naziv poglavlja: ";
        std::string naziv_poglavlja;
        std::getline(std::cin, naziv_poglavlja);
        if(naziv_poglavlja==".") break;
        std::vector<std::string> stranice;
        int br(1);
        for(;;) {
            std::cout <<"Unesite sadrzaj stranice " << br << ": ";
            std::string strana;
            std::getline(std::cin, strana);
            if(strana==".") break;
            stranice.push_back(strana);
            br++;
        }
        knjiga.insert({naziv_poglavlja, stranice});
    }
    std::cout << std::endl;
    auto indeks(KreirajIndeksPojmova(knjiga));
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(indeks);
    for(;;) {
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try {
            auto skup(PretraziIndeksPojmova(rijec, indeks));
            auto predzadnji(skup.end());
            predzadnji--;
            for(auto p(skup.begin()); p!=skup.end(); p++) {
                IspisiTuple(*p);
                std::cout <<" ";
            }
        } catch(std::logic_error nema) {
            std::cout << nema.what() << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}

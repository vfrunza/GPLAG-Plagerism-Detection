/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string,int,int>>>  INDEKS_POJMOVA;

bool je_slovo(char a);
int n_ta_rijec(const std::string &tekst, int n);
std::string extract_word(const std::string &tekst, int n);
void mala_slova(std::string &a);


INDEKS_POJMOVA KreirajIndeksPojmova(Knjiga naruto);
std::set< std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec,  std::map<std::string, std::set<std::tuple<std::string,int,int>> > indeks);
void IspisiIndeksPojmova( INDEKS_POJMOVA indeks);

int main ()
{
    Knjiga naruto;
    std::vector<std::string> stranice;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string naziv_poglavlja {},temp_stranica {};
        std::cin>>naziv_poglavlja;
        if(naziv_poglavlja==".")break;
        stranice.resize(0);
        std::cin.ignore(1000,'\n');
        for(int i(1);; i++) {
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline(std::cin,temp_stranica);

            //dodavanje stranice u poglavlje
            stranice.push_back(temp_stranica);
            //end
            if(temp_stranica==".")break;
        }
        //dodavanje poglavlja u knjigu
        naruto[naziv_poglavlja]=stranice;
        //end
    }
    std::cout<<"\nKreirani indeks pojmova:";
    auto indeks(KreirajIndeksPojmova(naruto));
    IspisiIndeksPojmova(indeks);
    std::string test;
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::cin>>test;
        if(test==".")break;
        try {
         
            auto pozicije(PretraziIndeksPojmova(test,indeks));
            for(auto i=pozicije.begin(); i!=pozicije.end(); i++) {
                std::cout<<std::get<0>(*i)<<"/"<<std::get<1>(*i)<<"/"<<std::get<2>(*i)<<" ";
            }
        } catch(...) {
            std::cout<< "Unesena rijec nije nadjena!";
        }
        std::cout<<"\n";
    }



    return 0;
}

void IspisiIndeksPojmova( INDEKS_POJMOVA indeks)
{
    std::cout<<"\n";
    for(auto it = indeks.begin(); it != indeks.end(); it++) {
        std::cout<<it->first<<":";
        for(auto it2 = (it->second).begin(); it2 != (it->second).end(); it2++) {
            if(it2 == (it->second).begin()) {
                std::cout<<" ";
            } else {
                std::cout<<", ";
            }
            std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
        }
        std::cout<<std::endl;
    }
}

std::set< std::tuple<std::string,int,int> > PretraziIndeksPojmova(std::string rijec, INDEKS_POJMOVA indeks)
{
    std::set< std::tuple<std::string,int,int>> pozicije;
   
    
    if( indeks.count(rijec) ) {
    auto it( indeks.find(rijec));
    auto y = it->second;
        for(auto it2 = y.begin(); it2 != y.end(); it2++) {
            auto var(*it2);
            pozicije.insert(var);
        }
    } else {
        throw std::logic_error("Pojam nije nadjen");
    }
    return pozicije;
}

std::map<std::string, std::set<std::tuple<std::string,int,int>> > KreirajIndeksPojmova(Knjiga naruto)
{
    INDEKS_POJMOVA mapa;
    std::string stranica {},temp {};
    for(auto it = naruto.begin(); it != naruto.end(); it++) {
        //idem kroz poglavlja
        for(int j = 0; j < (it->second).size(); j++ ) {
            //idem kroz stranice
            mala_slova((it->second).at(j));
            stranica=(it->second).at(j);
            for(int i=1; n_ta_rijec(stranica,i)<stranica.length(); i++) {
                //nasao i-tu rijec na stranici
                temp = extract_word(stranica,n_ta_rijec(stranica,i));
                if( mapa.count(temp)) {
                    (mapa.find(temp))->second.insert(std::tuple<std::string,int,int>(it->first, j+1,n_ta_rijec(stranica,i)));
                } else {
                    std::set<std::tuple<std::string,int,int>> a;
                    a.insert(std::tuple<std::string,int,int>(it->first,j+1,n_ta_rijec(stranica,i)));
                    mapa.insert(std::pair<std::string,std::set<std::tuple<std::string,int,int>>>(temp,a) );
                }
            }
        }
    }
    return mapa;
}

bool je_slovo(char a)
{
    if( (a>='a' && a<='z') || (a>='A' && a<='Z') || ( a>='0' && a<='9'))return true;
    return false;
}

int n_ta_rijec(const std::string &tekst, int n)
{
    bool neslovo(true);
    int br_rijeci(0);
    for(int i=0; i<tekst.length(); i++) {
        if(!je_slovo(tekst[i])) {
            neslovo=true;
        } else {
            if(neslovo) {
                br_rijeci++;
                if(n==br_rijeci)return i;
            }
            neslovo=false;
        }
    }
    return tekst.length();
}

std::string extract_word(const std::string &tekst, int n)
{
    std::string rijec {};
    for(int i=n; i<tekst.length(); i++) {
        if(!je_slovo(tekst[i]))break;
        rijec+=tekst[i];
    }
    return rijec;
}

void mala_slova(std::string &a)
{
    for(int i=0; i<a.length(); i++) {
        if( a[i]>='A' && a[i]<='Z' )a[i]+='a'-'A';
    }
}




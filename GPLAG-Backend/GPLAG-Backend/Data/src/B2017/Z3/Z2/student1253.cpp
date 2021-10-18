/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map< std::string, std::set<std::tuple<std::string, int, int>> > indeks_pojmova;


bool DaLiJeSlovoiliCifra(char znak)
{
    return( (znak>='A' && znak<='Z') || (znak>='a' && znak<='z') || (znak>='0' && znak<='9') );
}
void PretvoriUMala(std::string &s)
{
    for(int i=0; i<int(s.length()); i++) {
        if(s.at(i)>='A' && s.at(i)<='Z') s.at(i) += 32;
    }
}

indeks_pojmova KreirajIndeksPojmova(Knjiga k)
{
    indeks_pojmova mapa;

    for(auto it = k.begin(); it != k.end(); it++) {
        for(int j=0; j<(it->second).size(); j++) { //(j+1) je broj stranice
            bool nije_rijec(1);
            int pocetak(0);

            for(int i=0; i<(it->second.at(j)).length(); i++) { //it->second.at(j) je cijeli sadrzaj stranice
                if( !DaLiJeSlovoiliCifra((it->second.at(j)).at(i)) ) nije_rijec = true;
                else if(nije_rijec) {
                    nije_rijec = false;
                    pocetak = i;
                    while( i<(it->second.at(j)).length() && DaLiJeSlovoiliCifra((it->second.at(j)).at(i)) ) i++; //dolazimo do kraja rijeci
                    std::tuple<std::string, int, int> t;
                    std::get<0>(t) = it->first; //poglavlje
                    std::get<1>(t) = j+1;       //stranica
                    std::get<2>(t) = pocetak;   //index od kojeg pocinje rijec
                    std::set<std::tuple<std::string, int, int>> skup;
                    skup.insert(t);

                    std::string s;
                    s = (it->second.at(j)).substr(pocetak, i-pocetak);
                    PretvoriUMala(s);
                    auto temp(mapa.find(s));
                    if(temp == mapa.end()) mapa.insert({s, skup});
                    else {
                        (temp->second).insert(t);
                    }

                    i--;  //jer smo sa petljom otisli iza kraja rijeci

                }

            }
        }
    }
    return mapa;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec,const indeks_pojmova &mapa)
{
    std::set<std::tuple<std::string, int, int>> skup;
    bool prazan(true);
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
        if(rijec == it->first) {
            for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++) skup.insert(*it2);
            prazan = false;
        }
    }
    if(prazan) throw std::logic_error("Unesena rijec nije nadjena!");
    return skup;
}

void IspisiIndeksPojmova(const indeks_pojmova &mapa)
{
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
        std::cout<<it->first<<": ";
        int i(1);
        for(auto x : it->second) {
            std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
            if(i<int(it->second.size())) std::cout<<", ";
            i++;
        }
        std::cout<<"\n";
    }
    
}


int main ()
{
    Knjiga k;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline(std::cin, poglavlje);
        if(poglavlje==std::string(".")) break;
        std::vector<std::string> v;
        k.insert({poglavlje, v});
        auto it(k.find(poglavlje));
        for(int i=0;; i++) {
            std::cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
            std::string temp;
            std::getline(std::cin, temp);
            if(temp==std::string(".")) break;
            it->second.push_back(temp);
        }
    }
    indeks_pojmova m;
    m = KreirajIndeksPojmova(k);
    std::cout<<"\nKreirani indeks pojmova:\n";
    IspisiIndeksPojmova(m);

    for(;;) {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==std::string(".")) break;
        std::set<std::tuple<std::string, int, int>> pozicija;
        try {
            pozicija = PretraziIndeksPojmova(rijec, m);
        } catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what();
        }
        for(auto x : pozicija) std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<" ";
        std::cout<<std::endl;
    }

    return 0;
}

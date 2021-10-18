/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <string>
#include <cctype>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;

bool SlovoIliBroj(char znak)
{
    return ((znak>='A' && znak<='Z') || (znak>='a' && znak<='z') || (znak>='0' && znak<='9'));
}

bool IsteRijeci(std::string s1, std::string s2) {
    auto it1(s1.begin()), it2(s2.begin());
    while(it1!=s1.end() && it2!=s2.end()) {
        char znak1(*it1), znak2(*it2);
        if(std::toupper(znak1)!=std::toupper(znak2)) return false;
        it1++; it2++;
    }
    if(it1!=s1.end() || it2!=s2.end()) return false;
    return true;
}

IndeksPojmova KreirajIndeksPojmova(Knjiga k)
{
    IndeksPojmova trazeni_ip;
    auto kroz_knjigu(k.begin()); //it na uredeni par
    while(kroz_knjigu!=k.end()) { //krecem se kroz mapu, knjigu
        //uzela sam jedan uredjeni par
        auto v(kroz_knjigu->second); //uzela sam vektor stringova
        for(int i=0; i<v.size(); i++) { //uzima se string po string
            auto s(v[i]); //jedna stranica iz vektora
            auto it(s.begin()); //krecem se kroz stranicu
            auto it1=s.begin();
            for(it1; it1!=s.end(); it1++) {
                if(SlovoIliBroj(*it1)) {
                    int pozicija(it1-it);
                    std::string pomocni;
                    auto it2(it1);
                    for(it2; it2!=s.end(); it2++) {
                        if(SlovoIliBroj(*it2)) pomocni.push_back(*it2);
                        else break;
                    }
                    it1=it2-1;
                    bool vec_postoji(false);
                    auto it3(trazeni_ip.begin());
                    for(it3; it3!=trazeni_ip.end(); it3++) {
                        if(IsteRijeci(pomocni, it3->first)) {
                            it3->second.insert(std::make_tuple(kroz_knjigu->first, i+1, pozicija));
                            vec_postoji=true;
                            break;
                        }
                    }
                    if(!vec_postoji)   {
                        for(int i=0; i<pomocni.length(); i++) pomocni[i]=std::tolower(pomocni[i]);
                        auto a=std::make_tuple(kroz_knjigu->first, i+1, pozicija);
                        std::set<std::tuple<std::string, int, int>> skup;
                        skup.insert(a);
                        auto p=std::make_pair(pomocni, skup);
                        trazeni_ip.insert(p);
                    }            }            }        }
        kroz_knjigu++;
    }
    return trazeni_ip;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, IndeksPojmova mapa) {
    std::vector<std::tuple<std::string, int, int>> v;
    if(!mapa.count(rijec)) 
        throw std::logic_error("Unesena rijec nije nadjena!");
    else return mapa.find(rijec)->second;
}

void IspisiIndeksPojmova(IndeksPojmova mapa)   
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        int brojac(0);
        for(auto t: it->second) {
            std::cout<<std::get<0>(t)<<"/"<<std::get<1>(t)<<"/"
                     <<std::get<2>(t);
            brojac++;
            if(brojac<it->second.size()) std::cout<<", ";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    Knjiga unesena_knjiga;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline(std::cin, poglavlje);
        if(poglavlje==".") break;
        int brojac(1);
        std::vector<std::string> stranica;
        for(;;) {
            std::cout<<"Unesite sadrzaj stranice "<<brojac<<": ";
            std::string cijela_stranica;
            std::getline(std::cin, cijela_stranica);
            if(cijela_stranica==".") break;
            stranica.push_back(cijela_stranica);
            brojac++;
        }
        if(stranica.size()==0) break;
        unesena_knjiga.insert(std::pair<std::string, std::vector<std::string>>(poglavlje, stranica));
    }
    IndeksPojmova trazeni_ip(KreirajIndeksPojmova(unesena_knjiga));
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(trazeni_ip);
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try {
            auto v(PretraziIndeksPojmova(rijec, trazeni_ip));
           
            for(auto element: v) {
                std::cout<<std::get<0>(element)<<"/"<<std::get<1>(element)
                    <<"/"<<std::get<2>(element)<<" ";
                
            }
            std::cout<<std::endl;

        } catch (std::logic_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        }
    }

    return 0;
}

/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string,int,int>>> IndeksPojmova;
typedef std::set<std::tuple<std::string,int,int>> SkupTrojki;
typedef std::vector<std::string> VektorStringova;

bool DaLiJeSlovoIliBroj(const char &znak)
{
    if((znak>='A' && znak<='Z') || (znak>='a' && znak<='z') || (znak>='0' && znak<='9')) {
        return true;
    }
    return false;
}

void PretvoriUMalaSlova(std::string &S)
{
    for(auto &znak: S) {
        if(znak>='A' && znak<='Z') {
            znak+='a'-'A';
        }
    }
}

IndeksPojmova KreirajIndeksPojmova (Knjiga &K)
{
    IndeksPojmova Indeks;
    auto it(K.begin());
    while(it!=K.end()) {

        int broj_stranica(it->second.size());

        for(int stranica(0) ; stranica<broj_stranica ; stranica++) {

            int duzina_recenice(it->second[stranica].size());
            std::string str(it->second[stranica]);
            PretvoriUMalaSlova(str);
            for(int pozicija(0); pozicija<duzina_recenice ; pozicija++) {

                char znak(str[pozicija]);
                if(DaLiJeSlovoIliBroj(znak)) {
                    int pocetna(pozicija);
                    while(DaLiJeSlovoIliBroj(znak) && pozicija<duzina_recenice) {
                        pozicija++;
                        znak=str[pozicija];

                    }
                    int krajnja(pozicija);
                    std::string rijec(str.substr(pocetna,krajnja-pocetna));
                    std::string poglavlje(it->first);
                    std::tuple<std::string,int,int> trojka (std::make_tuple(poglavlje,stranica+1,pocetna));
                    auto p(&Indeks[rijec]);
                    p->insert(trojka);
                }
            }
        }
        it++;
    }
    return Indeks;
}

SkupTrojki PretraziIndeksPojmova(const std::string &s,IndeksPojmova &mapa)
{
    std::string rijec(s);
    PretvoriUMalaSlova(rijec);
    if(!mapa.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    return mapa[rijec];
}

void IspisiIndeksPojmova(IndeksPojmova &I)
{
    std::cout << "\nKreirani indeks pojmova: " << std::endl;
    auto indeks_it(I.begin());
    while(indeks_it!=I.end()) {
        std::cout << indeks_it->first << ": ";
        auto p(indeks_it->second.begin());
        auto k(indeks_it->second.end());
        k--;
        while(p!=k) {
            std::cout << std::get<0>(*p) << "/" << std::get<1>(*p) << "/" << std::get<2>(*p) << ", ";
            p++;
        }
        std::cout << std::get<0>(*p) << "/" << std::get<1>(*p) << "/" << std::get<2>(*p) << std::endl;
        indeks_it++;
    }
}

void novired()
{
    std::cout << std::endl;
}

int main()
{
    std::string tacka(".");
    Knjiga K;
    for(;;) {
        std::cout << "Unesite naziv poglavlja: ";
        std::string ime_poglavlja;
        std::getline(std::cin,ime_poglavlja);
        if(ime_poglavlja==tacka) break;
        VektorStringova poglavlje;
        int stranica(1);
        for(;;) {
            std::cout << "Unesite sadrzaj stranice " << stranica << ": ";
            std::string tekst;
            std::getline(std::cin,tekst);
            if(tekst==tacka) break;
            auto it_knjiga(&K[ime_poglavlja]);
            it_knjiga->push_back(tekst);
            stranica++;
        }
    }
    //novired();
    IndeksPojmova I(KreirajIndeksPojmova(K));
    IspisiIndeksPojmova(I);
    
    for(;;) {
        novired();
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==tacka) break;
        try {
            auto skup(PretraziIndeksPojmova(rijec,I));
            auto skup_it(skup.begin());
            while(skup_it!=skup.end()) {
                std::cout << std::get<0>(*skup_it) << "/" << std::get<1>(*skup_it) << "/" << std::get<2>(*skup_it) << " ";
                skup_it++;
            }
        } catch(std::logic_error izuzetak) {
            std::cout << "Unesena rijec nije nadjena!";
            novired();
        }
    }


    return 0;
}


/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <set>
#include <iterator>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string,int,int>>> Indeks;
typedef std::set<std::tuple<std::string,int,int>> KarakteristikeRijeci;

struct RijecIPozicija {
    int pozicija;
    std::string word;
};

// Funkcija koja trazi poziciju i rijec u stranici
RijecIPozicija NadjiPoziciju (const std::string &stranica,int n_ta_rijec)
{
    int i(0),vrati,redni_broj_rijeci(0);
    while (i<stranica.size()) {
        vrati=i;
        bool nadjena_rijec(false);
        std::string rijec;
        while (i<stranica.size() && ((stranica.at(i)>='A' && stranica.at(i)<='Z') || (stranica.at(i)>='a' && stranica.at(i)<='z') ||
                                     (stranica.at(i)>='0' && stranica.at(i)<='9'))) {
                                         char slovo_na_stranici(stranica.at(i));
                                         if (stranica.at(i)>='A' && stranica.at(i)<='Z') slovo_na_stranici=slovo_na_stranici+32;
            rijec.push_back(slovo_na_stranici);
            nadjena_rijec=true;
            i++;
        }
        i++;
        if(nadjena_rijec) redni_broj_rijeci++;
        if (redni_broj_rijeci==n_ta_rijec) {
            return {vrati,rijec};
        }
    }
    return {-1,"nema te rijeci"};
}

Indeks KreirajIndeksPojmova (const Knjiga &knjiga)
{
    auto it_knjige(knjiga.begin()), it_knjige_2(knjiga.begin());
    Indeks indeks;
    while (it_knjige_2!=knjiga.end()) {
        int stranica(0);
        while (it_knjige_2->second.size()>stranica) {
            int n(1); // n-ta rijec na stranici "stranica" u nekom poglavlju
            RijecIPozicija n_ta_rijec (NadjiPoziciju(it_knjige_2->second.at(stranica),n));
            while (n_ta_rijec.pozicija!=-1) {
                KarakteristikeRijeci skup;
                //while petlja za trazenje rijeci kroz cijelu knjigu
                while (it_knjige!=knjiga.end()) {
                    int i(0); // i-ta stranica
                    //while petlja za stranice
                    while (it_knjige->second.size()>i) {
                        int j(1); // j-ta rijec i-te stranice
                        // while petlja za rijeci na stranici
                        RijecIPozicija neka_rijec(NadjiPoziciju(it_knjige->second.at(i),j));
                        while (neka_rijec.pozicija!=-1) {

                            if (neka_rijec.word==n_ta_rijec.word) {
                                std::string poglavlje(it_knjige->first);
                                int redni_broj_str(i+1);
                                int redni_broj_rijeci (neka_rijec.pozicija);
                                auto t(std::tie(poglavlje,redni_broj_str,redni_broj_rijeci));
                                skup.insert(t);
                            }
                            j++;
                            neka_rijec=NadjiPoziciju(it_knjige->second.at(i),j);
                        }
                        i++;
                    }
                    it_knjige++;
                }
                indeks.insert({n_ta_rijec.word,skup});
                it_knjige=knjiga.begin();
                n++;
                n_ta_rijec=NadjiPoziciju(it_knjige_2->second.at(stranica),n);
            }
            stranica++;
        }
        it_knjige_2++;
    }
    return indeks;
}

KarakteristikeRijeci PretraziIndeksPojmova (const std::string &rijec,const Indeks &indeks)
{
    auto it_indeksa (indeks.begin());
    KarakteristikeRijeci skup_pozicija;
    while (it_indeksa!=indeks.end()) {
        if (it_indeksa->first==rijec) {
            skup_pozicija=it_indeksa->second;
            break;
        }
        it_indeksa++;
    }
    if (skup_pozicija.size()==0) throw std::logic_error ("Unesena rijec nije nadjena!");
    return skup_pozicija;
}

void IspisiIndeksPojmova (const Indeks &indeks)
{
    for (auto x : indeks) {
        std::cout<<x.first<<": ";
        int brojac(0);
        for (auto t : x.second) {
            std::cout<<std::get<0>(t)<<"/"<<std::get<1>(t)<<"/"<<std::get<2>(t);
            brojac++;
            if (brojac==x.second.size()) continue;
            std::cout<<", ";
        }
        std::cout<<std::endl;
    }
}

void UnosKnjige ()
{
    Knjiga knjiga;
    while(1) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline (std::cin, poglavlje);
        if (poglavlje==".") break;
        std::vector<std::string> stranice;
        int i(0);
        while (1) {
            std::cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
            std::string sadrzaj_stranice;
            std::getline (std::cin, sadrzaj_stranice);
            if (sadrzaj_stranice==".") break;
            stranice.push_back(sadrzaj_stranice);
            i++;
        }
        knjiga.insert({poglavlje,stranice});
    }
    std::cout<<"\nKreirani indeks pojmova: \n";
    Indeks indeks(KreirajIndeksPojmova(knjiga));
    IspisiIndeksPojmova(indeks);
    while (1) {
        std::cout<<"Unesite rijec: ";
        std::string trazena_rijec;
        std::getline(std::cin, trazena_rijec);
        if (trazena_rijec==".") break;
        try{
        KarakteristikeRijeci osobine(PretraziIndeksPojmova(trazena_rijec,indeks));
        for (auto x : osobine) {
            std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<" ";
        }}
        catch (std::logic_error izuzetak){
            std::cout<<izuzetak.what();
        }
        std::cout<<std::endl;
    }

}

int main ()
{
    try {
        UnosKnjige();
    } catch (std::logic_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    return 0;
}

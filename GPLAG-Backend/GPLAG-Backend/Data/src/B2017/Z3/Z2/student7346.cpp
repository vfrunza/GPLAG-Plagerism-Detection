/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::get;

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;
typedef std::multimap<std::string, int> RijeciJedneStranice;
typedef std::set<std::tuple<std::string, int, int>> Lokacije;
std::vector<std::string> UnosPoglavlja () {
    std::vector<std::string> str;
    int brojac(1);
    for(;;) {
        cout << "Unesite sadrzaj stranice " << brojac << ": ";
        std::string recenica;
        std::getline(cin, recenica);
        if(recenica == ".") break;
        str.push_back(recenica);
        brojac++;
    }
    return str;
}


bool Slovo (char znak)
{
    if ((znak >= 'A' && znak <= 'Z') || (znak >= 'a' &&  znak <= 'z') || (znak >= '0' && znak <= '9'))
        return true;
    return false;
}

RijeciJedneStranice KreirajSpisakRijeciJedneStranice (std::string stranica) {
    std::transform(stranica.begin(), stranica.end(), stranica.begin(), ::tolower);
    RijeciJedneStranice Rijeci;
    for (int i(0); i<stranica.size(); i++) {
        while (i<stranica.size() && !Slovo(stranica[i])) i++;
        int pozicija(i); 
        std::string rijec;
        while (i<stranica.size() && Slovo(stranica[i])) {
            rijec += stranica[i];
            i++;
        }
        if(rijec.length())
            Rijeci.insert({rijec, pozicija});
    }
    return Rijeci;
}

IndeksPojmova KreirajIndeksPojmova (Knjiga book)
{
    IndeksPojmova povratni;
    for(auto poglavlje : book) {
        for (int i(0); i<poglavlje.second.size(); i++) {
            auto RijeciTrenutneStranice = KreirajSpisakRijeciJedneStranice(poglavlje.second[i]);
            for (auto rijec : RijeciTrenutneStranice) {
                if(!povratni.count(rijec.first)) {
                    int stranica(i+1);
                    std::set<std::tuple<std::string, int, int>> parametri;
                    parametri.insert(std::tie(poglavlje.first, stranica, rijec.second));
                    povratni.insert({rijec.first, parametri});
                }
                
                else {
                    auto mjesto(povratni.find(rijec.first));
                    int stranica(i+1);
                    mjesto->second.insert(std::tie(poglavlje.first, stranica, rijec.second));
                }
            }
        }
    }
    return povratni;
}


Lokacije PretraziIndeksPojmova(std::string &trazena_rijec, IndeksPojmova pojmovi) {
    std::transform(trazena_rijec.begin(), trazena_rijec.end(), trazena_rijec.begin(), ::tolower);
    if(!pojmovi.count(trazena_rijec))
        throw std::logic_error("Pojam nije nadjen");
    auto mjesto(pojmovi.find(trazena_rijec));
    return mjesto->second;
}


void IspisiIndeksPojmova (IndeksPojmova indeks_pojmova) {
    for (auto pojam : indeks_pojmova) {
        cout << pojam.first << ": ";
        int cntr(0);
        auto info = pojam.second;
        for (auto lokacije : info) {
            cout << std::get<0>(lokacije) << "/" << std::get<1>(lokacije) << "/" << std::get<2>(lokacije);
            if(cntr<info.size()-1)
                cout << ", ";
            cntr++;
        }
        cout << endl;
    }
}



int main ()
{
    Knjiga book;
    for (;;) {
        cout << "Unesite naziv poglavlja: ";
        std::string naziv_poglavlja;
        std::getline(cin, naziv_poglavlja);
        if (naziv_poglavlja == ".") break;
        std::vector<std::string> Poglavlje = UnosPoglavlja();
        book.insert({naziv_poglavlja, Poglavlje});
    }
    
    IndeksPojmova rez = KreirajIndeksPojmova(book);
    cout << endl << "Kreirani indeks pojmova:" << endl;
    IspisiIndeksPojmova(rez);
    
    for(;;) {
        cout << "Unesite rijec: ";
        std::string trazena_rijec;
        std::getline(cin, trazena_rijec);
        if(trazena_rijec == ".") break;
        std::transform(trazena_rijec.begin(), trazena_rijec.end(), trazena_rijec.begin(), ::tolower);
        if(!rez.count(trazena_rijec)) cout << "Unesena rijec nije nadjena!" << endl;
        else {
            try {
                auto lokacije = PretraziIndeksPojmova(trazena_rijec, rez);
                for(auto lokacija : lokacije)
                    cout << get<0>(lokacija) << "/" << get<1>(lokacija) << "/" << get<2>(lokacija) << " ";
                cout << endl;
            }
            catch (std::exception izuzetak) {
                cout << izuzetak.what();
            }
        }
    }
    return 0;
}

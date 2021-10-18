/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};
typedef std::list<std::pair<Boje, std::string>> Karta;

Karta KreirajSpil()
{

    Karta karte;
    for(int i(0); i<4; ++i) {
        for(int j(2); j<15; ++j) {

            std::string broj;
            if(j == 11) broj = "J";
            else if(j == 12) broj = "Q";
            else if(j == 13) broj = "K";
            else if(j == 14) broj = "A";
            else broj = std::to_string(j);

            std::pair<Boje, std::string> par;

            if(i == 0) par = std::make_pair(Boje::Pik, broj);
            else if(i == 1) par = std::make_pair(Boje::Tref, broj);
            else if(i == 2) par = std::make_pair(Boje::Herc, broj);
            else if(i == 3) par = std::make_pair(Boje::Karo, broj);

            karte.push_back(par);
        }
    }

    return karte;
}

void IzbaciKarte(Karta &karte, std::multimap<Boje, std::string> &m)
{

    //Provjera broja karata u spilu
    int brojac(0);
    for(auto it = karte.begin(); it != karte.end(); ++it) ++brojac;
    if(brojac > 52) throw std::logic_error("Neispravna lista!");

    //Provjera Sortiranja
    for(auto it = karte.begin(); it != karte.end(); ++it) {

        int broj;
        if(it->second == "J") broj = 11;
        else if(it->second == "Q") broj = 12;
        else if(it->second == "K") broj = 13;
        else if(it->second == "A") broj = 14;
        else broj = std::stoi(it->second);

        if(broj < 2 || broj > 14) throw std::logic_error("Neispravna lista!");
    }

    //Brisanje elemenata
    for(auto it_liste = karte.begin(); it_liste != karte.end(); ++it_liste) {
        for(auto it_mape = m.begin(); it_mape != m.end(); ++it_mape) {

            if( (it_liste->first == it_mape->first) && (it_liste->second == it_mape->second) ) {

                karte.erase(it_liste);
                m.erase(it_mape);

            }
        }
    }

    return;
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Karta &karte, const short int &r, const int &b)
{
        //Ispitivanje drugog i treceg parametra funkcije
        if(r < 1 || r > 52) throw std::logic_error("Neispravni elementi za izbacivanje!");
        if(b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");

        //Provjera broja karata u spilu
        int brojac_karti(0);
        for(auto it = karte.begin(); it != karte.end(); ++it) ++brojac_karti;
        if(brojac_karti > 52) throw std::logic_error("Neispravna lista!");

        //Provjera Sortiranja
        for(auto it = karte.begin(); it != karte.end(); ++it) {

            int broj;
            if(it->second == "J") broj = 11;
            else if(it->second == "Q") broj = 12;
            else if(it->second == "K") broj = 13;
            else if(it->second == "A") broj = 14;
            else broj = std::stoi(it->second);

            if(broj < 2 || broj > 14) throw std::logic_error("Neispravna lista!");
        }
    
    //Izbacivanje i smijestanje u red-------------------------------------------------------------------------------------------------------------------------
    std::queue<std::pair<std::string, std::string>> red;
    std::string boja, broj;
    int brojac(1), izbacenih(0);
    auto it = karte.begin();
    auto it_kraj = karte.end();
    --it_kraj;
    while(izbacenih != b) {

        if(it == karte.end()) {
            it = karte.begin();
        }

        if(brojac != r) {
            ++brojac;
            ++it;
            continue;
        } else if(brojac == r) {

            if(static_cast<int>(it->first) == 0) boja = "Pik";
            else if(static_cast<int>(it->first) == 1) boja = "Tref";
            else if(static_cast<int>(it->first) == 2) boja = "Herc";
            else if(static_cast<int>(it->first) == 3) boja = "Karo";
            broj = it->second;

            std::pair<std::string, std::string> par {boja, broj};
            red.push(par);

            karte.erase(it);
            brojac = 1;
            ++izbacenih;
            if(izbacenih == b) break;
        }
        if(it == karte.end()) continue;
        ++it;
    }

    return red;
}

void VratiPrvihNKarata(Karta &karte, std::queue<std::pair<std::string, std::string>> &izbacene_karte, int n)
{
    if(izbacene_karte.size() < n) throw std::range_error("Nedovoljno karata u redu!");
    if(n <= 0) throw std::domain_error("Broj n je besmislen");

    int izbacenih(izbacene_karte.size());
    int koliko_puta(izbacenih - n);

    for(int i(0); i<koliko_puta; ++i) izbacene_karte.pop();

    for(;;) {
        std::pair<std::string, std::string> par_u_redu = izbacene_karte.front();
        Boje boja;
        if(par_u_redu.first == "Pik") boja = Boje::Pik;
        else if(par_u_redu.first == "Tref") boja = Boje::Tref;
        else if(par_u_redu.first == "Herc") boja = Boje::Herc;
        else if(par_u_redu.first == "Karo") boja = Boje::Karo;

        std::pair<Boje, std::string> par_za_ubacit;
        par_za_ubacit = std::make_pair(boja, par_u_redu.second);
        karte.push_back(par_za_ubacit);
        izbacene_karte.pop();
        if(izbacene_karte.empty()) break;
    }
}

void IspisKarti(const Karta &karte)
{
    int Boja_Karte(0);
    bool ispisano(false);
    for(auto it = karte.begin(); it != karte.end(); ++it) {

        if(Boja_Karte == 0) {
            if(!ispisano) std::cout<<"Pik: ";
            ispisano = true;
            if(static_cast<int>(it->first) == 0) std::cout<<it->second<<" ";

            auto it_temp = it;
            ++it_temp;
            if(it_temp == karte.end()) return;
            else {
                if(it_temp->first != it->first) {
                    ++Boja_Karte;
                    std::cout<<std::endl;
                    ispisano = false;
                    it = karte.begin();
                    continue;
                }
            }
        } else if(Boja_Karte == 1) {
            if(!ispisano) std::cout<<"Tref: ";
            ispisano = true;
            if(static_cast<int>(it->first) == 0) std::cout<<it->second<<" ";
            auto it_temp = it;
            ++it_temp;
            if(it_temp == karte.end()) return;
            else {
                if(it_temp->first != it->first) {
                    ++Boja_Karte;
                    std::cout<<std::endl;
                    ispisano = false;
                    it = karte.begin();
                    continue;
                }
            }

        } else if(Boja_Karte == 2) {
            if(!ispisano) std::cout<<"Herc: ";
            ispisano = true;
            if(static_cast<int>(it->first) == 0) std::cout<<it->second<<" ";
            auto it_temp = it;
            ++it_temp;
            if(it_temp == karte.end()) return;
            else {
                if(it_temp->first != it->first) {
                    ++Boja_Karte;
                    std::cout<<std::endl;
                    ispisano = false;
                    it = karte.begin();
                    continue;
                }
            }
        } else if(Boja_Karte == 3) {
            if(!ispisano) std::cout<<"Karo: ";
            ispisano = true;
            if(static_cast<int>(it->first) == 0) std::cout<<it->second<<" ";
            auto it_temp = it;
            ++it_temp;
            if(it_temp == karte.end()) return;
            else {
                if(it_temp->first != it->first) {
                    ++Boja_Karte;
                    std::cout<<std::endl;
                    ispisano = false;
                    it = karte.begin();
                    continue;
                }
            }
        }
    }
}

int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    int korak_razbrajanja;
    std::cin>>korak_razbrajanja;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int koliko_za_izbaciti;
    std::cin>>koliko_za_izbaciti;
    Karta k(KreirajSpil());
    try {
        std::queue<std::pair<std::string, std::string>> red = IzbaciKarteRazbrajanjem(k, korak_razbrajanja, koliko_za_izbaciti);
    } catch(std::logic_error le) {
        std::cout<<"Izuzetak: "<<le.what();
        return 0;
    } catch(...) {
        std::cout<<"Neocekivani Izuzetak";
        return 0;
    }

    int broj_karata(0);
    for(auto it = k.begin(); it != k.end(); ++it) ++broj_karata;
    std::cout<<"U spilu trenutno ima "<<broj_karata<<" karata, i to:"<<std::endl;
    IspisKarti(k);
    return 0;
}
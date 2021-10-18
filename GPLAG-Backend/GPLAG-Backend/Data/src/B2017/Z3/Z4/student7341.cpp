/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <stdexcept>
#include <algorithm>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

typedef std::list<std::pair<Boje, std::string>> SpilKarata;

SpilKarata KreirajSpil ()
{
    SpilKarata spil;
    std::vector<std::string> nazivi_karata {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int index(0);
    for (int i(0); i<4; i++) {
        while (index<13) {
            std::pair<Boje, std::string> it;
            std::string number;
            number=nazivi_karata[index];
            if (i==0) it = std::make_pair (Boje::Pik, number);
            else if (i==1) it = std::make_pair (Boje::Tref, number);
            else if (i==2) it = std::make_pair (Boje::Herc, number);
            else if (i==3) it = std::make_pair (Boje::Karo, number);
            spil.push_back(it);
            index++;
        }
        index=0;
    }
    return spil;
}

void IzbaciKarte (SpilKarata &spil, std::multimap<Boje, std::string> &za_izbaciti)
{
    
    auto it = spil.begin();
    int broj_karata(0);
    
   for (;;) {
        it++;
        broj_karata++;
        if (it==spil.end()) break;
    }
    if (broj_karata>52) throw std::logic_error("Neispravna lista!");
    //Provjera sortiranja
    auto rijec = spil.begin();//pomocna samo da mi oznaci pocetak
    rijec++;
    auto prethodni_pok = spil.begin();
    for (auto pok = rijec; pok != spil.end(); pok++) {
        int broj;
        int prethodni;
        //std::string temp=it->second;
        if (pok->second == "J") broj=11;
        else if (pok->second == "Q") broj=12;
        else if (pok->second == "K") broj=13;
        else if (pok->second == "A") broj=14;
        else broj = std::stoi (pok->second);
        std::string prethodni_temp = prethodni_pok->second;
        if (prethodni_pok->second == "J") prethodni=11;
        else if (prethodni_pok->second == "Q") prethodni=12;
        else if (prethodni_pok->second == "K") prethodni=13;
        else if (prethodni_pok->second == "A") prethodni=14;
        else prethodni = std::stoi (prethodni_pok->second);

        if (broj < 2 || broj > 14) throw;
        if (prethodni>broj && ((pok->first)==(prethodni_pok->first))) throw std::logic_error ("Neispravna lista!");

        //Izbacivanje
        for (auto it_spil = spil.begin(); it_spil !=spil.end(); it_spil++) {
            for (auto it_map = za_izbaciti.begin(); it_map != za_izbaciti.end(); it_map++) {
                if ((it_spil->first == it_map->first) && (it_spil->second==it_map->second)) {
                   
                    it_spil = spil.erase(it_spil);
                    za_izbaciti.erase(it_map);
                }
            }
        }

        prethodni_pok++;

    }


}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (SpilKarata &spil, const short int &r, const int &b )
{
    
    if (r<1 || r>52) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if (b<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if (b>52) {
        //for (auto it_spil=spil.begin(); it_spil!=spil.end(); it_spil++)
        spil.erase(spil.begin(), spil.end());
        std::queue<std::pair<std::string, std::string>> red{};
       return red;
    }
    std::queue<std::pair<std::string, std::string>> red;
    {
        auto it_spil = spil.begin();
        int broj_karata(0);
        for (;;) {
            if (it_spil==spil.end()) break;
            it_spil++;
            broj_karata++;
        }
        if (broj_karata>52) throw std::logic_error ("Neispravna lista!");
        auto rijec = spil.begin();
        rijec++;
        auto prethodni_it = spil.begin();
        for (auto it=rijec; it != spil.end(); it++) {
            int broj;
            int prethodni;
            if (it->second == "J") broj=11;
            else if (it->second == "Q") broj=12;
            else if (it->second == "K") broj=13;
            else if (it->second == "A") broj=14;
            else broj = std::stoi (it->second);

            if (prethodni_it->second == "J") prethodni=11;
            else if (prethodni_it->second == "Q") prethodni=12;
            else if (prethodni_it->second == "K") prethodni=13;
            else if (prethodni_it->second == "A") prethodni=14;
            else prethodni = std::stoi (prethodni_it->second);
            prethodni_it++;
            if (it->second<"2" && it->second>"10" && it->second!="K" && it->second!="Q" && it->second!="J" && it->second!="A") throw std::logic_error ("Neispravna lista!");
            if (prethodni<broj && ((it->first)!=(prethodni_it->first))) throw std::logic_error ("Neispravna lista!");
        }
    }

    std::string boja, broj;
    int broj_karata_za_izbaciti(0);
    auto it_spil = spil.begin();
    while (broj_karata_za_izbaciti!=b) {
        int brojac(1);
        if (it_spil==spil.end() ) it_spil=spil.begin();
        while (brojac!=r) {
            it_spil++;
            if(it_spil==spil.end()) it_spil=spil.begin();
            brojac++;
        }
        if (int(it_spil->first)==0) boja="Pik";
        else if (int(it_spil->first)==1) boja="Tref";
        else if (int(it_spil->first)==2) boja="Herc";
        else if (int(it_spil->first)==3) boja="Karo";
        broj = it_spil->second;
        red.push(std::make_pair (boja, broj));
        it_spil=spil.erase(it_spil);
        broj_karata_za_izbaciti++;
        if(broj_karata_za_izbaciti==b) break;
    
    }
    return red;
}

void IspisSpil(const SpilKarata &spil);

void VratiPrvihNKarata (SpilKarata &spil, std::queue<std::pair<std::string,std::string>> &red, int n)
{
    if (n<0) throw std::domain_error ("Broj n je besmislen!");
    if (n>red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    auto it_spil = spil.begin();
    int broj_karata_koje_smo_vratili(0);
    while (broj_karata_koje_smo_vratili<n) {
        Boje znak;
        if (red.front().first=="Pik") znak=Boje::Pik;
        else if (red.front().first=="Tref") znak=Boje::Tref;
        else if (red.front().first=="Herc") znak=Boje::Herc;
        else if (red.front().first=="Karo") znak=Boje::Karo;
        std::pair<Boje, std::string> treba_dodati (znak, red.front().second);


        for (auto it_spil=spil.begin(); it_spil!=spil.end(); it_spil++) {
            if (treba_dodati.first == it_spil->first) {
                spil.insert(it_spil, treba_dodati);
                break;
            }
        }

        red.pop();
        broj_karata_koje_smo_vratili++;
        it_spil=spil.begin();
    }


    int broj_prolaza(0);
    while (broj_prolaza<=5) {
        auto sljedeci = spil.begin();
        for (auto it_spil=spil.begin(); it_spil!=spil.end(); it_spil++)  {
            sljedeci++;
            if (it_spil->first == sljedeci->first) {
                int broj;
                if (it_spil->second == "J") broj = 11;
                else if (it_spil->second == "Q") broj = 12;
                else if (it_spil->second == "K") broj = 13;
                else if (it_spil->second == "A") broj = 14;
                else broj = std::stoi(it_spil->second);

                int sljedbenik;
                if (sljedeci->second =="J") sljedbenik = 11;
                else if (sljedeci->second == "Q") sljedbenik = 12;
                else if (sljedeci->second == "K") sljedbenik = 13;
                else if (sljedeci->second == "A") sljedbenik = 14;
                else sljedbenik = std::stoi(sljedeci->second);

                if(broj>sljedbenik) {
                    swap(*it_spil,*sljedeci);
                    it_spil--;
                    sljedeci--;
                }

            }
        }
        broj_prolaza++;
    }
}

void IspisSpil (const SpilKarata &spil)
{
    int boja(0);
    auto pocetak = spil.begin();
    auto kraj = spil.end();
    kraj--;
    bool ispisano_imeP(false);
    bool ispisano_imeH(false);
    bool ispisano_imeT(false);
    bool ispisano_imeK(false);
    for (auto it=pocetak; it!=kraj; it++) {
        if (boja==0) {
            if (!ispisano_imeP) {
                std::cout << "Pik: ";
                ispisano_imeP=true;
            }
            auto sljedeci=it;
            sljedeci++;
            if (it->first != sljedeci->first) {
                boja++;
                std::cout << it->second << " "<< std::endl;
                continue;
            } else {
                std::cout << it->second << " ";
            }
        }

        if (boja==1) {
            if(!ispisano_imeT) {
                std::cout<< "Tref: ";
                ispisano_imeT=true;
            }

            auto sljedeci=it;
            sljedeci++;
            if(it->first != sljedeci->first) {
                boja++;
                std::cout << it->second << " " << std::endl;
                continue;
            } else std::cout << it->second << " ";
        }

        if (boja==2) {
            if(!ispisano_imeH) {
                std::cout<<"Herc: ";
                ispisano_imeH=true;
            }
            auto sljedeci=it;
            sljedeci++;
            if(it->first != sljedeci-> first) {
                boja++;
                std::cout << it->second << " " << std::endl;
                continue;
            } else std::cout << it->second << " ";
        }

        if (boja==3) {
            if (!ispisano_imeK) {
                std::cout<<"Karo: ";
                ispisano_imeK=true;
            }

            auto sljedeci = it;
            sljedeci++;
            if (it->first != sljedeci-> first) {
                boja++;
                std::cout << it->second << " " << std::endl;
                continue;
            }

            else std::cout << it->second << " ";
        }

    }
    std::cout << kraj->second << " " << std::endl;
}

int main ()
{
    std::cout<<"Unesite korak razbrajanja: ";
    int korak;
    std::cin >> korak;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int za_izbaciti;
    std::cin >> za_izbaciti;
    SpilKarata spil(KreirajSpil());
    std::multimap<Boje,std::string> multimapa;
    //multimapa.insert({Boje::Herc,"Q"});
    //multimapa.insert({Boje::Karo,"3"});
    IzbaciKarte(spil,multimapa);
    std::queue<std::pair<std::string, std::string>> red;
    try {
        // std::cout << "ude ovdje" << std::endl;
        red = IzbaciKarteRazbrajanjem(spil, korak, za_izbaciti);
        if (red.size()==0) return 0;
    }

    catch (std::logic_error greska) {
        std::cout <<"Izuzetak: " << greska.what();
        return 0;
    }

    catch (...) {
        std::cout<<"Neocekivani izuzetak!";
        return 0;
    }
    int broj_karata(0);
    for (auto it=spil.begin(); it!=spil.end(); it++) broj_karata++;
    std::cout<<"U spilu trenutno ima "<<broj_karata<<" karata, i to:"<<std::endl;
    IspisSpil(spil);
    try {
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int za_vratiti;
        std::cin >> za_vratiti;
        VratiPrvihNKarata(spil, red, za_vratiti);
        auto ima=broj_karata+za_vratiti;
        std::cout << "U spilu trenutno ima " << ima << " karata, i to:" << std::endl;
        IspisSpil(spil);
    }

    catch (std::range_error greska) {
        std::cout << "Izuzetak: " <<greska.what();
        return 0;
    }

    catch (std::domain_error greska) {
        std::cout << "Izuzetak: " << greska.what();
        return 0;
    }
    return 0;
}

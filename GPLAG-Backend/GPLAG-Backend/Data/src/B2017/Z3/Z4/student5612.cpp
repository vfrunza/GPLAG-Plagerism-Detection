#include <list>
#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <string>
#include <stdexcept>
#include <algorithm>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

bool DaLiJeSortiranaKakoTreba(std::list<std::pair<Boje, std::string>> &Spil)
{

    std::string vrijednosti_karata[] {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    std::list<std::pair<Boje, std::string>>::iterator it3(Spil.begin());
    std::list<std::pair<Boje, std::string>>::iterator it4(Spil.begin());

    while(it3 != Spil.end()) {
        it4 = it3;
        while(it4 != Spil.end()) {
            if(it4->first < it3->first) {
                return false;
                break;
            }
            it4++;
        }
        it3++;
    }
    std::list<std::pair<Boje, std::string>>::iterator it5(Spil.begin());
    std::list<std::pair<Boje, std::string>>::iterator it6(Spil.begin());
    while(it5 != Spil.end()) {
        int index1(0), index2(0);
        it6 = it5;
        while(it6 != Spil.end()) {
            for(int i = 0; i < 13; i++) {
                if(it6->second == vrijednosti_karata[i]) {
                    index1 = i;
                    break;
                }
            }
            for(int i = 0; i < 13; i++) {
                if(it5->second == vrijednosti_karata[i]) {
                    index2 = i;
                    break;
                }
            }
            if(index2 > index1 && it5->first == it6->first) {
                return false;
                break;
            }
            it6++;
        }
        it5++;
    }
    return true;
}

std::list<std::pair<Boje,std::string>> KreirajSpil ()
{
    std::list<std::pair<Boje,std::string>> SpilKarata;

    std::string vrijednosti_karata[] {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

    for(int i = 0; i < 13; i++) {
        SpilKarata.push_back(std::make_pair(Boje::Pik, vrijednosti_karata[i]));
    }
    for(int i = 0; i < 13; i++) {
        SpilKarata.push_back(std::make_pair(Boje::Tref,vrijednosti_karata[i]));
    }
    for(int i = 0; i < 13; i++) {
        SpilKarata.push_back(std::make_pair(Boje::Herc,vrijednosti_karata[i]));
    }
    for(int i = 0; i < 13; i++) {
        SpilKarata.push_back(std::make_pair(Boje::Karo,vrijednosti_karata[i]));
    }

    return SpilKarata;
}

void IzbaciKarte (std::list<std::pair<Boje,std::string>> &Spil, std::multimap<Boje, std::string> &MultiMapa)
{
    std::string vrijednosti_karata[] {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

    //Provjera da li lista ima vise od 52 elementa
    if(Spil.size() > 52) throw std::logic_error("Neispravna lista!");

    //Provjera da li su elementi sortirani i bacanje izuzetka(ukoliko nisu)
    if(DaLiJeSortiranaKakoTreba(Spil) == false) throw std::logic_error("Neispravna lista!");


    //Provjera da li lista sadrzi besmislene podatke
    auto pomocni_it(Spil.begin());
    while(pomocni_it != Spil.end()) {
        int i(0);
        while(i < 13) {
            if(pomocni_it->second == vrijednosti_karata[i]) break;
            i++;
        }
        if(i == 13) throw std::logic_error("Neispravna lista!");
        pomocni_it++;
    }
    pomocni_it = Spil.begin();
    while(pomocni_it != Spil.end()) {
        if(pomocni_it->first != Boje::Pik && pomocni_it->first != Boje::Tref &&
                pomocni_it->first != Boje::Herc && pomocni_it->first!= Boje::Karo) throw std::logic_error("Neispravna lista!");

        pomocni_it++;
    }

    //Pretraga elemenata i izbacivanje iz liste/mape
    for(auto it2 = MultiMapa.begin(); it2 != MultiMapa.end(); it2++) {
        for(auto it1 = Spil.begin(); it1 != Spil.end(); it1++) {
            if(it1->first == it2->first && it1->second == it2->second) {
                it1 = Spil.erase(it1);
                MultiMapa.erase(it2);
            }
        }
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje,std::string>> &Spil,const short int &r, const int &b)
{

    std::queue<std::pair<std::string, std::string>> red_koji_se_vraca;

    std::string boje[] {"Pik","Tref","Herc","Karo"};
    std::string vrijednosti_karata[] {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    if(b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    //Provjera da li su parametri r i b u ispravnom opsegu i bacanje izuzetka(ukoliko nisu!)
    if(r < 1 || r > 52 ) throw std::logic_error("Neispravni elementi za izbacivanje!");


    //Provjera da li lista sadrzi vise od 52 elementa i bacanje izuzetka(ako sadrzi!)
    if(Spil.size() > 52) throw std::logic_error("Neispravna lista!");


    //Provjera da li elementi liste sadrze besmislene podatke i bacanje izuzetka(ukoliko sadrze)
    auto pomocni_it(Spil.begin());
    while(pomocni_it != Spil.end()) {
        int i(0);
        while(i < 13) {
            if(pomocni_it->second == vrijednosti_karata[i]) break;
            i++;
        }
        if(i == 13) throw std::logic_error("Neispravna lista!");
        pomocni_it++;
    }
    pomocni_it = Spil.begin();
    while(pomocni_it != Spil.end()) {
        if(pomocni_it->first != Boje::Pik && pomocni_it->first != Boje::Tref &&
                pomocni_it->first != Boje::Herc && pomocni_it->first!= Boje::Karo) throw std::logic_error("Neispravna lista!");

        pomocni_it++;
    }

    //Provjera da li su elementi liste sortirani i bacanje izuzetka(ukoliko nisu)
    if(DaLiJeSortiranaKakoTreba(Spil) == false) throw std::logic_error("Neispravna lista!");

    //Izbacivanje/Ubacivanje karata
    int index_boje(0);
    std::list<std::pair<Boje,std::string>>::iterator it(Spil.begin());

    int brojac_pomjeranja(0);

    int brojac_izbacenih(0);
    while(it != Spil.end()) {

        if((*it).first == Boje::Pik) index_boje = 0;
        else if((*it).first == Boje::Tref) index_boje = 1;
        else if((*it).first == Boje::Herc) index_boje = 2;
        else index_boje = 3;

        std::string pomocna_vrijednost((*it).second);

        if(brojac_pomjeranja == r-1) {

            red_koji_se_vraca.push(std::make_pair(boje[index_boje], pomocna_vrijednost));

            if(r == 1) {
                while(brojac_izbacenih < b) {
                    it = Spil.erase(it);
                    brojac_izbacenih++;
                }
            } else {
                it = Spil.erase(it);
                brojac_izbacenih++;
            }
            brojac_pomjeranja = 0;

        }
        if(brojac_izbacenih == b) break;
        it++;
        brojac_pomjeranja++;
        if(it == Spil.end() && brojac_izbacenih < b) it = Spil.begin();
    }

    //Sortiranje liste
    std::list<std::pair<Boje, std::string>>::iterator it3(Spil.begin());
    std::list<std::pair<Boje, std::string>>::iterator it4(Spil.begin());
    while(it3 != Spil.end()) {
        it4 = it3;
        while(it4 != Spil.end()) {
            if(it4->first < it3->first) {
                auto temp(*it4);
                *it4 = *it3;
                *it3 = temp;
            }
            it4++;
        }
        it3++;
    }
    std::list<std::pair<Boje, std::string>>::iterator it5(Spil.begin());
    std::list<std::pair<Boje, std::string>>::iterator it6(Spil.begin());
    while(it5 != Spil.end()) {
        int index1(0), index2(0);
        it6 = it5;
        while(it6 != Spil.end()) {
            for(int i = 0; i < 13; i++) {
                if(it6->second == vrijednosti_karata[i]) {
                    index1 = i;
                    break;
                }
            }
            for(int i = 0; i < 13; i++) {
                if(it5->second == vrijednosti_karata[i]) {
                    index2 = i;
                    break;
                }
            }
            if(index2 > index1 && it5->first == it6->first) {
                auto temp(*it5);
                *it5 = *it6;
                *it6 = temp;
            }
            it6++;
        }
        it5++;
    }

    return red_koji_se_vraca;
}
void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &Spil, std::queue<std::pair<std::string, std::string>> &red, int n)
{

    //Provjera da li je parametar n besmislen i bacanje izuzetka(ukoliko jeste)
    if(n < 0) throw std::domain_error("Broj n je besmislen!");

    //Provjera da li je parametar n veci od broja elemenata u redu i bacanje izuzetka(ukoliko jeste)
    if(n > red.size()) throw std::range_error("Nedovoljno karata u redu!");


    //Deklaracija i inicijalizacija nizova stringova (ime boja i vrijednosti karata)
    std::string boje[] {"Pik", "Tref", "Herc", "Karo"};
    std::string vrijednosti_karata[] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    //Deklaracija pomocnog reda i dodjela proslijeđenog reda, pomocnom redu
    std::queue<std::pair<std::string, std::string>> pomocni_red;
    pomocni_red = red;


    //Provjera da li lista sadrzi vise od 52 elementa i bacanje izuzetka(ukoliko sadrzi)
    if(Spil.size() > 52) throw std::logic_error("Neispravna lista!");

    //Provjera da li je lista sortirana kako treba i bacanje izutezka(ukoliko nije)
    if(DaLiJeSortiranaKakoTreba(Spil) == false) throw std::logic_error("Neispravna lista!");

    //Provjera da li lista sadrzi besmislene podatke i bacanje izuzetka(ukoliko sadrzi)
    auto pomocni_it(Spil.begin());
    while(pomocni_it != Spil.end()) {
        int i(0);
        while(i < 13) {
            if(pomocni_it->second == vrijednosti_karata[i]) break;
            i++;
        }
        if(i == 13) throw std::logic_error("Neispravna lista!");
        pomocni_it++;
    }
    pomocni_it = Spil.begin();
    while(pomocni_it != Spil.end()) {
        if(pomocni_it->first != Boje::Pik && pomocni_it->first != Boje::Tref &&
                pomocni_it->first != Boje::Herc && pomocni_it->first!= Boje::Karo) throw std::logic_error("Neispravna lista!");

        pomocni_it++;
    }
    //Prolazak kroz poslijeđeni red i ubacivanje elemenata u listu
    int brojac_izbacenih(0);
    while(!red.empty()) {
        int i(0);
        for(; i < 4; i++) {
            if(pomocni_red.front().first == boje[i]) break;
        }
        if(i == 4) throw std::logic_error("Neispravne karte!");
        int j(0);
        for(; j < 13; j++) {
            if(pomocni_red.front().second == vrijednosti_karata[j]) break;
        }
        if(j == 13) throw std::logic_error("Neispravne karte!");

        if(brojac_izbacenih == n) break;
        if(red.front().first == boje[0]) {
            Spil.push_back(std::make_pair(Boje::Pik,red.front().second));
            brojac_izbacenih++;
            if(brojac_izbacenih == n) break;
        } else if(red.front().first == boje[1]) {
            Spil.push_back(std::make_pair(Boje::Tref,red.front().second));
            brojac_izbacenih++;
            if(brojac_izbacenih == n) break;
        } else if(red.front().first == boje[2]) {
            Spil.push_back(std::make_pair(Boje::Herc,red.front().second));
            brojac_izbacenih++;
            if(brojac_izbacenih == n) break;
        } else {
            Spil.push_back(std::make_pair(Boje::Karo,red.front().second));
            brojac_izbacenih++;
        }
        red.pop();
    }
    //Sortiranje liste
    std::list<std::pair<Boje, std::string>>::iterator it3(Spil.begin());
    std::list<std::pair<Boje, std::string>>::iterator it4(Spil.begin());
    while(it3 != Spil.end()) {
        it4 = it3;
        while(it4 != Spil.end()) {
            if(it4->first < it3->first) {
                auto temp(*it4);
                *it4 = *it3;
                *it3 = temp;
            }
            it4++;
        }
        it3++;
    }
    std::list<std::pair<Boje, std::string>>::iterator it5(Spil.begin());
    std::list<std::pair<Boje, std::string>>::iterator it6(Spil.begin());

    while(it5 != Spil.end()) {
        int index1(0), index2(0);
        it6 = it5;
        while(it6 != Spil.end()) {
            for(int i = 0; i < 13; i++) {
                if(it6->second == vrijednosti_karata[i]) {
                    index1 = i;
                    break;
                }
            }
            for(int i = 0; i < 13; i++) {
                if(it5->second == vrijednosti_karata[i]) {
                    index2 = i;
                    break;
                }
            }
            if(index2 > index1 && it5->first == it6->first) {
                auto temp(*it6);
                *it6 = *it5;
                *it5 = temp;
            }
            it6++;
        }
        it5++;
    }
}

void Ispisi(std::list<std::pair<Boje, std::string>> &Spil)
{


    std::list<std::pair<Boje, std::string>>::iterator it(Spil.begin());


    std::cout << "Pik: ";
    auto it1(Spil.begin());
    while(it1->first != Boje::Pik) {
        it1++;
        if(it1 == Spil.end()) break;
    }
    if(it1 == Spil.end()) std::cout << std::endl;
    else {
        while(it1->first == Boje::Pik) {
            std::cout << it1->second << " ";
            it1++;
            if(it1 == Spil.end()) break;
        }
        std::cout << std::endl;
    }
    std::cout << "Tref: ";
    it1 = Spil.begin();
    while(it1->first != Boje::Tref) {
        it1++;
        if(it1 == Spil.end()) break;
    }
    if(it1 == Spil.end()) std::cout << std::endl;
    else {
        while(it1->first == Boje::Tref) {
            std::cout << it1->second << " ";
            it1++;
            if(it1 == Spil.end()) break;
        }
        std::cout << std::endl;
    }
    std::cout << "Herc: ";
    it1 = Spil.begin();
    while(it1->first != Boje::Herc) {
        it1++;
        if(it1 == Spil.end()) break;
    }
    if(it1 == Spil.end()) std::cout << std::endl;
    else {
        while(it1->first == Boje::Herc) {
            std::cout << it1->second << " ";
            it1++;
            if(it1 == Spil.end()) break;
        }
    }
    if(it1 != Spil.end()) std::cout << std::endl;
    std::cout << "Karo: ";
    it1 = Spil.begin();
    while (it1->first != Boje::Karo) {
        it1++;
        if(it1 == Spil.end()) break;
    }
    if(it1 == Spil.end()) std::cout << std::endl;
    else {
        while(it1->first == Boje::Karo) {
            std::cout << it1->second << " ";
            it1++;
            if(it1 == Spil.end()) break;
        }
    }
    std::cout << std::endl;


}
int main ()
{

    std::cout << "Unesite korak razbrajanja: ";
    short int r;
    std::cin >> r;

    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin >> b;

    std::list<std::pair<Boje, std::string>> spil(KreirajSpil());
    std::queue<std::pair<std::string, std::string>> red;
    try {
        red = IzbaciKarteRazbrajanjem(spil,r,b);
    } catch(std::logic_error izuzetak1) {
        std::cout << "Izuzetak: " << izuzetak1.what() << std::endl;
        return 0;
    }

    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:\n";
    Ispisi(spil);

    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    int broj_karata;
    std::cin >> broj_karata;

    try {
        VratiPrvihNKarata(spil,red,broj_karata);
    } catch(std::domain_error izuzetak2) {
        std::cout << "Izuzetak: " << izuzetak2.what() << std::endl;
        return 0;
    } catch(std::range_error izuzetak3) {
        std::cout << "Izuzetak: "<< izuzetak3.what() << std::endl;
        return 0;
    } catch(std::logic_error izuzetak4) {
        std::cout << "Izuzetak: " << izuzetak4.what() << std::endl;
        return 0;
    }
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:\n";
    Ispisi(spil);



    return 0;
}

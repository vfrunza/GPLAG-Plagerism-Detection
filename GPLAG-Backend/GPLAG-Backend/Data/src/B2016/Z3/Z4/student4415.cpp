/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>
#include <iterator>


// Zadaca 3 Z4
// Razvrstavanje djece u timove po pravilu prvih n%k timova ima (n/k)+1 igraca
// ostali timovi imaju n/k igraca
// objekat std::list simuliramo u kruznu listu tako kada dodjemo na kraj liste vracamo se na pocetak
// clanove liste kopiramo u skupove po pravilu nakon svakoj izbacivanja kruzimo n - puta kroz listu gdje je n duzina imena izbacenog djeteta

int duzina_imena (std::string ime )
{
    int brojac(0);
    for (auto &i : ime) {
        if ((i >= 'A' and i <= 'Z')or (i >= 'a' and i <= 'z') or (i >= '0' and i <= '9')) brojac++;
    }
    return brojac;
}


std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djeca2, int br_tim)
{

    if (br_tim < 1 or br_tim > djeca2.size()) throw std::logic_error("Razvrstavanje nemoguce");     // check is number of teams correct

    std::vector<std::set<std::string>> Timovi(0);       // vector of sets of strings
    std::list<std::string> djeca(0);                    // circular list
    std::set<std::string> tim;                          // temporary team
    // number of teams and size of team
    int br_tim_1(djeca2.size()%br_tim);
    int br_clanova_1((djeca2.size()/br_tim)+1);
    int br_clanova_2(djeca2.size()/br_tim);
    // copy vector into list
    for (auto i : djeca2) {
        djeca.push_back(i);
    }
    // list::iterator, temp(djete), brojac(duzina imena djeteta), zadnji (iterator u listi)
    auto it(djeca.begin());
    auto temp(*it);
    int brojac(0);
    auto zadnji(djeca.end());

    // main loop
    while (djeca.size() > 0) {

        temp = *it;
        it = djeca.erase(it);
        if (it == djeca.end()) it = djeca.begin();

        // pravimo skupove
        if (Timovi.size() < br_tim_1) {
            if (tim.size() < br_clanova_1)
                tim.insert(temp);
            else {
                Timovi.push_back(tim);
                tim.clear();
                tim.insert(temp);
            }
        } else {
            if (tim.size() < br_clanova_2)
                tim.insert(temp);
            else {
                Timovi.push_back(tim);
                tim.clear();
                tim.insert(temp);
            }
        }
        if (djeca.size() == 0 and tim.size() != 0) Timovi.push_back(tim);

        //trazimo novo djete

        if (djeca.size() == 0) continue;
        zadnji = djeca.end();
        zadnji--;
        brojac = duzina_imena(temp)-1;
        for (int i = 0; i < brojac; i++) {
            if (it == zadnji) it = djeca.begin();
            else it++;
        }
    }
    return Timovi;
}
int main ()
{
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cout << "Unesite imena djece: " << std::endl;
    std::cin.ignore(1000,'\n');
    std::vector<std::string> v1(n);
    for (auto &i : v1) {
        std::getline(std::cin,i);

    }
    std::cout << "Unesite broj timova: ";
    std::cin >> n;
    try {
        auto Timovi(Razvrstavanje(v1,n));

        int brojac(1);
        for (auto &i : Timovi) {
            auto zadnji(i.end());
            zadnji--;

            std::cout << "Tim " << brojac << ": ";
            brojac++;
            for (auto j = i.begin(); j != i.end(); j++) {


                if (j == zadnji) std::cout << *j;
                else std::cout << *j << ", ";
            }
            std::cout  << std::endl;
        }
    } catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;

    }
    return 0;
}
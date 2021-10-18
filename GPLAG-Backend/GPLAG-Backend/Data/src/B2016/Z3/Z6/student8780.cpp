/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>
#include <iterator>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr <Dijete> sljedeci ;

};


std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string>dijete, int broj_timova)
{
    std::vector<std::set<std::string>> timovi;
    if (broj_timova<1 || broj_timova> dijete.size()) throw std::logic_error("Razvrstavanje nemoguce");

    int broj_djece(dijete.size());
    int prvi (broj_djece%broj_timova);
    int clanovi (prvi+1);

    std::shared_ptr<Dijete> imena;
    for (int i=0; i<dijete.size() ; i++) {
        imena= std::make_shared<Dijete> ();
        if (i==dijete.size()-1) imena.get()[i].sljedeci=std::make_shared<Dijete>(imena.get()[0]);
        else imena.get()[i].sljedeci=std::make_shared<Dijete>(imena.get()[i+1]);
    }


    for (int k=0; k<broj_timova; k++) {
        std::set<std::string> tim;
        tim.insert (dijete[0]);
        std::unique_ptr<Dijete> pokazivac(new Dijete);


        pokazivac.get()[k].sljedeci = std::make_shared<Dijete>(imena.get()[0]);


        if (k<prvi) {
            for (int i=0; i<clanovi; i++) {
                // gdje pokazuje sljedeci ubaci u set

                tim.insert((pokazivac.get()[i].sljedeci.get()->ime));         // GREŠKA !

                // sljedeci se preusmjerava tako da ne pokazuje na to mjesto nego na sljedeci

                pokazivac.get()[i].sljedeci=pokazivac.get()[i+1].sljedeci;


            }


            timovi[k]=tim;

        }

        else {
            for (int i=0; i<clanovi-1; i++) {
                // gdje pokazuje sljedeci ubaci u set

                tim.insert((pokazivac.get()[i].sljedeci.get()->ime));         // GREŠKA !

                // sljedeci se preusmjerava tako da ne pokazuje na to mjesto nego na sljedeci

                pokazivac.get()[i].sljedeci=pokazivac.get()[i+1].sljedeci;
            }


            timovi[k]=tim;
        }

    }

    return timovi;

}

int main ()
{
    try {
        int broj_djece;
        int broj_timova;
        std::cout << "Unesite broj djece: ";
        std::cin >> broj_djece;
        std::vector<std::string> djeca;

        std::cout << "Unesite imena djece: ";

        for (int i=0; i<broj_djece; i++) {
            std::string ime;
            std::getline(std::cin,ime);
            djeca.push_back(ime);
        }

        std::cout << "Unesite broj timova: ";
        std::cin >> broj_timova;

        std::vector<std::set<std::string>> timovi(Razvrstavanje(djeca,broj_timova));

        for (int i=0; i<broj_timova; i++) {
            std::cout << "Tim "<< i+1 << ": ";
            for (auto x:timovi[i]) std::cout << x << ", ";
            std::cout << std::endl;

        }
    } catch(std::logic_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }

    return 0;
}
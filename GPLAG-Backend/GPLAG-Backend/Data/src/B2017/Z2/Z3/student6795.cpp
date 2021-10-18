/B 2017/2018, Zadaća 2, Zadatak 3
#include <iostream>
#include <new>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

//Funkcija koja Testira period
template <typename Tip>
bool Test_Perioda(const std::vector<Tip> &v, int T)
{
    for(int i(0); i<v.size(); ++i) {
        if(i + T == v.size()) break;
        if(v.at(i) != v.at(i+T)) return false;
    }

    return true;
}

//Funkcija koja ispituje da li je vektor periodican
template <typename Tip>
bool Periodican_slijed (const std::vector<Tip> &v, int &period)
{

    for(int i(1); i<v.size(); ++i) {
        if(Test_Perioda(v,i) == true) {
            period = i;
            return true;
        }
    }

    return false;
}

//Funkcija koja dodaje clanove vektoru sve dok velicina istog nije djeljiva sa periodom
template <typename Tip>
int Produzi_Vektor(const std::vector<Tip> &v, int &period)
{
    Tip prvi(v.at(0));
    int pozicija_i(0);

    for(int i(1); i < v.size(); ++i) {
        if(prvi == v.at(i)) break;
        pozicija_i = i;
    }

    std::vector<Tip> novi;

    bool prekini(false);
    for(;;) {
        for(int i(0); i <= pozicija_i; ++i) {
            if(novi.size() >= v.size()) {
                if(novi.size() % period == 0) {
                    prekini = true;
                    break;
                }
            }
            novi.push_back(v.at(i));
        }
        if(prekini) break;
    }

    int koliko_puta(0);
    koliko_puta = novi.size() / period;

    return koliko_puta;
}

template <typename Tip>
std::vector<Tip> VektorIspis(std::vector<Tip> &v, int period)
{
    Tip prvi(v.at(0));
    int pozicija_i(0);

    for(int i(1); i < v.size(); ++i) {
        if(prvi == v.at(i)) break;
        pozicija_i = i;
    }

    std::vector<Tip> novi;

    bool prekini(false);
    for(;;) {
        for(int i(0); i <= pozicija_i; ++i) {
            if(novi.size() >= v.size()) {
                if(novi.size() % period == 0) {
                    prekini = true;
                    break;
                }
            }
            novi.push_back(v.at(i));
        }
        if(prekini) break;
    }

    return novi;
}

template <typename Tip>
int koliko_puta_funkcija(const std::vector<Tip> &v)
{
    int brojac(1);

    Tip prvi(v.at(0));
    for(int i(1); i<v.size(); ++i) {
        if(prvi == v.at(i)) ++brojac;
    }

    return brojac;
}

template<typename Tip>
std::vector<Tip> Dopuni_Vektor(const std::vector<Tip> &v)
{

    std::vector<Tip> novi;
    for(int ponovi(1); ponovi<=2; ++ponovi) {
        for(int i(0); i<v.size(); ++i) {
            novi.push_back(v.at(i));
        }
    }

    return novi;
}

template <typename Tip>
Tip **AlocirajFragmentirano(const std::vector<Tip> &Radni_Vektor, int &koliko_puta)
{
    typename std::vector<Tip>::const_iterator pocetak;
    typename std::vector<Tip>::const_iterator iza_kraja_perioda;
    if(Radni_Vektor.size() == 0) throw std::logic_error("Prazan vektor!");
    int period(0);

    if(Periodican_slijed(Radni_Vektor,period)) {
        koliko_puta = Produzi_Vektor(Radni_Vektor, period);
        pocetak = std::begin(Radni_Vektor);
        iza_kraja_perioda = std::begin(Radni_Vektor) + period;
    } else {
        koliko_puta = 2;
        pocetak = std::begin(Radni_Vektor);
        iza_kraja_perioda = std::end(Radni_Vektor);
    }

    for(int i(0); i<Radni_Vektor.size(); ++i) {
        if(Radni_Vektor.at(i) <= 0) throw std::domain_error("Neispravan vektor!");
    }

    //Najveci broj kolona
    int najveci(0);
    for(int i(0); i<Radni_Vektor.size(); ++i) if(Radni_Vektor.at(i) > najveci) najveci = Radni_Vektor.at(i);
    int max(najveci);

    typename std::vector<Tip>::const_iterator temp;
    temp = pocetak;
    int elemenati(0);
    while(pocetak != iza_kraja_perioda) {
        ++elemenati;
        ++pocetak;
    }
    pocetak = temp;
    //Kreiranje matrice
    Tip **pok(nullptr);
    try {
        int red_alokacije(0);
        pok = new Tip* [elemenati * koliko_puta];
        for(int i(0); i<koliko_puta; ++i) {
            while(pocetak != iza_kraja_perioda) {
                int n = int (*pocetak);
                pok[red_alokacije] = new Tip [n];
                ++pocetak;
                ++red_alokacije;
            }
            pocetak = temp;
        }
        pocetak = temp;
        //UPIS
        int j(0);
        for(int i(0); i<elemenati * koliko_puta; ++i) {
            while(pocetak != iza_kraja_perioda) {
                int n = int(*pocetak);
                for(j = n-1; j>=0; --j) {
                    pok[i][j] = najveci--;
                }
                if(j == -1) break;
            }
            if(pocetak == iza_kraja_perioda -1) pocetak = temp;
            else ++pocetak;
            najveci = max;
        }


    } catch(...) {
        throw;
    }

    return pok;
}

template <typename Tip>
Tip **AlocirajKontinualno(const std::vector<Tip> &Radni_Vektor, int &koliko_puta)
{
    typename std::vector<Tip>::const_iterator pocetak;
    typename std::vector<Tip>::const_iterator iza_kraja_perioda;
    if(Radni_Vektor.size() == 0) throw std::logic_error("Prazan vektor!");
    int period(0);

    if(Periodican_slijed(Radni_Vektor,period)) {
        koliko_puta = Produzi_Vektor(Radni_Vektor, period);
        pocetak = std::begin(Radni_Vektor);
        iza_kraja_perioda = std::begin(Radni_Vektor) + period;
    } else {
        pocetak = std::begin(Radni_Vektor);
        iza_kraja_perioda = std::end(Radni_Vektor);
        koliko_puta = 2;
    }

    for(int i(0); i<Radni_Vektor.size(); ++i) {
        if(Radni_Vektor.at(i) <= 0) throw std::domain_error("Neispravan vektor!");
    }

    typename std::vector<Tip>::const_iterator temp;
    temp = pocetak;
    int elementi(0);
    while(pocetak != iza_kraja_perioda) {
        ++elementi;
        ++pocetak;
    }
    pocetak = temp;
    //Kreiranje matrice
    Tip **pok(nullptr);
    int j(0);
    try {
        int red_alokacije(1);
        pok = new Tip* [elementi * koliko_puta];
        pok[0] = new Tip[koliko_puta * koliko_puta * elementi];
        for(int i(0); i<koliko_puta; ++i) {
            while(pocetak != iza_kraja_perioda) {
                if(red_alokacije == elementi * koliko_puta) break;
                int n = int(*pocetak);
                pok[red_alokacije] = pok[red_alokacije - 1] + n;
                ++pocetak;
                ++red_alokacije;
            }
            pocetak = temp;
        }
        pocetak = temp;

        //UPIS
        for(int i(0); i<koliko_puta * elementi; ++i) {
            while(pocetak != iza_kraja_perioda) {
                int n = int(*pocetak);
                int unos = int(*pocetak);
                for(j = 0; j<n; ++j) {
                    pok[i][j] = unos--;
                }
                if(j == n) break;
            }
            if(pocetak == iza_kraja_perioda - 1) pocetak = temp;
            else ++pocetak;
        }


    } catch(...) {
        throw;
    }


    return pok;
}

int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int br_elemenata;
    std::cin>>br_elemenata;
    std::vector<int> vektor(br_elemenata);
    std::cout<<"Unesite elemente vektora: ";
    std::for_each(std::begin(vektor), std::begin(vektor) + br_elemenata, [](int &broj) {
        std::cin>>broj;
    });
    std::cout <<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
    int alokacija;
    std::cin>>alokacija;
    int koliko_puta(0);
    if(alokacija == 1) {
        int **pok(nullptr);
        std::vector<int> MojVektor;
        try {
            pok=AlocirajFragmentirano(vektor, koliko_puta);
            int period(0);
            Periodican_slijed(vektor, period);
            if(period != 0) MojVektor = VektorIspis(vektor, period);
            else MojVektor = Dopuni_Vektor(vektor);
            std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
            for(int i(0); i<MojVektor.size(); ++i) {
                for(int j(0); j<MojVektor.at(i); ++j) {
                    std::cout<<std::left<<std::setw(3)<<pok[i][j];
                }
                std::cout<<std::endl;
            }

            //BRISANJE
            for(int i(0); i<MojVektor.size(); ++i) delete[] pok[i];
            delete[] pok;

        } catch(std::logic_error poruka) {
            std::cout<<"Izuzetak: "<<poruka.what();
        } catch(std::domain_error poruka) {
            std::cout<<"Izuzetak: "<<poruka.what();
        } catch(std::bad_alloc) {
            delete[] pok;
            std::cout<<"Nedovoljno memorije";
        } catch(...) {
            std::cout<<"Neocekivani Izuzetak";
        }
    } else if(alokacija == 0) {
        int **pok(nullptr);
        std::vector<int> MojVektor;
        try {
            pok=AlocirajKontinualno(vektor, koliko_puta);
            int period(0);
            Periodican_slijed(vektor, period);
            if(period != 0) MojVektor = VektorIspis(vektor, period);
            else MojVektor = Dopuni_Vektor(vektor);

            std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
            for(int i(0); i<MojVektor.size(); ++i) {
                for(int j(0); j<MojVektor.at(i); ++j) {
                    std::cout<<std::left<<std::setw(3)<<pok[i][j];
                }
                std::cout<<std::endl;
            }

            //BRISANJE
            delete[] pok[0];
            delete[] pok;

        } catch(std::logic_error poruka) {
            std::cout<<"Izuzetak: "<<poruka.what();
        } catch(std::domain_error poruka) {
            std::cout<<"Izuzetak: "<<poruka.what();
        } catch(std::bad_alloc) {
            delete[] pok;
            std::cout<<"Nedovoljno memorije";
        } catch(...) {
            std::cout<<"Neocekivani Izuzetak";
        }
    }

    return 0;
}
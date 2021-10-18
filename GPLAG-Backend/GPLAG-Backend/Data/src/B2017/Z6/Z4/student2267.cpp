/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <functional>
#include <cmath>
#include <iomanip>
#include <complex>

template <typename TipElemenata>
class DatotecniKontejner
{
    std::fstream tok;
    void TestPozicije(int x);
    void TestIspravnosti();
    void Citaj();

public:
    DatotecniKontejner(const std::string &ime_datoteke);
    void DodajNoviElement(const TipElemenata &element);
    int DajBrojElemenata ();
    TipElemenata DajElement(int pozicija);
    void IzmijeniElement(int pozicija, const TipElemenata &element);
    void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)> kriterij = std::less<TipElemenata>());

    
};

template <typename TipElemenata>
DatotecniKontejner<TipElemenata>::DatotecniKontejner(const std::string &ime_datoteke)
{
    tok.open(ime_datoteke, std::ios::out| std::ios::in | std::ios::binary);
    if(!tok) {
        tok.clear();
        tok.close();
        tok.open(ime_datoteke, std::ios::out | std::ios::binary);
        tok.close();
        tok.open(ime_datoteke, std::ios::out | std::ios::in | std::ios::binary);

        if(!tok) throw std::logic_error("Problemi priliko otvaranja ili kreiranja datoteke");

    }

}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::DodajNoviElement(const TipElemenata &element)
{
    tok.seekp(0, std::ios::end);
    tok.write(reinterpret_cast<const char*> (&element), sizeof element);
    void TestIspravnosti();
    tok.seekg(0, std::ios::end);

}

template <typename TipElemenata>
int  DatotecniKontejner<TipElemenata>::DajBrojElemenata()
{

    TipElemenata testni;
    tok.seekg(0, std::ios::end);
    int broj(tok.tellg());
    return (broj/(sizeof testni));
}
template <typename TipElemenata>
TipElemenata  DatotecniKontejner<TipElemenata>::DajElement(int pozicija)
{
    TestPozicije(pozicija);

    TipElemenata trenutni;
    tok.seekg(pozicija * sizeof trenutni, std::ios::beg);
    tok.read(reinterpret_cast<char*>(&trenutni), sizeof trenutni);
    void TestIspravnosti();
    return trenutni;
}

template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::TestPozicije(int x)
{
    int broj(DajBrojElemenata());
    if (x < 0 || x >= broj)
        throw std::range_error("Neispravna pozicija");
}
template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::TestIspravnosti()
{
    if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
}
template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::IzmijeniElement(int pozicija, const TipElemenata &element)
{
    TestPozicije(pozicija);

    tok.seekp(pozicija * sizeof element, std::ios::beg);
    tok.write(reinterpret_cast<const char *> (&element), sizeof element);
    void TestIspravnosti();

}
template <typename TipElemenata>
void DatotecniKontejner<TipElemenata>::Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>
        kriterij)
{

    for (int i = 0; i < DajBrojElemenata() - 1; i++) {

        int trenutni = i;
        for (int j {i + 1}; j < DajBrojElemenata(); j++)
            if(kriterij(DajElement(j), DajElement(trenutni)))
                trenutni = j;

        auto temp1 (DajElement(trenutni)), temp2 (DajElement(i));
        tok.seekp(trenutni * sizeof temp1, std::ios::beg);
        tok.write(reinterpret_cast<const char*> (&temp2), sizeof temp2);
        void TestIspravnosti();
        tok.seekp(i * sizeof temp2, std::ios::beg);
        tok.write(reinterpret_cast<const char*> (&temp1), sizeof temp1);
        void TestIspravnosti();

    }


}
template <typename TipElemenata>
void  DatotecniKontejner<TipElemenata>::Citaj() {

        int broj(DajBrojElemenata());
        TipElemenata nakav;
        for(int i = 0; i < broj; i++) {

            tok.seekg(i * sizeof nakav, std::ios::beg);
            TipElemenata trenutni;
            tok.read(reinterpret_cast<char*> (&trenutni), sizeof trenutni);
            std::cout << std::fixed << std::setprecision(2) <<  trenutni << " ";
        }
        std::cout << std::endl;
    }


int main ()
{
   /*   TESTIRANJE!
    DatotecniKontejner<double> test("testna.dat");

    std::cout << "Kontejner: ";
    for(int i = 1; i < 11; i++)
        test.DodajNoviElement(1./i);

    test.Citaj();
    test.Sortiraj([](double x, double y) {
        return std::cos(x) < std::sqrt(y);
    });
    std::cout << "Nakon sortiranja: ";
    test.Citaj();

    std::cout << "Broj elemenata: " << test.DajBrojElemenata() << std::endl;
    std::cout << "Element na 7. poziciji: (pocetak od 0) " <<  test.DajElement(7) << std::endl;
    test.IzmijeniElement(7, 666);
    test.IzmijeniElement(3, 0.666);
    std::cout << "Nakon izmjene: ";
    test.Citaj();

    std::cout << "---------------------------------------------" << std::endl;
    DatotecniKontejner<std::complex<double>> novi("kompleksni.dat");

    std::cout << "Kontejner: ";
    for(int i = 1; i < 6; i++)
        novi.DodajNoviElement({std::cos(1./i), std::sin(1./i)});

    novi.Citaj();
    novi.Sortiraj([](std::complex<double> x, std::complex <double> y) {
        return std::abs(x) < std::abs(y);
    });
    std::cout << "Nakon sortiranja: ";
    novi.Citaj();

    std::cout << "Broj elemenata: " << novi.DajBrojElemenata() << std::endl;
    std::cout << "Element na 1. poziciji: (pocetak od 0) " <<  novi.DajElement(1) << std::endl;
    novi.IzmijeniElement(1, {666,999});
    novi.IzmijeniElement(3, {0.666,0.999});
    std::cout << "Nakon izmjene: ";
    novi.Citaj();

    std::cout << "Sortiranje po imaginarnom dijelu: " << std::endl;
    novi.Sortiraj([](std::complex<double> x, std::complex<double> y) {
        return x.imag() < y.imag();
    });
    novi.Citaj();
    */
 return 0;
    
}

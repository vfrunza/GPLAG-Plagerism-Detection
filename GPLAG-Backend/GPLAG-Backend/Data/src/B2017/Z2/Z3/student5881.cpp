#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

template <typename Tip>
int OdrediOsnovniPeriod(const std::vector<Tip> &niz)
{
    int brojac(1);
    for (int i = 1; i < niz.size(); i++) {
        if (niz.at(i)==niz.at(0)) {
            int j(0);
            for (; j+i < niz.size(); j++) {
                if (niz.at(i+j)!=niz.at(j))
                    break;
            }
            if (i+j==niz.size())
                return brojac;
        }
        brojac++;
    }
    return brojac;
}

template <typename Tip>
int  Izmjenivektor(const std::vector<Tip> &niz, int &koliko_puta)
{
    int brojac(OdrediOsnovniPeriod(niz));
    if (brojac==niz.size()) {
        koliko_puta=2;
        return brojac;
    }

    int vel(niz.size());
    while(vel%brojac!=0)
        vel++;
    koliko_puta=vel/brojac;
    return brojac;
}

template <typename Tip>
Tip ** AlocirajFragmentirano(const std::vector<Tip> &niz, int &koliko_puta)
{
    if (niz.size()==0)
        throw "Prazan vektor!";
    int najduzi_red(0);
    for (int i = 0; i < niz.size(); i++) {
        if (niz.at(i)<=0)
            throw std::domain_error("Neispravan vektor!");
        if (niz.at(i)>najduzi_red)
            najduzi_red=niz.at(i);
    }
    Tip ** dinmatrica(nullptr);
    int osnovniperiod(Izmjenivektor(niz, koliko_puta));

    try {
        dinmatrica = new Tip*[osnovniperiod*koliko_puta] {};
    } catch (...) {
        throw ;
    }
    try {
        for (int i = 0; i < niz.size(); i++)
            dinmatrica[i]=new Tip[niz.at(i)];

        for (int i = niz.size(); i < osnovniperiod*koliko_puta; i++)
            dinmatrica[i]=new Tip[niz.at(i%osnovniperiod)];
    } catch (...) {
        for (int i = 0; i < osnovniperiod*koliko_puta; i++)
            delete [] dinmatrica[i];
        delete [] dinmatrica;
        throw;
    }

    for (int i = 0; i < osnovniperiod*koliko_puta; i++) {
        int temp(najduzi_red);
        int indeks(i);
        if (i>=niz.size())
            indeks=i%osnovniperiod;
        for (int j = 0; j < niz.at(indeks); j++)
            dinmatrica[i][j]=1-niz.at(indeks)+temp++;
    }
    return dinmatrica;
}


template <typename Tip>
Tip ** AlocirajKontinualno(const std::vector<Tip> &niz, int &koliko_puta)
{
    if (niz.size()==0)
        throw "Prazan vektor!";
    for (int i = 0; i < niz.size(); i++) {
        if (niz.at(i)<=0)
            throw std::domain_error("Neispravan vektor!");
    }
    Tip ** dinmatrica(nullptr);
    int osnovniperiod(Izmjenivektor(niz, koliko_puta));

    try {
        dinmatrica = new Tip*[osnovniperiod*koliko_puta] {};
    } catch (...) {
        throw ;
    }

    int ukupnaVel(0);
    for (int i = 0; i < niz.size(); i++)
        ukupnaVel+=niz.at(i);
    for (int i = niz.size(); i < osnovniperiod*koliko_puta; i++)
        ukupnaVel+=niz.at(i%osnovniperiod);
    try {
        dinmatrica[0]=new Tip[ukupnaVel];
    } catch (...) {
        delete [] dinmatrica;
        throw;
    }

    for (int i = 1; i < osnovniperiod*koliko_puta; i++) {
        int indeks(i);
        if (i>niz.size())
            indeks=i%osnovniperiod;
        dinmatrica[i]=dinmatrica[i-1]+niz.at(indeks-1);
    }


    for (int i = 0; i < osnovniperiod*koliko_puta; i++) {
        int indeks(i);
        if (i>=niz.size())
            indeks=i%osnovniperiod;
        int temp(niz.at(indeks));
        for (int j = 0; j < niz.at(indeks); j++)
            dinmatrica[i][j]=temp--;
    }
    return dinmatrica;
}


int main ()
{
    int vel;
    int koliko_puta;
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >> vel;
    std::vector<int> niz;
    try {
        niz.resize(vel);
    } catch (...) {
        return -1;
    }
    std::cout << "Unesite elemente vektora: ";
    for (int i = 0; i < vel; i++)
        std::cin >> niz.at(i);

    int tip;
    std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
    std::cin >> tip;
    if (tip!=0 && tip!=1)
        return -1;

    int **dinmatrica(nullptr);
    try {
        if (tip==1)
            dinmatrica=AlocirajFragmentirano(niz, koliko_puta);
        else
            dinmatrica=AlocirajKontinualno(niz, koliko_puta);
    } catch (const std::domain_error &greska) {
        std::cout << "Izuzetak: " << greska.what();
        return -1;
    } catch (const char greska []) {
        std::cout << "Izuzetak: " << greska;
        return -1;
    } catch (...) {
        return -1;
    }
    int broj_redova(OdrediOsnovniPeriod(niz)*koliko_puta);
    std::cout << "Dinamicki alocirana matrica:" << std::endl;
    for (int i = 0; i < broj_redova; i++) {
        int indeks(i);
        if (i>=niz.size())
            indeks=i%(broj_redova/koliko_puta);
        for (int j = 0; j < niz.at(indeks); j++)
            std::cout << std::setw(3) << std::left << dinmatrica[i][j];
        std::cout << std::endl;
    }

    if (tip==1) {
        for (int i = 0; i < broj_redova; i++)
            delete [] dinmatrica[i];
    } else
        delete [] dinmatrica[0];
    delete [] dinmatrica;

    return 0;
}
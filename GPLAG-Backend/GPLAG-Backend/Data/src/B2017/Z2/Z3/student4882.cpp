#include <iomanip>
#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <type_traits>
#include <stdexcept>
#include <cmath>

template <typename Tip>
bool TestPerioda (const std::vector<Tip> vektor, int p) {
    bool period(true);
    const double eps=pow(10, -10);
    if (vektor.size()==1) {
        period=false;
        return period;
    }
    if (p>=vektor.size()) {
        period=false;
        return period;
    }
    for (int i=0; i<(vektor.size()-p); i++) {
        if (fabs(vektor.at(i)-vektor.at(i+p))>eps) {
            period=false;
            return period;
        }
    }
    return period;
}

template <typename Tip>
int OdrediOsnovniPeriod (const std::vector<Tip> vektor) {
    int brojac=0;
    const double eps=pow(10, -10);
    for (int i=1; i<vektor.size(); i++) {
        brojac++;
        if (fabs(vektor.at(0)-vektor.at(i))<=eps) {
            if (TestPerioda(vektor, brojac)==true) {
                return brojac;
            }
        }
    }
    brojac=0;
    return brojac;
}

template <typename Tip>
int** AlocirajFragmentirano (const std::vector<Tip> &v, int &koliko_puta) {
    int n=v.size(), t;
    if (n==0) throw std::domain_error("Prazan vektor!");
    for (int i=0; i<n; i++) {
        if (v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
    }
    if (OdrediOsnovniPeriod(v)!=0) {
        t=OdrediOsnovniPeriod(v);
        if (n%t==0) koliko_puta=(n/t);
        else koliko_puta=int(n/t)+1;
    }
    if (OdrediOsnovniPeriod(v)==0) {
        t=n;
        koliko_puta=2;
    }
    int **pok=nullptr;
    try {
        pok=new typename std::remove_reference<decltype(v.at(0)+v.at(0))>::type* [koliko_puta*t];
        try {
            for (int i=0; i<koliko_puta*t; i++) {
                pok[i]=new Tip [v.at(i%t)];
            }
        }
        catch (...) {
            for (int i=0; i<koliko_puta*t; i++) delete [] pok[i];
            delete [] pok;
            throw;
        }
        int najveci=0;
        for (int i=0; i<n; i++) {
            if (v.at(i)>najveci) najveci=v.at(i);
        }
        for (int i=0; i<koliko_puta*t; i++) {
            int k=najveci-v.at(i%t)+1;
            for (int j=0; j<v.at(i%t); j++) {
                pok[i][j]=k;
                k++;
            }
        }
        return pok;
    }
    catch (...) {
        for (int i=0; i<n; i++) {
            delete [] pok[i];
        }
        delete [] pok;
        throw;
    }
}

template <typename Tip>
int** AlocirajKontinualno (const std::vector<Tip> &v, int &koliko_puta) {
    int n=v.size(), t;
    if (n==0) throw std::domain_error("Prazan vektor!");
    for (int i=0; i<n; i++) {
        if (v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
    }
    if (OdrediOsnovniPeriod(v)!=0) {
        t=OdrediOsnovniPeriod(v);
        if (n%t==0) koliko_puta=(n/t);
        else koliko_puta=int(n/t)+1;
    }
    if (OdrediOsnovniPeriod(v)==0) {
        t=n;
        koliko_puta=2;
    }
    int **pok=nullptr;
    try {
        pok=new typename std::remove_reference<decltype(v.at(0)+v.at(0))>::type* [koliko_puta*t];
        int brojac(0);
        for (int i=0; i<t; i++) {
            brojac+=v.at(i);
        }
        brojac=brojac*koliko_puta;
        try {
            pok[0]=new typename std::remove_reference<decltype(v.at(0)+v.at(0))>::type [brojac];
        }
        catch (...) {
            delete [] pok [0];
            delete [] pok;
            throw;
        }
        for (int i=1; i<koliko_puta*t; i++) {
            pok[i]=pok[i-1]+v.at((i-1)%t);
        }
        int najveci=0;
        for (int i=0; i<n; i++) {
            if (v.at(i)>najveci) najveci=v.at(i);
        }
        for (int i=0; i<koliko_puta*t; i++) {
            int k=v.at(i%t);
            for (int j=0; j<v.at(i%t); j++) {
                pok[i][j]=k;
                k--;
            }
        }
        return pok;
    }
    catch (...) {
        delete [] pok[0];
        delete [] pok;
        throw;
    }
}

int main ()
{
    try {
        int n;
        std::cout << "Unesite broj elemenata vektora: ";
        std::cin >> n;
        std::cout << "Unesite elemente vektora: ";
        std::vector<int> v (n);
        int k;
        for (int i=0; i<n; i++) {
            std::cin >> k;
            v.at(i)=k;
        }
        int t;
        if (OdrediOsnovniPeriod(v)!=0) {
            t=OdrediOsnovniPeriod(v);
        }
        else {
            t=n;
        }
        std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
        std::cin >> k;
        int **pok=nullptr;
        int koliko_puta;
        if (k==1) { 
            pok=AlocirajFragmentirano(v, koliko_puta);
            std::cout << "Dinamicki alocirana matrica: " << std::endl;
            for (int i=0; i<koliko_puta*t; i++) {
                for (int j=0; j<v.at(i%t); j++) {
                    std::cout << std::left << std::setw(2) << pok[i][j] << " ";
                }
                std::cout << std::endl;
            }
            for (int i=0; i<koliko_puta*t; i++) delete [] pok[i];
            delete [] pok;
        }
        else if (k==0) {
            pok=AlocirajKontinualno(v, koliko_puta);
            std::cout << "Dinamicki alocirana matrica: " << std::endl;
            for (int i=0; i<koliko_puta*t; i++) {
                for (int j=0; j<v.at(i%t); j++) {
                    std::cout << std::left << std::setw(2) << pok[i][j] << " ";
                }
                std::cout << std::endl;
            }
            delete [] pok[0];
            delete [] pok;
        }
    }
    catch (std::domain_error izuzetak1) {
        std::cout << "Izuzetak: " << izuzetak1.what() << std::endl;
    }
    catch (std::bad_alloc) {
        std::cout << "Izuzetak: Alokacija nije uspjela!" << std::endl;
    }
    catch (...) {
        std::cout << "Izuzetak: Alokacija nije uspjela!" << std::endl;
    }
	return 0;
}
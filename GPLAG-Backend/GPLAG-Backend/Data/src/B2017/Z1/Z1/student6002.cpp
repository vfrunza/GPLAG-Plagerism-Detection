#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef std::vector<int> Vektor;

bool DaLiJeProst (int a)
{
    if (a == 0 || a == 1 )return false;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

Vektor Ternarni(int a)
{
    Vektor b;
    while(a != 0) {
        int broj = a % 3;
        b.push_back(broj);
        a /= 3;
    }
    return b;
}

bool SimetricniTernarniBrojevi(Vektor a)
{
    Vektor b, c;
    b = a;
    c = a;
    reverse(c.rbegin(), c.rend());

    for (int i = 0; i <a.size(); i++) {
        if(b.at(i) != c.at(i)) return false;
    }
    return true;
}

Vektor IzdvojiSimetricneTernarne (Vektor a, bool Pokusaj)
{
    Vektor c, d, e;
    bool  N, b;
    for (int i = 0; i < a.size()-1; i++) {
        b = DaLiJeProst(a.at(i));
        if (b == true) {
            c = Ternarni(a.at(i));
            N = SimetricniTernarniBrojevi(c);
        }
        if (b == false) {
            c = Ternarni(a.at (i));
            N = SimetricniTernarniBrojevi(c);
        }
        if(b== true && N == true)d.push_back(a.at(i));
        else if (b == false && N == true) e.push_back(a.at(i));
    }
    if (Pokusaj == false) {
        d.empty();
        return e;
    } else {
        e.empty();
        return d;
    }
}

int main ()
{
    Vektor a;
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    int broj;
    do {
        std::cin >> broj;
        a.push_back(broj);
    } while (broj != -1);
    int i = 0;
    bool T;
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    std::cin>> T;
    if (!(std::cin)) {
        std::cout << "Neispravan unos! Unesite ponovo: ";
        std::cin.clear();
        std::cin.ignore(10000, ' ');
    }
    std::cin>> T;
    Vektor Rjesenje = IzdvojiSimetricneTernarne(a,T);
    if(!(Rjesenje.empty())) {
        if (T == 1) std::cout << "Prosti simetricni brojevi iz vektora su: ";
        else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
        for (int i = 0; i < Rjesenje.size(); i++) {
            if (i == Rjesenje.size()-1) std::cout << Rjesenje.at (i) << ".";
            else std::cout << Rjesenje.at(i) << ", ";
        }
    } else {
        if(T==1) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
        else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
    }
    return 0;
}
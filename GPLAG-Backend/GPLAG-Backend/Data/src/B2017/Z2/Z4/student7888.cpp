#include <stdexcept>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>
#include <iostream>

// pomocna funkcija provjerava je li prirodan broj prost
bool DaLiJeProst (int n) {
    bool djeljiv(true);
    if (n<0) n=n*(-1);
    if (n<=1) return false;
    for (int i=2; i<(n/2)+1; i++) {
        if (n%i==0) return false;
        if (i==n-1) break;
    }
    return djeljiv;
}

// pomocna funkcija prebrojava proste faktore u broju
int BrojFaktora (int n) {
    int brojac(0);
    int t=n;
    for (int i=2; i<(n/2)+1; i++) {
        if (DaLiJeProst(i)==1 and t%i==0) {
            t=t/i;
            i=1;
            brojac++;
        }
        if (i==n-1) break;
    }
    return brojac;
}

// pomocna funkcija realizuje kriterij odredjen za main u tekstu zadatka
bool Kriterij (int x, int y) {
    int a=BrojFaktora(x);
    int b=BrojFaktora(y);
    if (a!=b) return a>b;
    else return x>y;
}

// pomocna funkcija realizuje funkciju odredjenu za main u tekstu zadatka
int TestnaFunkcija (int x, int y) {
    int z=(-2)*x+y;
    return z;
}

template <typename Tip1, typename Tip2, typename Tip3, typename TipFun1, typename TipFun2>
void SortirajPodrucjeVrijednosti (Tip1 p1, Tip1 p2, Tip2 p3, Tip3 p4, TipFun1 f1, TipFun2 f2) {
    int n=(p2-p1), znak(0);
    std::sort(p1, p2, Kriterij);
    std::sort(p3, p3+n, Kriterij);
    // prolazimo petljom kroz blokove iza p1 i p3
    for (int i=0; i<n; i++) {
        znak=0;
        auto z=f1(*(p1+i), *(p3+i));
        for (int j=0; j<n; j++) {
            // vrsimo zamjenu mjesta elemenata
            if (z==*(p4+j)) {
                auto temp=*(p4+i);
                *(p4+i)=*(p4+j);
                *(p4+j)=temp;
                znak=1;
            }
            if (j==n-1) break;
        }
        if (znak==0) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
        if (i==n-1) break;
    }
}

int main ()
{
    try {
        int n, k, znak=0;
        std::vector<int> jedan, dva, tri;
        std::cout << "Unesite broj elemenata: ";
        std::cin >> n;
        std::cout << "Unesite elemente prvog vektora: ";
        for (int i=0; i<n; i++) {
            std::cin >> k;
            znak=0;
            for (int j=0; j<i; j++) {
                if (k==jedan.at(j)) znak=1;
            }
            if (znak==1) {
                i--;
                continue;
            }
            else jedan.push_back(k);
        }
        std::cout << "Unesite elemente drugog vektora: ";
        for (int i=0; i<n; i++) {
            std::cin >> k;
            znak=0;
            for (int j=0; j<i; j++) {
                if (k==dva.at(j)) znak=1;
            }
            if (znak==1) {
                i--;
                continue;
            }
            else dva.push_back(k);
        }
        std::cout << "Unesite elemente treceg vektora: ";
        for (int i=0; i<n; i++) {
            std::cin >> k;
            znak=0;
            for (int j=0; j<i; j++) {
                if (k==tri.at(j)) znak=1;
            }
            if (znak==1) {
                i--;
                continue;
            }
            else tri.push_back(k);
        }
        SortirajPodrucjeVrijednosti(std::begin(jedan), std::end(jedan), std::begin(dva), std::begin(tri), TestnaFunkcija, Kriterij);
        std::cout << "\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
        for (int i=0; i<n; i++) std::cout << "f(" << *(std::begin(jedan)+i) << ", " << *(std::begin(dva)+i) << ") = " << *(std::begin(tri)+i) << std::endl;
    }
    catch (std::logic_error izuzetak) {
        std::cout << std::endl << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    return 0;
}
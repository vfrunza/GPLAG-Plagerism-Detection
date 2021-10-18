#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <cmath>
#include <vector>

template <typename ItTip>
int BrojElemenata(ItTip it1, ItTip it2) {
    int br_el(0);
    while (it1++ != it2) br_el++;
    return br_el;
}

template <typename ItTip1, typename ItTip2, typename ItTip3, typename FunTip1, typename FunTip2>
void SortirajPodrucjeVrijednosti (ItTip1 p1, ItTip1 p2, ItTip2 q1, ItTip3 r1, FunTip1 Funkcija, FunTip2 Poredak)
   /* typename std::remove_reference<decltype(*r1)>::type Funkcija (typename std::remove_reference<decltype(*p1)>::type, typename std::remove_reference<decltype(*p1)>::type), 
    bool Poredak (typename std::remove_reference<decltype(*p1)>::type, typename std::remove_reference<decltype(*p1)>::type))*/ {
    
    int br_el(BrojElemenata(p1, p2));
    ItTip2 q2(q1);
    for (int i = 0; i < br_el; i++) q2++;
    ItTip3 r2(r1);
    for (int i = 0; i < br_el; i++) r2++;
    std::sort(p1, p2, Poredak);
    std::sort(q1, q2, Poredak); // moguca greska
    auto kopija_p1(p1);
    auto kopija_q1(q1);
    while (kopija_p1 != p2) {
        if (std::find(r1, r2, Funkcija(*kopija_p1, *kopija_q1)) == r2) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
        kopija_p1++; kopija_q1++;
    }
    std::transform(p1, p2, q1, r1, Funkcija);
}

bool DaLiJeProst(int a) {
    if (a < 2) return false;
    for (int i = 2; i <= int(sqrt(a)); i++)
        if (a % i == 0) return false;
    return true;
}

int BrojProstihFaktora(int x) {
    int br(0);
    for (int i = 0; i < x; i++) 
        if (DaLiJeProst(i) && x % i == 0) {
            br += 1 + BrojProstihFaktora(x/i);
            break;
        }
    return br;
}

void Unos(std::vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        int x;
        std::cin >> x;
        for (int j = 0; j < i; j++) 
            if (v[j] == x) {
                std::cin >> x;
                j = -1;
            }
        v[i] = x;
    }
}

int main ()
{
    try {
        int n;
        std::cout << "Unesite broj elemenata: ";
        std::cin >> n;
        std::vector<int> v1(n), v2(n), v3(n);
        std::cout << "Unesite elemente prvog vektora: ";
        Unos(v1);
        std::cout << "Unesite elemente drugog vektora: ";
        Unos(v2);
        std::cout << "Unesite elemente treceg vektora: " << std::endl;
        Unos(v3);
        SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](int x, int y) -> int { return (-2) * x + y; },
            [](int x, int y) -> bool { if (BrojProstihFaktora(x) == BrojProstihFaktora(y)) return x > y; return BrojProstihFaktora(x) > BrojProstihFaktora(y); } );
        std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
        for (int i = 0; i < v1.size(); i++) 
            std::cout << "f(" << v1[i] << ", " << v2[i] << ") = " << v3[i] << std::endl;
    }
    catch (std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije";
    }
        
	return 0;
}
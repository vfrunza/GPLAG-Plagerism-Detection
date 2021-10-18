#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <cmath>
using std::vector;

template<typename A, typename B, typename C>
void SortirajPodrucjeVrijednosti(A start, A kraj, B start2, C start3,
typename std::remove_reference<decltype(*start3)>::type f(typename std::remove_reference<decltype(*start)>::type,
typename std::remove_reference<decltype(*start2)>::type),
bool f2(typename std::remove_reference<decltype(*start)>::type, typename std::remove_reference<decltype(*start2)>::type))
{
    B y(start2), kraj2(start2);
    C kraj3(start3);
    for (A i(start); i != kraj; i++, kraj2++, kraj3++);
    std::sort(start, kraj, f2);
    std::sort(start2, kraj2, f2);
    for (A x(start); x != kraj; x++, y++)
    {
        for (C z(start3); z != kraj3; z++)
            if (f(*x, *y) == *z) goto preskok;
        throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
        preskok:;
    }
    y = start2;
    C u(start3);
    for (A x(start); x != kraj; x++, y++, u++)
        for (C z(start3); z != kraj3; z++)
            if (f(*x, *y) == *z) std::swap(*z, *u);
}
int f(int x, int y) { return y - 2 * x; }
bool prost(int x)
{
    if (x == 1 || x == -1 || x == 0) return false;
    int u = std::round(std::sqrt(abs(double(x))));
    for (int i(2); i <= u; i++)
        if (x % i == 0) return false;
    return true;
}
int br_prostih(int x)
{
    for (int i(2); i < x; i++)
        if (prost(i) && x % i == 0) return 1 + br_prostih(x / i);
    return x > 1;
}
bool kriterij(int x, int y)
{
    int a(br_prostih(x)), b(br_prostih(y));
    return a > b || (a == b && x > y);
}
bool sadrzi(vector<int> &v, int x) { return std::find(v.begin(), v.end(), x) != v.end(); }

int main()
{
    int n, x;
    std::cout << "Unesite broj elemenata: ";
    std::cin >> n;
    vector<int> v1, v2, v3;
    std::cout << "Unesite elemente prvog vektora: ";
    for (int i(0); i < n; i++)
        if (!sadrzi(v1, (std::cin >> x, x))) v1.push_back(x);
        else i--;
    std::cout << "Unesite elemente drugog vektora: ";
    for (int i(0); i < n; i++)
        if (!sadrzi(v2, (std::cin >> x, x))) v2.push_back(x);
        else i--;
    std::cout << "Unesite elemente treceg vektora: ";
    for (int i(0); i < n; i++)
        if (!sadrzi(v3, (std::cin >> x, x))) v3.push_back(x);
        else i--;
    try
    {
        SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), f, kriterij);
        std::cout << "\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:";
        for (int i(0); i < n; i++)
            std::cout << "\nf(" << v1.at(i) << ", " << v2.at(i) << ") = " << f(v1.at(i), v2.at(i));
    }
    catch (std::logic_error e) { std::cout << "\nIzuzetak: " << e.what(); }
    catch (...) {}
	return 0;
}
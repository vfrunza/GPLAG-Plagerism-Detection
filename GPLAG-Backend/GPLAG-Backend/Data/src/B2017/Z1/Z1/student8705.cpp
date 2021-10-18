#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

bool prost(int x)
{
    if (x == 1 || x == -1 || x == 0) return false;
    int u = std::round(std::sqrt(x >= 0 ? x : -x));
    for (int i(2); i <= u; i++)
        if (x % i == 0) return false;
    return true;
}
bool simetrican(int x)
{
    int y(0), t(x);
    do y = y * 3 + t % 3;
    while (t /= 3);
    return x == y;
}
vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool f)
{
    vector<int> u;
    for (int el : v)
        if (el != 1 && el != -1 && prost(el) == f && simetrican(el))
        {
            int j(0);
            for (; j < u.size(); j++)
                if (u.at(j) == el) break;
            if (j == u.size())
                u.push_back(el);
        }
    return u;
}
int main()
{
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    int x;
    vector<int> v;
    while (std::cin >> x && x != -1)
        v.push_back(x);
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    while (!(std::cin >> x) || (x != 0 && x != 1))
    {
        std::cout << "Neispravan unos! Unesite ponovo: ";
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    v = IzdvojiSimetricneTernarne(v, x);
    if (!v.size())
        std::cout << "Nema " << (x ? "prostih" : "slozenih") << " simetricnih brojeva u vektoru.";
    else
    {
        std::cout << (x ? "Prosti" : "Slozeni") << " simetricni brojevi iz vektora su: " << v.at(0);
        for (int i(1); i < v.size(); i++)
            std::cout << ", " << v.at(i);
        std::cout << '.';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <deque>
using std::vector;

enum Smjer { Rastuci, Opadajuci };

bool stepen_dvojke(int x)
{
    return x >= 1 && !(x & (x-1));
}
std::deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer smjer)
{
    std::deque<vector<int>> dek;
    for (int i(0); i < v.size(); i++)
        if (stepen_dvojke(v.at(i)))
        {
            vector<int> u{v.at(i)};
            int j(i+1);
            for (; j < v.size(); j++)
                if ((smjer == Rastuci ? v.at(j) >= v.at(j-1) : v.at(j) <= v.at(j-1)) && stepen_dvojke(v.at(j)))
                    u.push_back(v.at(j));
                else break;
            if (u.size() > 1)
                dek.push_back(u);
            i = j-1;
        }
    return dek;
}
int main()
{
    int n, x;
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    vector<int> v(n);
    for (int i(0); i < n; i++)
        std::cin >> v.at(i);
    std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin >> x;
    std::cout << "Maksimalni " << (x == 1 ? "rastuci" : "opadajuci") << " podnizovi: ";
    for (auto v : MaksimalniPodnizoviStepenaDvojke(v, x == 1 ? Rastuci : Opadajuci))
    {
        std::cout << '\n';
        for (int i : v)
            std::cout << i << ' ';
    }
	return 0;
}
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename T>
auto IzdvojiDijagonale3D (T kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype (kont.at(0))>::type
    {
        typename std::remove_reference<decltype (kont.at(0))>::type rez;
        size_t x = kont.size(), y = 0, z = 0;
        if (x) y = kont.at(0).size();
        if (y) z = kont.at(0).at(0).size();
        for (size_t i = 0; i < x; ++i)
            {
                for (size_t j = 0; j < kont.at(i).size(); ++j)
                    if (kont.at(i).at(j).size() != z)
                        throw std::domain_error ("Redovi nemaju isti broj elemenata");
                if (kont.at(i).size() != y)
                    throw std::domain_error ("Plohe nemaju isti broj redova");
            }
        size_t sk = (size_t)smjer, mat[][3] = {
                {x, y, z}, //NaprijedNazad, NazadNaprijed
                {y, x, z}, //GoreDolje, DoljeGore
                {z, y, x}  //LijevoDesno, DesnoLijevo
            }, dim = std::min(mat[sk / 2][1], mat[sk / 2][2]);
        for (size_t i = 0; i < mat[sk / 2][0]; ++i)
            {
                typename std::remove_reference<decltype (kont.at(0).at(0))>::type dijagonala;
                bool ima = false;
                for (size_t j = 0; j < dim; ++j)
                    {
                        ima = true;;
                        size_t m[][3] = {
                            {i, j, j},
                            {x - i - 1, j, z - j - 1},
                            {x - j - 1, i, j},
                            {x - j - 1, y - i - 1, z - j - 1},
                            {x - j - 1, j, i},
                            {j, j, z - i - 1},
                        }, i1 = m[sk][0], i2 = m[sk][1], i3 = m[sk][2];
                        dijagonala.push_back (kont.at(i1).at(i2).at(i3));
                    }
                if (ima)
                    rez.push_back (dijagonala);
            }
        return rez;
    }
int main()
{
    std::cout << "Unesite dimenzije (x y z): ";
    int x, y, z; std::cin >> x >> y >> z;
    if (x < 0 || y < 0 || z < 0)
        return std::cout << "Neispravne dimenzije kontejnera!" << std::endl, 1;
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    std::vector<std::deque<std::deque<int>>> kont (x,
                std::deque<std::deque<int>> (y, std::deque<int> (z)));
    for (auto &m : kont)
        for (auto &v : m)
            for (auto &e : v)
                std::cin >> e;
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int s; std::cin >> s;
    if (s < 0 || s > 5)
    {
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;;
        return 0;
    }
    std::deque<std::deque<int>> m;
    try {m = IzdvojiDijagonale3D(kont, (SmjerKretanja)s);}
    catch (const std::domain_error &e) {std::cout << "Izuzetak: " << e.what(); return 1;}
    const char *n[] = {"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};
    std::cout << n[s] << ": " << std::endl;
    for (const auto &red : m)
    {
        for (const auto &x : red)
            std::cout.width (4), std::cout << x;
        std::cout << std::endl;
    }
    return 0;
}

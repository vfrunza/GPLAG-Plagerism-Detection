#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
//Provjereno, poslano.
enum class Boje { Pik, Tref, Herc, Karo };
typedef std::list<std::pair<Boje, std::string>> Spil;
std::string _karte_[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
std::string _boje_[4]{"Pik", "Tref", "Herc", "Karo"};
bool manji(const std::pair<Boje, std::string> &a, const std::pair<Boje, std::string> &b)
{
    return int(a.first) < int(b.first) || (a.first == b.first && std::find(_karte_, _karte_+13, a.second) < std::find(_karte_, _karte_+13, b.second));
}
void provjeri_spil(Spil &spil)
{
    if (spil.empty()) return;
    auto i(spil.begin());
    if (spil.size() > 52 || std::find(_karte_, _karte_+13, i->second) == _karte_+13) throw std::logic_error("Neispravna lista!");
    for (auto j(i); ++j != spil.end(); ++i)
        if (std::find(_karte_, _karte_+13, j->second) == _karte_+13 || manji(*j, *i) || *j == *i) throw std::logic_error("Neispravna lista!");
}
Spil KreirajSpil()
{
    Spil spil;
    for (int i(0); i < 4; ++i)
        for (int j(0); j < 13; ++j)
            spil.push_back({ Boje(i), _karte_[j] });
    return spil;
}
void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> &m)
{
    provjeri_spil(spil);
    for (auto i(spil.begin()); i != spil.end(); )
    {
        auto j(std::find(m.begin(), m.end(), std::pair<const Boje, std::string>(*i)));
        if (j != m.end())
        {
            i = spil.erase(i);
            auto x(*j);
            for (auto k(j = m.erase(j)); k != m.end() && (k = std::find(k, m.end(), x)) != m.end();) k = m.erase(k);
        }
        else ++i;
    }
}
std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Spil &spil, const short int &r, const int &b)
{
    if (r < 1 || r > 52 || b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    provjeri_spil(spil);
    std::queue<std::pair<std::string, std::string>> red;
    if (spil.empty()) return red;
    auto it(spil.begin());
    int pozicija(0), br(b);
    for (int i((r-1) % spil.size()); br > 0; --br, i = (i + r-1) % spil.size())
    {
        if (i > pozicija)
            for (; pozicija < i; ++pozicija) ++it;
        else if (i < pozicija)
            for (pozicija = 0, it = spil.begin(); pozicija < i; ++pozicija, ++it);
        red.push({ _boje_[int(it->first)], it->second });
        it = spil.erase(it);
        if (spil.empty()) break;
    }
    return red;
}
//?Kako provjeriti jesu li ispravne karte bez modifikacije reda, a bez koristenja pomocnih kontejnera?
void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    if (n < 0) throw std::domain_error("Broj n je besmislen!");
    else if (n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
    provjeri_spil(spil);
    for (int i(0); i < n; ++i)
    {
        if (std::find(_boje_, _boje_+4, red.front().first) == _boje_+4 || std::find(_karte_, _karte_+13, red.front().second) == _karte_+13)
            throw std::logic_error("Neispravne karte!");
        auto par(std::make_pair(Boje(std::find(_boje_, _boje_+4, red.front().first) - _boje_), red.front().second));
        if (std::find(spil.begin(), spil.end(), par) == spil.end())
            for (auto it(spil.begin()); ; ++it)
                if (it == spil.end() || manji(par, *it)) { spil.insert(it, par); break; }
        red.pop();
    }
}
void ispisi(const Spil &spil)
{
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
    auto it(spil.begin());
    for (int i(0); i < 4; ++i)
    {
        std::cout << '\n' << _boje_[i] << ':';
        for (; it != spil.end() && it->first == Boje(i); ++it) std::cout << ' ' << it->second;
    }
}
int main()
{
    int r, b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    try
    {
        Spil spil(KreirajSpil());
        auto izbacene(IzbaciKarteRazbrajanjem(spil, r, b));
        ispisi(spil);
        std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
        std::cin >> b;
        VratiPrvihNKarata(spil, izbacene, b);
        ispisi(spil);
    }
    catch (const std::exception &e) { std::cout << "Izuzetak: " << e.what(); }
    catch (...) {}
	return 0;
}
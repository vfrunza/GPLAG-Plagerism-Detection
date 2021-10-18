#include <iostream>
#include <utility>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <algorithm>
//Provjereno koliko je bilo moguce, jos uvijek postoje nedoumice, poslano.
//?Da li se prilikom unosa razlikuju velika i mala slova
typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> _Indeks_;
std::string &sljedeca_rijec(const std::vector<std::string> &v, int &i, int &j, std::string &s)
{
    for (; i < v.size(); ++i, j = 0)
        for (; j < v.at(i).length(); ++j)
            if ((j == 0 || !std::isalnum(v.at(i).at(j-1))) && std::isalnum(v.at(i).at(j)))
                for (;; s += std::tolower(v.at(i).at(j)), ++j)
                    if (j == v.at(i).length() || !std::isalnum(v.at(i).at(j))) return s;
    return s;
}
_Indeks_ KreirajIndeksPojmova(const Knjiga &k)
{
    _Indeks_ mapa;
    for (const auto &p : k)
    {
        int i(0), j(0);
        for (std::string s; sljedeca_rijec(p.second, i, j, s).length(); s.resize(0))
            mapa[s].insert(decltype(*mapa[s].begin()) { p.first, i+1, j - s.size() });
    }
    return mapa;
}
//?Da li se pretpostavlja da kljucna polja indeksa sadrze samo mala slova
std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(const std::string &s, const _Indeks_ &ind)
{
    for (auto &p : ind)
        if (p.first.length() == s.length() && std::equal(s.begin(), s.end(), p.first.begin(), [](char a, char b) {
            return std::tolower(a) == std::tolower(b); 
        })) return p.second;
    throw std::logic_error("Pojam nije nadjen");
}
//?Kako treba ispisati newline
void IspisiIndeksPojmova(const _Indeks_ &ind)
{
    for (const auto &el : ind)
    {
        std::cout << (&el != &*ind.begin() ? "\n" : "") << el.first << ": ";
        for (auto it(el.second.begin()); it != el.second.end(); it++)
            std::cout << (it != el.second.begin() ? ", " : "") << std::get<0>(*it) << '/' << std::get<1>(*it) << '/' << std::get<2>(*it);
    }
}
int main()
{
    Knjiga k;
    std::string s, t;
    while (std::cout << "Unesite naziv poglavlja: ", std::getline(std::cin, s), s != ".")
        for (int i(0); std::cout << "Unesite sadrzaj stranice " << i+1 << ": ", std::getline(std::cin, t), t != "."; i++)
            k[s].push_back(t);
    _Indeks_ ind(KreirajIndeksPojmova(k));
    std::cout << "\nKreirani indeks pojmova:\n";
    IspisiIndeksPojmova(ind);
    while (std::cout << "\nUnesite rijec: ", std::getline(std::cin, s), s != ".")
        try { for (auto &el : PretraziIndeksPojmova(s, ind)) std::cout << std::get<0>(el) << '/' << std::get<1>(el) << '/' << std::get<2>(el) << ' '; }
        catch (...) { std::cout << "Unesena rijec nije nadjena!"; }
	return 0;
}
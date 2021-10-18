#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
#include <fstream>
typedef std::map<std::string, std::set<int>> Mapa;
Mapa KreirajIndeksPojmova (const std::string &s)
    {
        Mapa m;
        auto tolow = [] (char x) {return x >= 'A' && x <= 'Z' ? x + 32 : x;};
        auto word = [&tolow](char x){return tolow(x) >= 'a' && tolow(x) <= 'z' || x >= '0' && x <= '9';};
        int i = 0, d = s.size(), r = 1;
        while (i < d)
        {
            if (!word (s.at(i))) r = 1;
            else if (r)
            {
                r = 0;
                int x = i;
                std::string v;
                while (x < d && word (s.at(x))) v += tolow(s.at(x++));
                m[v].insert(i);
            }
            ++i;
        }
        return m;
    }
std::set<int> PretraziIndeksPojmova (std::string s, const Mapa &m)
    {
        for (char &c : s) if (c >= 'A' && c <= 'Z') c += 32;
        if (m.count(s))
            return m.find(s)->second;
        throw std::domain_error ("Pojam nije nadjen");
    }
void IspisiIndeksPojmova (const Mapa &m)
    {
        for (auto i = m.cbegin(); i != m.cend() && (std::cout << i->first << ": "); ++i, std::cout << std::endl)
            for (auto k = i->second.cbegin(); k != i->second.cend() && (std::cout << *k); )
                if (++k != i->second.end())
                    std::cout << ",";
    }

std::streambuf *Redirect (const char *ime)
{
    static std::ofstream out(ime);
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    return coutbuf;
}


template<class F, class R, class ...T>
class EoN;
template<class F, class R, class ...T>
class EoN<F, R (T...)>
{
    F *f;
    mutable bool pozvana;
    public:
    EoN (F *f) : f(f), pozvana (false) {}
    R operator()(T && ...t) const 
        {
            if (!f) throw "Funkcija nije dodijeljena";
            pozvana = true;
            return (*f)(std::forward<T> (t)...);
        }
    bool JelPozvana() const {return pozvana;}
};
void Ispisi(std::string sta) {std::cout << "Ispisah: " << sta << std::endl;;}
/*
    EoN<decltype(Ispisi), void (std::string)> e (Ispisi);
    e("hehe");
    std::cout << "Pozvana: " << e.JelPozvana();

*/
inline int _main() __attribute__((always_inline));
inline int _main()
{
    std::cout << "Unesite tekst: ";
    std::string s; std::getline (std::cin, s);
    Mapa m = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    while (std::cout << "Unesite rijec: ", std::getline(std::cin, s), s != ".")
        try {auto x = PretraziIndeksPojmova(s, m); for (const auto &i : x) std::cout << i << " "; std::cout << std::endl;}
        catch (const std::logic_error &) {std::cout << "Unesena rijec nije nadjena!" << std::endl;}
    return 0;
}
#if 1
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
bool pozvana_ispisi = false, pozvana_kreiraj = false, pozvana_pretrazi = false;
void AT17_Ispisi (const std::map<std::string, std::set<int>> &mapa)
    { 
        pozvana_ispisi = true;
        return IspisiIndeksPojmova(mapa);
    }
std::map<std::string, std::set<int>> AT17_Kreiraj (std::string s)
    {
        pozvana_kreiraj = true; 
        return KreirajIndeksPojmova(s);
    }
std::set<int> AT17_Pretrazi (std::string s, const std::map<std::string, std::set<int>> &mapa)
    {
        pozvana_pretrazi = true;
        return PretraziIndeksPojmova(s, mapa);
    }
#define IspisiIndeksPojmova AT17_Ispisi
#define KreirajIndeksPojmova AT17_Kreiraj
#define PretraziIndeksPojmova AT17_Pretrazi

#endif 
int main()
{
    //Redirect("AT18.txt");
    _main();
    std::cin.clear();
    std::cout << std::boolalpha
              << "Pozvana IspisiIndeksPojmova: " << pozvana_ispisi << std::endl
              << "Pozvana PretraziIndeksPojmova: " << pozvana_pretrazi << std::endl
              << "Pozvana KreirajIndeksPojmova: " << pozvana_kreiraj << std::endl;
    
}

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <functional>
template <typename T>
class DatotecniKontejner
{
    std::fstream tok;
public:
    DatotecniKontejner(const std::string &ime);
    void DodajNoviElement(const T &element);
    int DajBrojElemenata();
    T DajElement(int pozicija);
    void IzmijeniElement(int pozicija, const T &element);
    void Sortiraj(std::function<bool(const T &, const T &)> kriterij = std::less<T>());
};

template <typename T>
DatotecniKontejner<T>::DatotecniKontejner(const std::string &ime)
{
    tok.open(ime, std::ios::binary | std::ios::in);
    if (!tok)
    {
        tok.clear(); tok.close();
        tok.open(ime, std::ios::binary | std::ios::out);
        if (!tok) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
    }
    tok.close();
    tok.open(ime, std::ios::binary | std::ios::out | std::ios::in);
    if (!tok)  throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
}
//?Probemi ili Problemi
template <typename T>
void DatotecniKontejner<T>::DodajNoviElement(const T &element)
{
    tok.seekp(0, std::ios::end);
    tok.write(reinterpret_cast<const char*>(&element), sizeof(T));
    tok.flush();
    if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
}
template <typename T>
int DatotecniKontejner<T>::DajBrojElemenata()
{
    tok.seekg(0, std::ios::end);
    int n(tok.tellg() / int(sizeof(T)));
    if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
    return n;
}

template <typename T>
T DatotecniKontejner<T>::DajElement(int pozicija)
{
    if (pozicija < 0 || pozicija >= DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
    tok.seekg(pozicija * sizeof(T), std::ios::beg);
    T x;
    tok.read(reinterpret_cast<char*>(&x), sizeof(T));
    if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
    return x;
}
template <typename T>
void DatotecniKontejner<T>::IzmijeniElement(int pozicija, const T &element)
{
    if (pozicija < 0 || pozicija >= DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
    tok.seekp(pozicija * sizeof(T), std::ios::beg);
    tok.write(reinterpret_cast<const char*>(&element), sizeof(T));
    tok.flush();
    if (!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
}

template <typename T>
void DatotecniKontejner<T>::Sortiraj(std::function<bool(const T &, const T &)> kriterij)
{
    int vel(DajBrojElemenata());
    for (int i(0); i < vel; ++i)
    {
        T trenutni(DajElement(i)), min(trenutni);
        int novi{};
        for (int j(i+1); j < vel; ++j)
        {
            T el(DajElement(j));
            if (kriterij(el, min))
            {
                min = std::move(el);
                novi = j;
            }
        }
        if (kriterij(min, trenutni))
        {
            IzmijeniElement(i, min);
            IzmijeniElement(novi, trenutni);
        }
    }
}

int main()
{
    DatotecniKontejner<double> d("brojevi.bin");
    int br_el(d.DajBrojElemenata());
    for (;;) try
    {
        std::cout << "Odaberite opciju:\n"
        "1 - Ispis elemenata\n"
        "2 - Prikazi element\n"
        "3 - Novi elementi\n"
        "4 - Izmjena elementa\n"
        "5 - Sortiranje\n"
        "0 - Kraj\n";
        int o; std::cin >> o;
        switch (o)
        {
            case 1:
                std::cout << "Elementi: ";
                for (int i(0); i < br_el; ++i)
                    std::cout << d.DajElement(i) << ' ';
                break;
            case 2:
                std::cout << "Unesite indeks elementa: "; std::cin >> o;
                o = d.DajElement(o);
                std::cout << "Element: " << o;
                break;
            case 3:
                std::cout << "Unesite broj elemenata: "; std::cin >> o;
                std::cout << "Unesite elemente: ";
                br_el += o;
                for (int i(0), x; i < o; ++i)
                    d.DodajNoviElement((std::cin >> x, x));
                break;
            case 4:
            {
                double x;
                std::cout << "Unesite indeks elementa: "; std::cin >> o;
                std::cout << "Unesite novu vrijednost: "; std::cin >> x;
                d.IzmijeniElement(o, x);
                break;
            }
            case 5:
                d.Sortiraj();
                break;
            case 0 : return 0;
        }
        std::cout << '\n';
    }
    catch (const std::exception &e) { std::cout << "Izuzetak: " << e.what() << '\n'; }
	return 0;
}

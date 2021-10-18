/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <utility>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
#include <iterator>

class Temperature
{
    std::list<int> minimalne, maksimalne;
    int min_moguca, max_moguca;
    void JeLiPremaseno(const std::list<int> &minimalne, const std::list<int> &maksimalne);
public:
    Temperature(int min_moguca, int max_moguca);
    void RegistrirajTemperature(const std::pair<int, int> &temperature);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura(){ return minimalne.size();};
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTemperaturu();
    int DajBrojTemperaturaVecihOd(int temperatura);
    int DajBrojTemperaturaManjihOd(int temperatura);
    bool operator!()const{ return !minimalne.size();}
    Temperature &operator++();
    Temperature operator++(int);
    Temperature &operator--();
    Temperature operator--(int);
    std::vector<int> operator*()const;
    std::vector<int> operator+()const;
    std::vector<int> operator-()const;
    std::pair<int, int> operator[](int i)const;
    Temperature &operator+=(int x);
    friend Temperature operator+(const Temperature &t, int x);
    inline friend Temperature operator+(int x, const Temperature &t){ return t + x;}
    Temperature &operator-=(int x);
    friend Temperature operator-(const Temperature &t, int x);
    friend Temperature operator-(int x, const Temperature &t);
    friend bool operator==(const Temperature &t1, const Temperature &t2){
        return t1.min_moguca == t2.min_moguca && t1.max_moguca == t2.max_moguca && t1.minimalne == t2.minimalne && t1.maksimalne == t2.maksimalne;
    }
    friend bool operator!=(const Temperature &t1, const Temperature &t2){ return !(t1 == t2);}
    friend std::ostream &operator << (std::ostream &tok, const Temperature &t);
};
void Temperature::JeLiPremaseno(const std::list<int> &minimalne, const std::list<int> &maksimalne)
{
    std::vector<bool> v(minimalne.size());
    std::transform(minimalne.begin(), minimalne.end(), maksimalne.begin(), v.begin(), std::equal_to<int>());
    if (std::count(v.begin(), v.end(), true))
        throw std::logic_error("Ilegalna operacija");
}
Temperature::Temperature(int min_moguca, int max_moguca)
{
    if (min_moguca > max_moguca)
        throw std::range_error("Nekorektne temperature");
}
void Temperature::RegistrirajTemperature(const std::pair<int, int> &temperature)
{
    if (temperature.first > temperature.second || temperature.first < min_moguca || temperature.second > max_moguca)
        throw std::range_error("Nekorektne temperature");
    minimalne.push_back(temperature.first);
    minimalne.push_back(temperature.second);
}
void Temperature::BrisiSve()
{
    minimalne.erase(minimalne.begin(), minimalne.end());
    maksimalne.erase(maksimalne.begin(), minimalne.end());
}
void Temperature::BrisiNegativneTemperature()
{
    auto max_neg(std::find_if(maksimalne.begin(), maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, 0)));
    if (max_neg != maksimalne.end())
    {
        auto min_neg(minimalne.begin());
        for (int i = 0; i< std::distance(max_neg, maksimalne.begin()); i++)
            min_neg++;
        minimalne.erase(min_neg);
        maksimalne.erase(max_neg);
        BrisiNegativneTemperature();
    }
}
int Temperature::DajMinimalnuTemperaturu()
{
    if (!minimalne.size())
        throw std::logic_error("Nema registriranih temperatura");
    int od_minimalnih (*std::min_element(minimalne.begin(), maksimalne.end()));
    int od_maksimalnih(*std::min_element(maksimalne.begin(), maksimalne.end()));
    if (od_minimalnih < od_maksimalnih)
        return od_minimalnih;
    else return od_maksimalnih;
}
int Temperature::DajMaksimalnuTemperaturu()
{
    if (!minimalne.size())
        throw std::logic_error("Nema registriranih temperatura");
    int od_minimalnih(*std::max_element(minimalne.begin(), minimalne.end()));
    int od_maksimalnih(*std::max_element(maksimalne.begin(), minimalne.end()));
    if (od_minimalnih > od_maksimalnih)
        return od_minimalnih;
    else return od_maksimalnih;
}
int Temperature::DajBrojTemperaturaVecihOd(int temperatura)
{
    if (!minimalne.size())
        throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, temperatura)) + 
           std::count_if(maksimalne.begin(), maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, temperatura));
}
int Temperature::DajBrojTemperaturaManjihOd(int temperatura)
{
    if (!minimalne.size())
        throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, temperatura)) + 
           std::count_if(maksimalne.begin(), minimalne.begin(), std::bind(std::less<int>(), std::placeholders::_1, temperatura));
}
Temperature &Temperature::operator++()
{
    if (std::count(minimalne.begin(), minimalne.end(), max_moguca))
        throw std::logic_error("Ilegalna operacija");
    JeLiPremaseno(minimalne, maksimalne);
    std::transform(minimalne.begin(), minimalne.end(), minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return *this;
}
Temperature Temperature::operator++(int)
{
    if (std::count(minimalne.begin(), minimalne.end(), max_moguca))
        throw std::logic_error("Ilegalna operacija");
    JeLiPremaseno(minimalne, maksimalne);
    Temperature pomocne(*this);
    std::transform(minimalne.begin(), minimalne.end(), minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return pomocne;
}
Temperature &Temperature::operator--()
{
    if (std::count(maksimalne.begin(), maksimalne.end(), min_moguca))
        throw std::logic_error("Ilegalna operacija");
    JeLiPremaseno(minimalne, maksimalne);
    std::transform(maksimalne.begin(), maksimalne.end(), maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return *this;
}
Temperature Temperature::operator--(int)
{
    if (std::count(maksimalne.begin(), maksimalne.end(), min_moguca))
        throw std::logic_error("Ilegalna operacija");
    JeLiPremaseno(minimalne, maksimalne);
    Temperature pomocne(*this);
    std::transform(maksimalne.begin(), maksimalne.end(), maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return pomocne;
}
std::vector<int> Temperature::operator*()const
{
    std::vector<int> razlike(minimalne.size());
    std::transform(minimalne.begin(), minimalne.end(), maksimalne.begin(), razlike.begin(), std::minus<int>());
    return razlike;
}
std::vector<int> Temperature::operator+()const
{
    std::vector<int> razlike(maksimalne.size());
    std::transform(maksimalne.begin(), maksimalne.end(), razlike.begin(), std::bind(std::minus<int>(), max_moguca, std::placeholders::_1));
    return razlike;
}
std::vector<int> Temperature::operator-()const
{
    std::vector<int> razlike(minimalne.size());
    std::transform(minimalne.begin(), minimalne.end(), razlike.begin(), std::bind(std::minus<int>(), std::placeholders::_1, min_moguca));
    return razlike;
}
std::pair<int, int> Temperature::operator[](int i)const
{
    if (i < 1 || i > minimalne.size())
        throw std::range_error("Neispravan indeks");
    std::vector<int> minimalne2(minimalne.size()), maksimalne2(maksimalne.size());
    std::copy(minimalne.begin(), minimalne.end(), minimalne2.begin());
    std::copy(maksimalne.begin(), maksimalne.end(), maksimalne2.begin());
    return std::pair<int, int>(minimalne2[i - 1], maksimalne2[i - 1]);
}
Temperature &Temperature::operator+=(int x)
{
    *this = *this + x;
    return *this;
}
Temperature operator +(const Temperature &t, int x)
{
    if (std::count_if(t.maksimalne.begin(), t.maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, t.max_moguca - x)) || std::count_if(t.minimalne.begin(), t.minimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, t.max_moguca - x)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura"); 
    Temperature t2(t);
    std::transform(t2.minimalne.begin(), t2.minimalne.end(), t2.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    std::transform(t2.maksimalne.begin(), t2.maksimalne.end(), t2.maksimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    return t2;
}
Temperature &Temperature::operator-=(int x)
{
    *this = *this - x;
    return *this;
}
Temperature operator -(const Temperature &t, int x)
{
    if (std::count_if(t.maksimalne.begin(), t.maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, t.min_moguca + x)) || std::count_if(t.minimalne.begin(), t.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, t.min_moguca + x)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    Temperature t2(t);
    std::transform(t2.minimalne.begin(), t2.minimalne.end(), t2.minimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    std::transform(t2.maksimalne.begin(), t2.maksimalne.end(), t2.maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    return t2;
}
Temperature operator-(int x, const Temperature &t)
{
    Temperature t2(t);
    std::transform(t2.minimalne.begin(), t2.minimalne.end(), t2.minimalne.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    std::transform(t2.maksimalne.begin(), t2.maksimalne.end(), t2.maksimalne.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    std::swap(t2.minimalne, t2.maksimalne);
    if (std::count_if(t2.maksimalne.begin(), t2.maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, t2.min_moguca)) || std::count_if(t2.minimalne.begin(), t2.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, t2.min_moguca)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t2;
}
std::ostream &operator <<(std::ostream &tok, const Temperature &t)
{
    std::copy(t.minimalne.begin(), t.minimalne.end(), std::ostream_iterator<int>(tok, " "));
    tok << std::endl;
    std::copy(t.maksimalne.begin(), t.maksimalne.end(), std::ostream_iterator<int>(tok, " "));
    return tok;
}

int main ()
{
	return 0;
}
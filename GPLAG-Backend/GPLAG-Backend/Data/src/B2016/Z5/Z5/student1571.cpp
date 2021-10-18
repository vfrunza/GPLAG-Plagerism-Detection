#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <list>
#include <stdexcept>
#include <vector>
#include <iterator>

class Temperature {
    std::list<int> minimalne, maximalne;
    public:
    Temperature (int min, int max);
    void RegistrirajTemperature (std::pair<int, int> vrijednosti);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajMaksimalnuTemperaturu() const;
    int DajMinimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd (int veci) const;
    int DajBrojTemperaturaManjihOd (int manji) const;
    friend bool operator! (const Temperature &p1);
    friend Temperature operator++ (Temperature &p1);
    friend Temperature operator++ (Temperature &temp, int n);
    friend Temperature operator-- (Temperature &p1);
    friend Temperature operator-- (Temperature &p1, int n);
    friend std::vector<int> operator* (const Temperature &p1);
    friend std::vector<int> operator+ (const Temperature &p1);
    friend std::vector<int> operator- (const Temperature &p1);
    std::pair<int,int> operator[] (int index);
    friend Temperature operator+ (const Temperature &p1, int n); //ubaciti izuzetke i ovo kasnije
    friend Temperature operator- (const Temperature &p1, int n);
    friend Temperature operator- (int n, const Temperature &p1);
    friend Temperature operator+ (int n, const Temperature &p1) { return p1 + n; }
    Temperature &operator+= (int x);
    Temperature &operator-= (int x);
    friend std::ostream &operator<< (std::ostream &tok, const Temperature &p1);
};
Temperature::Temperature (int min, int max) {
    if (min > max) throw std::range_error ("Nekorektne temperature");
    minimalne.push_back(min);
    maximalne.push_back(max);
}
void Temperature::RegistrirajTemperature (std::pair<int, int> vrijednosti) {
    if (vrijednosti.first > vrijednosti.second) throw std::range_error ("Nekorektne temperature");
    auto min = (minimalne.begin());
    auto max = (maximalne.begin());
    if (vrijednosti.first < *min || vrijednosti.second < *min || vrijednosti.first > *max || vrijednosti.second > *max)
            throw std::range_error ("Nekorektne temperature");
    minimalne.push_back (vrijednosti.first);
    maximalne.push_back (vrijednosti.second);
}
void Temperature::BrisiSve() {
    minimalne.erase (minimalne.begin(), minimalne.end());
    maximalne.erase (maximalne.begin(), maximalne.end());
}
void Temperature::BrisiNegativneTemperature() {
    std::cout << "NE RADI";

}
int Temperature::DajMaksimalnuTemperaturu() const {
    if (maximalne.size() == 0) throw std::logic_error ("Nema registriranih temperatura");
    auto it = std::max_element (maximalne.begin(), maximalne.end());
    return *it;
}
int Temperature::DajMinimalnuTemperaturu() const {
    if (minimalne.size() == 0) throw std::logic_error ("Nema registriranih temperatura");
    auto it = std::min_element (minimalne.begin(), minimalne.end());
    return *it;
}
int Temperature::DajBrojTemperaturaVecihOd (int veci) const {
    if (maximalne.size() == 0) throw std::logic_error ("Nema registriranih temperatura");
    int broj = std::count_if (maximalne.begin(), maximalne.end(), std::bind (std::greater<int>(), std::placeholders::_1, veci));
    return broj;
}
int Temperature::DajBrojTemperaturaManjihOd (int manji) const{
    if (minimalne.size() == 0) throw std::logic_error ("Nema registriranih temperatura");
    int broj = std::count_if (minimalne.begin(), minimalne.end(), std::bind (std::less<int>(), std::placeholders::_1, manji));
    return broj;
}
bool operator! (const Temperature &p1) {
    if(p1.minimalne.size() == 0 && p1.maximalne.size() == 0) return true;
    return false;
}
Temperature operator++ (Temperature &p1) {
    std::transform (p1.minimalne.begin(), p1.minimalne.end(), p1.minimalne.begin(), std::bind (std::plus<int>(), std::placeholders::_1, 1));
    return p1;
}
Temperature operator++ (Temperature &temp, int n) {
    Temperature p1 = temp;
    std::transform (p1.minimalne.begin(), p1.minimalne.end(), p1.minimalne.begin(), std::bind (std::plus<int>(), std::placeholders::_1, n));
    return temp;
}
Temperature operator-- (Temperature &p1) {
    std::transform (p1.maximalne.begin(), p1.maximalne.end(), p1.maximalne.begin(), std::bind (std::minus<int>(), std::placeholders::_1, 1));
    return p1;
}
Temperature operator-- (Temperature &p1, int n) {
    Temperature temp = p1;
    std::transform (temp.maximalne.begin(), temp.maximalne.end(), temp.maximalne.begin(), std::bind (std::minus<int>(), std::placeholders::_1, 1));
    return temp;
}
std::vector<int> operator* (const Temperature &p1) {
    int n = p1.minimalne.size();
    std::vector<int> vek(n);
    std::transform (p1.minimalne.begin(), p1.minimalne.end(), p1.maximalne.begin(), vek.begin(), std::minus<int>());
    return vek;
}
std::vector<int> operator- (const Temperature &p1) {
    auto min = (p1.minimalne.begin());
    int n = p1.minimalne.size();
    std::vector<int> vek (n);
    std::transform (p1.minimalne.begin(), p1.minimalne.end(), vek.begin(), std::bind(std::minus<int>(),std::placeholders::_1,* min));
    return vek;
}
std::vector<int> operator+ (const Temperature &p1) {
    auto max = (p1.maximalne.begin());
    int n = p1.maximalne.size();
    std::vector<int> vek(n);
    std::transform (p1.maximalne.begin(), p1.maximalne.end(), vek.begin(), std::bind (std::minus<int>(), *max, std::placeholders::_1));
    return vek;
}
std::pair<int, int> Temperature::operator[] (int index) {
    if (index > this->minimalne.size()) throw std::range_error ("Neispravan indeks");
    std::pair<int, int> par;
    auto it = this->minimalne.begin(), it1 = this->maximalne.begin();
    std::advance (it, index-1);
    std::advance (it1, index-1);
    par = std::make_pair (*it, *it1);
    return par;
}
Temperature operator+ (const Temperature &p1, int n) {
    Temperature temp = p1;
    auto min = p1.minimalne.begin();
    auto max = p1.maximalne.begin();
    std::transform (temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind (std::plus<int>(), std::placeholders::_1, n));
    std::transform (temp.maximalne.begin(), temp.maximalne.end(), temp.maximalne.begin(), std::bind (std::plus<int>(), std::placeholders::_1, n));
    auto maxi = std::max_element (temp.maximalne.begin(), temp.maximalne.end());
    auto mini = std::min_element (temp.minimalne.begin(), temp.minimalne.end());
  /*  if (*maxi > *max || *mini < *min)
        throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");*/
    return temp;
}
Temperature operator- (const Temperature &p1, int n) {
    Temperature temp = p1;
    std::transform (temp.maximalne.begin(), temp.maximalne.end(), temp.maximalne.begin(), std::bind (std::minus<int>(), std::placeholders::_1, n));
    std::transform (temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind (std::minus<int>(), std::placeholders::_1, n));
    return temp;
}
Temperature operator- (int n, const Temperature &p1) {
    Temperature temp = p1;
    std::transform (p1.minimalne.begin(), p1.minimalne.end(), temp.maximalne.begin(), std::bind (std::minus<int>(), n, std::placeholders::_1));
    std::transform (p1.maximalne.begin(), p1.maximalne.end(), temp.minimalne.begin(), std::bind (std::minus<int>(), n, std::placeholders::_1));
    return temp;
}
Temperature &Temperature::operator+= (int x) {
    std::transform (this->minimalne.begin(), this->minimalne.end(), this->minimalne.begin(), std::bind (std::plus<int>(), std::placeholders::_1, x));
    std::transform (this->maximalne.begin(), this->maximalne.end(), this->maximalne.begin(), std::bind (std::plus<int>(), std::placeholders::_1, x));
    return *this;
}
Temperature &Temperature::operator-= (int x) {
    std::transform (this->maximalne.begin(), this->maximalne.end(), this->maximalne.begin(), std::bind (std::minus<int>(), std::placeholders::_1, x));
    std::transform (this->minimalne.begin(), this->minimalne.end(), this->minimalne.begin(), std::bind (std::minus<int>(), std::placeholders::_1, x));
    return *this;
}
std::ostream &operator<< (std::ostream &tok, const Temperature &p1) {
    std::for_each (p1.minimalne.begin(), p1.minimalne.end(), [&tok] (int x) { tok << x << " ";});
    tok << std::endl;
    std::for_each (p1.maximalne.begin(), p1.maximalne.end(), [&tok] (int x) { tok << x << " ";});
    return tok;
}
int main ()
{
    try {
        Temperature t(-100,100);
        t.RegistrirajTemperature(std::make_pair(3,4));
        t.RegistrirajTemperature(std::make_pair(-3,2));
        t.RegistrirajTemperature(std::make_pair(-3,-2));
        t.RegistrirajTemperature(std::make_pair(-1,2));
        auto vek = *t; // test da li operator * radi dobro
        for (auto x: vek) std::cout << x << " ";
        std::cout << std::endl;
        auto vek1 = -t; //unarni -
        for (auto x: vek1) std::cout << x << " ";
        std::cout << std::endl << "Minimalna temperatura je: " << t.DajMinimalnuTemperaturu();
        std::cout << std::endl << "Minimalna temperatura je: " << t.DajMaksimalnuTemperaturu();
        std::cout << std::endl << "Broj temperatura manjih od 3 je " << t.DajBrojTemperaturaManjihOd(3);
        std::cout << std::endl << t;
        t = t + 2 ; // binarni operator +
        t = t - 3; // binarni operator -
        std::cout << std::endl << t;
        auto koor = t[2]; // operator[]
        std::cout << std::endl << koor.first << " " << koor.second;
        t += 3; // opertator +=
        t -= 3; // operator -=
        t.BrisiSve(); // metoda za brisanje
        std::cout << std::endl << t;
    }
    catch (std::range_error por) {
        std::cout << por.what();
    }
    catch (std::logic_error por) {
        std::cout << por.what();
    }
	return 0;
}
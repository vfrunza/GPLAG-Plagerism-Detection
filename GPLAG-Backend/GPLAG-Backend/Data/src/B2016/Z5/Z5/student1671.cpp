/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <functional>

class Temperature {
    int minimalna, maksimalna;
    std::list<int> minimalne_t;
    std::list<int> maksimalne_t;
    public:
    Temperature(int m, int M) {
        if (m > M) throw std::range_error ("Nekorektne temperature");
        minimalna = m; maksimalna = M;
    }
    void RegistrirajTemperature(std::pair<int, int> par);
    void BrisiSve();
    void BrisiNegativneTemperature(); // ???
    int DajBrojRegistriranihTemperatura() const { return minimalne_t.size(); }
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int t) const;
    int DajBrojTemperaturaManjihOd(int t) const;
    friend bool operator!(const Temperature &t);//
    Temperature operator++(int);//
    Temperature &operator++();//
    Temperature operator--(int);//
    Temperature &operator--();//
    Temperature operator*();// ?????
    Temperature operator+();
    Temperature operator-();
    std::pair<int, int> operator[](int i) const;//
    friend Temperature operator+(const Temperature &t, int y);
    friend Temperature operator-(const Temperature &t, int y);
    friend Temperature operator+(int y, const Temperature &t);
    friend Temperature operator-(int y, const Temperature &t);
    Temperature &operator+=(int y);
    Temperature &operator-=(int y);
    friend bool operator==(const Temperature &t1, const Temperature &t2);
    friend bool operator!=(const Temperature &t1, const Temperature &t2);
    friend std::ostream &operator<<(std::ostream &tok, const Temperature &t);
};
std::ostream &operator<<(std::ostream &tok, const Temperature &t) {
    //std::for_each(t.minimalne_t.begin(), t.minimalne_t.end(), std::bind((std::ostream&(std::ostream&, const Temperature&))::operator<<, std::ref(std::cout), _1));
}
bool operator!=(const Temperature &t1, const Temperature &t2) {
    return !(t1 == t2);
}
bool operator==(const Temperature &t1, const Temperature &t2) {
    if (t1.minimalne_t.size() == t2.minimalne_t.size() && t1.minimalna == t2.minimalna && t1.maksimalna == t2.maksimalna) 
        return std::equal(t1.minimalne_t.begin(), t1.minimalne_t.end(), t2.minimalne_t.begin()) && std::equal(t1.maksimalne_t.begin(), t1.maksimalne_t.end(), t2.maksimalne_t.begin());
    return false;
}
Temperature &Temperature::operator+=(int y) {
    *this = *this + y;
    return *this;
}
Temperature &Temperature::operator-=(int y) {
    *this = *this - y;
    return *this;
}
Temperature operator-(int y, const Temperature &t) {
    Temperature T(t.minimalna, t.maksimalna);
    T.minimalne_t = t.minimalne_t; T.maksimalne_t = t.maksimalne_t;
    std::transform(T.minimalne_t.begin(), T.minimalne_t.end(), T.maksimalne_t.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1));
    auto test_1(std::count_if(T.maksimalne_t.begin(), T.maksimalne_t.end(), std::bind(std::greater<int>(), std::placeholders::_1, t.maksimalna)));
    if (test_1) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    std::transform(t.maksimalne_t.begin(), t.maksimalne_t.end(), T.minimalne_t.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1));
    auto test_2(std::count_if(T.minimalne_t.begin(), T.minimalne_t.end(), std::bind(std::less<int>(), std::placeholders::_1, t.minimalna)));
    if (test_2) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return T;
}
Temperature operator+(int y, const Temperature &t) {
    return t + y;
}
Temperature operator-(const Temperature &t, int y) {
    Temperature T(t.minimalna, t.maksimalna);
    T.minimalne_t = t.minimalne_t; T.maksimalne_t = t.maksimalne_t;
    std::transform(T.minimalne_t.begin(), T.minimalne_t.end(), T.minimalne_t.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
    auto test_1(std::count_if(T.maksimalne_t.begin(), T.maksimalne_t.end(), std::bind(std::greater<int>(), std::placeholders::_1, t.maksimalna)));
    if (test_1) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    std::transform(T.maksimalne_t.begin(), T.maksimalne_t.end(), T.maksimalne_t.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
    auto test_2(std::count_if(T.minimalne_t.begin(), T.minimalne_t.end(), std::bind(std::less<int>(), std::placeholders::_1, t.minimalna)));
    if (test_2) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return T;
}
Temperature operator+(const Temperature &t, int y) {
    Temperature T(t.minimalna, t.maksimalna);
    T.minimalne_t = t.minimalne_t; T.maksimalne_t = t.maksimalne_t;
    std::transform(T.minimalne_t.begin(), T.minimalne_t.end(), T.minimalne_t.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    auto test_1(std::count_if(T.maksimalne_t.begin(), T.maksimalne_t.end(), std::bind(std::less<int>(), std::placeholders::_1, t.minimalna)));
    if (test_1) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    std::transform(T.maksimalne_t.begin(), T.maksimalne_t.end(), T.maksimalne_t.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    auto test_2(std::count_if(T.maksimalne_t.begin(), T.maksimalne_t.end(), std::bind(std::greater<int>(), std::placeholders::_1, t.maksimalna)));
    if (test_2) throw std::logic_error ("Prekoracen dozvoljeni opseg temperatura");
    return T;
}
std::pair<int, int> Temperature::operator[](int i) const {
    if (i < 1 || i > minimalne_t.size()) throw std::range_error ("Neispravan indeks");
    auto it1 = minimalne_t.begin();
    std::advance(it1, i-1);
    auto it2 = maksimalne_t.begin();
    std::advance(it2, i-1);
    return {*it1, *it2};
}
Temperature &Temperature::operator --() { // smanjuje maksimalne
    std::transform(maksimalne_t.begin(), maksimalne_t.end(), maksimalne_t.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    bool test(std::equal(minimalne_t.begin(), minimalne_t.end(), maksimalne_t.begin(), std::bind(std::less_equal<int>(), std::placeholders::_1, std::placeholders::_2)));
    if (!test) throw std::logic_error ("Ilegalna operacija");
    return *this;
}
Temperature Temperature::operator --(int) {
    Temperature pomocni(minimalna, maksimalna);
    pomocni.minimalne_t = minimalne_t, pomocni.maksimalne_t = maksimalne_t;
    (*this)--;
    return pomocni;
}
Temperature &Temperature::operator ++() { // povecava minimalne
    std::transform(minimalne_t.begin(), minimalne_t.end(), minimalne_t.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    bool test(std::equal(minimalne_t.begin(), minimalne_t.end(), maksimalne_t.begin(), std::bind(std::less_equal<int>(), std::placeholders::_1, std::placeholders::_2)));
    if (!test) throw std::logic_error ("Ilegalna operacija");
    return *this;
}
Temperature Temperature::operator ++(int) {
    Temperature pomocni(minimalna, maksimalna);
    pomocni.minimalne_t = minimalne_t; pomocni.maksimalne_t = maksimalne_t;
    (*this)++;
    //std::transform(minimalne_t.begin(), minimalne_t.end(), minimalne_t.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return pomocni;
};
bool operator!(const Temperature &t) {
    return t.minimalne_t.empty();
}
int Temperature::DajBrojTemperaturaManjihOd(int t) const {
    if(maksimalne_t.empty()) throw std::logic_error ("Nema registriranih temperatura");
    return std::count_if(minimalne_t.begin(), minimalne_t.end(), std::bind(std::less<int>(), std::placeholders::_1, t));
}
int Temperature::DajBrojTemperaturaVecihOd(int t) const {
    if(maksimalne_t.empty()) throw std::logic_error ("Nema registriranih temperatura");
    return std::count_if(maksimalne_t.begin(), maksimalne_t.end(), std::bind(std::greater<int>(), std::placeholders::_1, t));
}
int Temperature::DajMaksimalnuTemperaturu() const {
    if(maksimalne_t.empty()) throw std::logic_error ("Nema registriranih temperatura");
    return *std::max_element(maksimalne_t.begin(), maksimalne_t.end());
}
int Temperature::DajMinimalnuTemperaturu() const {
    if(minimalne_t.empty()) throw std::logic_error ("Nema registriranih temperatura");
    return *std::min_element(minimalne_t.begin(), minimalne_t.end());
}
void Temperature::BrisiSve() {
    minimalne_t.clear();
    maksimalne_t.clear();
}
void Temperature::RegistrirajTemperature(std::pair<int, int> par) {
    if (par.first > par.second || par.first > maksimalna || par.second > maksimalna 
    || par.first < minimalna ||  par.second < minimalna) throw std::range_error ("Nekorektne temperature");
    minimalne_t.push_back(par.first);
    maksimalne_t.push_back(par.second);
}


int main ()
{
	try {
	Temperature b(-10, 30);
	b.RegistrirajTemperature({-5, 22});
	b.RegistrirajTemperature({2, 27});
	std::cout << std::boolalpha << !b << std::endl;
	std::cout << std::boolalpha << !b << std::endl;
	std::cout << b.DajMaksimalnuTemperaturu() << std::endl;
	std::cout << b.DajMinimalnuTemperaturu() << std::endl;
	std::cout << "Broj registriranih temperatura: " << b.DajBrojRegistriranihTemperatura() << std::endl;
	std::cout << "Broj temperatura vecih od 22: " << b.DajBrojTemperaturaVecihOd(22) << std::endl;
	std::cout << "Broj temperatura manjih od 4: " << b.DajBrojTemperaturaManjihOd(4) << std::endl;
	std::cout << b[1].first << b[1].second << std::endl;
	//std::cout << b + 2 << std::endl;
	}
	catch(std::range_error e) {
	    std::cout << e.what() << std::endl;
	}
	return 0;
}
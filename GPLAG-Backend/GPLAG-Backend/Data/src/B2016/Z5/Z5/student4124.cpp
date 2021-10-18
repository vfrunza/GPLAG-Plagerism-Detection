/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>

static std::list<int> l(1);

class Temperature {
    int md, Md;
    std::list<int> max, min;
public:
    Temperature(int m, int M);
    
    void RegistrirajTemperature(std::pair<int, int> par);
    void BrisiSve();
    void BrisiNegativneTemperature(std::list<int>::iterator it1 = l.begin(), std::list<int>::iterator it2 = l.begin());
    
    int DajBrojRegistriranihTemperatura() const {return max.size();}
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int temp) const;
    int DajBrojTemperaturaManjihOd(int temp) const;
    
    bool operator !();
    
    std::vector<int> operator *();
    std::vector<int> operator -();
    std::vector<int> operator +();
    
    friend Temperature &operator ++(Temperature &t);
    friend Temperature &operator --(Temperature &t);
    friend Temperature operator ++(Temperature &t, int);
    friend Temperature operator --(Temperature &t, int);
    
    std::pair<int,int> operator [](int i) const;
    
    friend Temperature operator +(Temperature t, int n);
    friend Temperature operator -(Temperature t, int n);
    friend Temperature operator +(int n, Temperature t);
    friend Temperature operator -(int n, Temperature t);
    
    friend Temperature &operator +=(Temperature &t, int n);
    friend Temperature &operator -=(Temperature &t, int n);
    
    friend bool operator ==(const Temperature &t1, const Temperature &t2);
    friend bool operator !=(const Temperature &t1, const Temperature &t2);
    
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &t);
};

Temperature::Temperature(int m, int M) {
    if(m>M)
        throw std::range_error("Nekorektne temperature");
    md=m; Md=M;
}

void Temperature::RegistrirajTemperature(std::pair<int, int> par) {
    if(par.first>par.second or par.first<md or par.first>Md or par.second<md or par.second>Md)
        throw std::range_error("Nekorektne temperature");
    max.push_back(par.second);
    min.push_back(par.first);
}

void Temperature::BrisiSve() {
    max.clear();
    min.clear();
}

void Temperature::BrisiNegativneTemperature(std::list<int>::iterator it1, std::list<int>::iterator it2) {
    //auto it1(max.begin()), it2(min.begin());
    if(it1==l.begin()) {
        it1=min.begin();
        it2=max.begin();
    }
    if(it1!=min.end()) {
        if(*it1<0 and *it2<0) {
            it1=min.erase(it1);
            it2=max.erase(it2);
        } else {
        it1++; it2++;
        }
        BrisiNegativneTemperature(it1,it2);
    }
    /*while(it1!=max.end()) {
        if(*it1<0 and *it2<0) {
            it1=max.erase(it1);
            it2=min.erase(it2);
        }
        it1++; it2++;
    }*/
}

int Temperature::DajMinimalnuTemperaturu() const {
    if(max.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return *std::min_element(min.begin(), min.end());
}

int Temperature::DajMaksimalnuTemperaturu() const {
    if(max.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(max.begin(), max.end());
}

int Temperature::DajBrojTemperaturaVecihOd(int temp) const {
    if(max.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(max.begin(), max.end(), std::bind(std::greater<int>(), std::placeholders::_1, temp));
}

int Temperature::DajBrojTemperaturaManjihOd(int temp) const {
    if(max.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(min.begin(), min.end(), std::bind(std::less<int>(), std::placeholders::_1, temp));
}

bool Temperature::operator !() {
    if(max.size()==0)
        return true;
    return false;
}

Temperature &operator ++(Temperature &t) {
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    /*auto it(std::find_if(t.min.begin(), t.min.end(), t.max.begin(), std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2)));
    if(it!=t.min.end()) {
        std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
        throw std::logic_error("Ilegalna operacija");
    }*/
    return t;
}

Temperature &operator --(Temperature &t) {
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return t;
}

Temperature operator ++(Temperature &t, int) {
    auto t2(t);
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    /*auto it(std::find_if(t.min.begin(), t.min.end(), t.max.begin(), std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2)));
    if(it!=t.min.end()) {
        std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
        throw std::logic_error("Ilegalna operacija");
    }*/
    return t2;
}

Temperature operator --(Temperature &t, int) {
    auto t2(t);
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return t2;
}

std::vector<int> Temperature::operator *() {
    std::vector<int> v(max.size());
    std::transform(max.begin(), max.end(), min.begin(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
    return v;
}

std::vector<int> Temperature::operator -() {
    std::vector<int> v(min.size());
    std::transform(min.begin(), min.end(), v.begin(), std::bind(std::plus<int>(), -md, std::placeholders::_1));
    return v;
}

std::vector<int> Temperature::operator +() {
    std::vector<int> v(max.size());
    std::transform(max.begin(), max.end(), v.begin(), std::bind(std::minus<int>(), Md, std::placeholders::_1));
    return v;
}

std::pair<int,int> Temperature::operator [](int i) const {
    if(i<1 or i>max.size())
        throw std::range_error("Neispravan indeks");
    auto it1(min.begin()), it2(max.begin());
    std::advance(it1,i-1); std::advance(it2,i-1);
    return {*it1,*it2};
}

Temperature operator +(Temperature t, int n) {
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
    auto it = std::find_if(t.max.begin(), t.max.end(), std::bind(std::greater_equal<int>(), std::placeholders::_1, t.Md));
    if(it!=t.max.end()) {
        std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
        std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    return t;
}

Temperature operator -(Temperature t, int n) {
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
    auto it = std::find_if(t.min.begin(), t.min.end(), std::bind(std::less_equal<int>(), std::placeholders::_1, t.md));
    if(it!=t.min.end()) {
        std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
        std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    return t;
}

Temperature operator +(int n, Temperature t) {
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
    auto it = std::find_if(t.max.begin(), t.max.end(), std::bind(std::greater_equal<int>(), std::placeholders::_1, t.Md));
    if(it!=t.max.end()) {
        std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
        std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    return t;
}

Temperature operator -(int n, Temperature t) {
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), n, std::placeholders::_1));
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), n, std::placeholders::_1));
    auto temp(t.max);
    t.max=t.min; t.min=temp;
    auto it = std::find_if(t.min.begin(), t.min.end(), std::bind(std::less_equal<int>(), std::placeholders::_1, t.md));
    if(it!=t.min.end()) {
        std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
        std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    return t;
}

Temperature &operator +=(Temperature &t, int n) {
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
    auto it = std::find_if(t.max.begin(), t.max.end(), std::bind(std::greater_equal<int>(), std::placeholders::_1, t.Md));
    if(it!=t.max.begin()) {
        std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
        std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    return t;
}

Temperature &operator -=(Temperature &t, int n) {
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), n, std::placeholders::_1));
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), n, std::placeholders::_1));
    std::swap_ranges(t.min.begin(), t.min.end(), t.max.begin());
    auto it = std::find_if(t.min.begin(), t.min.end(), std::bind(std::less_equal<int>(), std::placeholders::_1, t.md));
    if(it!=t.min.begin()) {
        std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
        std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    return t;
}

bool operator ==(const Temperature &t1, const Temperature &t2) {
    if(t1.md==t2.md and t1.Md==t2.Md and t1.max==t2.max and t1.min==t2.min)
        return true;
    return false;
}

bool operator !=(const Temperature &t1, const Temperature &t2) {
    return !(t1==t2);
}

void I(int i) { std::cout << i << " ";}

std::ostream &operator <<(std::ostream &tok, const Temperature &t) {
    std::for_each(t.min.begin(), t.min.end(), std::bind(I, std::placeholders::_1));
    tok << std::endl;
    std::for_each(t.max.begin(), t.max.end(), std::bind(I, std::placeholders::_1));
    return tok;
}

int main ()
{
    Temperature t(-20,30);
    std::pair<int,int> par(-5,10);
    t.RegistrirajTemperature(par);
    par={-8,3};
    t.RegistrirajTemperature(par);
    std::cout << "Broj registriranih temperatura: " << t.DajBrojRegistriranihTemperatura() << std::endl;
    std::cout << t << std::endl;
    t.BrisiSve();
    std::cout << "Nakon brisanja svih temperatura, broj registriranih temperatura: " << t.DajBrojRegistriranihTemperatura() << std::endl;
    par={-5,10};
    t.RegistrirajTemperature(par);
    par={-8,3};
    t.RegistrirajTemperature(par);
    t.BrisiNegativneTemperature();
    std::cout << "Nakon brisanja negativnih, broj registriranih temperatura: " << t.DajBrojRegistriranihTemperatura() << std::endl;
	par={-5,-2};
	t.RegistrirajTemperature(par);
	std::cout << t << std::endl;
	std::cout << "Minimalna: " << t.DajMinimalnuTemperaturu() << std::endl << "Maksimalna: " << t.DajMaksimalnuTemperaturu() << std::endl;
	std::cout << "Broj temperatura vecih od 5 stepeni: " << t.DajBrojTemperaturaVecihOd(5) << std::endl;
	std::cout << "Broj temperatura vecih od -5 stepeni: " << t.DajBrojTemperaturaManjihOd(-5) << std::endl;
	std::vector<int> v(*t);
	std::cout << "Razlika maksimalne i minimalne temperature svakog dana: ";
	for(int x : v) std::cout << x << " ";
	std::cout << std::endl;
	v=-t;
	std::cout << "Razlika minimalno dozvoljene i minimalne temperature svakog dana: ";
	for(int x : v) std::cout << x << " ";
	std::cout << std::endl;
	v=+t;
	std::cout << "Razlika maksimalno dozvoljene i maksimalne temperature svakog dana: ";
	for(int x : v) std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "Druga temperatura po redu: " << t[2].first << " " << t[2].second << std::endl;
	std::cout << "Temperature uvecane za 3:" << std::endl << t+3 << std::endl;
	return 0;
}
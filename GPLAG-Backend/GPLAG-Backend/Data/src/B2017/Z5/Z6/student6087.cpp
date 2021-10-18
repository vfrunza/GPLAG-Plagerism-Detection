/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <cmath>
#include <memory>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <utility>
#include <string>
#include <iterator>


class Berza {
    int maximalna, minimalna;
    std::vector<int> berza;
  public:  
  Berza(int min, int max) : maximalna(max), minimalna(min) {
      if(maximalna  < 0 || minimalna < 0) throw std::range_error("Ilegalne granicne cijene"); 
  }
  explicit Berza(int max) : maximalna(max), minimalna(0) {
      if(maximalna  < 0) throw std::range_error("Ilegalne granicne cijene"); 
  }
  void RegistrirajCijenu(int cijena) {
      if(cijena > maximalna || cijena < minimalna) throw std::range_error("Ilegalna cijena");
      berza.push_back(cijena);
  }
  int DajBrojRegistriranihCijena() const { return berza.size(); }
  void BrisiSve() { berza.resize(0); }
  int DajMinimalnuCijenu() const {
      if(!berza.size()) throw std::range_error("Nema registriranih cijena");
      return*std::min_element(berza.begin(), berza.end());
  }
  int DajMaksimalnuCijenu() const {
      if(!berza.size()) throw std::range_error("Nema registriranih cijena");
      return*std::max_element(berza.begin(), berza.end());
  }
  bool operator!() const {
      return berza.size() == 0;
  }
  int DajBrojCijenaVecihOd(int cijena) const {
      if(!berza.size()) throw std::range_error("Nema registriranih cijena");
      return std::count_if(berza.begin(), berza.end(), std::bind(std::less<int>(), cijena, std::placeholders::_1));
  }
  void Ispisi() const;
  int operator[] (int i) const {
      if(i < 1 || i > berza.size()) throw std::range_error("Neispravan indeks");
      return berza[i-1];
  }
  Berza operator++(int);
  Berza& operator++();
  Berza operator--(int);
  Berza& operator--();
  Berza operator-();
  Berza operator+(int n);
  friend Berza operator+(int n, Berza &b);
  friend Berza operator-(Berza &b, int n);
  friend Berza operator-(int n, Berza &b);
  Berza operator+(Berza &b);
  Berza operator-(Berza &b);
  bool operator ==(Berza &b) const;
  bool operator !=(Berza &b) const;
  Berza &operator+=(const int n);
  Berza &operator+=(const Berza &b);
  Berza &operator-=(const int n);
  Berza &operator-=(const Berza &b);
};

Berza &Berza::operator-=(const int n)
{
    std::vector<int> v(berza);
    Berza berz  = *this;
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berz.berza.begin(), berz.berza.end(), berza.begin(), std::bind(std::minus<int>(), std::placeholders::_1, n));
    return *this;
}

Berza &Berza::operator-=(const Berza &b)
{
    if(maximalna != b.maximalna || minimalna != b.minimalna || berza.size() != b.berza.size()) throw std::domain_error("Nesaglasni operandi");
    Berza berz  = b;
    std::vector<int> v(berza);
    std::transform(v.begin(), v.end(), b.berza.begin(),v.begin(), std::minus<int>());
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), b.berza.begin(), berza.begin(), std::minus<int>());
    return *this;
}

Berza &Berza::operator+=(const Berza &b)
{
    if(maximalna != b.maximalna || minimalna != b.minimalna || berza.size() != b.berza.size()) throw std::domain_error("Nesaglasni operandi");
    Berza berz  = b;
    std::vector<int> v(b.berza);
    std::transform(v.begin(), v.end(), berza.begin(),v.begin(), std::plus<int>());
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), b.berza.begin(), berza.begin(), std::plus<int>());
    return *this;
}

Berza &Berza::operator+=(const int n)
{
    std::vector<int> v(berza);
    Berza berz = *this;
    std::transform(v.begin(), v.end(),v.begin(),  std::bind(std::plus<int>(), n, std::placeholders::_1));
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), berza.begin(), std::bind(std::plus<int>(), n, std::placeholders::_1));
    return *this;
}

bool Berza::operator !=(Berza &b) const
{
    return !(b.berza.size() == berza.size() && std::equal(berza.begin(), berza.end(), b.berza.begin()));
}

bool Berza::operator ==(Berza &b) const
{
    return (b.berza.size() == berza.size() && std::equal(berza.begin(), berza.end(), b.berza.begin()));
}

Berza Berza::operator-(Berza &b)
{
    if(maximalna != b.maximalna || minimalna != b.minimalna || berza.size() != b.berza.size()) throw std::domain_error("Nesaglasni operandi");
    Berza berz  = b;
    std::vector<int> v(berza);
    std::transform(v.begin(), v.end(), b.berza.begin(),v.begin(), std::minus<int>());
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), b.berza.begin(), berz.berza.begin(), std::minus<int>());
    return berz;
}

Berza Berza::operator+(Berza &b)
{
    if(maximalna != b.maximalna || minimalna != b.minimalna || berza.size() != b.berza.size()) throw std::domain_error("Nesaglasni operandi");
    Berza berz  = b;
    std::vector<int> v(b.berza);
    std::transform(v.begin(), v.end(), berza.begin(),v.begin(), std::plus<int>());
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), b.berza.begin(), berz.berza.begin(), std::plus<int>());
    return berz;
}

Berza operator-(int n, Berza &b)
{
    std::vector<int> v(b.berza);
    Berza berz  = b;
    std::transform(v.begin(), v.end(),v.begin(),  std::bind(std::minus<int>(), n, std::placeholders::_1));
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berz.berza.begin(), berz.berza.end(), berz.berza.begin(), std::bind(std::minus<int>(), n, std::placeholders::_1));
    return berz;
}

Berza operator-(Berza &b, int n)
{
    std::vector<int> v(b.berza);
    Berza berz  = b;
    std::transform(v.begin(), v.end(),v.begin(),  std::bind(std::minus<int>(), std::placeholders::_1 , n));
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berz.berza.begin(), berz.berza.end(), berz.berza.begin(), std::bind(std::minus<int>(), std::placeholders::_1 , n));
    return berz;
}

Berza operator+(int n, Berza &b)
{
    std::vector<int> v(b.berza);
    Berza berz = b;
    std::transform(v.begin(), v.end(),v.begin(),  std::bind(std::plus<int>(), n, std::placeholders::_1));
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berz.berza.begin(), berz.berza.end(), berz.berza.begin(), std::bind(std::plus<int>(), n, std::placeholders::_1));
    return berz;
}

Berza Berza::operator+(int n)
{
    std::vector<int> v(berza);
    Berza berz = *this;
    std::transform(v.begin(), v.end(),v.begin(),  std::bind(std::plus<int>(), n, std::placeholders::_1));
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, maximalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna))) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berz.berza.begin(), berz.berza.end(), berz.berza.begin(), std::bind(std::plus<int>(), n, std::placeholders::_1));
    return berz;
}

Berza Berza::operator++(int)
{
    std::vector<int> v(berza);
    Berza berz = *this;
    std::transform(v.begin(), v.end(),v.begin(),  std::bind(std::plus<int>(), 100, std::placeholders::_1));
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, maximalna))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), berza.begin(), std::bind(std::plus<int>(), 100, std::placeholders::_1));
    return berz;
}
Berza& Berza::operator++()
{
    std::vector<int> v(berza);
    std::transform(v.begin(), v.end(),v.begin(), std::bind(std::plus<int>(), 100, std::placeholders::_1));
    if(std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, maximalna))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), berza.begin(), std::bind(std::plus<int>(), 100, std::placeholders::_1));
    return *this;
}
Berza Berza::operator--(int)
{
    std::vector<int> v(berza);
    Berza berz  = *this;
    std::transform(v.begin(), v.end(),v.begin(),  std::bind(std::minus<int>(), std::placeholders::_1 , 100));
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), berza.begin(), std::bind(std::minus<int>(), std::placeholders::_1 , 100));
    return berz;
}
Berza& Berza::operator--()
{
    std::vector<int> v(berza);
    std::transform(v.begin(), v.end(),v.begin(), std::bind(std::minus<int>(), std::placeholders::_1 , 100));
    if(std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna))) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(berza.begin(), berza.end(), berza.begin(), std::bind(std::minus<int>(), std::placeholders::_1 , 100));
    return *this;
}

Berza Berza::operator-()
{
    int maxmin = maximalna + minimalna;
    Berza berz = *this;
    std::transform(berz.berza.begin(), berz.berza.end(), berz.berza.begin(), std::bind(std::minus<int>(), maxmin, std::placeholders::_1));
    return berz;
}

void Berza::Ispisi() const 
{
    std::vector<int> v(berza);
    std::vector<double>v1(v.size());
    std::sort(v.begin(), v.end(), std::greater<int>());
    std::transform(v.begin(), v.end(), v1.begin(), std::bind(std::divides<double>(), std::placeholders::_1, 100));
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<double>(std::cout << std::fixed << std::setprecision(2), "\n"));
}


int main ()
{
    Berza b(100000),b2(100000);
    b.RegistrirajCijenu(1000);
    b.RegistrirajCijenu(5000);
    b.RegistrirajCijenu(2000);
    b2.RegistrirajCijenu(300);
    b2.RegistrirajCijenu(220);
    b2.RegistrirajCijenu(200);
    std::cout << b.DajBrojRegistriranihCijena() <<std::endl;
    std::cout << b.DajMaksimalnuCijenu() << std::endl;
    std::cout << b2.DajMinimalnuCijenu() <<std::endl;
    std::cout << b.DajBrojCijenaVecihOd(2000) << std::endl;
    std::cout << !b2 << std::endl;
    std::cout << b2[2] << std::endl;
    b += b2;
    b += 100;
    b -= 100;
    Berza b1(100000);
    b1 = b - b2;
    b1.Ispisi();
    b1++;
    b1.Ispisi();
    ++b1;
    b1.Ispisi();
    b1--;
    b1.Ispisi();
    --b1;
    b1.Ispisi();
    b1.BrisiSve();
    b2.BrisiSve();
    b1.Ispisi(); b2.Ispisi();
	return 0;
}

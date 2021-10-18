/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <iterator>
class Berza {
	int maxcijena, mincijena;
	std::vector<int> cijene;
	static bool DaLiSuSaglasni(const Berza &b1, const Berza &b2);
public:
	Berza(int min, int max) { if (min < 0 || max < 0) throw std::range_error("Ilegalne granicne cijene"); mincijena = min; maxcijena = max; }
	explicit Berza(int max) { if (max < 0) throw std::range_error("Ilegalne granicne cijene"); mincijena = 0; maxcijena = max; }
	void RegistrirajCijenu(int cijena) { if (cijena > maxcijena || cijena < mincijena) throw std::range_error("Ilegalna cijena"); cijene.push_back(cijena); }
	int DajBrojRegistriranihCijena() const { return cijene.size(); }
	void BrisiSve() { cijene.clear(); }
	int DajMinimalnuCijenu() const { if (cijene.empty()) throw std::range_error("Nema registriranih cijena"); return *std::min_element(cijene.begin(), cijene.end()); }
	int DajMaksimalnuCijenu() const { if (cijene.empty()) throw std::range_error("Nema registriranih cijena"); return *std::max_element(cijene.begin(), cijene.end()); }
	bool operator !() const { return cijene.empty(); }
	int DajBrojCijenaVecihOd(int n) const;
	void Ispisi() const;
	int operator [](int i) const;
	Berza& operator ++();
	Berza operator ++(int);
	Berza& operator --();
	Berza operator --(int);
	Berza operator -();
	friend Berza operator +(const Berza &b1, const Berza &b2);
	friend Berza operator -(const Berza &b1, const Berza &b2);
	friend Berza operator +(const Berza &b1, int n);
	friend Berza operator +(int n, const Berza &b1);
	friend Berza operator -(const Berza &b1, int n);
	friend Berza operator -(int n, const Berza &b1);
	Berza& operator +=(const Berza &b1);
	Berza& operator -=(const Berza &b1);
	Berza& operator +=(int n);
	Berza& operator -=(int n);
	bool operator ==(const Berza &b) const;
	bool operator !=(const Berza &b) const;
};

int main()
{
	Berza b(500);
	b.RegistrirajCijenu(100); b.RegistrirajCijenu(150); b.RegistrirajCijenu(200);
	b.Ispisi();
	std::cout << "----------" << std::endl;
	b++;
	b.Ispisi();
	std::cout << "----------" << std::endl;
	b--;
	b.Ispisi();
	std::cout << "----------" << std::endl;
	b=-b;
	b.Ispisi();
	std::cout << "----------" << std::endl;
	b += 30;
	b.Ispisi();
	std::cout << "----------" << std::endl;
	b -= 30;
	b.Ispisi();
    return 0;
}

// IMPLEMENTACIJA
	// Berza::private
bool Berza::DaLiSuSaglasni(const Berza &b1, const Berza &b2) {
	return b1.DajBrojRegistriranihCijena() == b2.DajBrojRegistriranihCijena() && b1.DajMaksimalnuCijenu() == b2.DajMaksimalnuCijenu() && b1.DajMinimalnuCijenu() == b2.DajMinimalnuCijenu();
}
	// Berza::public
int Berza::DajBrojCijenaVecihOd(int n) const {
	if (!*this) throw std::range_error("Nema registriranih cijena");
	return std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, n));
}
void Berza::Ispisi() const {
	std::vector<double> pomocni;
	pomocni.resize(cijene.size());
	std::transform(cijene.begin(),cijene.end(),pomocni.begin(),std::bind(std::divides<double>(),std::placeholders::_1,100.0));
	std::sort(pomocni.begin(), pomocni.end(), std::greater<int>());
	std::copy(pomocni.begin(), pomocni.end(), std::ostream_iterator<double>(std::cout<<std::fixed<<std::setprecision(2), "\n"));
}
int Berza::operator [](int i) const {
	if (i > DajBrojRegistriranihCijena()) throw std::range_error("Neispravan indeks");
	return cijene[i - 1];
}
Berza& Berza::operator ++() {
	std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
	if (std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, maxcijena))) {
		std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -100));
		throw std::range_error("Prekoracen dozvoljeni opseg cijena");
	}
	return *this;
}
Berza Berza::operator ++(int) {
	Berza pomocni(*this);
	std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
	if (std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, maxcijena))) {
		std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -100));
		throw std::range_error("Prekoracen dozvoljeni opseg cijena");
	}
	return pomocni;
}
Berza& Berza::operator --() {
	std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -100));
	if (std::count_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, mincijena))) {
		std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
		throw std::range_error("Prekoracen dozvoljeni opseg cijena");
	}
	return *this;
}
Berza Berza::operator --(int) {
	Berza pomocni(*this);
	std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -100));
	if (std::count_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, mincijena))) {
		std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
		throw std::range_error("Prekoracen dozvoljeni opseg cijena");
	}
	return pomocni;
}
Berza Berza::operator -() {
	Berza novi(*this);
	std::transform(novi.cijene.begin(), novi.cijene.end(), novi.cijene.begin(), std::bind(std::minus<int>(), maxcijena + mincijena, std::placeholders::_1));
	return novi;
}
bool Berza::operator ==(const Berza &b) const {
	return DajBrojRegistriranihCijena() == b.DajBrojRegistriranihCijena() && std::equal(cijene.begin(), cijene.end(), b.cijene.begin());
}
bool Berza::operator !=(const Berza &b) const {
	return !(*this == b);
}
Berza operator +(const Berza &b1, const Berza &b2) {
	if (!Berza::DaLiSuSaglasni(b1, b2)) throw std::domain_error("Nesaglasni operandi");
	Berza b3(b1);
	std::transform(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin(), b3.cijene.begin(), std::plus<int>());
	if (std::count_if(b3.cijene.begin(), b3.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, b3.maxcijena)))
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	return b3;
}
Berza operator -(const Berza &b1, const Berza &b2) {
	if (!Berza::DaLiSuSaglasni(b1, b2)) throw std::domain_error("Nesaglasni operandi");
	Berza b3(b1);
	std::transform(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin(), b3.cijene.begin(), std::minus<int>());
	if (std::count_if(b3.cijene.begin(), b3.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, b3.mincijena)))
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	return b3;
}
Berza operator +(const Berza &b1, int n) {
	Berza b3(b1);
	std::transform(b3.cijene.begin(), b3.cijene.end(), b3.cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, n));
	if (std::count_if(b3.cijene.begin(), b3.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, b3.maxcijena)) || std::count_if(b3.cijene.begin(), b3.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, b3.mincijena)))
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	return b3;
}
Berza operator +(int n, const Berza &b1) {
	return b1 + n;
}
Berza operator -(const Berza &b1, int n) {
	return b1 + (-n);
}
Berza operator -(int n, const Berza &b1) {
	Berza b3(b1);
	std::transform(b3.cijene.begin(), b3.cijene.end(), b3.cijene.begin(), std::bind(std::minus<int>(), n, std::placeholders::_1));
	if (std::count_if(b3.cijene.begin(), b3.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, b3.maxcijena)) || std::count_if(b3.cijene.begin(), b3.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, b3.mincijena)))
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	return b3;
}
Berza& Berza::operator +=(const Berza &b1) {
	return *this = *this + b1;
}
Berza& Berza::operator -=(const Berza &b1) {
	return *this = *this - b1;
}
Berza& Berza::operator +=(int n) {
	return *this = *this + n;
}
Berza& Berza::operator -=(int n) {
	return *this = *this - n;
}
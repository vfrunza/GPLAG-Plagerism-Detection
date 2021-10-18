/B2017/2018: Zadaća 5, Zadatak 6
// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iomanip>
#include <stdexcept>
#include <utility>

using std::cin;
using std::cout;
using std::endl;

class Berza {
	std::vector<int> Cijene;
	int min, max;
	bool PripadnostIntervalu(int cijena) { if (cijena<min || cijena>max) return false; return true; }
	bool UOpsegu(int indeks) { return (indeks > 0 && indeks <= Cijene.size()); }
	int DajGG()const { return max; }
	int DajDG()const { return min; }
public:
	Berza(int min, int max);
	explicit Berza(int max);
	void RegistrirajCijenu(int cijena);
	int DajBrojRegistriranihCijena() const { return Cijene.size(); }
	void BrisiSve() { Cijene.clear(); Cijene.resize(0); }
	int DajMinimalnuCijenu();
	int DajMaksimalnuCijenu();
	bool operator !() { return this->Cijene.size() == 0; }
	int DajBrojCijenaVecihOd(int cijena) const;
	void Ispisi() const;
	int operator[](int indeks);
	Berza &operator  ++();
	Berza &operator  --();
	Berza operator  ++(int);
	Berza operator  --(int);
	Berza &operator -();
	friend Berza operator +(Berza B, int x);
	friend Berza operator +(int x, Berza B);
	friend Berza operator -(Berza B, int x);
	friend Berza operator -(int x, Berza B);
	friend Berza operator +(Berza B1, Berza B2);
	friend Berza operator -(Berza B1, Berza B2);
	friend Berza operator +=(Berza &B, int x) { return B = B + x; }
	friend Berza operator +=(int x, Berza &B) { return B = B + x; }
	friend Berza operator -=(Berza &B, int x) { return B = B - x; }
	friend Berza operator -=(int x, Berza &B) { return B = B - x; }
	Berza& operator +=(const Berza &B2) { return *this = *this + B2; }
	Berza& operator -=(const Berza &B2) { return *this = *this - B2; }
	friend bool operator ==(const Berza &B1, const Berza &B2);
	friend bool operator !=(const Berza &B1, const Berza &B2);
};

Berza::Berza(int min, int max) {
	if (min < 0 || max<0 || min>max) throw std::range_error("Ilegalne granicne cijene");
	Berza::max = max; Berza::min = min;
}
Berza::Berza(int max) {
	if(max<0) throw std::range_error("Ilegalne granicne cijene");
	Berza::max = max; Berza::min = 0;
}
void Berza::RegistrirajCijenu(int cijena) {
	if (!PripadnostIntervalu(cijena)) throw std::range_error("Ilegalna cijena");
	Cijene.push_back(cijena);
}
int Berza::DajMinimalnuCijenu() {
	if (!Cijene.size()) throw std::range_error("Nema registriranih cijena");
	auto minimalna(std::min_element(Cijene.begin(), Cijene.end()));
	return *minimalna;
}
int Berza::DajMaksimalnuCijenu() {
	if (!Cijene.size()) throw std::range_error("Nema registriranih cijena");
	auto maksimalna(std::max_element(Cijene.begin(), Cijene.end()));
	return *maksimalna;
}
int Berza::DajBrojCijenaVecihOd(int cijena) const {
	if (!Cijene.size()) throw std::range_error("Nema registriranih cijena");
	int broj(std::count_if(Cijene.begin(), Cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, cijena)));
	return broj;
}
void Berza::Ispisi() const {
	std::vector<double> Cijene2;
	std::transform(Cijene.begin(), Cijene.end(), std::back_inserter(Cijene2), std::bind(std::divides<double>(), std::placeholders::_1, 100.0));
	std::sort(Cijene2.begin(), Cijene2.end(), std::greater<double>());
	std::copy(Cijene2.begin(), Cijene2.end(), std::ostream_iterator<double>(std::cout << std::setprecision(2) << std::fixed, "\n"));
}
int Berza::operator [](int indeks){
	if (!UOpsegu(indeks)) throw std::range_error("Neispravan indeks");
	return Cijene[indeks-1];
}
Berza& Berza::operator ++() {
	std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
	if (std::count_if(Cijene.begin(), Cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, DajMaksimalnuCijenu()))) {
		std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
		throw std::range_error("Prekoracen dozvoljeni opseg cijena");
	}
	return *this;
}
Berza& Berza::operator --() {
	std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
	if (std::count_if(Cijene.begin(), Cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, DajMinimalnuCijenu()))) {
		std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
		throw std::range_error("Prekoracen dozvoljeni opseg cijena");
	}
	return *this;
}
Berza Berza::operator ++(int) {
	auto Pomocni = *this;
	std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
	if (std::count_if(Cijene.begin(), Cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, DajMaksimalnuCijenu()))) {
		std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
		throw std::range_error("Prekoracen dozvoljeni opseg cijena");
	}
	return Pomocni;
}
Berza Berza::operator --(int) {
	auto Pomocni = *this;
	std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
	if (std::count_if(Cijene.begin(), Cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, DajMinimalnuCijenu()))) {
		std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
		throw std::range_error("Prekoracen dozvoljeni opseg cijena");
	}
	return Pomocni;
}
Berza& Berza::operator -() {
	std::transform(Cijene.begin(), Cijene.end(), Cijene.begin(), std::bind(std::minus<int>(), DajGG() + DajDG(), std::placeholders::_1));
	return *this;
}
Berza operator+(Berza B, int x) {
	Berza PB(B.DajDG(), B.DajGG());
	PB.Cijene.resize(B.Cijene.size());
	std::copy(B.Cijene.begin(), B.Cijene.end(), PB.Cijene.begin());
	std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::less<int>(), PB.DajGG(), std::placeholders::_1))) {
		std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::greater<int>(), PB.DajDG(), std::placeholders::_1))) {
		std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	return PB;
}
Berza operator+(int x, Berza B) {
	Berza PB(B.DajDG(), B.DajGG());
	PB.Cijene.resize(B.Cijene.size());
	std::copy(B.Cijene.begin(), B.Cijene.end(), PB.Cijene.begin());
	std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::less<int>(), PB.DajGG(), std::placeholders::_1))) {
		std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::greater<int>(), PB.DajDG(), std::placeholders::_1))) {
		std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	return PB;
}
Berza operator-(Berza B, int x) {
	Berza PB(B.DajDG(), B.DajGG());
	PB.Cijene.resize(B.Cijene.size());
	std::copy(B.Cijene.begin(), B.Cijene.end(), PB.Cijene.begin());
	std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::less<int>(), PB.DajGG(), std::placeholders::_1))) {
		std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::greater<int>(), PB.DajDG(), std::placeholders::_1))) {
		std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	return PB;
}
Berza operator-(int x, Berza B) {
	Berza PB(B.DajDG(), B.DajGG());
	PB.Cijene.resize(B.Cijene.size());
	std::copy(B.Cijene.begin(), B.Cijene.end(), PB.Cijene.begin());
	std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::less<int>(), PB.DajGG(), std::placeholders::_1))) {
		std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::greater<int>(), PB.DajDG(), std::placeholders::_1))) {
		std::transform(PB.Cijene.begin(), PB.Cijene.end(), PB.Cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	return PB;
}
Berza operator+(Berza B1, Berza B2) {
	if (B1.DajDG() != B2.DajDG() || B1.DajGG() != B2.DajGG() || B1.Cijene.size() != B2.Cijene.size()) throw std::domain_error("Nesaglasni operandi");
	Berza PB(B1.DajDG(), B1.DajGG());
	std::transform(B1.Cijene.begin(), B1.Cijene.end(), B2.Cijene.begin(), std::back_inserter(PB.Cijene), std::plus<int>());
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::less<int>(), PB.DajGG(), std::placeholders::_1))) {
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::greater<int>(), PB.DajDG(), std::placeholders::_1))) {
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	return PB;
}
Berza operator-(Berza B1, Berza B2) {
	if (B1.DajDG() != B2.DajDG() || B1.DajGG() != B2.DajGG() || B1.Cijene.size() != B2.Cijene.size()) throw std::domain_error("Nesaglasni operandi");
	Berza PB(B1.DajDG(), B1.DajGG());
	std::transform(B1.Cijene.begin(), B1.Cijene.end(), B2.Cijene.begin(), std::back_inserter(PB.Cijene), std::minus<int>());
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::less<int>(), PB.DajGG(), std::placeholders::_1))) {
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	if (std::count_if(PB.Cijene.begin(), PB.Cijene.end(), std::bind(std::greater<int>(), PB.DajDG(), std::placeholders::_1))) {
		throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
	}
	return PB;
}
bool operator==(const Berza & B1, const Berza & B2) {
	if (B1.Cijene.size() != B2.Cijene.size()) return false;
	return std::equal(B1.Cijene.begin(), B1.Cijene.end(), B2.Cijene.begin());
}
bool operator!=(const Berza & B1, const Berza & B2) {
	if (B1.Cijene.size() != B2.Cijene.size()) return true;
	if (B1.Cijene.size() != B2.Cijene.size()) return false;
	return !std::equal(B1.Cijene.begin(), B1.Cijene.end(), B2.Cijene.begin());
}



int main()
{
	Berza B1(1, 100000);
	cout << "Hajd sad fino unesi cijene za ove berze: " << endl;
	cout << "Unesi cijene za B1: " << endl;
	for (int i(0); i < 6; i++) {
		int cijena;
		cin >> cijena;
		B1.RegistrirajCijenu(cijena);
	}
	cout << endl;
	++B1;
	B1++;
	cout << B1.DajMaksimalnuCijenu() << endl;
	cout << B1.DajMinimalnuCijenu() << endl;
	cout << B1.DajBrojCijenaVecihOd(2) << endl;
	cout << B1.DajBrojRegistriranihCijena() << endl;
	B1.Ispisi();
	cout << endl;
	B1 += 3;
	B1.Ispisi();
	cout << endl;
	cout << "AAAA" << endl;
	B1 = B1 + 5; 
	B1.Ispisi();
	cout << endl;
	cout << B1.DajBrojCijenaVecihOd(9);
	Berza B2(1, 100000);
	cout << "Unesi cijene za B2: ";
	for (int i(0); i < 6; i++) {
		int cijena;
		cin >> cijena;
		B2.RegistrirajCijenu(cijena);
	}
	cout << endl;
	if (B1 == B2) cout << "JEDNAKE!" << endl;
	if (B1 != B2) cout << "NISU JEDNAKE!" << endl;
	Berza B3(1, 1000000);
	B3 = B1 + B2;
	B3.Ispisi();
	cout << endl;
	B3 += B1;
	B3.Ispisi();
	cout << endl;
	B3--;
	B3.Ispisi();
	cout << endl;
	++B3;
	B3.Ispisi();
	cout << endl;
	cout << B3[2];
	return 0;
}


#include <iostream>
#include <iomanip>
#include <type_traits>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>

bool NijePonovac(const std::deque<long long int> &d, int x) {
	for(int i=0; i<d.size(); i++)
		if(d[i] == x) return false;
	return true;
}

void Unesi(std::deque<long long int> &d, int vel) {
	for(int i=0; i<vel; i++) {
		long long int x;
		std::cin >> x;
		if(i == 0 || NijePonovac(d, x)) d.push_back(x);
		else i--;
		}
}

void Ispisi(const std::vector<std::vector<long long int>> &c) {
	for(int i=0; i<c.size(); i++) {
		for(int j=0; j<c[i].size(); j++)
			std::cout << std::setw(6) << c[i][j] << " ";
		std::cout << std::endl;
	}
}

int SumaCifara(long long int x) {
	int suma(0);
	while(x != 0) {
		suma += abs(x) % 10;
		x /= 10;
	}
	return suma;
}

bool Prost(int x) {
	if(x < 2) return false;
	for(int i=2; i<x; i++)
		if(x % i == 0) return false;
	return true;
}

int SumaDjelilaca2(long long int x) {
	if(x < 0) x *= -1;
	int suma(0);
	for(int i=1; i<x; i++) 
		if(x % i == 0) suma += i;
	return suma;
}

int SumaDjelilaca(long long x) {
	if(x < 0) x *= -1;
	int suma(0);
	for(int i=1; i<=x; i++)
		if(x % i == 0) suma += i;
	return suma;
}

int BrojProstihFaktora(long long int x) {
	if(x < 0) x *= -1;
	int br(0);
	for(int i=2; i<=x; i++) 
		while(x % i == 0 && x != 0) { 
			x /= i; 
			br++; 
		}
	return br;
}

int BrojSavrsenihDjelilaca(long long int x) {
	if(x < 0) x *= -1;
	int br(0);
	for(int i=1; i<=x; i++) 
		if(x % i == 0 && SumaDjelilaca2(i) == i) br++;
	return br;
}

template <typename Iter>
Iter ObrisiPonovce(Iter p, Iter k) {
	Iter k1(k);
	while(p != k1) {
		auto temp(*p);
		p++;
		k1 = std::remove(p, k1, temp);
	}
	return k1;
}

template <typename It1, typename It2>
auto UvrnutiPresjek(It1 poc1, It1 kraj1, It2 poc2, It2 kraj2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
	kraj1 = ObrisiPonovce(poc1, kraj1); kraj2 = ObrisiPonovce(poc2, kraj2);
	typedef typename std::remove_reference<decltype(*poc1)>::type T;
	std::vector<std::vector<T>> mat;
	while(poc1 != kraj1) {
		It1 p2(poc2);
		while(p2 != kraj2) {
			if(*poc1 == *p2) mat.push_back({*poc1, T(), T()});
			p2++;
		}
		poc1++;
	}
	return mat;
} 

template <typename It1, typename It2, typename TipFun>
auto UvrnutiPresjek(It1 poc1, It1 kraj1, It2 poc2, It2 kraj2, TipFun f) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
	kraj1 = ObrisiPonovce(poc1, kraj1); kraj2 = ObrisiPonovce(poc2, kraj2);
	typedef typename std::remove_reference<decltype(*poc1)>::type T;
	std::vector<std::vector<T>> mat;
	while(poc1 != kraj1) {
		It2 p2(poc2);
		while(p2 != kraj2) {
 			if(f(*poc1) == f(*p2)) 
				mat.push_back({*poc1, *p2, f(*p2)});
			p2++;
		}
		poc1++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<T> v1, std::vector<T> v2) -> bool { 
		if(v1[0] == v2[0]) return v1[1] < v2[1];
		if(v1[2] == v2[2]) return v1[0] < v2[0];
		return v1[2] < v2[2];
	});
	return mat;
}

template <typename It1, typename It2>
auto UvrnutaRazlika(It1 poc1, It1 kraj1, It2 poc2, It2 kraj2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
	kraj1 = ObrisiPonovce(poc1, kraj1); kraj2 = ObrisiPonovce(poc2, kraj2);
	typedef typename std::remove_reference<decltype(*poc1)>::type T;
	std::vector<std::vector<T>> mat;
	It1 a1(poc1); It2 a2(poc2);
	while(poc1 != kraj1) {
		bool a(true);
		It2 p2(poc2);
		while(p2 != kraj2) {
			if(*poc1 == *p2) {
				a = false;
				break;
			}
			p2++;
		}
		if(a) mat.push_back({*poc1, T()});
		poc1++;
	}
	poc1 = a1; poc2 = a2;
	while(poc2 != kraj2) {
		bool a(true);
		It1 p1(poc1);
		while(p1 != kraj1) {
			if(*poc2 == *p1) {
				a = false;
				break;
			}
			p1++;
		}
		if(a) mat.push_back({*poc2, T()});
		poc2++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<T> v1, std::vector<T> v2) { return v1[0] > v2[0]; });
	return mat;
}

template <typename It1, typename It2, typename TipFun>
auto UvrnutaRazlika(It1 poc1, It1 kraj1, It2 poc2, It2 kraj2, TipFun f) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
	kraj1 = ObrisiPonovce(poc1, kraj1); kraj2 = ObrisiPonovce(poc2, kraj2);
	typedef typename std::remove_reference<decltype(*poc1)>::type T;
	std::vector<std::vector<T>> mat;
	It1 a1(poc1); It2 a2(poc2);
	while(poc1 != kraj1) {
		bool a(true);
		It2 p2(poc2);
		while(p2 != kraj2) {
			if(f(*poc1) == f(*p2)) {
				a = false;
				break;
			}
			p2++;
		}
		if(a) mat.push_back(std::vector<T> {*poc1, f(*poc1)});
		poc1++;
	}
	poc1 = a1; poc2 = a2;
	while(poc2 != kraj2) {
		bool a(true);
		It1 p1(poc1);
		while(p1 != kraj1) {
			if(f(*poc2) == f(*p1)) {
				a = false;
				break;
			}
			p1++;
		}
		if(a) mat.push_back(std::vector<T> {*poc2, f(*poc2)});
		poc2++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<T> v1, std::vector<T> v2) -> bool {
		if(v1[0] == v2[0]) return v1[1] > v2[1];
		return v1[0] > v2[0];
	});
	return mat;
}

int main () {
	std::deque<long long int> d1, d2;
	int vel1, vel2;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> vel1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	Unesi(d1, vel1);
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> vel2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	Unesi(d2, vel2);
	auto mat1 = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
	auto mat2 = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	Ispisi(mat1);
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	Ispisi(mat2);
	std::cout << "Dovidjenja!";
	return 0;
}
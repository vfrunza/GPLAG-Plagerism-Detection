/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <type_traits>
#include <iterator>

template <typename NekiTip, typename IterTip1, typename IterTip2, typename PovratniTip>
auto UvrnutiPresjek(IterTip1 pocetak_1, IterTip1 kraj_1, IterTip2 pocetak_2, IterTip2 kraj_2, PovratniTip fun(NekiTip)) -> std::vector<std::vector<decltype(*pocetak_1+*pocetak_1)>> {
	typedef typename std::remove_reference<std::vector<std::vector<decltype(*pocetak_1+*pocetak_1)>>>::type MojTip;
	typedef typename std::remove_reference<decltype(*pocetak_1)>::type ProizvoljanTip;
	MojTip Matrica;
	while (pocetak_1 != kraj_1) {
		auto rezultat(fun(*pocetak_1));
		auto pom_2(pocetak_2);
		while (pom_2 != kraj_2) {
			if (fun(*pom_2) == rezultat) {
				std::vector<ProizvoljanTip> v{*pocetak_1, *pom_2, rezultat};
				Matrica.push_back(v);
			}
			pom_2++;
		}
		pocetak_1++;
	}
	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<ProizvoljanTip> x, std::vector<ProizvoljanTip> y) {
		if (x[2] != y[2]) return x[2] < y[2];
		if (x[0] != y[0]) return x[0] < y[0];
		return x[1] < y[1];
	});
	return Matrica;	
}
template <typename NekiTip, typename IterTip1, typename IterTip2, typename PovratniTip>
auto UvrnutiPresjek(IterTip1 pocetak_1, IterTip1 kraj_1, IterTip2 pocetak_2, IterTip2 kraj_2) -> std::vector<std::vector<decltype(*pocetak_1+*pocetak_1)>> {
	typedef typename std::remove_reference<std::vector<std::vector<decltype(*pocetak_1+*pocetak_1)>>>::type MojTip;
	typedef typename std::remove_reference<decltype(*pocetak_1)>::type ProizvoljanTip;
	MojTip Matrica;
	std::vector<ProizvoljanTip> v;
	while (pocetak_1 != kraj_1) {
		auto pom_2(pocetak_2);
		while (pom_2 != kraj_2) {
			if (*pocetak_1 == *pom_2) v.push_back(*pocetak_1);
			pom_2++;
		}
		pocetak_1++;
	}
	Matrica.resize(v.size());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) Matrica[i].push_back(v[i]);
			else Matrica[i].push_back(0);
		}
	}
	return Matrica;
}
template <typename NekiTip, typename IterTip1, typename IterTip2, typename PovratniTip>
auto UvrnutaRazlika(IterTip1 pocetak_1, IterTip1 kraj_1, IterTip2 pocetak_2, IterTip2 kraj_2, PovratniTip fun(NekiTip)) -> std::vector<std::vector<decltype(*pocetak_1+*pocetak_1)>> {
	typedef typename std::remove_reference<std::vector<std::vector<decltype(*pocetak_1+*pocetak_1)>>>::type MojTip;
	typedef typename std::remove_reference<decltype(*pocetak_1)>::type ProizvoljanTip;
	MojTip Matrica;
	auto pom_1(pocetak_1);
	while (pom_1 != kraj_1) {
		auto rezultat(fun(*pom_1));
		auto pom_2(pocetak_2);
		bool test(false);
		while (pom_2 != kraj_2) {
			if (fun(*pom_2) == rezultat) {
				test = true;
				break;
			}
			pom_2++;
		}
		if(!test) {
			std::vector<ProizvoljanTip> v{*pom_1, rezultat};
			Matrica.push_back(v);
		}
		pom_1++;
	}
	while (pocetak_2 != kraj_2) {
		auto rezultat(fun(*pocetak_2));
		auto pom_1(pocetak_1);
		bool test(false);
		while (pom_1 != kraj_1) {
			if (fun(*pom_1) == rezultat) {
				test = true;
				break;
			}
			pom_1++;
		}
		if (!test) {
			std::vector<ProizvoljanTip> v{*pocetak_2, rezultat};
			Matrica.push_back(v);
		}
		pocetak_2++;
	}
	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<ProizvoljanTip> x, std::vector<ProizvoljanTip> y) {
		if (x[0] != y[0]) return x[0] > y[0];
		return x[1] > y[1];
	});
	return Matrica;
}

int SumaCifara(long long int n) {
	int suma(0);
	while (n) {
		suma += n%10;
		n/=10;
	}
	return suma;
}
int SumaDjelilaca(long long int n) {
	int suma(0);
	for (long long int i = 1; i <= n; i++)
		if (n%i == 0) suma += i;
	return suma;
}
bool DaLiJeProst(long long int n) {
	if (n < 2) return false;
	for (long long int i = 2; i <= int(std::sqrt(n)); i++) {
		if (n%i == 0 && i != n) return false;
		if (i == n) break;
	}
	return true;
}
int BrojProstihFaktora(long long int n) {
	int brojac(0);
	int i(2);
	while (i <= n) {
		if (DaLiJeProst(i))
			while (n != 0 && n%i == 0) {
				n/=i;
				brojac++;
			}
		i++;
	}
	return brojac;
}
bool DaLiJeSavrsen(long long int n) {
	int suma(0);
	for (int i = 1; i <= n/2; i++) {
		if (n%i == 0) suma += i;
		if (suma > n) return false;
	}
	if (suma == n) return true;
	return false;
}
int BrojSavrsenihDjelilaca(long long int n) {
	int brojac(0);
	for (int i = 1; i <= n; i++) {
		if (DaLiJeSavrsen(i) && n%i == 0) brojac++;
	}
	return brojac;
}


int main ()
{
	int vel_1;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> vel_1;
	std::deque<int> d1(vel_1);
	std::cout << "Unesite elemente prvog kontejnera: ";
	for (int i = 0; i < vel_1; i++) {
		int broj;
		std::cin >> broj;
		int j;
		for (j = 0; j < i; j++) if (d1[j] == broj) break;
		if (j == i) d1[i] = broj;
		else --i;
	}
	int vel_2;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> vel_2;
	std::deque<int> d2(vel_2);
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i = 0; i < vel_2; i++) {
		int broj;
		std::cin >> broj;
		int j;
		for (j = 0; j < i; j++) if (d2[j] == broj) break;
		if (j == i) d2[i] = broj;
		else --i;
	}
	auto m(UvrnutiPresjek(std::begin(d1), std::end(d1), std::begin(d2), std::end(d2), SumaCifara));
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) std::cout << std::setw(6) << m[i][j] << " ";
		std::cout << " " << std::endl;
	}
	auto n(UvrnutaRazlika(std::begin(d1), std::end(d1), std::begin(d2), std::end(d2), BrojProstihFaktora));
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	for (int i = 0; i < n.size(); i++) {
		for (int j = 0; j < n[i].size(); j++) std::cout << std::setw(6) << n[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!" << std::endl;
	return 0;
}
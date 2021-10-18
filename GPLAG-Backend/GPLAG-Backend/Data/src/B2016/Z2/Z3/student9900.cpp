/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

int SumaDjelilaca (long long int a) {
	int s(0);
	for (int i=1; i<=a; i++) {
		if (a%i==0) {
			s+=i;
		}
	}
	return s;
}

int BrojProstihFaktora (long long int a) {
	int s(0);
	for (int i=2; i<a; i++) {
		if (a%i==0) {
			int br(0);
			for (int j=2; j<i; j++) {
				if (i%j==0) {
					br++;
				}
			}
			if (br==0) {
				s++;
			}
		}
	}
	return s;
}

int SumaCifara (long long int a) {
	int s(0);
	while (a!=0) {
		s++;
		a/=10;
	}
	return s;
}

int BrojSavrsenihDjelilaca (long long int a) {
	int s(0);
	
	return s;
}

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>

auto UvrnutiPresjek (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f (Tip4)) -> std::deque<std::deque<Tip4>> {
	int br(0);
	std::deque<std::deque<Tip4>> m;
	while (p1 < p2) {
		while (p3 < p4) {
			if (f(*p1) == f(*p3)) {
				m.resize(br);
				m[br].push_back(*p1);
				m[br].push_back(*p2);
				m[br].push_back(f(*p1));
				br++;
			}
			p3++;
		}
		p1++;
	}
	return m;
}

int main () {
	int a;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> a;
	std::deque<long long int> d1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for (int i=0; i<a; i++) {
		long long int x;
		std::cin >> x;
		d1.push_back(x);
	}
	int b;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> b;
	std::deque<long long int> d2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i=0; i<b; i++) {
		long long int x;
		std::cin >> x;
		d2.push_back(x);
	}
	std::deque<std::deque<long long int>> m1(UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara));
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	for (int i=0; i<m1.size(); i++) {
		for (int j=0; j<m1[i].size(); j++) {
			std::cout << std::setw(6) << m1[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}
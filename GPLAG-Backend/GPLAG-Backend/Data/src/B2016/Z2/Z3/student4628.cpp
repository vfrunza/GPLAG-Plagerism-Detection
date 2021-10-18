/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
typedef std::deque<long long int> Dek;
typedef std::vector<long long int> Vektor;
typedef std::vector<std::vector<long long int>> Matrica;

int SumaDjelilaca (long long int n)
{
	int suma(0);
	for(int i = 1; i <= abs(n); i++) {
		if(n % i == 0)
		suma += i;
	}
	
	return suma;
}

int BrojProstihFaktora (long long int n)
{
	int broj(0), x(n);
	for(int i = 2; i <= abs(n); i++) {
		if(x % i == 0) {
			bool prost(true);
			for(int j = 2; j < i; j++) {
				if(i % j == 0) {
					prost = false;
					break;
				}
			}
			if(prost) {
				broj++;
				x /= i;
				i--;
			}
		}
		if(x == 1) break;
	}
	return broj;
}

bool SavrsenBroj(long long int n)
{
	int suma(0);
	bool savrsen(false);
	for(int i = 1; i < abs(n); i++) {
		if(n % i == 0) {
			suma += i;
		}
	}
	if(suma == n) savrsen = true;

	return savrsen;
}
int BrojSavrsenihDjelilaca (long long int n)
{
	int br(0);
	for(int i = 1; i <= abs(n); i++) {
		if(n % i == 0)
			if(SavrsenBroj(i)) br++;
	}
	return br;
}

int SumaCifara(long long int n)
{
	int suma(0);
	while (n != 0) {
		suma += abs(n % 10);
		n /= 10;
	}
	return suma;
}

template <typename PokTip1, typename PokTip2, typename NekiTip, typename Tip>
auto UvrnutiPresjek(PokTip1 pocetak1, PokTip1 iza_kraja1, PokTip2 pocetak2, PokTip2 iza_kraja2, NekiTip f (Tip)) ->std::vector<std::vector<decltype(*pocetak1 + *pocetak1)>> {

	std::vector<std::vector<decltype(*pocetak1 + *pocetak1)>> mat;
	std::vector<decltype(*pocetak1 + *pocetak1)> pomocni;

	PokTip2 p = pocetak2;

	while(pocetak1 != iza_kraja1) {
		p = pocetak2;
		decltype(*pocetak1 + *pocetak1) rez1 (f(*pocetak1));

		while(p != iza_kraja2) {
			decltype(*pocetak1 + *pocetak1)	rez2 = f(*p);
			if(rez1 == rez2) {
				pomocni.push_back(*pocetak1);
				pomocni.push_back(*p);
				pomocni.push_back(rez1);

				mat.push_back(pomocni);
				pomocni.clear();
			}

			p++;
		}

		pocetak1++;
	}

	std::sort(mat.begin(), mat.end(), [](std::vector<decltype(*pocetak1 + *pocetak1)> red1, std::vector<decltype(*pocetak1 + *pocetak1)> red2)->bool {
		if(red1[2] == red2[2]) {
			if(red1[0] == red2[0])
				return red1[1] < red2[1];
			else return red1[0] < red2[0];
		}
		return red1[2] < red2[2];
	});

	return mat;
}

template <typename PokTip1, typename PokTip2>
auto UvrnutiPresjek(PokTip1 pocetak1, PokTip1 iza_kraja1, PokTip2 pocetak2, PokTip2 iza_kraja2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type >> {

	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> pomocni;

	PokTip2 p = pocetak2;

	while(pocetak1 != iza_kraja1) {
		p = pocetak2;

		while(p != iza_kraja2) {
			if(*pocetak1 == *p) {
				pomocni.push_back(*pocetak1);
				pomocni.push_back(0);
				pomocni.push_back(0);

				mat.push_back(pomocni);
				pomocni.clear();
			}
			p++;
		}

		pocetak1++;
	}
	return mat;
}

template <typename PokTip1, typename PokTip2>
auto UvrnutaRazlika(PokTip1 pocetak1, PokTip1 iza_kraja1, PokTip2 pocetak2, PokTip2 iza_kraja2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {

	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> mat;
	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> pomocni;

	PokTip1 p = pocetak1;
	PokTip2 q = iza_kraja2;

	while(iza_kraja2 != pocetak2) {
		p = pocetak1;
		bool ima(false);

		while(p != iza_kraja1) {
			if(*(iza_kraja2 - 1) == *p) {
				ima = true;
				break;
			}
			p++;
		}
		if(ima == false) {
			pomocni.push_back(*(iza_kraja2 - 1));
			pomocni.push_back(0);

			mat.push_back(pomocni);
			pomocni.clear();
		}
		iza_kraja2--;
	}

	iza_kraja2 = q;

	while(pocetak1 != iza_kraja1) {
		q = pocetak2;
		bool ima(false);

		while(q != iza_kraja2) {
			if(*pocetak1 == *q) {
				ima = true;
				break;
			}
			q++;
		}
		if(ima == false) {
			pomocni.push_back(*pocetak1);
			pomocni.push_back(0);

			mat.push_back(pomocni);
			pomocni.clear();
		}
		pocetak1++;
	}
	return mat;
}
template < typename PokTip1, typename PokTip2, typename NekiTip, typename Tip>
auto UvrnutaRazlika(PokTip1 pocetak1, PokTip1 iza_kraja1, PokTip2 pocetak2, PokTip2 iza_kraja2, NekiTip f (Tip)) -> std::vector<std::vector<decltype(*pocetak1 + *pocetak1)>> {
	std::vector<std::vector<decltype(*pocetak1 + *pocetak1)>> mat;
	std::vector<decltype(*pocetak1 + *pocetak1)> pomocni;

	PokTip1 q = pocetak1;
	PokTip2 p = pocetak2;

	while(pocetak1 != iza_kraja1) {
		bool ima1(false);
		decltype(*pocetak1 + *pocetak1) rez1 = f(*pocetak1);

		while(p != iza_kraja2) {
			decltype(*pocetak1 + *pocetak1) rez2 = f(*p);
			if(rez1 == rez2) {
				ima1 = true;
				break;
			}
			p++;
		}

		if(ima1 == false) {
			pomocni.push_back(*pocetak1);
			pomocni.push_back(rez1);
			mat.push_back(pomocni);
			pomocni.clear();
		}
		p = pocetak2;
		pocetak1++;
	}
	pocetak1 = q;

	while(pocetak2 != iza_kraja2) {
		bool ima2(false);

		decltype(*pocetak1 + *pocetak1) rez3 = f(*pocetak2);

		while(q != iza_kraja1) {
			decltype(*pocetak1 + *pocetak1) rez4 = f(*q);
			if(rez3 == rez4) {
				ima2 = true;
				break;
			}
			q++;
		}
		if(ima2 == false) {
			pomocni.push_back(*pocetak2);
			pomocni.push_back(rez3);
			mat.push_back(pomocni);
			pomocni.clear();
		}

		q = pocetak1;
		pocetak2++;
	}

	std::sort(mat.begin(), mat.end(), [](std::vector<decltype(*pocetak1 + *pocetak1)> red1, std::vector<decltype(*pocetak1 + *pocetak1)> red2) -> bool
	{
		if(red1[0] == red2[0]) {
			if(red1[1]==red2[1])
				return red1[1] > red2[1];
		}
		return red1[0] > red2[0];
	});

	return mat;
}

int main()
{
	int n;
	cout << "Unesite broj elemenata prvog kontejnera: ";
	cin >> n;
	cout << "Unesite elemente prvog kontejnera: ";
	Dek kont1;

	long long y;
	cin >> y;
	kont1.push_back(y);

	for(int i = 1; i < n; i++) {
		cin >> y;
		bool ima = false;
		for(int j = 0; j < kont1.size(); j++) {
			if(y == kont1[j]) {
				ima = true;
				break;
			}
		}
		if(ima)
			i--;
		else kont1.push_back(y);

	}
	cin.clear();
	cin.ignore(100, '\n');

	int m;
	cout << "Unesite broj elemenata drugog kontejnera: ";
	cin >> m;
	cout << "Unesite elemente drugog kontejnera: ";
	Dek kont2;

	long long int x;
	cin >> x;
	kont2.push_back(x);

	for(int i = 1; i < m; i++) {
		cin >> x;

		bool ima = false;
		for(int j = 0; j < kont2.size(); j++) {
			if(x == kont2[j]) {
				ima = true;
				break;
			}
		}
		if(ima)
			i--;
		else kont2.push_back(x);

	}

	/*	for(auto x: kont1) cout << x << " ";
		cout << endl;
		for(auto y: kont2) cout << y << " ";
	*/
	auto matrica_presjeka (UvrnutiPresjek(kont1.begin(), kont1.end(), kont2.begin(), kont2.end(), SumaCifara));

	cout << "Uvrnuti presjek kontejnera: " << endl;
	for(int i = 0; i < matrica_presjeka.size(); i++) {
		for(int j = 0; j < matrica_presjeka.at(i).size(); j++)
			cout << std::setw(6) << matrica_presjeka.at(i).at(j) << " ";
		cout << endl;

	}

	auto matrica_razlike (UvrnutaRazlika(kont1.begin(), kont1.end(), kont2.begin(), kont2.end(), BrojProstihFaktora));

	cout << "Uvrnuta razlika kontejnera: " << endl;
	for(int i = 0; i < matrica_razlike.size(); i++) {
		for(int j = 0; j < matrica_razlike.at(i).size(); j++)
			cout << std::setw(6) << matrica_razlike.at(i).at(j) << " ";
		cout << endl;
	}

	cout << "Dovidjenja!";

	return 0;
}
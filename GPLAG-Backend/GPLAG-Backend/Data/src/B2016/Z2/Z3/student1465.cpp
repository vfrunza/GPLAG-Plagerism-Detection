/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iomanip>
using namespace std;


template <typename tip>
auto vratiIsto(tip param) -> decltype(param)
{
	return param;
}

//Funkcija uvrnuti presjek sa pet parametara
template <typename itip1, typename itip2, typename ftip>
auto UvrnutiPresjek(itip1 poc1, itip1 kraj1, itip2 poc2, itip2 kraj2, ftip fun = vratiIsto) -> vector<vector<decltype(*poc1 + *poc1)>> {
	vector<vector<decltype(*poc1 + *poc1)>> matrica;
	while(poc1 != kraj1) {
		auto walker = poc2;
		while(walker != kraj2) {

			if(fun(*poc1) == fun(*walker)) {
				matrica.push_back(vector<decltype(*poc1 + *poc1)> {*poc1, *walker, fun(*poc1)});
			}
			walker++;
		}
		poc1++;
	}
	sort(matrica.begin(), matrica.end(), [](vector<decltype(*poc1 + *poc1)> v1, vector<decltype(*poc1 + *poc1)> v2) {
		if(v1[2] != v2[2]) return v1[2] < v2[2];
		if(v1[0] != v2[0]) return v1[0] < v2[0];
		return v1[1] < v2[1];
	});
	return matrica;
}

//Funkcija uvrnuti presjek sa cetiri parametra
template <typename itip1, typename itip2>
auto UvrnutiPresjek(itip1 poc1, itip1 kraj1, itip2 poc2, itip2 kraj2) -> vector<vector<decltype(*poc1 + *poc1)>> {
	vector<vector<decltype(*poc1 + *poc1)>> matrica;
	while(poc1 != kraj1) {
		auto walker = poc2;
		while(walker != kraj2) {

			if(*poc1 == *walker) {
				matrica.push_back(vector<decltype(*poc1 + *poc1)> {*poc1, 0, 0});
			}
			walker++;
		}
		poc1++;
	}
	sort(matrica.begin(), matrica.end(), [](vector<decltype(*poc1 + *poc1)> v1, vector<decltype(*poc1 + *poc1)> v2) {
		if(v1[2] != v2[2]) return v1[2] < v2[2];
		if(v1[0] != v2[0]) return v1[0] < v2[0];
		return v1[1] < v2[1];
	});
	return matrica;
}

//Uvrnuta razlika sa pet parametara
template <typename itip1, typename itip2, typename ftip>
auto UvrnutaRazlika(itip1 poc1, itip1 kraj1, itip2 poc2, itip2 kraj2, ftip fun = vratiIsto) -> vector<vector<decltype(*poc1 + *poc1)>> {
	vector<vector<decltype(*poc1 + *poc1)>> matrica;
	auto walker1 = poc1;
	while(walker1 != kraj1) {
		bool nemapara = true;
		auto walker2 = poc2;
		while(walker2 != kraj2) {
			if(fun(*walker1) == fun(*walker2)) {
				nemapara = false;
				break;
			}
			walker2++;
		}
		if(nemapara) {
			matrica.push_back(vector<decltype(*poc1 + *poc1)> {*walker1, fun(*walker1)});
		}
		walker1++;
	}

	auto walker2 = poc2;
	while(walker2 != kraj2) {
		bool nemapara = true;
		auto walker1 = poc1;
		while(walker1 != kraj1) {
			if(fun(*walker2) == fun(*walker1)) {
				nemapara = false;
				break;
			}
			walker1++;
		}
		if(nemapara) {
			matrica.push_back(vector<decltype(*poc1 + *poc1)> {*walker2, fun(*walker2)});
		}
		walker2++;
	}
	sort(matrica.begin(), matrica.end(), [](vector<decltype(*poc1 + *poc1)> v1, vector<decltype(*poc1 + *poc1)> v2) {
		if(v1[0] != v2[0]) return v1[0] > v2[0];
		return v1[1] > v2[1];
	});
	return matrica;
}

//uvrnuta razlika sa cetiri parametra
template <typename itip1, typename itip2>
auto UvrnutaRazlika(itip1 poc1, itip1 kraj1, itip2 poc2, itip2 kraj2) -> vector<vector<decltype(*poc1 + *poc1)>> {
	vector<vector<decltype(*poc1 + *poc1)>> matrica;
	auto walker1 = poc1;
	while(walker1 != kraj1) {
		bool nemapara = true;
		auto walker2 = poc2;
		while(walker2 != kraj2) {
			if(*walker1 == *walker2) {
				nemapara = false;
				break;
			}
			walker2++;
		}
		if(nemapara) {
			matrica.push_back(vector<decltype(*poc1 + *poc1)> {*walker1, 0});
		}
		walker1++;
	}

	auto walker2 = poc2;
	while(walker2 != kraj2) {
		bool nemapara = true;
		auto walker1 = poc1;
		while(walker1 != kraj1) {
			if(*walker2 == *walker1) {
				nemapara = false;
				break;
			}
			walker1++;
		}
		if(nemapara) {
			matrica.push_back(vector<decltype(*poc1 + *poc1)> {*walker2, 0});
		}
		walker2++;
	}
	sort(matrica.begin(), matrica.end(), [](vector<decltype(*poc1 + *poc1)> v1, vector<decltype(*poc1 + *poc1)> v2) {
		if(v1[0] != v2[0]) return v1[0] > v2[0];
		return v1[1] > v2[1];
	});
	return matrica;
}


//FUNKCIJE
int SumaDjelilaca(long long int broj)
{
	int suma {0};
	for(int i {1}; i <= broj; i++) {
		if(broj % i == 0) {
			suma += i;
		}
	}
	return suma;
}

int BrojProstihFaktora(long long int n)
{
	int brojac {0};
	bool prosti_faktor;
	for(int i = 2; i <= n; i++) {
		prosti_faktor = true;
		if(n%i != 0) continue;
		for(int j = 2; j < i; j++) {
			if(i%j == 0) {
				prosti_faktor = false;
				break;
			}
		}
		if(prosti_faktor)
		{
			while(n%i == 0)
			{
				brojac++;
				n /= i;
			}
		}
	}
	return brojac;
}

bool DaLiJeSavrsen(long long int n)
{
	long long int suma {0};
	for(long long int i {1}; i < n; i++) {
		if(n % i == 0) {
			suma += i;
		}
	}
	if(n == suma) return true;
	return false;
}
int BrojSavrsenihDjelilaca(long long int n)
{
	int brojac {0};
	for(long long int i {1}; i <= n; i++) {
		if(n % i == 0 && (DaLiJeSavrsen(i) == true)) {
			brojac++;
		}
	}
	return brojac;
}
bool DaLiJeuDeku(deque<int> dek, int n)
{
	for(int i {0}; i < dek.size(); i++) {
		if(dek[i] == n) return true;
	}
	return false;
}

int SumaCifri(long long int n)
{
	int suma {0};
	while(n != 0) {
		suma += abs(n%10);
		n/=10;
	}
	return suma;
}

int main ()
{
	int n, m;
	cout << "Unesite broj elemenata prvog kontejnera: ";
	cin >> n;
	deque<int> dek1;
	cout << "Unesite elemente prvog kontejnera: ";
	int broj;
	for(int i {0}; i < n; i++) {
		cin >> broj;
		if(DaLiJeuDeku(dek1, broj) == true) {
			i--;
			continue;
		} 
		else dek1.push_back(broj);
	}

	cout << "Unesite broj elemenata drugog kontejnera: ";
	cin >> m;
	deque<int> dek2;
	cout << "Unesite elemente drugog kontejnera: ";
	for(int i {0}; i < m; i++) {
		cin >> broj;
		if(DaLiJeuDeku(dek2, broj) == true) {
			i--;
			continue;
		} 
		else dek2.push_back(broj);
	}

	auto presjek = UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifri);

	cout << "Uvrnuti presjek kontejnera: " << endl;
	for(int i {0}; i < presjek.size(); i++) {
		for(int j {0}; j < presjek[i].size(); j++)
			cout << setw(6) << presjek[i][j] << " ";
		cout << endl;
	}

	auto razlika = UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	cout << "Uvrnuta razlika kontejnera: " << endl;
	for(int i {0}; i < razlika.size(); i++) {
		for(int j {0}; j < razlika[i].size(); j++)
			cout << setw(6) << razlika[i][j] << " ";
		cout << endl;
	}
	cout << "Dovidjenja!";
	return 0;
}

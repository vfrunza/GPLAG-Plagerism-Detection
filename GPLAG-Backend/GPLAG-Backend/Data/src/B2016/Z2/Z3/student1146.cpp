/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>

using std::vector;
using std::deque;

#define tip typename std::remove_reference<decltype(*a)>::type

template <typename T, typename F>
auto izracunaj(T a, T b, F f)
-> vector<tip>
{
	vector<tip> rez;
	for (auto i = a; i != b; i++)
		rez.push_back(f(*i));
	return rez;
}

template <typename T, typename U, typename F>
auto UvrnutiPresjek(T a, T b, U c, U d, F f)
-> vector<vector<tip>>
{
	vector<vector<tip>> rez;
	
	auto val2 = izracunaj(c, d, f);
	
	for (auto i = a; i != b; i++) {
		auto prvi = *i;
		auto val = f(prvi);
		int br = 0;
		for (auto j = c; j != d; j++) {
			auto drugi = *j;
			if (val == val2[br])
				rez.push_back({prvi, drugi, val});
			br++;
		}
	}
	typedef tip t;
	std::sort(rez.begin(), rez.end(), 
		[](const vector<t>& a, const vector<t>& b) {
			if (a[2] != b[2]) return a[2] < b[2];
			if (a[0] != b[0]) return a[0] < b[0];
			return a[1] < b[1];
		}
	);
	
	
	return rez;
}

template <typename T, typename U>
auto UvrnutiPresjek(T a, T b, U c, U d)
-> vector<vector<tip>>
{
	vector<vector<tip>> rez;
	for (auto it = a; it != b; it++) 
		if (std::find(c, d, *it) != d)
			rez.push_back({*it, 0, 0});
			
	typedef tip t;
	std::sort(rez.begin(), rez.end(),
		[] (const vector<t>& a, const vector<t>& b) {
			return a[0] < b[0];
		}
	);
	return rez;
}

template <typename T, typename U, typename F>
auto UvrnutaRazlika(T a, T b, U c, U d, F f)
-> vector<vector<tip>>
{
	vector<vector<tip>> rez;
	
	auto val1 = izracunaj(a, b, f);
	auto val2 = izracunaj(c, d, f);
	
	int i = 0;
	for (auto it = a; it != b; it++) {
		if (std::find(val2.begin(), val2.end(), val1[i]) == val2.end())
			rez.push_back({*it, val1[i]});
		i++;
	}
	
	i = 0;
	for (auto it = c; it != d; it++) {
		if (std::find(val1.begin(), val1.end(), val2[i]) == val1.end())
			rez.push_back({*it, val2[i]});
		i++;
	}
	typedef tip t;
	std::sort(rez.begin(), rez.end(), 
		[] (const vector<t>& a, const vector<t>& b) {
			if (a[0] != b[0]) return b[0] < a[0];
			return b[1] < a[1];
		}
	);
	return rez;
}

template <typename T, typename U>
auto UvrnutaRazlika(T a, T b, U c, U d)
-> vector<vector<tip>>
{
	vector<vector<tip>> rez;
	for (auto it = a; it != b; it++) 
		if (std::find(c, d, *it) == d)
			rez.push_back({*it, 0});
	for (auto it = c; it != d; it++)
		if (std::find(a, b, *it) == b)
			rez.push_back({*it, 0});
	
	typedef tip t;
	std::sort(rez.begin(), rez.end(),
		[] (const vector<t>& a, const vector<t>& b) {
			return b[0] < a[0];
		}
	);
	return rez;
}

int BrojProstihFaktora(long long int x) {
	int rez = 0;
	if (x < 0) x = -x;
	long long int i = 2;
	while (i <= x) {
		if (x % i == 0) {
			rez++;
			x /= i;
		} else {
			i++;
		}
	}
	return rez;
}

int SumaDjelilaca(long long int x) {
	int rez = 0;
	for (long long int i = 1; i <= x; i++) 
		if (x % i == 0)
			rez += i;
	return rez;
}

bool savrsen(long long int x) {
	long long int s = 0;
	for (long long int i = 1; i < x; i++)
		if (x % i == 0)
			s += i;
	return s == x;
}

int BrojSavrsenihDjelilaca(long long int x) {
	int rez = 0;
	if (x < 0) x = -x;
	for (long long int i = 6; i <= x; i++)
		if (x % i == 0 && savrsen(i))
			rez++;
	return rez;
}

int main() {
	using std::cout;
	using std::cin;
	
	auto unesi = [](const char* ime) {
		cout << "Unesite broj elemenata " << ime << " kontejnera: ";
		int n;
		cin >> n;
		cout << "Unesite elemente " << ime << " kontejnera: ";
		deque<int> rez;
		while (rez.size() < n) {
			int x;
			cin >> x;
			if (std::find(rez.begin(), rez.end(), x) == rez.end())
				rez.push_back(x);
		}
		return rez;
	};
	
	auto a = unesi("prvog");
	auto b = unesi("drugog");
	
	auto presjek = UvrnutiPresjek(a.begin(), a.end(), b.begin(), b.end(), 
		[](int x) {
			int rez = 0;
			if (x < 0) x = -x;
			while (x) {
				rez += x % 10;
				x /= 10;
			}
			return rez;
		}
	);
	cout << "Uvrnuti presjek kontejnera:\n";
	for (auto const& red : presjek) {
		for (int x : red)
			cout << std::setw(6) << x << ' ';
		cout << '\n';
	}
	
	auto razlika = UvrnutaRazlika(a.begin(), a.end(), b.begin(), b.end(), BrojProstihFaktora);
	cout << "Uvrnuta razlika kontejnera:\n";
	for (auto const& red : razlika) {
		for (int x : red)
			cout << std::setw(6) << x << ' ';
		cout << '\n';
	}
	cout << "Dovidjenja!";
	return 0;
}
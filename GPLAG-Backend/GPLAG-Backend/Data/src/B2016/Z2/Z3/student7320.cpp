/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define pb push_back

typedef int lint; // vektore vektora u predloscima funkcija staviti da su int!!!

std::vector<lint> NadjiDjelioce(lint n) {
	std::vector<lint> ret;
	if (n < 0) return ret;
	for (lint i = 1; i <= n; i++)
		if (n % i == 0) ret.pb(i);
	return ret;
}
bool JeLiProstBroj(lint x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	for (lint i = 2; i < x; i++)
		if (x % i == 0) return 0;
	return 1;
}
bool JeLiSavrsenBroj(lint x) {
	lint suma = 0;
	std::vector<lint> SviDjelioci = NadjiDjelioce(x);
	for (int i = 0; i < SviDjelioci.size() - 1; i++) suma += SviDjelioci.at(i);
	return (suma == x);
}
int SumaDjelilaca(lint n) {
	int ret = 0;
	std::vector<lint> SviDjelioci = NadjiDjelioce(n);
	for (const lint &x : SviDjelioci) ret += x;
	return ret;
}
int SumaCifaraBroja(lint n) {
	int ret = 0;
	while (n) {
		ret += (n % 10);
		n /= 10;
	}
	return ret;
}
int BrojProstihFaktora(lint n) {
	int ret = 0;
	std::vector<lint> SviDjelioci = NadjiDjelioce(n);
	for (const lint &x : SviDjelioci) {
		if (x != 1 && JeLiProstBroj(x)) {
			while (n % x == 0) {
				n /= x;
				ret++;
			}
		}
	}
	return ret;
}
int BrojSavrsenihDjelilaca(lint n) {
	int ret = 0;
	std::vector<lint> SviDjelioci = NadjiDjelioce(n);
	for (const lint &x : SviDjelioci) if (JeLiSavrsenBroj(x)) ret++;
	return ret;
}

template<typename Tip1, typename Tip2>
std::vector<std::vector<lint> > UvrnutiPresjek(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, int f(lint)) {
	std::vector<std::vector<lint> > ret;
	std::vector<lint> temporarni;
	
	for (Tip1 x = poc1; x != kraj1; x++) {
		int val1 = f(*x);
		for (Tip2 y = poc2; y != kraj2; y++) {
			int val2 = f(*y);
			if (val1 == val2) {
				temporarni.pb(*x); temporarni.pb(*y); temporarni.pb(val1);
				ret.pb(temporarni);
				temporarni.clear();
			}
		}
	}
	std::sort(ret.begin(), ret.end(), [](std::vector<lint> a, std::vector<lint> b) -> bool {
		if (a.at(2) != b.at(2)) return a.at(2) < b.at(2);
		if (a.at(2) == b.at(2)) {
			if (a.at(0) != b.at(0)) return a.at(0) < b.at(0);
			if (a.at(0) == b.at(0)) return a.at(1) < b.at(1);
		}	
	});
	return ret;
}

template<typename Tip1, typename Tip2>
std::vector<std::vector<lint> > UvrnutiPresjek(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2) {
	std::vector<std::vector<lint> > ret;
	std::vector<lint> temporarni;
	
	for (Tip1 x = poc1; x != kraj1; x++)
		for (Tip2 y = poc2; y != kraj2; y++) {
			int val1 = *x;
			int val2 = *y;
			if (val1 == val2) {
				temporarni.pb(val1); temporarni.pb(0); temporarni.pb(0);
				ret.pb(temporarni);
				temporarni.clear();
			}
		}
	std::sort(ret.begin(), ret.end(), [](std::vector<lint> a, std::vector<lint> b) {
		if (a.at(2) != b.at(2)) return a.at(2) < b.at(2);
		if (a.at(2) == b.at(2)) {
			if (a.at(0) != b.at(0)) return a.at(0) < b.at(0);
			if (a.at(0) == b.at(0)) return a.at(1) < b.at(1);
		}	
	});
	return ret;
}

template<typename Tip1, typename Tip2>
std::vector<std::vector<lint> > UvrnutaRazlika(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, int f(lint)) {
	std::vector<std::vector<lint> > ret;
	std::vector<lint> temporarni;
	
	for (Tip1 x = poc1; x != kraj1; x++) {
		int val1 = f(*x);
		bool imaPar = 0;
		for (Tip2 y = poc2; y != kraj2; y++) { 
			int val2 = f(*y);
			if (val1 == val2) {
				imaPar = 1;
				break;
			}
		}
		if (!imaPar) {
			temporarni.pb(*x); temporarni.pb(val1);
			ret.pb(temporarni);
			temporarni.clear();
		}
	}
	for (Tip1 x = poc2; x != kraj2; x++) {
		int val1 = f(*x);
		bool imaPar = 0;
		for (Tip2 y = poc1; y != kraj1; y++) {
			int val2 = f(*y);
			if (val1 == val2) {
				imaPar = 1;
				break;
			}
		}
		if (!imaPar) {
			temporarni.pb(*x); temporarni.pb(val1);
			ret.pb(temporarni);
			temporarni.clear();
		}
	}
	std::sort(ret.begin(), ret.end(), [](std::vector<lint> a, std::vector<lint> b) -> bool {
		if (a.at(0) == b.at(0)) return a.at(1) < b.at(1);
		return a.at(0) > b.at(0);
	});
	return ret;
}

template<typename Tip1, typename Tip2>
std::vector<std::vector<lint> > UvrnutaRazlika(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2) {
	std::vector<std::vector<lint> > ret;
	std::vector<lint> temporarni;
	
	for (Tip1 x = poc1; x != kraj1; x++) {
		int val1 = *x;
		bool imaPar = 0;
		for (Tip2 y = poc2; y != kraj2; y++) {
			int val2 = *y;
			if (val1 == val2) {
				imaPar = 1;
				break;
			}
		}
		if (!imaPar) {
			temporarni.pb(*x); temporarni.pb(0);
			ret.pb(temporarni);
			temporarni.clear();
		}
	}
	for (Tip1 x = poc2; x != kraj2; x++) {
		int val1 = *x;
		bool imaPar = 0;
		for (Tip2 y = poc1; y != kraj1; y++) {
			int val2 = *y;
			if (val1 == val2) {
				imaPar = 1;
				break;
			}
		}
		if (!imaPar) {
			temporarni.pb(*x); temporarni.pb(0);
			ret.pb(temporarni);
			temporarni.clear();
		}
	}
	std::sort(ret.begin(), ret.end(), [](std::vector<lint> a, std::vector<lint> b) -> bool {
		if (a.at(0) == b.at(0)) return a.at(1) < b.at(1);
		return a.at(0) > b.at(0);
	});
	return ret;
}
int main() {
	//AT20 - negativni brojevi po sumi djelilaca
//Djeliocima broja smatraju se samo prirodni brojevi.
	std::deque<int> d1{-2, -1, 0, 43, -5, 10, 11}, d2{2, -1, 0, 5, -10, 23};
    std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaDjelilaca)};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaDjelilaca)};
	
	for (std::vector<int>& red : v1)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
}
int main2 ()
{
	//for (int i = 1; i <= 99; i++)
	//	std::cout << i << " = " << BrojProstihFaktora(i) << "\n";
	int n1, n2;
	lint tmp;
	std::deque<lint> dq1, dq2;
	std::vector<std::vector<lint> > rj1, rj2;
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for (int i = 0; i < n1; i++) { 
		std::cin >> tmp; 
		
		bool jelUDeku = 0;
		for (int j = 0; j < dq1.size(); j++) if (tmp == dq1.at(j)) { jelUDeku = 1; break; }
		if (!jelUDeku) dq1.pb(tmp); 
		else i--;
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i = 0; i < n2; i++) { 
		std::cin >> tmp; 
		
		bool jelUDeku = 0;
		for (int j = 0; j < dq2.size(); j++) if (tmp == dq2.at(j)) { jelUDeku = 1; break; }
		if (!jelUDeku) dq2.pb(tmp); 
		else i--;
	}
	
	std::cout << "Uvrnuti presjek kontejnera:\n";
	rj1 = UvrnutiPresjek(dq1.begin(), dq1.end(), dq2.begin(), dq2.end(), SumaCifaraBroja);

	for (int i = 0; i < rj1.size(); i++) {
		for (int j = 0; j < rj1.at(i).size(); j++)
			std::cout.width(6), std::cout << rj1.at(i).at(j) << " ";
		std::cout << "\n";
	}
	std::cout << "Uvrnuta razlika kontejnera:\n";
	rj2 = UvrnutaRazlika(dq1.begin(), dq1.end(), dq2.begin(), dq2.end(), BrojProstihFaktora);
	
	for (int i = 0; i < rj2.size(); i++) {
		for (int j = 0; j < rj2.at(i).size(); j++)
			std::cout.width(6), std::cout << rj2.at(i).at(j) << " ";
		std::cout << "\n";
	}
	std::cout << "Dovidjenja!\n";
	return 0;
}
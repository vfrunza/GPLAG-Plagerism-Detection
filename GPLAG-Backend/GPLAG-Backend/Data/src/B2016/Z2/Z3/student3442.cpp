#include <iostream>
#include <iomanip>
#include <deque>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <type_traits>

int SumaDjelilaca(int x) {
	if(x < 0) x *= -1;
	int suma = 0;
	for(int i = 1; i <= x; i++) {
		if(x % i == 0)
			suma += i;
	}
	return suma;
}
bool daLiJeSavrsen(int x) {
	int sumaDjelioca = 0;
	for(int i = 1; i < x; i++) {
		if(x % i == 0) {
			sumaDjelioca += i;
		}
	}
	if(sumaDjelioca == x) return true;
	return false;
}
int BrojSavrsenihDjelilaca(int x) {
	int brojac = 0;
	for(int i = 1; i <= x; i++) {
		if(x % i == 0) {
			if(daLiJeSavrsen(i)) {
				brojac++;
			}
		}
	} 
	return brojac;
}
int BrojProstihFaktora(int x) {
	if(x == 1) return 1;
	int brojac = 0; 
	int djelioc = 2;
	while(x != 1) {
		if(x % djelioc == 0) {
			brojac++;
			x /= djelioc;
		} else djelioc++;
	}
	return brojac;
}
int SumaCifre(int x) {
	int suma = 0;
	while(x != 0) {
		suma += x%10;
		x /= 10;
	}
	return suma;
}

template<typename T1, typename T2, typename TipKriterij>
std::vector<std::vector<TipKriterij>> UvrnutiPresjek(T1 pok1, T1 pok2, T2 pok3, T2 pok4, TipKriterij F(TipKriterij)) {
	std::vector<TipKriterij> pomocni;
	std::vector<std::vector<TipKriterij>> m;
	for(auto x = pok1; x != pok2; x++) {
		for(auto y = pok3; y != pok4; y++) {
			if(F(*x) == F(*y)) {
				pomocni.push_back(*x);
				pomocni.push_back(*y);
				pomocni.push_back(F(*x));
				m.push_back(pomocni);
				pomocni.erase(pomocni.begin(), pomocni.end());
			}
		}
	}
	
	std::sort(m.begin(), m.end(), [] (const std::vector<TipKriterij> &a, const std::vector<TipKriterij> &b) {
		if(a[2] < b[2]) return true;
		else if(a[2] == b[2]) {
			if(a[0] < b[0]) return true;
			else if(a[0] == b[0]) {
				if(a[1] < b[1]) return true;
			}
		}
		return false;
	}); 
	m.erase(std::unique(m.begin(), m.end()), m.end());
	
	return m;
}

template<typename T1, typename T2>
auto UvrnutiPresjek(T1 pok1, T1 pok2, T2 pok3, T2 pok4) 
	-> std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>> {
		
	
	std::vector<typename std::remove_reference<decltype(*pok1)>::type> pomocni;
	std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>> m;
	for(auto x = pok1; x != pok2; x++) {
		for(auto y = pok3; y != pok4; y++) {
			if(*x == *y) {
				pomocni.push_back(*x);
				pomocni.push_back(0);
				pomocni.push_back(0);
				m.push_back(pomocni);
				pomocni.erase(pomocni.begin(), pomocni.end());
			}
		}
	}
	
	std::sort(m.begin(), m.end(), [] (const std::vector<typename std::remove_reference<decltype(*pok1)>::type> &a, const std::vector<typename std::remove_reference<decltype(*pok1)>::type> &b) {
		if(a[2] < b[2]) return true;
		else if(a[2] == b[2]) {
			if(a[0] < b[0]) return true;
			else if(a[0] == b[0]) {
				if(a[1] < b[1]) return true;
			}
		}
		return false;
	}); 
	m.erase(std::unique(m.begin(), m.end()), m.end());
	
	return m;
}

template<typename T1, typename T2, typename TipKriterij>
std::vector<std::vector<TipKriterij>> UvrnutaRazlika(T1 pok1, T1 pok2, T2 pok3, T2 pok4, TipKriterij F(TipKriterij)) {
	std::vector<TipKriterij> pomocni;
	std::vector<std::vector<TipKriterij>> m;
	bool DaLiJeRazlicit;
	for(auto x = pok1; x != pok2; x++) {
		DaLiJeRazlicit = true;
		for(auto y = pok3; y != pok4; y++) {
			if(F(*x) == F(*y)) {
				DaLiJeRazlicit = false;
				break;
			}
		}
		if(DaLiJeRazlicit) {
			pomocni.push_back(*x);
			pomocni.push_back(F(*x));
			m.push_back(pomocni);
			pomocni.erase(pomocni.begin(), pomocni.end());
		}
	}
	
	for(auto x = pok3; x != pok4; x++) {
		DaLiJeRazlicit = true;
		for(auto y = pok1; y != pok2; y++) {
			if(F(*x) == F(*y)) {
				DaLiJeRazlicit = false;
				break;
			}
		}
		if(DaLiJeRazlicit) {
			pomocni.push_back(*x);
			pomocni.push_back(F(*x));
			m.push_back(pomocni);
			pomocni.erase(pomocni.begin(), pomocni.end());
		}
	}
	
	std::sort(m.begin(), m.end(), [](const std::vector<TipKriterij> &a, const std::vector<TipKriterij> &b) {
		return a[0] > b[0];
	}); 
	
	return m;	
}

template<typename T1, typename T2>
auto UvrnutaRazlika(T1 pok1, T1 pok2, T2 pok3, T2 pok4) 
		-> std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>> {
			
	std::vector<typename std::remove_reference<decltype(*pok1)>::type> pomocni;
	std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type>> m;
	bool DaLiJeRazlicit;
	for(auto x = pok1; x != pok2; x++) {
		DaLiJeRazlicit = true;
		for(auto y = pok3; y != pok4; y++) {
			if(*x == *y) {
				DaLiJeRazlicit = false;
				break;
			}
		}
		if(DaLiJeRazlicit) {
			pomocni.push_back(*x);
			pomocni.push_back(0);
			m.push_back(pomocni);
			pomocni.erase(pomocni.begin(), pomocni.end());
		}
	}
	
	for(auto x = pok3; x != pok4; x++) {
		DaLiJeRazlicit = true;
		for(auto y = pok1; y != pok2; y++) {
			if(*x == *y) {
				DaLiJeRazlicit = false;
				break;
			}
		}
		if(DaLiJeRazlicit) {
			pomocni.push_back(*x);
			pomocni.push_back(0);
			m.push_back(pomocni);
			pomocni.erase(pomocni.begin(), pomocni.end());
		}
	}
	
	std::sort(m.begin(), m.end(), [](const std::vector<typename std::remove_reference<decltype(*pok1)>::type> &a, const std::vector<typename std::remove_reference<decltype(*pok1)>::type> &b) {
		return a[0] > b[0];
	}); 
	
	return m;	
}

bool daLiJePrisutan(std::deque<int> v, int broj) {
	for(int i = 0; i < v.size(); i++) {
		if(v[i] == broj) return true;
	}
	return false;
}

int main() {
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int br1;
	std::cin >> br1;
	std::deque<int> v1;
	
	std::cout << "Unesite elemente prvog kontejnera: ";
	int broj = 0;
	for(int i = 0; i < br1; i++) {
		std::cin >> broj; 
		if(daLiJePrisutan(v1, broj) == false) {
			v1.push_back(broj);
		}
		else {
			i--;
			continue;
		}
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int br2;
	std::cin >> br2;
	std::deque<int> v2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	
	for(int i = 0; i < br2; i++) {
		std::cin >> broj; 
		if(daLiJePrisutan(v2, broj) == false) {
			v2.push_back(broj);
		}
		else {
			i--;
			continue;
		}
	}
	
	std::cout << "Uvrnuti presjek kontejnera:\n";
	auto m = UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(),v2.end(), SumaCifre);
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[0].size(); j++) {
			std::cout << std::setw(6) << m[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "Uvrnuta razlika kontejnera:\n";
	auto n = UvrnutaRazlika(v1.begin(), v1.end(), v2.begin(),v2.end(), BrojProstihFaktora);
	for(int i = 0; i < n.size(); i++) {
		for(int j = 0; j < n[0].size(); j++) {
			std::cout << std::setw(6) << n[i][j] << " ";
		}
		std::cout << "\n";
	}	
	std::cout << "Dovidjenja!";
	
	return 0;
}
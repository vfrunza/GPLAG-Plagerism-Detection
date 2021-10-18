/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/

#include <vector>
#include <string>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <deque>
#include <iomanip>



int BrojProstihFaktora (int n)
{
	int brojac(0);
	int djelilac(2);
	if (n == 0) return 0;
	while (n != 1) {
		if (n % djelilac != 0) djelilac++;
		else {
			n /= djelilac;
			brojac++;
		}
	}
	return brojac;
}

bool Savrsen (int n) 
{
	int suma1(0);
	for (int i = 1; i < n; i++) {
		if (n % i == 0) suma1 += i;
	}
	
	return suma1 == n;
}


int BrojSavrsenihDjelilaca (int n) 
{
	int brojac(0);
	for (int i = 2; i <= n; i++) {
		if (n % i == 0 and Savrsen(i)) brojac++;
	}
	return brojac;
}

int SumaDjelilaca(int n)
{
	int suma = 1;
	for (int i = 2; i*i <= n; i++) {
		int p = 1;
		while (n%i == 0) {
			p = p*i+1;
			n /= i;
		}
		suma *= p;
	}
	if (n > 1)
		suma *= 1 + n;
	return suma;
}

int SumaCifara (int n) 
{
	int suma(0);
	while (n !=0) {
		suma += abs(n%10);
		n /= 10;
	}
	return suma;
}

template <typename TipPok1,typename TipPok2,typename TipF_par,typename TipF_ret>
auto UvrnutiPresjek(TipPok1 p1,TipPok1 p2,TipPok2 p3, TipPok2 p4,TipF_ret fun(TipF_par)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> 
{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	auto poc(p3);
	while (p1 != p2) {
		p3 = poc;
		while (p3 != p4) {
			if (fun(*p1) == fun(*p3)) {
				Matrica.push_back({*p1,*p3,fun(*p1)});
			}
			p3++;
		}
		p1++;
	}
	
	std::sort(Matrica.begin(),Matrica.end(),[](std::vector<decltype(*p1+*p1)> v1,std::vector<decltype(*p1+*p1)> v2) {
		if (v1[2] < v2[2]) return true;
		if(v1[2] == v2[2]) {
			if(v1[0] < v2[0]) return true;
			if (v1[0] == v2[0]) {
				if (v1[1] < v2[1]) return true;
			}
			return false;
		}
		return false;
	});
	
	return Matrica;
}

template <typename TipPok1,typename TipPok2>
auto UvrnutiPresjek(TipPok1 p1,TipPok1 p2,TipPok2 p3, TipPok2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> 
{	
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	auto poc(p3);
	while (p1 != p2) {
		p3 = poc;
		while (p3 != p4) {
			if ((*p1) == (*p3)) {
				Matrica.push_back({*p1,decltype(*p3+*p3)(),decltype(*p1+*p1)()});
			}
			p3++;
		}
		p1++;
	}
	
	std::sort(Matrica.begin(),Matrica.end(),[](std::vector<decltype(*p1+*p1)> v1,std::vector<decltype(*p1+*p1)> v2) {
		if (v1[2] < v2[2]) return true;
		if(v1[2] == v2[2]) {
			if(v1[0] < v2[0]) return true;
			if (v1[0] == v2[0]) {
				if (v1[1] < v2[1]) return true;
			}
			return false;
		}
		return false;
	});
	
	return Matrica;
}
template <typename TipPok1,typename TipPok2,typename TipF_par,typename TipF_ret>
auto UvrnutaRazlika(TipPok1 p1,TipPok1 p2,TipPok2 p3, TipPok2 p4,TipF_ret fun(TipF_par)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> 
{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	auto poc(p3);
	auto poc2(p1);
	bool test(false);
	while (p1 != p2) {
		test = false;
		p3 = poc;
		while (p3 != p4) {
			if (fun(*p1) == fun(*p3)) {
				test = true;
				break;
			}
			p3++;
		}
		if (test == false) Matrica.push_back({*p1,fun(*p1)});
		p1++;
	}
	p3 = poc;
	while (p3 != p4) {
		test = false;
		p1 = poc2;
		while (p1 != p2) {
			if (fun(*p3) == fun(*p1)) {
				test = true;
				break;
			}
			p1++;
		}
		if (test == false) Matrica.push_back({*p3,fun(*p3)});
		p3++;
	}
	
	std::sort(Matrica.begin(),Matrica.end(),[](std::vector<decltype(*p1+*p1)> v1,std::vector<decltype(*p1+*p1)> v2) {
		if (v1[0] > v2[0]) return true;
		if(v1[0] == v2[0]) {
			if(v1[1] < v2[1]) return true;
			return false;
		}
		return false;
	});
	
	return Matrica;
}



template <typename TipPok1,typename TipPok2>
auto UvrnutaRazlika(TipPok1 p1,TipPok1 p2,TipPok2 p3, TipPok2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> 
{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	auto poc(p3);
	auto poc2(p1);
	bool test(false);
	while (p1 != p2) {
		test = false;
		p3 = poc;
		while (p3 != p4) {
			if ((*p1) == (*p3)) {
				test = true;
				break;
			}
			p3++;
		}
		if (test == false) Matrica.push_back({*p1,decltype(*p3)()});
		p1++;
	}
	p3 = poc;
	while (p3 != p4) {
		test = false;
		p1 = poc2;
		while (p1 != p2) {
			if ((*p3) == (*p1)) {
				test = true;
				break;
			}
			p1++;
		}
		if (test == false) Matrica.push_back({*p3,decltype(*p3)()});
		p3++;
	}
	
	std::sort(Matrica.begin(),Matrica.end(),[](std::vector<decltype(*p1+*p1)> v1,std::vector<decltype(*p1+*p1)> v2) {
		if (v1[0] > v2[0]) return true;
		if(v1[0] == v2[0]) {
			if(v1[1] < v2[1]) return true;
			return false;
		}
		return false;
	});
	
	return Matrica;
}

int main ()
{
	

	
	

	
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n(0);
	std::cin >> n;
	std::deque<int> v1(0);
	std::cout << "Unesite elemente prvog kontejnera: ";
	int n2(0);
	for (int i = 0; i < n; i++) {
		do {
			std::cin >> n2;
			if (std::find(v1.begin(),v1.end(),n2) == v1.end()) break;
		}while(1);
		v1.push_back(n2);
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n;
	std::deque<int> v2(0);
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i = 0; i < n; i++) {
		do {
			std::cin >> n2;
			if (std::find(v2.begin(),v2.end(),n2) == v2.end()) break;
		}while(1);
		v2.push_back(n2);
	}
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	
	auto Matrica = UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),SumaCifara);
	
	for (auto i : Matrica) {
		for (auto i2 : i) {
			std::cout <<std::setw(6)<< i2 << " ";
		}
		std::cout  << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	Matrica = UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora);
	
	for (auto i : Matrica) {
		for (auto i2 : i) {
			std::cout <<std::setw(6)<< i2 << " ";
		}
		std::cout  << std::endl;
	}
	std::cout << "Dovidjenja!" << std::endl;
	return 0;
}

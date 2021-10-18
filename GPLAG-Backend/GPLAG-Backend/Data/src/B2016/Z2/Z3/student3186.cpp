//B 16/17, Zadaća 2, Zadatak 3
#include <type_traits>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <cmath>

int SumaCifri (long long int n) {
	int suma(0);  n = std::fabs(n);
	while (n != 0) {
		suma += n%10;	n/=10;
	}	return suma;
}

int SumaDjelilaca (long long int n) {
	int suma(0);  n = std::fabs(n);
	for (int i=1; i<=n; ++i)
		if (n%i == 0) suma += i;
	return suma;
}

int BrojProstihFaktora (long long int n) {
	int brojac(0);  n = std::fabs(n);
	for (int i=2; i<=n; ++i)
		while (n % i == 0) {
			n/=i;  brojac++;
		}	return brojac;
}

int BrojSavrsenihDjelilaca (long long int n) {
	int brojac(0), suma(0);  n = std::fabs(n);
	for (int i=1; i<=n; ++i) {
		suma = 0;
		if (n%i == 0) {
			for (int j=1; j<i; ++j)
				if (i%j == 0)	suma += j;
			if (suma == i)	brojac++;
		}
	}	return brojac;
}

// Varijanta I..
template <typename IPtip1, typename IPtip2>
	auto UvrnutiPresjek (IPtip1 pocI, IPtip1 krajI, IPtip2 pocII, IPtip2 krajII) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocI)>::type>>
	{
		int vel(0);
		IPtip2 reset (pocII);
		std::vector<std::vector<typename std::remove_reference<decltype(*pocI)>::type>> Mat;
		while (pocI != krajI) {
			pocII = reset;
			while (pocII != krajII) {
				if (*pocI == *pocII) {
					Mat.resize(++vel);
					Mat[vel-1].resize(3, 0);
					Mat[vel-1][0] = (*pocI);
				}	pocII++;
			}	pocI++;
			std::sort (Mat.begin(), Mat.end(), [] (const std::vector<typename std::remove_reference<decltype(*pocI)>::type> &x,
			const std::vector<typename std::remove_reference<decltype(*pocI)>::type> &y) {	return x[0] < y[0];	});
		}	return Mat;
	}
	
// Varijanta II..
template <typename IPtip1, typename IPtip2, typename funI, typename funII>
	auto UvrnutiPresjek (IPtip1 pocI, IPtip1 krajI, IPtip2 pocII, IPtip2 krajII, funI funkcija(funII)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocI)>::type>>
	{
		int vel(0);
		IPtip2 reset (pocII);
		std::vector<std::vector<typename std::remove_reference<decltype(*pocI)>::type>> Mat;
		while (pocI != krajI) {
			pocII = reset;
			while (pocII != krajII) {
				if (funkcija(*pocI) == funkcija(*pocII)) {
					Mat.resize(++vel);
					Mat[vel-1].resize(3);
					Mat[vel-1][0] = (*pocI);
					Mat[vel-1][1] = (*pocII);
					Mat[vel-1][2] = (funkcija(*pocI));
				}	pocII++;
			}	pocI++;
		}
		// Sort Mat po f(f), pa x, pa y..
		std::sort (Mat.begin(), Mat.end(), [] (const std::vector<typename std::remove_reference<decltype(*pocI)>::type> &x,
		const std::vector<typename std::remove_reference<decltype(*pocI)>::type> &y)
		{	if (x[2] == y[2] and x[0] == y[0]) return x[1] < y[1];
			else if (x[2] == y[2])	return x[0] < y[0];		else return x[2] < y[2];	});
		return Mat;
	}
	
// Varijanta I..
template <typename IPtip1, typename IPtip2>
	auto UvrnutaRazlika (IPtip1 pocI, IPtip1 krajI, IPtip2 pocII, IPtip2 krajII) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocI)>::type>>
	{
		int vel(0);	bool ne_sadrzi;
		IPtip1 resetI(pocI);	IPtip2 resetII(pocII);
		std::vector<std::vector<typename std::remove_reference<decltype(*pocI)>::type>> Mat;
		
		while (pocI != krajI) {
			pocII = resetII;
			ne_sadrzi = true;
			while (pocII != krajII) {
				if (*pocI == *pocII) {
					ne_sadrzi = false;	break;
				}	pocII++;
			}
			if (ne_sadrzi) {
				Mat.resize(++vel);
				Mat[vel-1].resize(2,0);
				Mat[vel-1][0] = (*pocI);
			}	pocI++;
		}
		
		pocII = resetII;
		while (pocII != krajII) {
			pocI = resetI;
			ne_sadrzi = true;
			while (pocI != krajI) {
				if (*pocII == *pocI) {
					ne_sadrzi = false;	break;
				}	pocI++;
			}
			if (ne_sadrzi) {
				Mat.resize(++vel);
				Mat[vel-1].resize(2,0);
				Mat[vel-1][0] = (*pocII);
			}	pocII++;
		}
		// Sort mat po x..
		std::sort (Mat.begin(), Mat.end(), [] (const std::vector<typename std::remove_reference<decltype(*pocI)>::type> &x,
		const std::vector<typename std::remove_reference<decltype(*pocI)>::type> &y) {	return x[0] > y[0];	});
		return Mat;
	}
	
// Varijanta II..
template <typename IPtip1, typename IPtip2, typename funI, typename funII>
	auto UvrnutaRazlika (IPtip1 pocI, IPtip1 krajI, IPtip2 pocII, IPtip2 krajII, funI funkcija(funII)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocI)>::type>>
	{
		int vel(0);	bool ne_sadrzi;
		IPtip1 resetI (pocI);	IPtip2 resetII (pocII);
		std::vector<std::vector<typename std::remove_reference<decltype(*pocI)>::type>> Mat;
		
		while (pocI != krajI) { 
			pocII = resetII;
			ne_sadrzi = true;
			while (pocII != krajII) {
				if (funkcija(*pocI) == funkcija(*pocII)) {
					ne_sadrzi = false;	break;
				}	pocII++;
			}
			if (ne_sadrzi) {
				Mat.resize(++vel);
				Mat[vel-1].resize(2);
				Mat[vel-1][0] = (*pocI);
				Mat[vel-1][1] = (funkcija(*pocI));
			}	pocI++;
		}
		
		pocII = resetII;
		while (pocII != krajII) {
			pocI = resetI;
			ne_sadrzi = true;
			while (pocI != krajI) {
				if (funkcija(*pocII) == funkcija(*pocI)) {
					ne_sadrzi = false;	break;
				}	pocI++;
			}
			if (ne_sadrzi) {
				Mat.resize(++vel);
				Mat[vel-1].resize(2);
				Mat[vel-1][0] = (*pocII);
				Mat[vel-1][1] = (funkcija(*pocII));
			}	pocII++;
		}
		// Sort Mat po x, pa f(f)..
		std::sort (Mat.begin(), Mat.end(), [] (const std::vector<typename std::remove_reference<decltype(*pocI)>::type> &x,
		const std::vector<typename std::remove_reference<decltype(*pocI)>::type> &y)
		{ 	if (x[0] == y[0]) return x[1] > y[1]; 	else return x[0] > y[0];	});
		return Mat;
	}

void Unos_deka (std::deque<int> &dek, const int &vel) {
	for (int i=0; i<vel; ++i) {
		int broj;
		std::cin >> broj;
		bool ne_sadrzi(true);
		for (int j=0; j<i; ++j)
			if (broj == dek[j]) 
			{	ne_sadrzi = false;	break;	}
		if (ne_sadrzi)	dek.push_back(broj);
		else	i--;
	}
}

int main ()
{
	int br_elemenata1;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> br_elemenata1;
	
	std::cout << "Unesite elemente prvog kontejnera: ";
	std::deque<int> prvi_dek;
	Unos_deka(prvi_dek, br_elemenata1);
	
	int br_elemenata2;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> br_elemenata2;
	
	std::cout << "Unesite elemente drugog kontejnera: ";
	std::deque<int> drugi_dek;
	Unos_deka(drugi_dek, br_elemenata2);
	
	std::vector<std::vector<int>> Mat = UvrnutiPresjek(prvi_dek.begin(), prvi_dek.end(), drugi_dek.begin(), drugi_dek.end(), SumaCifri);
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	for (int i=0; i<Mat.size(); ++i ) {
		for (int j=0; j<Mat[i].size(); ++j)
			std::cout << std::setw(6) << Mat[i][j] << " ";	std::cout << std::endl;
	}	std::vector<std::vector<int>> Mat_ = UvrnutaRazlika(prvi_dek.begin(), prvi_dek.end(), drugi_dek.begin(), drugi_dek.end(), BrojProstihFaktora);
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	for (int i=0; i<Mat_.size(); ++i ) {
		for (int j=0; j<Mat_[i].size(); ++j)
			std::cout << std::setw(6) << Mat_[i][j] << " ";	std::cout << std::endl;
	}	std::cout << "Dovidjenja!" << std::endl;	return 0;
}
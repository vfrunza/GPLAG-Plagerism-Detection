#include <iostream>
#include <deque> 
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <type_traits>
#include <cmath>
#include <vector>

bool DaLiJeSavrsen (long long int n) {
	int suma (0);
	for (int i=1; i<n; i++) {
		if (n % i == 0)
			suma += i;
	}
	if (suma == n)
		return true;
	return false;
}
int SumaDjelilaca (long long int n) {
	int suma (0);
	for (int i=1; i<=std::abs(n); i++) {
		if (n % i == 0)
			suma += i;
	}
	return suma;
}
int BrojProstihFaktora (long long int n) {
	int brojac (0);
	for (int i=2; i<=n; i++) {
		while (n % i == 0) {
			n /= i;
			brojac++;
		}
	}
	return brojac;
} 
int BrojSavrsenihDjelilaca (long long int n) {
	int brojac (0);
	
	for (int i=1; i<=n; i++) {
		if (n % i == 0) {
			if (DaLiJeSavrsen(i))
				brojac++;
		}
	}
	return brojac;
}
int SumaCifara (long long int n) {
	int suma (0);
	do {
		suma += n % 10;
		n /= 10;
	} while (n != 0);
	return suma;
}
template <typename Tip1, typename Tip2, typename TipFunkcije, typename Povratna>
auto UvrnutiPresjek (Tip1 pocetak, Tip1 iza_kraja, Tip2 pocetak1, Tip2 iza_kraja1, Povratna f (TipFunkcije)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>>{
	std::vector<std::vector<typename std::remove_reference <decltype(*pocetak)>::type>> mat;
	if (iza_kraja - pocetak == 0)
		return mat;
	std::vector<typename std::remove_reference <decltype(*pocetak)>::type> pomocni;

	for (auto it = pocetak; it!=iza_kraja; it++) {
		for (auto it1 = pocetak1; it1!=iza_kraja1; it1++) {
			if (f(*it) == f(*it1)) {
				pomocni.push_back(*it), pomocni.push_back(*it1), pomocni.push_back(f(*it1));
			}
			if (pomocni.size() != 0)
				mat.push_back(pomocni);
			pomocni.resize(0);
		}
	}
	for (int i=0; i<mat.size()-1; i++) {
		for (int j=i+1; j<mat.size(); j++) {
			if (mat[i] == mat[j])
			mat.erase (mat.begin() + j);
		}
	}
	std::sort (mat.begin(), mat.end(), [](const std::vector<typename std::remove_reference<decltype(*pocetak)>::type> &v1, const std::vector<typename std::remove_reference<decltype(*pocetak)>::type>&v2)
	{
		if ((v1[2] == v2[2]) && (v1[0] == v2[0]))
			return v1[1] < v2[1];
		else if (v1[2] == v2[2])
			return v1[0] < v2[0];
		return v1[2] < v2[2];
	});
	return mat;
}
template <typename Tip1, typename Tip2>
auto UvrnutiPresjek (Tip1 pocetak, Tip1 iza_kraja, Tip2 pocetak1, Tip2 iza_kraja1) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {
	std::vector<typename std::remove_reference <decltype(*pocetak)>::type> pomocni;
	std::vector<std::vector<typename std::remove_reference <decltype(*pocetak)>::type>> prazna_mat;
	if (iza_kraja - pocetak == 0)
		return prazna_mat;

	int brojac (0);
	for (auto it = pocetak; it!=iza_kraja; it++) {
		for (auto it1 = pocetak1; it1!=iza_kraja1; it1++) {
			if (*it == *it1) {
				brojac++;
				pomocni.push_back(*it);
			}
		}
	}
	std::vector<std::vector<typename std::remove_reference <decltype(*pocetak)>::type>>mat (brojac, std::vector<typename std::remove_reference <decltype(*pocetak)>::type> (3,0));
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat[i].size(); j++) {
			mat[i][0] = pomocni[i];
		}
	}
	return mat;
}
template <typename Tip1, typename Tip2>
auto UvrnutaRazlika (Tip1 pocetak, Tip1 iza_kraja, Tip2 pocetak1, Tip2 iza_kraja1) -> std::vector<std::vector<typename std::remove_reference <decltype(*pocetak)>::type>> {
	std::vector<std::vector<typename std::remove_reference <decltype(*pocetak)>::type>>prazna_mat;
	if (iza_kraja - pocetak == 0)
		return prazna_mat;
		
	std::vector<typename std::remove_reference <decltype(*pocetak)>::type> pomocni;
	int brojac (0);
	for (auto it=pocetak1; it!=iza_kraja1; it++) {
		bool ne_sadrzi (true);
		for (auto it1=pocetak; it1!=iza_kraja; it1++) {
			if (*it == *it1) {
				ne_sadrzi = false;
				break;
			}
		}
		if (ne_sadrzi) {
			brojac++;
			pomocni.push_back(*it);
		}
	}
	for (auto it=pocetak; it!=iza_kraja; it++) {
		bool ne_sadrzi (true);
		for (auto it1=pocetak1; it1!=iza_kraja1; it1++) {
			if (*it == *it1) {
				ne_sadrzi = false;
				break;
			}
		}
		if (ne_sadrzi) {
			brojac++;
			pomocni.push_back(*it);
		}
	}
	std::vector<std::vector<typename std::remove_reference <decltype(*pocetak)>::type>>mat (brojac, std::vector<typename std::remove_reference <decltype(*pocetak)>::type> (2,0));
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat[i].size(); j++) {
			mat[i][0] = pomocni[i];
		}
	}
	std::sort (mat.begin(), mat.end(), [] (const std::vector<typename std::remove_reference<decltype(*pocetak)>::type>&v1, const std::vector<typename std::remove_reference<decltype(*pocetak)>::type>&v2)
	{
		return v1[0] > v2[0];
	});
	return mat;
}
template <typename Tip1, typename Tip2, typename TipFunkcije, typename Povratna>
auto UvrnutaRazlika (Tip1 pocetak, Tip1 iza_kraja, Tip2 pocetak1, Tip2 iza_kraja1, Povratna fun (TipFunkcije)) -> std::vector<std::vector<typename std::remove_reference <decltype(*pocetak)>::type>> {
	std::vector<std::vector<typename std::remove_reference <decltype(*pocetak)>::type>> mat;
	if (iza_kraja - pocetak == 0)
		return mat;
	std::vector<typename std::remove_reference <decltype(*pocetak)>::type> pomocni;

	for (auto it = pocetak; it!=iza_kraja; it++) {
		bool ne_sadrzi (true);
		for (auto it1 = pocetak1; it1!=iza_kraja1; it1++) {
			if (fun (*it) == fun (*it1)) {
				ne_sadrzi = false;
				break;
			}
		}
		if (ne_sadrzi) {
			pomocni.push_back (*it);
			pomocni.push_back (fun(*it));
		}
		if (pomocni.size() != 0) 
			mat.push_back(pomocni);
		pomocni.resize(0);
	}
	for (auto it=pocetak1; it!=iza_kraja1; it++) {
		bool ne_sadrzi (true);
		for (auto it1=pocetak; it1!=iza_kraja; it1++) {
			if (fun (*it) == fun (*it1)) {
				ne_sadrzi = false;
				break;
			}
		}
		if (ne_sadrzi) {
			pomocni.push_back (*it);
			pomocni.push_back (fun (*it));
		}
		if (pomocni.size() != 0)
			mat.push_back (pomocni);
		pomocni.resize(0);
	}
	std::sort (mat.begin(), mat.end(), [] (const std::vector<typename std::remove_reference <decltype(*pocetak)>::type>&v1, const std::vector<typename std::remove_reference <decltype(*pocetak)>::type> &v2)
	{
		if (v1[0] == v2[0])
			return v1[1] > v2[1];
		return v1[0] > v2[0];
	});
	return  mat;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n;
	std::deque<int> dek1; 
	std::cout << "Unesite elemente prvog kontejnera: ";
	for (int i=0; i<n; i++) {
		int a;
		std::cin >> a;
	auto p = std::find (dek1.begin(), dek1.end(), a);
	if (p == dek1.end())
		dek1.push_back(a);
	else
		i--;
	}
	int m;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> m;
	std::deque<int> dek2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i=0; i<m; i++) { 
		int a;
		std::cin >> a;
	auto p = std::find (dek2.begin(), dek2.end(), a);
	if (p == dek2.end())
		dek2.push_back(a);
	else
		i--;
	}
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	auto mat = UvrnutiPresjek (dek1.begin(),dek1.end(),dek2.begin(),dek2.end(), SumaCifara);
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat[i].size(); j++)
			std::cout << std::setw(6) << mat[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	auto mat1 = UvrnutaRazlika (dek1.begin(), dek1.end(), dek2.begin(), dek2.end(),BrojProstihFaktora);
	for (int i=0; i<mat1.size(); i++) {
		for (int j=0; j<mat1[i].size(); j++)
			std::cout << std::setw(6) << mat1[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}
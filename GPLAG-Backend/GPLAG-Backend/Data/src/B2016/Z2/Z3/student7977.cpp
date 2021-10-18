/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <algorithm>
#include <iomanip>
#include <cmath>

template< typename NekiTip >
NekiTip absulutno(NekiTip n){
	if(n<0){
		n *= (-1);
		return n;
	}
	return n;
}

int f(long long int n){
	if(n == 0) return 0;
	if(n < 1) return absulutno(int(n*10)) + f(n - int(n));
	return absulutno(n%10) + f(n/10);
}

int SumaDjelilaca(long long int n){
	n = absulutno(n);
	int suma_d(n);
	for(int i=1; i<=n/2; i++){
		if(n%i == 0){
			suma_d += i;
		}
	}
	return suma_d;
}

bool DaLiJeProst(int n){
	for(int i=2; i<=n/2; i++){
		if(n%i == 0){
			return false;
		}
	}
	if(n <= 1) return false;
	return true;
}

int BrojProstihFaktora(long long int n){
	int broj_pf(0);
	for(int i=2; i<=n/2; i++){
		if(n%i == 0 && DaLiJeProst(i)){
			broj_pf++;
			for(int j=2; 1; j++){
				if(n%int(pow(i , j)) == 0){
					broj_pf++;
					continue;
				}
				break;
			}
		}
	}
	if(DaLiJeProst(n)) broj_pf++;
	return broj_pf;
}

bool SavrsenBroj(int n){
	int suma_d(0);
	for(int i=1; i<n; i++){
		if(n%i == 0) suma_d += i;
	}
	if(n == suma_d) return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int n){
	int broj_sd(0);
	for(int i=1; i<=n; i++){
		if(n%i==0){
			if(SavrsenBroj(i)) broj_sd++;
		}
	}
	return broj_sd;
}

template <typename Kontejner1, typename Kontejner2, typename PovratniTip, typename PrimaciTip>
auto UvrnutiPresjek(Kontejner1 pocetak1, Kontejner1 iza_kraja1, Kontejner1 pocetak2, Kontejner2 iza_kraja2, PovratniTip funkcija(PrimaciTip)) -> std::vector<std::vector<typename std::remove_reference< decltype (*pocetak1 + *pocetak2)>::type>> {
	std::vector<std::vector<typename std::remove_reference< decltype (pocetak1[0] + pocetak2[0])>::type>> v;
	auto pom1(pocetak1);
	auto pom2(pocetak2);
	const double Epsilon(0.0000001);
	int br_redova(0);
	
	while(pom1 != iza_kraja1){
		pom2 = pocetak2;
		while(pom2 != iza_kraja2){
			if(absulutno(funkcija(*pom1) - funkcija(*pom2)) < Epsilon){
				br_redova++;
				v.resize(br_redova);
				v[br_redova-1].resize(3);
				v[br_redova-1][0] = *pom1;
				v[br_redova-1][1] = *pom2;
				v[br_redova-1][2] = funkcija(*pom1);
			}
			pom2++;
		}
		pom1++;
	}
	
	if(v.size() > 1){
		std::sort(std::begin(v), std::end(v), 
		[](std::vector<decltype(pocetak1[0]+pocetak2[0])> v, std::vector<decltype(pocetak1[0]+pocetak2[0])> v1){
				const double Epsilon(0.0000001);
				if(absulutno(v1[2] - v[2])<Epsilon){ 
					if(absulutno(v1[0] - v1[0]) < Epsilon){
						return v < v1;
					}
					return v < v1;
				}
				return v[2] < v1[2];
			} );
	}
	return v;
 }

template <typename Kontejner1, typename Kontejner2>
auto UvrnutiPresjek(Kontejner1 pocetak1, Kontejner1 iza_kraja1, Kontejner2 pocetak2, Kontejner2 iza_kraja2) -> std::vector<std::vector<typename std::remove_reference<decltype(pocetak1[0] + pocetak2[0])>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype (pocetak1[0] + pocetak2[0])>::type>> v;
	auto pom1(pocetak1);
	auto pom2(pocetak2);
	int br_redova(0);
	const double Epsilon(0.0000001);
	
	while(pom1 != iza_kraja1){
		pom2 = pocetak2;
		while(pom2 != iza_kraja2){
			if(absulutno(*pom1 - *pom2) < Epsilon){
				br_redova++;
				v.resize(br_redova);
				v[br_redova-1].resize(3);
				v[br_redova-1][0] = *pom1;
				v[br_redova-1][1] = 0;
				v[br_redova-1][2] = 0;
			}
			pom2++;
		}
		pom1++;
	}
	
	if(v.size() > 1){
		std::sort(std::begin(v), std::end(v));
	}
	return v;
}

template <typename Kontejner1, typename Kontejner2, typename PovratniTip, typename PrimaciTip>
auto UvrnutaRazlika(Kontejner1 pocetak1, Kontejner1 iza_kraja1, Kontejner1 pocetak2, Kontejner2 iza_kraja2, PovratniTip funkcija(PrimaciTip)) -> std::vector<std::vector<typename std::remove_reference< decltype (*pocetak1 + *pocetak2)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype (pocetak1[0] + pocetak2[0])>::type>> v;
	auto pom1(pocetak1);
	auto pom2(pocetak2);
	int br_redova(0);
	const double Epsilon(0.000000001);
	while(pom1 != iza_kraja1){
		pom2 = pocetak2;
		while(pom2 != iza_kraja2){
			if(absulutno(funkcija(*pom1) - funkcija(*pom2)) < Epsilon){
				break;
			}
			pom2++;
		}
		if(pom2 == iza_kraja2){
			br_redova++;
			v.resize(br_redova);
			v[br_redova-1].resize(2);
			v[br_redova-1][0] = *pom1;
			v[br_redova-1][1] = funkcija(*pom1);
		}
		pom1++;
	}
	pom1 = pocetak1;
	pom2 = pocetak2;
	
	while(pom2 != iza_kraja2){
		pom1 = pocetak1;
		while(pom1 != iza_kraja1){
			if(absulutno(funkcija(*pom1) - funkcija(*pom2)) < Epsilon){
				break;
			}
			pom1++;
		}
		if(pom1 == iza_kraja1){
			br_redova++;
			v.resize(br_redova);
			v[br_redova-1].resize(2);
			v[br_redova-1][0] = *pom2;
			v[br_redova-1][1] = funkcija(*pom2);
		}
		pom2++;
	}
	
	if(v.size() > 1){
		std::sort(std::begin(v), std::end(v), 
		[](std::vector<decltype(pocetak1[0]+pocetak2[0])> v, std::vector<decltype(pocetak1[0]+pocetak2[0])> v1){
			const double Epsilon(0.0000001);
			if(absulutno(v1[0] - v[0]) < Epsilon){
				return v1 < v;
			}
			return  v1[0] < v[0];
		});
	}
	return v;
}

template <typename Kontejner1, typename Kontejner2>
auto UvrnutaRazlika(Kontejner1 pocetak1, Kontejner1 iza_kraja1, Kontejner2 pocetak2, Kontejner2 iza_kraja2) -> std::vector<std::vector<typename std::remove_reference<decltype(pocetak1[0] + pocetak2[0])>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype (pocetak1[0] + pocetak2[0])>::type>> v;
	auto pom1(pocetak1);
	auto pom2(pocetak2);
	int br_redova(0);
	const double Epsilon(0.0000001);
	
	while(pom1 != iza_kraja1){
		pom2 = pocetak2;
		while(pom2 != iza_kraja2){
			if(absulutno(*pom1 - *pom2) < Epsilon) break;
			
			pom2++;
		}
		if(pom2 == iza_kraja2){
			br_redova++;
			v.resize(br_redova);
			v[br_redova-1].resize(2);
			v[br_redova-1][0] = *pom1;
			v[br_redova-1][1] = 0;
		}
		pom1++;
	}
	
	pom1 = pocetak1;
	pom2 = pocetak2;
	
	while(pom2 != iza_kraja2){
		pom1 = pocetak1;
		while(pom1 != iza_kraja1){
			if(absulutno(*pom1 - *pom2) < Epsilon){
				break;
			}
			pom1++;
		}
		if(pom1 == iza_kraja1){
			br_redova++;
			v.resize(br_redova);
			v[br_redova-1].resize(2);
			v[br_redova-1][0] = *pom2;
			v[br_redova-1][1] = 0;
		}
		pom2++;
	}
	
	if(v.size() > 1){
		std::sort(std::begin(v), std::end(v),
		[](std::vector<decltype(pocetak1[0]+pocetak2[0])> v, std::vector<decltype(pocetak1[0]+pocetak2[0])> v1){ return v1 < v; });
	}
	return v;
}

int main ()
{
	std::deque<int> d, d1;
	int duzina, duzina1, broj;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> duzina;
	d.resize(duzina);
	std::cout << "Unesite elemente prvog kontejnera: ";
	
	for(int i=0; i<duzina; i++){
		std::cin >> broj;
		int j;
		for(j=0; j<i; j++){
			if(broj == d[j]) break;
		}
		if(i == j){
			d[i] = broj;
		}else{
			i--;
		}
	}

	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> duzina1;
	d1.resize(duzina1);
	std::cout << "Unesite elemente drugog kontejnera: ";
	
	for(int i=0; i<duzina1; i++){
		std::cin >> broj;
		int j;
		for(j=0; j<i; j++){
			if(broj == d1[j]) break;
		}
		if(i == j){ 
			d1[i] = broj;
		}else{
			i--;
		}
	}
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	std::vector<std::vector<int>> v{ UvrnutiPresjek(d.begin(), d.end(), d1.begin(), d1.end(), f) };
	
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			std::cout << std::setw(6) << v[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	std::vector<std::vector<int>> v1{ UvrnutaRazlika(d.begin(), d.end(), d1.begin(), d1.end(), BrojProstihFaktora) };
	for(int i=0; i<v1.size(); i++){
		for(int j=0; j<v1[i].size(); j++){
			std::cout << std::setw(6) << v1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";

	return 0;
}
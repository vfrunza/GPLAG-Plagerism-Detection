#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

int SumaDjelilaca(long long int n){
	int suma(0);
	if (n <0) n = n * -1;
	
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			suma += i; 
		}
		
	}
	return suma;
}

int SumaDjelilacaN(long long int n){
	int suma(0);
	for (int i = 1; i < n; i++) {
		if (n%i == 0) {
			suma += i; 
		}
		
	}
	return suma;
}

int SumaCifara(int n){
	int suma(0);
	
	if (n <0) n = n * -1;
	
	while (n != 0) {
		suma += n %10;
		n= n /10;
	}
	return suma;
}

bool DaLiJeProst(int n){
		
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int BrojProstihFaktora(long long int n){
	int brojac{0}, i{2};
	
	while (n != 1){
		if (DaLiJeProst(i) && n % i == 0) {
			brojac++;
			n = n / i;
			i=2;
			continue;
		}
		i++;
	}
	return brojac;
}

int BrojSavrsenihDjelilaca (long long int n){
	int brojac(0);
	
	for (int i = 6; i < n; i++) {
		if (SumaDjelilacaN(i)==i) {
			brojac++;
		}
		
	}
	return brojac;
}


template <typename IterTip1, typename IterTip2, typename TipFje, typename TipParametra>
std::vector<std::vector<TipFje>> UvrnutiPresjek(IterTip1 it1, IterTip1 it2, IterTip2 it3, IterTip2 it4, TipFje F(TipParametra)){
	std::vector<std::vector<TipFje>> RezultatPresjeka;
	IterTip2 Kopija(it3);
	int i(0);
	while (it1 != it2) {
		it3 = Kopija;
		while (it3 != it4) {
			if (F(*it1) == F(*it3)) {
				RezultatPresjeka.resize(i+1);
				RezultatPresjeka[i].push_back(*it1);
				RezultatPresjeka[i].push_back(*it3);
				RezultatPresjeka[i].push_back(F(*it1));
				i++;
			}
			it3++;
		}
		it1++;
	} //Alg za testiranje i upisivanje podataka
	
	//Sortiranje, prevesti ovo u template jezik, posebni slucaj kad nije fja poslana
	std::sort(std::begin(RezultatPresjeka), std::end(RezultatPresjeka), [] (std::vector<int>x, std::vector<int> y){
	if (x[2] < y[2]) return true;
	
	else if (x[2] == y[2]){
		if(x[0] < y[0]) return true; 
		else if (x[0] > y[0]) return false; 
		else if (x[0] == y[0]){ 
			if(x[1] < y[1]) return true; 
			else if (x[1] > y[1]) return false; 
		}
	} 
	return false;
});
	
	return RezultatPresjeka;
}



template <typename IterTip1, typename IterTip2, typename TipFje, typename TipParametra>
std::vector<std::vector<TipFje>> UvrnutaRazlika(IterTip1 it1, IterTip1 it2, IterTip2 it3, IterTip2 it4, TipFje F(TipParametra)){
	std::vector<std::vector<TipFje>> RezultatRazlike;
	
	{
	IterTip2 Kopija(it3); IterTip1 KopijaI(it1);
	int i(0);
	while (it1 != it2) {
		it3 = Kopija;

		while (it3 != it4) {
			if (F(*it1) == F(*it3)) {
				break;
			}
			it3++;
		}
		if (it3 == it4) {
			
			RezultatRazlike.resize(i+1);
			RezultatRazlike[i].push_back(*it1);
			
			RezultatRazlike[i].push_back(F(*it1));
			i++;
		}
		
		
		
		it1++;
	}
	it3 = Kopija;
	while (it3 != it4) {
		it1 = KopijaI;

		while (it1 != it2) {
			if (F(*it3) == F(*it1)) {
				break;
			}
			it1++;
		}
		if (it1 == it2) {
			
			RezultatRazlike.resize(i+1);
			RezultatRazlike[i].push_back(*it3);
			
			RezultatRazlike[i].push_back(F(*it3));
			i++;
		}
		
		
		
		it3++;
	}
	}//Alg za testiranje i upisivanje podataka
	//Sortirati u opadajuci poredak, prevesti u temp
	
	std::sort(std::begin(RezultatRazlike), std::end(RezultatRazlike), [] (std::vector<int>x, std::vector<int> y){
	if (x[0] > y[0]) return true;
	
	else if (x[0] == y[0]){
		if(x[1] > y[1]) return true; 
		else if (x[1] < y[1]) return false; 
		
	} 
	return false;
}); 

	return RezultatRazlike;
}

int main (){
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n; 	std::cin >> n; std::deque<int> d1;
	
	std::cout << "Unesite elemente prvog kontejnera: ";
	for (int i = 0; i < n; i++) {
		int broj; std::cin >> broj; bool jedinstven(true);
		for (auto j : d1) {
			if (j == broj) {
				jedinstven=false; break;
			}
		}
		if (jedinstven) d1.push_back(broj);
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n; 	std::deque<int> d2;
	
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i = 0; i < n; i++) {
		int broj; std::cin >> broj; bool jedinstven(true);
		for (auto j : d2) {
			if (j == broj) {
				jedinstven=false; break;
			}
		}
		if (jedinstven) d2.push_back(broj);
	}
	
	std::vector<std::vector<int>> a = UvrnutiPresjek(std::begin(d1), std::end(d1), std::begin(d2), std::end(d2), SumaCifara);
	std::vector<std::vector<int>> b = UvrnutaRazlika(std::begin(d1), std::end(d1), std::begin(d2), std::end(d2), BrojProstihFaktora);
	
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	for (int i = 0; i < a.size(); i++) {
		for (auto j : a[i]) {
			std::cout << std::setw(6) << j << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	for (int i = 0; i < b.size(); i++) {
		for (auto j : b[i]) {
			std::cout << std::setw(6) << j << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!" << std::endl;



	return 0;
}
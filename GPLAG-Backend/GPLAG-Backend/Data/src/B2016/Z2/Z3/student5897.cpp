#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <math.h>

int SumaDjelilaca(long long int broj) {
	if(broj==0) return 0;
	int suma=abs(broj);
	for(int i=2; i<abs(broj)/2+1; i++) {
		if(broj%i==0) suma=suma+i;
	}
	if(suma!=1) suma++;
	return suma;
}

bool DaLiJeProst (int n) {
	bool jeliprost(true);
	int suma(0);
	for(int i=1; i<sqrt(abs(n)); i++) {
		if(n%i==0) suma++;
		if(suma>1) { jeliprost = false; break; }
	}
	return jeliprost;
}

int BrojProstihFaktora(long long int n) {
	int broj_prostih(0);
	int t=n;
	
	for(int i=2; i<=abs(n)/2; i++) {
		if(t%i==0 && DaLiJeProst(i)) { 
			broj_prostih++; 
			//std::cout << "t " << t;
			t=t/i;
			i--;
		}
	}
	
	//je li n prost:
	if(DaLiJeProst(n)) broj_prostih++;
	
	return broj_prostih;
}

int BrojSavrsenihDjelilaca(long long int n) {
	
	int broj(0);
	
	for(int i=1; i<abs(n)/2+1; i++) {
		if(n%i==0) {
			
			//provjera je li i savrsen br.
			int suma_djelilaca(0);
			
			for(int j=1; j<i/2+1; j++) {
				if(i%j==0) suma_djelilaca+=j;
			}
			
			if(suma_djelilaca==i) broj++;
			
		}
	}
	
	{
	//je li n savrsen broj:
		int suma(0);
		for(int i=1; i<abs(n)/2+1; i++) if(n%i==0) suma+=i;
		if(suma==n) broj++;
	}
	
	return broj;
}

int fp(long long int n) {
	int suma(0);
	while(n) {
		suma+=abs(n)%10;
		n/=10;
	}
	return suma;
}

template <typename T1, typename T2,typename T3, typename T4>
auto UvrnutiPresjek(T1 pocetak, T1 iza_kraja, T2 pocetak_2, T2 iza_kraja_2, T3 f(T4) ) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {

	T2 cuvaj_poc2 = pocetak_2;
	int n=0;
    std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> matrica(n);
	
	while(pocetak!=iza_kraja) {

		while(pocetak_2!=iza_kraja_2) {
			
	    	if(f(*pocetak)==f(*pocetak_2)) {
	    		if(*pocetak==0 || f(*pocetak)!=0)  { 
	    			matrica.resize(matrica.size()+1);
	    			matrica[n].push_back(*pocetak);
	    			matrica[n].push_back(*pocetak_2);
	    			matrica[n].push_back(f(*pocetak));
	    			n++;
	    		}
			}
	    	pocetak_2++; 
		}
		
		pocetak_2=cuvaj_poc2;
		pocetak++;
	}
	
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<T3> x, std::vector<T3> y) { if(x[2]==y[2] && x[0]==y[0]) return x[1]<y[1];
																							else if(x[2]==y[2]) return x[0]<y[0]; 
																							else return x[2]<y[2];	} );
	
	return matrica;
}

template <typename T1, typename T2>
auto UvrnutiPresjek(T1 pocetak, T1 iza_kraja, T2 pocetak_2, T2 iza_kraja_2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {
	
	int n(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> matrica(n);
	
	for(;pocetak!=iza_kraja; pocetak++) {
		for(T2 poc=pocetak_2; poc!=iza_kraja_2; poc++) {
			if(*pocetak==*poc) {
				matrica.resize(matrica.size()+1);
				matrica[n].push_back(*pocetak);
				matrica[n].push_back(0);
				matrica[n].push_back(0);
				n++;
			}
		}
	}
	
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*pocetak)>::type> x, std::vector<typename std::remove_reference<decltype(*pocetak)>::type> y) { return x[2]<y[2]; } );
	
	return matrica;
}

template<typename T1, typename T2, typename T3, typename T4>
auto UvrnutaRazlika(T1 pocetak, T1 iza_kraja, T2 pocetak_2, T2 iza_kraja_2, T3 f(T4) ) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {
	T1 cuvaj_poc1 = pocetak;
	T2 cuvaj_poc2 = pocetak_2;
	int n=0; 
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> matrica(n);
	
	for(;pocetak!=iza_kraja; pocetak++) {
		int brojac(0);
		
		for(;pocetak_2!=iza_kraja_2; pocetak_2++) {
			if(f(*pocetak)==f(*pocetak_2)) brojac++;
		}
		
		if(brojac==0) {
			matrica.resize(matrica.size()+1);
			matrica[n].push_back(*pocetak);
			matrica[n].push_back(f(*pocetak));
			n++;
		}
		pocetak_2=cuvaj_poc2;
	}
	
	pocetak_2=cuvaj_poc2;
	pocetak=cuvaj_poc1;
	
	for(;pocetak_2!=iza_kraja_2; pocetak_2++) {
		int brojac(0);
		
		for(;pocetak!=iza_kraja; pocetak++) {
			if(f(*pocetak_2)==f(*pocetak)) brojac++;
		}
		
		if(brojac==0) {
			matrica.resize(matrica.size()+1);
			matrica[n].push_back(*pocetak_2);
			matrica[n].push_back(f(*pocetak_2));
			n++;
		}
		pocetak=cuvaj_poc1;
	}
	
	//sortiranje:
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<T3> x, std::vector<T3> y) { if(x[0]==y[0]) return x[1]>y[1]; else return x[0]>y[0]; });
	
	return matrica;
}

template<typename T1, typename T2>
auto UvrnutaRazlika(T1 pocetak, T1 kraj, T2 pocetak_2, T2 kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {
	
	int n(0);
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> matrica(n);
	
		for(T1 poc=pocetak; poc!=kraj; poc++) {
			bool razlika(true);
			for(T2 poc2=pocetak_2; poc2!=kraj2; poc2++) {
				if(*poc==*poc2) { razlika=false; break; }
			}
			if(razlika==true) { 
				matrica.resize(matrica.size()+1);
				matrica[n].push_back(*poc); matrica[n].push_back(0); n++;
			}
		}
		
	for(T2 poc2=pocetak_2; poc2!=kraj2; poc2++) {
		bool razlika(true);
		for(T1 poc=pocetak; poc!=kraj; poc++) {
			if(*poc==*poc2) { razlika=false; break; }
		}
		if(razlika==true) {
			matrica.resize(matrica.size()+1);
			matrica[n].push_back(*poc2); matrica[n].push_back(0); n++;
		}
	}
	
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<typename std::remove_reference<decltype(*pocetak)>::type> x, std::vector<typename std::remove_reference<decltype(*pocetak)>::type> y) { return x[0]>y[0]; });

	return matrica;
}

int main ()
{


    std::deque<int> kontejner, kontejner_2;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int broj_prvog_kontejnera;
	std::cin >> broj_prvog_kontejnera;
	
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i=0; i<broj_prvog_kontejnera; i++) {
		int unos;
		std::cin >> unos;
		kontejner.push_back(unos);
		for(int j=0; j<kontejner.size()-1; j++) {
			if(kontejner[j]==unos) { kontejner.resize(kontejner.size()-1); i--; }
		}
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int broj_drugog_kontejnera;
	std::cin >> broj_drugog_kontejnera;
	
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0; i<broj_drugog_kontejnera; i++) {
		int unos;
		std::cin >> unos;
		kontejner_2.push_back(unos);
		for(int j=0; j<kontejner_2.size()-1; j++) {
			if(kontejner_2[j]==unos) { kontejner_2.resize(kontejner_2.size()-1); i--; }
		}
	}
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	auto matrica(UvrnutiPresjek(kontejner.begin(), kontejner.end(), kontejner_2.begin(), kontejner_2.end(), fp));
	
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[i].size(); j++) {
			std::cout << std::setw(6) << matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	auto razlika(UvrnutaRazlika(kontejner.begin(), kontejner.end(), kontejner_2.begin(), kontejner_2.end(), BrojProstihFaktora));
	
	for(int i=0; i<razlika.size(); i++) {
		for(int j=0; j<razlika[i].size(); j++) {
			std::cout << std::setw(6) << razlika[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	
	
	std::cout << "Dovidjenja!";
	
	return 0;
}
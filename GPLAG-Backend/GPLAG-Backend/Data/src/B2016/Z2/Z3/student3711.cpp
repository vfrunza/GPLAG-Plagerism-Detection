/*B 16/17, Zadaća 2, Zadatak 3
	NAPOMENA: i javni ATo-vi su dio postavke
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <deque>

typedef std::vector<std::vector<int>> MATRICA;
typedef std::vector<int> VEKTOR;

/* ------------------------------------------------ */

// POMOCNE fcije
std::deque<int> UnosDeka (int broj_elemenata){
	std::deque<int> kontejner;
	for(int i=0; i<broj_elemenata; i++){
		int tmp;
		bool unesi = true;
		std::cin >> tmp;
		if(i == 0){
			kontejner.push_back(tmp);
		} else {
			for(int j=0; j<kontejner.size(); j++){
				if(tmp == kontejner[j]){
					unesi = false;
					break;
				}
			}
			if(unesi == true){
				kontejner.push_back(tmp);
			}
		}
	}
	return kontejner;
}
void IspisDeka(std::deque<int> dek){
	for(int i=0; i<dek.size(); i++){
		std::cout << dek[i] << " ";
	}
}
void IspisMatrice(MATRICA matrica){
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++){
			std::cout << matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/* ------------------------------------------------ */

// Fcije iz USLOVA zadatka
int SumaCifara(long long int broj){
	int suma_cifara = 0;
	while(broj != 0){
		int cifra;
		cifra = broj % 10;
		suma_cifara = suma_cifara + cifra;
		broj = broj / 10;
	}
	return suma_cifara;
}
int SumaDjelilaca (long long int broj){
	int suma_djelilaca = 0;
	for(int i=1; i<=broj; i++){
		if(broj%i == 0){
			suma_djelilaca = suma_djelilaca + i;
		}
	}
	return suma_djelilaca;
}
int BrojProstihFaktora (long long int broj){
	int brojac = 0;
	for (int i=2; i<broj; ++i){
		if(broj%i == 0){
			brojac++;
		}
		
	}
	return brojac;
}

/* ------------------------------------------------ */

// uvrnuti_PRESJEK i uvrnuta_RAZLIKA
template <typename art1, typename art2, typename parametar, typename funkcija>
MATRICA UvrnutiPresjek (art1 kontenjer1_pocetak, art1 kontenjer1_kraj, art2 kontenjer2_pocetak, art2 kontenjer2_kraj, funkcija fcija(parametar)){
	MATRICA matrix;
	while(kontenjer1_pocetak != kontenjer1_kraj){
		art2 temporary = kontenjer2_pocetak;
		while(temporary != kontenjer2_kraj){
			if(fcija(*kontenjer1_pocetak) == fcija(*temporary)){
				VEKTOR za_unos(0);
				za_unos.push_back(*kontenjer1_pocetak);
				za_unos.push_back(*temporary);
				za_unos.push_back(fcija(*kontenjer1_pocetak));
				matrix.push_back(za_unos);
			}
			temporary++;
		}
		kontenjer1_pocetak++;
	}
	sort(matrix.begin(), matrix.end(), [] (const VEKTOR v1, const VEKTOR v2) -> bool{
											if (v1[2]!=v2[2]) return v1[2]<v2[2];
											else if (v1[2]==v2[2]) return v1[0]<v2[0];
											else if (v1[2]==v2[2] && v1[0]==v2[0]) return v1[1]<v2[1]; 
										}
	);
	
	return matrix;
	
}

template <typename art1, typename art2, typename parametar, typename funkcija>
MATRICA UvrnutaRazlika (art1 kontenjer1_pocetak, art1 kontenjer1_kraj, art2 kontenjer2_pocetak, art2 kontenjer2_kraj, funkcija fcija(parametar)){
	bool ponavlja_se = false;
	MATRICA matrix;
	
	while(kontenjer1_pocetak != kontenjer1_kraj){
		art2 temporary = kontenjer2_pocetak;
		while(temporary != kontenjer2_kraj){
			if(fcija(*kontenjer1_pocetak) != fcija(*temporary)){
				ponavlja_se = false;
			} else {
				ponavlja_se = true;
				break;
			}
			temporary++;
		}
		if (ponavlja_se==false){
			VEKTOR za_unos(0);
			za_unos.push_back(*kontenjer1_pocetak);
			za_unos.push_back(fcija(*kontenjer1_pocetak));
		}
			
			matrix.push_back(za_unos);
		}
		kontenjer1_pocetak++;
	ponavlja_se = false;
	while(kontenjer2_pocetak != kontenjer2_kraj){
		art1 temporary = kontenjer1_pocetak;
		while(temporary != kontenjer1_kraj){
			if(fcija(*kontenjer2_pocetak) != fcija(*temporary)){
				ponavlja_se = false;
			} else {
				ponavlja_se = true;
				break;
			}
			temporary++;
		}
		if (ponavlja_se==false){
			VEKTOR za_unos(0);
			za_unos.push_back(*kontenjer2_pocetak);
			za_unos.push_back(fcija(*kontenjer2_pocetak));
			matrix.push_back(za_unos);
		}
		kontenjer2_pocetak++;
	}
	
	for(int i=0; i<matrix.size()-1; i++){
		for(int j=i+1; j<matrix.size(); j++){
			if(matrix[i][1] == matrix[j][1]){
				matrix.erase(matrix.begin()+j);
				j--;
			}
		}
	}
	

	sort(matrix.begin(), matrix.end(), [] (const VEKTOR v1, const VEKTOR v2) -> bool {
											if (v1[0]!=v2[0]) return v1[0]>v2[0];
											else if (v1[0]==v2[0]) return v1[1]>v2[1];
										}
	);
	
	return matrix;
	
	
}

/* ------------------------------------------------ */

int main(){
	int n1, n2;
	
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n1;
	std::deque<int> kontejner_br1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	kontejner_br1 = UnosDeka(n1);
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n2;
	std::deque<int> kontejner_br2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	kontejner_br2 = UnosDeka(n2);
	
	// Uvrnuti presjek
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	MATRICA matrica_1;
	matrica_1 = UvrnutiPresjek(kontejner_br1.begin(), kontejner_br1.end(), kontejner_br2.begin(), kontejner_br2.end(), SumaCifara);
	IspisMatrice(matrica_1);
	
	// Uvrnuta razlika
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	MATRICA matrica_2;
	matrica_2 = UvrnutaRazlika(kontejner_br1.begin(), kontejner_br1.end(), kontejner_br2.begin(), kontejner_br2.end(), SumaCifara);
	IspisMatrice(matrica_2);
	
	std::cout << "Dovidjenja!";
	return 0;
}
/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
	
	-OK, HVALA TI BERINA :*
*/

#include <vector>
#include <iostream>
#include <cmath>

bool DaLiJeProst(int n){
	//Funkcija vraća true ako je broj prost, false ako nije
	n = abs(n);
	for(int i = 2; i <= ceil(sqrt(n)); i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

int duzina(int n){
	//Funkcija vraća broj cifara broja
	if(n == 0) return 1;
	int duzina = 0;
	while(n){
		duzina++;
		n /= 10;
	}
	return duzina;
}

bool Simetricni(int broj){
	/*Funkcija prima broj
		pretvara ga u ternarni broj,
		njegove cifre u tom sistemu pohranjuje u vektor,
		provjerava da li su cifre simetriče,
		ako jesu vraća true, ako nisu vraća false
	*/
	std::vector<int> ternar;
	while(broj){
		ternar.push_back(broj%3);
		broj = broj / 3;
	}
	int idido = floor(ternar.size()/2);
	for(int i = 0; i < idido; i++){
		if(ternar.at(i) != ternar.at(ternar.size() - i - 1)) return false;
	}
	return true;
}

bool DaLiJeUVektoru(std::vector<int> v, int broj){
	//Funkcija vraća vrijednost true ako je posmatrani broj u vektoru
	//a vrijednost false ako posmatrani broj nije u vektoru
	for(int i = 0; i < v.size(); i++){
		if(v.at(i) == broj) return true;
	}
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> niz, bool tacno){
	std::vector<int> vektor;
	if(tacno){
	/*Ovo je slučaj kada se posmatraju prosti brojevi iz vektora*/	
		for(int i = 0; i < niz.size(); i++){
			if(DaLiJeProst(niz.at(i)) && Simetricni(niz.at(i)) && !DaLiJeUVektoru(vektor,niz.at(i))){
				vektor.push_back(niz.at(i));
			}
		}
		
	}else{
		/*Slučaj kada se posmatraju složeni brojevi iz vektora*/
		for(int i = 0; i < niz.size(); i++){
			if(!DaLiJeProst(niz.at(i)) && Simetricni(niz.at(i)) && !DaLiJeUVektoru(vektor,niz.at(i))){
				vektor.push_back(niz.at(i));
			}
		}
		
	}
	return vektor;
}

int main ()
{
	std::vector<int> brojevi;
	int unos;
	int odabir;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	//Unos cifara u vektor
	do{
		std::cin >> unos;
		if(unos == -1) break;
		brojevi.push_back(unos);
	}while(unos != -1);
	//Unos odabira u vektor (0 ili 1)
	do{
		std::cin >> odabir;
		if(odabir == 0 || odabir == 1) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(odabir != 0 || odabir != 1);
	
	if(odabir == 1){
		brojevi = IzdvojiSimetricneTernarne(brojevi, true);
		if(brojevi.size() == 0){
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i = 0; i < brojevi.size(); i++){
			if(i == brojevi.size() - 1){
				std::cout << brojevi.at(i) << ".";
			}else{
				std::cout << brojevi.at(i) << ", ";
			}
		}
	}else if(odabir == 0){
		brojevi = IzdvojiSimetricneTernarne(brojevi, false);
		if(brojevi.size() == 0){
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i = 0; i < brojevi.size(); i++){
			if(i == brojevi.size() - 1){
				std::cout << brojevi.at(i) << ".";
			}else{
				std::cout << brojevi.at(i) << ", ";
			}
		}
	}
	
	return 0;
}
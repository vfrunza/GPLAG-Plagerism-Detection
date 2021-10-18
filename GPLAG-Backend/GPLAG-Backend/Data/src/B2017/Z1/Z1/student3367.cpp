/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <cmath>
#include <vector>

bool daLiJeTernarniSimetrican(int broj){
	if(broj < 0) {
		
		broj *=-1;
	}
	int suma = 0;
	int obrnutaSuma = 0;
	int k = 1;
	while(broj > 0){

		int ostatak = broj %3;
		suma = suma  + ostatak*k;
		obrnutaSuma = obrnutaSuma*10 + ostatak;
		k*= 10;
		broj /=3;
		
	}
	
	if(suma == obrnutaSuma) return true;
	return false;
}
bool daLiJeProst(int broj){
	if (broj < 0) broj *= -1;
	
	for(int i = 2; i <=sqrt(broj); i++){
		if (broj%i == 0) return false;
	}
	return true;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor, bool prost){
	std::vector<int> novivektor;
	for(int i = 0; i < vektor.size(); i++){
		if( daLiJeProst(vektor.at(i)) == prost){
			if(daLiJeTernarniSimetrican(vektor.at(i))) novivektor.push_back(vektor.at(i));
		}
	}
	return novivektor;
}
int main ()
{
	std::vector<int> vektor;
	int n = 0;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		std::cin>>n;
		if(n == -1) break;
		vektor.push_back(n);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;){
		std::cin >> n;
		if( n== 0 || n== 1) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
			
	}
	vektor = IzdvojiSimetricneTernarne(vektor, n);
	if(vektor.size() == 0){
		if( n == 1) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		if( n == 0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	else{
		if( n == 1) std::cout << "Prosti simetricni brojevi iz vektora su: ";
		if( n == 0) std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	
		for(int i = 0; i < vektor.size(); i++){
			if(i == vektor.size()-1) std::cout << vektor.at(i) << ".";
			else std::cout << vektor.at(i) << ", ";
		}
	}
	return 0;
}
/*B 2017/2018, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/

//ako padnnu autotestovi provjeriti da li sam vodio racuna oko negativnih brojeva

#include <iostream>
#include <cmath>
#include <vector>

unsigned long long PretvoriUTernarne(int broj) // Pretvara decimalni broj u ternarni
{

	unsigned long long TernarniBroj(0);
	int i(1), ostatak;

	while (broj!=0) {

		ostatak = broj%3;
		broj /= 3;
		TernarniBroj += ostatak * i;
		i*=10;

	}

	return TernarniBroj;

}

int ObrniBroj(int broj) // Vraca broj okrenut naopako
{

	int cifra, ObrnutBroj(0);
	while (broj>0) {

		cifra=broj%10;
		ObrnutBroj=ObrnutBroj*10+cifra;
		broj/=10;

	}

	return ObrnutBroj;
}

bool DaLiJeProst(int broj)  // Vraca TRUE ako je prost, FALSE ako je slozen
{
	if (broj==0) return false;

	broj=std::abs(broj);
	
//	std::cout << broj << std::endl;

	for(int i=2; i<=int(std::sqrt(broj)); i++)
		if (broj%i==0) return false;

	return true;
}

bool DaLiJeUVektoru(std::vector<int> vektor, int broj) 
{

	for(int i=0; i<vektor.size(); i++)
		if (vektor.at(i)==broj) return false; //Broj se vec nalazi u vektoru

	return true; //Broja se ne nalazi u vektoru

}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> vektor, bool logicka)
{

	std::vector<int> PovratniVektor;

	if (logicka==true) {

		for(int i=0; i<vektor.size(); i++) {
			if((vektor.at(i)!=1) && (DaLiJeUVektoru(PovratniVektor,vektor.at(i))==true) && (DaLiJeProst(vektor.at(i))==true)
			        && (PretvoriUTernarne(vektor.at(i))==ObrniBroj(PretvoriUTernarne(vektor.at(i)))))
				PovratniVektor.push_back(vektor.at(i));
		}
	}

	else if (logicka==false) {

		for(int i=0; i<vektor.size(); i++) {
			if ((DaLiJeUVektoru(PovratniVektor,vektor.at(i))==true) && (DaLiJeProst(vektor.at(i))==false)
			        && (PretvoriUTernarne(vektor.at(i))==ObrniBroj(PretvoriUTernarne(vektor.at(i)))))
				PovratniVektor.push_back(vektor.at(i));
		}
	}

	return PovratniVektor;

}

int main ()
{
	std::vector<int> brojevi;

	std::cout << "Unesite elemente vektora (-1 za kraj): " ;
	int broj, LogVrijednost;

	do { // moze se desiti da se i ovdje unese nesto sto nije broj
		std::cin >> broj;
		if(broj!=-1) brojevi.push_back(broj);
	} while(broj!=-1);

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";

	for(;;) { // Moze se desiti da se unese nesto sto nije broj

		std::cin >> LogVrijednost;
		if(LogVrijednost==0 || LogVrijednost==1) break;
		std::cout << "Neispravan unos! Unesite ponovo: " ;

	}

	/*	for(;;){
		std::cin >> LogVrijednost;
		if((std::cin) && ((LogVrijednost==1) || (LogVrijednost==0))) break;
		std::cout << "Neispravan unos! Unesite ponovo: " ;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}  */

	std::vector<int> vektor(IzdvojiSimetricneTernarne(brojevi,LogVrijednost)) ;

	if(vektor.size()>0) {
		if (LogVrijednost==1) std::cout << "Prosti simetricni brojevi iz vektora su: " ;
		else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<vektor.size(); i++) {

			if(i==vektor.size()-1) std::cout << vektor.at(i)<< "."<<std::endl;
			else std::cout <<vektor.at(i)<<", ";
		}
	}

	else {
		if (LogVrijednost==1) std::cout << "Nema prostih simetricnih brojeva u vektoru." << std::endl;
		else std::cout << "Nema slozenih simetricnih brojeva u vektoru." << std::endl;
	}

	return 0;
}
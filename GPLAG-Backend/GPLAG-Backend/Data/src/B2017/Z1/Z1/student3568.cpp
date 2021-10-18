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
#include <vector>
#include <cmath> 
#include <stdexcept> 
#include <string> 

typedef std::vector<int> Vektor;

//funkcija koja racuna apsolutnu vrijednost od svih brojeva koji su iz opsega int
long long int ApsolutnaVrijednost (int n){
	if(n<0) return (static_cast<long long int> (abs(n+1)) + 1);
	return static_cast<long long int>(n);
}

//Provjerava da li je proslijedjeni cjelobrojni parametar prost broj
bool Prost(long long int broj)
{

	if(broj<0) throw std::domain_error("Pogresan parametar!");
	if(broj == 0 || broj == 1) return false;
	
	for(int i=2; i<=sqrt(broj); i++) {
		if(broj % i == 0) return false; 
	} 

	return true;
}

//Vraća string koji koji predstavlja zapis proslijedjenog cjelobrojnog parametra
//u ternarnom brojnom sistemu
std::string Ternarni(int broj)
{
	std::string ternarni("");
	
	if(broj < 0) ternarni+='-';
	
	int tmp(broj);
	while (tmp != 0) {
		char c(static_cast<char> (abs(tmp % 3) + '0'));
		ternarni+=c;
		tmp /= 3;
	}

	return ternarni;
}

//Vraća za proslijedjeni string onaj koji je njemu obrnut
std::string ObrnutString (std::string s)
{
	std::string obrnut("");

	for(int j=s.length()-1; j>=0; j--){
		obrnut+=s.at(j);
	}

	return obrnut;
}

//Provjerava da li je proslijedjeni string simetrican
bool SimetricanString (std::string s)
{
	return(s == ObrnutString(s));
	
}

//Provjerava da li se proslijedjeni cjelobrojni parametar nalazi u vektoru 
//koji je takodjer proslijedjen kao parametar
bool U_vektoru (Vektor v, int x)
{
	for(int i = 0; i<v.size(); i++) {
		if(v.at(i) == x) return true;
	}

	return false;
}

Vektor IzdvojiSimetricneTernarne (Vektor brojevi, bool t)
{ 
	//true - prosti, false - slozeni

	Vektor sim_ternarni;
	for(int x : brojevi) {
		if(x!=1 && (U_vektoru(sim_ternarni, x)==false) && (t == Prost(ApsolutnaVrijednost(x))) && SimetricanString(Ternarni(ApsolutnaVrijednost(x))))
			sim_ternarni.push_back(x); 
	}

	return sim_ternarni;
}


int main ()
{ 
	Vektor brojevi;

	std::cout<< "Unesite elemente vektora (-1 za kraj): "; 
	int broj(-1);
	do {
		std::cin >> broj;
		if(broj != -1) brojevi.push_back(broj);  
	} while (broj != -1);

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int t;
	for(;;){ 
		std::cin >> t;
		if(t==1 || t==0) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	
	Vektor v(std::move(IzdvojiSimetricneTernarne(brojevi, bool(t))));

	if(v.size() == 0 && t==true)
		std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else if(v.size() == 0 && t==false)
		std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	else {

		if(t==true)
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
		else
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";

		for(unsigned int i=0; i<v.size(); i++) {
			if(i != v.size()-1)
				std::cout << v.at(i) << ", ";
			else 
				std::cout << v.at(i) << "."; 
		}
  
	}
	return 0;
}
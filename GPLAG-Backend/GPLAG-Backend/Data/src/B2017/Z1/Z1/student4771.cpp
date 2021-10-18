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
#include <limits>
#include <deque>
#include <string>

//Funkcija za prevaranje brojeva u ternarne brojeve 
template<typename T> std::string PretvoriUTernarni(int broj){
	
	std::string rijec;
	int a=rijec.length()-1;
	char ostatak(0);
	do{
		ostatak=broj%3; 
		rijec=ostatak - '0';
		broj=broj/3;
	} while(broj!=0);
	for(int i=0; i<=a/2; i++){
		if(rijec.at(i)!=rijec.at(a-i-1)) return 0;
	}
	return rijec;
} 

//Funkcija koja provjerava da li su brojevi parni ili ne, te ako jesu vraca vrijednost "true", ako nisu "false".
bool DaLiSuProsti(unsigned int broj){
	if(broj<2) return 0;
	for(int i=2; i<=std::sqrt(broj); i++){
		if(broj%i==0) return false;
	} 
	return true;
}

template<typename NekiTip>
std::vector<NekiTip> IzdvojiSimetricneTernarne(std::vector<NekiTip> V1, bool a){ //Funkcija za izdvajanje simetricnih ternarnih brojeva
	std::vector<NekiTip> V2;
	for(int i=(V1.at(0)); i<=V1.size(); i++) {
		
		if(DaLiSuProsti(i)==true) {
			V2=(PretvoriUTernarni(i));
			}
		if(DaLiSuProsti(i)==false) { 
			V2=(PretvoriUTernarni(i));
			}
	}
	return V2;		//Povratni vektor funkcije sa prostim/slozenim ciframa cije su ternarne vrijednosti simetricne
}



int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	//Unos sslijeda brojeva za provjeru
	std::vector<int> V1;
	int broj;
	do{
		std::cin>>broj;
		if(broj!=-1) V1.push_back(broj);
	} while(broj!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool a;
	std::cin>>a;
	std::vector<int> V;
	V=IzdvojiSimetricneTernarne(V1,a);
	if(V.size()!=0){
	std::cout<<"Prosti simetricni brojevi iz vektora su: "<<std::endl;
	for(int i=0; i<V.size()-1; i++){
		if(i==V.size()-1)
		std::cout<<V.at(i);
		else
		std::cout<<V.at(i)<<", ";
	}
	std::cout<<".";
	}
	else {
	 std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	return 0;
}

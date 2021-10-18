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
#include<cmath>
#include<vector>
//prost
bool JeLiProst(int broj){
	long long int pozitivan(broj);
	if(broj<0) pozitivan*=-1;
	if(pozitivan<=2) return false;
	for(int i(2);i<=std::sqrt(pozitivan);i++){
		if(pozitivan%i==0) return false;
	}
	return true;
}

bool DaLiJeSimetrican(std::string broj);
std:: string PretvoriUTernarni(int broj);

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>vektor,bool logicka){
	std::vector<int>novi;
	if(logicka==true){
		for(int i(0); i<vektor.size();i++)
		if(JeLiProst(vektor.at(i))==true) novi.push_back(vektor.at(i));
	}

else{
	for(int i(0); i<vektor.size(); i++){
		if((vektor.at(i)==1)) continue;
		if(JeLiProst(vektor.at(i))==false) 
			novi.push_back(vektor.at(i));
	}
}

for(int i(0); i<novi.size();i++){
	std::string ternarni(PretvoriUTernarni(novi.at(i)));
	if(DaLiJeSimetrican(ternarni)!=true){
	novi.erase(novi.begin() + i);
	i--;
}
}

for(int i(0); i<novi.size();i++)
{
	for(int j(i+1);j<novi.size();j++)
{
	if(novi.at(i)==novi.at(j)) {
	novi.erase(novi.begin() + j);
	j--;
}
	
}

}
return novi;
	
}

//simetricnost
bool DaLiJeSimetrican(std::string broj){
	std::string obrnut;
	for(int i(broj.length()-1);i>=0;i--){
		obrnut.push_back(broj.at(i));
	}
	if(broj==obrnut) return true;
	else{
		return false;
	}
}

//pretvorba u ternarni
std:: string PretvoriUTernarni(int broj){
	std::string ternarni;
	while(broj!=0){
		ternarni.push_back(broj%3+'0');
		broj/=3;
	}
	return ternarni;
}


int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> brojevi;
	for(;;) {
		int a;
		std::cin >> a;
		if(a == -1) break;
		brojevi.push_back(a);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int unos;
	for(;;) {
		std::cin >> unos;
		if(unos != 1 && unos != 0) {
			std::cout << "Neispravan unos! Unesite ponovo: ";
			continue;
		}
		break;
	}
	bool prosti(unos);
	brojevi = IzdvojiSimetricneTernarne(brojevi, prosti);
	if(brojevi.size() == 0) {
		if(prosti) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	else {
		if(prosti) std::cout << "Prosti simetricni brojevi iz vektora su: ";
		else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	}
	for(int i(0); i < brojevi.size(); i++) {
		if(i != brojevi.size() - 1) std::cout << brojevi.at(i) << ", ";
		else std::cout << brojevi.at(i) << ".";
	}
	return 0;
}
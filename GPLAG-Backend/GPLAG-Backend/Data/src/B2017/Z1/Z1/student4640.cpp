#include <iostream>
#include <vector>
#include <cmath>

int PretvoriUTernarni (int n) {
	
	int broj(0), broj1(n);
	bool negativan=false;
	
	if (broj1 < 0) negativan=true;
	while (broj1!=0) {
		broj=broj*10 + (broj1)%3;
		broj1/=3;
	}
	
	int novi(0);
	while (broj != 0) {
		novi=novi*10 + broj%10;
		broj/=10;
	}
	if (negativan) return -novi;
	else return novi;
}


int Obrnut (int n) {
	int broj_cifara(int (log10 (n)));
	if (n==0) return 0;
	return ((n%10 * pow(10, broj_cifara)) + Obrnut(n/10));
}


bool Prost (int n) {
	
	bool prost=true;
	if (n <= 1 ) prost=false;
	else {
		for (int i=2; i<=sqrt(n); i++) {
			if (n%i==0) {
				prost=false;
				break;
			}
		}
	}
	if (prost) return true;
	return false;
}


bool Simetrican (int n) {
	
	if (Obrnut(PretvoriUTernarni(n)) == PretvoriUTernarni(n)) return true;
	return false;
}

	
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool a) {
	
	std::vector<int> prost, slozen;
	
	for (int i=0; i<v.size(); i++) {
		if (Prost(v.at(i)) && Simetrican(v.at(i)) && a) {
			 prost.push_back(v.at(i));
		}
		else if (!Prost(v.at(i)) && Simetrican(v.at(i)) && !a) {
			 slozen.push_back(v.at(i));
		}
	}
	
	if (a) {
	for (int i=0; i<prost.size(); i++) {
		for (int j=i+1; j<prost.size(); j++) {
			if (prost.at(i)==prost.at(j)) {
				for (int k=j; k<prost.size(); k++) 
					prost.at(k)=prost.at(k+1);
			}
		}
	} }
	else {
	for (int i=0; i<slozen.size(); i++) {
		for (int j=i+1; j<slozen.size(); j++) {
			if (slozen.at(i)==slozen.at(j)) {
				for (int k=j; k<slozen.size(); k++) 
					slozen.at(k)=slozen.at(k+1);
			}
		}
	} }
	
	if (a) return  prost;
	return slozen;
}
	
	int main () {
		
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
		std::cin>>broj;
		if (broj == -1) break;
		else v.push_back(broj);
	}
	while (broj != -1);
	
	int opcija, izbor(0);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>opcija;
		if (opcija != 0 && opcija != 1) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
		else izbor=opcija;
	}
	while (opcija != 0 &&  opcija != 1);
		
		if (izbor == 1) {
		std::vector<int>vraceni=IzdvojiSimetricneTernarne(v, true);
		if (vraceni.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<vraceni.size(); i++) {
			if (i==vraceni.size()-1) std::cout<<vraceni.at(i)<<".";
			else std::cout<<vraceni.at(i)<<", ";
		} } }
		
		else if (izbor == 0) {
			
			std::vector<int>vraceni=IzdvojiSimetricneTernarne(v,false);
			if (vraceni.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0; i<vraceni.size(); i++) {
				if (i==vraceni.size()-1) std::cout<<vraceni.at(i)<<".";
				else std::cout<<vraceni.at(i)<<", ";
			}
		}
	}
		return 0;
	}
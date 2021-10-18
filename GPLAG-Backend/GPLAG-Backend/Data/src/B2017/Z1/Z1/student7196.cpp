#include <iostream>
#include <vector>
#include <cmath>

long int ObrnutBroj(long int broj) {
	long int obrnut(0);
	while (broj) {
		int cifra(broj%10);
		obrnut=obrnut*10+cifra;
		broj/=10;
	}
	return obrnut;
}

bool SlozenIliNula(int broj) {
	if (broj==0) return true;
	for (int i=2; i<=std::sqrt(broj); i++) {
		if (broj%i==0) return true;
	}
	return false;
}

bool Jednaki(long int prvi, long int drugi) {
	if (prvi==drugi) return true;
	return false;
}

long int Dec2Ter(int broj) {
	long int novi(0), kolicnik(1);
	int brojac(0);
	while (kolicnik) {
		kolicnik=broj/3;
		novi+=(broj%3)*int(std::pow(10, brojac++));
		broj/=3;
	}
	return novi;
}

std::vector<int> IzbaciPonavljanja(std::vector<int> v) {
	std::vector<int> novi;
	novi=v;
	for (int i=1; i<novi.size(); i++) {
		for (int j=0; j<i; j++) {
			if (novi.at(j)==novi.at(i)) {
				novi.erase(novi.begin()+i);
				j--;
				i--;
			}
		}
	}
	return novi;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool pomocna) {
	int broj;
	long int ternarni;
	std::vector<int> vektor;
	for (int i=0; i<v.size(); i++) {
		if (v.at(i)<0) broj=-v.at(i);
		else broj=v.at(i);
		ternarni=Dec2Ter(broj);
		if (pomocna) {
			if (!SlozenIliNula(broj) && Jednaki(ternarni, ObrnutBroj(ternarni))) vektor.push_back(broj);
		}
		else {
			if (SlozenIliNula(broj) && Jednaki(ternarni, ObrnutBroj(ternarni))) vektor.push_back(broj);
		}
		
	}
	vektor=IzbaciPonavljanja(vektor);
	return vektor;
}

int main ()
{
	int broj, pomocna;
	std::vector<int> v, novi;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> broj;
		if (broj!=-1) v.push_back(broj);
	} while (broj!=-1);
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> pomocna;
	while (pomocna!=0 && pomocna!=1) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> pomocna;
	}
	
	novi=IzdvojiSimetricneTernarne(v, pomocna);
	
	if (novi.size()==0) {
		if (pomocna) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 1;
		}
		else {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 1;
		}
	}
	
	if (pomocna) {
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<novi.size(); i++) {
			if (i<novi.size()-1) {
				std::cout << novi.at(i) << ", ";
			}
			else {
				std::cout << novi.at(i) << ".";
			}
		}
	}
	else {
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<novi.size(); i++) {
			if (i<novi.size()-1) {
				std::cout << novi.at(i) << ", ";
			}
			else {
				std::cout << novi.at(i) << ".";
			}
		}
	}
	
	return 0;
}
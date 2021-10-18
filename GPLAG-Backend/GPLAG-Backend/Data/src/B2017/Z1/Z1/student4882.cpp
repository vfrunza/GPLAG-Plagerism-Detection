#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cmath>

// pomocna funkcija provjerava da li je proslijedjeni broj prost
bool DaLiJeProst (int n) {
	bool djeljiv(true);
	if (n<0) n=n*(-1);
	if (n<=1) return false;
	for (int i=2; i<n; i++) {
		if (n%i==0) return false;
		if (i==n-1) break; 
	}
	return djeljiv;
}

// pomocna funkcija racuna broj cifara u slovu
int PrebrojCifre (int broj) {
	int brojac(0);
	while (broj!=0) {
		broj=broj/10;
		brojac++;
	}
	return brojac;
}

// pomocna funkcija pretvara broj iz dekadnog u ternarni sistem
int PretvoriUTernarni (int normalan) {
	int ternarni(0), stepen(1);
	if (normalan<0) normalan=normalan*(-1);
	while (normalan!=0) {
		ternarni+=(normalan%3)*stepen;
		stepen=stepen*10;
		normalan=normalan/3;
	}
	return ternarni;
}

// pomocna funkcija provjerava je li broj u ternarnom zapisu simetrican
bool JeriSimetrican (int broj) {
	bool simetrija(false);
	if (broj<0) broj=broj*(-1);
	int temp=broj, novi(0);
	while (temp!=0) {
		novi=novi*10;
		novi+=(temp%10);
		temp=temp/10;
	}
	if (broj==novi) simetrija=true;
	return simetrija;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> vektor, bool logika) {
	std::vector<int> odvojeni;
	// slucaj kada se traze prosti simetricni
	if (logika==true) {
		for (int i=0;i<vektor.size();i++) {
			if (DaLiJeProst(vektor.at(i))==1 and (JeriSimetrican(PretvoriUTernarni(vektor.at(i))))==1) {
				odvojeni.push_back(vektor.at(i));
			}
			if (i==vektor.size()-1) break; 
		}
	}
	// slucaj kada se traze slozeni simetricni
	else {
		for (int i=0; i<vektor.size();i++) {
			if (DaLiJeProst(vektor.at(i))==0 and (JeriSimetrican(PretvoriUTernarni(vektor.at(i))))==1) {
					odvojeni.push_back(vektor.at(i));
			}
			if (i==vektor.size()-1) break;
		}
	}
	// petlja izbacuje elemente koji se ponavljaju 
	for (int i=0; i<odvojeni.size(); i++) {
		for (int j=0; j<odvojeni.size(); j++) {
			if (odvojeni.at(i)==odvojeni.at(j) and i!=j) odvojeni.erase(odvojeni.begin()+j);
		}
	}
	for (int i=0; i<odvojeni.size(); i++) {
		if (std::fabs(odvojeni.at(i))<=1) odvojeni.erase(odvojeni.begin()+i);
	}
	return odvojeni;
}

int main ()
{
	int k;
	std::vector<int> vektor;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	while (1) {
		std::cin >> k;
		if (k==-1) break;
		vektor.push_back(k);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int c;
	for (;;) {
		std::cin >> c;
		if (c==1 or c==0) break;
		else {std::cout << "Neispravan unos! Unesite ponovo: ";}
	}
	bool t=c;
	std::vector<int> test=IzdvojiSimetricneTernarne(vektor, t);
	if (c==1) {
		if (test.size()==0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<test.size(); i++) {
			if (i==test.size()-1) std::cout << test.at(i) << ".";
			else std::cout << test.at(i) << ", ";
			if (i==test.size()-1) break;
		}
	}
	if (c==0) {
		if (test.size()==0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<test.size(); i++) {
			if (i==test.size()-1) std::cout << test.at(i) << ".";
			else std::cout << test.at(i) << ", ";
			if (i==test.size()-1) break;
		}
	}
	return 0;
}

// uslovi u kodu tipa "if (varijabla==granica-1) break;" predstavljaju zastitu od prekoracenja u slucaju da je granica
// maksimalna vrijednost nekog cjelobrojnog tipa
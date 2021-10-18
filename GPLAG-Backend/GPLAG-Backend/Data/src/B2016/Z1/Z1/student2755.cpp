#include <iostream>
#include <vector>
#include <cmath>

int Obrni(int n) {
	int novi(0);
	while(n!=0) {
		novi = novi*10 + n%10;
		n/=10;
	}
	return novi;
}

int Ternarni(int n) {
	int rez(0);
	while(n!=0) {
		rez = rez*10 + n%3;
		n/=3;
	}
	return Obrni(rez);
}

bool Testiraj(int n) {
	int cifra, brojaci[3]={0};
	while(n!=0) {
		cifra=n%10;
		brojaci[cifra]++;	//histogram - brojimo koliko se puta javlja svaka cifra u ternarnom obliku broja
		n/=10;
	}
	bool paran(false);
	for(int i(0); i<3; i++) {
		if(brojaci[i]%2==0 && brojaci[i]!=0) paran=true;
		else paran=false;
	}
	return paran;
}

bool Ponavljanje (int n, std::vector<int> v) {
	int br(0);
	for(int i(0); i<v.size(); i++) {
		if(n==v[i]) br++;
	}
	if(br>=1) return true;
	else return false;
} 

std::vector<int> IzdvojiGadne (std::vector<int> v, bool var) {
	std::vector<int> privremeni;
	std::vector<int> rez1;
	std::vector<int> rez2;
	privremeni=v;
	bool test;
	for(int i(0); i<privremeni.size(); i++) {
		privremeni[i]=Ternarni(fabs(v[i]));
		test=Testiraj(privremeni[i]);
		if(test) {
			if(Ponavljanje(v[i], rez1)) continue;	//ako se element vec jednom javlja u vektoru preskacemo njegov ispis
			rez1.push_back(v[i]);
		}
		else {
			if(Ponavljanje(v[i], rez2)) continue;	//ako se element vec jednom javlja u vektoru preskacemo njegov ispis
			rez2.push_back(v[i]);
		}
	}
	if(var) return rez1;
	else return rez2;
}

int main () {
	std::vector<int> v;
	int broj;
	std::cout << "Unesite brojeve: ";
	do{
		std::cin >> broj;
		if(broj!=0) v.push_back(broj);
	} while(broj!=0);
	
	std::vector<int> novi(IzdvojiGadne(v, false));
	for(int i(0); i<novi.size(); i++) std::cout << novi[i] << " ";
	
	return 0;
}
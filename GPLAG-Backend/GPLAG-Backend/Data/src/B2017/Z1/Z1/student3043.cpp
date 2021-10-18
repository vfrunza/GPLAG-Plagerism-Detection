#include <iostream>
#include <vector>
#include <cmath>

bool jeProst(int broj) {
	if(broj<=1) return false;
	for(int i=2; i<broj; i++) 
	if(broj%i==0) return false;
	return true;
}

int uBazu3(int broj) {
	int  r=0, f=1;
	while (broj>0) {
		r+=broj%3*f;
		broj/=3;
		f=f*10;
	}
	return r;
}
bool jeSimetrican(int broj) {
	int naopacke = 0, kopija=broj;
	while(kopija>0) {
		naopacke=naopacke*10;
		naopacke=naopacke+kopija%10;
		kopija=kopija/10;
	}
	return broj==naopacke;
	}
std::vector <int> IzdvojiSimetricneTerenarne(std::vector<int> unos, bool t) {
	std::vector<int> rjesenje;
	for (int i=0; i<unos.size(); i++) {
		if(jeProst(unos.at(i))==t && jeSimetrican(uBazu3(unos.at(i))))
		rjesenje.push_back(unos.at(i));
	}
	return rjesenje;
}
int main () {
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> unos;
	int a;
	for(;;) {
	std::cin>> a;
	if(a==-1) break;
	unos.push_back(a); }
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int t;
	bool t1;
	for(;;) {
		std::cin >> t;
		if( t!=1 && t!=0) {
			std::cout << "Neispravan unos! Unesite ponovo: ";
		}
		else {
			t1=t;
			break;
		}
	}
	
std::vector<int> rjesenje;

rjesenje = IzdvojiSimetricneTerenarne(unos, t1);
if(rjesenje.size() ==0) {
	if(t1) std::cout <<"Nema prostih simetricnih brojeva u vektoru.";
	else std::cout <<"Nema slozenih simetricnih brojeva u vektoru.";
}
else {
	if(t1) std::cout <<"Prosti simetricni brojevi iz vektora su: ";
	else std::cout <<"Slozeni simetricni brojevi iz vektora su: ";
}
for(int i(0); i<rjesenje.size(); i++) {
	if(i == rjesenje.size() - 1) std::cout << rjesenje.at(i) << ".";
	else std::cout << rjesenje.at(i) <<", ";
}
return 0;
}

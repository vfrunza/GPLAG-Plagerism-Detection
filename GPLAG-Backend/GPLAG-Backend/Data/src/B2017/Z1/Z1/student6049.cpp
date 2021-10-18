#include<iostream>
#include<vector>
#include<cmath>
bool Prost (int broj) {
	if(broj<=1) return false;
	for(int i(2); i<=sqrt(broj); i++) {
	    if(broj%i==0) return false;
	}
	return true;
}

bool SimetricanTernarni (std::vector<int> v) {
	for(int i(0); i<v.size()/2; i++) {
		if(v.at(i)!=v.at(v.size()-1-i)) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool prost) {
	std::vector<int> simetricniternarni;
	for(int i(0); i<v.size(); i++) {
		int broj(abs(v.at(i)));
		std::vector<int> cifre;
		while(broj!=0) {
			cifre.push_back(broj%3);
			broj/=3;
		}
		broj=abs(v.at(i));
		if(prost && Prost(broj) && SimetricanTernarni(cifre) && broj!=1) {
			simetricniternarni.push_back(v.at(i));
		
		}
	    else if(!prost && !(Prost(broj)) && SimetricanTernarni(cifre) && broj!=1) {
			simetricniternarni.push_back(v.at(i));
		}
	}
	for(int i(0); i<simetricniternarni.size(); i++) {
		for(int j(i+1); j<simetricniternarni.size(); j++) {
			if(simetricniternarni.at(i)==simetricniternarni.at(j)) {
				simetricniternarni.erase(simetricniternarni.begin()+j);
				j--;
			}
		}
	}
	return simetricniternarni;
}
int main () {
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	int broj;
	for(;;) {
		std::cin>>broj;
		if(broj!=-1) v.push_back(broj);
		else break;
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prostslozen;
	for(;;) {
		std::cin>>prostslozen;
		if(prostslozen!=1 && prostslozen!=0) std::cout<<"Neispravan unos! Unesite ponovo: ";
		else break;
	}
	std::vector<int> novivektor(IzdvojiSimetricneTernarne(v,prostslozen));
	if(novivektor.size()==0) {
		if(prostslozen==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else if(prostslozen==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	else {
		if(prostslozen) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i(0); i<novivektor.size(); i++) {
			if(i==novivektor.size()-1) std::cout<<novivektor.at(i)<<".";
			else std::cout<<novivektor.at(i)<<", ";
		}
	}
	return 0;
}
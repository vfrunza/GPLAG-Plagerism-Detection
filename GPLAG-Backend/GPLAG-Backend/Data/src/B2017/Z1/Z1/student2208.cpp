#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int broj)
{
	if (broj<2) return false;
	for (int i=2; i<=sqrt(broj); i++) {
		if (broj%i==0) return false;
	}
	return true;
}

std::vector<int> PretvoriUTernarne (int n)
{
	std::vector<int> v;
	while (n!=0) {
		int broj;
		broj=std::abs(n%3);
		v.push_back(broj);
		n/=3;
	}

	return v;
}

bool DaLiJeSimetrican (std::vector<int> v)
{
	if (v.size()%2==0) {
		for (int i(0); i<v.size()/2; i++) {
			if (v.at(i) != v.at (v.size()-i-1)) return false;
		}
	} else if (v.size()%2!=0) {
		for (int i(0); i<v.size()/2+1; i++) {
			if (v.at(i) != v.at(v.size()-i-1)) return false;
		}
	}

	return true;
}

std::vector <int> IzdvojiSimetricneTernarne (std::vector<int> v, bool tacnost)
{
	std::vector <int> vektor;
	for (int i=0; i<v.size(); i++) {
		if (tacnost==true) {
			if (v.at(i)==1) continue;
			if (DaLiJeProst(v.at(i))==true) vektor.push_back(v.at(i));
		}

		else if (tacnost==false) {
			if (v.at(i)==1) continue;
			if (DaLiJeProst(v.at(i))==false) vektor.push_back(v.at(i));
		}
	}

	std::vector<int> ternarni;
	for (int i(0); i<vektor.size(); i++) {
		ternarni = PretvoriUTernarne(vektor.at(i));
		bool t;
		t=DaLiJeSimetrican(ternarni);
		if (t==false) {
			vektor.erase(vektor.begin()+i);
			i--;
		}
	}
	if (vektor.size()==0) return vektor;
	else {
		for (int i(0); i<vektor.size()-1; i++) {
			for (int j(i+1); j<vektor.size(); j++) {
				if (vektor.at(i)==vektor.at(j)) vektor.erase(vektor.begin()+j);
			}
		}
	}

	return vektor;
}
int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int element;
	do {
		std::cin>>element;
		if (element != -1 ) v.push_back(element);
	} while (element != -1);

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int tacnost;
	do {
		std::cin>>tacnost;
		if (tacnost!=1 && tacnost!=0) std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while (tacnost!=1 && tacnost!=0);
	if (tacnost==1) {
		std::vector<int> vektor;
		vektor=IzdvojiSimetricneTernarne(v, true);
		if (vektor.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for (int i(0); i<vektor.size(); i++) {
				if (i==vektor.size()-1) std::cout<<vektor.at(i)<<"."<< std::endl;
				else std::cout<<vektor.at(i)<<", ";
			}
		}
	}

	else if (tacnost==0) {
		std::vector <int> vektor;
		vektor = IzdvojiSimetricneTernarne(v, false);
		if (vektor.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for (int i(0); i<vektor.size(); i++) {
				if (i==vektor.size()-1) std::cout<<vektor.at(i)<<"."<<std::endl ;
				else std::cout<<vektor.at(i)<<", ";
			}
		}
	}
	return 0;
	
}
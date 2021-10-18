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

bool JeLiProst(int n) {

	int k(sqrt(n));
	for(int i=2; i<=k; i++) {
		if(n%i==0) return false;
	}
	return true;
}


std::vector<int> Ternarni(int n) {
	std::vector<int> rez;

	while(n!=0) {
		rez.push_back(n%3);
		n/=3;
	}

	return rez;
}

bool Simetricni(std::vector<int> v) {

	bool jeste=true;
	for(int i=0, j=v.size()-1; i<v.size()/2; i++, j--) {

		if(v.at(i)!=v.at(j))
			jeste=false;
	}

	return jeste;

}

std::vector<int> IzdvojiSimetricneTernarne(std::vector <int> v, bool prost) { //msm da funckija prost treba biti bool, tj da li je prost
	std::vector <int> v1;

	if(prost) {
		for(auto x : v) {

			if(Simetricni(Ternarni(x))==true && JeLiProst(x)==true ) { //izdvaja one sa prostim

				bool ima=true;
				for(auto y : v1) {
					if(y==x) ima=false;
				}
				if(ima==true) v1.push_back(x);
			}
		}
	} else {
		for(auto x : v) {

			if(Simetricni(Ternarni(x))==true && JeLiProst(x)==false) { //izdvaja one sa slozenim brojevima

				bool ima=true;
				for(auto y : v1) {
					if(y==x) ima=false;
				}
				if(ima==true) v1.push_back(x);
			}
		}
	}

	return v1;

}

int main () {

	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> A(0);

	while(true) {
		int x=0;
		std::cin >> x;
		if(x==(-1)) break;
		A.push_back(x);
	}

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int n;

	do {
		std::cin >>n;
		if(n!=1 && n!=0) std::cout << "Neispravan unos! Unesite ponovo: ";
	} while((n!=1) && (n!=0));


	std::vector<int> B(0),C(0);
	B=IzdvojiSimetricneTernarne(A,true);
	C=IzdvojiSimetricneTernarne(A,false);

	if(n==1) {
		if(B.size()>0) {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for(auto x : B) {
				std::cout << x;
				if(x!=B.at(B.size()-1)) {
					std::cout << ", ";
				} else std::cout <<".";
			}
		} else std::cout <<"Nema prostih simetricnih brojeva u vektoru.";

		}

	if(n==0) {
		if(C.size()>0) {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(auto x : C) {
				std::cout << x;
				if(x!=C.at(C.size()-1)) {
					std::cout << ", ";
				} else std::cout << ".";

			}
		} else std::cout <<"Nema slozenih simetricnih brojeva u vektoru.";
		}


	return 0;
}

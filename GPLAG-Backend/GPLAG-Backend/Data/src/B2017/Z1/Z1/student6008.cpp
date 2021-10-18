#include <iostream>
#include <vector>
#include <cmath>

bool Prost(int n)
{
	if (n==2 || n==3 ) return true;
	if (n<0 || n==1) return false;
	if ( n%2==0 ) return false;
	for (int i=3; (unsigned int)(i*i)<=n; i++) {
		if ( n%i==0 ) return false;
	}
	return true;
}


bool Pretvaranje (int x)
{
	int i=0,j,k=0;
	std::vector<int> V(100);
	std::vector<int> V1(100);
	if (x<0) x=fabs(x);
	while(x>0) {
		V.at(i)=x%3;
		i++;
		x=x/3;
	}
	V.resize(i);
	for (j=V.size()-1; j>=0; j--) {
		V1.at(k)=V.at(j);
		k++;
	}
	V1.resize(k);
	if (V==V1) return true;
	else return false;
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v,bool a)
{
	int i;
	std::vector<int> vektor;
	if (a) {
		for (i=0; i<v.size(); i++) {
			if (Prost(v.at(i))) {
				if (Pretvaranje(v.at(i))) {
					bool unesen=false;
					for(int j=0; j<int(vektor.size()); j++) {
						if (vektor.at(j)==v.at(i)) unesen=true;
					}
					if (!unesen) vektor.push_back(v.at(i));
				}
			} else continue;
		}
		return vektor;
	} else if (a==false) {
		for (i=0; i<v.size(); i++) {
			if (Prost(v.at(i))==false) {
				if (Pretvaranje(v.at(i))) {
					bool unesen=false;
					for(int j=0; j<int(vektor.size()); j++) {
						if (vektor.at(j)==v.at(i)) unesen=true;
					}
					if (!unesen) vektor.push_back(v.at(i));
				}
			} else continue;
		}
		return vektor;
	}
}


int main ()
{
	std::vector<int> v;
	std::vector<int> w;
	int i,j;
	int n;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for (;;) {
		std::cin>>i;
		if (i==-1) break;
		else v.push_back(i);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for (;;) {
		std::cin>>n;
		if (n==1 || n==0) break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	w=IzdvojiSimetricneTernarne(v,n);
	if (n==1) {
		if (w.size()==0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		} else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for (j=0; j<w.size()-1; j++) {
				std::cout<<w.at(j)<<", ";
			}
			std::cout<<w.at(w.size()-1)<<".";
		}
	} else if (n==0) {
		if (w.size()==0) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		} else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for (j=0; j<w.size()-1; j++) {
				std::cout<<w.at(j)<<", ";
			}
			std::cout<<w.at(w.size()-1)<<".";
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>


std::vector<int> PretvoriUTernarni (int broj)
{
	std::vector<int> v;
	int p=broj;
	int c;
	while(p!=0) {
		c=p%3;
		p=p/3;
		v.push_back(c);
	}
	
	return v;
}

std::vector<int> ObrniUTernarni (std::vector<int> v)
{ 
	std::vector<int> V;
	for(int i=v.size()-1; i>=0; i--){
		V.push_back(v.at(i));
	}

	return V; 
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool n)
{
	std::vector<int> VP, VS;
	for(int i=0; i<v.size(); i++) {
		bool prost(true);
		for(int j=2; j<v.at(i); j++) {
			if(v.at(i)%j==0) {
				prost=false;
				break;
			}
		}
		if(prost) VP.push_back(v.at(i));
		else VS.push_back(v.at(i));
	}
	std::vector<int> Rezultantni;
	if(n==true) {
		for(int i=0; i<VP.size(); i++) {
			if	(PretvoriUTernarni(VP.at(i))==ObrniUTernarni(PretvoriUTernarni(VP.at(i)))) {
				Rezultantni.push_back(VP.at(i));
			}
		}
	} else {
		for(int i=0; i<VS.size(); i++) {
			if (PretvoriUTernarni(VS.at(i))==ObrniUTernarni(PretvoriUTernarni(VS.at(i)))) {
				Rezultantni.push_back(VS.at(i));
			}
		}
	}
	for(int i=0; i<Rezultantni.size(); i++) {
		for(int j=i+1; j<Rezultantni.size(); j++) {
			if(Rezultantni.at(i)==Rezultantni.at(j)) Rezultantni.erase(Rezultantni.begin()+j);
		}
	}
	return Rezultantni;
}


int main ()
{
	int n(0);
	std::vector<int> v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	while(n!=-1) {
		std::cin >> n;
		if(n==-1) {
			break;
		}
		v.push_back(n);
	}
	int k;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> k;
	while (k!=1 && k!=0) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> k;
		if(k==1 || k==0) break;
	}
	if(k==true) {
		std::vector<int> Konacni(IzdvojiSimetricneTernarne(v,true));
		if(Konacni.size()==0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<Konacni.size(); i++) {
			std::cout << Konacni.at(i);
			if(i!=Konacni.size()-1) {
				std::cout << ", ";
			} else {
				std::cout <<".";
			}
		}
	} else if(k==false) {
		std::vector<int> Konacni(IzdvojiSimetricneTernarne(v,false)) ;
		if(Konacni.size()==0){
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<Konacni.size(); i++) {
			std::cout << Konacni.at(i);
			if(i!=Konacni.size()-1) {
				std::cout << ", ";
			} else {
				std::cout << ".";
			}
		}
	}

	return 0;
}
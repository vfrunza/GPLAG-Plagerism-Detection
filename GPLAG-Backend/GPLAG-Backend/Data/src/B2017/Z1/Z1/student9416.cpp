#include <iostream>
#include <vector>
#include <cmath>

/* Funkcija koja vraca vrijednost true ili false u zavisnosti od proslijedjenog parametra n */
bool DaLiJeProst(int n)
{
	if(n==0) return false; //Nulu posmatramo kao slozen broj
	n=fabs(n);
	for(int i=2; i<n; i++) {
		if(n%i==0)return false;
	}
	return true;
}

bool DaLiJeSimetricanTernarni(int broj)
{
	if(broj==1)return false;
	int t(0);
	broj=fabs(broj);
	
	while(broj!=0) {
		int cifra=broj%3;
		broj=broj/3;
		t=t*10 + cifra;
	}
	int pamti(t);
	int k(0);
	while(t!=0) {
		int cifra=t%10;
		t=t/10;
		k=k*10 + cifra;
	}

	if(pamti==k)return true;
	else return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool logicka)
{
	std::vector<int> novi;
	std::vector<int> novi2;
//U vektor novi smijestamo sve simetricne ternarne brojeve iz vektora v
	for(int i=0; i<v.size(); i++) {
		if(DaLiJeSimetricanTernarni(v.at(i))) novi.push_back(v.at(i));
	}
	
	if(logicka) {
		for(int i=0; i<novi.size(); i++) {
			if(DaLiJeProst(novi.at(i)))  novi2.push_back(novi.at(i)); //Ako je prost smjestimo ga u vektor novi2
		}
	} else {
		for(int i=0; i<novi.size(); i++) {
			if(DaLiJeProst(novi.at(i))==false) novi2.push_back(novi.at(i));//Ako je slozen smjestimo ga u vektor novi2
		}
	}

//Iz vektora izbacimo sve one brojeve koji su dupli
	for(int i=0; i<int(novi2.size()-1); i++) {
		for(int j=(i+1); j<novi2.size(); j++) {
			if(novi2.at(j)==novi2.at(i)) novi2.erase(novi2.begin() + j);
		}
	}
	return novi2;

}

int main ()
{
	std::vector<int> vektor;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		int broj;
		std::cin>>broj;
		if(!std::cin){
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else if(broj==-1)break;
		else vektor.push_back(broj);
	} while(1);

	int logicka;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>logicka;
		if (logicka==0 || logicka==1) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";

	} while(1);
	
	std::vector<int> novi(IzdvojiSimetricneTernarne(vektor, logicka)) ;

	if(logicka) {
		if(novi.size()==0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<novi.size(); i++) {
			std::cout<<novi.at(i);
			if(i==(novi.size()-1)) std::cout<<".";
			else std::cout<<", ";
		}
	} else {
		if(novi.size()==0) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<novi.size(); i++) {
			std::cout<<novi.at(i);
			if(i==(novi.size()-1)) std::cout<<".";
			else std::cout<<", ";
		}
	}
	return 0;
}
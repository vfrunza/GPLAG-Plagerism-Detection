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

typedef std::vector<int> vektor;

bool BioUVektoru(int n, vektor v) {
	bool bio_vec(false);
	for(int i=0; i<v.size(); i++) {
		if(n==v.at(i)) {
			bio_vec=true;
			break;
		}
	}
	return bio_vec;
}

bool Prost(int n) {
	int pomocni;
	if(n<0) {
		pomocni=n*(-1);
	} else pomocni=n;
	
	bool prost=true;
	if(pomocni==1) {
		prost=false;
		return prost;
	}
	for(int i=2; i*i<=pomocni; i++) {
		if(pomocni%i==0) {
			prost=false;
			break;
		}
	}
	return prost;
}

int Ternarni(int n) {
	vektor v;
	bool negativan;
	int ternarni(0);
	
	if(n<0) {
		negativan=true;
		n*=(-1);
	} else negativan=false;
	
	while(n!=0) {
		v.push_back(n%3);
		n/=3;
	}
	
	for(int i=v.size()-1; i>=0; i--) 
		ternarni=10*ternarni+v.at(i);
	
	if(negativan) return ternarni*(-1);
	else return ternarni;
}

bool TernarniSimetrican (int ternarni) {
	vektor v;
	bool simetrican=true;
	
	if(ternarni<0) ternarni*=(-1);
	
	while(ternarni!=0) {
		v.push_back(ternarni%10);
		ternarni/=10;
	}
	
	for(int i=0; i<v.size()/2; i++) {
		if(v.at(i)!=v.at(v.size()-1-i)) {
			simetrican=false;
			break;
		}
	}
	
	return simetrican;
}

vektor IzdvojiSimetricneTernarne (vektor v, bool logy) {
	vektor povratni;
	for(int i=0; i<v.size(); i++) {
		int ternarni(0);
		if(logy) {
			if(Prost(v.at(i))) {
				ternarni=Ternarni(v.at(i));
				if(TernarniSimetrican(ternarni) && !BioUVektoru(v.at(i), povratni)) povratni.push_back(v.at(i)); 
			}
		} else {
			if(!Prost(v.at(i))) {
				ternarni=Ternarni(v.at(i));
				if(TernarniSimetrican(ternarni) && !BioUVektoru(v.at(i), povratni)) povratni.push_back(v.at(i));
			}
		}
	}
	return povratni;
}

int main ()
{
	vektor v;
	int broj(0), izbor;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>broj;
		if(broj!=-1) v.push_back(broj);
	} while(broj!=-1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;) {
		std::cin>>izbor;
		if(izbor==1 || izbor==0) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	//	std::cin.clear();
	//	std::cin.ignore(1000, '\n');
	}
	
	vektor v1(IzdvojiSimetricneTernarne(v, izbor));
	if(v1.size()!=0) {
		if(izbor==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size(); i++) {
			if(i!=v1.size()-1) std::cout<<v1.at(i)<<", ";
			else std::cout<<v1.at(i)<<".";
		}
	} else {
		if(izbor==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	
	return 0;
}
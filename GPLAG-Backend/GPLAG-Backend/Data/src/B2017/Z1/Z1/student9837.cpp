#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef std::vector<int> vektor;

bool ProstBroj (int n)
{
	int br=0;
	if(n==1) {
		return(false);
	} else {
		for(int i=1; i<=n; i++) {
			if(n%i==0) br++;
		}
		if(br==2) return(true);
		else return(false);
	}
}


vektor Prostiilislozeni (vektor e, bool f)
{
	vektor p;
	vektor s;
	for(int y: e) {
		if(ProstBroj(y)==true) {
			p.push_back(y);
		} else {
			s.push_back(y);
		}
	}
	if(f==true) return p;
	else return s;
}


int PretvoriUTernarni (int v)
{
	int g(1), t(0);
	do {
		int trenutna=v;
		v=v/3;
		int o=trenutna-(v*3);
		t=t+(o*g);
		g=g*10;
	} while(v>0);
	return t;
}


bool Palindrom (int n)
{
	int cifra, rev=0;
	int ncopy=n;
	do {
		cifra=n%10;
		rev=(rev*10)+cifra;
		n=n/10;
	} while (n>0);

	if(ncopy==rev)
		return true;
	else
		return false;
}


vektor IzdvojiSimetricneTernarne (vektor a, bool b)
{
	vektor prosti;
	vektor slozeni;
	vektor simetricniprosti, simetricnislozeni;
	if(b==true) {
		prosti=Prostiilislozeni(a, true);
		for (auto i: prosti) {
			if(Palindrom(PretvoriUTernarni(i))==true)
				simetricniprosti.push_back(i);
		}
	} else {
		slozeni=Prostiilislozeni(a, false);
		for(auto i: slozeni) {
			if(Palindrom(PretvoriUTernarni(i))==true)
				simetricnislozeni.push_back(i);
		}
	}

	simetricniprosti.erase(unique(simetricniprosti.begin(), simetricniprosti.end()), simetricniprosti.end());

	simetricnislozeni.erase(unique(simetricnislozeni.begin(), simetricnislozeni.end()), simetricnislozeni.end());

	if(b==true) return simetricniprosti;
	else return simetricnislozeni;
}


int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	vektor unos;
	vektor ispis;
	int broj;
	do {
		std::cin>>broj;
		if (broj!=-1) unos.push_back(broj);
	} while(broj!=-1);

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int logi;
	std::cin>>logi;
	while(logi!=0 && logi!=1) {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>logi;
	}
	if(logi==true) {
		ispis=IzdvojiSimetricneTernarne(unos, logi);
		if(ispis.empty()==true) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		} else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			int vel=ispis.size();
			for(int i=0; i<vel; i++) {
				if(i!=vel-1) std::cout<<ispis.at(i)<<", ";
				else std::cout<<ispis.at(i)<<".";
			}
		}
	} else {
		ispis=IzdvojiSimetricneTernarne(unos, logi);
		if(ispis.empty()==true) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		} else {
			int vel=ispis.size();
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";

			for(int i=0; i<vel; i++) {
				if(i!=vel-1) std::cout<<ispis.at(i)<<", ";
				else std::cout<<ispis.at(i)<<".";
			}
		}
	}
	return 0;
}
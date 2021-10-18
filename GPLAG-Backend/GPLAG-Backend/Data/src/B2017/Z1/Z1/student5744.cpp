#include <iostream>
#include <cmath>
#include <vector>

bool DaLiJeProst (unsigned int a) {
	if (a<2) return false;
	for( int i=2; i<a; i++) {
		if (a%i==0) return false;
	}
	return true;
}

std::vector<long long int> TernarniOblik (std::vector<int> v) {
	long x;
	long i (1);
	long pozitivan;
	std::vector<long long int> vt;
	for (int j=0; j<v.size(); j++) {
		long long int ternarni (0);
		if (v.at(j)<0) pozitivan =-v.at(j);
		else pozitivan=v.at(j);
		i=1;
		while (pozitivan!=0) {
			x=pozitivan%3;
			pozitivan/=3;
			ternarni+=x*i;
			i*=10;
		}
		vt.push_back(ternarni);
	}
	return vt;
}


bool DaLiJeSimetrican (long long int a) {
	
	int n;
	n=a;
	int x (0);
	int y;
	while (a>0) {
		y=a%10;
		x=x*10+y;
		a/=10;
	}
	if (n==x) return true;
	else return false;
}

bool DaLiPostojiDupli (std::vector<int> v, int a) {
	for (int i=0; i<v.size(); i++) {
		if (v.at(i)==a) return true;
	}
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool t) {
	std::vector<int> novi_vektor;
	std::vector<int> v_ps;
	for (int i=0; i<v.size(); i++) {
		if(DaLiJeProst(v.at(i))==t) 
		v_ps.push_back (v.at(i));
	}
	std::vector<long long int> v_tern;
	v_tern=TernarniOblik(v_ps);
	for (int j=0; j<v_tern.size(); j++) {
		bool simetrican;
		simetrican = DaLiJeSimetrican(v_tern.at(j));
		if (simetrican==true && DaLiPostojiDupli(novi_vektor, v_ps.at(j))==false)
		novi_vektor.push_back (v_ps.at(j));
	}
	return novi_vektor;	
}


int main () {
	
	std::vector<int> v;
	std::vector<int> ymfc;
	int broj;
	bool p_ili_s;
	int unos_broja;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>broj;
		if (broj!=-1)
		v.push_back(broj);
	}
	while (broj!=-1);
	
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>unos_broja;
	while (unos_broja!=1 && unos_broja!=0) {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>unos_broja;
	}
	
	p_ili_s=unos_broja;
		
	
	
	ymfc=IzdvojiSimetricneTernarne(v, p_ili_s);
	
	if (ymfc.size() < 1) {
		std::cout<<"Nema ";
		if (p_ili_s!=1) std::cout<<"slozenih ";
		else std::cout<<"prostih ";
		std::cout<<"simetricnih brojeva u vektoru.";
	}
	
	else {
		if (p_ili_s==1) std::cout<<"Prosti ";
		else std::cout<<"Slozeni ";
	
		std::cout<<"simetricni brojevi iz vektora su: ";
	
		for (int i=0; i<ymfc.size(); i++) {
			if (i==( ymfc.size() - 1) ) 
				std::cout<<ymfc.at(i)<<"."; 
			else 
				std::cout<<ymfc.at(i)<<", ";
		}
	}
	return 0;
}
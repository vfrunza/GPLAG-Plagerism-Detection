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
typedef std::vector<int> Vektor;

bool Prost(int n) {
	if(n==0) return false;
	int r=sqrt(n);
	bool prost=1;
	for(int i=2;i<=r;i++) {
		if(n%i==0) {
			prost=false;
		    break;
	}
}
if(prost) return true;
else return false;
}

int Ternarni(int x) {
	int u=1;
	int unit;
	int ternarni=0;
	while(x!=0) {
		unit=x%3;
		ternarni=ternarni+unit*u;
		x/=3;
		u*=10;
	}
	return ternarni;
}

bool Simetrican(int t) {
	int n=t,priv,broj=0;
	do {
		priv=t%10;
		broj=broj*10+priv;
		t/=10;
	} while(t!=0);
	if(n==broj) return true;
	else return false;
}

Vektor IstiElementi(Vektor a) {
	int i;
	for(i=0;i<a.size();i++) {
		for(int j=i+1;j<a.size();j++) {
			if(a[i]==a[j]) {
				a.erase(a.begin()+j);
			}
		}
	}
	return a;
}

Vektor IzdvojiSimetricneTernarne(Vektor a,bool b) {
	if(b==true) {
		Vektor v3,v4;
		for(int i=0;i<a.size();i++) {
			if(Prost(a.at(i))==false) continue;
			else {
				if(Simetrican(Ternarni(a.at(i)))==false) continue;
				else {
					v3.push_back(a.at(i));
				}
			}
		}
		v4=IstiElementi(v3);
		return v4;
	}
	if(b==false) {
		Vektor v3,v4;
		for(int i=0;i<a.size();i++) {
			if(Prost(a.at(i))==true) continue;
			else {
				if(Simetrican(Ternarni(a.at(i)))==false) continue;
				else {
					v3.push_back(a.at(i));
				}
			}
		}
		v4=IstiElementi(v3);
		return v4;
	}
}
	

int main ()
{
	Vektor v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
		std::cin >> broj;
		if(broj==-1) break;
		if(broj!=-1) v.push_back(broj);
	} while(broj!=-1);
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int broj1;
	do {
	 std::cin >> broj1;
	 if(broj1!=1 && broj1!=0) {
	 	std::cout << "Neispravan unos!";
	 	std::cout << " Unesite ponovo: ";
	 }
	} while(broj1!=1 && broj1!=0);
	Vektor v1=IzdvojiSimetricneTernarne(v,bool(broj1));
	if(v1.size()==0 && broj1==1) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else if(v1.size()==0 && broj1==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	else if(v1.size()!=0 && broj1==1) {
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<v1.size();i++) {
			std::cout << v1.at(i);
			if(i!=v1.size()-1) std::cout << ", ";
			else std::cout << "." << std::endl;
		}
	}
		else if(v1.size()!=0 && broj1==0) {
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<v1.size();i++) {
			std::cout << v1.at(i);
			if(i!=v1.size()-1) std::cout << ", ";
			else std::cout << "." << std::endl;
		}
	}
	return 0;
}
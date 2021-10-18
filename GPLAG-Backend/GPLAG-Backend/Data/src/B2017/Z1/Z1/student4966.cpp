/*B 2017/2018, Zadaća 1, Zadatak 2
	
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
using std::cout;
using std::cin;
typedef std::vector<int> Vektor;
long long ObrniBroj (long long broj) {
	long long obrnut(0);
	while (broj) {
		int cifra(broj%10);
		obrnut=obrnut*10+cifra;
		broj/=10;
	}
	return obrnut;
}
bool DaLiJeProst(int n) {
	long long n2=n;
	if (n2<0) n2*=-1;
	if (n2<2) return false;
	for(int i=2;i<=std::sqrt(n2);i++) 
		if(n2%i==0) 
			return false;
	return true;
}
bool DaLiJeSimetrican (long long broj) {
	return (broj==ObrniBroj(broj));
}
long long PretvoriUTernarni (int broj) {
	long long ternarni(0);
	while (broj) {
		int cifra=broj%3;
		ternarni=ternarni*10+cifra;
		broj/=3;
	}
	return ObrniBroj(ternarni);
}
Vektor IzbaciSuvisne(Vektor v) {
	for (int i=0;i<v.size();i++) 
		for (int j=i+1;j<v.size();j++) 
			if (v.at(j)==v.at(i)) {
				v.erase(v.begin()+j);
				j--;
			}
	return v;
}
Vektor IzdvojiSimetricneTernarne(Vektor v, bool prosti) {
	Vektor povratniVektor;
	for (int broj : v) 
		if (DaLiJeProst(broj)==prosti && DaLiJeSimetrican(PretvoriUTernarni(broj)))
			povratniVektor.push_back(broj);
	povratniVektor=IzbaciSuvisne(povratniVektor);
	return povratniVektor;
}
int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	Vektor v;
	int broj, prost;
	do {
		cin>>broj;
		if (broj!=-1) v.push_back(broj);
	} while (broj!=-1);
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		cin>>prost;
		if (prost!=0 && prost!=1) cout<<"Neispravan unos! Unesite ponovo: ";
	} while(prost!=0 && prost!=1);
	Vektor v2=IzdvojiSimetricneTernarne(v, bool(prost));
	if (prost) {
		if (v2.size()==0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else cout<<"Prosti simetricni brojevi iz vektora su: ";
	}
	else {
		if (v2.size()==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	for (int i=0;i<v2.size();i++) {
		cout<<v2.at(i);
		if (i!=v2.size()-1) cout<<", ";
		else cout<<".";
	}
	return 0;
}
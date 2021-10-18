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

bool JeLiProst (int n) {
	for(int i=2;i<=std::sqrt(n);i++) {
		if (n%i==0) return false;
	}
	return true;
}

bool TernarnaSimetricnost (int n) {
	if (n<0) n*=-1;
	std::vector<int> ter_n(0);
	int m(0);
	do {
		m=n%3;
		ter_n.push_back(m);
		n/=3;
	} while (n!=0);
	//Imamo vector tj. ternarnu reprezentaciju. Sada ispitujemo simetricnost vektora:
	for(int i=0; i<ter_n.size(); i++) {
		if(ter_n.at(i)!=ter_n.at(ter_n.size()-1-i))
			return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool t_n) {
	std::vector<int> novi(0);
	for(int i=0;i<v.size();i++) {
		for(int j=i+1;j<v.size();j++) {
			if(v.at(i)==v.at(j)) {
				if(j==v.size()-1) {
					v.resize(v.size()-1);
					j--;
				}
			else
				for(int k=j;k<v.size()-1;k++) {
					v.at(k)=v.at(k+1);
					v.resize(v.size()-1);
					k--;
				}
			j--;
		}
	}
	}
	for(int i=0; i<v.size();i++)
		if (TernarnaSimetricnost(v.at(i)) && t_n==JeLiProst(v.at(i))) novi.push_back(v.at(i));
	return novi;
}

int main ()
{
	std::vector<int> v(0);
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int x;
	for(;;) {
		std::cin>>x;
		if(x==-1) break;
		v.push_back(x);
	}
	int t_n(0);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	for(;;) {
		std::cin>>t_n;
		if(t_n==1 || t_n==0) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	std::vector<int> novi(IzdvojiSimetricneTernarne(v,t_n));
	if (novi.size()==0) {
		if (t_n==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else if(t_n==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	else if (t_n==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else if (t_n==0) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i(0); i<novi.size();i++) {
		if(i==novi.size()-1) std::cout<<novi.at(i)<<".";
		else std::cout<<novi.at(i)<<", ";
	}
	
	
	return 0;
}


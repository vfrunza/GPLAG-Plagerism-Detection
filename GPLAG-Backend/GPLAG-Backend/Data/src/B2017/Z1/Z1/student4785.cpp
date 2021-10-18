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

bool ProstBroj(int a)
{
	if(a<0) a=-a;
	if(a<2) return false;
	for(int i=2; i<=sqrt(a); i++) {
		if(a%i==0) return false;
	}
	return true;
}

int Ternarni(int a)
{
	if(a<0) a=-a;
	int stepen(0),trn(0);
	while(pow(3,(stepen+1))<=a)
		stepen++;
	for(int i=stepen; i>=0; i--) {
		int b=int(a/pow(3,i));
		trn=trn*10+b;
		a-=b*pow(3,i);
	}
	return trn;
}

bool Simetrican(int a)
{
	int temp=a;
	if(temp<0) temp=-temp;
	int b(0);
	do {
		b=b*10+temp%10;
		temp/=10;
	} while(temp>0);
	if(b!=a)
		return false;
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool prost)
{
	std::vector<int> s;
	for(int i=0; i<v.size(); i++) {
		if(prost==ProstBroj(v.at(i)) && Simetrican((Ternarni(v.at(i)))))
			s.push_back(v.at(i));
	}
	for(int i=0; i<s.size(); i++) {
		for(int j=0; j<i; j++) {
			if(s.at(i)==s.at(j)) {
				s.erase(s.begin()+i);
				i--;
				break;
			}
		}
	}
	return s;
}

int main ()
{
	int broj;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>broj;
		if(broj!=-1) {
			v.push_back(broj);
		}
	} while(broj!=-1);
	bool prost(true);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int p;
	do {
		std::cin>>p;
		if(p!=0 && p!=1)
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		else
			prost=p;
	} while(p!=0 && p!=1);
	std::vector<int> b=IzdvojiSimetricneTernarne(v,prost);
	if(b.size()==0) {
		if(prost)
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	} else {
		if(prost) std::cout<<"Prosti ";
		else std::cout<<"Slozeni ";
		std::cout<<"simetricni brojevi iz vektora su: ";
		for(int i=0; i<b.size(); i++) {
			std::cout<<b.at(i);
			if(i!=b.size()-1) std::cout<<", ";
			else std::cout<<".";
		}
	}
	return 0;
}
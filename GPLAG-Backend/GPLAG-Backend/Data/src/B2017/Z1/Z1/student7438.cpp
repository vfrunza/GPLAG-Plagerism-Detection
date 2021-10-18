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
#include <cmath>
#include <vector>

int DaLiJeProst(int n)
{
	if(n==0) return -1;
	if(n<0) n*=-1;
	if(n<2) return 0;
	int T=1;
	for(int i=2; i<=(static_cast<int>(std::sqrt(n))); i++)
		if(n%i==0) {
			T=0;
			break;
		}
	if(T) return 1;
	else return -1;
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v,bool T)
{
	if(T) {
		for(int i=0; i<v.size(); i++) {
			if(DaLiJeProst(v.at(i))==1) continue;
			else {
				v.erase(v.begin() + i);
				i--;
			}
		}
	} else {
		for(int i=0; i<v.size(); i++) {
			if(DaLiJeProst(v.at(i))==-1) continue;
			else {
				v.erase(v.begin()+i);
				i--;
			}
		}
	}
	for(int i=0; i<v.size(); i++)
		for(int j=i; j<v.size(); j++)
			if(v.at(i)==v.at(j) && i!=j) {
				v.erase(v.begin()+j);
				j--;
			}

	int a,j(0),k;
	bool b(true);
	std::vector<int>temp;
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)<0) a=(-1)*v.at(i);
		else a=v.at(i);
		while(a>0) {
			temp.push_back(a%3);
			a/=3;
			j++;
		}
		for(k=0; k<j; k++)
			if(temp.at(k)!=temp.at(j-k-1)) {
				b=false;
				break;
			}
		for(k=0; k<j; k++) {
			temp.erase(temp.begin() + k);
			k--;
			j--;
		}
		j=0;
		if(b) continue;
		else  {
			v.erase(v.begin()+i);
			i--;
			b=true;
		}

	}
	return v;
}

int main ()
{
	std::vector<int> v;
	int x;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>x;
		if(x==-1) break;
		v.push_back(x);
	} while(true);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>x;
		if(x!=1 && x!=0) {
			while(x!=1 && x!=0) {
				std::cout<<"Neispravan unos! Unesite ponovo: ";
				std::cin>>x;
			}
		}
		break;
	} while(true);
	if(IzdvojiSimetricneTernarne(v,x).size()==0 && x==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else if(IzdvojiSimetricneTernarne(v,x).size()==0 && x==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(x) {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<IzdvojiSimetricneTernarne(v,x).size(); i++)
			if(i==IzdvojiSimetricneTernarne(v,x).size()-1)  std::cout<<IzdvojiSimetricneTernarne(v,x).at(i)<<".";
			else std::cout<<IzdvojiSimetricneTernarne(v,x).at(i)<<", ";
	} else {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<IzdvojiSimetricneTernarne(v,x).size(); i++)
			if(i==IzdvojiSimetricneTernarne(v,x).size()-1)  std::cout<<IzdvojiSimetricneTernarne(v,x).at(i)<<".";
			else std::cout<<IzdvojiSimetricneTernarne(v,x).at(i)<<", ";
	}
	return 0;
}
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

int Ternarni (int broj) {
	
	int ternarnibroj=0,i=0;

	while(broj!=0) {
		
		ternarnibroj=ternarnibroj+(broj%3)*pow(10,i);
		broj/=3;
		i++;
		
	}
	return ternarnibroj;
	
}


bool Prost(int broj) {

if(broj==0) return false;

if(broj<0)broj*=-1;

for(int i=2;i<=sqrt(broj);i++) {
	
	if(broj%i==0)return false;
}

return true;
}

bool Simetrican(int broj) {
	
	broj=Ternarni(broj);
	std::vector<int> vektor;
	while(broj!=0) {
		vektor.push_back(broj%10);
		broj/=10;
	}
	
	for(int i=0;i<vektor.size();i++) {
		
		if(vektor.at(i)!=vektor[vektor.size()-i-1])
		return false;
	}
	
	return true;
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>vektor,bool tacno) {

std::vector<int> pomocni;

if(tacno==true) {
	
	for(int i=0;i<vektor.size();i++) {
		
		if(Prost(vektor.at(i))&&Simetrican(vektor.at(i))&&vektor.at(i)!=1) {
				
				pomocni.push_back(vektor.at(i));
				
			}
	}
}

if(tacno==false) {
	
	for(int i=0;i<vektor.size();i++) {
		
			
			if(!Prost(vektor.at(i))&&Simetrican(vektor.at(i))&&vektor.at(i)!=1) {
				
				pomocni.push_back(vektor.at(i));
				
			}
	}
}


	for(int i=0;i<pomocni.size();i++) {
		
		for(int j=0;j<pomocni.size();j++) {
			if(pomocni.at(i)==pomocni.at(j) && i!=j){
			pomocni.erase(pomocni.begin()+j);
			j--;
			}
		}

	}


return pomocni;
}

int main ()
{
	int a;
	std::vector<int>vektor;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>a;
		if(a!=-1) vektor.push_back(a);
	}
	while(a!=-1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
std::cin>>a; 
while (a!=1 && a!=0) {std::cout<<"Neispravan unos! Unesite ponovo: ";std::cin>>a;}


if(a==1) {vektor=IzdvojiSimetricneTernarne(vektor,true);}
if(a==0){vektor=IzdvojiSimetricneTernarne(vektor,false);}
	
	
	if(a==1) {
			if(vektor.size()==0) {std::cout<<"Nema prostih simetricnih brojeva u vektoru."; return 0;}
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	}
	
	if(a==0) {
			if(vektor.size()==0) {std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; return 0;}
	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	
	
	for(int i=0;i<vektor.size();i++) {
		std::cout<<vektor[i];
		if(i==vektor.size()-1) std::cout<<".";
		else std::cout<<", ";
	}
	
	return 0;
}
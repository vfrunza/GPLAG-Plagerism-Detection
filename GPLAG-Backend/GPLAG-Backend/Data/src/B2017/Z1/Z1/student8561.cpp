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
#include <iomanip>
#include <cmath>
typedef std::vector<int> vektor;

bool IfProst(int n){
	int i, br(0);
	if(n==0 || n==1) return 0;
	if(n>1){for(i=2;i<n;i++) if(n%i==0) br++;}
	if(n<0) return 0;
	if(br==0) return 1;
	return 0;
}

int ternarni(int n){
	int br(0),i=1;
	if(n<0) n=abs(n);
	int ost(0);
	do{
		ost=n%3;
		n=n/3;
		br=br+ost+pow(10,i);
		i++;
	}while(n!=0);
	return br/10;
}

int IfSimetrican(int n){
	int br1(n),br2(0);
	do{
		br2=(br1%10)+br2*10;
		br1=br1/10;
	}while(br1!=0);
	if(n==br2) return 1;
	return 0;
}


vektor IzdvojiSimetricneTernarne(vektor v,bool tn){
	vektor a;
	for(int i=0;i<v.size();i++){
		if(IfProst(v.at(i))==!tn) {v.erase(v.begin()+i); i--;}
	}
	for(int i=0;i<v.size();i++){
		a.resize(i+1);
		a.push_back(ternarni(v.at(i)));
	}
	for(int i=0;i<a.size();i++){
		if(IfSimetrican(a.at(i))==0)
			a.erase(a.begin()+i);
			a.resize(a.size()-1);
		}
		 return a;
	
}


int main ()
{
	vektor v,a;
	int broj,tn;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
			std::cin>>broj;
			v.push_back(broj);
		
	}while(broj!=-1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{
		std::cin>>tn;
		if(tn>1 || tn<0)
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			
		}while(tn>1 || tn<0);
	
	a=IzdvojiSimetricneTernarne(a,tn);
	
	if(a.size()==0) { 
		if(tn==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru."; 
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; 
		return 0;
	}
	if(tn==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0;i<a.size();i++){
		if(i<a.size()-1) std::cout<<a.at(i)<<",";
		std::cout<<a.at(i)<<".";
	}
	
	
	return 0;
}
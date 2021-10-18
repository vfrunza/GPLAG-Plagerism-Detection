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


bool DaLiJeProst(int n, bool a)
{
	if(n==1){
		if(a)
			return false;
			else return true;
			
	}


	if(n<0) n*=(-1);
	for(int i = 2; i<=sqrt(n); i++){
		if(n%i==0){
			if(a)
			return false;
			else  return true;
			
			
		}
	}
	if(a)
		return false;
		else
		return true;
}

unsigned long long int Obrni(unsigned long long int n){
	unsigned long long int novi_broj(0);
	unsigned long long int temp(n);
	int brojac(0);
	
	do{temp/=10;
	brojac ++;
	}
	while (temp!=0);
	
	for(; brojac!=0;brojac--){
		novi_broj+=n%10*(unsigned long long int)(pow(10, brojac-1));
		n/=10;
	}
	return novi_broj;
		
	
}
bool Simetrican(int n){
	unsigned long long int b(0);
	if(n<0) n*=-1;
	for (int i = 0; n!= 0; i++) {
		b+=(n%3)*(unsigned long long)(pow(10,i));
	n/=3;
	
	}
	unsigned long long int obrni_broj=Obrni(b);
	
	if(obrni_broj==b)
	return false;
	return true;
	
	
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>vektor, bool pamti)
{
	std::vector<int>novi_vektor;
	for (int i = 0; i < vektor.size(); i++) {
		if(DaLiJeProst(vektor.at(i), pamti) && Simetrican(vektor.at(i))){
		int j(0);
		for ( j = 0; j < novi_vektor.size(); j++) {
			if(vektor.at(i)==novi_vektor.at(j))
				break;
			}
			if( j==novi_vektor.size())
			novi_vektor.push_back(vektor.at(i));
			
		}
		
	}
	return novi_vektor;
}


int main ()
{
	std::vector<int>vektor;
	int b;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	do{
		std::cin>>b;
	if(!std::cin){ 
		std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	else{  if(b==-1)
			break;
			vektor.push_back(b);
	}
	}
	while (1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{ std::cin>>b;
	
	if(!std::cin || (b!=0 && b!=1)){
	if(!std::cin){ 
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	else 
	break;
}while(1);
	std::vector<int>novi_vektor=IzdvojiSimetricneTernarne(vektor, b);
	if(b==1){
		if(!novi_vektor.size()){
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
			
		}else
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			
	}else {
		if(!novi_vektor.size()){
			
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		} else 
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
		for (int i = 0; i < novi_vektor.size(); i++) {
			if(i==novi_vektor.size()-1)
				std::cout<<novi_vektor.at(i)<<".";
				else
				std::cout<<novi_vektor.at(i)<<", ";
		}
		
	
	return 0;
}
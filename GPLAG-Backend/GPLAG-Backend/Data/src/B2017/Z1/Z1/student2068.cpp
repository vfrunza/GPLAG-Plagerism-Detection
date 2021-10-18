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
bool Ponovljeni(std::vector<int> v,int a){
	for(int i=0;i<v.size();i++){
		if(v.at(i)==a)
		return false;
	}
	return true;
}
bool PretvoriUTernarne(int n){
	std::vector<int> cifre;
	if(n<1)
		n=n*(-1);
	while(n!=0){
		cifre.push_back(n%3);
		n=n/3;
	}
	for(int i=0;i<cifre.size()/2;i++){
		if(cifre.at(i)!=cifre.at(cifre.size()-i-1))
			return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a) {
	std::vector<int> unos;
	
	if(a==true){
	for(int i=0;i<v.size();i++){
		bool b(true);
		int j;
		int pom=abs(v.at(i));
		for(j=2;j<abs(v.at(i));j++){
		    if(pom%j==0){
		    	b=false;
				break;
			}	
		}			
		if(b==true){
			if(PretvoriUTernarne(v.at(i))==true){
			    if(Ponovljeni(unos,v.at(i)))
			    unos.push_back(v.at(i));
			}
		}
	}
	return unos;	
	}
	else if(a==false){
	for(int i=0;i<v.size();i++){
		int pom=abs(v.at(i));
		int j;
		for(j=2;j<abs(v.at(i));j++){
			if(pom%j==0){
			    if(PretvoriUTernarne(v.at(i))==true){
					unos.push_back(v.at(i));
					break;
			    }
			}
		}
	}
	return unos;
	}
	return unos;
}


int main ()
{
	int v;
	std::vector<int> brojevi;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		std::cin>>v;
		if(v!=-1)
		brojevi.push_back(v);
	}while(v!=-1);
	int n;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{
		std::cin>>n;
		if(n!=0 && n!=1)
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(n!=0 && n!=1);
	
	std::vector<int> Vektor_brojeva(IzdvojiSimetricneTernarne(brojevi,n));
	if(Vektor_brojeva.size()==0&&n==1){
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(Vektor_brojeva.size()==0&&n==0){
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(n==1){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<Vektor_brojeva.size();i++){
			std::cout<<Vektor_brojeva.at(i);
		if(i<Vektor_brojeva.size()-1)
			std::cout<<", ";
		else 
			std::cout<<".";
		}
	}		
	if(n==0){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<Vektor_brojeva.size();i++){
			std::cout<<Vektor_brojeva.at(i);
		if(i<Vektor_brojeva.size()-1)
			std::cout<<", ";
		else 
			std::cout<<".";
		}
	}
	
	return 0;
}
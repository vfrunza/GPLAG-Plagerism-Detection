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

bool DaLiJeProst(int a){
	if(a<0) a=a*(-1);
	if(a==1) return false;
	for(int i=2; (unsigned int)(i*i)<=a; i++){
		if(a%i==0) return false;
	}
	return true;
}

int PretvoriUTernarne(int a){
	int b=0;
	if(a<0) a=a*(-1);
	while(a!=0){
	b=b*10+a%3;
	a=a/3;
}

	return b;
}

int Naopak(int a){
	int b=0;
	while(a!=0){
		b=b*10+a%10;
		a=a/10;
	}
	return b;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, int b){
	std::vector<int> novi;
	if(b==1){
		for(int i=0; i<a.size(); i++){
			if(DaLiJeProst(a.at(i))){
				int c=PretvoriUTernarne(a.at(i));
				if(Naopak(c)==c) novi.push_back(a.at(i));
			}
			
		}
		return novi;
	}
	
	else if(b==0){
		for(int i=0; i<a.size(); i++){
			if(!DaLiJeProst(a.at(i))){
				int d=PretvoriUTernarne(a.at(i));
				if(Naopak(d)==d) novi.push_back(a.at(i));
			}
		}
		return novi;
	}
	
	}

int main ()
{
	int b;
	std::vector<int> a;
	std::vector<int> c;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(1){
		int unos;
		std::cin>>unos;
		if(unos==-1) break;
		else a.push_back(unos);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{
		std::cin>>b;
		if(b!=0 && b!=1){
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
		
	}while(b!=0 && b!=1);
	
	c=IzdvojiSimetricneTernarne(a,b);
	if(b==0 && c.size()!=0){
	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(unsigned int i=0; i<c.size(); i++){
		if(i==c.size()-1) std::cout<<c.at(i)<<"."<<std::endl;
		else std::cout<<c.at(i)<<", ";
	}
	}
	else if(b==1 && c.size()!=0){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(unsigned int i=0; i<c.size(); i++){
		if(i==c.size()-1) std::cout<<c.at(i)<<"."<<std::endl;
		else std::cout<<c.at(i)<<", ";
	}
	}
	
	else if(c.size()==0){
		if(b==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		if(b==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	
	
	return 0;
}
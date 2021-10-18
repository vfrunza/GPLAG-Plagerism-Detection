#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int n) {
	
	if(n<0)n=-n;
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0) return false;
	}
	return true;
}

bool Simetrican (int n) {
	
    std::vector<int>v;

	while (n!=0) {
		int c=n%10;
		v.push_back(c);
		n=n/10;
	}
	int vel=v.size();
	for(int i=0;i<=vel/2;i++){
		if(v.at(i)!=v.at(vel-1-i))return false;
	}
	return true;
}

int PretvoriUTernarni (int m) {
	int n=m;
	int x=0,ostatak=0,b=0;
	if(n<0){
		n=-n;
		b=1;
	} 
	
int i=0;
	while (n!=0) {
		ostatak=n%3;
		x=x+ostatak*pow(10,i);
		n=n/3;
		i++;
	} 
	
	
/*	if(Simetrican(x)){
		if(b==1) {
			x=-x;
		return x;
		}
	}*/
	
	if(b==1)x=-x;
	return x;
	
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> a, bool b) {
	
	std::vector<int> v;
	
/*	for(int i=0; i<a.size(); i++) {
		if(DaLiJeProst(a.at(i)))v.push_back(a.at(i));
	}*/
	
	for(int i=0;i<a.size();i++){
		if(b==true)
		if(DaLiJeProst(a.at(i)) && Simetrican(PretvoriUTernarni(a.at(i)))) v.push_back(a.at(i));
		if(b==false) if(DaLiJeProst(a.at(i))==0 && Simetrican(PretvoriUTernarni(a.at(i)))) v.push_back(a.at(i));
	}
	
/*	int vel=v.size();
	std::vector<int> v1;
	
	for(int i=0;i<vel;i++){
		int x;
		x=PretvoriUTernarni(v.at(i));
		v1.push_back(x);
	}*/
	
	return v;
}
	
	
int main ()
{ 
	int broj;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	do {
		std::cin>>broj;
		if(broj!=-1) v.push_back(broj);
		else break;
	}   while(broj!=-1);
	
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int ps;//ps-prosti_slozeni
	while(1){
		std::cin>>ps;
		if(ps!=0 && ps!=1)std::cout<<"Neispravan unos! Unesite ponovo: ";
		else break;
	}
	
	std::vector<int> neki_vektor;
	
	neki_vektor=IzdvojiSimetricneTernarne(v,ps);
	
	if(ps==1) {
		if(neki_vektor.size()==0){
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	} else
	  std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	  
	 for(int i=0;i<neki_vektor.size();i++){
	 	if(i==neki_vektor.size()-1) std::cout<<neki_vektor.at(i)<<".";
		else std::cout<<neki_vektor.at(i)<<", ";
		
	}
	}
	else if(ps==0) {
		if(neki_vektor.size()==0) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		} else 
		  std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		  for(int i=0; i<neki_vektor.size(); i++) {
		  	if( i== neki_vektor.size()-1) std::cout<<neki_vektor.at(i)<<".";
		  	else std::cout<<neki_vektor.at(i)<<", ";
		  }
	
	}
	
	return 0;
}
#include<vector>
#include <iostream>
#include<cmath>
#include<iomanip>

bool Prost(int n)
{
	if(n<0) n=-n;
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0) return false;
	}
	return true;
}


int TernarniBrojevi(int n){
	int k(0),suma(0);
	int a;
	while(n!=0){
		a=n%3;
		n/=3;
		suma+=a*(pow(10,k));
		k++;
	}
	return suma;
}

int Simetricni(int broj){
 	int brojac(0);
 	int temp(broj);
 	while(temp!=0){
 		temp/=10;
 		brojac++;
 	}
 	int suma(0);
 	int a;
 	while(broj!=0){
 		a=broj%10;
 		broj/=10;
 		suma+=a*(pow(10,brojac));
 		brojac--;
 	}
 	return suma/10;
 }
 

 
 std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, bool JeProst){
 	
 	std::vector<int>c;
 	
 	for(int i=0;i<a.size();i++){
 		
 		if((JeProst)==(Prost(a.at(i)))){
 			 
 			 int broj1=TernarniBrojevi(a.at(i));
 			int broj2=Simetricni(broj1);
 			if(broj1==broj2)  c.push_back(a.at(i));
 			 }
 		}
 	
 	return c;
 }
 
int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj(0);
	std::vector<int>v,z;
	while(broj!=-1){
		std::cin>>broj;
        v.push_back(broj);
	}
	v.resize(v.size()-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int n;
	std::cin>>n;
	while((n!=0) && (n!=1)){
	
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>n;
	}
	z=IzdvojiSimetricneTernarne(v,n);
	if(n) {
		
		if(z.size()==0){
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
		}
		else {
		 std::cout<<"Prosti simetricni brojevi iz vektora su:"; 
		 for(int i=0;i<z.size();i++){
		 	if(i==z.size()-1) std::cout<<" "<<z.at(i)<<".";
		 	else std::cout<<" "<<z.at(i)<<",";
		 }
		 }
	}
	
	else {
		
		if(z.size()==0){
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
		}
		else {
		 std::cout<<"Slozeni simetricni brojevi iz vektora su:"; 
		 for(int i=0;i<z.size();i++){
		 	if(i==z.size()-1) std::cout<<" "<<z.at(i)<<".";
		 	else std::cout<<" "<<z.at(i)<<",";
		 }
		 }
	}
	
	
	return 0;
}
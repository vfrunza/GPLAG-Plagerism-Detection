
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int n){
	for (int i=2;(unsigned int)(i*i)<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v1, bool a ){
	std::vector<unsigned long long int> stepenitrice;
	std::vector<int> prosti;
	std::vector<int> slozeni;
	int indeks;
	for(int i=0;i<100;i++){
		stepenitrice.push_back(std::pow(3,i));
	}
	for(int x: v1){
		if(x=-1)break;
		
		unsigned long int suma(0),pomocna(0),pomocna2,pomocna3,y;
		y=(abs)(x);
		for(int i=0;i<100;i++){
			if(y>stepenitrice.at(i)){
				indeks=i;
			}
		}
		for(int j=indeks;j>=0;j--){
			suma=suma+(y/stepenitrice.at(j))*std::pow(10,j);
			pomocna=y/stepenitrice.at(j);
			y=y-(pomocna*stepenitrice.at(j));
		}
		pomocna2=suma;
		for(int i=indeks;i>=0;i--){
			pomocna3+=(suma%10)*pow(10,i);
			suma=suma/10;}
			
		if(DaLiJeProst((abs)(x))){if(pomocna2==pomocna3){
			prosti.push_back(x);
		}	}
		else{if(pomocna2==pomocna3){
			slozeni.push_back(x);}
		}
}
if(a){
	return prosti;
}
else return slozeni;
}
int main (){
	int n;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> brojevi;
	
	for(;;){
	std::cin>>n;
	if n=-1 break;
	brojevi.push_back(n);}
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int m;
	std::cin>>m;
	std::vector<int> kraj (IzdvojiSimetricneTernarne(brojevi,m));
	
	if(m){
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(int x : kraj){
		std::cout<<x<<" ";}}
	else{
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int x : kraj){
		std::cout<<x<<" ";}}
		
	return 0;
}
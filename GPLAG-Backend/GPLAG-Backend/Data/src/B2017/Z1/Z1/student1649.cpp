#include <iostream>
#include <cmath>
#include <vector>

typedef std::vector<int> IntVektor;

bool Simetrican(int n){
	IntVektor cifre;
	n = std::fabs(n);
	while(n != 0){
		cifre.push_back(n % 10);
		n /= 10;
	}
	int i = cifre.size()-1;
	int j(0);
	while(j <= i){
		if(cifre.at(i) != cifre.at(j)) return false;
		else j++; i--;
	}
	return true;
}

long long int Ternarni(int n){
	IntVektor vektor;
	n = std::fabs(n);
	int i(0);
	while(n != 0){
		vektor.push_back(n % 3);
		n/=3;
		i++;
	}
    long long int broj = 0;
	for(int i = vektor.size()-1; i >= 0; i--){
		broj += vektor.at(i) * std::pow(10,i);
	}
	return broj;
}

bool Prost(int n){
	if(n == 0) return false;
	n = std::fabs(n);
	for(int i = 2; i <= std::sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

IntVektor IzdvojiSimetricneTernarne(IntVektor vektor, bool prost){
	IntVektor novivektorp, novivektors, novip, novis;
	
	for(int i = 0; i < vektor.size(); i++){
		if(vektor.at(i) == 1) continue;
		else if(Prost(vektor.at(i))) novivektorp.push_back(vektor.at(i));
		else novivektors.push_back(vektor.at(i));
	}
		long long int novi1;
			for(int i = 0; i < novivektorp.size(); i++){
				novi1 = Ternarni(novivektorp.at(i));
				if(Simetrican(novi1)) novip.push_back(novivektorp.at(i));
			}	
		long long int novi2;
			for(int i = 0; i<novivektors.size(); i++){
				novi2 = Ternarni(novivektors.at(i));
				if(Simetrican(novi2)) novis.push_back(novivektors.at(i));
			}
				if(prost) return novip;
				else return novis;
	
		}

int main (){
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	IntVektor vektor;
	int broj;
	for(;;){
		std::cin>>broj;
		if(broj == -1) break;
		vektor.push_back(broj);
	}
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int test;
	greska:
	std::cin>>test;
	if(test != 1 && test != 0){
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			goto greska;
		}
	if(test) {
		IntVektor novi(IzdvojiSimetricneTernarne(vektor,true));
		if(novi.size() == 0){
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		} 
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i = 0; i < novi.size(); i++){
			if(i < novi.size()-1) std::cout<<novi.at(i)<<", ";
			else std::cout<<novi.at(i)<<".";
		}
	}
	else{
		IntVektor novi(IzdvojiSimetricneTernarne(vektor,false));
		if(novi.size() == 0){
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i = 0; i <novi.size(); i++){
			if(i < novi.size()-1) std::cout<<novi.at(i)<<", ";
			else std::cout<<novi.at(i)<<".";
		}
	}
	return 0;
}
/B2017/2018: ZSR 4, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>


//////////////////////////

bool DaLiJeProst(int broj){
	if(broj<0) broj*=-1;
	if(broj<2){
		return false;
	}
	for(int i = 2; i <= sqrt(broj); i++){
		if(broj % i == 0){
			return false;
		}
	
	}
	return true;
}

int DaLiJeTernarni(int broj)
{
	unsigned long long int ternarni=0;
	while (broj!=0)
	{
		ternarni=ternarni*10+broj%3;
		broj/=3;
	}
	unsigned long long int obrnuti=0, broj1=ternarni;
	while(broj1!=0)
	{
		obrnuti=obrnuti*10+broj1%10;
		broj1/=10;
	}
	
	return obrnuti;
}

bool palindrom(int poslani_broj)
{
	if(poslani_broj<0) poslani_broj*=-1;
	unsigned long long int obrnuti=0, broj=poslani_broj;
	while(broj!=0)
	{
		obrnuti=obrnuti*10+broj%10;
		broj/=10;
	}
	if(poslani_broj==obrnuti)
		return true;
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, int prost_slozen)
{
	std::vector<int> novi;
	for(int i=0; i<v.size(); i++)
	{
		if(prost_slozen==true)
			if(DaLiJeProst(v[i])==true && palindrom(DaLiJeTernarni(v[i]))==true)
				novi.push_back(v[i]);
		if(prost_slozen==false)
			if(DaLiJeProst(v[i])==false && palindrom(DaLiJeTernarni(v[i]))==true)
				novi.push_back(v[i]);
	}
	return novi;
}


int main ()
{
	int element;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): " ;
	for(;;){
		std::cin>>element;
		if(element!= -1) v.push_back(element);
		else break;
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prostilislozen;
	for(;;){
		std::cin>>prostilislozen;
		if(prostilislozen==0 || prostilislozen == 1) break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	bool x(prostilislozen);
	int brojac(0);
	std::vector<int>vektor(IzdvojiSimetricneTernarne(v,x));
	if(x == 1 && vektor.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(x == 0 && vektor.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else if( x == 1){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(auto y: vektor){
			std::cout<<y;
			brojac++;
			if(brojac == vektor.size()) std::cout<<".";
			else std::cout<<", ";
		}
	}
	else{
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(auto y: vektor){
			std::cout<< y;
			brojac++;
			if(brojac == vektor.size()) std::cout<<".";
			else std::cout<<", ";
		}
	}
	return 0;
	
		
}





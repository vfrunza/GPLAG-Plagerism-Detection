#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> Vektor;
Vektor PretvoriUTernarni(Vektor v1)
{
	Vektor v2;
	int broj;
	for(int i=0; i<v1.size(); i++) {
		int brojac=0;
		int ternarni=0;
		while(v1.at(i)!=0) {
			broj=v1.at(i)%3;
			v1.at(i)=v1.at(i)/3;
			brojac++;
			ternarni+=broj*pow(10,brojac-1);
		}
		v2.push_back(ternarni);
	}
	return v2;
}
Vektor ObratnoBroj(Vektor v1)
{
	Vektor v2;
	for(int i=0; i<v1.size(); i++) {
		int obratnobroj=0;
		int brojac=0;
		int kopijabroja=v1.at(i);
		while(kopijabroja!=0) {
			kopijabroja=kopijabroja/10;
			brojac++;
		}
		brojac--;
		while(v1.at(i)!=0) {
			int broj=v1.at(i)%10;
			obratnobroj+=broj*pow(10,brojac);
			brojac--;
			v1.at(i)=v1.at(i)/10;
		}
		v2.push_back(obratnobroj);
	}
	return v2;
}
Vektor ProvjeriSimetricne(Vektor v1, Vektor v2)
{
	Vektor v3;
	for(int i=0; i<v1.size(); i++) {
		for(int j=0; j<v2.size(); j++) {
			if(v1.at(i)==v2.at(j)) {
				v3.push_back(v1.at(i));
			}
		}
	}
	return v3;
}
Vektor ObrniIzTernarnog(Vektor v1)
{
	Vektor v2;
	for(int i=0; i<v1.size(); i++) {
		int temp=v1.at(i);
		int brojac=-1;
		while(v1.at(i)!=0) {
			v1.at(i)=v1.at(i)/10;
			brojac++;
		}
		int ternarni=0;
		while(brojac>=0) {
			int ostatak=temp%10;
			ternarni=ternarni+ostatak*pow(3,brojac);
			temp=temp/10;
			brojac--;
		}
		v2.push_back(ternarni);
	}
	return v2;
}
bool Prost(int broj)
{
	bool dalijeprost=true;
	if(broj==0) dalijeprost=false;
	for(int i=2; (unsigned int) (i*i)<=broj; i++) {
		if(broj%i==0)
			dalijeprost=false;
	}
	return dalijeprost;
}
Vektor IzdvojiSimetricneTernarne(Vektor v1, bool broj)
{
	Vektor v2=PretvoriUTernarni(v1);
	Vektor v3=ObratnoBroj(v2);
	Vektor v4=ProvjeriSimetricne(v2,v3);
	Vektor v5=ObrniIzTernarnog(v4);
	Vektor v6,v7;
	for(int i=0; i<v5.size(); i++) {
		if(v5.at(i)!=1 && v5.at(i)!=-1) {
			if(Prost(v5.at(i))==true) {
				v6.push_back(v5.at(i));
			} else {
				v7.push_back(v5.at(i));
			}
		}
	}
	if(broj==true) {
		return v6;
	} else {
		return v7;
	}
}
int main()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	Vektor v1,v2,v3;
	int a;
	for(int i=0; ; i++) {
		std::cin>>a;
		if(a==-1) break;
		v1.push_back(a);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int b;
	std::cin>>b;
	while(b!=0 && b!=1) {
		std::cout<<"Neispravan unos! ";
		std::cout<<"Unesite ponovo: ";
		std::cin>>b;
	}
	if(b==1) {
		v2=IzdvojiSimetricneTernarne(v1, true);
		if(v2.size()!=0) {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<v2.size(); i++) {
				if(i<v2.size()-1) {
					std::cout<<v2.at(i)<<", ";
				} else {
					std::cout<<v2.at(i)<<".";
				}
			}
		} else {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		}
	}
	if(b==0) {
		v3=IzdvojiSimetricneTernarne(v1, false);
		if(v3.size()!=0) {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<v3.size(); i++) {
				if(i<v3.size()-1) {
					std::cout<<v3.at(i)<<", ";
				} else {
					std::cout<<v3.at(i)<<".";
				}
			}
		}  else {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		}
	}
	return 0;
}
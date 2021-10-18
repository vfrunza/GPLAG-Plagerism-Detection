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
bool Prost(int a){
	if(a<=1)
	return false;
	for(int i=2;i<a;i++){
		if(a%i==0)
		return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, int a){
	if (a==1){
		std::vector<int> v_prostih;
		int brojac=0;
		for(int i=0;i<v.size();i++){
			int broj=v.at(i);
			if(Prost(broj)){
				int suma=0	;
				int broj2(broj);/*Dobijanje broja u ternarnom obliku*/
				while(broj2>0){
					brojac=0;
					int broj1(broj2);
					while(broj1>0){
						broj1=broj1/3;
						brojac++;
					}
					for(int i=0;i<=2;i++){
						if(broj2-i*pow(3,brojac-1)<pow(3,brojac-1) && broj2-i*pow(3,brojac-1)>=0){
							suma+=i*pow(10,brojac-1);
							broj2=broj2-i*pow(3,brojac-1);
						}
					}
				}								/*Provjera simetricnosti*/
				std::vector<int> v1,v2;
				int suma1(suma),cifra=0;
				while(suma1!=0){
					cifra=suma1%10;
					suma1=suma1/10;
					v1.push_back(cifra);
				}
				v2=v1;
				int tacnost;
				for(int i=0;i<v1.size();i++){
					if(v1.at(i)!=v2.at(v1.size()-1-i)){
					tacnost=0;
					break;}
					else
					tacnost=1;
				}
				if(tacnost==1)
				v_prostih.push_back(broj);
				
			}
		}
		return v_prostih;
	}
	if(a==0){
		
		std::vector<int> v_prostih;
		int brojac=0;
		for(int i=0;i<v.size();i++){
			int broj=v.at(i);
			if(!(Prost(broj))){
				int suma=0	;
				int broj2(broj);/*Dobijanje broja u ternarnom obliku*/
				while(broj2>0){
					brojac=0;
					int broj1(broj2);
					while(broj1>0){
						broj1=broj1/3;
						brojac++;
					}
					for(int i=0;i<=2;i++){
						if(broj2-i*pow(3,brojac-1)<pow(3,brojac-1) && broj2-i*pow(3,brojac-1)>=0){
							suma+=i*pow(10,brojac-1);
							broj2=broj2-i*pow(3,brojac-1);
						}
					}
				}								/*Provjera simetricnosti*/
				std::vector<int> v1,v2;
				int suma1(suma),cifra=0;
				while(suma1!=0){
					cifra=suma1%10;
					suma1=suma1/10;
					v1.push_back(cifra);
				}
				v2=v1;
				int tacnost;
				for(int i=0;i<v1.size();i++){
					if(v1.at(i)!=v2.at(v1.size()-1-i)){
					tacnost=0;
					break;}
					else
					tacnost=1;
				}
				if(tacnost==1)
				v_prostih.push_back(broj);
				
			}
		}
		return v_prostih;
	}
}

int main ()
{
	std::vector<int> v,v1;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		int i;
		std::cin>>i;
		if(i==-1)
		break;
		v.push_back(i);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;
	for(;;){
	std::cin>>a;
	
		if(a==0 || a==1)
		break;
		else
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	v1=IzdvojiSimetricneTernarne(v,a);
	if(v1.size()==0 && a==0){
	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	else if(v1.size()==0 && a==1)
	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else{
	if(a==1)
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	if(a==0)
	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; i<v1.size();i++){
		if(i!=v1.size()-1)
		std::cout<<v1.at(i)<<", ";
		else
		std::cout<<v1.at(i)<<".";
	}
		
	}
	return 0;
}
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

bool Simetricna(int y){
	int cifra(0);
	while(y!=0){
		cifra=cifra*10+y%3;
		y/=3;
	}
	if(y%2==0) cifra*=10;
	int broj=cifra;
	int naopako(0);
	while(cifra!=0){
		naopako=naopako*10+cifra%10;
		cifra/=10;
	}
	if(broj==naopako) return 1;
	return 0;
	
}
bool Slozen(int n){
	for(int j=2;j<=std::sqrt(n);j++){
				if(n%j==0)
					return 1;
	}
	return 0;
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v , bool x){
	std::vector<int>c;
	
	for(int i=0;i<v.size();i++){
		bool slozen(Slozen(v.at(i)));
		if(slozen==1 && x==false){
			if(Simetricna(v.at(i)))
			c.push_back(v.at(i));
		}
		else if(slozen==0 && x==true){
			if(Simetricna(v.at(i)))
			c.push_back(v.at(i));
		}
	}
	return c;
}

int main ()
{
	std::vector<int> v;
	int broj;
	int x;
/*	std::vector<int> b;
	b=IzdvojiSimetricneTernarne(v,true);
	for(int i=0;i<b.size();i++){
		std::cout<<b.at(i)<<" ";
	}*/
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
	std::cin>>broj;
	if(broj==-1)break;
	v.push_back(broj);
	}while(broj!=-1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";

	do{
		std::cin>>x;
		if(x!=0 && x!=1)
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(x!=0 && x!=1);
	
	
	
	std::vector<int> a(IzdvojiSimetricneTernarne(v,x));
	
	if(a.size()==0 && x==true)
	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(a.size()==0 && x==false)
	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else if(a.size()!=0 && x==true){
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<a.size();i++){
		if(i==a.size()-1)
		std::cout<<a.at(i)<<".";
		else
		std::cout<<a.at(i)<<", ";
	}
	}
	else if(a.size()!=0 && x==false){
	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	
		for(int i=0;i<a.size();i++){
		if(i==a.size()-1)
		std::cout<<a.at(i)<<".";
		else
		std::cout<<a.at(i)<<", ";
	}
	}
	return 0;

}
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

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>brojevi,bool a){
	std::vector<int> vektor;
	int velicina(brojevi.size());
	
	for(int i=0;i<velicina;i++){
		int brojac(0),temp;
		if(brojevi.at(i)<0) temp=brojevi.at(i)*(-1);
		else temp=brojevi.at(i);
		
		for(int j=2;j<temp;j++){
			if(temp%j==0) brojac++;
		}
		if(brojac==0 && a!=true) continue;
		if(brojac!=0 && a!=false) continue;
		
		long long int pretvoreni(0);
		int cifra;
		
		if(brojevi.at(i)<0) temp=brojevi.at(i)*(-1);
		else temp=brojevi.at(i);
		
		do	{
			cifra=temp%3;
			temp=temp/3;
			pretvoreni=pretvoreni*10+cifra;
		}while(temp>0);
		
	
		long long int obrnut(0);
		temp=pretvoreni;
		
		do{
			cifra=temp%10;
			temp=temp/10;
			obrnut=obrnut*10+cifra;
		}while(temp>0);
		
	
		if(obrnut==pretvoreni) vektor.push_back(brojevi.at(i));
	}
	return vektor;
}
	


int main ()
{
	std::vector<int> vektor;
	int a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		std::cin>>a;
		if(a!=-1) vektor.push_back(a);
		else break;
	}while(a!=-1);
	
	int x;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{
		std::cin>>x;
		if(x!=0 && x!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(x!=0 && x!=1);
	
	bool Prosti;
	if(x==1) Prosti=true;
	else Prosti=false;
	std::vector<int> pretvoreni(IzdvojiSimetricneTernarne(vektor,Prosti));

	if(x==true){
		 if(pretvoreni.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		 else std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	}
	else {
		if(pretvoreni.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	for(int i=0;i<pretvoreni.size();i++){
		std::cout<<pretvoreni.at(i);
		if(i!=pretvoreni.size()-1) std::cout<<", ";
		else std::cout<<".";
	}
	return 0;
}
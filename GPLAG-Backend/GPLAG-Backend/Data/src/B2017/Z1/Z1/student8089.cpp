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

typedef std::vector<int> vektor;

bool DaLiJeProst(int n){
	if(n<1) n*=-1;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return false;
	}
	return true;
	
}

int Ternarni(int broj){
	int pretvoreni(0);
	int i(0);
	while(broj != 0){
		int c ;
		c = broj % 3;
		pretvoreni+=c*pow(10,i++);
		broj/=3;
	}
	return pretvoreni;
}


vektor IzdvojiSimetricneTernarne(vektor v,bool vrijednost){
	vektor v1,v2;
	for(int br : v){
		int broj(br);
		int obrnuto(0),brojac(0),j(0);
		int pomocna = Ternarni(br);
		int naprijed = Ternarni(br);
		int ter3 = Ternarni(br);
		
		while(pomocna != 0){
			pomocna/=10;
			brojac++;
		}
		while(ter3 != 0){
			int c = ter3 % 10;
			obrnuto+=c*pow(10,--brojac);
			ter3/=10;
		}
		if(DaLiJeProst(broj)  && naprijed==obrnuto) v1.push_back(broj);
		if(DaLiJeProst(broj) != true && naprijed==obrnuto) v2.push_back(broj);
	}
	if (vrijednost == true) return v1;
	 return v2;
}



int main ()
{
	
	
	int unos,n;
	vektor a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	
    do{
    	std::cin>>n;
    	if(n==-1) break;
    	else a.push_back(n);
    }while(1);
    
    vektor prosti = IzdvojiSimetricneTernarne(a,true);
	vektor slozeni = IzdvojiSimetricneTernarne(a,false);
    
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";	
   do{
	std::cin>>unos;
	if(unos != 1 && unos != 0) std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(unos != 1 && unos != 0);
	
	if(prosti.size() == 0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	if(slozeni.size() == 0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	
	if(unos == 1 && prosti.size() != 0){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<prosti.size()-1; i++) std::cout<<prosti.at(i)<<", ";
		std::cout<<prosti.at(prosti.size()-1)<<".";
		
	}
	if(unos == 0 && slozeni.size() != 0){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<slozeni.size()-1; i++) std::cout<<slozeni.at(i)<<", ";
		std::cout<<slozeni.at(slozeni.size()-1)<<".";
	}
	
	
	return 0;
}
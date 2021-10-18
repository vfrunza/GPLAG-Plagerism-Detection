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

bool ProstiBrojevi(int n) {
	if(n<0) n*=(-1);
	if(n<=1) return false;
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i == 0) return false;
	}
	return true;
}


int Ternarni (int br) {
	int x(0), cifra;
	while(br != 0) {
		cifra = br % 3;
	    x = x*10 + cifra;
	    br = br/3;
	}
	return x;
}

int Obrnut (int x) {
	int obrnut_broj(0), zadnja_cifra;
	
	while(x!=0) {
		zadnja_cifra = x % 10;
		x = x/10;
		obrnut_broj = obrnut_broj*10 + zadnja_cifra;
		
	}
	return obrnut_broj;
}

bool Simetrican (int x) {
	if(x == Obrnut(x)) 
	   return true;
	else
	   return false;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>a, bool b) {
	std::vector<int> c, d;
	
	for(int i=0; i<a.size()-1; i++) {
		for(int j=i+1; j<a.size(); j++) {
			if(a.at(i) == a.at(j)) {
				a.erase(a.begin() + j);
				j--;
			}
			if(i == j) {
				j++;
			}
		}
	}
	for(int i=0; i<a.size(); i++) {
	//	std::cout<<a.at(i)<<" "<<ProstiBrojevi(a.at(i)) <<" "<<Simetrican(Ternarni(a.at(i)));
    if( a.at(i) != 1 ) {
		if(ProstiBrojevi(a.at(i)) && Simetrican(Ternarni(a.at(i))) )
		   c.push_back(a.at(i));
		else if(!(ProstiBrojevi(a.at(i))) && Simetrican(Ternarni(a.at(i))))
		   d.push_back(a.at(i));
	}
	}
	if(b) return c;
	return d;
} 


int main ()
{
	int a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	std::vector<int> v;
	
	do {
		std::cin>>a;
		if(a != -1) v.push_back(a);
		
	} while(a != -1);
	
	int b;
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>b;
	
	while(b!=1 && b!=0) {
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>b;
	} 

	std::vector<int> kraj = IzdvojiSimetricneTernarne(v, b);
    
	if(b == 1) {
		if(kraj.size() == 0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		} else
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		
		for(int i=0; i<kraj.size(); i++) {
			
		    if(i == kraj.size()-1) std::cout<<kraj.at(i)<<".";
		else std::cout<<kraj.at(i)<<", ";
		
	    }
	

	} else if(b == 0)  {
			if(kraj.size() == 0) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		} else 
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<kraj.size(); i++) {
		   if(i == kraj.size()-1) std::cout<<kraj.at(i)<<".";
		   else std::cout<<kraj.at(i)<<", ";
	    }
	
  


	}

	return 0;
}
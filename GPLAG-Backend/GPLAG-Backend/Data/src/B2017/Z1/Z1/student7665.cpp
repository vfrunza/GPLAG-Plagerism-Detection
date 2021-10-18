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
	bool DaLiJeProst (int n) {
			
			if (n<0) 
			n=abs(n);
		
			for (int i=2;i<=n-1;i++) {
		 	if (n%i==0) 
			return false;
			}
			return true;
		}
		

		std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool prost) {
			
			std::vector<int> kraj; 
			
			if (prost) {
				
				for (int i=0; i<v.size(); i++) {
								
							
				std::vector<int> ternar;
				int x=v.at(i);	
				
				
				if (DaLiJeProst(x)) {				
				
			
				while (x>0) {
					
					if (x<0) 
					x=abs(x);
					int ostatak=x%3;
					ternar.push_back(ostatak);
					x/=3;
					}
				
					
				int a(0);
				int b(ternar.size()-1);
				
				bool simetrican = true;
				
				while (a<b) {
					
					if(ternar.at(a) != ternar.at(b))
					simetrican = false;
				
					
				a++;
				b--;
				}	
				
				 if (simetrican==true) {
				 
				kraj.push_back(v.at(i));
				}
				}
			    } 
			
			} else {
				
				
				for (int i=0; i<v.size(); i++) {
								
				std::vector<int> ternar;
				int x=v.at(i);	
								
				if (!(DaLiJeProst(x))) {
			
				while (x>0) {
					
					int ostatak=x%3;
					ternar.push_back(ostatak);
					x/=3;
					}
				
					
				int a(0);
				int b(ternar.size()-1);
				
				bool simetrican = true;
				
				while (a<b) {
					
					if(ternar.at(a) != ternar.at(b))
					simetrican = false;
				
					
				a++;
				b--;
				}	
				
				 if (simetrican==true) {
				 
				kraj.push_back(v.at(i));
			
				} } }  }
				
				return kraj;
			
		}
		
		
	int main () {
	int broj;
	std::vector<int> niz;

	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::cin >> broj;
	while (broj!=-1) {
	
	niz.push_back(broj);
	std::cin >> broj;
	} 
	int t;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> t;
	
	while (t!=1 && t!=0) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> t;
		std::cin.ignore (1000,'\n');
	}
	
	
	
	
	std::vector<int> prosti(IzdvojiSimetricneTernarne(niz,true));
	std::vector<int> slozeni(IzdvojiSimetricneTernarne(niz,false));
	
	if (t==1) {
	std::vector<int> prazan(0);
	if (prosti!=prazan) {
	std::cout << "Prosti simetricni brojevi iz vektora su: ";
	for (int i=0; i<prosti.size(); i++) {
		
		if (i==prosti.size()-1) {
			std::cout << prosti.at(i);
		} else {
		std::cout << prosti.at(i) << ", ";
		}
	
	} 
		std::cout << "." << std::endl;
	} else std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	} else if (t==0)  {
		std::vector<int>  prazan(0);
		if (slozeni!=prazan) {
	std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	
	for (int i=0; i<slozeni.size(); i++) {
		
		if (i==slozeni.size()-1) {
			std::cout << slozeni.at(i);
		} else {
			std::cout << slozeni.at(i) <<", ";
		}}
	 std::cout << "." << std::endl;
	} else if (slozeni==prazan) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}
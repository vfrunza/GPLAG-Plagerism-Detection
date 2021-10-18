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

bool DaLiJeProst (int a) {
	
	//if(a==1 || a==0) return false;
	
	for(int i(2);i<a;i++) {
		if(a%i==0) {
			return false;
		}
	}
	
	return true;
}

int PretvoriUTernarne (int broj) {

	std::vector<int> cifre;

	do {
		int a=broj%3;
		cifre.push_back(a); 
		broj/=3;
	} while(broj!=0);
	
	int ternarni(0);
	for(int i=cifre.size()-1;i>=0;i--) {
		ternarni+=cifre.at(i)*std::pow(10,(i));
	}
	
	return ternarni;
}

bool DaLiJeSimetrican (int x) {
	
	int broj=PretvoriUTernarne(x);
	std::vector<int> brojevi_naprijed;
	do {
		int a=broj%10;
		brojevi_naprijed.push_back(a); 
		broj/=10; 
	} while(broj!=0);
	
	std::vector<int> brojevi_nazad;
	for(int i=brojevi_naprijed.size()-1;i>=0;i--) {
		brojevi_nazad.push_back(brojevi_naprijed.at(i));
	}
	
	for(int i(0);i<brojevi_naprijed.size();i++) {
		for(int j(0);j<brojevi_nazad.size();j++) {
			if(i==j) {
				if(brojevi_naprijed.at(i)!=brojevi_nazad.at(j)) return false;
			}
		}
	}
	return true;
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> brojevi, bool istina) {
	
	std::vector<int> slozeni;
	if(istina!=true) {
		
		for(int i(0);i<brojevi.size();i++) {
			if(brojevi.at(i)!=1) {
				if(brojevi.at(i)==0 || DaLiJeProst(std::abs(brojevi.at(i)))==false) 
					 slozeni.push_back(brojevi.at(i));
			}
		}
	
		for(int i(0);i<slozeni.size();i++) {
			for(int j(i+1);j<slozeni.size();j++) {
				if(slozeni.at(i)==slozeni.at(j)) {
					slozeni.erase(slozeni.begin()+j);
					j--;
				}
			}
		}
		for(int i(0);i<slozeni.size();i++) {
			if (DaLiJeSimetrican(std::abs(slozeni.at(i)))==false) {
				slozeni.erase(slozeni.begin()+i);
				i--;
			}
		}
		
		
		return slozeni;
	}
	
	std::vector<int> prosti;
	if(true) {
		//Napuni novi vektor prostim brojevima
		for(int i(0);i<brojevi.size();i++) {
			if(brojevi.at(i)!=1 && brojevi.at(i)!=0) {
				if(DaLiJeProst(std::abs(brojevi.at(i)))) 
				 prosti.push_back(brojevi.at(i));
			}
		}
		//Izbaci sve duple da ne smetaju 
		for(int i(0);i<prosti.size();i++) {
			for(int j(i+1);j<prosti.size();j++) {
				if(prosti.at(i)==prosti.at(j)) {
					prosti.erase(prosti.begin()+j);
					j--;
				} 
				
			}
		} 

		//Simetrija3
		for(int i(0);i<prosti.size();i++) {
			if (DaLiJeSimetrican(std::abs(prosti.at(i)))==false) {
				prosti.erase(prosti.begin()+i);
				i--;
			}
		}
	} 
	return prosti;
	
}



int main () {
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> vekt;
	int broj;
	
	do {
		std::cin>>broj;
		if(broj!=-1) vekt.push_back(broj);
	} while (broj!=-1);
	
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;	
	for(;;){
		std::cin>>a;
		if(a==1 || a==0) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	bool prost;
	if(a==1) prost=true;
	else prost=false;


	
	std::vector<int> Novi_vektor(IzdvojiSimetricneTernarne(vekt,prost));
	if(prost==true) {
		
		if(Novi_vektor.size()>0){
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i(0);i<Novi_vektor.size();i++) {
				if(i<Novi_vektor.size()-1)
					std::cout<<Novi_vektor.at(i)<<", ";
				else std::cout<<Novi_vektor.at(i)<<".";
			}
		}
		else std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	if(prost==false) {
		if(Novi_vektor.size()>0) {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i(0);i<Novi_vektor.size();i++) {
				if(i<Novi_vektor.size()-1)
					std::cout<<Novi_vektor.at(i)<<", ";
					else std::cout<<Novi_vektor.at(i)<<".";
			}
		}
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	
	
	return 0;
}
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

bool ProvjeraBrojeva (int n){
	if (n<=1) return false;
	for (int i=2;i<=std::sqrt(n);i++){
		if (n==2) return true;
		else if (n%i==0) return false;
	}
	return true;
}

std::vector <int> PretvorbaUTernarne (int n){
	std::vector <int> i;
	do{
		i.push_back(std::abs(n%3));
		n/=3;
	}while(n!=0);
	return i;
}

bool Simetricni (int n){
	std::vector <int> v2=PretvorbaUTernarne(n);
	for ( int i=0;i<v2.size();i++)
		if (v2.at(i)!=v2.at(v2.size()-1-i))
			return false;
		return true;
}

std::vector <int> IzdvojiSimetricneTernarne (std::vector <int> v1, bool stanje) {
	std::vector <int> vektor;
	if (stanje==true){
		for (int i=0;i<v1.size();i++){
			bool dupli=false;
			if(Simetricni (v1.at(i)) && ProvjeraBrojeva(v1.at(i))==true){
			for (int j=0;j<vektor.size();j++)
				if (v1.at(i)==vektor.at(j))dupli=true;
				if (dupli==false) vektor.push_back(v1.at(i));
				
			}
		}
	}else if (stanje==false){
		for (int i=0;i<v1.size();i++){
			bool dupli=false;
			if(Simetricni (v1.at(i)) && ProvjeraBrojeva(v1.at(i))==false){
			for (int j=0;j<vektor.size();j++)
				if (v1.at(i)==vektor.at(j))dupli=true;
				if (dupli==false) vektor.push_back(v1.at(i));
			}
		}
	}
	return vektor;
}





int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector <int> vektor;
	for(;;){
		int broj;
		std::cin>>broj;
		if (broj==-1) break;
		vektor.push_back (broj);
	}
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int provjera;
	do{
		std::cin>>provjera;
		if (provjera!=0 && provjera!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(provjera!=0 && provjera!=1);
	std::vector <int> vektor2 (IzdvojiSimetricneTernarne (vektor, bool (provjera)));
	
	if (vektor2.size()!=0){
		if (provjera==true)
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	    else if (provjera==false)
	    std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0;i<vektor2.size();i++){
				if(i==vektor2.size()-1) std::cout<<vektor2.at(i)<<".";
				else std::cout<<vektor2.at(i)<<", ";
			}
	}
	else if (vektor2.size()==0){
		if (provjera==true)
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else if (provjera==false)
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}
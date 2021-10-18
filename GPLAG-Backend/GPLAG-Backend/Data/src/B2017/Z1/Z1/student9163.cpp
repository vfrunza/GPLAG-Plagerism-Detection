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

typedef std:: vector <int> Vektor;

bool DaLiJeProst (int n) {
	for (int i(2); i<= std:: sqrt (n); i++)
	     if (n%i==0) return false;
	return true;     
}

int PretvoriUTernarni (int b) {
	int ternarni_broj(0), i(0);
	do {
		  if (b<0) b=-b;
		  int cifra=b%3;
		  ternarni_broj+=cifra*pow(10,i);
		  b/=3;
		  i++;
   	} while (b);	
    return ternarni_broj;    
}
bool DaLiSuSimetricni (int x) {
	int y(0), pom(PretvoriUTernarni(x));
	int pom1(PretvoriUTernarni(x));   
 	do {
         int cifra=pom%10;
         y=y*10+cifra;   
         pom/=10;
         } while (pom);
    if (pom1!=y) return false;
    else return true;
}
Vektor IzdvojiSimetricneTernarne (Vektor v, bool prost) {
	Vektor simetricni_ternarni;  
	if (prost) //ako se trazi vektor prostih brojeva
	   {
	   	   for (int i(0); i<v.size(); i++)
	   	       if (DaLiJeProst(v.at(i)))
	   	       	  if (DaLiSuSimetricni(v.at(i)))
	   	       	  simetricni_ternarni.push_back(v.at(i));
	   }
	else {
		   for (int i(0); i<v.size(); i++)
		       if (!(DaLiJeProst(v.at(i))))
		          if (DaLiSuSimetricni(v.at(i)))
		              simetricni_ternarni.push_back(v.at(i));
	}   
	return simetricni_ternarni;
}
int main ()
{
	int broj;
	Vektor vek;
	// unos brojeva u vektor
	std:: cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std:: cin >> broj;
		if(broj==-1) break; 
		vek.push_back(broj);
	} while (broj!=-1);
	int pr;
	std:: cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    while(1) {
    	std:: cin >> pr;
    	if (pr==0 || pr==1) break;
    	else std:: cout << "Neispravan unos! Unesite ponovo: ";
    }
    //ispis 
    
	Vektor vek_ter(IzdvojiSimetricneTernarne(vek, pr)); 
    if(pr)
    {
	    if(vek_ter.size()==0) {
		std:: cout<< "Nema prostih simetricnih brojeva u vektoru.";
	    } else {
		std:: cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int i(0); i<vek_ter.size()-1; i++) 
		     std:: cout << vek_ter.at(i) << ", ";
		std:: cout << vek_ter.at(vek_ter.size()-1) << ".";
	    }
    }
	else {
		if(vek_ter.size()==0)
			std:: cout << "Nema slozenih simetricnih brojeva u vektoru.";
	    else{
		std:: cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int i(0); i<vek_ter.size()-1; i++) 
		    std:: cout << vek_ter.at(i) << ", ";
		std:: cout << vek_ter.at(vek_ter.size()-1) << ".";
		}
	}
	return 0;
}
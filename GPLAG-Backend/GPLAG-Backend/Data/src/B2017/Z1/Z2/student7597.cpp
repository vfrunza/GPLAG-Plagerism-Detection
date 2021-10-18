/*B 2017/2018, Zadaća 1, Zadatak 2
	
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
#include <iomanip>
#include <stdexcept>

using std::vector;

typedef vector<vector<double>> Matrica;

/* VRACA VIŠU MATRICU*/

Matrica visa(Matrica a,Matrica b) { 
	if(a.at(a.size()/2).at(a.size()/2) > b.at(b.size()/2).at(b.size()/2))
		return a;
	return b;
}
 /* */
 
vector<Matrica> PlanineMatrice (Matrica mat) {
	
	for(vector<double> red : mat) {
		if(red.size() != mat.at(0).size())
			throw std::domain_error("Matrica nije korektna");
	}
	
	vector<Matrica> planine;
	vector<double> koncentricni;
	for(int i=0;i<mat.size();i++) {
		for(int j=0;j<mat.at(0).size();j++) {  // Za svaki element matrice ubacujemo sume koncentricnih kvadrata
		
			koncentricni.push_back(mat.at(i).at(j)); // Prvi konc "kvadrat" je sam taj element..
			int brojac=1;
			while(j-brojac>=0 && i-brojac>=0 && i+brojac<mat.size() && j+brojac<mat.at(0).size()) { // Trazim sume koncentricnih kvadrata
				double suma = 0;
				for(int red=i-brojac;red<=i+brojac;red++) {
					for(int kolona=j-brojac;kolona<=j+brojac;kolona++) {
							suma+=mat.at(red).at(kolona);
					}
				}
				for(int x : koncentricni)  // Uzmi samo vanjski okvir , otkini unutrasnje sume
					suma-=x;            
				if(suma<koncentricni.at(brojac-1))  // Ako je koncetricna suma manja od prethodne
					koncentricni.push_back(suma);
				else
					break;
				brojac++;
			}
			if(koncentricni.size() >= 1) { // U koncetricne spada i vrh planine
				brojac--;     // Treba smanjiti za jedan da ne izadjem iz opsega
				Matrica p;
				int brojRedova = 2*koncentricni.size()-1;
				p.resize(brojRedova);
				for(int red=0;red<brojRedova;red++) {              // Akrobacije sa pomocnom matricom , koju guram u vektor matrica (planine)
					for(int kolona=0;kolona<brojRedova;kolona++) {
						p.at(red).push_back(mat.at(red+i-brojac).at(kolona+j-brojac));
					}
				}
				planine.push_back(p);
			}
			koncentricni.resize(0); // Priprema za iduci element
		 // END
		}
	}
	return planine;
}

Matrica NajvecaPlaninaMatrice(Matrica mat) {
	
	vector<Matrica> planine = PlanineMatrice(mat);
	Matrica najvecaPlanina;
	if(planine.size()==0)
		return najvecaPlanina;
		
	najvecaPlanina = planine.at(0);
	
	for(Matrica X : planine ) {                 // Trazi najvecu planinu..
		if(X.size()>najvecaPlanina.size())
			najvecaPlanina = X;
		else if(X.size()==najvecaPlanina.size() && X==visa(X,najvecaPlanina))
			najvecaPlanina = X;
	}
	
	return najvecaPlanina;
}


int main ()
{
	int m,n;
	Matrica mat;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	mat.resize(m);
	std::cout<<"Unesite elemente matrice: ";
	double element;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			std::cin>>element;
			mat.at(i).push_back(element);
		}
	} 
	          /* ISPIS MATRICE */
	std::cout<<"\nNajveca planina unesene matrice je: \n";
	
	try {
		Matrica najveca = NajvecaPlaninaMatrice(mat);
		for(int i=0;i<najveca.size();i++) {
			for(int j=0;j<najveca.at(0).size();j++) 
				std::cout<<std::setw(6)<<najveca.at(i).at(j);
			std::cout<<std::endl;
		}
	}
	catch (std::domain_error e) {
		std::cout<<"Izuzetak: "<<e.what();
	}
	
	return 0;
}
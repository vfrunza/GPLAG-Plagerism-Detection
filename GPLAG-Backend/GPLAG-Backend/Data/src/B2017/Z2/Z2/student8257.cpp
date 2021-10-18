/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::deque;

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, 
GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template<typename kontejner>
	void Ispravan(const kontejner &kont) {
		
		int dimenzija = kont.size();    // Broj 2D ploha
		
		for(int i=0;i<dimenzija;i++) {
			if(kont.at(i).size()!=dimenzija)  // Ako ploha ima razlicit broj redova od broja ploha
				throw std::domain_error("3D matrica nema oblik kocke");
			for(int j=0;j<dimenzija;j++) {
				if(kont.at(i).at(j).size()!=dimenzija)  // Ako ploha nije kvadratna
					throw std::domain_error("3D matrica nema oblik kocke");
			}
		}
		if(dimenzija%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	}
	
template<typename kontejner>
	auto napraviPjescani(const kontejner &kont)->kontejner {  // PO DEFAULTU PRAVI GORE-DOLJE PJESCANI SAT
		int duzina = kont.size();
		kontejner pjescani(duzina);
		for(int i=0;i<duzina;i++) {  // Prolazi kroz sve 2D matrice
				pjescani.at(i).resize(duzina);
				for(int j=0;j<duzina;j++) {  
					for(int k=j;k<duzina-j;k++) {  
						pjescani.at(i).at(j).push_back(kont.at(i).at(j).at(k));  		// PRAVI GORNJU POLU PJESCANOG SATA
						if(j!=duzina/2)  											// Da ne ubaci dva puta sredisnji element
							pjescani.at(i).at(duzina-j-1).push_back(kont.at(i).at(duzina-j-1).at(k));	// PRAVI DONJU POLU PJESCANOG SATA
					}	
				}
			}
		return pjescani;
	}
template<typename kontejner>
	auto rotirajUlijevo(const kontejner &kont) ->kontejner {
		int duzina = kont.size();
		kontejner rez(duzina);
		for(int i=0;i<duzina;i++) {
			rez.at(i).resize(duzina);
			// Transponiranje matrice
			for(int j=0;j<duzina;j++) {
				for(int k=0;k<duzina;k++) {
					rez.at(i).at(j).push_back(kont.at(i).at(k).at(duzina-j-1));
				}
			}
		}
		return rez;
	}

template<typename kontejner>
	void Izvrni(kontejner &kont) {
		int duzina = kont.size();
		for(int i=0;i<duzina;i++) 
			std::reverse(kont.at(i).begin(),kont.at(i).end());
	}

template<typename kontejner>
	auto PjescaniSat(const kontejner &kont,SmjerKretanja smjer) ->kontejner {
		
		Ispravan(kont); // Provjera ispravnosti kontejnera
		
		kontejner pjescani;
		if(smjer == SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore ) {  // GoreDolje , DoljeGore
			pjescani = napraviPjescani(kont);  // Ovo je GoreDolje
			if(smjer==SmjerKretanja::DoljeGore)   // Ako hocemo DoljeGore , treba izvrnuti samo
				Izvrni(pjescani);
		}
		else if(smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::DesnoLijevo ) { // LijevoDesno , DesnoLijevo
			pjescani = rotirajUlijevo(kont);    // Rotira sve podmatrice u "lijevo"
			pjescani = napraviPjescani(pjescani);
			
			if(smjer==SmjerKretanja::LijevoDesno )  //  Ako ipak treba LijevoDesno samo izvrni matrice
				Izvrni(pjescani);
		}
		else if(smjer == SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed ) {
			int duzina = kont.size();
			pjescani.resize(duzina);			// Pripremam kontejner da napravim pjescani od njega
			for(int i=0;i<duzina;i++) {           
				pjescani.at(i).resize(duzina);
				for(int j=0;j<duzina;j++) {
					for(int k=0;k<duzina;k++) {  // Prvi redovi svih matrica iz "kont" idu u prvu matricu pjecanog sata,drugi idu u drugu itd...
						pjescani.at(i).at(j).push_back(kont.at(j).at(i).at(k));
					}
				}
			}
			pjescani = napraviPjescani(pjescani);  // NaprijedNazad
			if(smjer==SmjerKretanja::NazadNaprijed)
				Izvrni(pjescani);
		}
		return pjescani;
	}
	
int main ()
{
	try {
		std::cout<<"Unesite dimenziju (x/y/z): ";
		int n;
		std::cin>>n;
		while(!(std::cin) || n<1) {
			std::cout<<"Dimenzija nije ispravna, unesite opet: ";
			std::cin>>n;
		}
			
		vector<deque<deque<int>>> kont3D(n);
		std::cout<<"Unesite elemente kontejnera: ";
		for(int i=0;i<n;i++) {
			kont3D.at(i).resize(n);
			for(int j=0;j<n;j++) {
				kont3D.at(i).at(j).resize(n);
				for(int k=0;k<n;k++)
					std::cin>>kont3D[i][j][k];
			}
		}
		
		std::cout<<"Unesite smjer kretanja [0 - 5]: ";
		int izbor;
		while(!(std::cin>>izbor) || izbor<0 || izbor>5) {
			std::cout<<"Smjer nije ispravan, unesite opet: ";
		}
		auto pjescani = PjescaniSat(kont3D , SmjerKretanja(izbor));
		std::cout<<"\nPjescani sat unesene matrice je:\n\n";
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(j<=n/2)
					std::cout<<std::setw(j*4)<<"";
				else	
					std::cout<<std::setw((n-j-1)*4)<<"";
				for(int k=0;k<pjescani.at(i).at(j).size();k++) {
					std::cout<<std::setw(4)<<pjescani.at(i).at(j).at(k);
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
		}
		return 0;
	}
	catch(std::domain_error e ) {
		std::cout<<"\nIzuzetak: "<<e.what();
	}
	catch(std::length_error e ) {
		std::cout<<"\nIzuzetak: "<<e.what();
	}
}
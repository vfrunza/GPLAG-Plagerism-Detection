#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kont>
auto PjescaniSat (kont c, SmjerKretanja s) -> decltype(c)
{
	kont kontejner=c;
	kont kontejner2=c;
	int dim=c.size();
	for(int d=0; d<dim; d++) {
		for(int i=0; i<dim; i++) {
			kontejner.at(d).at(i).resize(0);
			kontejner2.at(d).at(i).resize(0);
		}
	}
	for(int i=0; i<c.size(); i++) {
		if(c.at(i).size() != c.size()) throw std::domain_error ("3D matrica nema oblik kocke");
		for(int j=0; j<c.at(i).size(); j++) {
			if(c.at(i).at(j).size()!= c.size()) throw std::domain_error ("3D matrica nema oblik kocke");
		}
	}
	if(c.size()%2==0) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");

/* Ako je smjer NpNz ili NzNp */ 
	if(int(s)==0 || int(s)==1) {
		for(int i=0; i<dim; i++) {
			for(int d=0; d<dim; d++) {
				for(int j=d; j<dim-d; j++) {
					kontejner.at(i).at(d).push_back(c.at(d).at(i).at(j));
				}
				if(d==dim/2) continue;
				for(int j=dim-d-1; j<=d; j++) {
					kontejner.at(i).at(d).push_back(c.at(d).at(i).at(j));
				}
			}
		}
		
/* Ako je smjer NzNP samo prepiše u novi kontejner u suprotnom redoslijedu redove odozdo prema gore*/
		int k;
		if(int(s)==1) {
			for(int d=0; d<dim; d++) {
				k=0;
				for(int i=dim-1; i>=0; i--) {
					for(int j=0; j<kontejner.at(d).at(i).size(); j++) {
						kontejner2.at(d).at(k).push_back(kontejner.at(d).at(i).at(j));
					}
					k++;
				}
			}
			return kontejner2;
		}
	}
/* Ako je smjer GD ili DG */	
	if(int(s)==2 || int(s)==3){
		for(int d=0; d<dim; d++){
			for(int i=0; i<dim; i++){
				for(int j=i; j<(dim-i); j++){kontejner.at(d).at(i).push_back(c.at(d).at(i).at(j));}
				if(i==dim/2) continue;
				for(int j=dim-i-1; j<=i; j++){kontejner.at(d).at(i).push_back(c.at(d).at(i).at(j));}
			}
		}
	/*Ako je smjer DG*/
		int k;
		if(int(s)==3){
			for(int d=0; d<dim; d++){
				k=0;
				for(int i=dim-1; i>=0; i--){
					for(int j=0; j<kontejner.at(d).at(i).size(); j++){
						kontejner2.at(d).at(k).push_back(kontejner.at(d).at(i).at(j));
					}
					k++;
				}
			}
			return kontejner2;
		}
	}
	/* Ako je smjer LD ili DL */
	if(int(s)==4 || int(s)==5){
		for(int d=0; d<dim; d++){
			for(int j=0; j<dim; j++){
				for(int i=j; i<dim-j; i++){kontejner.at(d).at(j).push_back(c.at(d).at(i).at(j));}
				if(j==dim/2) continue;
				for(int i=dim-j-1; i<=j; i++){kontejner.at(d).at(j).push_back(c.at(d).at(i).at(j));}
			}
		}
	/*Ako je smjer DL*/
		int k;
		if(int(s)==5){
			for(int d=0; d<dim; d++){
				k=0;
				for(int i=dim-1; i>=0; i--){
					for(int j=0; j<kontejner.at(d).at(i).size(); j++){
						kontejner2.at(d).at(k).push_back(kontejner.at(d).at(i).at(j));
					}
					k++;
				}
			}
			return kontejner2;
		}
		
	}



	return kontejner;

}

int main ()
{
	try {
		int broj;
		std::cout<<"Unesite dimenziju (x/y/z): ";
		int dim;
		do {
			std::cin>>dim;
			if(dim<1) std::cout<<"Dimenzija nije ispravna, unesite opet: ";
		} while(dim<1);

		std::vector<std::deque<std::deque<int>>> c;
		std::deque<std::deque<int>> d;
		std::deque<int> f;
		std::cout<<"Unesite elemente kontejnera: ";
		for(int i=0; i<dim; i++) {
			for(int j=0; j<dim; j++) {
				for(int k=0; k<dim; k++) {
					std::cin>>broj;
					f.push_back(broj);
				}
				d.push_back(f);
				f.resize(0);
			}
			c.push_back(d);
			d.resize(0);
		}

		int smjer;
		std::cout<<"Unesite smjer kretanja [0 - 5]: ";
		do {
			std::cin>>smjer;
			if(smjer<0 || smjer>5) std::cout<<"Smjer nije ispravan, unesite opet: ";
		} while(smjer<0 || smjer>5);
		std::vector<std::deque<std::deque<int>>> novi;
		novi=PjescaniSat(c, SmjerKretanja(smjer));
		std::cout<<std::endl<<"Pjescani sat unesene matrice je:"<<std::endl<<std::endl;
		for(int d=0; d<dim; d++) {
			for(int i=0; i<dim; i++) {
				for(int k=0; k<(dim-novi.at(d).at(i).size())/2; k++) std::cout<<"    ";
				for(int j=0; j<novi.at(d).at(i).size(); j++) {
					std::cout<<std::right<<std::setw(4)<<novi.at(d).at(i).at(j);
				
				}
				std::cout<<std::endl;
			}
			std::cout<<std::endl<<std::endl;
			
		}

	} catch(std::range_error izuzetak) {
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}

	catch(std::length_error izuzetak) {
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	return 0;
}
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
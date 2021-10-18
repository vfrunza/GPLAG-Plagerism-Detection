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
#include <stdexcept>
#include <iomanip>
#include <type_traits>

enum class SmjerKretanja{
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename KontTip>
	KontTip PjescaniSat(KontTip kontejner, SmjerKretanja smjer){
		KontTip rjesenje; 
		
		//provjera dimenzija dal je kocka... dal su sve iste dimenzije ugl
		for(int i=0; i<kontejner.size(); i++){
			for(int j=0; j<kontejner.at(i).size(); j++){
				if( (kontejner.at(i).size()!=kontejner.at(i).at(j).size()) || (kontejner.size()!=kontejner.at(i).size()) || (i+1<kontejner.size() && kontejner.at(i).size()!=kontejner.at(i+1).size()) ) throw std::domain_error("3D matrica nema oblik kocke");
			}
		}
		//provjera neparnosti
		for(int i=0; i<kontejner.size(); i++){
			for(int j=0; j<kontejner.at(i).size(); j++){
				if(kontejner.at(i).size()%2==0)throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
			}
		}
		
		for(int i=0; i<kontejner.size(); i++){
			typename std::remove_reference<decltype(kontejner.at(i))>::type pomocna_matrica;
			for(int j=0, br=0; j<kontejner.at(i).size(); j++){
				typename std::remove_reference<decltype(kontejner.at(i).at(j))>::type pomocni_red;
				for(int z=0; z<kontejner.at(i).at(j).size(); z++){
					if(smjer==SmjerKretanja::GoreDolje && z>=0+br && z<kontejner.at(i).at(j).size()-br)pomocni_red.push_back(kontejner.at(i).at(j).at(z));
					if(smjer==SmjerKretanja::DoljeGore && z>=0+br && z<kontejner.at(i).at(j).size()-br)pomocni_red.push_back(kontejner.at(i).at(kontejner.size()-1-j).at(z));
					if(smjer==SmjerKretanja::DesnoLijevo && z>=0+br && z<kontejner.at(i).at(j).size()-br)pomocni_red.push_back(kontejner.at(i).at(z).at(kontejner.size()-1-j));
					if(smjer==SmjerKretanja::LijevoDesno && z>=0+br && z<kontejner.at(i).at(j).size()-br)pomocni_red.push_back(kontejner.at(i).at(z).at(j));
					if(smjer==SmjerKretanja::NaprijedNazad && z>=0+br && z<kontejner.at(i).at(j).size()-br)pomocni_red.push_back(kontejner.at(j).at(i).at(z));
					if(smjer==SmjerKretanja::NazadNaprijed && z>=0+br && z<kontejner.at(i).at(j).size()-br)pomocni_red.push_back(kontejner.at(kontejner.size()-j-1).at(i).at(z));
				}
				pomocna_matrica.push_back(pomocni_red);
				if(j<kontejner.at(i).size()/2)br++;
				else br--;
			}
			rjesenje.push_back(pomocna_matrica);
		}
		return rjesenje;
	}

int main ()
{
	int n;
	std::cout << "Unesite dimenziju (x/y/z): ";
	for(;;){
		std::cin >> n;
		if(n>=0) break;
		else std::cout << "Dimenzija nije ispravna, unesite opet: ";
	}
	std::vector<std::deque<std::deque<int>>> kontejner (n, std::deque<std::deque<int>>(n, std::deque<int>(n)));
	std::cout << "Unesite elemente kontejnera: ";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int z=0; z<n; z++){
				std::cin >> kontejner.at(i).at(j).at(z);
			}
		}
	}
	int x;
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	for(;;){
		std::cin >> x;
		if(x>=0 && x<=5) break;
		else std::cout << "Smjer nije ispravan, unesite opet: ";
	}
	SmjerKretanja smjer {SmjerKretanja(x)};
	try{
		std::vector<std::deque<std::deque<int>>> pjescani_sat(PjescaniSat(kontejner, smjer));
		std::cout << "\nPjescani sat unesene matrice je:\n\n";
		for(int i=0; i<pjescani_sat.size(); i++){
			for(int j=0, br=0; j<pjescani_sat.at(i).size(); j++){
				for(int z=0; z<pjescani_sat.at(i).at(j).size(); z++){
					for(int k=0; k<br; k++) std::cout << std::setw(4) << "";
					std::cout << std::setw(4) << pjescani_sat.at(i).at(j).at(z);
				}
				if(j<pjescani_sat.at(i).size()/2)br++;
				else br--;
				std::cout << "\n";
			}
			std::cout << "\n";
		}
	}
	catch(std::domain_error &e){
		std::cout << "\nIzuzetak: " << e.what();
	}
	catch(std::length_error &e){
		std::cout << "\nIzuzetak: " << e.what();
	}
	return 0;
}
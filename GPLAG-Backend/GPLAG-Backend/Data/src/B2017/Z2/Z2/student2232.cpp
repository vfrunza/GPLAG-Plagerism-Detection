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
#include <type_traits>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja {
NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Tip>
Tip PjescaniSat(Tip kont, SmjerKretanja smjer){

	for(int i=0; i<int(kont.size()); i++)
		for(int j=0; j<int(kont.at(i).size()); j++)
			if(int(kont.size())!=int(kont.at(i).size()) || int(kont.at(0).size())!=int(kont.at(i).size()) || int(kont.size())!=int(kont.at(i).at(j).size()) || int(kont.at(i).size())!=int(kont.at(i).at(j).size()) || int(kont.at(i).at(0).size())!=int(kont.at(i).at(j).size()))
				throw std::domain_error ("3D matrica nema oblik kocke");
	if(int(kont.size())%2==0 && int(kont.size())!=0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	Tip Sat(kont.size());
	if(smjer==SmjerKretanja::GoreDolje){
		for(int i=0; i<int(kont.size()); i++){
			typename std::remove_reference<decltype(kont.at(i))>::type matrica(kont.at(i).size());
			for(int j=0; j<int(kont.at(i).size()); j++){
				for(int k=0; k<int(kont.at(i).at(j).size()); k++){
					if((k<=int(kont.at(i).at(j).size())/2)){
						if((j<=int(kont.at(i).size())/2 && j<=k) || (j>int(kont.at(i).size()/2) && j+k>=int(kont.at(i).at(j).size())-1)) 
							matrica.at(j).push_back(kont.at(i).at(j).at(k));
					}
					else{
						if((j>=int(kont.at(i).size())/2 && j>=k) || (j<=int(kont.at(i).size())/2 && j+k<=int(kont.at(i).at(j).size())-1))	
							matrica.at(j).push_back(kont.at(i).at(j).at(k));
					}
				}
			}
			Sat.at(i)=matrica;
		}
	}
	else if(smjer==SmjerKretanja::DoljeGore){
		for(int i=0; i<int(kont.size()); i++){
			typename std::remove_reference<decltype(kont.at(i))>::type matrica(kont.at(i).size());
			for(int j=int(kont.at(i).size())-1; j>=0; j--){
				for(int k=0; k<int(kont.at(i).at(j).size()); k++){
					if((k<=int(kont.at(i).at(j).size())/2)){
						if((j<=int(kont.at(i).size())/2 && j<=k) || (j>int(kont.at(i).size()/2) && j+k>=int(kont.at(i).at(j).size())-1)) 
							matrica.at(j).push_back(kont.at(i).at(int(kont.at(i).size())-1-j).at(k));
					}
					else{
						if((j>=int(kont.at(i).size())/2 && j>=k) || (j<=int(kont.at(i).size())/2 && j+k<=int(kont.at(i).at(j).size())-1))	
							matrica.at(j).push_back(kont.at(i).at(int(kont.at(i).size())-1-j).at(k));
					}
				}
			}
			Sat.at(i)=matrica;
		}
	}
	else if(smjer==SmjerKretanja::LijevoDesno){
		for(int i=0; i<int(kont.size()); i++){
			typename std::remove_reference<decltype(kont.at(i))>::type matrica(kont.at(i).size());
			for(int j=0; j<int(kont.at(i).size()); j++){
				for(int k=0; k<int(kont.at(i).at(j).size()); k++){
					if((k<=int(kont.at(i).at(j).size())/2)){
						if((j<=int(kont.at(i).size())/2 && j<=k) || (j>int(kont.at(i).size()/2) && j+k>=int(kont.at(i).at(j).size())-1)) 
							matrica.at(j).push_back(kont.at(i).at(k).at(j));
					}
					else{
						if((j>=int(kont.at(i).size())/2 && j>=k) || (j<=int(kont.at(i).size())/2 && j+k<=int(kont.at(i).at(j).size())-1))	
							matrica.at(j).push_back(kont.at(i).at(k).at(j));
					}
				}
			}
			Sat.at(i)=matrica;
		}
	}
	else if(smjer==SmjerKretanja::DesnoLijevo){
		for(int i=0; i<int(kont.size()); i++){
			typename std::remove_reference<decltype(kont.at(i))>::type matrica(kont.at(i).size());
			for(int j=int(kont.at(i).size())-1; j>=0; j--){
				for(int k=0; k<int(kont.at(i).at(j).size()); k++){
					if((k<=int(kont.at(i).at(j).size())/2)){
						if((j<=int(kont.at(i).size())/2 && j<=k) || (j>int(kont.at(i).size()/2) && j+k>=int(kont.at(i).at(j).size())-1)) 
							matrica.at(j).push_back(kont.at(i).at(k).at(int(kont.at(i).size())-1-j));
					}
					else{
						if((j>=int(kont.at(i).size())/2 && j>=k) || (j<=int(kont.at(i).size())/2 && j+k<=int(kont.at(i).at(j).size())-1))	
							matrica.at(j).push_back(kont.at(i).at(k).at(int(kont.at(i).size())-1-j));
					}
				}
			}
			Sat.at(i)=matrica;
		}
	}
	else if(smjer==SmjerKretanja::NaprijedNazad){
		for(int i=0; i<int(kont.size()); i++){
			typename std::remove_reference<decltype(kont.at(i))>::type matrica(kont.at(i).size());
			for(int j=0; j<int(kont.at(i).size()); j++){
				for(int k=0; k<int(kont.at(i).at(j).size()); k++){
					if((k<=int(kont.at(i).at(j).size())/2)){
						if((j<=int(kont.at(i).size())/2 && j<=k) || (j>int(kont.at(i).size()/2) && j+k>=int(kont.at(i).at(j).size())-1)) 
							matrica.at(j).push_back(kont.at(j).at(i).at(k));
					}
					else{
						if((j>=int(kont.at(i).size())/2 && j>=k) || (j<=int(kont.at(i).size())/2 && j+k<=int(kont.at(i).at(j).size())-1))	
							matrica.at(j).push_back(kont.at(j).at(i).at(k));
					}
				}
			}
			Sat.at(i)=matrica;
		}
	}
	else if(smjer==SmjerKretanja::NazadNaprijed){
		for(int i=0; i<int(kont.size()); i++){
			typename std::remove_reference<decltype(kont.at(i))>::type matrica(kont.at(i).size());
			for(int j=int(kont.at(i).size())-1; j>=0; j--){
				for(int k=0; k<int(kont.at(i).at(j).size()); k++){
					if((k<=int(kont.at(i).at(j).size())/2)){
						if((j<=int(kont.at(i).size())/2 && j<=k) || (j>int(kont.at(i).size()/2) && j+k>=int(kont.at(i).at(j).size())-1)) 
							matrica.at(j).push_back(kont.at(int(kont.at(i).size())-1-j).at(i).at(k));
					}
					else{
						if((j>=int(kont.at(i).size())/2 && j>=k) || (j<=int(kont.at(i).size())/2 && j+k<=int(kont.at(i).at(j).size())-1))	
							matrica.at(j).push_back(kont.at(int(kont.at(i).size())-1-j).at(i).at(k));
					}
				}
			}
			Sat.at(i)=matrica;
		}
	}
	return Sat;
	
}

int main ()
{
	std::cout << "Unesite dimenziju (x/y/z): ";
	int dimenzija;
	for(;;){	
		std::cin >> dimenzija;
		if(dimenzija>-1) break;
		std::cout << "Dimenzija nije ispravna, unesite opet: ";
	}
	std::cout << "Unesite elemente kontejnera: ";
	std::vector<std::deque<std::deque<int>>> kocka(dimenzija, std::deque<std::deque<int>> (dimenzija, std::deque<int> (dimenzija)));
	for(int i=0; i<dimenzija; i++)
		for(int j=0; j<dimenzija; j++)
			for(int k=0; k<dimenzija; k++) std::cin >> kocka.at(i).at(j).at(k);
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	int s;
	for(;;){	
		std::cin >> s;
		if(s>-1 && s<6) break;
		std::cout << "Smjer nije ispravan, unesite opet: ";
	}
	SmjerKretanja smjer = SmjerKretanja(s);
	std::cout << std::endl;
	try{
		std::vector<std::deque<std::deque<int>>> Sat(PjescaniSat(kocka,smjer));
		std::cout << "Pjescani sat unesene matrice je:\n";
		for(int i=0; i<int(Sat.size()); i++){
			std::cout << std::endl;
			for(int j=0; j<int(Sat.at(i).size()); j++){
				if(Sat.at(i).size()==Sat.at(i).at(j).size()){
					for(int k=0; k<int(Sat.at(i).at(j).size()); k++){
						std::cout << std::right << std::setw(4) << Sat.at(i).at(j).at(k);
					}
				}
				else{
				int temp(0);
					while(temp++<int(Sat.at(i).size()-Sat.at(i).at(j).size())/2) std::cout << "    ";
					for(int k=0; k<int(Sat.at(i).at(j).size()); k++){
						std::cout << std::right << std::setw(4) << Sat.at(i).at(j).at(k);
					}
				}
				std::cout << std::endl;
			}
		}
	}
	catch(std::domain_error e){
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	catch(std::length_error e){
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	return 0;
}
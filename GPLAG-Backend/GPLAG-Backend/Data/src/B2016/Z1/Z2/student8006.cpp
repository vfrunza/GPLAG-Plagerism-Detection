/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

bool DaLiJeGrbava(std::vector<std::vector<double>> Matrica){
	for(int i = 1; i < Matrica.size(); i++)
			if(Matrica.at(i).size() != Matrica.at(0).size())
				return false;
	return true;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> Matrica){
	bool control = DaLiJeGrbava(Matrica);
	if(!control) throw std::domain_error("Matrica nije regularna");
	//Kreiramo matricu koja ce horizontalno izmijesati elemente
	std::vector<std::vector<double>> Horizontalna;
	Horizontalna.resize(Matrica.size());
	for(int i = 0; i < Matrica.size(); i++)
		for(int j = 0; j < Matrica.at(i).size(); j++){
			double temp;
			temp = Matrica.at(i).at(Matrica.at(i).size() - 1 - j);
			Horizontalna.at(i).push_back(temp);
		}
	//Sada isto, samo kreiramo vertikalnu matricu ulazne matrice
	std::vector<std::vector<double>> Vertikalna;
	Vertikalna.resize(Matrica.size());
	for(int i = 0; i < Matrica.size(); i++)
		for(int j = 0; j < Matrica.at(i).size(); j++){
			double temp(Matrica.at(Matrica.size() - 1 - i).at(j));
			Vertikalna.at(i).push_back(temp);
		}
	//Ovaj dio sam nazvao HorVer jer fakticki radi obje operacije iznad od jednom pa dobijamo i trecu "ogledalo" matricu
	std::vector<std::vector<double>> HorVer;
	HorVer.resize(Matrica.size());
	for(int i = 0; i < Matrica.size(); i++)
		for(int j = 0; j < Matrica.at(i).size(); j++){
			double temp(Vertikalna.at(i).at(Matrica.at(i).size() - 1 - j));
			HorVer.at(i).push_back(temp);
		}
	//Sustina dijela ispod je sljedeca:
	//Kreiramo matricu koju cemo vratiti iz funkcije
	//Sve petlje ispod sluze da bukvalno kreiraju priveremeni vektor koji je popunjen sa
	//elementima prvog reda horizontalne, vertikalne i horver matrice i nakon toga taj 
	//vektor stavljamo kao prvi red povratne matrice(vektora vektora) i tako i za drugi red
	//i za svaki red do 3 * red ulazne matrice.
	std::vector<std::vector<double>> Povratna;
	for(int i = 0; i < Matrica.size(); i++){
		std::vector<double> tmp;
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(HorVer.at(i).at(j));
		}
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(Vertikalna.at(i).at(j));
		}
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(HorVer.at(i).at(j));
		}
		Povratna.push_back(tmp);
	}
	
	for(int i = 0; i < Matrica.size(); i++){
		std::vector<double> tmp;
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(Horizontalna.at(i).at(j));
		}
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(Matrica.at(i).at(j));
		}
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(Horizontalna.at(i).at(j));
		}
		Povratna.push_back(tmp);
	}
	
	for(int i = 0; i < Matrica.size(); i++){
		std::vector<double> tmp;
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(HorVer.at(i).at(j));
		}
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(Vertikalna.at(i).at(j));
		}
		for(int j = 0; j < Matrica.at(i).size(); j++){
			tmp.push_back(HorVer.at(i).at(j));
		}
		Povratna.push_back(tmp);
	}
	
	return Povratna;
}

int main ()
{	
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin >> m >> n;
	if(m < 0 || n < 0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	//Unos matrice
	std::vector<std::vector<double>> Matrica;
	Matrica.resize(m);
	for(int i = 0; i < Matrica.size(); i++)
	Matrica.at(i).resize(n);
	std::cout << "Unesite elemente matrice: ";
	for(int i = 0; i < Matrica.size(); i++){
		for(int j = 0; j < Matrica.at(i).size(); j++){
			double tmp;
			std::cin >> tmp;
			Matrica.at(i).at(j) = tmp;
		}
	}
	
	std::vector<std::vector<double>> Povratna;
	Povratna = OgledaloMatrica(Matrica);
	
	try{
	std::cout << "\nRezultantna matrica: \n";
	for(int i = 0; i < Povratna.size(); i++){
		for(int j = 0; j < Povratna.at(i).size(); j++){
			std::cout << std::setw(4) << std::setprecision(12) << Povratna.at(i).at(j);
			}
		std::cout << std::endl;
		}
	}
	
	catch(std::domain_error trash){
		std::cout << trash.what() << std::endl;
	}
	
	return 0;
}
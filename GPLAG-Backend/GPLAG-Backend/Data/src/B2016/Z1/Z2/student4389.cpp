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

typedef std::vector<std::vector <double>> Matrica;

Matrica KreirajMatricu(int a, int b){					//Funkcija sa predavanja za kreiranje matrice
	return Matrica(a, std::vector<double> (b, 0));
}

Matrica VertikalnoOgledalo (Matrica matrica){
	double temp(0);
	for(int i=0; i<matrica.size()/2; i++){
		for(int j=0; j<matrica[0].size(); j++){
			temp = matrica.at(i).at(j);
			matrica.at(i).at(j) = matrica.at(matrica.size()-i-1).at(j);
			matrica.at(matrica.size()-i-1).at(j) = temp;
		}
	}
	return matrica;
}

Matrica HorizontalnoOgledalo (Matrica matrica){
	double temp(0);
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[0].size()/2; j++){
			temp = matrica.at(i).at(j);
			matrica.at(i).at(j) = matrica.at(i).at(matrica[0].size()-j-1);
			matrica.at(i).at(matrica[0].size()-j-1) = temp;
		}
	}
	return matrica;
}

/*Matrica HorizontalnoVertikalnoOgledalo (Matrica matrica){
	double temp(0);
	int duzina;
	if(matrica.size()%2==0) duzina=matrica.size()/2;
	else duzina=(matrica.size()/2)+1;
	for(int i=0; i<duzina; i++){
		for(int j=0; j<matrica[0].size(); j++){
			std::cout << i<<" "<<j<< std::endl;
			temp = matrica.at(i).at(j);
			matrica.at(i).at(j) = matrica.at(matrica.size()-i-1).at(matrica[0].size()-j-1);
			matrica.at(matrica.size()-i-1).at(matrica[0].size()-j-1) = temp;
		}
	}
	return matrica;
}*/

Matrica HorizontalnoVertikalnoOgledalo (Matrica matrica){
	matrica = HorizontalnoOgledalo(matrica);
	matrica = VertikalnoOgledalo(matrica);
	return matrica;
}

void GrbavaCheck(Matrica matrica){
	for(int i=0; i< matrica.size(); i++){
		if(matrica.at(i).size()!=matrica[0].size()) throw std::domain_error("Matrica nije korektna");
	}
}


Matrica OgledaloMatrica (Matrica orig_matrica){															//Funkcija kreira novu matricu kojoj je broj
	GrbavaCheck(orig_matrica);
	if(orig_matrica.size()==0) return orig_matrica;
	Matrica matrica(KreirajMatricu(orig_matrica.size()*3, orig_matrica[0].size()*3));
	Matrica temp_matrica(KreirajMatricu(orig_matrica.size(), orig_matrica[0].size()));
	for(int i=0; i<orig_matrica.size(); i++){
		for(int j=0; j<orig_matrica[0].size(); j++){
			matrica.at(orig_matrica.size() + i).at(orig_matrica[0].size() + j) = orig_matrica.at(i).at(j);
		}
	}
	temp_matrica = VertikalnoOgledalo(orig_matrica);
	for(int i=0; i<orig_matrica.size(); i++){
		for(int j=0; j<orig_matrica[0].size(); j++){
			matrica.at(i).at(orig_matrica[0].size() + j) = temp_matrica.at(i).at(j);
			matrica.at((2*orig_matrica.size())+i).at(orig_matrica[0].size() + j) = temp_matrica.at(i).at(j);
		}
	}
	temp_matrica = HorizontalnoOgledalo(orig_matrica);
	for(int i=0; i<orig_matrica.size(); i++){
		for(int j=0; j<orig_matrica[0].size(); j++){
			matrica.at(orig_matrica.size() + i).at(j) = temp_matrica.at(i).at(j);
			matrica.at(orig_matrica.size() + i).at((2*orig_matrica[0].size()) + j) = temp_matrica.at(i).at(j);
		}
	}
	if(orig_matrica.size() == 1)
		temp_matrica = HorizontalnoOgledalo(orig_matrica);
	else
		temp_matrica = HorizontalnoVertikalnoOgledalo(orig_matrica);
	for(int i=0; i<orig_matrica.size(); i++){
		for(int j=0; j<orig_matrica[0].size(); j++){
			matrica.at(i).at(j) = temp_matrica.at(i).at(j);
			matrica.at((2*orig_matrica.size()) + i).at(j) = temp_matrica.at(i).at(j);
			matrica.at(i).at((2*orig_matrica[0].size()) + j) = temp_matrica.at(i).at(j);
			matrica.at((2*orig_matrica.size()) + i).at((2*orig_matrica[0].size()) + j) = temp_matrica.at(i).at(j);
		}
	}
	return matrica;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 1;
	}
	std::cout << "Unesite elemente matrice:" << std::endl;
	Matrica matrica(KreirajMatricu(m, n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrica.at(i).at(j);
		}
	}
	std::cout << "Rezultantna matrica:" << std::endl;
	try{
		matrica = OgledaloMatrica(matrica);
	}catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	for(int i = 0; i<matrica.size(); i++){
		for(int j = 0; j<matrica[0].size(); j++){
			std::cout << std::setw(4) << matrica.at(i).at(j);
		}
		std::cout << std::endl;
	}
	/*Matrica matrica{{123, 321},{-12,0},{456, -7}};
	matrica=HorizontalnoVertikalnoOgledalo(matrica);
		for(int i = 0; i<matrica.size(); i++){
			for(int j = 0; j<matrica[0].size(); j++){
				std::cout << matrica[i][j]<<" ";
			}
		std::cout << std::endl;
	}*/
	return 0;
	
}
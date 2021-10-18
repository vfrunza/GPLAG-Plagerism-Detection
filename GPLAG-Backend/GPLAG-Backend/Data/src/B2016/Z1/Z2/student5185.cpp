#include <iostream>
#include <vector>
#include <iomanip>


std::vector<std::vector<double>> HorizontalnoOgledalo(std::vector<std::vector<double>> Matrica){
	for (int i = 0; i < Matrica.size(); i++) {
		for (int j = 0; j < Matrica[i].size()/2; j++) {
			double temp{Matrica[i][Matrica[i].size() - 1 - j]};
			Matrica[i][Matrica[i].size() - 1 - j] = Matrica[i][j];
			Matrica[i][j] = temp;
		}
	}
	return Matrica;
}

std::vector<std::vector<double>> VertikalnoOgledalo (std::vector<std::vector<double>> Matrica){
	
	for (int i = 0; i < Matrica.size()/2; i++) {
		std::vector<double> temp{Matrica[i]};
		Matrica[i] = Matrica[Matrica.size()-1-i];
		Matrica[Matrica.size()-1-i] = temp;
	}
	
	return Matrica;
}

std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> Matrica){
	if (Matrica.size() == 0) {
		return Matrica;
	}
	

	//Predpostavka da nije grbava
	std::vector<std::vector<double>> SuperMatrica (3*Matrica.size(), std::vector<double> (Matrica[0].size()*3));
	
	
	//Super matrica kreirana
	
	// Neophodne matrice
	std::vector<std::vector<double>> VOMatrica = VertikalnoOgledalo(Matrica);
	std::vector<std::vector<double>> HOMatrica = HorizontalnoOgledalo(Matrica);
	std::vector<std::vector<double>> HVOMatrica = VertikalnoOgledalo(HOMatrica);
	//
	
	{
	int k{0}, l{0};
	
	//Ispis lijeve horizontalne
	k=0;
	for (int i = SuperMatrica.size()/3; i < 2 * (SuperMatrica.size()/3) ; i++) {
		l = 0;
		for (int j = 0; j < SuperMatrica[i].size() / 3; j++) {
			SuperMatrica[i][j] = HOMatrica[k][l];
			l++;
		}
		k++;
	}	
	
	//Desna horizontala
	k=0;
	for (int i = SuperMatrica.size()/3; i < 2 * (SuperMatrica.size()/3) ; i++) {
		l = 0;
		for (int j = 2* SuperMatrica[i].size() / 3; j < SuperMatrica[i].size(); j++) {
			SuperMatrica[i][j] = HOMatrica[k][l];
			l++;
		}
		k++;
	}
		
	//Ispis gornje vertikalne
	k=0;
	for (int i = 0; i < SuperMatrica.size()/3; i++) {
		l = 0;
		for (int j = SuperMatrica[i].size()/3; j < 2* SuperMatrica[i].size() / 3; j++) {
			SuperMatrica[i][j] = VOMatrica[k][l];
			l++;
		}
		k++;
	}
	
	//Ispis donje vertikalne
	k=0;
	for (int i = 2 * (SuperMatrica.size()/3); i < SuperMatrica.size(); i++) {
		l = 0;
		for (int j = SuperMatrica[i].size()/3; j < 2* SuperMatrica[i].size() / 3; j++) {
			SuperMatrica[i][j] = VOMatrica[k][l];
			l++;
		}
		k++;
	}
	
	// Ispis matrice u centar
	k=0;
	for (int i = SuperMatrica.size()/3; i < 2 * (SuperMatrica.size()/3) ; i++) {
		l = 0;
		for (int j = SuperMatrica[i].size()/3; j < 2* SuperMatrica[i].size() / 3; j++) {
			SuperMatrica[i][j] = Matrica[k][l];
			l++;
		}
		k++;
	}
	
	//Gornji lijevi kutat
	k=0;
	for (int i = 0; i < SuperMatrica.size()/3; i++) {
		l = 0;
		for (int j = 0; j < SuperMatrica[i].size() / 3; j++) {
			SuperMatrica[i][j] = HVOMatrica[k][l];
			l++;
		}
		k++;
	}
	
	//Donji lijevi
	k=0;
	for (int i = 2*SuperMatrica.size()/3; i < SuperMatrica.size(); i++) {
		l = 0;
		for (int j = 0; j < SuperMatrica[i].size() / 3; j++) {
			SuperMatrica[i][j] = HVOMatrica[k][l];
			l++;
		}
		k++;
	}
	
	//Gornji desni
	k=0;
	for (int i = 0; i < SuperMatrica.size()/3; i++) {
		l = 0;
		for (int j = 2*SuperMatrica[i].size() / 3; j < SuperMatrica[i].size(); j++) {
			SuperMatrica[i][j] = HVOMatrica[k][l];
			l++;
		}
		k++;
	}
	
	//Donji desni
	k=0;
	for (int i = 2*SuperMatrica.size()/3; i < SuperMatrica.size(); i++) {
		l = 0;
		for (int j = 2*SuperMatrica[i].size() / 3; j < SuperMatrica[i].size(); j++) {
			SuperMatrica[i][j] = HVOMatrica[k][l];
			l++;
		}
		k++;
	}
	
	
	
		
	} //Blok za srednji dio progra
	
	
	
	
	return SuperMatrica;
}

int main (){
	
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if (m<0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	

	std::cout << "Unesite elemente matrice:";
	std::vector<std::vector<double>> Matrica(m, std::vector<double> (n));
	
	for (int i = 0; i < Matrica.size(); i++) {
		for (int j = 0; j < Matrica[i].size(); j++) {
			std::cin >> Matrica[i][j];
		}
	}
	
	Matrica = OgledaloMatrica(Matrica);
	
	std::cout << std::endl << "Rezultantna matrica:" << std::endl;
	
	
	for (int i = 0; i < Matrica.size(); i++) {
		std::cout << " ";
		for (int j = 0; j < Matrica[i].size(); j++) {
			std::cout << std::setw(3) << Matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
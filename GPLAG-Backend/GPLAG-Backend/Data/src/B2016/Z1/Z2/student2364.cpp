#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

std::vector <double> DajVektor(std::vector <double> a, std::vector <double> b,std::vector<double> h){
	
	std::vector <double> c;
	
	for(double x : a)c.push_back(x);                                                                    // Kreiramo vektor ciji su elementi redom svi clanovi prvog, drugog i treceg
	for(double x : b)c.push_back(x);                                                                    // vektora dodjeljenog funkciji
	for(double x : h)c.push_back(x);
	
	return c;
}

Matrica KreirajMatricu(int redovi, int kolone){
	return Matrica(redovi, std::vector<double>(kolone));
}

int broj_r(Matrica M){
	return M.size();
}

int broj_k(Matrica M){
	return M[0].size();
}

Matrica UnesiMatricu(int redovi, int kolone){
	Matrica M(KreirajMatricu(redovi, kolone));
	
	std::cout << "Unesite elemente matrice: ";
	
	for(int i(0); i < redovi; i++)
		for(int j(0); j < kolone; j++)
			std::cin >> M.at(i).at(j);
			
	return M;
}

void IspisiMatricu(Matrica M){
	
	std::cout << std::endl << "Rezultantna matrica: " << std::endl;
	for(int i(0); i < broj_r(M); i++){
		for(int j(0); j < broj_k(M); j++){
			std::cout << std::setw(4) << M.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

Matrica Vertikala(Matrica M){
	Matrica K(M);
	std::vector <double> pomocni;                                                                // Okrecemo redoslijed elemenata matrice
	
	for(int i(0); i < broj_r(M)/2; i++){
		pomocni = K.at(i);
		K.at(i) = K.at(broj_r(M)-1-i);
		K.at(broj_r(M)-1-i) = pomocni;
	}
	
	return K;
}

Matrica Horizontala(Matrica M){                                                                       
	Matrica K(KreirajMatricu(broj_r(M), 0));                                                          
	                                                                                              // Mogli smo i sa std::reverse da okrenemo elemente matrice...
	for(int i(0); i < broj_r(M); i++){
		for(int j(0); j < broj_k(M); j++){
			K.at(i).push_back(M.at(i).at(broj_k(M) - 1 -j));
		}
	}

	return K;
}

Matrica HorizontalaVertikala(Matrica M){
	Matrica K(KreirajMatricu(broj_r(M), 0));
	
	for(int i(0); i < broj_r(M); i++){
		for(int j(0); j < broj_k(M); j++){
			K.at(i).push_back( M.at(broj_r(M) - 1 - i).at(broj_k(M) - 1 -j));
		}
	}
	return K;
}

Matrica OgledaloMatrica(Matrica M){
	                                                                           
	for(int i(0); i < broj_r(M); i++){                                                         // Provjeravamo da li su sve kolone matrice imaju isto elemenata, ty provjeravamo
		for(int j(i+1); j < broj_r(M); j++){                                                   // da li je funkciji dodjeljena grbava matrica
   			if(M.at(i).size() != M.at(j).size())
				throw std::domain_error("Matrica nije korektna");
		}
	}
	
	Matrica H(M);
	Matrica Konacna(KreirajMatricu(3*broj_r(M), 0));
	Matrica A(Vertikala(M));
	Matrica B(Horizontala(M));
	Matrica C(HorizontalaVertikala(M));
	
	int redovi = broj_r(M);
	
	for(int i(0); i < redovi; i++){
		Konacna.at(i) = std::move(DajVektor(C.at(i) , A.at(i), C.at(i)));
	}
	                                                                                          // Sastavljamo konacnu matricu dimenzija 3*m * 3*n
	int index(0);
	for(int i(redovi); i < 2*redovi; i++){
		Konacna.at(i) = std::move(DajVektor(B.at(index), M.at(index), B.at(index)));
		index++;
	}
	
	index = 0;
	
	for(int i(2*redovi); i < 3*redovi; i++){
		Konacna.at(i) = std::move(DajVektor(C.at(index), A.at(index), C.at(index)));
		index ++;
	}
	
	return Konacna;
}


int main(){
	
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if(m < 0 || n < 0)
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		else{
			try{
			Matrica M(UnesiMatricu(m, n));
			Matrica K(OgledaloMatrica(M));
				IspisiMatricu(K);
			}
			catch(std::domain_error izuzetak){
				std::cout << izuzetak.what();
			}
			
		}
	return 0;
}
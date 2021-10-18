/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double> (br_kolona));
}

int BrojRedova(Matrica m){
	return m.size();
}

int BrojKolona(Matrica m){
	if (BrojRedova(m) == 0) return 0;
	return m[0].size();
}

// Horizontalno ogledalo
Matrica h(Matrica mat){
	int br_redova(BrojRedova(mat));
	int br_kolona(BrojKolona(mat));
	Matrica m(KreirajMatricu(br_redova, br_kolona));
	
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			m[i][j] = mat[i][br_kolona-1-j];
		}
	}
	return m;
}

// Vertikalno ogledalo
Matrica v(Matrica mat){
	int br_redova(BrojRedova(mat));
	int br_kolona(BrojKolona(mat));
	Matrica m(KreirajMatricu(br_redova, br_kolona));
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			m[i][j] = mat[br_redova-i-1][j];
		}
	}
	return m;
}

// Kombinovana ogledala
Matrica hv(Matrica mat){
	int br_redova(BrojRedova(mat));
	int br_kolona(BrojKolona(mat));
	Matrica m(KreirajMatricu(br_redova, br_kolona));
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			m[i][j] = mat[br_redova-i-1][br_kolona-j-1];
		}
	}
	return m; 
}

Matrica OgledaloMatrica(Matrica mat){
	int br_redova(BrojRedova(mat));
	int br_kolona(BrojKolona(mat));
	
	for(int i=1; i<br_redova; i++){
		if(br_kolona != mat[i].size()) {
			throw std::domain_error("Matrica nije korektna");
		}
	}
	
	// Horizontalno ogledalo
	Matrica m1(h(mat));
	
	// Vertikalo ogledalo
	Matrica m2(v(mat));
	
	// Kombinovano ogledalo
	Matrica m3(hv(mat));
	
	// Kreiranje povratne matrice
	Matrica matrica(KreirajMatricu(3*br_redova, 3*br_kolona));
	
	//Prva kolona
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			matrica[i][j] = m3[i][j];
		}
	}
	for(int i=br_redova; i< 2*br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			matrica[i][j] = m1[i-br_redova][j];
		}
	}
	for(int i= 2*br_redova; i< 3*br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			matrica[i][j] = m3[i-2*br_redova][j];
		}
	}
	
	//Druga kolona
	for(int i=0; i<br_redova; i++){
		for(int j=br_kolona; j<2*br_kolona; j++){
			matrica[i][j] = m2[i][j-br_kolona];
		}
	}
	for(int i=br_redova; i<2*br_redova; i++){
		for(int j=br_kolona; j<2*br_kolona; j++){
			matrica[i][j] = mat[i-br_redova][j-br_kolona];
		}
	}
	for(int i=2*br_redova; i<3*br_redova; i++){
		for(int j=br_kolona; j<2*br_kolona; j++){
			matrica[i][j] = m2[i-2*br_redova][j-br_kolona];
		}
	}
	
	//Treca kolona
	for(int i=0; i<br_redova; i++){
		for(int j=2*br_kolona; j<3*br_kolona; j++){
			matrica[i][j] = m3[i][j-2*br_kolona];
		}
	}
	for(int i=br_redova; i< 2*br_redova; i++){
		for(int j=2*br_kolona; j<3*br_kolona; j++){
			matrica[i][j] = m1[i-br_redova][j-2*br_kolona];
		}
	}
	for(int i=2*br_redova; i< 3*br_redova; i++){
		for(int j=2*br_kolona; j<3*br_kolona; j++){
			matrica[i][j] = m3[i-2*br_redova][j-2*br_kolona];
		}
	}
	return matrica;
}

// Ispis matrice
void IspisiMatricu(Matrica matrica){
	for(int i=0; i<BrojRedova(matrica); i++){
		for(int j=0; j<BrojKolona(matrica); j++){
			std::cout << std::setw(4) << matrica[i][j];
		}
		std::cout << std::endl;
	}
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin >> m >> n;
	
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
	}else{
		
	Matrica mat(KreirajMatricu(m, n));
	std::cout << "Unesite elemente matrice: " << std::endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin >> mat[i][j];
		}
	}
	
	std::cout << "Rezultantna matrica: " << std::endl;
	try{
   		IspisiMatricu(OgledaloMatrica(mat));
	}catch(std::domain_error izuzetak){
		std::cout << izuzetak.what();
	}
	
	}
	return 0;
}
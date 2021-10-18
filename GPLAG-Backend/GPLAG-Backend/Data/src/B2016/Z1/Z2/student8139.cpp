#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

int BrojRedova(Matrica m){
	return m.size();
}

int BrojKolona(Matrica m){
	if(m.size()==0) return 0;
	return m[0].size();
}

Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++) std::cin >> m[i][j];
	}
	return m;
}

bool DaLiJeGrbava(Matrica m){
	int broj_redova=BrojKolona(m);
	for(int i=1; i<BrojRedova(m); i++){
		if(m[i].size()!=broj_redova) return true;
	}
	return false;
}

void IspisiMatricu(Matrica m){
	for(int i=0; i<BrojRedova(m); i++){
		for(int j=0; j<BrojKolona(m); j++) std::cout << std::setw(4) << m[i][j];
		std::cout << std::endl;
	}
}

Matrica ObrniVertikalno(Matrica m){
	auto vert(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	for(int i=0; i<BrojRedova(m); i++) vert[BrojRedova(m)-i-1]=m[i];
	return vert;
}

Matrica ObrniHorizontalno(Matrica m){
	auto hor(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	for(int i=0; i<BrojRedova(m); i++){
		for(int j=0; j<BrojKolona(m); j++) hor[i][BrojKolona(m)-j-1]=m[i][j];
	}
	return hor;
}

Matrica ObrniKombinovano(Matrica m){
	auto komb(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	komb=ObrniVertikalno(m);
	komb=ObrniHorizontalno(komb);
	return komb;
}

Matrica OgledaloMatrica(Matrica m){
	auto rezultantna(KreirajMatricu(3*BrojRedova(m),3*BrojKolona(m)));
	if(DaLiJeGrbava(m)) throw std::domain_error("Matrica nije korektna");
	for(int i=0; i<BrojRedova(m); i++){
		for(int j=0; j<BrojKolona(m); j++){
			rezultantna[i][j]=ObrniKombinovano(m)[i][j];
			rezultantna[i][BrojKolona(m)+j]=ObrniVertikalno(m)[i][j];
			rezultantna[i][2*BrojKolona(m)+j]=ObrniKombinovano(m)[i][j];
			rezultantna[BrojRedova(m)+i][j]=ObrniHorizontalno(m)[i][j];
			rezultantna[BrojRedova(m)+i][BrojKolona(m)+j]=m[i][j];
			rezultantna[BrojRedova(m)+i][2*BrojKolona(m)+j]=ObrniHorizontalno(m)[i][j];
			rezultantna[2*BrojRedova(m)+i][j]=ObrniKombinovano(m)[i][j];
			rezultantna[2*BrojRedova(m)+i][BrojKolona(m)+j]=ObrniVertikalno(m)[i][j];
			rezultantna[2*BrojRedova(m)+i][2*BrojKolona(m)+j]=ObrniKombinovano(m)[i][j];
		}
	}
	return rezultantna;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0){ 
		std::cout << "Dimenzije matrice moraju biti nenegativne!" ;
		return 0;
	}
	std::cout << "Unesite elemente matrice: \n";
	auto A(UnesiMatricu(m,n));
	try{
		auto velika(OgledaloMatrica(A));
		std::cout << "Rezultantna matrica: \n";
		IspisiMatricu(velika);
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	
	return 0;
}
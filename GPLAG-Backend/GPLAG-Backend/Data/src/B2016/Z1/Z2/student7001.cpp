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

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova, int broj_kolona) {
	if (broj_redova<0 || broj_kolona<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

bool GrbavaIliNe(Matrica m) {
	for (int i=1; i<m.size(); i++)
		if (m[0].size()!=m[i].size()) return true;
	return false;
}

Matrica HorizontalnoOgledalo(Matrica izvorna_matrica) {
	Matrica horizontalno_ogledalo(KreirajMatricu(izvorna_matrica.size(), izvorna_matrica[0].size()));
	for (int i=0; i<izvorna_matrica.size(); i++) {
		int k{};
		for (int j=izvorna_matrica[i].size()-1; j>=0; j--) {
			horizontalno_ogledalo[i][k]=izvorna_matrica[i][j];
			k++;
		}
	}
	return horizontalno_ogledalo;
}

Matrica VertikalnoOgledalo(Matrica izvorna_matrica) {
	Matrica vertikalno_ogledalo(KreirajMatricu(izvorna_matrica.size(), izvorna_matrica[0].size()));
	int k{};
	for (int i=izvorna_matrica.size()-1; i>=0; i--) {
		for (int j=0; j<izvorna_matrica[i].size(); j++)
			vertikalno_ogledalo[k][j]=izvorna_matrica[i][j];
		k++;
	}
	return vertikalno_ogledalo;
}

Matrica KombinovanoOgledalo(Matrica izvorna_matrica) {
	Matrica kombinovano_ogledalo(KreirajMatricu(izvorna_matrica.size(), izvorna_matrica[0].size()));
	int k1{};
	for (int i=izvorna_matrica.size()-1; i>=0; i--) {
		int k2{};
		for (int j=izvorna_matrica[i].size()-1; j>=0; j--) {
			kombinovano_ogledalo[k1][k2]=izvorna_matrica[i][j];
			k2++;
		}
		k1++;
	}
	return kombinovano_ogledalo;
}

Matrica OgledaloMatrica(Matrica izvorna_matrica) {
	if (izvorna_matrica.size()==0) return izvorna_matrica;
	else if (GrbavaIliNe(izvorna_matrica)) throw std::domain_error("Matrica nije korektna");
	Matrica horizontalno_ogledalo(HorizontalnoOgledalo(izvorna_matrica));
	Matrica vertikalno_ogledalo(VertikalnoOgledalo(izvorna_matrica));
	Matrica kombinovano_ogledalo(KombinovanoOgledalo(izvorna_matrica));
	Matrica ogledalo_matrica(KreirajMatricu(izvorna_matrica.size()*3, izvorna_matrica[0].size()*3));
	for (int i=0; i<izvorna_matrica.size(); i++) {
		int k{};
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=kombinovano_ogledalo[i][j];
			k++;
		}
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=vertikalno_ogledalo[i][j];
			k++;
		}
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=kombinovano_ogledalo[i][j];
			k++;
		}
	}
	int k1{};
	for (int i=izvorna_matrica.size(); i<izvorna_matrica.size()*2; i++) {
		int k{};
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=horizontalno_ogledalo[k1][j];
			k++;
		}
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=izvorna_matrica[k1][j];
			k++;
		}
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=horizontalno_ogledalo[k1][j];
			k++;
		}
		k1++;
	}
	k1=0;
	for (int i=izvorna_matrica.size()*2; i<izvorna_matrica.size()*3; i++) {
		int k{};
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=kombinovano_ogledalo[k1][j];
			k++;
		}
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=vertikalno_ogledalo[k1][j];
			k++;
		}
		for (int j=0; j<izvorna_matrica[0].size(); j++) {
			ogledalo_matrica[i][k]=kombinovano_ogledalo[k1][j];
			k++;
		}
		k1++;
	}
	return ogledalo_matrica;
}

int main() {
	try {
		int broj_redova, broj_kolona;
		std::cout << "Unesite dimenzije matrice (m n): ";
		std::cin >> broj_redova >> broj_kolona;
		Matrica m(KreirajMatricu(broj_redova,broj_kolona));
		std::cout << "Unesite elemente matrice: ";
		for (int i=0; i<broj_redova; i++)
			for (int j=0; j<broj_kolona; j++)
				std::cin >> m[i][j];
		m=OgledaloMatrica(m);
		std::cout << std::endl << "Rezultantna matrica: " << std::endl;
		for (int i=0; i<m.size(); i++) {
			for (int j=0; j<m[0].size(); j++)
				std::cout << std::setw(4) << m[i][j];
		std::cout << std::endl;
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}
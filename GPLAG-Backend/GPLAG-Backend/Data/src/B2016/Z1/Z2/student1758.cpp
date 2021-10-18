/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>> HorizontalnoOgledalo (std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> nova(matrica.size(), std::vector<double> (matrica[0].size()));
	int s(0);
	for(int i(0); i<matrica.size(); i++) {
		s=0;
		for(int j(matrica[i].size()-1); j>=0; j--) {
			nova[i][s++]=matrica[i][j];
		}
	}
	return nova;
}

std::vector<std::vector<double>> VertikalnoOgledalo (std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> nova(matrica.size(), std::vector<double> (matrica[0].size()));
	int k(0);
	for(int i(matrica.size()-1); i>=0; i--) {
		for(int j(0); j<matrica[i].size(); j++) {
			nova[k][j]=matrica[i][j];
			
		}
		k++;
	}
	return nova;
}

std::vector<std::vector<double>> KombinovanoOgledalo (std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> nova(matrica.size(), std::vector<double> (matrica[0].size()));
	int k(0), s(0);
	for(int i(matrica.size()-1); i>=0; i--) {
		s=0;
		for(int j(matrica[i].size()-1); j>=0; j--) {
			nova[k][s]=matrica[i][j];
			s++;
		}
		k++;
	}
	return nova;
}

int koordinate (int i, int j, std::vector<std::vector<double>> matrica) {
	//m -0, hv - 1, h - 2, v - 3
	if(i==matrica.size() && j==matrica[0].size()) return 0;
	else if((i==0 || i==matrica.size()*2) && (j==0 || j==matrica[0].size()*2)) return 1;
	else if(i==matrica.size() && (j==0 || j==matrica[0].size()*2)) return 2;
	else if((i==0 || i==matrica.size()*2) && j==matrica[0].size()) return 3;
	return 5;
}

std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> M) {
	for(int j(0); j<M.size(); j++) {
		if(M[0].size()!= M[j].size()) {
			throw std::domain_error("Matrica nije korektna!");
		}	
	}
	std::vector<std::vector<double>> nova;
	if(M.size()==0) {
		nova=std::vector<std::vector<double>>(0, std::vector<double>(0));
		return nova;
	}
	else if(M[0].size()==0) {
		nova=std::vector<std::vector<double>>(3*M.size(), std::vector<double>(0));
		return nova;
	}
	nova=std::vector<std::vector<double>>(3*M.size(), std::vector<double> (3*M[0].size()));

	auto komb(KombinovanoOgledalo(M));
	auto hori(HorizontalnoOgledalo(M));
	auto vert(VertikalnoOgledalo(M));
	int k(0), s(0);
	for(int i(0); i<nova.size(); i+=M.size()) {
		for(int j(0); j<nova[i].size(); j+=M[0].size()) {
			int odredi_koja(koordinate(i, j, M));
			if(odredi_koja==0) {
				for(k=0; k<M.size(); k++) {
					for(s=0; s<M[k].size(); s++) {
						nova[i+k][j+s]=M[k][s];
					}
				}
			}
			else if(odredi_koja==1) {
				for(k=0; k<komb.size(); k++) {
					for(s=0; s<komb[k].size(); s++) {
						nova[i+k][j+s]=komb[k][s];
					}
				}
			}
			else if(odredi_koja==2) {
				for(k=0; k<hori.size(); k++) {
					for(s=0; s<hori[k].size(); s++) {
						nova[i+k][j+s]=hori[k][s];
					}
				}
			}
			else if(odredi_koja==3) {
				for(k=0; k<vert.size(); k++) {
					for(s=0; s<vert[k].size(); s++) {
						nova[i+k][j+s]=vert[k][s];
					}
				}
			}
		}
	}
	return nova;
}

void Ispisi (std::vector<std::vector<double>> matrica) {
	std::cout << std::endl;
	for(int i(0); i<matrica.size(); i++ ) {
		for(int j(0); j<matrica[i].size(); j++) {
			std::cout << std::setw(4) << matrica[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main () {
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(!std::cin) {
		std::cout << "Nisu uneseni brojevi!" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return 0;
	}
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	std::cout << "Unesite elemente matrice:";
	std::vector<std::vector<double>> M(m, std::vector<double> (n));
	for(int i(0); i<m; i++) {
		for(int j(0); j<n; j++) {
			std::cin >> M[i][j];
		}
	}
	try {
		auto ogledalo(OgledaloMatrica(M));
		std::cout << std::endl << "Rezultantna matrica: ";
		Ispisi(ogledalo);
	}
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}
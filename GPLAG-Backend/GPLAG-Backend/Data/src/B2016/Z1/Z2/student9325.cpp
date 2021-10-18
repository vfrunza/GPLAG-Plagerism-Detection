#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica sastavi(std::vector<double> v, int m, int n) {
	Matrica sastavljena(m, std::vector<double>(n));
	int pozicija = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			sastavljena[i][j] = v[pozicija];
			pozicija++;
		}
	}
	return sastavljena;
}

Matrica h(Matrica centar) {
	std::vector<double> pomocni;
	
	for(int i = 0; i < centar.size(); i++) {
		for(int j = centar[0].size() - 1; j >= 0; j--) {
			pomocni.push_back(centar[i][j]);
		}
	}
	if(centar.size() == 0) {
		return sastavi(pomocni, centar.size(),0);
	}
	return sastavi(pomocni, centar.size(), centar[0].size());
}
Matrica v(Matrica centar) {
	std::vector<double> pomocni;
	
	for(int i = centar.size() - 1; i >= 0; i--) {
		for(int j = 0; j < centar[0].size(); j++) {
			pomocni.push_back(centar[i][j]);
		}
	}
	if(centar.size() == 0) {
		return sastavi(pomocni, centar.size(),0);
	}
	return sastavi(pomocni, centar.size(), centar[0].size());
}
Matrica hv(Matrica centar) {
	std::vector<double> pomocni;
	
	for(int i = centar.size() - 1; i >= 0; i--) {
		for(int j = centar[0].size() - 1; j >= 0; j--) {
			pomocni.push_back(centar[i][j]);
		}
	}
	if(centar.size() == 0) {
		return sastavi(pomocni, centar.size(),0);
	}
	return sastavi(pomocni, centar.size(), centar[0].size());
}

bool DaLiJeGrbava(Matrica centar) {
	std::vector<double> v;
	for(int i = 0; i < centar.size(); i++) {
		v.push_back(centar[i].size());
	}
	
	for(int i = 0; i < v.size(); i++) {
		for(int j = i + 1; j < v.size(); j++) {
			if(v[i] != v[j]) return true;
		}
	}
	return false;
}

Matrica OgledaloMatrica(Matrica centar) {
	if(DaLiJeGrbava(centar)) throw std::domain_error("Matrica nije korektna");
	
	int m = centar.size();
	int n;
	
	if(m == 0) {
		n = 0;
	} else n = centar[0].size();
	
	Matrica ogledalo(3*m, std::vector<double>(3*n)); 
	//int pozicija = 0;
	
	auto _hv = hv(centar);
	auto _h = h(centar);
	auto _v = v(centar);
	
	// G - gornja, S - srednja, D - dona
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			// I kolona
			// G
			if(i == 0 && j == 0) {
				for(int k = 0; k < m; k++) {
					for(int t = 0; t < n; t++) {
						ogledalo[k][t] = _hv[k][t];
					}
				}
			}
			// S
			if(i == 1 && j == 0) {
				for(int k = m, k1=0; k < 2 * m; k++, k1++) {
					for(int t = 0; t < n; t++) {
						ogledalo[k][t] = _h[k1][t];
					}
				}
			}
			// D
			if(i == 2 && j == 0) {
				for(int k = 2 * m, k1 = 0; k < 3 * m; k++, k1++) {
					for(int t = 0; t < n; t++) {
						ogledalo[k][t] = _hv[k1][t];
					}
				}
			}
			
			// II kolona
			// G
			if(i == 0 && j == 1) {
				for(int k = 0, k1 = 0; k < m; k++, k1++) {
					for(int t = n, t1 = 0; t < 2 * n; t++, t1++) {
						ogledalo[k][t] = _v[k1][t1];
					}
				}
			}
			// S
			if(i == 1 && j == 1) {
				for(int k = m, k1 = 0; k < 2 * m; k++, k1++) {
					for(int t = n, t1 = 0; t < 2 * n; t++, t1++) {
						ogledalo[k][t] = centar[k1][t1];
					}
				}
			}
			// D
			if(i == 2 && j == 1) {
				for(int k = 2 * m, k1 = 0; k < 3 * m; k++, k1++) {
					for(int t = n, t1 = 0; t< 2 * n; t++, t1++) {
						ogledalo[k][t] = _v[k1][t1];
					}
				}
			}
			
			// III kolona
			// G
			if(i == 0 && j == 2) {
				for(int k = 0; k < m; k++) {
					for(int t = 2 * n, t1 = 0; t < 3 * n; t++, t1++) {
						ogledalo[k][t] = _hv[k][t1];
					}
				}
			}
			// S
			if(i == 1 && j == 2) {
				for(int k = m, k1 = 0; k <2 * m; k++, k1++ ) {
					for(int t = 2 * n, t1 = 0; t < 3 * n; t++, t1++) {
						ogledalo[k][t] = _h[k1][t1];
					}
				}
			}
			// D
			if(i == 2 && j == 2) {
				for(int k = 2 * m, k1 = 0; k< 3 * m; k++, k1++) {
					for(int t = 2 * n, t1 = 0; t < 3 * n; t++, t1++) {
						ogledalo[k][t] = _hv[k1][t1];
					}
				}
			}
		}
	}
	return ogledalo;
}

int main() {

	try{
		std::cout << "Unesite dimenzije matrice (m n): ";

		int br_redova, br_kolona;
		std::cin >> br_redova >> br_kolona;
		
		if(br_redova < 0 || br_kolona < 0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		
		std::cout << "Unesite elemente matrice:\n";
		
		Matrica m(br_redova, std::vector<double>(br_kolona));
		for(int i = 0; i<br_redova; i++) {
			for(int j = 0; j<br_kolona; j++) {
				std::cin >> m[i][j];
			}
		}
		
		Matrica m1 = OgledaloMatrica(m);
		
		std::cout << "Rezultantna matrica:\n";
		
		for(int i= 0; i < m1.size(); i++) {
			for(int j= 0; j < m1[0].size(); j++) {
				std::cout << std::setw(4) << m1[i][j];
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout <<"IZUZETAK: " << izuzetak.what() <<"!";
	}
	return 0;
}
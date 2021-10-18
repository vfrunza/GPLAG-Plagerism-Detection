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

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int red, int kol) {
	if(red == 0) return Matrica(0);
	return Matrica(red, std::vector<double> (kol));
}

bool GrbavaMatrica(Matrica mat) {
	for(int i=0; i<mat.size(); i++)
		if(mat[0].size() != mat[i].size()) return true;
	return false;
}

Matrica DajHorizontalno(Matrica mat) {
	Matrica h(mat.size());
	for(int i=0; i<mat.size(); i++)
		for(int j=mat[i].size()-1; j>=0; j--)
			h[i].push_back(mat[i][j]);
	return h;
}

Matrica DajVertikalno(Matrica mat) {
	Matrica v;
	for(int i=mat.size()-1; i>=0; i--)
		v.push_back(mat[i]);
	return v;
}

Matrica OgledaloMatrica(Matrica mat) {
	if(mat.size() == 0) return Matrica(0);
	if(GrbavaMatrica(mat)) throw std::domain_error ("Matrica nije korektna");
	
	Matrica M(KreirajMatricu(3*mat.size(), 3*mat[0].size()));
	if(M.size() == 0 || M[0].size() == 0) return M;
	
	Matrica h(DajHorizontalno(mat)), v(DajVertikalno(mat)), hv(DajHorizontalno(DajVertikalno(mat)));
	int red(mat.size()), kol(mat[0].size());
	for(int i=0; i<red; i++) 
		for(int j=0; j<kol; j++) {
			M[i][j] = hv[i][j];
			M[i+red][j] = h[i][j];
			M[i+2*red][j] = hv[i][j];
			
			M[i][j+kol] = v[i][j];
			M[i+red][j+kol] = mat[i][j];
			M[i+2*red][j+kol] = v[i][j];
			
			M[i][j+2*kol] = hv[i][j];
			M[i+red][j+2*kol] = h[i][j];
			M[i+2*red][j+2*kol] = hv[i][j];
		}
	return M;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat(KreirajMatricu(m, n));
	std::cout << "Unesite elemente matrice: " << std::endl;
	for(int i=0; i<mat.size(); i++) 
		for(int j=0; j<mat[i].size(); j++)
			std::cin >> mat[i][j];
	try {
		std::cout << "Rezultantna matrica: " << std::endl;
		Matrica M(OgledaloMatrica(mat));
		for(int i=0; i<M.size(); i++) {
			for(int j=0; j<M[i].size(); j++)
				std::cout << std::setw(4) << M[i][j];
			std::cout << std::endl;
		}
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}
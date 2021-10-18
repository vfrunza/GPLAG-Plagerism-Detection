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
	return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

void IspisiMatricu(Matrica m) {
	for(int i(0); i< m.size(); i++) {
		for(int j(0); j<m[0].size(); j++) 
		std::cout << std::setw(4) << m[i][j];
		std::cout << std::endl;
	}
}

Matrica Horizontalna(Matrica mat) {
	Matrica rez(KreirajMatricu(mat.size(),mat[0].size()));
	for(int i(0); i<mat.size(); i++) {
		for(int j(0); j< mat[0].size(); j++) 
		rez[i][j] = mat[mat.size()-1-i][j];
	}
	return rez;
}
std::vector<double> ObrniRed(std::vector<double> v) {
	std::vector<double> v2;
	for(int i(0); i<v.size(); i++) 
		v2.push_back(v[v.size()-1-i]);
	return v2;
}

Matrica Vertikalna(Matrica mat) {
	Matrica rez(KreirajMatricu(mat.size(),mat[0].size()));
	for(int i(0); i<mat.size(); i++) {
		rez[i] = ObrniRed(mat[i]);
	}
	return rez;
} 
Matrica Kombinovana(Matrica mat) {
	Matrica rez1(KreirajMatricu(mat.size(),mat[0].size()));
	rez1 = Horizontalna(mat);
	Matrica rez2(KreirajMatricu(mat.size(),mat[0].size()));
	rez2 = Vertikalna(rez1);
	return rez2;
}

Matrica OgledaloMatrica(Matrica mat) {
	
	for(int i(1); i<mat.size(); i++) 
		if(mat[0].size()!=mat[i].size()) throw std::domain_error("Matrica nije korektna");
	
	if(mat.empty()) return mat;
	if(mat[0].empty()) {
		Matrica prazniredovi(KreirajMatricu(3*mat.size(),3*mat[0].size()));
		return prazniredovi;
	}
	Matrica rez(KreirajMatricu(3*mat.size(),3*mat[0].size()));
	Matrica kom(KreirajMatricu(mat.size(),mat[0].size()));
	kom = Kombinovana(mat);
	Matrica hor(KreirajMatricu(mat.size(),mat[0].size()));
	hor = Horizontalna(mat);
	Matrica ver(KreirajMatricu(mat.size(),mat[0].size()));
	ver = Vertikalna(mat);
	for(int i(0); i<rez.size(); i++) {
		for(int j(0); j<rez[i].size(); j++) {
			if((j<rez[i].size()/3 || j>=(rez[i].size()-rez[i].size()/3)) && (i<rez.size()/3 || i>=(rez.size()-rez.size()/3)))
			rez[i][j]=kom[i%mat.size()][j%mat[0].size()];
			else if((i>=rez.size()/3 && i<(rez.size()-rez.size()/3)) && (j<rez[i].size()/3 || j>=(rez[i].size() - rez[i].size()/3)))
			rez[i][j]=ver[i%mat.size()][j%mat[0].size()];
			else if((j>=rez[i].size()/3 && j<(rez[i].size()-rez[i].size()/3)) && (i<rez.size()/3 || i>=(rez.size()-rez.size()/3)))
			rez[i][j]=hor[i%mat.size()][j%mat[0].size()];
			else rez[i][j]=mat[i%mat.size()][j%mat[0].size()];
		}
	}
	return rez;
} 

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	Matrica mat(KreirajMatricu(m,n));
	for(int i(0); i<m; i++) {
		for(int j(0); j<n; j++) {
			std::cin >> mat[i][j];
		}
	}
	try {
	std::cout <<std::endl<< "Rezultantna matrica: " << std::endl;
	Matrica rez(KreirajMatricu(3*m,3*n));
	rez=OgledaloMatrica(mat);
	IspisiMatricu(rez);
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}
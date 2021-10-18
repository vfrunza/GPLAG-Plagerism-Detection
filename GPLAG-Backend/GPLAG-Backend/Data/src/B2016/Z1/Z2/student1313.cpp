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

Matrica KreirajMatricu (int m, int n) {
	return Matrica (m, std::vector<double> (n));
}

int BrojRedova (Matrica mat) {
	return mat.size();
}
int BrojKolona (Matrica mat) {
	return mat[0].size();
}

Matrica UnesiMatricu (int m, int n) {
	auto mat(KreirajMatricu(m,n));
	for (int i=0; i<m; i++)
	for (int j=0; j<n; j++) {
		std::cin >> mat[i][j];
	}
return mat;
}

void IspisiMatricu (Matrica mat) {
	for (int i=0; i<BrojRedova(mat); i++) {
		for (int j=0; j<BrojKolona(mat); j++)
		 std::cout << std::setw(4) << mat[i][j];
		 std::cout << std::endl;
	}
}
Matrica ObrniRedove (Matrica mat) {
	Matrica pom;
	
	for (int i=mat.size()-1; i>=0; i--) 
	pom.push_back(mat[i]);
	
	return pom;
}

Matrica ObrniKolone (Matrica mat) {
	Matrica pom; std::vector<double> pv;
	
	for (int i=0; i<mat.size(); i++) {
		for (int j=mat[i].size()-1; j>=0; j--)
		
		pv.push_back(mat[i][j]);
		pom.push_back(pv);
		pv.resize(0);
	}
	return pom;
}

bool GrbavaMatrica (Matrica mat) {
	for (int i=0; i<mat.size(); i++) {
	if (mat[i].size()!=mat[0].size()) return true;
	}
	return false;
}
  
Matrica OgledaloMatrica (Matrica mat) {
	Matrica povratna; std::vector<double>krajnji;
	try {
	
	if (GrbavaMatrica(mat)==true) throw std::domain_error ("Matrica nije korektna.");
	auto vertikalna = ObrniRedove(mat);
	auto horizontalna = ObrniKolone(mat);
	auto kombinovana = ObrniRedove(ObrniKolone(mat));
	
	for (int i=0; i<mat.size(); i++) {
		for (auto x: kombinovana[i]) krajnji.push_back(x);
		for (auto x: vertikalna[i]) krajnji.push_back(x);
		for (auto x: kombinovana[i]) krajnji.push_back(x);
		povratna.push_back(krajnji);
		krajnji.resize(0); }
		
	for (int i=0; i<mat.size(); i++) {
		for (auto x: horizontalna[i]) krajnji.push_back(x);
		for (auto x: mat[i]) krajnji.push_back(x);
		for (auto x: horizontalna[i]) krajnji.push_back(x);
		povratna.push_back(krajnji);
		krajnji.resize(0); }
		
	for (int i=0; i<mat.size(); i++) {	
		for (auto x: kombinovana[i]) krajnji.push_back(x);
		for (auto x: vertikalna[i]) krajnji.push_back(x);
		for (auto x: kombinovana[i]) krajnji.push_back(x);
		
		povratna.push_back(krajnji);
     	krajnji.resize(0); }
    }

  catch (std::domain_error izuzetak) {
   	std::cout << izuzetak.what() << std::endl;
  }
return povratna;   
}



int main ()
{
	try {
    int m,n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if (m<0 || n<0) throw std::domain_error ("Dimenzije matrice moraju biti nenegativne!");
	
	
	std::cout << "Unesite elemente matrice: ";
	
	auto mat(UnesiMatricu(m,n));
	std::cout<<std::endl;
	
	std::cout << "Rezultantna matrica: "<< std::endl;
	IspisiMatricu(OgledaloMatrica(mat));
    }
    
    catch (std::domain_error izuzetak) {
    	std::cout << izuzetak.what() <<std::endl;
    	
    } 
  
	return 0;
}
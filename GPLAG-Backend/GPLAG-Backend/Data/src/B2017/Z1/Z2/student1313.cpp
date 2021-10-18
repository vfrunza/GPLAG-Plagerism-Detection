/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;


Matrica KreirajMatricu (int m, int n) {
	return Matrica (m, std::vector<double> (n));
}

Matrica UnesiMatricu (int m, int n) {
	auto mat (KreirajMatricu(m,n));
	for (int i(0); i<m; i++) {
		for (int j(0); j<n; j++) {
			std::cin >> mat.at(i).at(j);
		}
	}
return mat;	
}

void  IspisiMatricu (Matrica mat) {
	for (int i(0); i<mat.size(); i++) {
		for (int j(0); j<mat.at(i).size(); j++) {
			std::cout << std::setw(6) << mat.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
}

bool DaLiJePlanina (Matrica m, int px, int kx, int py, int ky) {
	double sredina, suma(0); int t(1);
	int sredx((px+kx)/2), sredy((py+ky)/2);
	sredina=m.at((px+kx)/2).at((py+ky)/2);
	do {
	for (int i(0); i<m.size(); i++) {
		for (int j(0); j<m.at(i).size(); j++)  {
			if (i-sredx>=(0-t) && i-sredx<=t && j-sredy<=t && j-sredy>=(0-t)) {
				suma+=m.at(i).at(j);
			} 
		}
	}
	suma-=sredina;
	if (sredina<suma) return false;
	sredina+=suma;
	suma=0;
	t++;
	}while (t<(kx-px)/2);
return true;
}

Matrica NajvecaPlaninaMatrice (Matrica m) {
	Matrica pom(0); std::vector<double> vek;
	int duzina(3), px, kx, py, ky;
	if (m.size()==0) return pom; 
	
	for (int i(0); i<m.size(); i++) {
		if (m.at(i).size()!=m.at(0).size()) throw std::domain_error ("Matrica nije korektna");
	}
	
	if (m.size()<3 || m.at(0).size()<3) {
		double max(0);
		for (int i(0); i<m.size(); i++) {
			for (int j(0); j<m.at(i).size(); j++) {
				if (m.at(i).at(j)>max) {
					max=m.at(i).at(j);
				}
			}
		}
		vek.push_back(max);
	    pom.push_back(vek);
	    return pom;	
	}
	
	int stara_duz(0); double vrh(0), novi_vrh(0);
	do {
	for (int i(0); i<m.size()-duzina; i++) {
		for (int j(0); j<m.at(i).size()-duzina; j++) {
			if (DaLiJePlanina(m,i,i+duzina,j,j+duzina) && duzina>=stara_duz) {
		       // novi_vrh=m.at((px+kx)/2).at((py+ky)/2);
		        //if (novi_vrh>vrh) {
				px=i; kx=i+duzina;
				py=j; ky=j+duzina;
				stara_duz=duzina;
				//vrh=novi_vrh;
		        //}
		        
			}
		}
	}
	duzina+=2;
	vrh=0;
	}while(duzina<m.size());
	
	std::vector<double> v;
	for (int i(px); i<=kx; i++) {
		for (int j(py); j<=ky; j++) {
			v.push_back(m.at(i).at(j));
		}
		pom.push_back(v);
		v.resize(0);
	}
return pom;	
}



int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		 return 0; }
	//Matrica mat;
	std::cout << "Unesite elemente matrice: ";
	auto mat(UnesiMatricu(m,n));
	//IspisiMatricu(mat);
	
	
	try {
	Matrica nova(NajvecaPlaninaMatrice(mat));
	std::cout << std::endl;
	std::cout << "Najveca planina unesene matrice je: ";
	std::cout << std::endl;
	/*for (int i(0); i<mat.size(); i++) {
		for (int j(0); j<mat.at(i).size(); j++) {
			std::cout << mat.at(i).at(j);
		}
		std::cout << std::endl;
	}
	}*/
	
	IspisiMatricu(nova);
	}
	catch (std::domain_error izuzetak) {
	std::cout << izuzetak.what();
	}
	return 0;
}
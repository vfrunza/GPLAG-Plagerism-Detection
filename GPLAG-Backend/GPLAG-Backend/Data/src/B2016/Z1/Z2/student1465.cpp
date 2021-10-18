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

//funkcija za obrtanje vektora
std::vector<double> Obrni_vektor(std::vector<double> v) {
	std::vector<double> novi;
	for(int i = v.size()-1; i >= 0; i--) {
		novi.push_back(v.at(i));
	}
	return novi;
}

//horizontalno ogledalo
Matrica horizontalno_ogledalo (Matrica A) {
	Matrica horizontalna;
	for(int i = 0; i < A.size(); i++) {
		horizontalna.push_back(Obrni_vektor(A.at(i)));
	}
	return horizontalna;
}

//vertikalno ogledalo
Matrica vertikalno_ogledalo (Matrica A) {
	Matrica vertikalna;
	for(int i = A.size()-1; i >= 0; i--) {
		vertikalna.push_back(A.at(i));
	}
	return vertikalna;
}

//glavna funkcija
Matrica OgledaloMatrica (Matrica A) {
	
	int m = A.size();
	int n;
	if (m == 0) n = 0;
	else {
		n = A.at(0).size();
		for(int i = 0; i < m; i++) {
			int vel;
			vel = A[i].size();
			if(n != vel) throw std::domain_error("Matrica nije korektna");
		}
	}
	Matrica h = horizontalno_ogledalo(A);
	Matrica v = vertikalno_ogledalo(A);
	Matrica hv = horizontalno_ogledalo(v);
	Matrica nova(3*m, std::vector<double>(3*n));
	
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A.at(0).size(); j++)
		{
			nova[m+i][n+j] = A.at(i).at(j);
			nova[m+i][j] = nova.at(m+i).at(2*n+j) = h.at(i).at(j);
			nova[i][n+j] = nova.at(2*m+i).at(n+j) = v.at(i).at(j);
			nova.at(i).at(j) = nova.at(i).at(2*n+j) = nova.at(2*m+i).at(j) = nova.at(2*m+i).at(2*n+j) = hv.at(i).at(j);
		}
	}
	return nova;
}

int main ()
{
	try {
		int m, n;
		std::cout << "Unesite dimenzije matrice (m n): ";
		std::cin >> m >> n;
		if(m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
		}
	
		Matrica pocetna(m, std::vector<double>(n));
		Matrica konacna(3*m, std::vector<double>(3*n));
	
		std::cout << "Unesite elemente matrice: ";
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				std::cin >> pocetna.at(i).at(j);
			}
		}
		std::cout << std::endl;
		konacna = OgledaloMatrica(pocetna);
		
		std::cout << "Rezultantna matrica: " << std::endl;
		for(int i = 0; i < konacna.size(); i++) {
			for(int j = 0; j < konacna.at(i).size(); j++) {
				std::cout << std::setw(4) << konacna.at(i).at(j);
			}
			std::cout << std::endl;
			}
		return 0;
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	

}
/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
/*#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matricad;

bool KoncentricniKrugovi(Matricad matrica, int dimenzija1, int dimenzija2, int i, int j)
{
	int brojkrugova(0), duzina1(dimenzija1-i-1), duzina2(i), duzina3(dimenzija2-j-1), duzina4(j);
	if(duzina1>duzina2 && duzina1>duzina3 && duzina1>duzina4) brojkrugova=duzina1;
	else if(duzina2>duzina1 && duzina2>duzina3 && duzina2>duzina4) brojkrugova=duzina2;
	else if(duzina3>duzina1 && duzina3>duzina2 && duzina3>duzina4) brojkrugova=duzina3;
	else if(duzina4>duzina1 && duzina4>duzina2 && duzina4>duzina3) brojkrugova=duzina4;
	int b(1);
	double maxsuma(0);
	maxsuma=matrica.at(i-1).at(j-1)+matrica.at(i-1).at(j)+matrica.at(i-1).at(j+1);
	maxsuma+=matrica.at(i).at(j-1)+matrica.at(i).at(j+1);
	maxsuma+=matrica.at(i+1).at(j-1)+matrica.at(i+1).at(j)+matrica.at(i+1).at(j+1);
	if(matrica.at(i).at(j)<maxsuma) return false;
	for(int k=1; k<brojkrugova+1; k++) {
		int a(0);
		b+=2;
		double suma {0};
		for(int h=1; h<(b+1)/2; h++) {
			suma+=matrica.at(i-k).at(j-h);
			suma+=matrica.at(i+k).at(j-h);
			suma+=matrica.at(i-k).at(j+h);
			suma+=matrica.at(i+k).at(j+h);
			suma+=matrica.at(j-k).at(i-h);
			suma+=matrica.at(j+k).at(i-h);
			suma+=matrica.at(j-k).at(i+h);
			suma+=matrica.at(j+k).at(i+h);
			a=h;
		}
		suma-=matrica.at(i-k).at(j-a);
		suma+=matrica.at(i+k).at(j-a);
		suma-=matrica.at(i-k).at(j+a);
		suma+=matrica.at(i+k).at(j+a);
		suma+=matrica.at(i-1).at(j)+matrica.at(i+1).at(j)+matrica.at(i).at(j-1)+matrica.at(i).at(j+1);
		if(suma<maxsuma) maxsuma=suma;
		else return false;
	}
	return true;
}

Matricad NajvecaPlaninaMatrice(Matricad matrica)
{
	for(int j=0; j<matrica.size(); j++)
		if(matrica.at(0).size()!=matrica.at(j).size()) throw std::domain_error("Matrica nije korektna");
	Matricad max, m1(matrica);
	int k1 {0}, k2 {0};
	if(matrica.size()==0 || matrica.at(0).size()==0) return max;
	int dimenzija1(matrica.size()), dimenzija2(matrica.at(0).size());
	if(dimenzija1>=4 && dimenzija2>=4) {
		double maxelement;
		do {
			for(int i=1; i<dimenzija1-1; i++) {
				for(int j=1; j<dimenzija2-1; j++)
					if(KoncentricniKrugovi(matrica, dimenzija1, dimenzija2, i, j)) {
						maxelement=matrica.at(i).at(j);
						k1=i;
						k2=j;
						break;
					}
				if(k1!=0) break;
			}
		} while(k1==0);
		for(int i=1; i<dimenzija1-1; i++) {
			for(int j=1; j<dimenzija2-1; j++) {
				if(matrica.at(i).at(j)>maxelement) {
					if(KoncentricniKrugovi(matrica, dimenzija1, dimenzija2, i, j)) {
						maxelement=matrica.at(i).at(j);
						k1=i;
						k2=j;
					}
				}
			}
		}
	} else {
		double maxelement(matrica.at(0).at(0));
		for(int i=0; i<matrica.size(); i++) {
			for(int j=0; j<matrica.at(i).size(); j++) {
				if(matrica.at(i).at(j)>maxelement) {
					maxelement=matrica.at(i).at(j);
					k1=i;
					k2=j;
				}
			}
		}
	}
	int dimenzija;
	if(matrica.size()>matrica.at(0).size()) dimenzija=matrica.size();
	else dimenzija=matrica.at(0).size();
	if(dimenzija%2==0) {
		if(dimenzija1>dimenzija2 && dimenzija1==dimenzija2+1) {
			if((dimenzija1-k1-1)<k1) {
				m1.erase(m1.begin()+0);
			}
			if((dimenzija1-k1-1)>k1) {
				m1.erase(m1.begin()+matrica.size()-1);
			}
		}
		if(dimenzija1<dimenzija2 && dimenzija2==dimenzija1+1) {
			if((dimenzija2-k2-1)<k2) {
				for(int i=0; i<m1.size(); i++)
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
			}
			if((dimenzija2-k2-1)>k2) {
				for(int i=0; i<m1.size(); i++)
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
			}
		}
		if((dimenzija1-k1-1)<k1 && (dimenzija2-k2-1)<k2) {
			m1.erase(m1.begin()+0);
			for(int i=0; i<m1.size(); i++)
				for(int j=0; j<m1.at(i).size(); j++)
					if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
		}
		if((dimenzija1-k1-1)<k1 && (dimenzija2-k2-1)>k2) {
			m1.erase(m1.begin()+0);
			for(int i=0; i<m1.size(); i++)
				for(int j=0; j<m1.at(i).size(); j++)
					if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
		}
		if((dimenzija1-k1-1)>k1 && (dimenzija2-k2-1)>k2) {
			m1.erase(m1.begin()+m1.size()-1);
			for(int i=0; i<m1.size(); i++)
				for(int j=0; j<m1.at(i).size(); j++)
					if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
		}
		if((dimenzija1-k1-1)>k1 && (dimenzija2-k2-1)<k2) {
			m1.erase(m1.begin()+m1.size()-1);
			for(int i=0; i<m1.size(); i++)
				for(int j=0; j<m1.at(i).size(); j++)
					if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
		}
	} else {
		if(dimenzija1>dimenzija2) {
			if((dimenzija1-k1-1)<k1) {
				m1.erase(m1.begin()+0);
				m1.erase(m1.begin()+0);
			}
			if((dimenzija1-k1-1)>k1) {
				m1.erase(m1.begin()+m1.size()-1);
				m1.erase(m1.begin()+m1.size()-1);
			}
		}
		if(dimenzija1<dimenzija2) {
			if((dimenzija2-k2-1)<k2) {
				for(int i=0; i<m1.size(); i++){
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
				}
			}
			if((dimenzija2-k2-1)>k2) {
				for(int i=0; i<m1.size(); i++){
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
				}
			}
		}
		if((dimenzija1-k1-1)<k1 && (dimenzija2-k2-1)<k2) {
			m1.erase(m1.begin()+0);
			m1.erase(m1.begin()+0);
			for(int i=0; i<m1.size(); i++){
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
			}
		}
		if((dimenzija1-k1-1)>k1 && (dimenzija2-k2-1)<k2) {
			m1.erase(m1.begin()+m1.size()-1);
			m1.erase(m1.begin()+m1.size()-1);
			for(int i=0; i<m1.size(); i++){
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==0) m1.at(i).erase(m1.at(i).begin()+j);
			}
		}
		if((dimenzija1-k1-1)<k1 && (dimenzija2-k2-1)>k2) {
			m1.erase(m1.begin()+0);
			m1.erase(m1.begin()+0);
		    for(int i=0; i<m1.size(); i++){
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
			}
		}
		if((dimenzija1-k1-1)>k1 && (dimenzija2-k2-1)>k2) {
			m1.erase(m1.begin()+m1.size()-1);
			for(int i=0; i<m1.size(); i++){
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
					for(int j=0; j<m1.at(i).size(); j++)
						if(j==m1.at(i).size()-1) m1.at(i).erase(m1.at(i).begin()+j);
			}
		}
	}
	return m1;
}

int main ()
{
	std::cout <<"Unesite dimenzije matrice (m i n): ";
	int m, n;
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 1;
	}
	Matricad mat(m, Vektor (n));
	std::cout << "Unesite elemente matrice: " << std::endl;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			std::cin >> mat.at(i).at(j);
	try {
		Matricad mat1=NajvecaPlaninaMatrice(mat);
		std::cout << "Najveca planina unesene matrice je: " << std::endl;
		for(int i=0; i<mat1.size(); i++) {
			for(int j=0; j<mat1.at(i).size(); j++)
				std::cout << std::right << std::setw(6) << mat1.at(i).at(j);
			std::cout << std::endl;
		}
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

void Ispisi (Matrica mat) {
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(0).size(); j++) {
			std::cout << std::setw(6) << mat.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

bool Grbava (Matrica mat) {
	int red(mat.at(0).size());
	for (int i=0; i<mat.size(); i++) {
		if (mat.at(i).size()!=red) return true;
	}
	return false;
}

double zbir (Matrica mat, int red, int kolona, int lvl) {
	double suma(0);
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(0).size(); j++) {
			if ((i==red-lvl || i==red+lvl) && (j>=kolona-lvl && j<=kolona+lvl)) suma+=mat.at(i).at(j);
			else if ((i>red-lvl && i<red+lvl) && (j==kolona-lvl || j==kolona+lvl)) suma+=mat.at(i).at(j);
		}
	}
	return suma;
}

Matrica Kreiraj (Matrica mat, int red, int kolona, int lvl) {
	Matrica m;
	m.resize(lvl*2-1);
	for (int i=0; i<lvl*2-1; i++) m.at(i).resize(lvl*2-1);
	for (int i=0; i<lvl*2-1; i++) {
		for (int j=0; j<lvl*2-1; j++) {
			m.at(i).at(j)=mat.at(red-lvl+1+i).at(kolona-lvl+1+j);
		}
	}
	return m;
}

Matrica NajvecaPlaninaMatrice (Matrica mat) {
	Matrica max;
	if (mat.size()<=0) return max;
	else if (Grbava(mat)) throw std::domain_error("Matrica nije korektna");
	else if (mat.at(0).size()==0) return max;
	
	max.resize(1); max.at(0).resize(1); max.at(0).at(0)=mat.at(0).at(0);
	int max_lvl(1), koordinata_i(0), koordinata_j(0);
	double centar(mat.at(0).at(0));
	
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(0).size(); j++) {
			int lvl(1);
			
			if (max_lvl==1 && mat.at(i).at(j)>centar) {
				centar=mat.at(i).at(j);
				max=Kreiraj(mat, i, j, lvl);
			}
			
			if (i+lvl<mat.size() && i-lvl>=0 && j-lvl>=0  && j+lvl<mat.at(0).size() && mat.at(i).at(j)>zbir(mat, i, j, lvl)) {
				lvl++;
				while (i+lvl<mat.size() && i-lvl>=0 && j-lvl>=0  && j+lvl<mat.at(0).size() && zbir(mat, i, j, lvl-1)>zbir(mat, i, j, lvl)) {
					lvl++;
				}
				if (lvl>max_lvl || (lvl==max_lvl && centar<mat.at(i).at(j)) || (lvl==max_lvl && std::fabs(centar-mat.at(i).at(j))<0.001 && i<koordinata_i) || (lvl==max_lvl && std::fabs(centar-mat.at(i).at(j))<0.001 && i==koordinata_i && j<koordinata_j)) {
					max_lvl=lvl;
					koordinata_i=i;
					koordinata_j=j;
					centar=mat.at(i).at(j);
					max=Kreiraj(mat, i, j, lvl);
				}
			}
		}
	}
	
	return max;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 1;
	} 
	Matrica mat;
	mat.resize(m);
	for (int i=0; i<m; i++) mat.at(i).resize(n);
	
	std::cout << "Unesite elemente matrice:" << std::endl;
	
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<mat.at(0).size(); j++) {
			std::cin >> mat.at(i).at(j);
		}
	}
	try {
		std::cout << "Najveca planina unesene matrice je:" << std::endl;
		Ispisi (NajvecaPlaninaMatrice(mat));
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}
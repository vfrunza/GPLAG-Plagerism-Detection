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
#include <iomanip>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::vector<double>> matrica;

matrica KreirajMatricu (int br_redova, int br_kolona)
{
	return matrica(br_redova, std::vector<double> (br_kolona));
}

matrica UnesiMatricu(int br_redova, int br_kolona)
{
	auto m(KreirajMatricu(br_redova, br_kolona));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<br_redova; i++)
		for(int j=0; j<br_kolona; j++) {
			std::cin>>m.at(i).at(j);
		}
	return m;
}

int SumaKvadrata(matrica m, int x, int y, int sirina)
{
	int suma=0;
	for(int j=y; j<y+sirina; j++) {
		suma+=m.at(x).at(j);
		suma+=m.at(x+sirina-1).at(j);
	}
	for(int i=x+1; i<x+sirina-1; i++) {
		suma+=(m.at(i).at(y)+m.at(i).at(y+sirina-1));
	}
	return suma;
}

void IspisiMatricu(matrica m)
{
	std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.at(0).size(); j++)
			std::cout<<std::setw(6)<<m.at(i).at(j);
		std::cout<<std::endl;
	}
}

matrica NajvecaPlaninaMatrice (matrica mat)
{
	int m(mat.size()), n(mat.at(0).size()), br(0);
	//tmp { broj kvadrata | velicina vrha | x koordinata vrha | y koordinata vrha }
	matrica tmp(m*n, std::vector<double> (4));

	for(int i=0; i<m; i++) if(n!=mat.at(i).size()) throw std::domain_error("Matrica nije korektna");

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			tmp.at(br).at(1)=mat.at(i).at(j);
			tmp.at(br).at(2)=i;
			tmp.at(br).at(3)=j;
			int br_kvadrata(1), suma1(tmp.at(br).at(1)), suma2(0);
			if(i==0 || j==0 || i==m-1 || j==n-1) {
				tmp.at(br).at(0)=1;
				br++;
			} else {
				do {
					suma2=suma1;
					suma1=SumaKvadrata(mat, i-br_kvadrata, j-br_kvadrata, 2*br_kvadrata+1);
					br_kvadrata++;
				} while(suma1<suma2 && (i-br_kvadrata+1)>0 && (j-br_kvadrata+1)>0 && (i+br_kvadrata)<m && (j+br_kvadrata)<n);
				tmp.at(br).at(0)=br_kvadrata;
				br++;
			}
		}
	}
	int max_ind(0);
	const double e(0.00000001);
	for(int i=1; i<m*n; i++) {
		if(tmp.at(i).at(0)>tmp.at(max_ind).at(0)) max_ind=i;
		if(std::fabs(tmp.at(i).at(0)-tmp.at(max_ind).at(0))<e) {
			if(tmp.at(i).at(1)>tmp.at(max_ind).at(1)) max_ind=i;
			else if(std::fabs(tmp.at(i).at(1)-tmp.at(max_ind).at(1))<e) {
				if(tmp.at(i).at(2)<tmp.at(max_ind).at(2)) max_ind=i;
				else if(std::fabs(tmp.at(i).at(2)-tmp.at(max_ind).at(2))<e) {
					if(tmp.at(i).at(3)<tmp.at(max_ind).at(3)) max_ind=i;
				}
			}
		}
	}
	matrica planina(2*tmp.at(max_ind).at(0)-1);
	int X(tmp.at(max_ind).at(2)-tmp.at(max_ind).at(0)+1);
	int ind(0);
	int Y(tmp.at(max_ind).at(3)-tmp.at(max_ind).at(0)+1);
	for(int i=X; i<(X+2*tmp.at(max_ind).at(0)-1); i++) {
		for(int j=Y; j<(Y+2*tmp.at(max_ind).at(0)-1); j++) {
			planina.at(ind).push_back(mat.at(i).at(j));
		}
		ind++;
	}
	return planina;
}

int main ()
{
	matrica M;
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
		return 0;
	}
	M=UnesiMatricu(m,n);
	try {
		matrica planina=NajvecaPlaninaMatrice(M);
		IspisiMatricu(planina);
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}
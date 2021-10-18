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

typedef std::vector<std::vector<double>>matrica;
matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return matrica(br_redova,std::vector<double>(br_kolona));
}
matrica UnesiMatricu(int br_redova,int br_kolona)
{
	matrica m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++)
		for(int j=0; j<br_kolona; j++)
			std::cin>>m[i][j];
	return m;
}

matrica OgledaloMatrica(matrica m)
{
	for(int i=0; i<m.size(); i++) {
		if(m[i].size()!=m[0].size())
			throw std::domain_error("Matrica nije korektna");
	}
	int br_redova=m.size();
	int br_kolona;
	if(m.size()==0)
		br_kolona=0;
	else br_kolona=m[0].size();
	matrica	mat(3*br_redova,std::vector<double>(3*br_kolona));

	matrica horizontalna;
	horizontalna=m;
	for(int i=0; i<horizontalna.size(); i++) {
		for(int j=0; j<horizontalna[i].size()/2; j++) {
			double tmp=horizontalna[i][j];
			horizontalna[i][j]=horizontalna[i][horizontalna[i].size()-1-j];
			horizontalna[i][horizontalna[i].size()-1-j]=tmp;
		}
	}

	matrica vertikalna=m;
	for(int i=0; i<vertikalna.size()/2; i++) {
		for(int j=0; j<vertikalna[i].size(); j++) {
			double tmp=vertikalna[i][j];
			vertikalna[i][j]=vertikalna[vertikalna.size()-1-i][j];
			vertikalna[vertikalna.size()-1-i][j]=tmp;
		}
	}
	matrica kombinovana=vertikalna;
	if(br_redova==1) {
		for(int i=0; i<kombinovana.size(); i++) {
			for(int j=0; j<kombinovana[i].size()/2; j++) {
				double tmp=kombinovana[i][j];
				kombinovana[i][j]=kombinovana[kombinovana.size()-1-i][kombinovana[i].size()-1-j];
				kombinovana[kombinovana.size()-1-i][kombinovana[i].size()-1-j]=tmp;
			}
		}
	} else {
		for(int i=0; i<kombinovana.size(); i++) {
			for(int j=0; j<kombinovana[i].size()/2; j++) {
				double tmp=kombinovana[i][j];
				kombinovana[i][j]=kombinovana[i][kombinovana[i].size()-1-j];
				kombinovana[i][kombinovana[i].size()-1-j]=tmp;
			}
		}
	}
	if(br_redova==1) {
		for(int i=0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				mat[i][j]=kombinovana[i][j];
				mat[br_redova+i][j]=kombinovana[i][j];
				mat[br_redova*2+i][j]=kombinovana[i][j];
				mat[br_redova*2+i][br_kolona*2+j]=kombinovana[i][j];
				mat[br_redova+i][br_kolona*2+j]=kombinovana[i][j];
				mat[i][br_kolona*2+j]=kombinovana[i][j];
				mat[br_redova+i][br_kolona+j]=m[i][j];
				mat[i][br_kolona+j]=vertikalna[i][j];
				mat[br_redova*2+i][br_kolona+j]=vertikalna[i][j];
			}
		}

	} else {
		for(int i=0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				mat[i][j]=kombinovana[i][j];
				mat[br_redova + i][j]=horizontalna[i][j];
				mat[br_redova*2 +i][j]=kombinovana[i][j];
				mat[i][br_kolona+j]=vertikalna[i][j];
				mat[i][br_kolona*2+j]=kombinovana[i][j];
				mat[br_redova+i][br_kolona+j]=m[i][j];
				mat[br_redova+i][br_kolona*2+j]=horizontalna[i][j];
				mat[br_redova*2+i][br_kolona+j]=vertikalna[i][j];
				mat[br_redova*2+i][br_kolona*2+j]=kombinovana[i][j];
			}
		}
	}
	return mat;
}
int main ()
{
	int n,m;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>n>>m;
	if(n<0 || m<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	matrica a(UnesiMatricu(n,m));
	matrica d;
	try {
		d=(OgledaloMatrica(a));
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica: ";
	std::cout<<std::endl;
	for(int i=0; i<d.size(); i++) {
		for(int j=0; j<d[i].size(); j++) {
			std::cout<<std::setw(4)<<d[i][j];
		}
		std::cout<<std::endl;
	}

	return 0;
}
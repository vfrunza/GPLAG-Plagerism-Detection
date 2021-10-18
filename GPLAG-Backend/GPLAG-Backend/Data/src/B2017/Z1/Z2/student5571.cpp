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
#define eps 0.0000000001

typedef std::vector<std::vector<double>> matrica;

bool Provjeri(matrica M,int x, int y, int k)
{
	if(x-k<0 || y-k<0 || x+k>=M.size() || y+k>=M.at(0).size()) return false;
	return true;
}
double IzracunajSumu(matrica M, int x, int y, int k)
{
	double suma(0);
	for(int i=x-k; i<=x+k; i++) {
		for(int j=y-k; j<=y+k; j++) {
			if((i>x-k && i<x+k && j>y-k && j<y+k) || (i==x && j==y)) continue;
			suma+=M.at(i).at(j);
		}
	}
	return suma;
}

matrica NajvecaPlaninaMatrice(matrica M)
{

	matrica m;


	if((M.size()==0)) return m;
	else if(M.size()>0 && M.at(0).size()==0) return m;

	for(int i=1; i<M.size(); i++) {
		if(M.at(0).size()!=M.at(i).size()) throw std::domain_error("Matrica nije korektna");
	}

	if(M.size()==2 && M.at(0).size()>0) {
		double max(M.at(0).at(0));

		for(int i=0; i<M.size(); i++) {
			for(int j=0; j<M.at(0).size(); j++) {
				if(M.at(i).at(j)>=max) max=M.at(i).at(j);
			}
		}

		matrica par(1,std::vector<double>(1,max));

		return par;
	}

	int kmax(0),vrhi(0),vrhj(0);
	double maxVrh(0);
	for(int i=1; i<M.size()-1; i++) {
		for(int j=1; j<M.at(i).size()-1; j++) {
			if(M[i][j]>IzracunajSumu(M,i,j,1)) {
				int k(1);
				while(Provjeri(M, i, j, k+1)) {
					if(IzracunajSumu(M,i,j,k)<IzracunajSumu(M,i,j,k+1)) break;
					k++;
				}
				if(k>kmax) {
					kmax=k;
					vrhi=i;
					vrhj=j;
					maxVrh=M.at(i).at(j);
				} else if(k==kmax) {
					if(M[i][j]>maxVrh) {
						maxVrh=M[i][j];
						vrhi=i;
						vrhj=j;
					} else if(std::fabs(M[i][j]-maxVrh)<eps) {
						if(i<vrhi) {
							vrhi=i;
							vrhj=j;
						} else if(i==vrhi) {
							if(j<vrhj) vrhj=j;
						}
					}

				}

			}
		}
	}

	for(int i=vrhi-kmax; i<=vrhi+kmax; i++) {
		std::vector<double> red;
		for(int j=vrhj-kmax; j<=vrhj+kmax; j++) red.push_back(M.at(i).at(j));
		m.push_back(red);

	}
	return m;
}

int main ()
{
	try {
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		int m,n;
		std::cin>>m>>n;
		if(m<0 || n<0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<<"Unesite elemente matrice:";
		matrica M;
		double clan;
		for(int i=0; i<m; i++) {
			std::vector<double> redm;
			for(int j=0; j<n; j++) {
				std::cin>>clan;
				redm.push_back(clan);
			}
			M.push_back(redm);
		}



		std::cout<<std::endl;
		std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
		matrica mat(NajvecaPlaninaMatrice(M));
		for(int i=0; i<mat.size(); i++) {
			for(int j=0; j<mat.at(0).size(); j++) {
				std::cout<<std::setw(6)<<mat.at(i).at(j);
			}
			std::cout<<std::endl;
		}

	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() <<std::endl;
	}
	return 0;
}
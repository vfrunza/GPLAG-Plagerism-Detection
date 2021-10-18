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

using std::cin;
using std::cout;
using std::endl;

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica mat)
{
	Matrica mat1;
	if(mat.size()==0) return mat1;

	for(int i=0; i<mat.size()-1; i++) {
		if(mat[i].size()!=mat[i+1].size()) throw std::domain_error("Matrica nije korektna");
	}

	Matrica h(mat.size(),std::vector<double>(mat[0].size()));
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(i).size(); j++) {
			h.at(i).at(j)=mat.at(i).at(mat[i].size()-j-1);
		}
	}

	Matrica v(mat.size(),std::vector<double>(mat[0].size()));
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(i).size(); j++) {
			v.at(i).at(j)=mat.at(mat.size()-i-1).at(j);
		}
	}

	Matrica hv1(mat.size(),std::vector<double>(mat[0].size()));
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(i).size(); j++) {
			hv1.at(i).at(j)=mat.at(mat.size()-i-1).at(j);
		}
	}
	Matrica hv(mat.size(),std::vector<double>(mat[0].size()));
	for(int i=0; i<hv1.size(); i++) {
		for(int j=0; j<hv1.at(i).size(); j++) {
			hv.at(i).at(j)=hv1.at(i).at(hv1[i].size()-j-1);
		}
	}

	Matrica nova(3*mat.size(),std::vector<double>(3*mat[0].size()));
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(i).size(); j++) {
			nova.at(i).at(j)=hv.at(i).at(j);
		}
	}
	for(int i=0; i<mat.size(); i++) {
		for(int j=mat.at(i).size(); j<2*mat.at(i).size(); j++) {
			nova.at(i).at(j)=v.at(i).at(j-mat.at(i).size());
		}
	}
	for(int i=0; i<mat.size(); i++) {
		for(int j=2*mat.at(i).size(); j<3*mat.at(i).size(); j++) {
			nova.at(i).at(j)=hv.at(i).at(j-2*mat.at(i).size());
		}
	}
	for(int i=mat.size(); i<2*mat.size(); i++) {
		for(int j=0; j<mat.at(i-mat.size()).size(); j++) {
			nova.at(i).at(j)=h.at(i-mat.size()).at(j);
		}
	}
	for(int i=mat.size(); i<2*mat.size(); i++) {
		for(int j=mat.at(i-mat.size()).size(); j<2*mat.at(i-mat.size()).size(); j++) {
			nova.at(i).at(j)=mat.at(i-mat.size()).at(j-mat.at(i-mat.size()).size());
		}
	}
	for(int i=mat.size(); i<2*mat.size(); i++) {
		for(int j=2*mat.at(i-mat.size()).size(); j<3*mat.at(i-mat.size()).size(); j++) {
			nova.at(i).at(j)=h.at(i-mat.size()).at(j-2*mat.at(i-mat.size()).size());
		}
	}
	for(int i=2*mat.size(); i<3*mat.size(); i++) {
		for(int j=0; j<mat.at(i-2*mat.size()).size(); j++) {
			nova.at(i).at(j)=hv.at(i-2*mat.size()).at(j);
		}
	}
	for(int i=2*mat.size(); i<3*mat.size(); i++) {
		for(int j=mat.at(i-2*mat.size()).size(); j<2*mat.at(i-2*mat.size()).size(); j++) {
			nova.at(i).at(j)=v.at(i-2*mat.size()).at(j-mat.at(i-2*mat.size()).size());
		}
	}
	for(int i=2*mat.size(); i<3*mat.size(); i++) {
		for(int j=2*mat.at(i-2*mat.size()).size(); j<3*mat.at(i-2*mat.size()).size(); j++) {
			nova.at(i).at(j)=hv.at(i-2*mat.size()).at(j-2*mat.at(i-2*mat.size()).size());
		}
	}

	return nova;
}
int main ()
{

	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0)	cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {

		Matrica mat(m,std::vector<double>(n));
		cout<<"Unesite elemente matrice: ";
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cin>>mat[i][j];
			}
		}

		try {
			auto mat1(OgledaloMatrica(mat));
			cout<<endl<<"Rezultantna matrica: "<<endl;

			for(int i=0; i<mat1.size(); i++) {
				for(int j=0; j<mat1[i].size(); j++) {
					cout<<std::setw(4)<<mat1[i][j];
				}
				cout<<endl;
			}
		} catch(std::domain_error izuzetak) {
			cout<<izuzetak.what()<<endl;
		}
	}
	return 0;
}
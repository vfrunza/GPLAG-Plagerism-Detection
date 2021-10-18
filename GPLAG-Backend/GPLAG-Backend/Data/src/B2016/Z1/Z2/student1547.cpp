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

typedef std::vector<double> vektor;

using std::cout;
using std::cin;

std::vector<std::vector<double>> HorOgledalo(std::vector<std::vector<double>> m)
{
	for(int i=0; i< m.size(); i++) {
		for(int j=0; j<m[i].size()/2; j++) {
			double temp;
			temp=m[i][j];
			m[i][j]=m[i][m[i].size()-1-j];
			m[i][m[i].size()-1-j]=temp;
		}
	}
	return m;
}

std::vector<std::vector<double>> VerOgledalo(std::vector<std::vector<double>> mat)
{
	for(int i=0; i<mat.size()/2; i++) {
		vektor a(mat[i]);
		mat[i]=std::move(mat[mat.size()-1-i]);
		mat[mat.size()-1-i]=std::move(a);
	}
	return mat;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat)
{
	std::vector<std::vector<double>> novamat(3*mat.size()), horiz(HorOgledalo(mat)), ver(VerOgledalo(mat)), mix(HorOgledalo(VerOgledalo(mat)));
	bool izuzetak(false);
	for(int i=0; i<mat.size(); i++) {
		for(int j=i+1; j<mat.size(); j++) {
			if(mat[i].size()!=mat[j].size()) izuzetak=true;
		}
	}
	if(izuzetak) throw std::domain_error ("Matrica nije korektna");

	for(int i=0; i<novamat.size(); i++) {
		for(int j=0; j<3*mat[0].size(); j++) {
			if(i<mat.size()){
				if(j<mat[0].size()){
					novamat.at(i).push_back(mix.at(i)[j]);
				}
				if(j>=mat[0].size() and j<2*mat[0].size()){
					novamat.at(i).push_back(ver.at(i)[j-mat[0].size()]);
				}
				if(j>=2*mat[0].size()){
					novamat.at(i).push_back(mix.at(i)[j-2*mat[0].size()]);
				}
			}
			if(i>=mat.size() and i<2*mat.size()){
				if(j<mat[0].size()){
					novamat.at(i).push_back(horiz.at(i-mat.size())[j]);
				}
				if(j>=mat[0].size() and j<2*mat[0].size()){
					novamat.at(i).push_back(mat.at(i-mat.size())[j-mat[0].size()]);
				}
				if(j>=2*mat[0].size()){
					novamat.at(i).push_back(horiz.at(i-mat.size())[j-2*mat[0].size()]);
				}
			}
			if(i>=2*mat.size()){
				if(j<mat[0].size()){
					novamat.at(i).push_back(mix.at(i-2*mat.size())[j]);
				}
				if(j>=mat[0].size() and j<2*mat[0].size()){
					novamat.at(i).push_back(ver.at(i-2*mat.size())[j-mat[0].size()]);
				}
				if(j>=2*mat[0].size()){
					novamat.at(i).push_back(mix.at(i-2*mat.size())[j-2*mat[0].size()]);
				}
			}

		}
	}
return novamat;
}

int main ()
{
	int m, n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	if(m<0 or n<0){ 
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<< "Unesite elemente matrice: " << std::endl;
	std::vector<std::vector<double>> mat(m, std::vector<double>(n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> mat[i][j];
		}
	}
	mat=OgledaloMatrica(mat);
	cout << "Rezultantna matrica: " << std::endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			cout << std::setw(4) << mat[i][j];
		}
		cout << std::endl;
	}
	return 0;
}
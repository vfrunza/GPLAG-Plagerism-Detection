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
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice(Matrica mat)
{
	int suma=0;
	std::vector<int>v;
	Matrica m(mat.size());
	for(int i=0; i<mat.size()-1; i++) {
		for(int j=0; j<mat.at(i).size()-1; j++) {
			if(i<=1 && j<=1) return mat;
			else if(i>1 && j>1) {
//				for(int k=i-1; k<=i+1; k++) {
				for(int k=j-1; k<=j+1; k++) {
					suma+=mat.at(i-1).at(k)+mat.at(i).at(k)-m.at(i).at(j)+mat.at(i+1).at(k);
					v.push_back(m.at(i-1).at(k));
					v.push_back(m.at(i).at(j-1));
					v.push_back(m.at(i).at(j));
					v.push_back(m.at(i).at(j+1));
					v.push_back(m.at(i+1).at(k+1));
				}
			}
			if(suma<mat.at(i).at(j)) {
				for(int i=0; i<v.size(); i++) {
					for(int i=0; j<v.size(); j++) {
						m.at(i).at(j)=v.at(i);
					}
				}
			}
		}
	}

	return m;

}


int main ()
{
	Matrica mat {{0,0,0},{1,25,1},{1,1,20},{2,3,4}};
	//{{0,0,0,15,12,6}, {1,25,1,5,2,9}, {1,1,20,15,10,5}, {3,2,19,130,14,8}, {90,6,20,12,17,2}, {12,3,5,1,8,4}};
	mat=NajvecaPlaninaMatrice(mat);
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(0).size(); j++) {
			std::cout << mat.at(i).at(j) << " ";
		}
		std::cout<< std::endl;
	}
	return 0;










}
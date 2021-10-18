/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include <iomanip>
#include <stdexcept>


std::vector<std::vector<double>>OgledaloMatrica(std::vector<std::vector<double>>m){
	if (m.size()==0) return m;
	for (int i=0;i<m.size()-1;i++){
		if (m[i].size()!=m[i+1].size()) throw std::domain_error ("Matrica nije korektna");
	}
	std::vector<std::vector<double>>km(m.size()*3,std::vector<double>(m[0].size()*3));
	for (int i=0;i<m.size();i++){
		for (int j=0;j<m[0].size();j++){
			km[i][j]=m[m.size()-1-i][m[0].size()-1-j];
			km[i][j+m[0].size()]=m[m.size()-1-i][j];
			km[i][j+2*m[0].size()]=m[m.size()-1-i][m[0].size()-1-j];
			km[i+m.size()][j]=m[i][m[0].size()-1-j];
			km[i+m.size()][j+m[0].size()]=m[i][j];
			km[i+m.size()][j+2*m[0].size()]=m[i][m[0].size()-1-j];
			km[i+2*m.size()][j]=m[m.size()-1-i][m[0].size()-1-j];
			km[i+2*m.size()][j+m[0].size()]=m[m.size()-1-i][j];
			km[i+2*m.size()][j+2*m[0].size()]=m[m.size()-1-i][m[0].size()-1-j];
		}
	}
	return km;
}

int main ()
{
	try{
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m;
		std::cin>>n;
		if (m<0 || n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
		std::vector<std::vector<double>>mat(m,std::vector<double>(n));
		std::cout<<"Unesite elemente matrice: "<<std::endl;
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				std::cin>>mat[i][j];
			}
		}
		std::vector<std::vector<double>>mati(OgledaloMatrica(mat));
		std::cout<<"Rezultantna matrica: "<<std::endl;
		for (int i=0;i<mati.size();i++){
			for (int j=0;j<mati[0].size();j++){
				std::cout<<std::setw(4)<<mati[i][j];
			}
			std::cout<<std::endl;
		}
	}
	catch (std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	
	return 0;
}
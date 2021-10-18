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
//Pomocna f-ja za kreiranje matrice
Matrica KreirajMat(int m, int n){
	return Matrica(m,std::vector<double>(n));
}
//Pomocna f-ja za unos matrice
Matrica UnesiMatricu(int m, int n){
	auto mat(KreirajMat(m,n));
	for(int i(0); i<m; i++)
		for(int j(0); j<n; j++){
			std::cin>>mat.at(i).at(j);
		}
	return mat;
}
//Pomocna f-ja za provjeru da li je matrica grbava
bool DaLiJeGrbava(Matrica m){
	for(int i=0; i<m.size(); i++){
		if(m.at(0).size()!=m.at(i).size()) return 1;
	}
	return 0;
}
//Pomocna f-ja za ispis matrice
void IspisiMatricu(Matrica m){
	for(int i(0); i<m.size(); i++){
		for(int j(0); j<m.at(i).size(); j++)
		std::cout<<std::setw(6)<<std::right<<m.at(i).at(j);
		std::cout<<std::endl;
	}
}
int Br_El(Matrica m){
	int brojac(0);
	for(int i(0); i<m.size(); i++){
		for(int j(0); j<m.at(i).size(); j++)
		brojac++;
	}
	return brojac;
}

Matrica NajvecaPlaninaMatrice(Matrica mat){
	//Ispitivanje da li je matrica grbava i bacanje izuzetka ako jest
	if(DaLiJeGrbava(mat)) throw std::domain_error("Matrica nije korektna");
	Matrica m;
	if(mat.size()==0) return m;
	double max(0);
	if(Br_El(mat)<=8){
		
		for(int i(0); i<mat.size(); i++){
			for(int j(0); j<mat.at(i).size(); j++){
			if(mat.at(i).at(j)>max) max=mat.at(i).at(j);
			}
		}
		m.push_back(std::vector<double>(1,max));
		 int isti(0);
		 double element=mat.at(0).at(0);
		for(int i(0); i<mat.size(); i++){
			for(int j(0); j<mat.at(i).size(); j++){
				if(element==mat.at(i).at(j)) isti++;
			}
		}
		if(isti==mat.size()*mat.at(0).size()) m.push_back(std::vector<double>(0, element));
	}
	/*else if(Br_El(mat)>=8){
		
	}*/
	
	return m;
}

int main ()
{
	int m;
	int n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m;
	std::cin>>n;
	if(m<0 || n<0){  
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice:";
	auto mat(UnesiMatricu(m,n));
	try{
		Matrica MAT(NajvecaPlaninaMatrice(mat));
		std::cout<<"\nNajveca planina unesene matrice je:\n";
		for(int i(0); i<MAT.size(); i++){
			for(int j(0); j<MAT[i].size(); j++)
			std::cout<<std::setw(6)<<MAT.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}
/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica m){
	if(m.size()==0)
		return m;
	for(int i=0; i<m.size()-1; i++){
		for(int j=i+1; j<m.size(); j++){
			if(m[i].size()!=m.at(j).size()){
				throw std::domain_error("Matrica nije korektna");
			}
		}
	}
	Matrica M(3*m.size(), std::vector<double>(3*m.at(0).size()));
	Matrica hM(m.size(), std::vector<double>(m.at(0).size())), vM(m.size(), std::vector<double>(m.at(0).size())), hvM(m.size(), std::vector<double>(m.at(0).size()));
	//ogledala hM, vM, hvM
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m.at(i).size(); j++){
			hvM[i][j]=m[m.size()-1-i][m[i].size()-1-j];
			hM[i][hM[i].size()-1-j]=m[i][j];
			vM[vM.size()-1-i][j]=m[i][j];
		}
	}
	for(int i=0; i<hvM.size(); i++){
		for(int j=0; j<hvM.at(i).size(); j++){
			M[i][j]=hvM[i][j];
			M[M.size()-1-i][M[i].size()-1-j]=hvM[hvM.size()-1-i][hvM[i].size()-1-j];
			M[M.size()-1-i][j]=hvM[hvM.size()-1-i][j];
			M[i][M[i].size()-1-j]=hvM[i][hvM[i].size()-1-j];
			M[i+hM.size()][j]=hM[i][j];
			M[i+hM.size()][j+2*hM[i].size()]=hM[i][j];
			M[i+hM.size()][j+hM[i].size()]=m[i][j];
			M[i][j+vM[i].size()]=vM[i][j];
			M[i+2*vM.size()][j+vM[i].size()]=vM[i][j];
		}
	}
	return M;
}

int main (){
	int red, kol;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>red>>kol;
	if(red<0 || kol<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 1;
	}
	Matrica m(red, std::vector<double>(kol));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[0].size(); j++){
			std::cin>>m[i][j];
		}
	}
	std::cout<<std::endl;
	try{
		Matrica ispis(OgledaloMatrica(m));
		std::cout<<"Rezultantna matrica:"<<std::endl;
		for(std::vector<double> i: ispis){
			for(double j: i){
				std::cout<<std::setw(4)<<j;
			}
			std::cout<<std::endl;
		}
	}
	catch(...){
	}
	return 0;
}
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

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> vektor;

Matrica Horizontalna(Matrica matrica){
	if(matrica.size()==0) return matrica;
	for(int i(0);i<matrica[0].size()/2;i++){
		for(int j(0);j<matrica.size();j++){
			double tmp=matrica[j][i];
			matrica[j][i]=matrica[j][matrica[0].size()-i-1];
			matrica[j][matrica[0].size()-i-1]=tmp;
			
		}
	}
	return matrica;
}
Matrica Vertikalna(Matrica matrica){
	if(matrica.size()==0) return matrica;
	for(int i(0);i<matrica.size()/2;i++){
		for(int j(0);j<matrica[0].size();j++){
			double tmp=matrica[i][j];
			matrica[i][j]=matrica[matrica.size()-i-1][j];
			matrica[matrica.size()-i-1][j]=tmp;
		}
	}
	return matrica;
}

Matrica Kombinovana(Matrica matrica){
	if(matrica.size()==0) return matrica;
	Matrica kombinovana=Horizontalna(matrica);
	Matrica kombinovana1=Vertikalna(kombinovana);
	return kombinovana1;
	
}

Matrica OgledaloMatrica(Matrica matrica){
	for (int i(0);i<matrica.size();i++){
		if(matrica[0].size()!=matrica[i].size()) throw std::domain_error("Matrica nije korektna");
	}
	if(matrica.size()==0) return matrica;
	Matrica horizontalna=Horizontalna(matrica);
	Matrica vertikalna=Vertikalna(matrica);
	Matrica kombinovana=Kombinovana(matrica);
	
	Matrica zadnja(3*matrica.size(),std::vector<double>(3*matrica[0].size()));
	
	for(int i(0);i<matrica.size();i++){
		for(int j(0);j<matrica[0].size();j++){
			zadnja[i][j]=kombinovana[i][j];
			zadnja[i+matrica.size()][j]=horizontalna[i][j];
			zadnja[i+matrica.size()*2][j]=kombinovana[i][j];
			zadnja[i][j+matrica[0].size()]=vertikalna[i][j];
			zadnja[i+matrica.size()][j+matrica[0].size()]=matrica[i][j];
			zadnja[i+matrica.size()*2][j+matrica[0].size()]=vertikalna[i][j];
			zadnja[i][j+matrica[0].size()*2]=kombinovana[i][j];
			zadnja[i+matrica.size()][j+matrica[0].size()*2]=horizontalna[i][j];
			zadnja[i+matrica.size()*2][j+matrica[0].size()*2]=kombinovana[i][j];
		}
	}
	return zadnja;
}


int main ()
{ try{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) throw std::domain_error ("Dimenzije matrice moraju biti nenegativne!");
	Matrica matrica(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i(0);i<matrica.size();i++){
		for(int j(0);j<matrica[0].size();j++){
			std::cin>>matrica[i][j];
		}
	}
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica: "<<std::endl;
	Matrica matrica2=OgledaloMatrica(matrica);
	for(int i(0);i<matrica2.size();i++){
		for(int j(0);j<matrica2[0].size();j++){
			std::cout<<std::right<<std::setw(4)<<matrica2[i][j];
		}
		std::cout<<std::endl;
	}
}
catch(std::domain_error izuzetak){
	std::cout<<izuzetak.what();
}
	return 0;
}
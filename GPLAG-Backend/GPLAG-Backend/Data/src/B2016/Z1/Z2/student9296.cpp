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
typedef std::vector<std::vector<double>> DoubleMatrica;

DoubleMatrica OgledaloMatrica(DoubleMatrica M){
	DoubleMatrica hM, vM, hvM;
	for(int i=0; i<M.size(); i++){
		int sirina(M[i].size()); 
		if(sirina!=M[0].size()) throw std::domain_error("Matrica nije korektna.");
	}
	for(int i=M.size()-1; i>=0; i--) {
		vM.push_back(M[i]);		//vertikalno
	}
	hM=M;
	hvM=vM;
	for(int i=0; i<M.size(); i++){
		for(int j=0; j<M[0].size()/2; j++){
			double pom(hM[i][j]);
			hM[i][j]=std::move(hM[i][M[0].size()-j-1]);		//horizontalno
			hM[i][M[0].size()-j-1]=std::move(pom);
			
			pom=std::move(hvM[i][j]);
			hvM[i][j]=std::move(hvM[i][M[0].size()-j-1]);		//hor i ver
			hvM[i][M[0].size()-j-1]=std::move(pom);
		}
	}
	
	int m(M.size()), n;
	if(m==0) n=0;
	else n=M[0].size();
	DoubleMatrica nova(3*m, std::vector<double>(3*n));
	for(int i=0; i<3*m; i++){
		for(int j=0; j<3*n; j++){
			if(i>=0&&i<m){
				if(j>=0&&j<n) nova[i][j]=hvM[i][j];
				else if(j>=n&&j<2*n) nova[i][j]=vM[i][j-n];
				else if(j>=2*n&&j<3*n) nova[i][j]=hvM[i][j-2*n];
			}
			else if(i>=m&&i<2*m){
				if(j>=0&&j<n) nova[i][j]=hM[i-m][j];
				else if(j>=n&&j<2*n) nova[i][j]=M[i-m][j-n];
				else if(j>=2*n&&j<3*n) nova[i][j]=hM[i-m][j-2*n];
			}
			else if(i>=2*m&&i<3*m){
				if(j>=0&&j<n) nova[i][j]=hvM[i-2*m][j];
				else if(j>=n&&j<2*n) nova[i][j]=vM[i-2*m][j-n];
				else if(j>=2*n&&j<3*n) nova[i][j]=hvM[i-2*m][j-2*n];
			}
		}
	}
	return nova;
}
int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	DoubleMatrica M(m, std::vector<double> (n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>M[i][j];
		}
	}
	try{
		auto nova(OgledaloMatrica(M));
		std::cout<<"Rezultantna matrica:"<<std::endl;
		for(int i=0; i<nova.size(); i++){
			for(int j=0; j<nova[0].size(); j++){
				std::cout<<std::setw(4)<<nova[i][j];
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}
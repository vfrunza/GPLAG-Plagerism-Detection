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
std::vector<std::vector<double>> Horizontalno_ogledalo(std::vector<std::vector<double>> M) {
	for(int i(0);i<M.size();i++) {
		for(int j(0);j<M[i].size()/2; j++) {
		    double tmp=M[i][j];
		    M[i][j]=M[i][M[i].size()-1-j];
		    M[i][M[i].size()-1-j]=tmp;
		   
		   	}
		   	
	}
	return M;
}
std::vector<std::vector<double>> Vertikalno_ogledalo(std::vector<std::vector<double>> M) {
	int n=M.size();
	for(int i(0);i<M.size()/2;i++) {
		for(int j(0);j<M[i].size(); j++) {
		    double tmp=M[i][j];
		    M[i][j]=M[n-i-1][j];
		    M[n-i-1][j]=tmp;
		    
		   	}
		   	
	}
	return M;
}
std::vector<std::vector<double>> Kombinovano_ogledalo(std::vector<std::vector<double>> M) {
	M=Horizontalno_ogledalo(M);
	M=Vertikalno_ogledalo(M);
	return M;
}
bool Grbava_Matrica(std::vector<std::vector<double>> M) {
	bool grbava=false;
	for(int i(0);i<M.size()-1;i++) {
		if(M[i].size()!=M[i+1].size()) { grbava=true;
		break;
		}
	}
	return grbava;
}
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> M) {
	if(M.size()==0) return M;
	if(Grbava_Matrica(M)==true) throw std::domain_error("Matrica nije korektna");
	std::vector<std::vector<double>> N((3*M.size()),std::vector<double> (3*M[0].size()));
	std::vector<std::vector<double>>KOM;
	KOM=(Kombinovano_ogledalo(M));
	std::vector<std::vector<double>>VER;
	VER=(Vertikalno_ogledalo(M));
	std::vector<std::vector<double>> HOR;
	HOR=(Horizontalno_ogledalo(M));
	int m=M.size();
	int n=M[0].size();
	
	for(int i(0);i<m;i++) {
		for(int j(0);j<3*n;j++) {
			 if(j<n) N[i][j]=KOM[i][j];
		else if(j>=n && j<2*n) N[i][j]=VER[i][j-n];
			else N[i][j]=KOM[i][j-2*n];
		}
	}
	for(int i(m);i<2*m;i++) {
		for(int j(0);j<3*n;j++) {
			if(j<n) N[i][j]=HOR[i-m][j];
			else if(j>=n && j<2*n) N[i][j]=M[i-m][j-n];
			else N[i][j]=HOR[i-m][j-2*n];
		}
	}
	for(int i(2*m);i<3*m;i++) {
		for(int j(0);j<3*n;j++) {
			if(j<n) N[i][j]=KOM[i-2*m][j];
			else if(j>=n && j<2*n) N[i][j]=VER[i-2*m][j-n];
			else N[i][j]=KOM[i-2*m][j-2*n];
			
		}
	}
	return N;
}
int main ()

{    try{
	int m,n;
	
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;

	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {
	    std::vector<std::vector<double>> M(m,std::vector<double> (n));
		std::cout<<"Unesite elemente matrice: "<<std::endl;
		for(int i(0);i<M.size();i++) {
			for(int j(0);j<M[i].size();j++){
				std::cin>>M[i][j];
			}
		}
		std::vector<std::vector<double>> N(3*m,std::vector<double>(3*n));
		N=OgledaloMatrica(M);
		std::cout<<"Rezultantna matrica:"<<std::endl;
		
		for(int i(0);i<N.size();i++) {
			for(int j(0);j<N[i].size();j++) {
				std::cout<<std::setw(4)<<N[i][j];
				
			}
			std::cout<<std::endl;
		}
			}
	}
	catch(std::domain_error izuzetak) {
     std::cout << izuzetak.what() << std::endl;
}
	
	return 0;
}
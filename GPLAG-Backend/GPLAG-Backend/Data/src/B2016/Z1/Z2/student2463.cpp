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

typedef std::vector<std::vector<double>> Matrica;
//Matrica KreirajMatricu(int brj_redova, int broj_kolona){
	//return Matrica(broj_redova, std::vector<double>(broj kolona))

Matrica Horizontalna(Matrica A){
	int temp;
	
	for(int i=0; i<A.size(); i++){
		for(int j=0; j<(A[i].size())/2; j++){
			temp=A[i][j];
			A[i][j]=A[i][A[i].size()-1-j];
			A[i][A[i].size()-1-j]=temp;
		}
	}
	return A;
}

Matrica Vertikalna(Matrica A){
	int temp;
	int i=0;
	for(int j=0; j<A[i].size(); j++){
		for(i=0; i<A.size()/2; i++){
			temp=A[i][j];
			A[i][j]=A[A.size()-1-i][j];
			A[A.size()-1-i][j]=temp;
		}
	}
	return A;
	}


Matrica OgledaloMatrica(Matrica M){
	if(M.size()== 0) return M;
	int redovi, kolone;
	for(int i=0; i<M.size(); i++){
		if(M[i].size()!=M[0].size()) throw std::domain_error("Matrica nije korektna");
	}
	redovi=M.size();
	kolone=M[0].size();
	
	Matrica O(redovi*3, std::vector<double>(kolone*3));
	
	Matrica H(redovi, std::vector<double>(kolone));
	Matrica V(redovi, std::vector<double>(kolone));
	Matrica HV(redovi, std::vector<double>(kolone));
	
	
	H = Horizontalna(M);
	V = Vertikalna(M);
	HV = Horizontalna(M);
	HV = Vertikalna(HV);
	
	for(int i=0; i<3*redovi; i++){
		for(int j=0; j<3*kolone; j++){
			if(i<redovi && j<kolone)	O[i][j]=HV[i][j];
			if(i<redovi && j>=kolone && j<kolone*2) O[i][j]=V[i][j-kolone];
			if(i<redovi && j>=kolone*2) O[i][j]=HV[i][j-kolone*2];
			
			if(i>=redovi && i<redovi*2 && j<kolone) O[i][j]=H[i-redovi][j];
			if(i>=redovi && i<redovi*2 && j>=kolone && j<kolone*2) O[i][j]=M[i-redovi][j-kolone];
			if(i>=redovi && i<redovi*2 && j>=kolone*2) O[i][j]=H[i-redovi][j-kolone*2];
			
			if(i>=2*redovi && j<kolone) O[i][j]=HV[i-redovi*2][j];
			if(i>=2*redovi && j>=kolone && j<kolone*2) O[i][j]=V[i-redovi*2][j-kolone];
			if(i>=2*redovi && j>=kolone*2) O[i][j]=HV[i-redovi*2][j-kolone*2];
			
		}
	}
	return O;
}


int main ()
{
	try{
		int m,n;
		double x;
		Matrica O,M;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m;
		std::cin>>n;
		if(m<0 || n<0){
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<<"Unesite elemente matrice:"<<std::endl;
		for(int i=0;i<m;i++){
			std::vector<double> temp;
			for(int j=0;j<n;j++){
				std::cin>>x;
				temp.push_back(x);
			}
			O.push_back(temp);
		}
		std::cout<<"Rezultantna matrica:"<<std::endl;
		O = OgledaloMatrica(O);
		for(int i=0; i<O.size(); i++){
			for(int j=0; j<O[i].size(); j++){
				std::cout<< std::setw(4)<< O[i][j];
			}
			std::cout<<std::endl;
		}
		
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	
	return 0;
}
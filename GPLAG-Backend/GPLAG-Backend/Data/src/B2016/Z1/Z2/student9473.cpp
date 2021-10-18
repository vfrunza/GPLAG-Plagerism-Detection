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

std::vector<std::vector<double>> h(std::vector<std::vector<double>> M){ 
	for(int i=0; i<(int)M.size(); i++){
		int k=(int)M[i].size()-1;
		for(int j=0; j<(int)M[i].size()/2;j++){
			double n;
			n=M[i][j];
			M[i][j]=M[i][k];
			M[i][k]=n;
			k--;
		}
	}
	return M;
}

std::vector<std::vector<double>> v(std::vector<std::vector<double>> M){
	int k=(int)M.size()-1;
	for(int i=0; i<(int)M.size()/2; i++){
		for(int j=0; j<(int)M[i].size(); j++){
			double n;
			n=M[i][j];
			M[i][j]=M[k][j];
			M[k][j]=n;
		}
		k--;
	}
	return M;
}

std::vector<std::vector<double>> hv(std::vector<std::vector<double>> M){
	return v(h(M));
}

std::vector<std::vector<double>> DodajDole(std::vector<std::vector<double>> M, std::vector<std::vector<double>> N){
	for(int i=0; i<(int)N.size(); i++)
		M.push_back(N[i]);
	return M;
}

std::vector<std::vector<double>> Spoji(std::vector<std::vector<double>> M, std::vector<std::vector<double>> N){
	for(int i=0; i<(int)M.size(); i++)
		for(int j=0; j<(int)N[i].size();j++)
			M[i].push_back(N[i][j]);
	return M;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> M){
	for(int i=0; i<(int)M.size(); i++)
		if((int)M[i].size()!=(int)M[0].size())
			throw std::domain_error("Matrica nije korektna");
	std::vector<std::vector<double>> M1,M2;
	M1=DodajDole(DodajDole(hv(M),h(M)),hv(M));
	M2=DodajDole(DodajDole(v(M),M),v(M));
	return Spoji(Spoji(M1,M2),M1);
}


int main(){	
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m;
	std::cin>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 1;
	}
	std::cout<<"Unesite elemente matrice: ";
	std::vector<std::vector<double>> M;
	for(int i=0; i<m; i++){
		std::vector<double> v;
		for(int j=0; j<n; j++){
			int p;
			std::cin>>p;
			v.push_back(p);
		}
		M.push_back(v);
	}
	try{
		M=OgledaloMatrica(M);
	}
	    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
    	return 2;
    }
	std::cout<<"\nRezultantna matrica:\n";
	for(int i=0; i<(int)M.size(); i++){
		for(int j=0; j<(int)M[i].size(); j++)
			std::cout<<std::setw(4)<<M[i][j];
		std::cout<<"\n";
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

std::vector<std::vector<double>> horizontalnoOgledalo(std::vector<std::vector<double>> m){
	
	auto novam=m;
	
	if(m.size()==0)
		return m;
	
	for(int i(0);i<m.size();i++){
		for(int j(0);j<m[i].size();j++){
			
			novam[i][j]=m[i][m[i].size()-1-j];
		}
	}
	return novam;
}

std::vector<std::vector<double>> vertikalnoOgledalo (std::vector<std::vector<double>> m){
	
	auto novam=m;
	
	if(m.size()==0)
		return m;
		
	for(int j(0);j<m[0].size();j++){
		for(int i(0);i<m.size();i++){
			
			novam[i][j]=m[m.size()-i-1][j];
		}
	}
	
	return novam;
}
std::vector<std::vector<double>> kombinovanoOgledalo (std::vector<std::vector<double>> m){
	
	auto novam=m;
	
	if(m.size()==0)
		return m;
	
	for(int i(0);i<m.size();i++){
		for(int j(0);j<m[i].size();j++){
			
			novam[i][j]=m[m.size()-i-1][m[i].size()-j-1];
			
		}
	}
	
	
	return novam;
}


std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica){
	
	for(int s(0);s<matrica.size();s++){
		
		if(matrica[s].size()!=matrica[0].size()) throw std::domain_error ("Matrica nije korektna");
	}
	
	std::vector<std::vector<double>> rezultat(matrica.size()*3);
	std::vector<std::vector<double>> h,v,hv;
	
	h=horizontalnoOgledalo(matrica);
	v=vertikalnoOgledalo(matrica);
	hv=kombinovanoOgledalo(matrica);
	
	std::vector<std::vector<std::vector<std::vector<double>>>> mf={{hv,v,hv},{h,matrica,h},{hv,v,hv}};
	
	int br(0);
	
	for(int i(0);i<mf.size();i++){
		for(int j(0);j<matrica.size();j++){
			for(int k(0);k<3;k++){
				for(int l(0);l<mf[i][k][j].size();l++){
					rezultat[br].push_back(mf[i][k][j][l]);
			}
		}
		
		br++;
	}
	}
	
	return rezultat;
}
int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::vector<std::vector<double>> matrica(m,std::vector<double>(n));
	
	
	std::cout<<"Unesite elemente matrice: ";
	
	for(int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			
			std::cin>>matrica[i][j];
		}
	}
	std::cout<<std::endl;
	
	std::vector<std::vector<double>> rezultantnamatrica;
	
	try {
	
	rezultantnamatrica=OgledaloMatrica(matrica);
	
	std::cout<<"Rezultantna matrica: "<<std::endl;
	
	for(int k(0);k<rezultantnamatrica.size();k++){
		for(int l(0);l<rezultantnamatrica[k].size();l++){
			
			std::cout<<std::setw(4)<<rezultantnamatrica[k][l];
		}
		
		std::cout<<std::endl;
	}
	
	}
	catch(std::domain_error e){
		std::cout<<e.what();
	}
	return 0;
}
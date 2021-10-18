#include <iostream>
#include <vector> 
#include <iomanip>
#include <stdexcept>


typedef std::vector<std::vector<double>>  Matrica;

bool IspravnostMatrice(Matrica m, int brred, int brkol){
	int brelem;
	for(int i=0;i<brred;i++){
		brelem=m[i].size();
		if(brelem!=brkol)return false;
		}
	return true;
}

Matrica Horizontalna(Matrica m){
	Matrica horiz (m.size(),std::vector<double>(m[0].size()));
	double element;
	for(int i=0;i<m.size();i++){
		for(int j=m[0].size()-1;j>=0;j--){
			element=m[i][j];
			horiz[i][abs(j-(m[0].size())+1)]=element;
			}
			}
	return horiz;
}
Matrica Vertikalna(Matrica m){
	Matrica vertik (m.size(),std::vector<double>(m[0].size()));
	double element;
		for(int i=m.size()-1;i>=0;i--){
		for(int j=0;j<m[i].size();j++){
			element=m[i][j];
			vertik[abs(i-m.size()+1)][j]=element;
			}
		}
	return vertik;
}

Matrica OgledaloMatrica(Matrica m){
	
	if(m.size()==0){
		return m;
	}
	else if(m[0].size()==0){
		int velred=m.size()*3;
		std::vector<std::vector<double>> temp1(velred,std::vector<double>(0));
		return temp1;
	}
	int red,kol;
	red=m.size();
	kol=m[0].size();
	if(!IspravnostMatrice(m,red,kol)) throw std::domain_error("Matrica nije korektna");
	Matrica TrazenaMatrica(3*red,std::vector<double> (3*kol));
	
	for(int i=0;i<TrazenaMatrica.size();i++){
		for(int j=0;j<TrazenaMatrica[0].size();j++){
			if(i<red){
				if(j<kol || j>=(2*kol))TrazenaMatrica[i][j]=Horizontalna(Vertikalna(m))[i][j%kol];
				else TrazenaMatrica[i][j]=Vertikalna(m)[i][j%kol];
			}
			else if(i>=red && i<2*red){
				if(j<kol || j>=2*kol) TrazenaMatrica[i][j]=Horizontalna(m)[i%red][j%kol];
				else TrazenaMatrica[i][j]=m[i%red][j%kol];
			}
			else {
				if(j<kol || j>=2*kol)TrazenaMatrica[i][j]=Horizontalna(Vertikalna(m))[i%red][j%kol];
				else TrazenaMatrica[i][j]=Vertikalna(m)[i%red][j%kol];
			}
		}
	}
	return TrazenaMatrica;
}
void IspisiMatricu(Matrica m){
	for(auto red:m){
		for(auto x:red) std::cout << std::setw(4) <<x;
		std::cout  << std::endl;
	}
}
 

int main ()
{   

	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	try{
		std::cin >> m>>n;
		if(m<0 ||n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	}
	catch(std::domain_error greska){
		std::cout<<greska.what()<<std::endl;
		return 0;
	}
	Matrica mat(m,std::vector<double>(n));
	std::cout << "Unesite elemente matrice: "<<std::endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin >> mat[i][j];
		}
	}
	std::cout << "Rezultantna matrica: " << std::endl;
	IspisiMatricu(OgledaloMatrica(mat));
	return 0;
	
	
}
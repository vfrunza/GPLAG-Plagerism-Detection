#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <stdexcept>
std::vector<std::vector<double>>HM(std::vector<std::vector<double>>v){
	
	double temp;
	for(int i=0;i<v.size();i++){
		for(int j=v[0].size()-1;j>=0;j--){
			for(int k=0;k<j;k++){
				temp = v[i][k];
				v[i][k] = v[i][k+1];
				v[i][k+1] = temp;
			}
		}
	}
	
	return v;
}

std::vector<std::vector<double>>VM(std::vector<std::vector<double>>v){
	
	double temp;
	for(int i=0;i<v[0].size();i++){
		for(int j=v.size()-1;j>=0;j--){
			for(int k=0;k<j;k++){
				temp = v[k][i];
				v[k][i] = v[k+1][i];
				v[k+1][i] = temp;
			}
		}
	}
	
	return v;
}

std::vector<std::vector<double>>HVM(std::vector<std::vector<double>>v){
	
	std::vector<std::vector<double>>p(HM(v));
	p = VM(p);
	return p;
	
}

std::vector<std::vector<double>>OgledaloMatrica(std::vector<std::vector<double>> v){

	std::vector<std::vector<double>>p;
	if(v.empty())return v;
	
	//provjera za grbavu matricu 
	bool grbava(false);
	int sirina_reda = v[0].size();
	for(int i=0;i<v.size();i++){
		if(v[i].size() != sirina_reda){
			grbava = true;
			break;
		}
	}
	
	if(grbava)throw std::domain_error("Matrica nije korektna");
	
	p.resize(3*v.size());
	
	
	
	for(int i=0;i<p.size();i++)p[i].resize(3*(int)(v[0].size()));
	
	std::vector<std::vector<double>>hm(HM(v));
	std::vector<std::vector<double>>vm(VM(v));
	std::vector<std::vector<double>>hvm(HVM(v));
	
	int duzina = v.size();
	int sirina = v[0].size();
	
	//prvi red hvm vm hvm
	for(int i=0;i<duzina;i++){
		
		for(int j=0;j<sirina;j++){
			p[i][j] = hvm[i][j];
		}
		
		for(int j=0;j<sirina;j++){
			p[i][j+sirina] = vm[i][j];
		}
		
		for(int j=0;j<sirina;j++){
			p[i][j+2*sirina] = hvm[i][j];
		}
		
	}
	
	
	//drugi red hm M h 
	for(int i=duzina;i<2*duzina;i++){
		
		for(int j=0;j<sirina;j++){
			p[i][j] = hm[i-duzina][j];
		}
		
		for(int j=0;j<sirina;j++){
			p[i][j+sirina] = v[i-duzina][j];
		}
		
		for(int j=0;j<sirina;j++){
			p[i][j+2*sirina] = hm[i-duzina][j];
		}
		
	}
	
	
	//treci red
	for(int i=2*duzina;i<3*duzina;i++){
		
		for(int j=0;j<sirina;j++){
			p[i][j] = hvm[i-2*duzina][j];
		}
		
		for(int j=0;j<sirina;j++){
			p[i][j+sirina] = vm[i-2*duzina][j];
		}
		
		for(int j=0;j<sirina;j++){
			p[i][j+2*sirina] = hvm[i-2*duzina][j];
		}
		
	}
	
	return p;
	
}

	
	






int main ()
{
	
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::vector<std::vector<double>>v;
	
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	v.resize(m);
	for(int i=0;i<m;i++)v[i].resize(n);
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>v[i][j];
		}
	}
	


	
	try{
			
	std::vector<std::vector<double>>p(OgledaloMatrica(v));
	std::cout<<"\nRezultantna matrica: "<<std::endl;
	for(std::vector<double>red: p){
		for(double x: red){
			std::cout<<std::setw(4)<<x;
		}
		std::cout<<std::endl;
	}
	
	}catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}



	return 0;
}










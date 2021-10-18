/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<stdexcept>

std::vector<std::vector<double>> h(std::vector<std::vector<double>> m){
	
	std::vector<std::vector<double>> hm(m.size());
	for(int i=0;i<m.size();i++) hm[i].resize(m[i].size());
	
	for(int i(0);i<m.size();i++){
		std::vector<double> v;
		for(int j(m[i].size()-1);j>=0;j--){
			v.push_back(m[i][j]);
		}
		hm[i]=v;
	}
	return hm;
}

std::vector<std::vector<double>> v(std::vector<std::vector<double>> m){
	
	std::vector<std::vector<double>> vm(m.size());
	for(int i=0;i<m.size();i++) vm[i].resize(m[i].size());
	
	for(int i(0);i<m.size();i++){
		std::vector<double> v;
		for(int j(0);j<m[i].size();j++){
			v.push_back(m[i][j]);
		}
		vm[m.size()-1-i]=v;
	}
	return vm;
}

std::vector<std::vector<double>> hv(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> temp;
	temp=v(h(m));
	return temp;
}



std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> m){
	
	for (int i = 0; i < m.size(); i++) {
		if (m[i].size() != m[0].size()) {
			throw std::domain_error("Matrica nije korektna");
		}
	}
	 
   	std::vector<std::vector<double>> ogl(3*m.size());
   	
   	for(int i=0;i<ogl.size();i++) ogl[i].resize(3*m[0].size());
   	
   	for(int i=0;i<ogl.size();i++){
   		for(int j=0;j<ogl[i].size();j++){
   			if(i<m.size()){
   				if(j<m[i].size()) ogl[i][j]=hv(m)[i][j];
   				else if(j<2*m[i].size()) ogl[i][j]=v(m)[i][j-m[i].size()];
   				else ogl[i][j]=hv(m)[i][j-2*m[i].size()];
   			}
   			else if(i<2*m.size()){
   				if(j<m[i-m.size()].size()) ogl[i][j]=h(m)[i-m.size()][j];
   				else if(j<2*m[i-m.size()].size()) ogl[i][j]=m[i-m.size()][j-m[i-m.size()].size()];
   				else ogl[i][j]=h(m)[i-m.size()][j-2*m[i-m.size()].size()];
   			}
   			else{
   				if(j<m[i-2*m.size()].size()) ogl[i][j]=hv(m)[i-2*m.size()][j];
   				else if(j<2*m[i-2*m.size()].size()) ogl[i][j]=v(m)[i-2*m.size()][j-m[i-2*m.size()].size()];
   				else ogl[i][j]=hv(m)[i-2*m.size()][j-2*m[i-2*m.size()].size()];
   			}
   		}
   	}
   	
   	
	return ogl;
}

int main ()
{
	try {
		int m, n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(m<0 || n<0){ std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	
		std::vector<std::vector<double>> mat(m);
		for(int i=0;i<m;i++) mat[i].resize(n);
		std::cout<<"Unesite elemente matrice: "<<std::endl;
	

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				std::cin>>mat[i][j];
			}
			
		}
		
		std::cout<<"Rezultantna matrica: "<<std::endl;
		if(m==0 && n==0) return 0;
		std::vector<std::vector<double>> fin;
		fin=OgledaloMatrica(mat);
		for(int i=0;i<fin.size();i++){
			for(int j=0;j<fin[i].size();j++){
				std::cout<<std::setw(4)<<fin[i][j];
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	
	return 0;
}
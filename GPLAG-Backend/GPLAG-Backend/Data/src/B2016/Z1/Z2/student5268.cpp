#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
std::vector<std::vector<double>> UnesiMatricu(int red,int kol){
	std::vector<std::vector<double>> m(red,std::vector<double> (kol));
	
	for(int i=0;i<red;i++){
		for(int j=0;j<kol;j++){
		
			std::cin >> m[i][j];
		}
		
	}
	return m;
} 
std::vector<std::vector<double>> Horizontala(std::vector<std::vector<double>> m){
	std::vector<double> pomv(m[0].size());
	for(int i=0;i<int(m.size()/2);i++){
	   pomv=m[i];
	   m[i]=m[m.size()-1-i];
	   m[m.size()-1-i]=pomv;
	}
	return m;
}
std::vector<std::vector<double>> Vertikala(std::vector<std::vector<double>> m){
	double pom;
	for(int i=0;i<m[0].size()/2;i++){
          for(int j=0;j<m.size();j++){
          	pom=m[j][i];
          	m[j][i]=m[j][m[0].size()-i-1];
          	m[j][m[0].size()-i-1]=pom;
          }
	}
	return m;
}
std::vector<std::vector<double>> Kombinovano(std::vector<std::vector<double>> m){
	return Horizontala(Vertikala(m));
	
}
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> m){
	if(m.size()==0)
	return m;
	int grb=m[0].size();
	for(int i=1;i<m.size();i++){
		if(m[i].size()!=grb)
		throw std::domain_error("Matrica nije korektna");
	}
	std::vector<std::vector<double>> o(m.size()*3,std::vector<double> (m[0].size()*3));
	std::vector<std::vector<double>> a;
	a=Kombinovano(m);
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++){
			o[i][j]=a[i][j];
			o[i+a.size()*2][j]=a[i][j];
			o[i][j+a[0].size()*2]=a[i][j];
			o[i+a.size()*2][j+a[0].size()*2]=a[i][j];
		}
	}
	std::vector<std::vector<double>> b;
	b=Vertikala(m);
	for(int i=0;i<b.size();i++){
		for(int j=0;j<b[0].size();j++){
			o[i+b.size()][j]=b[i][j];
			o[i+b.size()][j+b[0].size()*2]=b[i][j];
		}
	}
	std::vector<std::vector<double>> c;
	c=Horizontala(m);
	for(int i=0;i<c.size();i++){
		for(int j=0;j<c[0].size();j++){
			o[i][j+c[0].size()]=c[i][j];
			o[i+2*c.size()][j+c[0].size()]=c[i][j];
		}
	}
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			o[i+m.size()][j+m[0].size()]=m[i][j];
		}
	}
	return o;
}
int main (){
	
	std::vector<std::vector<double>> m;
	std::cout << "Unesite dimenzije matrice (m n): " ;
	int a,b;
	std::cin >> a>>b;
	if( a<0 || b<0 ){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
	return 0;
	}
	std::cout << "Unesite elemente matrice: " ;
	m=UnesiMatricu(a,b);
	try{
	m=OgledaloMatrica(m);
	}
	catch(std::domain_error exception){
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl<<"Rezultantna matrica: \n";
	for(int i=0;i<m.size();i++){
	for(int j=0;j<m[0].size();j++){
	std::cout <<std::setw(4)<< m[i][j];
	}
		std::cout<<std::endl;
	}
	return 0;
}
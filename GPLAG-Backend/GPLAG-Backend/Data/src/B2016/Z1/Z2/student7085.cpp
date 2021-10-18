
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>


typedef std:: vector<std:: vector<double>> matrica;

matrica horizontalno_ogledalo(matrica m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size()/2;j++){
			double temp=m[i][j];
			m[i][j]=m[i][m[i].size()-1-j];
			m[i][m[i].size()-1-j]=temp;
		}
	}
	return m;
}

matrica vertikalno_ogledalo(matrica m){
	for(int i=0;i<m.size()/2;i++){
		for(int j=0;j<m[i].size();j++){
			double temp=m[i][j];
			m[i][j]=m[m.size()-1-i][j];
			m[m.size()-1-i][j]=temp;
		}
	}
	return m;
}

matrica horizontalnoVertikalno_ogledalo(matrica m){
	return vertikalno_ogledalo(horizontalno_ogledalo(m));
}

matrica OgledaloMatrica(matrica m){
	if((m.size()==0 || m[0].size()==0) || (m.size()==0 && m[0].size()==0)){
		m.resize(3*m.size());
		return m;
	}
	for(int i=0;i<m.size();i++){
		if(m[0].size()!=m[i].size()) throw std::domain_error("Matrica nije korektna");
		}
	
	matrica velika(3*m.size(),std:: vector<double> (3*m[0].size()));
	matrica hV(horizontalnoVertikalno_ogledalo(m));
	matrica V(vertikalno_ogledalo(m));
	matrica h(horizontalno_ogledalo(m));

	
	for(int i=0;i<hV.size();i++){
		for(int j=0;j<hV[0].size();j++){
			velika[i][j]=hV[i][j];
		}
	}
	for(int i=0;i<V.size();i++){
		for(int j=0;j<V[0].size();j++){
			velika [i][j+hV[0].size()]=V[i][j];
		}
	}
	for(int i=0;i<hV.size();i++){
		for(int j=0;j<hV[0].size();j++){
			velika[i][j+2*hV[0].size()]=hV[i][j];
		}
	}
	for(int i=0;i<h.size();i++){
		for(int j=0;j<h[0].size();j++){
			velika[i+hV.size()][j]=h[i][j];
		}
	}
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			velika[i+V.size()][j+h[0].size()]=m[i][j];
		}
	}
	for(int i=0;i<h.size();i++){
		for(int j=0;j<h[0].size();j++){
			velika[i+hV.size()][j+2*h[0].size()]=h[i][j];
		}
	}
	for(int i=0;i<hV.size();i++){
		for(int j=0;j<hV[0].size();j++){
			velika[i+2*hV.size()][j]=hV[i][j];
		}
	}
	for(int i=0;i<V.size();i++){
		for(int j=0;j<V[0].size();j++){
			velika[i+2*hV.size()][j+hV[0].size()]=V[i][j];
		}
	}
	for(int i=0;i<hV.size();i++){
		for(int j=0;j<hV[0].size();j++){
			velika[i+2*hV.size()][j+2*hV[0].size()]=hV[i][j];
		}
	}
	   
	return velika;
}


int main ()
{
	int k,n;
	std:: cout<< "Unesite dimenzije matrice (m n): ";
	std:: cin>> k>>n;
	if(k<0 || n<0){
		std:: cout<< "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrica m(k,std::vector<double> (n));
	std:: cout<< "Unesite elemente matrice: ";
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			std:: cin>>m[i][j];
		}
	}
	std:: cout<<std:: endl;
	std:: cout<<"Rezultantna matrica: "<<std::endl;
	try{
	auto a=OgledaloMatrica(m);

	for(int i=0;i<a.size();i++){
		for(int j=0;j< a[0].size();j++){
			std:: cout<<std:: right<<std:: setw(4)<<a[i][j];
         if(j==a[i].size()-1)std::cout<< std:: endl;
		}
	}
	}
	catch(std::domain_error greska){
	   std:: cout<< "IZUZETAK: "<<greska.what()<<std::endl;
	}
	return 0;
}
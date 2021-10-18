#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>





std::vector<std::vector<double>> Horizontalnaf(std::vector<std::vector<double>> Osnovna){
	for(int i=0; i<Osnovna.size();i++){
		for(int j=0; j<Osnovna[i].size()/2;j++){
			double element(Osnovna[i][j]);
			Osnovna[i][j]=Osnovna[i][Osnovna[i].size()-j-1];
			Osnovna[i][Osnovna[i].size()-j-1]=element;
		}
	}
	return Osnovna;
}

std::vector<std::vector<double>> Vertikalnaf(std::vector<std::vector<double>> Osnovna){
	for(int i=0; i<Osnovna.size()/2;i++){
		for(int j=0;j<Osnovna[i].size();j++){
			double element(Osnovna[i][j]);
			Osnovna[i][j]=Osnovna[Osnovna.size()-1-i][j];
			Osnovna[Osnovna.size()-1-i][j]=element;
		}
	}
	return Osnovna;
}

std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> Osnovna){
	
	std::vector<std::vector<double>> Ogledalo;
	if(Osnovna.size()==0) 
		return Ogledalo;
	if(Osnovna.size()!=0 && Osnovna[0].size()==0) {
		Ogledalo.resize(3*Osnovna.size());
		return Ogledalo;
		
	}
	
	
	if(Osnovna.size()!=0 &&Osnovna.size()!=1 ){
		int sirina(Osnovna[0].size());
		for(int i=0; i<Osnovna.size(); i++)
		if(Osnovna[i].size()!=sirina ) throw std::domain_error ("Matrica nije korektna");
	}
	std::vector<std::vector<double>> Horizontalna(Horizontalnaf(Osnovna));
	std::vector<std::vector<double>> Vertikalna(Vertikalnaf(Osnovna));
	std::vector<std::vector<double>> VertikalnaIHorizontalna(Vertikalnaf(Horizontalnaf(Osnovna)));
	int m(Osnovna.size());
	int n(Osnovna[0].size());
	
	
	Ogledalo.resize(3*m);
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			Ogledalo[i].push_back(VertikalnaIHorizontalna[i][j]);
		}
		for(int j=0;j<n;j++){
				Ogledalo[i].push_back(Vertikalna[i][j]);
		}
		for(int j=0;j<n;j++){
				Ogledalo[i].push_back(VertikalnaIHorizontalna[i][j]);
		}
	}
	for(int i=m;i<2*m;i++){
		for(int j=0;j<n;j++){
			Ogledalo[i].push_back(Horizontalna[i-m][j]);
		}
		for(int j=0;j<n;j++){
				Ogledalo[i].push_back(Osnovna[i-m][j]);
		}
		for(int j=0;j<n;j++){
				Ogledalo[i].push_back(Horizontalna[i-m][j]);
		}
	}
	for(int i=2*m;i<3*m;i++){
	for(int j=0;j<n;j++){
			Ogledalo[i].push_back(VertikalnaIHorizontalna[i-2*m][j]);
		}
		for(int j=0;j<n;j++){
				Ogledalo[i].push_back(Vertikalna[i-2*m][j]);
		}
		for(int j=0;j<n;j++){
				Ogledalo[i].push_back(VertikalnaIHorizontalna[i-2*m][j]);
		}
	}
	
	return Ogledalo;
}
int main ()
{
	try{
		int m,n;
		std::cout << "Unesite dimenzije matrice (m n): ";
		std::cin >> m >> n;
		if(m<0 || n<0){
			std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
			return 0;
		}
		
		std::cout << "Unesite elemente matrice: ";
		std::vector<std::vector<double>> matrica (m,std::vector<double>());
	
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				double element;
				std::cin >> element ;
				matrica[i].push_back(element);
			}
		}
		

		std::cout << std::endl <<"Rezultantna matrica:"<< std::endl;
		std::vector<std::vector<double>> Ogledalo (OgledaloMatrica(matrica));
		for(int i=0;i<Ogledalo.size();i++){
			for(int j=0;j<Ogledalo[i].size();j++){
				std::cout << std::right << std::setw(4) << Ogledalo[i][j];
			}
			std::cout<< std::endl;
		}

	}
	catch(std::domain_error exception){
		std::cout << exception.what() ;
	}
	
	return 0;
}
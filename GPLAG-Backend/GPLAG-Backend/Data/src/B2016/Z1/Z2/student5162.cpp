/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
// Napravi funkcije koje prave horizontalno i vertikalno ogledalo matrice
// kombinovano ogledalo ces dobiti tako sto pozoves i horiz i vertik funkciju
//posto je vektor, mozes mijenjati velicinu
//probaj sa dekom tako da mozes i push front i push back, ali onda opet na kraju moras prebaciti u vektor
//
#include <iostream>
#include <vector>
#include<iomanip>
#include <stdexcept>

std::vector<double> Saberi (std::vector<double> v1, std::vector<double> v2){
	
	std::vector<double> novi;
	for (int i(0); i<v1.size(); i++){
		novi.push_back(v1.at(i));
	}
		for (int i(0); i<v2.size(); i++){
		novi.push_back(v2.at(i));
	}
		for (int i(0); i<v1.size(); i++){
		novi.push_back(v1.at(i));
	}
	return novi;
}

typedef std::vector<std::vector<double>> Matrica;

Matrica HorizontalnoOgledalo (Matrica m){//obrce redoslijed kolona

	for ( int i(0); i<m.size(); i++){
		
		for ( int j(0); j<(m[i].size())/2; j++){
			
			double temp;
			temp=m[i][j];
			m[i][j]=m[i][ m[i].size() - 1 - j ];
			m[i][ m[i].size() - 1 - j ] = temp;
		}
	}
	return m;
}
Matrica VertikalnoOgledalo (Matrica m){  //obrce redoslijed redova
	
	for (int j(0); j<(m[0].size()); j++){
		for( int i(0); i<(m.size())/2; i++){
			double temp;
			temp=m[i][j];
			m[i][j]=m[m.size()-1-i][j];
			m[m.size()-1-i][j]=temp;
			
		}
	}
	return m;
	
}

Matrica OgledaloMatrica(Matrica mat){
	
	if (mat.size()==0) return mat;
	for(int i(1); i<mat.size(); i++){
		if(mat[0].size()!=mat[i].size()) throw std::domain_error ("Matrica nije korektna");
	}
	
	Matrica H, V, HV, nova;
	
	H=HorizontalnoOgledalo(mat);
	V=VertikalnoOgledalo(mat);
	HV=HorizontalnoOgledalo(VertikalnoOgledalo(mat));
	if(mat.size()==0) return mat;
	
	for (int i(0); i<3*(mat.size()); i++){
		if(i<mat.size()) nova.push_back( Saberi(HV[i], V[i]) );
		if(i>=mat.size() && i<2*mat.size()) nova.push_back( Saberi(H[i-mat.size()], mat[i-mat.size()] ) );
		if(i>=2*mat.size() && i<3*mat.size()) nova.push_back( Saberi(HV[i-(2*mat.size())], V[i-(2*mat.size())] ) ) ;
	}
	
	
	return nova;
	
}

int main (){
	try{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin>>m>>n;
	if (m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica mat(m, std::vector<double>(n));
	for(int i(0); i<m; i++){
		for(int j(0); j<n; j++){
			double temp;
			std::cin>>temp;
			mat[i][j]=temp;
		}
	}
	
	mat=OgledaloMatrica(mat);
	std::cout<<"\nRezultantna matrica: "<<std::endl;
	
	for(int i(0); i<mat.size(); i++){
		
		for (int j(0); j<mat[0].size(); j++){
			
		std::cout<<std::setw(4)<<mat[i][j];
		}
		
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}

	return 0;
}
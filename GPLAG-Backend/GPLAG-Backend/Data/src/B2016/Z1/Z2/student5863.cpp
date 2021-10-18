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

Matrica HorizontalnoOgledalo(Matrica m){
	Matrica mat(m.size(),std::vector<double>(m[0].size()));
	
	for(int i=0; i< int(m.size()); i++){
		int k=0;
		for(int j=int(m[0].size())-1; j>=0; j--){
			mat[i][k] = m[i][j];
			k++;
		}
	}
	
	return mat;
}

Matrica VertikalnoOgledalo( Matrica m){
	Matrica mat(m.size(),std::vector<double>(m[0].size()));
	int k=0;
	for(int i= int(m.size())-1; i>=0; i--){
		for(int j=0; j<int(m[0].size()); j++)
		mat[k][j] = m[i][j];
		k++;
	}
	
	return mat;
}

Matrica KombinovanoOgledalo(Matrica m){
	Matrica mat(m.size(), std::vector<double>(m[0].size()));
	
	mat = HorizontalnoOgledalo(m);
	mat = VertikalnoOgledalo(mat);
	
	return mat;
}

bool jelGrbava( Matrica m){
	int k=1;
	while(k < m.size()){
		if(m[0].size() < m[k].size() || m[k].size() < m[0].size()) return true;
		
		k++;
	}
	return false;
}


Matrica OgledaloMatrica(Matrica m){
		if(m.size() ==0 ) return m;
	else if(jelGrbava(m)) throw std::domain_error("Matrica nije korektna");
		Matrica matrica(3*m.size(), std::vector<double>(3*m[0].size()));
	
	Matrica kombinovana = KombinovanoOgledalo(m);
	Matrica horizontalna = HorizontalnoOgledalo(m);
	Matrica vertikalna = VertikalnoOgledalo(m);
	int brojRedova = m.size();
	int brojKolona = m[0].size();
	
	int i=0,j=0,k=0,l=0;
	while (i < int(matrica.size())) {
		j=0;
		while( j < int(matrica[0].size())){
			if( i == brojRedova || i == 2*brojRedova || i == 3*brojRedova) l=0;
			k=0;
			if(( i>=0 && i < brojRedova) ||(i>= 2*brojRedova && i < matrica.size())){
			while( k < brojKolona){
				if( j>=0 && j < brojKolona){
					while(j>=0 && j < brojKolona){
					matrica[i][j] = kombinovana[l][k];
					j++;
					k++;
				}
				}
				else if(j >= brojKolona && j < 2*brojKolona){
					while(j >= brojKolona && j < 2*brojKolona){
						matrica[i][j] = vertikalna[l][k];
						j++;
						k++;
					}
				}
				else if(j >= 2*brojKolona && j < int(matrica[0].size())){
					while (j >= 2*brojKolona && j < int(matrica[0].size())) {
						matrica[i][j] = kombinovana[l][k];
						j++;
						k++;
					}
				}
			}
		}
		else{
			
				while( k < brojKolona){
				if( j>=0 && j < brojKolona){
					while(j>=0 && j < brojKolona){
					matrica[i][j] = horizontalna[l][k];
					j++;
					k++;
				}
				}
				else if(j >= brojKolona && j < 2*brojKolona){
					while(j >= brojKolona && j < 2*brojKolona){
						matrica[i][j] = m[l][k];
						j++;
						k++;
					}
				}
				else if(j >= 2*brojKolona && j < int(matrica[0].size())){
					while (j >= 2*brojKolona && j < int(matrica[0].size())) {
						matrica[i][j] = horizontalna[l][k];
						j++;
						k++;
					}
				}
			}
			
		}
		}
		i++;
		l++;
	}
	
	
	
	return matrica;
}

int main ()
{
	
	try{
		std::cout<<"Unesite dimenzije matrice (m n): ";
		int m,n;
		std::cin>>m>>n;
		if(m < 0 || n < 0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		Matrica mat(m,std::vector<double>(n));
		std::cout<<"Unesite elemente matrice: ";
		for(int i=0; i< m; i++){
			for(int j=0; j<n; j++)
				std::cin>>mat[i][j];
			
		}
		
		Matrica rezM = OgledaloMatrica(mat);
		std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
		
		for(std::vector<double> red : rezM){
			for(double element : red) std::cout<<std::setw(4)<<element;
			std::cout<<std::endl;
		}
	}catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}
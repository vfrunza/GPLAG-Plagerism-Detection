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

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica primljena){
	int m,n;
	m=primljena.size();
	if(m!=0){
		n=primljena[0].size();
	//provjeri je li grbava
	for(int i=0; i<primljena.size(); i++){
		if(primljena[i].size()!=n)
			throw std::domain_error("Matrica nije korektna");
	}
	//formiraj horizontalnu
	Matrica horizontalna(m,std::vector<double>(n));
	for(int i=0; i<m; i++){
		int x;
		x=n-1;
		for(int j=0; j<n; j++){
			horizontalna[i][j]=primljena[i][x];
			x--;
		}
	}
	
	//formiraj vertikalnu
	Matrica vertikalna(m,std::vector<double>(n));
	int x=m-1;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			vertikalna[i][j]=primljena[x][j];
		}
		x--;
	}
	
	//formiraj kombinovanu
	x=m-1;
	Matrica kombinovana(m,std::vector<double>(n));
	for(int i=0; i<m; i++){
		int y=n-1;
		for(int j=0; j<n; j++){
			kombinovana[i][j]=primljena[x][y];
			y--;
		}
		x--;
	}
	
	//formiraj matricu koja se vraca iz funkcije
	int s,p;
	s=3*m;
	p=3*n;
	Matrica vracena(s,std::vector<double>(p));
	int k,red;
	red=0;
	// kombinacija kombinovana vertikalna kombinovana
	for(int i=0; i<m; i++){
		k=0;
		for(int j=0; j<n; j++){
			vracena[red][k]=kombinovana[i][j];
			k++;
		}
		for(int j=0; j<n; j++){
			vracena[red][k]=vertikalna[i][j];
			k++;
		}
		for(int j=0; j<n; j++){
			vracena[red][k]=kombinovana[i][j];
			k++;
		}
		red++;
	}
	// kombinacija horizontalna matrica horizontalna
	for(int i=0; i<m; i++){
		k=0;
		for(int j=0; j<n; j++){
			vracena[red][k]=horizontalna[i][j];
			k++;
		}
		for(int j=0; j<n; j++){
			vracena[red][k]=primljena[i][j];
			k++;
		}
		for(int j=0; j<n; j++){
			vracena[red][k]=horizontalna[i][j];
			k++;
		}
		red++;
	}
	// kombinovana vertikalna kombinovana
	for(int i=0; i<m; i++){
		k=0;
		for(int j=0; j<n; j++){
			vracena[red][k]=kombinovana[i][j];
			k++;
		}
		for(int j=0; j<n; j++){
			vracena[red][k]=vertikalna[i][j];
			k++;
		}
		for(int j=0; j<n; j++){
			vracena[red][k]=kombinovana[i][j];
			k++;
		}
		red++;
	}
	return vracena;
	}
	//ovo sam dodala
	Matrica prazna_vracena;
	return prazna_vracena;
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	Matrica unesena(m,std::vector<double>(n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin >> unesena[i][j];
		}
	}
	Matrica vracena;
	try {
		vracena=OgledaloMatrica(unesena);
		std::cout << std::endl;
		std::cout << "Rezultantna matrica: " << std::endl;
		for(int i=0; i<vracena.size(); i++){
			for(int j=0; j<vracena[i].size(); j++){
				std::cout << std::setw(4) << vracena[i][j];
			}
			std::cout << std::endl;
		}
	} catch (std::domain_error tekst){
		std::cout << tekst.what();
	}
	return 0;
}
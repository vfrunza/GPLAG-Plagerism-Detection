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

//HORIZONTALA
std::vector<std::vector<double>>Horizontal(std::vector<std::vector<double>> matrica) {
	int temp;
	int temp1;
	int a=0;
	
	temp=matrica.size();
	temp1=matrica[0].size();
	std::vector<std::vector<double>>matrixa(temp, std::vector<double>(temp1));
	for(int i=0; i<temp; i++) {
		for(int j=temp1-1; j>=0; j--) {
			matrixa[i][j]=matrica[i][a];
			a++;
		}
		a=0;
	}
	return matrixa;
}
// VERTIKALA
std::vector<std::vector<double>>Vertikalna(std::vector<std::vector<double>> matrica) {
	int temp;
	int temp1;
	int a=0;
	
	temp=matrica.size();
	temp1=matrica[0].size();
	std::vector<std::vector<double>>matrixa(temp, std::vector<double>(temp1));
	for(int i=temp-1; i>=0; i--) {
		for(int j=0; j<temp1; j++) {
			matrixa[i][j]=matrica[a][j];
		}
		a++;
	}
	return matrixa;
} 
//KOMBINACIJA
std::vector<std::vector<double>>Kombinaciona(std::vector<std::vector<double>> matrica) {
	int temp;
	int temp1;
	int a=0;
	int b=0;
	
	temp=matrica.size();
	temp1=matrica[0].size();
	std::vector<std::vector<double>>matrixa(temp, std::vector<double>(temp1));
	for(int i=temp-1; i>=0; i--) {
		for(int j=temp1-1; j>=0; j--) {
			matrixa[i][j]=matrica[a][b];
			b++;
		}
		a++;
		b=0;
	}
	return matrixa;
}
//OBICNA
std::vector<std::vector<double>>Obicna(std::vector<std::vector<double>> matrica) {
	int temp;
	int temp1;
	
	temp=matrica.size();
	temp1=matrica[0].size();
	std::vector<std::vector<double>>matrixa(temp, std::vector<double>(temp1));
	for(int i=0; i<temp; i++) {
		for(int j=0; j<temp1; j++) {
			matrixa[i][j]=matrica[i][j];
		}
	}
	return matrixa;
}

std::vector<std::vector<double>>OgledaloMatrica(std::vector<std::vector<double>> matrica1) {
	
	if(matrica1.size()==0) return matrica1;
	for(int i=1; i<matrica1.size(); i++) {
		if(matrica1[0].size()!=matrica1[i].size()) throw std::domain_error ("Matrica nije korektna");
	}
	
	int red, kolona;
	int a, b;
	red=matrica1.size();
	kolona=matrica1[0].size();
	std::vector<std::vector<double>> matrix1(red*3, std::vector<double>(kolona*3));
	std::vector<std::vector<double>> POMOCNI(red, std::vector<double>(kolona));
	
	for(int i=0; i<red*3; i++) {
		for(int j=0; j<kolona*3; j++) {
			if((i==0 && j==0) || (i==0 && j==(kolona*2)) || (i==(red*2) && j==0) || (i==(red*2) && j==(kolona*2))) {
				POMOCNI=Kombinaciona(matrica1);
				a=0;
				for(int k=i; k<i+red; k++) {
					b=0;
					for(int l=j; l<j+kolona; l++) {
						matrix1[k][l]=POMOCNI[a][b];
						b++;
					}
					a++;
				} 
				} else {
					if((i==0 && j==kolona) || (i==(red*2) && j==kolona)) {
						POMOCNI=Vertikalna(matrica1);
						a=0;
						for(int k=i; k<i+red; k++) {
							b=0;
							for(int l=j; l<j+kolona; l++) {
								matrix1[k][l]=POMOCNI[a][b];
								b++;
							}
							a++;
						}	
					} else {
						if((i==red && j==0) || (i==red && j==(kolona*2))) {
							POMOCNI=Horizontal(matrica1);
								a=0;
								for(int k=i; k<i+red; k++) {
									b=0;
									for(int l=j; l<j+kolona; l++) {
										matrix1[k][l]=POMOCNI[a][b];
										b++;
									}
									a++;
								}
							} else {
							if(i==red && j==kolona) {
								POMOCNI=Obicna(matrica1);
								a=0;
									for(int k=i; k<i+red; k++) {
										b=0;
										for(int l=j; l<j+kolona; l++) {
											matrix1[k][l]=POMOCNI[a][b];
											b++;
										}
									a++;
									}
								}
							}
						}
					}
				}
			}	
	
	return matrix1;
}

int main () {
	try {
	int m;
	int n;
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!\n";
		return 0;
	}
	std::vector<std::vector<double>>matrica(m, std::vector<double>(n));
	std::vector<std::vector<double>>monster;
	std::cout << "Unesite elemente matrice:\n";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			double temp;
			std::cin >> temp;
			matrica[i][j]=temp;
		}
	}
	std::cout << "Rezultantna matrica: " << std::endl;
	monster=OgledaloMatrica(matrica);
	for(int i=0; i<m*3; i++) {
		for(int j=0; j<n*3; j++) {
			if(j==(n*3)-1) std::cout << std::setw(4) << monster[i][j];
			else std::cout << std::setw(4) << monster[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}

/*	
	monster=Obicna(matrica);
	for(int i=0; i<red; i++) {
		for(int j=0; j<kolona; j++) {
			std::cout << monster[i][j];
		}
		std::cout << std::endl;
	}
*/return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> DMatrica;
DMatrica NajvecaPlaninaMatrice (const DMatrica &matrix)
{
	//PROVJERA ZA GRBAVU MATRICU
	int provjera_redova(matrix.at(0).size());
	for(int i=0; i<matrix.size(); i++) {
		if(matrix.at(i).size()!=pro
		vjera_redova) {
			throw std::domain_error ("Matrica nije korektna");
		}
	}
	//SLUCAJ KADA JE PLANINA MATRICA FORMATA 1X1
	double najveci(matrix.at(0).at(0));
	for(int i=0; i<matrix.size(); i++) {
		for(int j=0; j<matrix.size(); j++) {
			if(matrix.at(i).at(j)>najveci) {
				najveci=matrix.at(i).at(j);
			}
		}
	}
	DMatrica max_mat(1 , std::vector<double> (1));
	max_mat.at(0).at(0)=najveci;
	//ZA FORMAT PLANINE MATRICE 3X3 I VECI
	int max_dim(0);
	double max_suma(0);
	for(int i=0; i<matrix.size(); i++) {
		for(int j=0; j<matrix.at(0).size(); j++) {
			int format(2);
			DMatrica sub;
			while(format<matrix.size()) {
				//KREIRANJE PODMATRICE n x n FORMATA
				if(i+format<matrix.size() && j+format<matrix.at(i).size()) {
					sub.resize(format+1);
					for(int k=0; k<sub.size(); k++) {
						sub.at(k).resize(format+1);
					}
					DMatrica temp;
					temp.resize(format+1);
					for(int k=0; k<temp.size(); k++) {
						temp.at(k).resize(format+1);
					}
					sub=temp;
					for(int k=0; k<sub.size(); k++) {
						for(int l=0; l<sub.at(k).size(); l++) {
							sub.at(k).at(l)=matrix.at(i+k).at(l+j);
						}
					}
					//CLAN NA PRESJEKU DIJAGONALA
					int srednji((sub.size()/2));
					double potencijalni(sub.at(srednji).at(srednji));
					int kocentricni(0);
					double suma(0);
					double prethodni(0);
					int brojac(0);
					bool prekidac(true);
					//RACUNANJE SUME KOCENTRICNOG KVADRATA SA CENTROM U "POTENCIJALOM"
					while(kocentricni<=srednji-kocentricni && prekidac==true) {
						suma=0;
						for(int k=0; k<sub.size(); k++) {
							for(int l=0; l<sub.at(0).size(); l++) {
								if(k==0+kocentricni || k==sub.size()-1-kocentricni) {
									if(l>=0+kocentricni && l<=sub.size()-1-kocentricni) {
										suma+=sub.at(k).at(l);
									}
								}
								if(l==0+kocentricni || l==sub.size()-1-kocentricni) {
									if(k>0+kocentricni && k<sub.size()-1-kocentricni) {
										suma+=sub.at(k).at(l);
									}
								}
							}
						}
						brojac++;
						if(suma<potencijalni) {
							if(brojac==1) {
								prethodni=suma;
								prekidac=true;
							}
							if(brojac>1) {
								if(prethodni<suma) {
									prekidac=true;
									prethodni=suma;
								} else{
									prekidac=false;
									brojac=0;
									prethodni=0;
								} 
							}
						} else {
							prekidac=false;
						}
						kocentricni++;
					}
					//UPIS PODMATRICE U POVRATNU MATRICU
					if(prekidac==true && max_dim<=format+1) {
						if(format+1==max_dim) {
							if(potencijalni>max_suma) {
								max_mat=sub;
								max_dim=format+1;
								max_suma=potencijalni;

							}
						}
						else{
							max_mat=sub;
							max_dim=format+1;
							max_suma=potencijalni;
						}
					}
				}
				format+=2;
			}
		}
	}
	return max_mat;
}
int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	DMatrica mat(m, std::vector<double> (n));
	std::cout << "Unesite elemente matrice: " << std::endl;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin>>mat.at(i).at(j);
		}
	}
	try {
		std::cout << "Najveca planina unesene matrice je: "<<std::endl;
		DMatrica k(NajvecaPlaninaMatrice(mat));
		for(auto red : k) {
			for(auto x : red) {
				std::cout<<std::setw(6) << x;
			}
			std::cout << std::endl;
		}
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	return 0;
}
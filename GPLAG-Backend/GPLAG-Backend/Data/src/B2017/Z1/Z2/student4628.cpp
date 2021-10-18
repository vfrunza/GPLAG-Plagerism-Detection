/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::cin;
using std::cout;

typedef std::vector<std::vector<double>> Matrica;

bool NijeGrbava(Matrica mat) {
	for(int i=1; i<mat.size(); i++) {
		if(mat.at(0).size()!=mat.at(i).size()) 	return false;
	}
	return true;
}


double rangovi( Matrica mat, int i, int j) {
	double suma1(mat.at(i).at(j));
	int rang(0);
	while(1) {
		i--;
		j--;
		if(i<0 || j<0) return rang;
		int brojac1(i+2);
		int brojac2(i+2);
		if(brojac1>mat.size()) return rang;
		if(brojac2>mat.at(0).size()) return rang;
		double suma2(0);
		for(int k=i; k<brojac1; k++) {
			for(int l=j; l<brojac2; l++) {
				suma2+=mat.at(k).at(l);
			}
		}
		if((suma2-suma1)<suma1) {
			rang++;
			suma1=suma2-suma1;
		}
		else break;
	}
	return rang;
}

Matrica NajvecaPlaninaMatrice(Matrica mat) {
	if(!NijeGrbava(mat)) throw std::domain_error("Matrica nije korektna");
	Matrica mat_rangovi(mat);
	double najveci(mat.at(0).at(0));
	int max_rang(0), maxi(0), maxj(0);
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(0).size(); j++) {
			mat_rangovi.at(i).at(j)=rangovi(mat, i, j);
			if(mat_rangovi.at(i).at(j)>=max_rang) {
				if(mat_rangovi.at(i).at(j)>=max_rang) {
				if(mat_rangovi.at(i).at(j)==max_rang) {
					if(mat.at(i).at(j)>najveci) {
						najveci=mat.at(i).at(j);
						max_rang=mat_rangovi.at(i).at(j);
						maxi=i;
						maxj=j;
					}
					else if(mat.at(i).at(j)==najveci) {
						if(i<maxi) {
							max_rang=mat_rangovi.at(i).at(j);
							maxi=i;
							maxj=j;
						}
						else if(i==maxi && j<maxj) {
							max_rang=mat_rangovi.at(i).at(j);
							maxi=i;
							maxj=j;
						}
					}
				}
				else {
				max_rang=mat_rangovi.at(i).at(j);
				najveci=mat.at(i).at(j);
				maxi=i;
				maxj=j;
				}
			}
		}
	}
}	
	Matrica povratna;

		
	if(max_rang==0) {	
		std::vector<double> pom;
		pom.push_back(najveci);
		povratna.push_back(pom);
		return povratna;
	}
	
	if(mat.size()==0) return povratna; 
	
	int vel(3);
	int brojac(1);
	while(brojac<max_rang) {
		vel+=2;
		brojac++;
	}
	int duzina1=maxi-max_rang, duzina2=maxj-max_rang;
	for(int i=duzina1; i<duzina1+vel;  i++) {
		std::vector<double> pomocni;
		for(int j=duzina2; j<duzina2+vel; j++) {
			pomocni.push_back(mat.at(i).at(j));
		}
		povratna.push_back(pomocni);
	}
	return povratna;
}


int main ()
{
	try {
	cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0) {
	cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
	}
	cout<<"Unesite elemente matrice: "<<std::endl;
	Matrica mat(m, std::vector<double>(n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin>>mat.at(i).at(j);
		}
	}
	cout<<"Najveca planina unesene matrice je: "<<std::endl;
	Matrica planina=NajvecaPlaninaMatrice(mat);
	for(auto red: planina) {
		for( auto kolona: red) {
			cout<<std::right<<std::setw(6)<<kolona;
		}
		cout<<std::endl;
	}
	}
	
	catch(std::domain_error izuzetak) {
		cout<<izuzetak.what();
	}
	return 0;
}
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
#include <deque>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova, int broj_kolona){
	return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

int BrojRedova (Matrica m){
	return m.size();
}
int BrojKolona (Matrica m){
//	std::cout << m[0]. size();
	return m[0].size();
}

Matrica UnesiMatricu( int broj_redova, int broj_kolona){
	Matrica m = (KreirajMatricu(broj_redova,broj_kolona));
	
	for(int i = 0; i < broj_redova; i++){
		for(int j = 0; j < broj_kolona; j++){
			std::cin >> m[i][j];
		}
	}
	return m;
}

void IspisiMatricu (Matrica m){
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[0].size(); j++){
			std::cout <<std::setw(6) << m[i][j];
		}
		std::cout<<std::endl;
	}
}

Matrica NajvecaPlaninaMatrice (Matrica pocetna_matrica){
	//uslovi bacanja izuzetka
//	bool grbava = false;
//std::cout <<"MMMMMMM ";
	if (pocetna_matrica.size() == 0 || pocetna_matrica[0].size() == 0){
		Matrica prazna(KreirajMatricu(0,0));
		return prazna;
	}
	for(int i = 0; i < pocetna_matrica.size(); i++){
	//	std::cout <<"MMMMMMM ";
		int brojac(0);
		for(int j = 0; j < pocetna_matrica[0].size(); j++){
			brojac ++;
		}
		if( brojac != pocetna_matrica[0].size()) throw std::domain_error ("Izuzetak: Matrica nije korektna!");
	}
	
//	Matrica matrica_planina;
	int vrh, veci_vrh(0);
	int novi_redovi, nove_kolone, nove_dimenzije_max(0), nova_dimenzija;
	Matrica konacna_planina;
	std::vector<double> vektor_redova_i_redova, vektor_vrhova;
	
	for(int i = 0; i < pocetna_matrica.size(); i++){
		//std::cout <<"MMMMMMM ";
		for(int j = 0; j < pocetna_matrica[0].size(); j++){
		//	std::cout <<"MMMMMMM ";
			if((i > 0 && i < pocetna_matrica.size() - 1 )&& (j > 0 && j < pocetna_matrica[0].size() - 1)){
				double suma(0);
				std::cout <<"MMMMMMM ";
				suma =  (pocetna_matrica[i - 1][j - 1]) + (pocetna_matrica[i - 1][j]) + (pocetna_matrica[i - 1][j + 1]) + (pocetna_matrica[i][j - 1]) + (pocetna_matrica[i][j + 1]) + (pocetna_matrica[i + 1][j- 1]) + (pocetna_matrica[i + 1][j]) + (pocetna_matrica[i + 1][j + 1]);
			
				if (pocetna_matrica[i][j] > suma){
					vrh = pocetna_matrica[i][j];
					
				
			//	if(vrh > maksimalni_vrh) maksimalni_vrh = vrh;
					novi_redovi = (pocetna_matrica.size() - i) ;
					nove_kolone = (pocetna_matrica[0].size() - j) ;
				
					if(nove_kolone < novi_redovi) nova_dimenzija = nove_kolone;
					else if(novi_redovi < nove_kolone) nova_dimenzija = novi_redovi;
				
					if(nova_dimenzija >= nove_dimenzije_max){
						Matrica matrica_planina = KreirajMatricu(nove_dimenzije_max, nove_dimenzije_max);
						if(nova_dimenzija == nove_dimenzije_max){
							if (vrh > veci_vrh){
								
								veci_vrh = vrh; 
								int duzina, sirina;
								duzina = (nove_dimenzije_max / 2) - 1;
								sirina = (nove_dimenzije_max / 2) - 1;
								for(int k =0; k < pocetna_matrica.size() ;k++){
								std::vector<double> pomocni;
								for(int p = 0; p < pocetna_matrica[0].size(); p++){
								//	std::vector<double> pomocni;
									if((k >= (i - (nove_dimenzije_max - 1) / 2) && k <= (i - (nove_dimenzije_max - 1)/ 2)) && (p >= (j - (nove_dimenzije_max - 1) / 2) && p <= (j - (nove_dimenzije_max - 1)/ 2)))
									pomocni.push_back(pocetna_matrica[k][p]);
									}
									matrica_planina.push_back(pomocni);
								}
							}
						}
						else{
							nove_dimenzije_max = nova_dimenzija;
							veci_vrh = vrh;
							int duzina, sirina;
							duzina = (nove_dimenzije_max / 2) - 1;
							sirina = (nove_dimenzije_max / 2) - 1;
							for(int k =0; k < pocetna_matrica.size() ;k++){
								std::vector<double> pomocni;
								for(int p = 0; p < pocetna_matrica[0].size(); p++){
								//	std::vector<double> pomocni;
									if((k >= (i - (nove_dimenzije_max - 1) / 2) && k < (i - (nove_dimenzije_max - 1)/ 2)) && (p >= (j - (nove_dimenzije_max - 1) / 2) && p < (j - (nove_dimenzije_max - 1)/ 2)))
									pomocni.push_back(pocetna_matrica[k][p]);
								}
								matrica_planina.push_back(pomocni);
							}
						}
						if(i == pocetna_matrica.size() - 2 && j == pocetna_matrica[0].size() - 2) return matrica_planina;
					}
				}
			}
		}
	}
//	return konacna_planina;
}


int main(){
	
	std::cout <<"Unesite eloemente matrice (m i n): ";
	int m, n;
	std::cin >> m >> n;
	
	if(m < 0 || n < 0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	try{
	//else{
		Matrica matrica ;
		std::cout<< "Unesite elemente matrice: ";
		 matrica = UnesiMatricu(m, n);
		
		
		//	Matrica matrica;
			Matrica Planina_matrica = NajvecaPlaninaMatrice (matrica);
			std::cout << "Najveca planina unese matrice je: " << std::endl;
		//	IspisiMatricu(Planina_matrica);
		}
		catch(std::domain_error izuzetak){
			std::cout << izuzetak.what() << std::cout<< std::endl;
		//}
		
	}

return 0;	
}
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
#include <complex>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;
const double epsilon = 0.000000001;



Matrica KreirajMatricu(int broj_redova, int broj_kolona){
	return Matrica(broj_redova, std::vector<double> (broj_kolona));
}



Matrica NajvecaPlaninaMatrice(Matrica x){
	for(int i=0; i<int(x.size()); i++){
		if(x.at(i).size()!=
		x.at(0).size()) throw std::domain_error("Matrica nije korektna");    //Provjera oblika matrice, da li je grbava ili ne.
	}
	Matrica max=KreirajMatricu(0,0);			//Kreiranje prazne matrice, ukoliko je jedna od dimenzija matrice 0.
	if(x.size()>0 && x.at(0).size()>0){
		max=KreirajMatricu(1,1);		
		max.at(0).at(0)=x.at(0).at(0);
		for(int i=0; i<int(x.size()); i++){								//Trazenje najvece planine dimenzija 1x1.
			for(int j=0; j<int(x.at(i).size()); j++){
				if(max.at(0).at(0)<x.at(i).at(j)) max.at(0).at(0)=x.at(i).at(j);
			}
		}
	}
	std::vector<Matrica> PlaninaMatrice;					//Vektor koji ce sadrzavati sve Planine matrice dimenzija 2x2 i vece.
	std::vector<std::complex<int>> koordinate;				//Vektor koji ce sadrzavati koordinate svakog vrha planine.
	if(x.size()>2 && x.at(0).size()>2){
		for(int i=1; i<int(x.size())-1; i++){
			for(int j=1; j<int(x.at(i).size())-1; j++){
				std::vector<double> sume;							//Vektor svih suma koncentricnih kvadrata jedne planine.
				int brojac=1;								//"Poluprecnik" koncentricnih kvadrata jedne planine.
					while(i-brojac>=0 && j-brojac>=0 && i+brojac<x.size() && j+brojac<x.at(i).size()){		//Provjera da li su koordinate unutar matrice.
						double suma=0;
						for(int k=i-brojac; k<=i+brojac; k++){
							for(int l=j-brojac; l<=j+brojac; l++){
								if(l==j-brojac || l==j+brojac || k==i-brojac || k==i+brojac) suma+=x.at(k).at(l);
							}
						}
						if(sume.size()==0 && suma<x.at(i).at(j)){
							sume.push_back(suma);
							brojac++;
						} 
						else if (sume.size()>0 && suma<sume.at(sume.size()-1)){
							sume.push_back(suma);	
							brojac++;
						} 
						else break;
					}
					brojac--;					
				if(sume.size()>0){
					PlaninaMatrice.push_back(KreirajMatricu(2*brojac+1, 2*brojac+1));	//Kreiranje matrice odgovarajucih dimenzija u vektoru.
					koordinate.push_back(std::complex<int>(i,j));	//Ubacivanje koordinata vrha na prvo mjesto vektora (koordinate i matrica su na istim mjestima u svojim vektorima).
					for(int k=i-brojac; k<=i+brojac; k++){
						for(int l=j-brojac; l<=j+brojac; l++){
							PlaninaMatrice.at(int(PlaninaMatrice.size())-1).at(k-(i-brojac)).at(l-(j-brojac))=x.at(k).at(l); //Ubacivanje odgovarajucih elemenata u malocas kreiranu matricu.
						}
					}
				} 
			}
		}
	}
	if(PlaninaMatrice.size()>0){
		max=PlaninaMatrice.at(0);									
		std::complex<int> max_koordinate=koordinate.at(0);
			for(int i=1; i<int(PlaninaMatrice.size()); i++){													
				if(max.size()<PlaninaMatrice.at(i).size()){
					max=PlaninaMatrice.at(i);	
					max_koordinate=koordinate.at(i);
				}  				  										//Trazenje najvece podmatrice.
				else if(max.size()==PlaninaMatrice.at(i).size()){																			
					if(max.at(max.size()/2).at(max.size()/2)<PlaninaMatrice.at(i).at(PlaninaMatrice.size()/2).at(PlaninaMatrice.size()/2)){			//Trazenje najveceg centralnog elementa. 
						max=PlaninaMatrice.at(i);
						max_koordinate=koordinate.at(i);
					}	
					else if(fabs(max.at(max.size()/2).at(max.size()/2)-PlaninaMatrice.at(i).at(PlaninaMatrice.size()/2).at(PlaninaMatrice.size()/2))<epsilon){
						if(koordinate.at(i).real()<max_koordinate.real()){
							max=PlaninaMatrice.at(i);
							max_koordinate=koordinate.at(i);							//Trazenje minimalne prve koordinate vrha.
						} 														
						else if(koordinate.at(i).real()==max_koordinate.real()){
							if(koordinate.at(i).imag()<max_koordinate.imag()){ 			//Trazenje minimalne druge koordinate vrha.
								max=PlaninaMatrice.at(i);
								max_koordinate=koordinate.at(i);
							}															
						}
					}
				}
			}			
	}
	return max;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int redovi, kolone;
	std::cin >> redovi >> kolone;
	if(redovi<0 || kolone<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!\n";
		return 0;
	} 
	Matrica m(KreirajMatricu(redovi, kolone));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<redovi; i++){
		for(int j=0; j<kolone; j++){
			std::cin >> m.at(i).at(j);
		}
	}
	Matrica planina=NajvecaPlaninaMatrice(m);
	std::cout << "\nNajveca planina unesene matrice je:\n";
	for(int i=0; i<planina.size(); i++){
		for(int j=0; j<planina.at(0).size(); j++){
			std::cout << std::setw(6) << planina.at(i).at(j);
		}
		std::cout << std::endl;
	}
	return 0;
}
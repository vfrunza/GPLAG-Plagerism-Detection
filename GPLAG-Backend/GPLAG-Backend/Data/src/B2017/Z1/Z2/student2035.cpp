#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>

bool JesuLiJednaki(double x, double y) {
	double epsilon(pow(10,-15));
	return std::fabs(x-y)<=epsilon*(std::fabs(x)+std::fabs(y));
	
}


double SumaKteOkoline(std::vector<std::vector<double>> matrica, int iti_red, int jta_kolona, int k) //ovdje primas regularnu matricu, napravi funkciju koja provjerava regularnost matrice i to u glavnom funkciji radi
{
	
	
	double suma(0); 
	
	for(int i=iti_red-k; i<=iti_red+k; i++)
	for(int j=jta_kolona-k; j<=jta_kolona+k; j++) 
	{
	if(i==iti_red-k || i==iti_red+k || j==jta_kolona-k || j==jta_kolona+k) {
		suma=suma+matrica.at(i).at(j); 

	}}
	
	return suma; 
	
}


bool RegularnaMatrica(std::vector<std::vector<double>> matrica) { //provjeri da li ok ova funkcija opet 
	if(matrica.size()==0) return true; //regularna je prazna matrica
	int kolone(matrica.at(0).size()); 
	for(int i=1; i<matrica.size(); i++) {
		if(matrica.at(i).size()!=kolone) return false; 
	}
	
	return true; 
}


std::vector<std::vector<double>> IzdvojiPodmatricu(std::vector<std::vector<double>> matrica, int centralni_element_red, int centralni_element_kolona, int dimenzija) {
	std::vector<std::vector<double>> nova(dimenzija*2+1, std::vector<double> (dimenzija*2+1));
	int a=0; 
	int b=0; 
	for(int i=centralni_element_red-dimenzija; i<=centralni_element_red+dimenzija; i++) {{
	for(int j=centralni_element_kolona-dimenzija; j<=centralni_element_kolona+dimenzija; j++) {
	nova.at(a).at(b)=matrica.at(i).at(j); 

	b++; } 
	b=0;
		a++; 
	}
	

	
	}
	return nova; 
	
}

bool FunkcijaProvjere(int br_redova_matrice, int broj_konolna_matrice, int iti_red, int jta_kolona, int k) {
	if(iti_red-k<0 || jta_kolona-k<0 || iti_red+k>=br_redova_matrice || jta_kolona+k>=broj_konolna_matrice) return false; //ili stroga nejednakost kod svih
	return true;
}

std::vector<std::vector<double>> MaxClanMatrice(std::vector<std::vector<double>> matrica) {
	std::vector<std::vector<double>> rezultat(1, std::vector<double> (1)); 
	double max_element(matrica.at(0).at(0)); 
	for(int i=0; i<matrica.size(); i++)
	for(int j=0; j<matrica.at(0).size(); j++)
	if(matrica.at(i).at(j)>max_element && !JesuLiJednaki(matrica.at(i).at(j), max_element)) max_element=matrica.at(i).at(j); //ovdje si ubacila za poredjenje jer je bilo unsaefe
	
	rezultat.at(0).at(0)=max_element; 
	return rezultat; 
	
}


std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica) {
	if(!RegularnaMatrica(matrica)) throw std::domain_error("Matrica nije korektna"); 
	std::vector<std::vector<double>> rezultat;
	if(matrica.size()==0) return rezultat; 
	if(matrica.at(0).size()==0) return rezultat; 
	if(matrica.size()<3 || matrica.at(0).size()<3) { //svodi se na trazenje max elementa
		rezultat=MaxClanMatrice(matrica); 
		return rezultat; 
	}
	bool prvi_ulaz(true); 
	bool kontrolna_za_pomocnu_funkciju(true);
	double suma(0); 
	double previous_suma(0);
	int kontrolna_dimenzija(0); //skontaaj da li da krenes od 1 ili 0 
	int dimenzija(0);
	int koordinata_i(0);
	int koordinata_j(0); 
	int maxdimenzija(0); 
	int finalna_koordinata_i(0); 
	int finalna_koordinata_j(0); 
	for(int i=1; i<matrica.size()-1; i++) {
		for(int j=1; j<matrica.at(0).size()-1; j++) {
			prvi_ulaz=true; 
			kontrolna_za_pomocnu_funkciju=true;
			kontrolna_dimenzija=0;
			previous_suma=0;
			dimenzija=0;
			while(kontrolna_za_pomocnu_funkciju) {
				//napraviti funkciju ovu provjere umjesto slanja po referenci; 
				if(!FunkcijaProvjere(matrica.size(), matrica.at(0).size(), i, j, kontrolna_dimenzija)) break;
				
				suma=SumaKteOkoline(matrica, i, j, kontrolna_dimenzija); 
			//	std::cout << "Izasao sam iz funkcije. Ja sam element " << matrica.at(i).at(j) << "Mogu ici do dimenzije " << kontrolna_dimenzija <<" i tu mi je suma " << suma <<" a prosla suma mi je bila " << previous_suma <<std::endl;
				if(prvi_ulaz) {
					previous_suma=suma;
					prvi_ulaz=false;
					kontrolna_dimenzija++;
					continue;
				}
				
				else {
					if(previous_suma>suma)
					{
						dimenzija=kontrolna_dimenzija; 
						kontrolna_dimenzija++; 
						previous_suma=suma;
						koordinata_i=i; 
						koordinata_j=j; 
						continue;
					}
					
					else {
					//	std::cout << "SORRY IPAK MOGU SAMO DO DIMENZIJE " << dimenzija; 
						break;
					}
				}
				previous_suma=suma;
				
						}
						
				if(dimenzija>maxdimenzija) {maxdimenzija=dimenzija; 
					finalna_koordinata_i=koordinata_i; 
					finalna_koordinata_j=koordinata_j;
					//ovdje dodaj jos onih more uslova kada su iste bla bla
				}
				
				//ovdje si pocela dodavati da znas kad se sve raspadne i testiraj ovo btw
				//OVDJE SI DODAVALA ONO POREDJENJE
				else if(dimenzija==maxdimenzija) {
					if(matrica.at(koordinata_i).at(koordinata_j)>matrica.at(finalna_koordinata_i).at(finalna_koordinata_j) && !JesuLiJednaki(matrica.at(koordinata_i).at(koordinata_j), matrica.at(finalna_koordinata_i).at(finalna_koordinata_j))) {
						finalna_koordinata_i=koordinata_i; 
						finalna_koordinata_j=koordinata_j; 
					}
					else if(JesuLiJednaki(matrica.at(koordinata_i).at(koordinata_j),matrica.at(finalna_koordinata_i).at(finalna_koordinata_j)) && koordinata_i<finalna_koordinata_i) {
						finalna_koordinata_i=koordinata_i; 
						finalna_koordinata_j=koordinata_j; 
					}
					else if(JesuLiJednaki(matrica.at(koordinata_i).at(koordinata_j),matrica.at(finalna_koordinata_i).at(finalna_koordinata_j)) && koordinata_i==finalna_koordinata_i && koordinata_j<finalna_koordinata_j) {
						finalna_koordinata_i=koordinata_i;
						finalna_koordinata_j=koordinata_j; 
					}
				}
		}
	}

		if(maxdimenzija) {
		try {
		std::vector<std::vector<double>> rez(IzdvojiPodmatricu(matrica, finalna_koordinata_i, finalna_koordinata_j, maxdimenzija )); 
			return rez;
		}
		catch(std::out_of_range) {std::cout << "bio je problem izdvojiti podmatricu"; } }
		
		rezultat=MaxClanMatrice(matrica); 
	
	return rezultat; 
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m, n; 
	std::cin >> m >> n; //ovdje ona provjera i zajebancije
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0; 
	}
	std::cout << "Unesite elemente matrice: "; 
	std::vector<std::vector<double>> matrica(m, std::vector<double> (n)); 
	for(int i=0; i<m; i++) 
	for(int j=0; j<n; j++)
	std::cin >> matrica.at(i).at(j); 

	std::vector<std::vector<double>> planina(NajvecaPlaninaMatrice(matrica));
	std::cout << std::endl << "Najveca planina unesene matrice je: " <<std::endl;
	if(planina.size()!=0) {
	for(int i=0; i<planina.size(); i++) {
	for(int j=0; j<planina.at(0).size(); j++) {
	std::cout << std::setw(6) << planina.at(i).at(j); }
	std::cout << std::endl; } }
	
	
	
	
	return 0;
}
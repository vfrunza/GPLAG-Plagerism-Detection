#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iomanip>

//POPRAVI 0x0
//POGRESAN FORMAT MATRICE 3x0

//Skraćenica
typedef std::vector<std::vector<double>>  Matrica;

Matrica KreirajMatricu(int a, int b, double pocetni = 0.){
	//Funkcija za kreiranje matrice
	return Matrica(a, std::vector<double>(b,pocetni));
}

int BrojRedova(const Matrica m){
	//Vraća broj redova matrice
	return m.size();
}

int BrojKolona(const Matrica m){
	//Vraća broj kolona matrice
	if(m.size() == 0) return 0;
	return m.at(0).size();
}

int Vrh(const Matrica m){
	/*	Funkcija Vrh prima parametre(matrica)
		-Funkcija Vrh vraća srednji član matrice ako je neprazna matrica neparnih dimenzija
	*/
	if(BrojKolona(m) == 0 || BrojRedova(m) == 0) return 0;
	
	if(BrojKolona(m) % 2 == 0 || BrojRedova(m) % 2 == 0) return 0;
	
	return m.at(floor(BrojKolona(m)/2.)).at(floor(BrojRedova(m)/2.));
}

Matrica Provjeri(const Matrica m, int a, int b, double vrh){
	/*Funkcija Proveri prima parametre(matrica, kolona u kojoj se nalazi posmatrani vrh, red u kojem se nalazi posmatrani vrh)
		-Funkcija Provjeri vraća matricu koja zadovoljava kriterije planine, ako matrica ne zadovoljava kriterije planine vraća samo posmatrani element
	*/
	// Referentni centar matrice
	double prosli(vrh);
	long long int brojac = 0;
	long int e(1);
	//std::cout <<"Centar: "<< vrh << std::endl; 
	while((a - e) >= 0 && (a + e) < m.size() && (b - e) >= 0 && (b + e) < m.at(0).size()){ // Sve dok je u definisanom dijelu matrice
		long double suma(0.);
		
		for(int i = -1*e; i <= e; i++){
			suma += m.at(-1*e + a).at(i + b) + m.at(e + a).at(i + b);
			if(i != e && i != -1*e){
				suma += m.at(i + a).at(-1*e + b) + m.at(i + a).at(e + b);
			}
		}
		
		/*for(int i = -1*e; i <= e; i++){
			for(int j = -1*e; j <= e; j++){
				suma += m.at(a + i).at(b + j);
			}
		}*/
		//std::cout << "Suma:" << suma  << " " << prosli << std::endl;
		//PROBLEM JE SA SUMOM
		if(suma - prosli >= 0) break;
		if(suma - prosli < 0){
			prosli = suma;
		}
		brojac++;
		e++;
	}
	if(brojac == 0){
		return KreirajMatricu(1,1,vrh);
	}
	//std::cout << "Brojac : " << brojac << std::endl;
	
	//Punjenje matrice;
	long long int redovi = 0;
	long long int broj_redova = 2*brojac + 1;
	Matrica vrati(KreirajMatricu(broj_redova,0));
	
	for(int i = -1*brojac; i <= brojac; i++){
		for(int j = -1*brojac; j <= brojac; j++){
			vrati.at(redovi).push_back(m.at(a + i).at(b + j));
			//std::cout << m.at(a + i).at(b + j) << " ";
		}
		//std::cout << std::endl;
		redovi++;
	}
	
	//vraćanje napunjeme matrice
	return vrati;
}

Matrica NajvecaPlaninaMatrice(const Matrica m){
	//Provjeravanje validnosti matrice(da li je matrica grbava?)
	
	if(m.size() == 0 || m.at(0).size() == 0) return KreirajMatricu(0,0);
	int broj_kolona = m.at(0).size();
	int broj_redova = m.size();
	
	for(int i = 0; i < BrojRedova(m); i++){
		if(m.at(i).size() != broj_kolona){
			throw std::domain_error("Matrica nije korektna");
		}
	}
	
	//Korisni rad...
	Matrica ispitaj(KreirajMatricu(1,1,m.at(0).at(0)));
	for(int i = 0; i < broj_redova; i++){ //Posmatra samo "unutrašnje" elemente matrice, jer je postmatranje rubova matrice u našem slučaju besmisleno
		for(int j = 0; j < broj_kolona; j++){
			Matrica ispitana(Provjeri(m, i, j, m.at(i).at(j)));
			if(( ispitaj.size() < ispitana.size() ) || ( ispitaj.size() == ispitana.size() && Vrh(ispitaj) < Vrh(ispitana))){
				ispitaj = ispitana; 
			}
		}
	}
	
	return ispitaj;
}



int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	if(m < 0 || n < 0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	
	std::cout << "Unesite elemente matrice:" << std::endl;
	
	//Kreira matricu sa m redova, kolone se puno preko fukncije push_back;
	Matrica matrica(KreirajMatricu(m, 0));
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			double unos;
			std::cin >> unos;
			matrica.at(i).push_back(unos);
			//Punjenje matrice
		}
	}
	//std::cout << "Dimenzije matrice (brojkolona) (brojredova) (centar)" << BrojKolona(matrica) << " " << BrojRedova(matrica) << " " <<Vrh(matrica);
	
	//ČAROBNA FUNKCIJA hehe
	matrica = NajvecaPlaninaMatrice(matrica);
	
	std::cout << "Najveca planina unesene matrice je:" << std::endl;
	
	
	//Ispis matrice
	for(int i = 0; i < BrojKolona(matrica); i++){
		for(int j = 0; j < BrojRedova(matrica); j++){
			std::cout << std::setw(6) << matrica.at(i).at(j);
		}
		std::cout << std::endl;
	}
	
	return 0;
}
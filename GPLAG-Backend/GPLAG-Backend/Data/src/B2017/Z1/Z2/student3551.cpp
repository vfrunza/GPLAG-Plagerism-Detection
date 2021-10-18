/*B 2017/2018, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/

/* MATRICA 1  (10x9)
	Matrica mat {{1, 1,  1,  1, 1, 1,   1,  1,-10},
				 {1, 1,  1,  1, 1, 1,   1,  1,-10},
		         {1, 1,  1,  1, 1, 37,  1,  1,-10},
			     {1, 1,  9,  9, 9, 9,   9,  1,-10},
			     {1, 1,  8.1,20,100,20,8.4, 1,-10},
				 {1, 1,  8.2,20,300,20,8.5, 1,-10},
				 {1, 1,  8.3,20,20,20, 8.6, 1,-10},
				 {1, 1,  9,  9, 9, 9,   9,  1,-10},
				 {1, 1,  1,  1, 1, 1,   1,  1,-10},
				 {1, 1,  1,  1, 1, 1,   1,  1,-10},
	};
	iZGLED 2. sloja kocke
	Matrica mat {{-1, -1, -1, -1, -1, -1, -1, -1, -1},
				 {-1,  0,  0,  0,  0,  0,  0,  1, -1},
		         {-1,  0,  0,  0,  0,  1,  0,  1, -1},
		         {-1,  0,  0,  0,  0,  0,  0,  1, -1},
		         {-1,  0,  0,  0,  0,  0,  0,  1, -1},
		         {-1,  0,  0,  0,  4,  0,  0,  1, -1},
		         {-1,  0,  0,  0,  0,  0,  0,  1, -1},
		         {-1,  0,  0,  0,  0,  0,  0,  1, -1},
		         {-1,  0,  0,  0,  0,  0,  0,  1, -1},
		         {-1, -1, -1, -1, -1, -1, -1, -1, -1},
	};
*/
/* MATICA 2   (6x6)
	Matrica mat {{ 0,  0,  0, 15, 12,  6},
				 { 1, 25,  1,  5,  2,  9},
		         { 1,  1, 20, 15, 10,  5},
			     { 3,  2, 19,130, 14,  8},
			     {90,  6, 20, 12, 17,  2},
				 {12,  3,  5,  1,  8,  4}
	};
	iZGLED 2 sloja kocke
	Matrica mat {{-1, -1, -1, -1, -1, -1},
				 {-1,  1,  0,  0,  0, -1},
		         {-1,  0,  0,  0,  0, -1},
		         {-1,  0,  0,  2,  0, -1},
		         {-1,  0,  0,  0,  0, -1},
		         {-1, -1, -1, -1, -1, -1}
	};
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

constexpr double eps(0.0001);

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

int BrojRedova(Matrica m)
{
	return m.size();
}

int BrojKolona(Matrica m)
{
	return m.at(0).size();
}

bool Grbava(Matrica m)
{
	int br_kolona(m.at(0).size());
	for(int i=1; i<m.size(); i++)
		if(m.at(i).size() != br_kolona) return true;
	return false;
}

Matrica NajvecaPlaninaMatrice(Matrica MAT)
{
	Matrica PLANINA;
	if (MAT.size()==0)
	return PLANINA;
	
	int m(BrojRedova(MAT));
	int n(BrojKolona(MAT));
	
	if (Grbava(MAT)) throw std::domain_error("Matrica nije korektna");

	std::vector<std::vector<std::vector<double>>>Kocka(m, std::vector<std::vector<double>>(n, std::vector<double>(2,0)));

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++)
			Kocka.at(i).at(j).at(0) = MAT.at(i).at(j);
	}
	
	for(int i=0; i<m; i++) 
		for(int j=0; j<n; j++)
			Kocka.at(i).at(0).at(1)=0;

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++)
			if(i==0 || j==0 || i==m-1 || j==n-1) continue;
			else {
				double sredinji(Kocka.at(i).at(j).at(0));
				double suma_osam (0);

				suma_osam += Kocka.at(i-1).at(j-1).at(0);
				suma_osam += Kocka.at(i-1).at(j).at(0);
				suma_osam += Kocka.at(i-1).at(j+1).at(0);
				suma_osam += Kocka.at(i).at(j-1).at(0);
				suma_osam += Kocka.at(i).at(j+1).at(0);
				suma_osam += Kocka.at(i+1).at(j-1).at(0);
				suma_osam += Kocka.at(i+1).at(j).at(0);
				suma_osam += Kocka.at(i+1).at(j+1).at(0);
				if(sredinji>suma_osam) {
					Kocka.at(i).at(j).at(1) = 1;
				}
			}
	}

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++)
			if(std::fabs(Kocka.at(i).at(j).at(1))<eps)
				continue;
			else {
				int visina(1),suma_osam;
				int v(visina), prethodna_suma;
				prethodna_suma = Kocka.at(i).at(j).at(0);
				v=2;  //v predstavlja visinu vrha 'planine' koju ispitujemo
				while(!(i-v<0 || j-v<0 || i+v>m-1 || j+v>n-1 || (2*v+1==n && n==m))) {
					suma_osam =0;
					for(int k=i-v; k<i+v; k++) {
						suma_osam += Kocka.at(i-v).at(k).at(0);
						suma_osam += Kocka.at(i+v).at(k).at(0);
					}
					for(int k=i-v+1; k<=i+v-1; k++) {
						suma_osam += Kocka.at(k).at(j-v).at(0);
						suma_osam += Kocka.at(k).at(j+v).at(0);
					}
					if(suma_osam < prethodna_suma) {
						v++;
						Kocka.at(i).at(j).at(1)=v-1;
						prethodna_suma =  suma_osam;
					} else break;
				}

			}
	}

	int max_visina(-2);
	std::vector<int> VRH (3); // sadrzi: {visinu vrha, x-koordinatu vrha, y-koordinatu vrha}
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++)
			if (Kocka.at(i).at(j).at(1) > max_visina) {
				max_visina = Kocka.at(i).at(j).at(1);
				VRH.at(0)  = max_visina;
				VRH.at(1)  = i;
				VRH.at(2)  = j;
			}

		//sta radimo kada planine imaju istu visinu
			else if(std::fabs(Kocka.at(i).at(j).at(1) - max_visina)<eps) {
				//uzimamo veci vrh jednako visokih planina
				if(Kocka.at(i).at(j).at(0) > Kocka.at(VRH.at(1)).at(VRH.at(2)).at(0)) {
					VRH.at(1)  = i;
					VRH.at(2)  = j;
				}
				//sta radimo kada vrhovi jednako visokih planina imaju iste vrijednosti
				else if(std::fabs(Kocka.at(i).at(j).at(0) - Kocka.at(VRH.at(1)).at(VRH.at(2)).at(0)) < eps) {
					//uzimamo vrh sa manjom 1. koordinatom
					//ili onaj sa manjom 2. koord ako su im prve koordiante jednake
					if (i < VRH.at(1) || (i==VRH.at(1) && j<VRH.at(2))) {
						VRH.at(1)  = i;
						VRH.at(2)  = j;
					}
				}
			}
	}

	//ako je max_visina = -1 onda element sacuvan u VRH sam cini vrh
	//bez ikakvih dodavanja redova ili kolona



	//pravimo matricu Planina
	int visina(VRH.at(0));
	int x(VRH.at(1));
	int y(VRH.at(2));

	int red(0), kolona(0);
	int dimenzije(2*visina +1);
	PLANINA.resize(dimenzije);
	for(int i=0; i<PLANINA.size(); i++)
		PLANINA.at(i).resize(dimenzije);

	for(int i=x-visina; i<=x+visina; i++) {
		kolona=0;
		for(int j=y-visina; j<=y+visina; j++) {
			PLANINA.at(red).at(kolona) = Kocka.at(i).at(j).at(0);
			kolona++;
		}
		red++;
	}



	return PLANINA;

}


int main ()
{
	int n,m;
	std::cout <<"Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;

	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	if(m==0 || n==0) {m=0;n=0;}
	Matrica MAT(KreirajMatricu(m,n));
	std::cout << "Unesite elemente matrice:";

	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++)
			std::cin >> MAT.at(i).at(j);
	}
	try {
		Matrica Planina = NajvecaPlaninaMatrice(MAT);

		std::cout<<std::endl;
		std::cout << "Najveca planina unesene matrice je:";
		int red(Planina.size()),kolona;
		if(red==0) kolona=0;
		else kolona = Planina.at(0).size();

		std::cout << std::endl;
		for(int i=0; i<red; i++) {
			for(int j=0; j<kolona; j++)  
				std::cout << std::setw(6) <<Planina.at(i).at(j);
			std::cout << std::endl;
		} 

	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
		return 0;
	} catch(...) {
		std::cout << "Pogresan izuzetak!";
		return 0;
	}
	return 0;
}

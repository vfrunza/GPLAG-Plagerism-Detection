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

typedef std::vector<std::vector<double>> Matrica;

bool DaLiJeGrbava(Matrica Mat)
{

	int Provjera(Mat.at(0).size());

	for(int i=0; i<Mat.size(); i++) {

		if(Mat.at(i).size()>Provjera || Mat.at(i).size()<Provjera) return true;

	}

	return false;
}

Matrica NajvecaPlaninaMatrice(Matrica Mat) //Uradjeni specificni slucajevi
{

	Matrica PovratnaMatrica(Mat);
	if(DaLiJeGrbava(Mat)) throw std::domain_error("Matrica nije korektna");

	if(Mat.size()==0) return PovratnaMatrica; //Kada je 0 vraca praznu matricu
	
	if(Mat.size()==2 && Mat.at(0).size()==2){ //Kada je 2x2 vraca najveci element
		double max=0;
		
		for(int i=0;i<Mat.size();i++){
			for(int j=0;j<Mat.at(i).size();j++)
				if(Mat.at(i).at(j)>max) max=Mat.at(i).at(j);
		}
		
		std::vector<double> test;
		test.push_back(max);
		PovratnaMatrica.clear();
		PovratnaMatrica.push_back(test);
		return PovratnaMatrica;
	}
	
	double Planina(0.);
	double suma(0.);
	
	for(int i=0;i<Mat.size();i++){
		
		for(int j=0;j<Mat.at(i).size();j++){
			
		
				
		//		std::cout << Mat.at(i).at(j) <<"     ";
			
			
		}
		
	//	std::cout  << std::endl;
		
	}
	
//	std::cout << Planina << std::endl;
	return PovratnaMatrica;

}

int main ()
{
	try {

		std::cout << "Unesite dimenzije matrice (m i n): " ;
		int m,n;
		std::cin >> m >> n;

		if(m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!" ;
			return 0;
		}

		std::cout << "Unesite elemente matrice: " ;

		std::vector<double> PomocniVektor;
		Matrica UnesenaMatrica;
		int brojac(0),brojac2(0),brojac3(0);
		double broj;

		while(1) {
			std::cin >> broj;
			PomocniVektor.push_back(broj);
			brojac++;
			brojac3++;
			if(brojac==n || std::cin.peek()=='\n' || brojac3==m*n) {
				UnesenaMatrica.push_back(PomocniVektor);
				PomocniVektor.clear();
				brojac=0;
				brojac2++;
				if(brojac2==m) break;
			}
		}

		auto MatricaIzMaina(NajvecaPlaninaMatrice(UnesenaMatrica));
		std::cout << std::endl;
		std::cout <<"Najveca planina unesene matrice je:" << std::endl;
		for(int i=0; i<MatricaIzMaina.size(); i++) {

			for(int j=0; j<MatricaIzMaina.at(i).size(); j++) std::cout << std::setw(6) << MatricaIzMaina.at(i).at(j) ;

			std::cout << std::endl;
		}

	} catch (std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}

	return 0;
}
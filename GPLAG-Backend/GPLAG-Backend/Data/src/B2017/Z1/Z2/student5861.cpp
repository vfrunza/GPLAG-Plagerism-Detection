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
#include <cmath>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

double SumaClanovaKvadrata(Matrica matrica, int i, int j, int a)
{
	double suma1 = 0;
	double suma2 = 0;
	double suma3 = 0;
	double suma4 = 0;
	for(int k=0; k<2*a+1; k++) {
		suma1 = suma1 + matrica.at(i-a).at(j-a+k);
		suma2 = suma2 + matrica.at(i+a).at(j-a+k);
		suma3 = suma3 + matrica.at(i-a+k).at(j-a);
		suma4 = suma4 + matrica.at(i-a+k).at(j+a);
	}
	double suma = suma1 + suma2 + suma3 + suma4 - (matrica.at(i-a).at(j-a) + matrica.at(i-a).at(j+a) + matrica.at(i+a).at(j-a) + matrica.at(i+a).at(j+a));
	return suma;
}

/*bool ProvjeraDaLiJeOpadajuciNiz(std::vector<double> niz)
{
	for(int i=0; i<niz.size()-1; i++) {
		if(niz.at(i)<niz.at(i+1)) {
			return false;
		}
	}
	return true;
}*/

Matrica PiramidalnaMatrica(Matrica matrica, int i, int j, int n)
{
	Matrica piramidalnaMatrica(2*n+1, std::vector<double>(2*n+1));
	for(int k=0; k<2*n+1; k++) {
		for(int m=0; m<2*n+1; m++) {
			piramidalnaMatrica.at(k).at(m)=matrica.at(i-n+k).at(j-n+m);
		}
	}
	return piramidalnaMatrica;
}

void printajMatricu(Matrica matrica)
{
	for(auto red : matrica) {
		for(auto clan : red)
			std::cout<<std::setw(6)<<clan;
		std::cout<<std::endl;
	}
}
/*void dodajOsobine(std::vector<double> osobineNM, std::vector<double> osobinePM)
{
	osobinePM.clear();
	osobinePM.push_back(osobineNM.at(0));
	osobinePM.push_back(osobineNM.at(1));
	osobinePM.push_back(osobineNM.at(2));
	osobinePM.push_back(osobineNM.at(3));
}*/

bool DaLiJeNadjenaNovaMatrica(std::vector<double> osobineNM, std::vector<double> osobinePM)
{
	if(osobineNM.at(0) > osobinePM.at(0)) {
		return true;
	} else if((osobineNM.at(0)==osobinePM.at(0)) && (osobineNM.at(1))>osobinePM.at(1)) {
		return true;
	} else if((osobineNM.at(0)==osobinePM.at(0))&&(osobineNM.at(1)==osobinePM.at(1)) && osobineNM.at(2)<osobinePM.at(2)) {
		return true;
	} else if((osobineNM.at(0)==osobinePM.at(0))&&(osobineNM.at(1)==osobinePM.at(1)) && (osobineNM.at(2)==osobinePM.at(2)) && osobineNM.at(3)<osobinePM.at(3)) {
		return true;
	} else {
		return false;
	}
}
int UdaljenostPozicijeOdRubaMatrice(Matrica matrica, int i, int j)
{
	int r = matrica.size();
	int c = matrica.at(0).size();
	int n = std::min(i,j);
	n = std::min(n, r-i-1);
	n = std::min(n, c-j-1);
	return n;
}

bool DaliSeNaDatojPozicijiNalaziPiramidalnaMatrica(Matrica matrica, int i, int j)
{
	int n = UdaljenostPozicijeOdRubaMatrice(matrica, i, j);
	if(n==0) return true;
	double prethodniKvadrat = matrica.at(i).at(j);

	for(int k=n; k>0; k--) {
		double trenutniKvadrat = SumaClanovaKvadrata(matrica, i, j, n-k+1);
		if(prethodniKvadrat>trenutniKvadrat) {
			prethodniKvadrat = trenutniKvadrat;
		} else
			return false;
		if(k==1) {
			return true;
		}
	}
}

Matrica NajvecaPlaninaMatrice(Matrica matrica)
{
	Matrica piramidalnaMatrica;
	bool novaMatricaPronadjena = false;
	bool matricaPronadjena = false;
	std::vector<double> osobinePrethodneMatrice = {0, 0, 0, 0};
	std::vector<double> osobineNoveMatrice;


	int r = matrica.size();
	int c = matrica.at(0).size();
	//int prethodniKvadrat;
	//int trenutniKvadrat;

	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(matrica.at(i).size()!=c)
				throw std::domain_error("Matrica nije korektna");
		}
	}
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			novaMatricaPronadjena = false;

			int n = UdaljenostPozicijeOdRubaMatrice(matrica, i, j);


			int prethodniKvadrat = matrica.at(i).at(j);

			novaMatricaPronadjena = DaliSeNaDatojPozicijiNalaziPiramidalnaMatrica(matrica, i, j);

			if(novaMatricaPronadjena) {
				osobineNoveMatrice = {double(n), matrica.at(i).at(j), double(i), double(j)};
				matricaPronadjena = true;
			}

			if(novaMatricaPronadjena && DaLiJeNadjenaNovaMatrica(osobineNoveMatrice, osobinePrethodneMatrice)) {
				piramidalnaMatrica = PiramidalnaMatrica(matrica, i, j, n);
				//dodajOsobine(osobineNoveMatrice, osobinePrethodneMatrice);
				osobinePrethodneMatrice.clear();
				osobinePrethodneMatrice.push_back(osobineNoveMatrice.at(0));
				osobinePrethodneMatrice.push_back(osobineNoveMatrice.at(1));
				osobinePrethodneMatrice.push_back(osobineNoveMatrice.at(2));
				osobinePrethodneMatrice.push_back(osobineNoveMatrice.at(3));
			}
		}
	}
	if(matricaPronadjena == false) {
		Matrica praznaMatrica(0, std::vector<double>(0));
		return praznaMatrica;
	}
	return piramidalnaMatrica;
}

Matrica NapraviMatricu()
{
	int m;
	int n;
	double clan;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		Matrica matrica;
		return matrica;
	} else {
		Matrica matrica(m, std::vector<double>(n));
		std::cout<<"Unesite elemente matrice: ";
		for(int i = 0; i < m; i++) {
			for(int j=0; j<n; j++) {
				std::cin>>clan;
				matrica.at(i).at(j)=clan;
			}
		}
		return matrica;
	}

}
int main()
{
	Matrica matrica = NapraviMatricu();
	if(matrica.empty()) return 0;

	Matrica a;
	try {
		std::cout<<"\nNajveca planina unesene matrice je: \n";
		a = NajvecaPlaninaMatrice(matrica);
	} catch (std::domain_error e) {
		std::cout << e.what();
	}

	printajMatricu(a);

	return 0;
}
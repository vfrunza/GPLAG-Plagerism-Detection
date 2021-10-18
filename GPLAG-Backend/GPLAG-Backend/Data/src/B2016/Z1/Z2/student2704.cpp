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

typedef std::vector<std::vector<double>> Matrica;

Matrica Horizontalna(Matrica h)   //obrnut redoslijed kolona
{

	Matrica mat(h);
	int i=0;
	while(i<mat.size()) {
		int j=0;
		while(j<(mat.at(i).size())/2) {
			double temp=mat.at(i).at(j);
			mat.at(i).at(j)=mat.at(i).at(mat.at(i).size()-1-j);
			mat.at(i).at(mat.at(i).size()-1-j++)=temp;
		}
		i++;
	}
	return mat;

}

Matrica Vertikalna(Matrica v)  //obrnut redoslijed redova
{

	Matrica mat(v);
	int i=0;
	while(i<(mat.size())/2) {

		int j=0;
		while(j<mat.at(i).size()) {
			double temp=mat.at(i).at(j);
			mat.at(i).at(j)=mat.at(mat.size()-1-i).at(j);
			mat.at(mat.size()-1-i).at(j++)=temp;
		}
		i++;
	}
	return mat;
}

Matrica OgledaloMatrica(Matrica mat)
{
	{int i=0;
	while(i<mat.size()){
		if(mat.at(i).size()!=mat.at(0).size()){
			throw std::domain_error ("Matrica nije korektna!");
		}
		i++;
	}}

	Matrica S_matrica;
	Matrica L_matrica;

	L_matrica.resize(3*mat.size());

	S_matrica=(Vertikalna(Horizontalna(mat)));	//1. red, 1. kolona(lijevo)-hv mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(i).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	S_matrica=mat;
	S_matrica=Vertikalna(mat);	//1.red, 2.kolona(sredina)-v mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(i).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	S_matrica=mat;
	S_matrica=Vertikalna(Horizontalna(mat));	//1.red, 3.kolona(desno)-hv mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(i).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	S_matrica=mat;
	S_matrica=Horizontalna(mat);	//2.red, 1.kolona(lijevo)-h mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(i+S_matrica.size()).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	S_matrica=mat;	//2.red, 2.kolona(sredina)-obicna mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(i+S_matrica.size()).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	S_matrica=mat;
	S_matrica=Horizontalna((mat));	//2.red, 3.kolona(desno)-h mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(i+S_matrica.size()).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	S_matrica=mat;
	S_matrica=Vertikalna(Horizontalna(mat));	//3.red, 1.kolona(lijevo)-hv mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(2*S_matrica.size()+i).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	S_matrica=mat;
	S_matrica=Vertikalna((mat));		//3.red, 2.kolona(sredina)-v mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(2*S_matrica.size()+i).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	S_matrica=mat;
	S_matrica=Vertikalna(Horizontalna(mat));	//3.red, 3.kolona(desno)-hv mat
	{
		int i=0;
		while(i<S_matrica.size()) {
			int j=0;
			while(j<S_matrica.at(0).size()) {
				L_matrica.at(2*S_matrica.size()+i).push_back(S_matrica.at(i).at(j++));
			}
			i++;
		}
	}

	return L_matrica;

}

int main ()
{

	try {
		int m,n;
		std::cout << "Unesite dimenzije matrice (m n): ";
		std::cin >> m;
		std::cin >> n;

		if(n<0 || m<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
			return 0;
		}

		Matrica mat(m,std::vector<double> (n));


		std::cout << "Unesite elemente matrice: " << std::endl;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				std::cin >> mat[i][j];
			}
		}

		Matrica final;
		final=(OgledaloMatrica(mat));

		std::cout << "Rezultantna matrica: ";

		for(int i=0; i<final.size(); i++) {
			std::cout << std::endl;
			for(int j=0; j<final.at(0).size(); j++) {
				std::cout << std::setw(4) << std::right << final.at(i).at(j);
			}
		}
	} catch (std::domain_error matricaizuzetak) {
		std::cout << matricaizuzetak.what();
	}

	return 0;
}
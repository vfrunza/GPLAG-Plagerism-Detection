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

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona)
{
	Matrica m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++)
		for(int j=0; j<br_kolona; j++) {
			std::cin>>m.at(i).at(j);
		}
	return m;
}

void IspisiMatricu(Matrica m)
{
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.at(i).size(); j++)
			std::cout<<std::setw(6)<<m.at(i).at(j);
		std::cout<<std::endl;
	}
}

bool ispravanIndeks(Matrica mat, int i, int j)
{
	if(i>=0 && j>=0 && i<mat.size() && mat.size()!=0 && j<mat.at(0).size())
		return true;
	return false;
}

Matrica NajvecaPlaninaMatrice(Matrica mat)
{
	if(mat.size()==0 || mat.at(0).size()==0)
		return mat;

	int a(1); //redni broj koncentricnog kruga

	int vel(mat.at(0).size());
	for(int i=0; i<mat.size(); i++) {
		if(mat.at(i).size()!=vel)
			throw std::domain_error("Matrica nije korektna");
	}

	int maxVel(0); // dimenzija najvece piramide
	int x(-1), y(-1); //postavljeno na -1 da znamo da nema piramide

	for(int i=0; i<mat.size(); i++) { //uzimamo jedan po jedan element matrice, posmatramo ga
		for(int j=0; j<mat.at(0).size(); j++) { //kao vrh
			a=1;
			double sumaPrethod(mat.at(i).at(j)), suma(0);
			int br(0);//broj koncentricnog kvadrata za svaku piramidu

			while(1) {
				for(int k=j-a; k<=j+a; k++) { //dodaje u sumu prvi red i zadnji red
					if(ispravanIndeks(mat,i-a,k))
						suma+=mat.at(i-a).at(k);
					if(ispravanIndeks(mat,i+a,k))
						suma+=mat.at(i+a).at(k);
				}

				for(int k=i-a+1; k<=i+a-1; k++) { //dodaje u sumu kolone bez elemeata na coskovima(-1,+1)
					if(ispravanIndeks(mat,k,j-a))
						suma+=mat.at(k).at(j-a);
					if(ispravanIndeks(mat,k,j+a))
						suma+=mat.at(k).at(j+a);
				}

				if(suma<sumaPrethod) { //poredi sume koncentricnih kvadrata
					sumaPrethod=suma;
					a++;
					suma=0;
					br++;
				} else break; //prekida petlju ukoliko nije ispunjen uslov piramide
			}

			if(br>maxVel) { //pamtimo velicinu najvece piramide
				maxVel=br;
				x=i;
				y=j;
			} else if(br==maxVel) { //ukoliko imaju dvije piramide iste velicine, uzima se sa vecim vrhom
				if(x!=-1 && y!=-1 && mat.at(i).at(j)>mat.at(x).at(y))
					x=i;
				y=j;
			}
		}
	}

	Matrica rez;

	if(x==-1 && y==-1)//provjerava se je li pronadjena piramida
		return rez;

	for(int i=x-maxVel; i<=x+maxVel; i++) { //dodaju se elementi u novu matricu
		std::vector<double> tmp;
		rez.push_back(tmp);

		for(int j=y-maxVel; j<=y+maxVel; j++) {
			if(ispravanIndeks(mat,i,j)) {
				rez.at(rez.size()-1).push_back(mat.at(i).at(j));
			}
		}
	}

	return rez;
}

int main ()
{
	int visina, sirina;

	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>visina>>sirina;

	if(sirina<0 || visina<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}

	std::cout<<"Unesite elemente matrice: ";
	Matrica matrica(UnesiMatricu(visina,sirina));

	if(matrica.size()==2 && matrica.at(0).size()==2) {
		double max;
		for(int i(0); i<matrica.size(); i++) {
			max=matrica.at(i).at(0);
			for(int j(0); j<matrica.at(i).size(); j++) {
				if(matrica.at(i).at(j)>max) {
					max=matrica.at(i).at(j);
				}
			}
		}

		std::cout<<std::endl<<"Najveca planina unesene matrice je: "<<std::endl;
		std::cout<<std::setw(6)<<max;
		return 0;

	}

	try {
		std::cout<<std::endl<<"Najveca planina unesene matrice je: "<<std::endl;
		IspisiMatricu(NajvecaPlaninaMatrice(matrica));
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}

	return 0;
}
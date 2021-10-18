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
typedef std::vector<std::vector <double>> Matrica;





Matrica NajvecaPlaninaMatrice(Matrica UnesenaMatrica)
{

	//Provjera da li je matrica grbava.
	if(UnesenaMatrica.size()<1 || UnesenaMatrica.at(0).size()<1) throw std::domain_error("Matrica nije korektna");
	for(int i=1; i<UnesenaMatrica.size(); i++) if(UnesenaMatrica.at(0).size()!=UnesenaMatrica.at(i).size()) throw std::domain_error("Matrica nije korektna");

	Matrica Rezultat;
	int brojac=0;
	int MaxVelicina=0;
	double suma=0;
	double MaksimalniVrh(UnesenaMatrica.at(0).at(0));
	double VrhPlaninaMatrice(UnesenaMatrica.at(0).at(0));
	std::vector <double> VektorSuma;
	int KoordinataPoI=0,KoordinataPoJ=0;
	int MaxKoordinataI=0,MaxKoordinataJ=0;

	for (int i = 1; i < UnesenaMatrica.size()-1; i++) {
		for (int j = 1; j < UnesenaMatrica.at(i).size()-1; j++) {

			VrhPlaninaMatrice=UnesenaMatrica.at(i).at(j);
			brojac=0;
			VektorSuma.resize(1);
			VektorSuma.at(0)=VrhPlaninaMatrice;
			KoordinataPoI=i;
			KoordinataPoJ=j;

//5 5 0 0 0 0 0 0 1 1 1 0 0 1 500 1 0 0 1 1 1 0 0 0 0 0 0


			while(i-brojac>0 && j-brojac>0 && i+brojac<UnesenaMatrica.size() && j+brojac<UnesenaMatrica.at(0).size()) {
				suma=0;
				for (int k = i-brojac-1; k <= i+brojac+1; k++) {
					for (int l = j-brojac-1; l <= j+brojac+1; l++) {
						if(k==i-brojac-1 || k==i+brojac+1) suma+=UnesenaMatrica.at(k).at(l);
						if((k!=i-brojac-1 && k!=i+brojac+1) && (l==j-brojac-1 || l==j+brojac+1)) suma+=UnesenaMatrica.at(k).at(l);

					}
				}

				VektorSuma.push_back(suma);


				if(VektorSuma.at(brojac)<=VektorSuma.at(brojac+1))	break;

				
				if(i-brojac-1<0 || j-brojac-1<0 || i+brojac+1>=UnesenaMatrica.size() || j+brojac+1>=UnesenaMatrica.at(0).size()) break;
				brojac++;
			}

			if(brojac!=0) {
				if(brojac>MaxVelicina) {
					MaxVelicina=brojac;
					MaksimalniVrh=VrhPlaninaMatrice;
					MaxKoordinataI=KoordinataPoI;
					MaxKoordinataJ=KoordinataPoJ;
				}
			}
		}
	}
	if(MaxVelicina==0) {
		double MaxElement(UnesenaMatrica.at(0).at(0));
		for (int i = 0; i < UnesenaMatrica.size(); i++) {
			for (int j = 0; j < UnesenaMatrica.at(i).size(); j++) {
				if(UnesenaMatrica.at(i).at(j)>MaxElement) MaxElement=UnesenaMatrica.at(i).at(j);
			}
		}
		Rezultat.resize(1);
		Rezultat.at(0).push_back(MaxElement);
		return Rezultat;

	}

	//std::cout<<std::endl<<MaxVelicina<<std::endl<<MaxKoordinataI<<std::endl<<MaxKoordinataJ<<std::endl;

	Rezultat.resize(MaxVelicina*2+1);
	int Brojac=-1;

	for(int i=MaxKoordinataI-MaxVelicina; i<=MaxVelicina+MaxKoordinataI; i++) {
		Brojac++;
		for(int j=MaxKoordinataJ-MaxVelicina; j<=MaxVelicina+MaxKoordinataJ; j++) Rezultat.at(Brojac).push_back(UnesenaMatrica.at(i).at(j));
	}
	return Rezultat;
}


int main ()
{


	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica MojaMatrica(m,std::vector <double> (n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) std::cin>>MojaMatrica.at(i).at(j);
	std::cout<<std::endl;

	Matrica JBS(NajvecaPlaninaMatrice(MojaMatrica));
	std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
	for(int i=0; i<JBS.size(); i++) {
		for(int j=0; j<JBS.at(i).size(); j++) std::cout<<std::setw(6)<<std::right<<JBS.at(i).at(j);
		std::cout<<std::endl;
	}


	return 0;
}
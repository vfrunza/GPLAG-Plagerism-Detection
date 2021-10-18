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
typedef std::vector<std::vector<double>> Dblmatrica;
int manjiod(int x,int y)
{
	if(x<y) return x;
	return y;
}
Dblmatrica KreirajMatricu(int broj_redova,int broj_kolona)
{
	return Dblmatrica(broj_redova,std::vector<double>(broj_kolona));
}
Dblmatrica NajvecaPlaninaMatrice(Dblmatrica matrica)
{
	int m(matrica.size());//broj redova

	Dblmatrica najvplanina(0);
	if(m==0) return najvplanina;//matrica prazna
	//matrica ima jedan element tj formata 1x1
	int n(matrica.at(0).size());//broj kolona
	if(n==0) return najvplanina;
	if(m==1 && n==1) {
		najvplanina=KreirajMatricu(n,n);
		najvplanina.at(0).at(0)=matrica.at(0).at(0);
		return najvplanina;
	}
	//matrica formata 2x2
	if(m==2 && n==2) {
		int max(matrica.at(0).at(0));
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(matrica.at(i).at(j)>max) max=matrica.at(i).at(j);
			}
		}
		najvplanina=KreirajMatricu(1,1);//tada najveca planina ima jedan element i to je najveci element matrice
		najvplanina.at(0).at(0)=max;
		return najvplanina;
	}
	//grbava matrica
	for(int i=1; i<m; i++) {
		if(matrica.at(i).size()!=matrica.at(i-1).size())
			throw std::domain_error("Matrica nije korektna");
	}
	//u ovom dijelu najvplanina ima velicinu 0

	const double epsilon(0.0000000001);//dva realna broja jednaka ako je std::fabs(x-y)<epsilon
	int sirina(0),ivrha,jvrha,vrh;//vrh,sirina planine i koordinate vrha
	int ipom,jpom,pomvrh,pomsirina(1),pomdim,pompomsirina;//dimenzije neke pomocne planine koje cemo porediti sa najvecom planinom
	//rubne slucajeve u ovom dijelu ne posmatramo kao moguce vrhove nego se baziramo na trazenje planine formata veceg od 1x1
	//uzimamo slucaj kada su dimenzije matrice matrice vece ili jednake 3x3
	if(m>2 && n>2) {
		for(int i=1; i<m-1; i++) {
			for(int j=1; j<n-1; j++) {
				auto a(matrica.at(i).at(j));
				double suma(0),sumaprije(0),prvasuma(0);
				pompomsirina=1;
				while(i-pompomsirina>=0 && i+pompomsirina<=m-1 && j-pompomsirina>=0 && j+pompomsirina<=n-1) {
					//prvo racunamo sumu prvog kvadrata oko centralnog elementa pa ako mozemo prosirimo se
			//	if(i-pomsirina)
					for(int k=i-pompomsirina; k<=i+pompomsirina; k++) {
						for(int t=j-pompomsirina; t<=j+pompomsirina; t++)
							if(k==i-pompomsirina || k==i+pompomsirina || t==j-pompomsirina || t==j+pompomsirina)
								suma+=matrica.at(k).at(t);
					}


					if(pompomsirina==1) {
						prvasuma=suma;
						sumaprije=suma;
					//	suma=0;

					}
					//treba nam prva suma oko ovog centralnog
					if(a<prvasuma) break;
					if(suma>sumaprije) break;


					if(pomsirina!=1)
						sumaprije=suma;
					suma=0;
					pomsirina=pompomsirina;
					pompomsirina++;
				}
				//kad se izvrti while petlja nasli smo najvecu mogucu sirinu za taj element a,imamo njegove koordirante i sirinu te planine
				if((prvasuma-0)>epsilon) {
					if(a>prvasuma) {
						ipom=i;
						jpom=j;
						pomvrh=a;
						pomdim=pomsirina;
					}
					if(pomdim>sirina) {
						sirina=pomdim;
						vrh=pomvrh;
						ivrha=ipom;
						jvrha=jpom;

					} else if (pomdim==sirina) {
						//ako prva pomocna planina ima veci vrh a iste su im dimenzije
						if(std::fabs(pomvrh-vrh)>epsilon) {
							vrh=pomvrh;
							ivrha=ipom;
							jvrha=jpom;


						} else if(ivrha>ipom) {

							ivrha=ipom;
							jvrha=jpom;
							sirina=pomdim;
							vrh=pomvrh;
						} else if (jpom<jvrha)
							jvrha=jpom;

					}
				}



			}
		}

	}
	if(sirina>0) { //znaci da smo pronasli planinu
		najvplanina=KreirajMatricu(2*sirina+1,2*sirina+1);
		int br=0;
		int brk=0;
		for(int i=ivrha-sirina; i<=ivrha+sirina; i++) {
			for(int j=jvrha-sirina; j<=jvrha+sirina; j++){
				najvplanina.at(br).at(brk)=matrica.at(i).at(j);
			
			//najvplanina.at(std::abs(sirina-i).push_back(matrica.at(i).at(j));
			//najvplanina.at(br).push_back(matrica.at(i).at(j));
		
				brk++;
			}
		br++;
		brk=0;
	}
	}

//ako je dimenzija matrice ostala nula,znaci da nismo pronasli nijednu matricu formata veceg od 1x1 i sve se svede na trazenje
//najveceg elementa matrice koji ce biti ta planina
	double max(matrica.at(0).at(0));
	if(sirina==0) {
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				auto a(matrica.at(i).at(j));
				if(a>max) max=a;
			}
		}
		najvplanina.resize(1);
		najvplanina.at(0).resize(1);
		najvplanina.at(0).at(0)=max;
	}

	return najvplanina;

}

int main ()
{
	try {
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>>m>>n;
		if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne! ";
		else {
			Dblmatrica matrica(m);
			for(int i=0; i<m; i++) matrica.at(i).resize(n);
			std::cout<<"Unesite elemente matrice:";
			for(int i=0; i<m; i++) {
				for(int j=0; j<n; j++) {
					std::cin>>matrica.at(i).at(j);
				}
			}
			Dblmatrica planina;
			planina=NajvecaPlaninaMatrice(matrica);
			std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
			for(int i=0; i<planina.size(); i++) {
				for(int j=0; j<planina.size(); j++) {
					std::cout<<std::setw(6)<<planina.at(i).at(j);
				}
				std::cout<<std::endl;
			}
		}
	} catch( std::domain_error poruka) {
		std::cout<<poruka.what()<<std::endl;
	}
	return 0;
}

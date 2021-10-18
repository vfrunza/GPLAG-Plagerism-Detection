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

typedef std::vector<std::vector<double> > matrica;

double Planina(matrica m) //funkcija koja provjerava da li je matrica oblika Planina matrice
{
	int n(m.size()); //prosljedjujemo kvadratnu matricu, pa je dovoljno gledati samo broj redova
	if(n<=0) return 0;
	int p((n-1)/2);
	double vrh ((m.at(p)).at(p));
	double max(vrh);
	for(int k=1; k<n-p; k++) {
		double suma(0);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if((i>=(p-k) && i<=(p+k)) && (j>=(p-k) && j<=(p+k))) {
					if(i==p-k || j==p-k || i==p+k || j==p+k) {
						suma += (m.at(i)).at(j);
					}
				}
			}

		}
		if(suma < max) max=suma;  //suma je zbir clanova matrice u koncentricnom kvadratu koja mora biti manja od vrijednosti vrha ili od prethodne sume koncentricog kvadrata
		else return 0;
	}

	return vrh; //funkcija vraca vrijednost vrha matrice ili "0" u slucaju da matrica nije Planina matrica
}

matrica NajvecaPlaninaMatrice(matrica m)
{
	matrica planina;
	if(m.size()==0 || (m.at(0)).size()==0) throw m;
	int br_kolona((m.at(0)).size());
	for(auto red:m) {
		if(int(red.size()) != br_kolona) throw std::domain_error("Matrica nije korektna");
	}
	int br_redova(m.size());
	int n(0);           //maximalna dimenzija Planina matrice
	if(br_redova>br_kolona) n=br_kolona;
	else n=br_redova;
	int brojac(0);      //varijabla koja označava broj Planina matrica
	int max_vrh(0);
	int max_dimenzija(0);

	for(int k=n; k>=0; k--) {                           //k ce biti dimenzija najvece planine matrice
		if(k%2 != 0) {								    //po uslovu zadatka "n" je neparno
			for(int t=0; t<=br_redova-k; t++) {         //u nasoj matrici ima vise kvadratnih podmatrica dimenzija manjih od "n" ..
				for(int h=0; h<=br_kolona-k; h++) {     // ..pa tu podmatricu pomjeramo pomocu "t" i "h" da bi obuhvatili sve slucajeve
					matrica pomocna;                    //matrica koju šaljemo u f-iju "Planina"
					int vel(0);                         //dimenzija pomocne matrice
					pomocna.resize(k);
					for(int i=0+t; i<k+t; i++) {        //unutar ove petlje je jedna podmatrica dimenzije "k" čijim članovima pristupamo sa "i" i "j"
						for(int j=0+h; j<k+h; j++) {
							(pomocna.at(vel)).push_back((m.at(i)).at(j));
						}
						vel++;
					}

					int temp (Planina(pomocna));  //varijabla u koju privremeno smještamo rezultat f-ije "Planina" pa je poredimo sa "max_vrh"
					if(temp!=0 && max_dimenzija<=k) {
						max_dimenzija = k;
						brojac++;
						if(brojac>1) {  //ukoliko je ovo nova matrica planina, istih dimenzija kao prethodna, moramo im porediti vrhove
							if(max_vrh<temp) {
								max_vrh = temp;
								planina = pomocna;
							}
						} else {
							planina = pomocna;
							max_vrh = temp;
						}
					}
				}
			}
			if(brojac!=0) break; //ako se pojavila matrica planina, onda je ona najveca matrica planina i dalje ne moramo provjeravati
		}
	}


	return planina;
}

int main ()
{
	int m, n;
	try {
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		for(;;) {
			std::cin>>m>>n;
			if(std::cin) break;
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');

		}
		if(m<0 || n<0) throw ("Dimenzije matrice moraju biti nenegativne!");
		matrica mat(m, std::vector<double>(n));
		if(m!=0 && n!=0) {
			std::cout<<"Unesite elemente matrice: ";
			for(int i=0; i<m; i++) {
				for(int j=0; j<n; j++) {
					for(;;) {
						std::cin>>(mat.at(i)).at(j);
						if(std::cin) break;
						std::cout<<"Neispravan unos! Unesite ponovo: ";
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}
				}
			}
		}
		matrica planina;
		planina = NajvecaPlaninaMatrice(mat);
		std::cout<<"\nNajveca planina unesene matrice je:\n";
		for(auto red:planina) {
			for(auto x:red) {
				std::cout<<std::setw(6)<<x;
			}
			std::cout<<"\n";
		}

	} catch (const char izuzetak[]) {
		std::cout<<izuzetak<<std::endl;
	} catch (const std::domain_error &e) {
		std::cout << "Izuzetak: " << e.what() << std::endl;
	} catch(const matrica &nulta) {
		std::cout<<"\nNajveca planina unesene matrice je:\n";
		for(auto red:nulta) {
			for(auto x:red) {
				std::cout<<std::setw(6)<<x;
			}
			std::cout<<"\n";
		}
	} catch(...) {
		std::cout << "Pogrešan izuzetak!";
	}
	return 0;
}
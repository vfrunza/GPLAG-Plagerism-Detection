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
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <cmath>

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> m)
{
	std::vector<std::vector<double>> planina;

	if(m.size()==0 || m.at(0).size()==0) return planina;

	int velicina=m.at(0).size();
	for(int i=1; i<m.size(); i++) {
		if(m.at(i).size()!=velicina) throw std::domain_error("Matrica nije korektna");
	}

// za matrice kolone(vrste) i one cija je jedna dimenzija manja od 3 planina je zapravo najveci njen element
// te je dovoljno njega vratiti tj. vratiti matricu formata 1x1 (nece postojati planina veceg neparnog reda)
	double naj=m.at(0).at(0);
	if(m.size()<3 || m.at(0).size()<3) {
		for(int i=0; i<m.size(); i++) {
			for(int j=0; j<m.at(0).size(); j++) if(m.at(i).at(j)>naj) naj=m.at(i).at(j);
		}
		planina.resize(1);
		planina.at(0).push_back(naj);
		return planina;
	}

// kada je matrica formata vecih od 3 trazimo planine prema poznatom pravilu

	int prvadimenzija(m.size()), drugadimenzija(m.at(0).size());
	int najvecadimenzijaplanine;
	if(prvadimenzija<drugadimenzija) najvecadimenzijaplanine=prvadimenzija;
	else najvecadimenzijaplanine=drugadimenzija;
	if(najvecadimenzijaplanine%2==0) najvecadimenzijaplanine-=1;            // odredjujemo najveci moguci red planine matrice

	int prvakoord(0), drugakoord(0), temp_prva(0), temp_druga(0);
	double temp_suma(0);
	double clan, vrh(m.at(0).at(0));

	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.at(0).size(); j++) {

			std::vector<std::vector<double>> privremena; // deklarisana matrica ce sluziti za smjestanje potencijalnih najvecih planina zadane matrice

			clan=m.at(i).at(j);
			temp_prva=i;
			temp_druga=j;
			int pocetak1(i), pocetak2(j);

			privremena.resize(1);
			privremena.at(0).push_back(clan);

			double unutra(m.at(i).at(j));
			for(int k=1; k<=najvecadimenzijaplanine; k++) {
				if (pocetak1-k<0 || pocetak2-k<0 || k+pocetak1>=m.size() || k+pocetak2>=m.at(0).size()) break;
				for(int p=pocetak1-k; p<=pocetak1+k; p++) {
					for(int q=pocetak2-k; q<=pocetak2+k; q++) {
						if(p==pocetak1-k || p==pocetak1+k || q==pocetak2-k || q==pocetak2+k) temp_suma+=m.at(p).at(q);
					}
				}

				if(temp_suma<unutra) {
					privremena.resize(0);
					int kontrolna(0);
					for(int p=pocetak1-k; p<=pocetak1+k; p++) {
						privremena.resize(privremena.size()+1);
						for(int q=pocetak2-k; q<=pocetak2+k; q++) {
							privremena.at(kontrolna).push_back(m.at(p).at(q));
						}
						kontrolna++;
					}
				}
				unutra=temp_suma;
				temp_suma=0;
			}
			if(privremena.size()>planina.size()) {                              // odabir trazene najvece planine prema uvjetima zadatka
				planina=std::move(privremena);
				vrh=clan;
				prvakoord=temp_prva;
				drugakoord=temp_druga;
			}
			if(privremena.size()==planina.size()) {
				if(clan>vrh || (std::fabs(clan-vrh)>0 && temp_prva>prvakoord) || (std::fabs(clan-vrh)>0 && temp_prva==prvakoord && temp_druga>drugakoord)) {
					planina=std::move(privremena);
					vrh=clan;
					prvakoord=temp_prva;
					drugakoord=temp_druga;
				}
			}
		}
	}
	
	return planina;
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 1;
	}

	std::vector<std::vector<double>> matrica (m, std::vector<double>(n));

	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> matrica.at(i).at(j);
		}
	}
	std::cout << std::endl;

	try {
		std::vector<std::vector<double>> naj_planina(NajvecaPlaninaMatrice(matrica));

		std::cout << "Najveca planina unesene matrice je: " << std::endl;
		for(int i=0; i<naj_planina.size(); i++) {
			for(int j=0; j<naj_planina.at(0).size(); j++) {
				std::cout << std::setw(6) << naj_planina.at(i).at(j);
			}
			std::cout << std::endl;
		}

	} catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}

	return 0;
}
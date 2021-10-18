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
using std::cout;
using std::cin;
typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;
bool DaLiJeGrbava(const Matrica &m) {
	for (int i(0);i<m.size()-1;i++) {
		if (m.at(i).size()!=m.at(i+1).size())
			return true;
	}
	return false;
}
long double IzracunajSumuLevela (const Matrica &m, int x, int y, int velicina) {
	long double suma(0);
	for (int i(x-velicina);i<=x+velicina;i++) 
		for (int j(y-velicina);j<=y+velicina;j++)
			if ((i==x-velicina || i==x+velicina) || (j==y-velicina || j==y+velicina)) 
				suma+=m.at(i).at(j);
	return suma;
}
Matrica NapraviMatricu (const Matrica &m, int x, int y, int velicina) {
	Matrica povratna;
	int brojac(0);
	for (int i(x-velicina);i<=x+velicina;i++) {
		povratna.resize(++brojac);
		for (int j(y-velicina);j<=y+velicina;j++) {
			povratna.at(brojac-1).push_back(m.at(i).at(j));
		}
	}
	return povratna;
}
Matrica NajvecaPlaninaMatrice(const Matrica &m) {
	if (DaLiJeGrbava(m)) throw std::domain_error("Matrica nije korektna");
	Matrica povratnaMatrica;
	if (!m.size() || !m.at(0).size())
		return povratnaMatrica;
	int maxvelicina(0), xkoordinatamaxa(0), ykoordinatamaxa(0);
	double maxvrh(m.at(0).at(0));
	for (int i=0;i<m.size();i++) {
		for (int j=0;j<m.at(i).size();j++) {
			long double pocetnasuma(m.at(i).at(j)), suma;
			int velicina(1);
			while (i-velicina>=0 && i+velicina<m.size() && j-velicina>=0 && j+velicina<m.at(i).size()) {
				suma=IzracunajSumuLevela(m, i, j, velicina);
				if (suma>=pocetnasuma)
					break;
				pocetnasuma=suma;
				velicina++;
			}
			velicina--;
			if (velicina>maxvelicina) {
				maxvelicina=velicina;
				maxvrh=m.at(i).at(j);
				xkoordinatamaxa=i;
				ykoordinatamaxa=j; // POPRAVIT CU SVE OVO NO H8 PLS
			}
			if (velicina==maxvelicina) {
				if (m.at(i).at(j)>maxvrh) {
					maxvrh=m.at(i).at(j);
					xkoordinatamaxa=i;
					ykoordinatamaxa=j;
				}
			}
		}
	}
	povratnaMatrica=NapraviMatricu(m, xkoordinatamaxa, ykoordinatamaxa, maxvelicina);
	return povratnaMatrica;
}
int main ()
{
	cout<<"Unesite dimenzije matrice (m i n): ";
	int m, n;
	cin>>m>>n;
	if (m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat;
	cout<<"Unesite elemente matrice: ";
	for (int i=0;i<m;i++) {
		mat.resize(i+1);
		for (int j=0;j<n;j++) {
		   double broj;
		   cin>>broj;
		   mat.at(i).push_back(broj);
		}
	}
	auto najvecaPlanina=NajvecaPlaninaMatrice(mat);
	cout<<std::endl<<"Najveca planina unesene matrice je: "<<std::endl;
	for (auto red : najvecaPlanina) {
		for (auto broj : red) 
			cout<<std::setw(6)<<std::right<<broj;
		cout<<std::endl;
	}
	return 0;
}
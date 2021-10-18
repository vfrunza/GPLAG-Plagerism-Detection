#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

double Suma (Matrica m, int pozicija_red, int pozicija_kolona, int br)
{
	double s(0);
	for (int i(pozicija_kolona-br); i<=pozicija_kolona+br; i++) {
		s += m.at(pozicija_red-br).at(i);
	}

	for (int i(pozicija_kolona-br); i<=pozicija_kolona+br; i++) {
		s += m.at(pozicija_red+br).at(i);
	}

	for (int i(pozicija_red-br); i<=pozicija_red+br; i++) {
		s += m.at(i).at(pozicija_kolona-br);
	}

	for (int i(pozicija_red-br); i<=pozicija_red+br; i++) {
		s += m.at(i).at(pozicija_kolona+br);
	}

	s=s-(m.at(pozicija_red-br).at(pozicija_kolona-br) + m.at(pozicija_red-br).at(pozicija_kolona+br) + m.at(pozicija_red+br).at(pozicija_kolona-br) + m.at(pozicija_red+br).at(pozicija_kolona+br));
	return s;
}


Matrica NajvecaPlaninaMatrice (Matrica m)
{
	int k(0), l(0);
	bool grbava(false);
	for (int i(1); i<m.size(); i++) {
		if (m.at(i).size() != m.at(i-1).size()) grbava=true;
	}
	if (grbava) throw std::domain_error ("Matrica nije korektna");
	if (m.size()==0) return m;
	double broj_kolona = m.at(0).size();
	double broj_redova = m.size();
	Matrica NajvecaPlanina ;
	if (broj_kolona == 2 || broj_redova==2 || broj_kolona==1 || broj_redova==1) {
		for (int i(0); i<broj_redova; i++) {
			for (int j(0); j<broj_kolona; j++) {
				Matrica NajvecaPlanina (1, std::vector <double> (1));
				if (i==0 && j==0) NajvecaPlanina.at(k).at(l)=m.at(i).at(j);
				else if (NajvecaPlanina.at(k).at(l) < m.at(i).at(j)) NajvecaPlanina.at(k).at(l)=m.at(i).at(j);
				if (i==broj_redova-1 && j==broj_kolona-1) return NajvecaPlanina;
			}
		}
	}

	else 
	{
		Matrica NajvecaPlanina (broj_redova, std::vector<double> (broj_kolona));
		double max_element;
		int pozicija_red(0), pozicija_kolona(0), b(0);
		for (int i(0); i<broj_redova; i++) {
			for (int j(0); j<broj_kolona; j++) {
				if (i==0 && j==0) max_element=m.at(i).at(j);
				else if (max_element<m.at(i).at(j)) {
					max_element=m.at(i).at(j);
					pozicija_kolona=j;
					pozicija_red=i;
				}
			}
		}
		if (pozicija_red==0 || pozicija_kolona==0) {
			NajvecaPlanina.resize(0);
			return NajvecaPlanina;
		}
		int brojac(1);
		for (int o(0); broj_redova>pozicija_red+brojac && broj_kolona>pozicija_kolona+brojac; ++o) {
			int suma;
			suma = Suma (m, pozicija_red, pozicija_kolona, brojac);
			if (suma < m.at(pozicija_red).at(pozicija_kolona)) {
				for (int i(pozicija_red-brojac); i<=pozicija_red+brojac; i++) {
					for (int j(pozicija_kolona-brojac); j<=pozicija_kolona+brojac; j++) {
						NajvecaPlanina.at(k).at(l)=m.at(i).at(j);
						l++;
					}
					k++;
					l=0;
					b=k;
				}
			}
			brojac++;
			k=0;
		}

		NajvecaPlanina.resize(b);
		for (int i(0); i<NajvecaPlanina.size(); i++) {
			NajvecaPlanina.at(i).resize(b);
		}
		return NajvecaPlanina;
	}


}

int main ()
{
	int n, m;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	if (m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	if (m==0 || n==0) return 0;
	std::cout<<"Unesite elemente matrice:\n";
	Matrica matrica (m, std::vector<double> (n));
	for (int i(0); i<m; i++) {
		for (int j(0); j<n; j++) {
			double broj;
			std::cin>>broj;
			matrica.at(i).at(j)=broj;
		}
	}

	try {
		Matrica NajvecaPlanina=NajvecaPlaninaMatrice(matrica);
		if (NajvecaPlanina.size()==0) return 0;
		std::cout << "Najveca planina unesene matrice je:" << std::endl;
		for (int i(0); i<NajvecaPlanina.size(); i++) {
			for (int j(0); j<NajvecaPlanina.size(); j++) {
				std::cout << std::setw(6) << NajvecaPlanina.at(i).at(j);
			}
			std::cout << std::endl;
		}
	}

	catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	return 0;
}
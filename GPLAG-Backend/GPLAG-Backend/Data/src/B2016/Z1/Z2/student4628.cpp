//B 2016/2017, Zadaća 1, Zadatak 2

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica ;

Matrica UnesiMatricu (int br_redova, int br_kolona)
{
	Matrica a (br_redova, Vektor(br_kolona));
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona; j++)
			cin >> a.at(i).at(j);
	}
	return a;
}

Matrica HorizontalnoOgledalo (Matrica a)
{
	if(a.size() == 0 || a[0].size() == 0)
		return Matrica (0, Vektor(0));

	Matrica d;
	for(int i = 0; i < a.size(); i++) {
		Vektor c;
		for(int j = a.at(i).size() - 1; j >= 0; j--)
			c.push_back(a.at(i).at(j));         // u novi vektor c unosim elemente redova matrice od posljednjeg ka prvom
		d.push_back(c);                         // redove "slazem" u novu matricu d
	}
	return d;
}

Matrica VertikalnoOgledalo (Matrica b)
{
	if(b.size() == 0 || b[0].size() == 0)
		return Matrica (0, Vektor(0));
	Matrica c;
	for(int i = b.size() - 1; i >= 0; i--)
		c.push_back(b.at(i));                   // u novu matricu ubacujem redove matrice poslane kao parametar f-je u obrnutom redoslijedu

	return c;
}

Matrica OgledaloMatrica (Matrica D)
{
	for(int i = 0; i < D.size(); i++) {
		if(i != D.size() - 1)
			if(D[i].size() != D[i+1].size())                       // ukoliko nije jednak broj elemenata svakog reda matrica je grbava
				throw std::domain_error("Matrica nije korektna"); // bacamo izuzetak
	}
	
	Matrica M;
	Matrica h = std::move(HorizontalnoOgledalo(D));
	Matrica v = std::move(VertikalnoOgledalo(D));
	Matrica hv = std::move(HorizontalnoOgledalo(D));
	hv = std::move(VertikalnoOgledalo(hv));

	//u pomocni vektro ubacujem elemente i-tog reda matrica, a zatim elemente tog vektora ubacujem u ogledalo matricu
	for(int i = 0; i < D.size(); i++) {
		Vektor pomocni;

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(hv.at(i).at(j));

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(v.at(i).at(j));

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(hv.at(i).at(j));

		M.push_back(pomocni);
	}

	for(int i = 0; i < D.size(); i++) {
		Vektor pomocni;

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(h.at(i).at(j));

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(D.at(i).at(j));

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(h.at(i).at(j));

		M.push_back(pomocni);
	}

	for(int i = 0; i < D.size(); i++) {
		Vektor pomocni;

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(hv.at(i).at(j));

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(v.at(i).at(j));

		for(int j = 0; j < D[i].size(); j++)
			pomocni.push_back(hv.at(i).at(j));

		M.push_back(pomocni);

	}

	return M;
}

int main ()
{
	try {
		int n, m;
		cout << "Unesite dimenzije matrice (m n): ";
		cin >> m >> n;
		if( m < 0 || n < 0 ) {
			cout << "Dimenzije matrice moraju biti nenegativne!";
			return 1;
		}

		cout << "Unesite elemente matrice: ";
		auto D (UnesiMatricu(m, n));

		cout << endl <<"Rezultantna matrica: " << endl;

		auto A = std::move(OgledaloMatrica(D));
		for(int i = 0; i < 3*m; i++) {
			for(int j = 0; j < 3*n; j++)
				cout << std::setw(4) << A.at(i).at(j);
			cout << endl;
		}

	} catch (std::domain_error izuzetak) {
		cout << izuzetak.what() << endl;  // hvatanje izetka i ispisivanje odgovarajuce poruke
	}

	return 0;
}
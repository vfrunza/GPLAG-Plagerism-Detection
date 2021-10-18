//B 2016/2017, Zadaća 1, Zadatak 2

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> matrica;
typedef std::vector<double> vektor;

matrica OgledaloMatrica (matrica ulaz);
bool JeGrbava(matrica ulaz);

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	if(std::cin >> m >> n, m < 0 || n < 0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	matrica mat(m);
	for(int i = 0; i< m; i++) mat[i].resize(n);
	double br;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) {
			std::cin >> br;
			mat[i][j] = br;
		}

	std::cout << std::endl;

	try {
		auto rezultat(OgledaloMatrica(mat));
		std::cout << "Rezultantna matrica:";
		for(auto x: rezultat) {
			std::cout << std::endl;
			for(auto y: x)
				std::cout<< std::setw(4) << y;
		}
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}

	return 0;
}

bool JeGrbava(matrica ulaz)
{
	for(int i = 0; i < ulaz.size(); i++)
		if(ulaz[0].size() != ulaz[i].size())
			return true;

	return false;
}


matrica OgledaloMatrica (matrica ulaz)
{

	if (JeGrbava(ulaz)) throw std::domain_error("Matrica nije korektna");

	matrica nova;

	nova.resize(ulaz.size()*3);

	for(int i = 0; i < nova.size(); i++)
		nova[i].resize(ulaz[0].size()*3);


	//kreiramo novu matricu koju ćemo kasnije mijenjati
	int x(0);
	for(int i = 0; i < nova.size(); i++) {
		int y(0);
		for(int j = 0; j < nova[0].size(); j++) {
			nova[i][j] = ulaz[x][y];
			y++;

			if (y == ulaz[0].size())
				y = 0;
		}
		x++;
		if(x == ulaz.size())
			x = 0;
	}

	vektor temp;
	int k(0);

	//kreiramo vertikalna ogledala originalne matrice i počinjemo sa kreacijom kombinovanih
	for(int i = 0; i < nova.size(); i++) {

		if(i < ulaz.size() &&  i < ulaz.size()/2) {
			temp = nova[i];
			nova[i] = nova[ulaz.size()-(i+1)];
			nova[ulaz.size()-(i+1)] = temp;
		}

		if(i > ulaz.size()*2 - 1 ) {
			nova[i] = nova[k];
			k++;
		}
	}

	// nova pomoćna varijabla
	double temp2;

	for(int i = 0; i < nova.size(); i++) {
		int f(0);
		k = 0;
		//dovršavamo kombinovana ogledala originalne matrice
		for(int j = 0; j < nova[0].size(); j++) {
			if(i < ulaz.size() || i > ulaz.size()*2 - 1) {
				if(j < ulaz[0].size() && j < ulaz[0].size()/2) {
					temp2 = nova[i][j];
					nova[i][j] = nova[i][ulaz[0].size()-(j+1)];
					nova[i][ulaz[0].size()-(j+1)] = temp2;
				}

				if(j > ulaz[0].size()*2 - 1 ) {
					nova[i][j] = nova[i][k];
					k++;
				}
			}
			//kreiramo horizontalna ogledala originalne matrice
			if(i > ulaz.size()-1 && i < ulaz.size()*2) {
				if(j < ulaz[0].size() && j < ulaz[0].size()/2) {
					temp2 = nova[i][j];
					nova[i][j] = nova[i][ulaz[0].size()-(j+1)];
					nova[i][ulaz[0].size()-(j+1)] = temp2;
				}

				if(j > ulaz[0].size()*2 - 1) {
					nova[i][j] = nova[i][f];
					f++;
				}
			}
		}
	}
	return nova;
}
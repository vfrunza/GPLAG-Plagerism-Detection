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
#include <iomanip>
#include <stdexcept>
#include <vector>

// Razlog zasto sam koristio define u ovoj situaciji je to sto mi je imalo vise
// smisla od konstante u trenutku
#define DIM_UNDEF -100

typedef std::vector<std::vector<double>> dblMatrix;

// PROTOTIPI funkcija
// Pomocne funkcije direktno vezane za zadatak
bool isRectangular(dblMatrix);
int dimensionOfMountain(dblMatrix, int, int);

// Funkcija zadata za implementaciju
dblMatrix NajvecaPlaninaMatrice(dblMatrix);

int main ()
{
	int m, n;
	
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	if (m < 0 || n < 0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	
	dblMatrix input(m, std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	for (int i{0}; i < m; i++)
		for (int j{0}; j < n; j++)
			std::cin >> input.at(i).at(j);
			
	std::cout << std::endl;
	
	dblMatrix res;
	try {
		res = std::move(NajvecaPlaninaMatrice(input));
	}
	catch (std::domain_error ex) {
		std::cout << ex.what() << std::endl;
		return 0;
	}
	
	std::cout << "Najveca planina unesene matrice je: " << std::endl;
	for (auto row : res) {
		for (auto num : row)
			std::cout << std::setw(6) << num;
			
		std::cout << std::endl;
	}
	
	return 0;
}

dblMatrix NajvecaPlaninaMatrice(dblMatrix matrix)
{
	// Provjeri validnost matrice prije ma kakvog rada na njoj
	if (!isRectangular(matrix))
		throw std::domain_error("Matrica nije korektna");
	
	// Ukoliko matrica nema redova ili kolona, dimenzija maksimalne planine
	// ce ostati nedefinirana, te petlja koja kopira matricu u rjesenje nece
	// nista uraditi (jer je DIM_UNDEF negativan)
	int maxDimension{DIM_UNDEF}, iMax{0}, jMax{0};
	
	for (int i{0}; i < matrix.size(); i++)
	{
		for (int j{0}; j < matrix.at(i).size(); j++)
		{
			int currDimension{dimensionOfMountain(matrix, j, i)};
			if (currDimension > maxDimension || (currDimension == maxDimension &&
				matrix.at(iMax).at(jMax) < matrix.at(i).at(j)))
				{
					maxDimension = currDimension;
					iMax = i;
					jMax = j;
				}
		}
	}
	
	dblMatrix res;
	
	// Moze se napisati veci nivo apstrakcije (copySubMatrix()?), ali je i ovo prihvatljivo
	for (int i{iMax - maxDimension / 2}; i <= iMax + maxDimension / 2; i++)
	{
		std::vector<double> row;
		for (int j{jMax - maxDimension / 2}; j <= jMax + maxDimension / 2; j++)
			row.push_back(matrix.at(i).at(j));
			
		res.push_back(row);
	}
	
	return res;
}

// Funkcija koja vraca dimenziju planine koja bi se posmatrala ako uzmemo
// da nam je vrh u (x, y) u prosljedjenoj matrici
// x = j, y = i
int dimensionOfMountain(dblMatrix matrix, int x, int y)
{
	double currSum{matrix.at(y).at(x)};
	// Pretpostavimo da je dimenzija barem 3 (jer je barem jedan u svakom slucaju)
	int currDimension{3};
	
	while (true)
	{
		// Ukoliko smo dosli do rubova, ne moze se dalje povecavati dimenzija
		if (y - currDimension / 2 < 0 || y + currDimension / 2 >=matrix.size())
			break;
		
		if (x - currDimension / 2 < 0 || x + currDimension / 2 >= matrix.at(0).size())
			break;
		
		// Izracunavanje sume trenutnog prstena
		double sum{0};
		for (int i{0}; i < currDimension; i++)
		{
			// Gornja strana
			sum += matrix.at(y - currDimension / 2).at(x - currDimension / 2 + i);
			
			// Donja strana
			sum += matrix.at(y + currDimension / 2).at(x - currDimension / 2 + i);
			
			// Lijeva strana
			sum += matrix.at(y - currDimension / 2 + i).at(x - currDimension / 2);
			
			// Desna strana
			sum += matrix.at(y - currDimension / 2 + i).at(x + currDimension / 2);
		}
		
		// Odmakni po cosak koji smo dvaput dodali
		// Gore-lijevo
		sum -= matrix.at(y - currDimension / 2).at(x - currDimension / 2);
		// Dolje-lijevo
		sum -= matrix.at(y + currDimension / 2).at(x - currDimension / 2);
		// Gore-desno
		sum -= matrix.at(y - currDimension / 2).at(x + currDimension / 2);
		// Dolje-desno
		sum -= matrix.at(y + currDimension / 2).at(x + currDimension / 2);
		
		// Da li je suma ovog prstena manja od prethodnog prstena
		// nije planina
		if (currSum <= sum)
			break;
			
		currDimension += 2;
		currSum = sum;
	}
	
	// Nije uspjelo sa trenutnom pretpostavkom dimenzije, vrati se na onu koja je bila u prethodnom
	// slucaju, tj. oduzmi dva
	currDimension -= 2;
	
	// Ako nije planina ovo ce vratiti -1, te to nece nista promijeniti
	return currDimension;
}

// Funkcija vraca true ukoliko matrica nije grbava,
// a false u suprotnom
bool isRectangular(dblMatrix matrix)
{
	for (int i{0}; i < matrix.size() - 1; i++)
		if (matrix.at(i).size() != matrix.at(i + 1).size())
			return false;
	
	return true;
}
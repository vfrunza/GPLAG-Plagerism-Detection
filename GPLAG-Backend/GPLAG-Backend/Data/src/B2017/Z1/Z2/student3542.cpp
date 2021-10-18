/*B 2017/2018, ===TITLE===
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: student3542@etf.unsa.ba.	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

int min(int a, int b, int c, int d)
{
    int e(a < b ? a : b), f(c < d ? c : d);
    return e < f ? e : f;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica)
{
    if (matrica.empty()) 
    	return std::vector<std::vector<double>>();

    for (std::vector<double> vektor : matrica)
		if (vektor.size() != matrica.at(0).size())
			throw std::domain_error("Matrica nije korektna");
			
    if (!matrica.at(0).size()) 
    	return std::vector<std::vector<double>>();
    	
    //Glavni dio
    int maxdim(0), maxvrh(0), x, y;
    for (int i(0); i < matrica.size(); i++)
        for (int j(0); j < matrica.at(0).size(); j++)
        {
            int prethodni(matrica.at(i).at(j)), max(min(i, j, matrica.size() - 1 - i, matrica.at(0).size() - 1 - j)), d(0), dim(0);
            while (++d <= max)
            {
                //Racunanje zbira elemenata d-tog koncentricnog kvadrata
                double s(0);
                for (int k(i-d); k <= i+d; k++)
                    for (int l(j-d); l <= j+d; l++)
                        if (k == i-d || k == i+d || l == j-d || l == j+d)
                            s += matrica.at(k).at(l);
                if (s < prethodni) 
                	prethodni = s;
                else break;
            }
            dim = 2*d - 1;
            //Postavljanje novog kandidata
            if (dim > maxdim || (dim == maxdim && matrica.at(i).at(j) > maxvrh))
                maxvrh = matrica.at(i).at(j), maxdim = dim, x = i - d + 1, y = j - d + 1;
        }
    std::vector<std::vector<double>> tmp(maxdim);
    for (int i(x); i < x + maxdim; i++)
        for (int j(y); j < y + maxdim; j++)
            tmp.at(i-x).push_back(matrica.at(i).at(j));
    return tmp;
}

int _main ()
{
    int m, n;
    std::cout << "Unesite dimenzije matrice (m i n): ";
    if (!(std::cin >> m >> n), m < 0 || n < 0)
    {
        std::cout << "Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    
    std::cout << "Unesite elemente matrice:\n";
    std::vector<std::vector<double>> matrica(m, std::vector<double>(n));
    for (std::vector<double> &red : matrica)
        for (double &el : red)
            std::cin >> el;
            
    std::cout << "Najveca planina unesene matrice je:" << std::endl;
    matrica = NajvecaPlaninaMatrice(matrica);
    
    for (std::vector<double> red : matrica)
    {
        for (double element : red)
            std::cout << std::setw(6) << element;
        std::cout << std::endl;
    }
	return 0;
}


std::vector<std::vector<double>> PomocnaFunkcija (std::vector<std::vector<double>> m)
    {
        size_t br = m.size();
        size_t bk = br ? m.at(0).size() : 0;
        std::vector<std::vector<double>> r (3 * br, std::vector<double> (3 * bk));
        for (size_t i = 0; i < br; ++i)
            for (size_t j = 0; j < bk; ++j)
            {
                auto el = m.at(i).at(j);
                r.at(br - i - 1)    .at(bk - j - 1)     = el; //gornja-lijeva
                r.at(br - i - 1)    .at(j + bk)         = el; //gornja-srednja
                r.at(br - i - 1)    .at(3 * bk - j - 1) = el; //gornja-desna
                r.at(i + br)        .at(bk - j - 1)     = el; //centralna-lijeva
                r.at(i + br)        .at(j + bk)         = el; //centralna-srednja
                r.at(i + br)        .at(3 * bk - j - 1) = el; //centralna-desna
                r.at(3 * br - i - 1).at(bk - j - 1)     = el; //donja-lijeva
                r.at(3 * br - i - 1).at(j + bk)         = el; //donja-srednja
                r.at(3 * br - i - 1).at(3 * bk - j - 1) = el; //donja-desna
            }
        return r;
    }

int main()
{
    _main();
    _main();
    _main();
    
}
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using std::vector;
typedef vector<vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice(Matrica mat)
{
    if (!mat.size()) return Matrica();
    int m(mat.size()), n(mat.at(0).size());
    for (auto red : mat)
        if (red.size() != n) throw std::domain_error("Matrica nije korektna");
    if (n == 0) return Matrica();
    //Glavni dio
    int maxdim(0), x(0), y(0);
    double maxvrh(0);
    for (int i(0); i < m; i++)
        for (int j(0); j < n; j++)
        {
            int d(0), dim(0);
            double prethodni(mat.at(i).at(j));
            while (++d <= i && d <= j && d <= m-1-i && d <= n-1-j)
            {
                //Racunanje zbira elemenata d-tog koncentricnog kvadrata
                double s(0);
                for (int k(i-d); k <= i+d; k++)
                    for (int l(j-d); l <= j+d; l++)
                        if (k == i-d || k == i+d || l == j-d || l == j+d)
                            s += mat.at(k).at(l);
                if (s < prethodni) prethodni = s;
                else break;
            }
            //Postavljanje novog kandidata
            if ((dim = 2*d - 1) > maxdim || (dim == maxdim && mat.at(i).at(j) > maxvrh))
            {
                maxvrh = mat.at(i).at(j);
                maxdim = dim;
                x = i - d + 1;
                y = j - d + 1;
            }
        }
    //Vracanje planine matrice
    Matrica tmp(maxdim, vector<double>(maxdim));
    for (int i(x); i < x + maxdim; i++)
        for (int j(y); j < y + maxdim; j++)
            tmp.at(i-x).at(j-y) = mat.at(i).at(j);
    return tmp;
}
int main()
{
    int m, n;
    std::cout << "Unesite dimenzije matrice (m i n): ";
    std::cin >> m >> n;
    if (m < 0 || n < 0)
    {
        std::cout << "Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::cout << "Unesite elemente matrice:\n";
    Matrica mat(m, vector<double>(n)), np;
    for (int i(0); i < m; i++)
        for (int j(0); j < n; j++)
            std::cin >> mat.at(i).at(j);
    try
    {
        np = NajvecaPlaninaMatrice(mat);
        std::cout << "Najveca planina unesene matrice je:\n";
        for (auto red : np)
        {
            for (double el : red)
                std::cout << std::setw(6) << el;
            std::cout << std::endl;
        }
    }
    catch (std::domain_error e)
    {
        std::cout << e.what();
        return 0;
    }
	return 0;
}
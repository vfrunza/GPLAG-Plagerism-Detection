#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice(Matrica matrica)
{
    for (int i=0; i<matrica.size(); i++) {
        if (matrica.at(i).size()!= matrica.at(0).size()) throw std::domain_error("Matrica nije korektna");
        //ne trebamo hvatati
    }

    double suma(0);
    for (int i=0; i<matrica.size(); i++) {
        for (int j=0; j<matrica.at(i).size(); j++) {


        }
    }
    return matrica;
}

int main ()
{
    int m,n;
    Matrica matrica;
    std::cout << "Unesite dimenzije matrice (m i n): ";
    std::cin >> m >> n;
    if (m<0 || n<0) std::cout << "Dimenzije matrice moraju biti nenegativne!";
    else {

        std::cout << "Unesite elemente matrice: ";
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                std::cin >> matrica.at(i).at(j);
            }
        }
        std::cout << std::endl;
        //Matrica izlazna(NajvecaPlaninaMatrice(matrica));
        std::cout << "Najveca planina unesene matrice je:";
        // std::cout << NajvecaPlaninaMatrice(matrica);

    }
    return 0;
}
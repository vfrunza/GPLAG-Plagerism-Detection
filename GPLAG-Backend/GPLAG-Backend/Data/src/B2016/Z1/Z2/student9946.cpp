#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica DodajHorizontalnu(int pozicija_x, int pozicija_y, Matrica original, Matrica rezultat)
{
    for (int i = 0; i < original.size(); i++) {
        for (int j = 0; j < original[i].size(); j++) {
            rezultat[pozicija_y*original.size() + i][pozicija_x*original[i].size() +  original[i].size() - j - 1] = original[i][j];
        }
    }
    return rezultat;
}

Matrica DodajVertikalnu(int pozicija_x, int pozicija_y, Matrica original, Matrica rezultat)
{
    for (int i = 0; i < original.size(); i++) {
        for (int j = 0; j < original[i].size(); j++) {
            rezultat[pozicija_y*original.size() + original.size() - i - 1][pozicija_x*original[i].size() +  j] = original[i][j];
        }
    }
    return rezultat;
}

Matrica DodajKosu(int pozicija_x, int pozicija_y, Matrica original, Matrica rezultat)
{
    for (int i = 0; i < original.size(); i++) {
        for (int j = 0; j < original[i].size(); j++) {
            rezultat[pozicija_y*original.size() + original.size() - i - 1][pozicija_x*original[i].size() +  original[i].size() - j - 1] = original[i][j];
        }
    }
    return rezultat;
}

Matrica DodajOriginalnu(int pozicija_x, int pozicija_y, Matrica original, Matrica rezultat)
{
    for (int i = 0; i < original.size(); i++) {
        for (int j = 0; j < original[i].size(); j++) {
            rezultat[pozicija_y*original.size() + i][pozicija_x*original[i].size() + j] = original[i][j];
        }
    }
    return rezultat;
}

Matrica OgledaloMatrica(Matrica original)
{
    int broj_redova = original.size(), broj_kolona;

    if (broj_redova == 0) {
        broj_kolona = 0;
    } else {
        broj_kolona = original[0].size();
    }

    if (broj_redova > 1) {
        for (int i = 1; i < broj_redova; i++) {
            if (original[i].size() != broj_kolona) {
                throw std::domain_error("Matrica nije korektna");
            }
        }
    }
    Matrica rezultat = Matrica(broj_redova*3, std::vector<double>(broj_kolona*3));

    rezultat = DodajHorizontalnu(0, 1, original, rezultat);
    rezultat = DodajHorizontalnu(2, 1, original, rezultat);
    rezultat = DodajVertikalnu(1, 0, original, rezultat);
    rezultat = DodajVertikalnu(1, 2, original, rezultat);
    rezultat = DodajKosu(0, 0, original, rezultat);
    rezultat = DodajKosu(0, 2, original, rezultat);
    rezultat = DodajKosu(2, 0, original, rezultat);
    rezultat = DodajKosu(2, 2, original, rezultat);
    rezultat = DodajOriginalnu(1, 1, original, rezultat);

    return rezultat;
}

int main()
{
    int redovi, kolone;

    std::cout << "Unesite dimenzije matrice (m n): ";
    std::cin >> redovi >> kolone;

    if (redovi < 0 || kolone < 0) {
        std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
    } else {
        std::cout << "Unesite elemente matrice:" << std::endl;

        Matrica original = Matrica(redovi, std::vector<double> (kolone));

        for (int i = 0; i < redovi; i++) {
            for (int j = 0; j < kolone; j++) {
                std::cin >> original[i][j];
            }
        }

        Matrica rezultat = OgledaloMatrica(original);

        std::cout << "Rezultantna matrica: " << std::endl;

        for (int i = 0; i < rezultat.size(); i++) {
            for (int j = 0; j < rezultat[i].size(); j++) {
                std::cout << std::setw(4) << rezultat[i][j];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
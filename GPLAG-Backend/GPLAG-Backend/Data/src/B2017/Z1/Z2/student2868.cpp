#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>

bool GrbavaMatrica(std::vector<std::vector<double>> matrica)
{
    for (int i = 0; i < matrica.size()-1; i++) {
        if (matrica.at(i).size()!=matrica.at(i+1).size())
            return true;
    }
    return false;
}

int Pozicija(int N)
{
    int xy(0);
    if (N%2==0)
        return xy=(N/2)-1;
    return xy=N/2;
}

int Provjera(std::vector<std::vector<double>> matrica, int y, int x, int k, long double vrh)
{
    long double suma(0);
    long double suma_prethodna(0);
    int s(1);

    for (; s <=k; s++) {
        for (int i = y-s; i <= y+s; i++) {
            for (int j = x-s; j <= x+s; j++) {
                if (i!=y-s && i!=y+s && j!=x-s && j!=x+s)
                    continue;
                suma+=matrica.at(i).at(j);
            }
        }
        if (s==1) {
            if (vrh<=suma)
                return s-1;
            suma_prethodna=suma;
        } else {
            if (suma_prethodna<=suma)
                return s-1;
            suma_prethodna=suma;
        }
        suma=0;
    }
    return s-1;
}

double PronadjiNajveciBroj(std::vector<std::vector<double>> mat)
{
    double maks=mat.at(0).at(0);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.at(0).size(); j++) {
            if (mat.at(i).at(j)>maks)
                maks=mat.at(i).at(j);
        }
    }
    return maks;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica)
{
    //0 0 0 15 12 6 1 25 1 5 2 9 1 1 20 15 10 5 3 2 19 130 14 8 90 6 20 12 17 2 12 3 5 1 8 4 (6x6) RADI
    //2 1 9 1 2 9 1 1 9 9 90 9 9 9 9 9 90 9 (6x3) RADI
    //2 1 1 9 9 9 1 2 1 90 9 90 9 9 9 9 9 9 (3x6) RADI
    //0 0 0 0 0 0 0 0 -1 (3x3) RADI
    // 1 1 1 1 1 1 -1 -20 -2 1 1 -1 100 -3 1 1 -2 -5 -4 1 1 1 1 1 1 (5x5) RADI
    std::vector<std::vector<double>> rez;
    if (matrica.size()==0 || matrica.at(0).size()==0)
        return rez;
    if (GrbavaMatrica(matrica))
        throw std::domain_error("Matrica nije korektna");

    int visina(matrica.size()), sirina(matrica.at(0).size());
    int manja(visina);
    if (sirina<visina)
        manja=sirina;

    int poc(Pozicija(manja));
    int maks(0);
    int x(0),y(0);
    for (int k = 0; k < poc; k++) {
        for (int i = poc-k; i < visina-poc+k; i++) {
            for (int j = poc-k; j < sirina-poc+k; j++) {
                if (i!=poc-k && i!=visina-poc+k-1 && j!=poc-k && j!=sirina-poc+k-1)
                    continue;
                int kontrola=Provjera(matrica,i,j,poc-k,matrica.at(i).at(j));
                if (kontrola>maks) {
                    maks=kontrola;
                    x=j;
                    y=i;
                } else if (maks!=0 && kontrola==maks) {
                    if (matrica.at(i).at(j)>matrica.at(x).at(y)) {
                        x=j;
                        y=i;
                    } else if (abs(matrica.at(i).at(j)-matrica.at(x).at(y))<0.00000001) {
                        if (i<x) {
                            x=j;
                            y=i;
                        } else if (i==x && j<y) {
                            x=j;
                            y=i;
                        }
                    }
                }
            }
        }
    }

    if (maks==0) {
        rez.resize(1);
        rez.at(0).push_back(PronadjiNajveciBroj(matrica));
        return rez;
    }

    rez.resize((maks*2)+1);
    for (int i = 0; i < rez.size(); i++) {
        rez.at(i).resize(rez.size());
        for (int j = 0; j < rez.size(); j++) {
            rez.at(i).at(j)=matrica.at(y-maks+i).at(x-maks+j);
        }
    }

    return rez;
}

int main ()
{
    int m, n;
    std::cout << "Unesite dimenzije matrice (m i n): ";
    do {
        std::cin >> m >> n;
        if (!std::cin || m<=0 || n<=0) {
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Pogresne dimenzije matrice!";
                return 1;
            } else {
                std::cout << "Dimenzije matrice moraju biti nenegativne!";
                return 1;
            }
        } else
            break;
    } while(1);

    std::vector<std::vector<double>> matrica(m, std::vector<double>(n));

    std::cout << "Unesite elemente matrice: ";
    for (int i = 0; i < matrica.size(); i++) {
        for (int j = 0; j < matrica.at(i).size(); j++) {
            std::cin >> matrica.at(i).at(j);
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Neispravan unos! Unesite ponovo: ";
                j--;
            }
        }
    }

    try {
        std::vector<std::vector<double>> planina=NajvecaPlaninaMatrice(matrica);

        std::cout << "\nNajveca planina unesene matrice je:" << std::endl;
        for (auto i : planina) {
            for (auto j : i) {
                std::cout << std::setw(6) << std::right << j;
            }
            std::cout << std::endl;
        }
    } catch (std::domain_error error) {
        std::cout << error.what();
    }

    return 0;
}

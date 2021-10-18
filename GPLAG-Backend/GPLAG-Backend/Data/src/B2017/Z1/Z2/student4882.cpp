#include <stdexcept>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

typedef std::vector<std::vector<double>> MATRICA; // zbog preglednosti

// pomocna funkcija za kreiranje matrice
MATRICA KreirajMatricu (int m, int n) {
    return MATRICA (m, std::vector<double>(n));
}

// pomocna funkcija za unos matrice
MATRICA UnesiMatricu (int m, int n) {
    MATRICA unesi(KreirajMatricu(m, n));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            std::cin >> unesi.at(i).at(j);
            if (j==n-1) break;
        }
        if (i==m-1) break;
    }
    return unesi;
}

// pomocna funkcija koja na osnovu primljenih koordinata vrha 
// i dimenzije podmatrice izdvaja najvecu planinu
MATRICA IzreziMatricu (MATRICA mat, int a, int b, int k) {
    MATRICA cut=KreirajMatricu(k*2+1, k*2+1);
    int m(0), n(0);
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat.at(i).size(); j++) {
            if (i>=a-k and i<=a+k and j>=b-k and j<=b+k) {
                cut.at(m).at(n)=mat.at(i).at(j);
                n++;
                if (n==2*k+1) {
                    n=0;
                    m++;
                    if(m==2*k+1) {
                        break;
                    }
                }
            }
            if (j==mat.at(i).size()-1) break;
        }
        if (i==mat.size()-1) break;
    }
    return cut;
}

MATRICA NajvecaPlaninaMatrice (MATRICA mat) {
    MATRICA planina;
    double const Eps=pow(10, -10);
    if (mat.size()==0 or mat.at(0).size()==0) return KreirajMatricu(0, 0);
    int znak(1);
    int referent=mat.at(0).size();
    for (int i=0; i<mat.size(); i++) {
        if ((mat.at(i).size())!=referent) {
            znak=0;
        }
        if (i==mat.size()-1) break;
    }
    if (znak==0) {
        throw std::domain_error("Matrica nije korektna");
    }
    int cuvar(0);
    double najveci=mat.at(0).at(0);
    int iii, jjj;
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat.at(i).size(); j++) {
            if (i!=0 and j!=0 and i!=(mat.size()-1) and j!=(mat.at(i).size())-1) { // ako nije rub
                double temp(mat.at(i).at(j)), broj(temp);
                int ii(i), jj(j);
                for (int k=1; k<(mat.size()); k++) {
                    if (i-k>=0 and j-k>=0 and i+k<mat.size() and j+k<mat.at(i).size()) { // mora postojati element matrice
                        double suma(0);
                        //ispitujemo k-okolinu elementa
                        for (int a=i-k; a<=i+k; a++) {
                            for (int b=j-k; b<=j+k; b++) {
                                if (a==i+k or a==i-k or b==j+k or b==j-k) {
                                    suma+=mat.at(a).at(b);
                                }
                                if (b==j+k) break;
                            }
                            if (a==i+k) break;
                        }
                        if ((temp-suma)>Eps*(std::fabs(suma)+std::fabs(temp))) { // ako je vrh brda
                            temp=suma;
                            suma=0;
                            int sirina=k;
                            if (sirina>cuvar) { // ako je najveca sirina
                                najveci=broj;
                                cuvar=sirina;
                                jjj=jj;
                                iii=ii;
                            }
                            else if (sirina==cuvar) { // ako je ista, gledamo velicinu vrha
                                if ((broj-najveci)>Eps*(std::fabs(broj)+std::fabs(najveci))) {
                                    najveci=broj;
                                    cuvar=sirina;
                                    jjj=jj;
                                    iii=ii;
                                }
                            }
                            else continue;
                        }
                        else {
                            break;
                        }
                    }
                    if (k==mat.size()-1) break;
                }
            }
            if (j==mat.at(i).size()-1) break;
        }
        if (i==mat.size()-1) break;
    }
    // slucaj kad se trazi najveci element matrice
    if (cuvar==0) {
        najveci=mat.at(0).at(0);
        iii=0;
        jjj=0;
        for (int i=0; i<mat.size(); i++) {
            for (int j=0; j<mat.at(i).size(); j++) {
                if ((mat.at(i).at(j)-najveci)>Eps*(std::fabs(mat.at(i).at(j))+std::fabs(najveci))) {
                    najveci=mat.at(i).at(j);
                    iii=i;
                    jjj=j;
                }
                if (j==mat.at(i).size()-1) break;
            }
            if (i==mat.size()-1) break;
        }
    }
    return IzreziMatricu(mat, iii, jjj, cuvar);
}

int main ()
{
    try {
        int m, n;
        std::cout << "Unesite dimenzije matrice (m i n): ";
        std::cin >> m >> n;
        if (!(m>=0 and n>=0)) {
            std::cout << "Dimenzije matrice moraju biti nenegativne!";
            return 0;
        }
        std::cout << "Unesite elemente matrice: ";
        MATRICA mat=UnesiMatricu(m, n);
        MATRICA planina=NajvecaPlaninaMatrice(mat);
        std::cout << "\nNajveca planina unesene matrice je: \n";
        for (int i=0; i<planina.size(); i++) {
            for (int j=0; j<planina.at(i).size(); j++) {
                std::cout << std::setw(6) << planina.at(i).at(j);
                if (j==planina.at(i).size()-1) break;
            }
            std::cout << "\n";
            if (i==planina.size()-1) break;
        }
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what();
        std::cout << "\n";
    }
	return 0;
}
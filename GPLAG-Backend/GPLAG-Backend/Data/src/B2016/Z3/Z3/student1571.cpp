#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <new>

template <typename Tip>
struct Matrica {
    int br_redova, br_kolona;
    Tip **elementi = nullptr;
};
template <typename Tip>
void UnistiMatricu (Matrica<Tip> mat) {
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename Tip>
Matrica<Tip> StvoriMatricu (int br_redova, int br_kolona) {
    Matrica<Tip> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new Tip*[br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i] =  nullptr;
    try {
        for (int i=0; i<br_redova; i++) 
            mat.elementi[i] = new Tip [br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename Tip>
void UnesiMatricu (char ime, Matrica<Tip> &mat) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout << ime << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}
template <typename Tip>
void IspisiMatricu (const Matrica<Tip> &mat, int sirina, int preciznost = 6, bool treba_brisati = false) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) 
            std::cout << std::setw(sirina) << std::setprecision (preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}
template <typename Tip>
void nul_matrica (Matrica<Tip> &mat) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++)
            mat.elementi[i][j] = 0;
    }
}
template <typename Tip>
void jedinicna_matrica (Matrica<Tip> &mat) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            if (i == j) mat.elementi[i][j] = 1;
            else mat.elementi[i][j] = 0;
        }
    }
}
template <typename Tip>
Matrica<Tip> ZbirMatrica (const Matrica<Tip> &mat1, const Matrica<Tip> &mat2) {
    if (mat1.br_redova != mat2.br_redova || mat1.br_kolona != mat2.br_kolona) 
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto mat3 = StvoriMatricu<Tip>(mat1.br_redova, mat1.br_kolona);
    for (int i=0; i<mat1.br_redova; i++) {
        for (int j=0; j<mat1.br_kolona; j++)
            mat3.elementi[i][j] = mat1.elementi[i][j] + mat2.elementi[i][j];
    }
    return mat3;
}
template <typename Tip>
void pomnozi_skalarom (const Matrica<Tip> &mat, double skalar) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) 
            mat.elementi[i][j] *= skalar;
    }
}
template <typename Tip>
Matrica<Tip> ProduktMatrica (const Matrica<Tip> &mat1, const Matrica<Tip> &mat2) {
    if (mat1.br_kolona != mat2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto produkt_matrica = StvoriMatricu<Tip>(mat1.br_redova, mat2.br_kolona);
    for (int i=0; i<mat1.br_redova; i++) 
        for (int j=0; j<mat2.br_kolona; j++) {
            Tip suma (0);
            for (int k=0; k<mat2.br_redova; k++) 
                    suma += mat1.elementi[i][k] * mat2.elementi[k][j];
            produkt_matrica.elementi[i][j] = suma;
        }
    return produkt_matrica;
}
template <typename Tip>
Matrica<Tip> MatricniPolinom (const Matrica<Tip> &mat, std::vector<double> vek) {
    if (mat.br_redova != mat.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
    Matrica<Tip> jedinicna, nul, kopija_poslane;
    try {
        if (vek.size() == 0) {
            auto c = StvoriMatricu<Tip>(mat.br_redova, mat.br_kolona);
            nul_matrica(c);
            return c;
        }
        jedinicna = StvoriMatricu<Tip>(mat.br_redova, mat.br_kolona); //Kreiram jedinicnu i mnozim sa 1.elementom u vektoru
        jedinicna_matrica(jedinicna);
        pomnozi_skalarom(jedinicna, vek[0]);
        if (vek.size() == 1) return jedinicna;
        kopija_poslane = StvoriMatricu<Tip>(mat.br_redova, mat.br_kolona); //kopija poslane pomnozena skalarom
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                kopija_poslane.elementi[i][j] = mat.elementi[i][j];
            }
        }
        if (vek.size() > 0) { 
            pomnozi_skalarom(kopija_poslane, vek[1]);
            nul = ZbirMatrica(jedinicna, kopija_poslane);
            for (int i=0; i<mat.br_redova; i++) {
                for (int j=0; j<mat.br_kolona; j++)
                    kopija_poslane.elementi[i][j] = nul.elementi[i][j];
            }
            UnistiMatricu(nul);
        }
        jedinicna_matrica(jedinicna); //vracam na jedinicnu
        for (int i=2; i<vek.size(); i++) {
            jedinicna_matrica(jedinicna);

            for (int j=0; j<i; j++) {
                nul = ProduktMatrica(mat, jedinicna);
                for (int k=0; k<mat.br_redova; k++) {
                    for (int e=0; e<mat.br_kolona; e++)
                        jedinicna.elementi[k][e] = nul.elementi[k][e];
                }
                UnistiMatricu(nul);
            }
            pomnozi_skalarom(jedinicna, vek[i]);
            nul = ZbirMatrica(kopija_poslane, jedinicna);
            for (int k=0; k<mat.br_redova; k++) {
                for (int e=0; e<mat.br_kolona; e++) 
                    kopija_poslane.elementi[k][e] = nul.elementi[k][e];
            }
            UnistiMatricu(nul);
        }
    }
    catch(...) {
        UnistiMatricu(jedinicna);
        UnistiMatricu(nul);
        UnistiMatricu(kopija_poslane);
        throw;
    }
    UnistiMatricu(jedinicna);
    return kopija_poslane;
}

int main ()
{
    Matrica<double> a, b;
    int dim;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dim;
    std::vector<double> v;
    try {
        a = StvoriMatricu<double>(dim, dim);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        v.resize(red + 1);
        std::cout << "Unesite koeficijente polinoma: ";
        for (int i=0; i<=red; i++) 
            std::cin >> v[i];
        IspisiMatricu(MatricniPolinom<double> (a, v), 10, 6, true);
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!";
    }
    UnistiMatricu(a); UnistiMatricu(b);
	return 0;
}
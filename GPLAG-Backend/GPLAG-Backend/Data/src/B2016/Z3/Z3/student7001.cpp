/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElementa>
struct Matrica {
    int br_redova, br_kolona;
    TipElementa **elementi=nullptr;
};

template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat) {
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElementa> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new TipElementa*[br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for (int i=0; i<br_redova; i++) 
            mat.elementi[i]=new TipElementa[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElementa>
void UnesiMatricu(char ime_matrice, Matrica<TipElementa> &mat) {
    for (int i=0; i<mat.br_redova; i++)
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}

template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &mat1, const Matrica<TipElementa> &mat2) {
    auto mat3(StvoriMatricu<TipElementa>(mat1.br_redova,mat2.br_kolona));
    for (int i=0; i<mat1.br_redova; i++) {
        for (int j=0; j<mat2.br_kolona; j++) {
            TipElementa suma(0);
            for (int k=0; k<mat2.br_redova; k++)
                suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
            mat3.elementi[i][j]=suma;
        }
    }
    return mat3;
}

template <typename TipElementa>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &mat1, const std::vector<double> &v) {
    if (mat1.br_redova!=mat1.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto matricni_polinom(StvoriMatricu<TipElementa>(mat1.br_redova,mat1.br_kolona));
    for (int i=0; i<mat1.br_redova; i++)
        for (int j=0; j<mat1.br_kolona; j++)
            matricni_polinom.elementi[i][j]=0;
    if (!v.size()) return matricni_polinom;
    auto tmp(mat1); 
    for (int i=0; i<v.size(); i++) {
        if (i==0) {
            for (int k=0; k<mat1.br_redova; k++)
                for (int j=0; j<mat1.br_kolona; j++)
                    if (k==j) matricni_polinom.elementi[k][j]=v[i];
        }
        else if (i==1) {
            for (int k=0; k<mat1.br_redova; k++)
                for (int j=0; j<mat1.br_kolona; j++)
                    matricni_polinom.elementi[k][j]+=mat1.elementi[k][j]*v[i];
        }
        else {
            if (i>2) {
                auto tmp1(tmp);
                tmp=ProduktMatrica(mat1,tmp);
                UnistiMatricu(tmp1);
            }
            else tmp=ProduktMatrica(mat1,tmp);
            for (int k=0; k<mat1.br_redova; k++)
                for (int j=0; j<mat1.br_kolona; j++)
                    matricni_polinom.elementi[k][j]+=tmp.elementi[k][j]*v[i];
        }
    }
    if (v.size()>2) UnistiMatricu(tmp);
    return matricni_polinom;
}

int main () {
    Matrica<double> a,b;
    int dimenzija;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija;
    try {
        a=StvoriMatricu<double>(dimenzija,dimenzija);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A',a);
        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;
        std::vector<double> v(red+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for (int i=0; i<v.size(); i++) std::cin >> v[i];
        IspisiMatricu(b=MatricniPolinom(a,v),10,6,true);
    }
    catch(std::domain_error izuzetak) {
        UnistiMatricu(a);
        std::cout << izuzetak.what();
    }
    catch(std::bad_alloc) {
        return 0;
    }
    UnistiMatricu(a);
	return 0;
}
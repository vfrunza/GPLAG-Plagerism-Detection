/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using std::vector;

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi=nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu (Matrica<TipElemenata> mat) {
        if (!mat.elementi) return;
        for (int i=0; i<mat.br_redova; i++)
            delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        try {
        mat.elementi=new TipElemenata*[br_redova];
        for (int i=0; i<br_redova; i++)
            mat.elementi[i]=nullptr;
        try {
            for (int i=0; i<br_redova; i++)
                mat.elementi[i]=new TipElemenata[br_redova];
        }
        catch (...) {
            UnistiMatricu(mat);
            throw;
        }
        }
        catch (...) {
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
    }
    
template <typename TipElemenata>
    void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            }
            std::cout << std::endl;
        }
        if (treba_brisati)
            UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for (int i=0; i<m1.br_redova; i++)
            for (int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        return m3;    
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for (int i=0; i<m1.br_redova; i++) {
            for (int j=0; j<m2.br_kolona; j++) {
                m3.elementi[i][j]=0;
                for (int k=0; k<m1.br_kolona; k++) {
                    m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &mat, vector<double> koef) {
        if (mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
        auto rez(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        for (int i=0; i<rez.br_redova; i++)
            for (int j=0; j<rez.br_kolona; j++)
                rez.elementi[i][j]=0;
        if (koef.size()==0) return rez;
        auto pomocna(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        auto pom_rez(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        auto pom_pomocna(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        for (int i=0; i<koef.size(); i++) {
            for (int j=0; j<pomocna.br_redova; j++) {
                for (int k=0; k<pomocna.br_kolona; k++) {
                    if (j==k)
                        pomocna.elementi[j][k]=1;
                    else
                        pomocna.elementi[j][k]=0;
                }
            }
            for (int j=0; j<i; j++) {
                pom_pomocna=pomocna;
                pomocna=ProduktMatrica(pomocna, mat);
                UnistiMatricu(pom_pomocna);
            }
            for (int j=0; j<pomocna.br_redova; j++)
                for (int k=0; k<pomocna.br_kolona; k++)
                    pomocna.elementi[j][k]*=koef[i];
            pom_rez=rez;
            rez=ZbirMatrica(rez, pomocna);
            UnistiMatricu(pom_rez);
        }
        UnistiMatricu(pomocna);
        return rez;
    }

int main ()
{
    Matrica<double> a, c;
    int m, n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    n=m;
    try {
        a=StvoriMatricu<double>(m,n);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        int red_polinoma;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red_polinoma;
        vector<double> koef_polinoma(red_polinoma+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for (int i=0; i<koef_polinoma.size(); i++)
            std::cin >> koef_polinoma[i];
        IspisiMatricu(c=MatricniPolinom(a, koef_polinoma),10);
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    //UnistiMatricu(b);
    UnistiMatricu(c);
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

template <typename TipElemenata>
 struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
 };
 
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
 }

template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona]{};
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
 }
 
template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
 }

template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
 }
 
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m1.br_kolona; j++) {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
 }
 
template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m3.br_redova; i++) {
        for(int j=0; j<m3.br_kolona; j++) {
            for(int k=0; k<m1.br_kolona; k++) {
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
 }

template <typename TipElemenata>
 void PomnoziMatricuSkalarom(Matrica<TipElemenata> &m, double x) {
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++) {
            m[i][j]*=x;
        }
    }
 }
/*
template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> p) {
    if(A.br_kolona!=A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto I(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    auto M(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    for(int k=0; k<p.size(); k++) {
        if(k==0) {
            for(int i=0; i<A.br_redova; i++) {
                for(int j=0; j<A.br_redova; j++) {
                    if(i==j) I[i][j]==1;
                }
            }
            PomnoziMatricuSkalarom(I, p[0]);
            M=ZbirMatrica(M, I);
        }
        else if(k==1) {
            PomnoziMatricuSkalarom(A, p[1]);
            M=ZbirMatrica(M, A);
        }
        else {
            for(int j=1; j<k; j++) {
                ProduktMatrica(A, A)
            }
        }
    }
 }
*/

int main ()
{
    Matrica<double> a, b, c;
    int m, n;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    try {
        a=StvoriMatricu<double>(m, n);
        b=StvoriMatricu<double>(m, n);
        std::cout << "Unesi matricu A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesi matricu B:\n";
        UnesiMatricu('B', b);
        std::cout << "Zbir ove dvije matrice je:\n";
        IspisiMatricu(c=ZbirMatrica(a, b), 7);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
	return 0;
}
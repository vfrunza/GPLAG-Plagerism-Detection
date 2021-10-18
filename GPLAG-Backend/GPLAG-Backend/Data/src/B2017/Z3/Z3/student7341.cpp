/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat)
{
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for (int i=0; i<br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat)
{
    for (int i=0; i<mat.br_redova;  i++)
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout.precision(preciznost);
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout  << std::endl;
    }

    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    Matrica<TipElemenata> m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    for (int i=0; i<m1.br_redova; i++)
        for (int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_kolona != m2.br_redova) std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3 =StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for (int i=0; i<m3.br_redova; i++) {
        for (int j=0; j<m3.br_kolona; j++) {
            TipElemenata suma(0);
            for (int k=0; k<m2.br_redova; k++)
                suma += m1.elementi[i][k] * m2.elementi[k][j];

            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template <typename TipElemenata, typename TipElemenata2>
Matrica<TipElemenata> SkalarniProdukt ( const Matrica<TipElemenata> &mat, TipElemenata2 p)
{
    Matrica<TipElemenata> konacna = StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            konacna.elementi[i][j]=(*p) * mat.elementi[i][j];
        }
    }
    return konacna;
}

template <typename TipElemenata, typename TipElemenata1>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &A, int n, TipElemenata1 polinom)
{
    Matrica<TipElemenata> P ;
    Matrica<TipElemenata> jedinicna;
    try {
        if (n<0) {
            throw std::domain_error ("Neispravan stepen polinoma");
        }
        if (A.br_kolona!=A.br_redova) {
            throw std::domain_error ("“Matrica mora biti kvadratna");
        }
      
        jedinicna = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        for (int i=0; i<A.br_redova; i++) {
            for (int j=0; j<A.br_kolona; j++) {
                if(i==j) jedinicna.elementi[i][j]=1;
                else jedinicna.elementi[i][j]=0;
            }
        }

        if (n==0) {
            Matrica<TipElemenata> pomocna = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
            pomocna=SkalarniProdukt(jedinicna,polinom);
            UnistiMatricu(P);
            UnistiMatricu(A);
            UnistiMatricu(jedinicna);
            return pomocna;
        }

        else {
            for (int i(0); i<=n; i++) {
                if (i==0) {
                    P=SkalarniProdukt(jedinicna, polinom);
                    polinom++;
                } else if (i==1) {
                    Matrica<TipElemenata> a;
                    a=SkalarniProdukt(A, polinom);
                    Matrica<TipElemenata> b;
                    b=ZbirMatrica(P,a);
                    for (int i(0); i<A.br_redova; i++) {
                        for (int j(0); j<A.br_kolona; j++) {
                            P.elementi[i][j]=b.elementi[i][j];
                        }
                    }
                    UnistiMatricu(a);
                    UnistiMatricu(b);
                    polinom++;
                } else {
                    Matrica<TipElemenata> b;
                    b=ProduktMatrica(A,A);
                    Matrica<TipElemenata> a;
                    for (int j=0; j<i-2; j++) {
                        Matrica<TipElemenata> d;
                        d=ProduktMatrica(b,A);
                        for (int i(0); i<A.br_redova; i++)
                            for (int j(0); j<A.br_kolona; j++)
                                b.elementi[i][j]=d.elementi[i][j];
                        UnistiMatricu(d);
                    }

                    a=SkalarniProdukt(b, polinom);
                    polinom++;
                    Matrica<TipElemenata> c;
                    c=ZbirMatrica(P, a);
                    for (int i(0); i<A.br_redova; i++)
                        for (int j(0); j<A.br_kolona; j++)
                            P.elementi[i][j]=c.elementi[i][j];
                    UnistiMatricu(b);
                    UnistiMatricu(a);
                    UnistiMatricu(c);
                }
            }
        }
    } catch (std::domain_error greska) {
        UnistiMatricu(A);
        UnistiMatricu(P);
        UnistiMatricu(jedinicna);
        throw std::domain_error(greska);
    }
    UnistiMatricu(jedinicna);
    return P;
}

int main ()
{
    Matrica<double> a, b;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a=StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red_polinoma;
        std::cin >> red_polinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> polinom;
        for(int i=0; i<=red_polinoma; i++) {
            double broj;
            std::cin >> broj;
            polinom.push_back(broj);
        }
        IspisiMatricu(b=MatricniPolinom(a,red_polinoma,polinom.begin()), 10);
    } catch (std::domain_error greska) {
        std::cout << greska.what() << std::endl;
    } catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    return 0;


}

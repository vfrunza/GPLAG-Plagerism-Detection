/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <list>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; 
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            m3.elementi[i][j] = 0;
        }
    }
    
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            for(int k=0; k < m1.br_kolona; k++) {
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int n, IterTip p)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_kolona != A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto P(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    for(int i=0; i<A.br_redova; i++) {
        for(int j=0; j<A.br_redova; j++) {
            if(i==j) P.elementi[i][j] = *p;
            else P.elementi[i][j] = 0;
        }
    }
    p++;
    
    try {
        auto temp(ProduktMatrica(A, A));
        for(int k=1; k<=n; k++) {
            if(k==1) {
                for(int i=0; i<A.br_redova; i++) {
                    for(int j=0; j<A.br_redova; j++) {
                        P.elementi[i][j] += A.elementi[i][j] * (*p);
                    }
                } 
            } else if(k==2) {
                for(int i=0; i<A.br_redova; i++) {
                    for(int j=0; j<A.br_redova; j++) {
                        P.elementi[i][j] += temp.elementi[i][j] * (*p);
                    }
                }
            } else {
                try {
                    auto m(ProduktMatrica(temp, A));
                    for(int i=0; i<A.br_redova; i++) {
                        for(int j=0; j<A.br_redova; j++) {
                            P.elementi[i][j] += m.elementi[i][j] * (*p);
                        }
                    }
                    auto nova(temp);
                    temp = m;
                    UnistiMatricu(nova);
                } catch(...) {
                    UnistiMatricu(temp);
                    throw;
                }
            }

            p++;
        }
        UnistiMatricu(temp); 
    } catch(...) {
        UnistiMatricu(P);
        throw;
    }

    return P;
}


int main()
{
    Matrica<double> a, c; 
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::list<double> lista;
        for(int i=0; i<=n; i++) {
            double x(0);
            std::cin>>x;
            lista.push_back(x);
        }
        IspisiMatricu(c = MatricniPolinom(a, n, lista.begin()), 10, 6);

    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    } catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(c);
    return 0;
}

/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
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
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica <TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m4(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            TipElemenata suma(0);
            for(int k=0; k<m1.br_kolona; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m4.elementi[i][j]=suma;
        }
    }
    return m4;
}
template<typename TipElemenata>
Matrica<TipElemenata> Stepen(const Matrica<TipElemenata>&m, int n)
{
    auto m8(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    Matrica<TipElemenata>pro;
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++) {
            if(i==j) m8.elementi[i][j]=1;
            else m8.elementi[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++) {
        pro=ProduktMatrica(m8, m);
        for(int i=0; i<pro.br_redova; i++) {
            for(int j=0; j<pro.br_kolona; j++) {

                m8.elementi[i][j]=pro.elementi[i][j];

            }
        }
        UnistiMatricu(pro);
    }
    return m8;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &m, std::vector<double> v)
{
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto m5(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    auto m6(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    auto m7(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    auto m9(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<m5.br_redova; i++) {
        for(int j=0; j<m5.br_kolona; j++) {
            if(i==j) m5.elementi[i][j]=1;
            else m5.elementi[i][j]=0;
        }
    }
    for(int i=0; i<m6.br_redova; i++) {
        for(int j=0; j<m6.br_kolona; j++) {
            m6.elementi[i][j]=0;
        }
    }
    for(int i=0; i<m7.br_redova; i++) {
        for(int j=0; j<m7.br_kolona; j++) {
            m7.elementi[i][j]=m.elementi[i][j];
        }
    }
    Matrica<TipElemenata> pomocna;
    for(int i=0; i<v.size(); i++) {
        if(i==0) {
            for(int j=0; j<m.br_redova; j++) {
                for(int k=0; k<m.br_kolona; k++) {
                    m5.elementi[j][k]*=v[i];
                }
            }
            pomocna=ZbirMatrica(m6, m5);
            for(int i=0; i<pomocna.br_redova; i++) {
                for(int j=0; j<pomocna.br_kolona; j++) {

                    m6.elementi[i][j]=pomocna.elementi[i][j];

                }
            }
            UnistiMatricu(pomocna);
        } else if(i==1) {
            Matrica<TipElemenata> pomocna2;

            for(int j=0; j<m.br_redova; j++) {
                for(int k=0; k<m.br_kolona; k++) {
                    m7.elementi[j][k]*=v[i];
                }
            }
            pomocna2=ZbirMatrica(m6, m7);
            for(int i=0; i<pomocna2.br_redova; i++) {
                for(int j=0; j<pomocna2.br_kolona; j++) {

                    m6.elementi[i][j]=pomocna2.elementi[i][j];

                }
            }
            UnistiMatricu(pomocna2);
        } else {
            Matrica<TipElemenata>pomocna4;
            pomocna4=Stepen(m, i);
            for(int i=0; i<pomocna4.br_redova; i++) {
                for(int j=0; j<pomocna4.br_kolona; j++) {

                    m9.elementi[i][j]=pomocna4.elementi[i][j];

                }
            }
            UnistiMatricu(pomocna4);

            Matrica<TipElemenata>pomocna3;
            for(int j=0; j<m9.br_redova; j++) {
                for(int k=0; k<m9.br_kolona; k++) {
                    m9.elementi[j][k]*=v[i];
                }
            }
            pomocna3=ZbirMatrica(m6, m9);
            for(int i=0; i<pomocna3.br_redova; i++) {
                for(int j=0; j<pomocna3.br_kolona; j++) {

                    m6.elementi[i][j]=pomocna3.elementi[i][j];

                }
            }
            UnistiMatricu(pomocna3);

        }

    }
    UnistiMatricu(m9);
    UnistiMatricu(m5);
    UnistiMatricu(m7);
    return m6;
}

int main()
{
    Matrica<double> a, e;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;

    a = StvoriMatricu<double>(m, m);
    std::cout << "Unesite elemente matrice A: "<<std::endl;
    UnesiMatricu('A', a);
    std::cout<<"Unesite red polinoma: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite koeficijente polinoma: ";
    double broj;
    std::vector<double>v;
    for(int i=0; i<=n; i++) {
        std::cin>>broj;
        v.push_back(broj);
    }
    IspisiMatricu(e=MatricniPolinom(a, v),10);
    UnistiMatricu(a);
    UnistiMatricu(e);
    return 0;
}
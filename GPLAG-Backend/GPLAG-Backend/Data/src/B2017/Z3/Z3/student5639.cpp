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
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati == true) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3;
    m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
            m3.elementi[i][j]= {};
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            TipElemenata suma(0);
            for(int k = 0; k < m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> Jedinicna(int broj_redova)
{
    Matrica<TipElemenata>mat;
    mat = StvoriMatricu<TipElemenata>(broj_redova, broj_redova);
    for(int i=0; i<broj_redova; i++) {
        for(int j=0; j<broj_redova; j++) {
            if(i == j) mat.elementi[i][j]=1;
            else mat.elementi[i][j]=0;
        }
    }
    return mat;
}

template <typename TipElemenata>
Matrica<TipElemenata> MnozenjeSkalarom(Matrica<TipElemenata> &m, double broj)
{
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++) {
            m.elementi[i][j]*=broj;
        }
    }
    return m;
}

template<typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> m, int n, IterTip p)
{
    if(n < 0) throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_redova != m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> nulti_stepen, m1, m2, m3, m4, vrati;
    try {
        m1 = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        m2 = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        m3 = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        vrati = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        // nulti_stepen = Jedinicna<TipElemenata>(m.br_kolona);
        for(int i = 0; i < m.br_redova; i++)
            for(int j = 0; j < m.br_kolona; j++)
                m1.elementi[i][j] = m.elementi[i][j];

        for(int i = 0; i <= n ; i++) {
            if (i == 0) {
                /*      for(int i = 0; i < m.br_redova; i++) {
                          for(int j = 0; j < m.br_kolona; j++) {
                              m2.elementi[i][j] = nulti_stepen.elementi[i][j];
                          }
                      }
                      m2 = MnozenjeSkalarom(m2, *p);
                      vrati = ZbirMatrica(vrati, m2);*/
                for(int i=0; i<m.br_redova; i++) {
                    for(int j=0; j<m.br_kolona; j++) {
                        if(i == j) m2.elementi[i][j]=1;
                        else m2.elementi[i][j]=0;
                    }
                }

                m2 = MnozenjeSkalarom(m2, *p);
                vrati = ZbirMatrica(vrati, m2);
            } else if(i == 1) {
                for(int i = 0; i < m.br_redova; i++) {
                    for(int j = 0; j < m.br_kolona; j++) {
                        m2.elementi[i][j] = m.elementi[i][j];
                    }
                }
                m2 = MnozenjeSkalarom(m2, *(p+1));
                vrati = ZbirMatrica(vrati, m2);
            } else {
                m4 = ProduktMatrica(m1, m);
                for(int i = 0; i < m.br_redova; i++) {
                    for(int j = 0; j < m.br_kolona; j++) {
                        //  m1.elementi[i][j] = m.elementi[i][j];
                        m3.elementi[i][j] = m1.elementi[i][j];
                    }
                }
                UnistiMatricu(m1);
                m1 = ProduktMatrica(m3, m);
                m4 = MnozenjeSkalarom(m4, *(p+i));
                vrati = ZbirMatrica (vrati, m4);
                UnistiMatricu(m4);
            }
        }
        return vrati;
        /*   UnistiMatricu(m1);
           UnistiMatricu(m2);
           UnistiMatricu(m3); */
    } catch (...) {
        UnistiMatricu(m1);
        UnistiMatricu(m2);
        UnistiMatricu(m3);
        UnistiMatricu(vrati);
        throw;
    }
}


int main()
{
    Matrica<double> a;
    int dimenzija, red_polinoma;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija;
    try {
        a = StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> red_polinoma;
        std::vector<double> koeficijenti;
        double koef;
        std::cout << "Unesite koeficijente polinoma: ";
        int i(0);
        while (i++ <= red_polinoma) {
            std::cin >> koef;
            koeficijenti.push_back(koef);
        }
        IspisiMatricu(MatricniPolinom(a, red_polinoma, koeficijenti.begin()), 10);
        UnistiMatricu(a);
    } catch(...) {
        UnistiMatricu(a);
        throw;
    }
    return 0;
}

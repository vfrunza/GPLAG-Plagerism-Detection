/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

template <typename TipElementa>
struct Matrica {
    int br_redova, br_kolona;
    TipElementa **elementi = nullptr;
};

template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElementa> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    try {
        mat.elementi = new TipElementa*[br_redova];
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElementa[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElementa>
void UnesiMatricu(char ime_matrice, Matrica<TipElementa> &mat)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElementa>
void IspisiMatricu (const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost = 7, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        cout << endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElementa>
Matrica<TipElementa> ZbirElemenata (const Matrica<TipElementa> &mat1, const Matrica<TipElementa> &mat2)
{
    if(mat1.br_redova != mat2.br_redova || mat1.br_kolona != mat2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto mat3(StvoriMatricu<TipElementa>(mat1.br_redova, mat1.br_kolona));
    for(int i = 0; i < mat1.br_redova; i++) {
        for(int j = 0; j < mat1.br_kolona; j++)
            mat3.elementi[i][j] = mat1.elementi[i][j] + mat2.elementi[i][j];
    }
    return mat3;
}

template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3 = StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona);
    double suma(0);
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            for(int k = 0; k < m1.br_kolona; k++)
                suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
            suma = 0;
        }
    }
    return m3;
}

template <typename TipElementa>
Matrica <TipElementa> MatricniPolinom (Matrica<TipElementa> m, const std::vector<double> &v)
{
    if(m.br_redova != m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");

    if(v.empty()) {
        for(int i = 0; i < m.br_redova; i++) {
            for(int j = 0; j < m.br_kolona; j++)
                m.elementi[i][j] = 0;
        }
        return m;
    } else {
        int br_redova(m.br_redova), br_kolona(m.br_kolona);
        Matrica<TipElementa> rez(StvoriMatricu<TipElementa>(br_redova, br_kolona));

        Matrica<TipElementa> jednicna((StvoriMatricu<TipElementa>(br_redova, br_kolona)));
        for(int i = 0; i < m.br_redova; i++) {
            for(int j = 0; j < m.br_kolona; j++) {
                if(i == j) jednicna.elementi[i][j] = 1;
                else jednicna.elementi[i][j] = 0;
            }
        }

        Matrica<TipElementa> tmp(StvoriMatricu<TipElementa>(br_redova, br_kolona));
        for(int i = 0; i < tmp.br_redova; i++) {
            for(int j = 0; j < tmp.br_kolona; j++)
                tmp.elementi[i][j] = m.elementi[i][j];
        }

        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < m.br_redova; j++) {
                for(int k = 0; k < m.br_kolona; k++) {
                    if(i == 0) {
                        rez.elementi[j][k] = v[i]*jednicna.elementi[j][k];
                    } else {
                        rez.elementi[j][k] += v[i]*tmp.elementi[j][k];
                    }
                }
            }
            try {
                if(i != 0) {
                    auto temp = ProduktMatrica(tmp, m);
                    for(int x = 0; x <temp.br_redova; x++)
                        for(int y = 0; y < temp.br_kolona; y++)
                            tmp.elementi[x][y] = temp.elementi[x][y];
                    UnistiMatricu(temp);
                }
            } catch(std::domain_error e) {
                throw;
            }
        }
        UnistiMatricu(tmp);
        UnistiMatricu(jednicna);
        return rez;
    }
}

int main ()
{
    Matrica<double> a, b;
    int m;
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        cout << "Unesite elemente matrice A: " << endl;
        UnesiMatricu('A', a);
        cout << "Unesite red polinoma: ";
        int n;
        cin >> n;
        cout<< "Unesite koeficijente polinoma: ";
        int x;
        std::vector<double> v;
        for(int i = 0; i <= n; i++) {
            cin >> x;
            v.push_back(x);
        }
        try {
            IspisiMatricu(b = MatricniPolinom<double>(a, v), 10);
        } catch(std::domain_error e) {
            cout << e.what();
        }
    } catch (std::bad_alloc) {
        cout << "Nema dovoljno momorije!" << endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(b);

    return 0;
}
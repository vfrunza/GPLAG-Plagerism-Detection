/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova;
    int br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    try {
        mat.elementi = new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
        for(int i=0; i<br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_redova; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica <TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_kolona || m1.br_redova != m2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    }

    return m3;
}

template <typename TipElemenata>
bool SaglasneZaMnozenje(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    return m1.br_kolona == m2.br_redova;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(!(SaglasneZaMnozenje(m1, m2))) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            m3.elementi[i][j]=0;
            for(int k=0; k<m2.br_redova; k++) m3.elementi[i][j] += (m1.elementi[i][k]*m2.elementi[k][j]);
        }
    }
    return m3;
}

template <typename TipElemenata>
bool JeLiKvadratna(const Matrica<TipElemenata> &A)
{
    return A.br_redova == A.br_kolona;
}

template <typename TipElemenata>
Matrica<TipElemenata> KreirajJedinicnu(const Matrica<TipElemenata> &A)
{
    auto jedinicna(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    for(int i=0; i<jedinicna.br_redova; i++) {
        for(int j=0; j<jedinicna.br_redova; j++)
            if(i==j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0;
    }
    return jedinicna;

}

template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSkalarom(const Matrica<TipElemenata> &mat, TipElemenata skalar)
{
    auto pomnozena(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<pomnozena.br_redova; i++) {
        for(int j=0; j<pomnozena.br_kolona; j++)
            pomnozena.elementi[i][j] = skalar*mat.elementi[i][j];
    }

    return pomnozena;
}

template <typename TipElemenata>
bool SveNule(const Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            if(mat.elementi[i][j]!=0) return false;
        }
    }
    return true;
}


template <typename TipElemenata, typename IterILIPok>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, int n, IterILIPok iter)
{
    if (n<0) throw std::domain_error ("Neispravan stepen polinoma");
    if (!(JeLiKvadratna(A))) throw std::domain_error ("Matrica mora biti kvadratna");

    auto matricni_polinom(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    auto jedinicna(KreirajJedinicnu<TipElemenata>(A));

    for(int i=0; i<matricni_polinom.br_redova; i++) {
        for(int j=0; j<matricni_polinom.br_kolona; j++)
            matricni_polinom.elementi[i][j] = 0;
    }

    if(SveNule(A)) {
        UnistiMatricu(matricni_polinom);
        auto rezultat(PomnoziSkalarom<TipElemenata>(jedinicna, *iter));
        UnistiMatricu(jedinicna);
        return rezultat;
    }

    for(int i=0; i<=n; i++) {
        auto pomocna_1(PomnoziSkalarom<TipElemenata>(jedinicna, *iter));
        auto pomocna_2(ZbirMatrica<TipElemenata>(matricni_polinom, pomocna_1));
        UnistiMatricu(matricni_polinom);
        matricni_polinom = pomocna_2;
        UnistiMatricu(pomocna_1);
        auto temp =jedinicna;
        jedinicna=ProduktMatrica(A, jedinicna);
        UnistiMatricu(temp);
        iter++;
        if(i==n) UnistiMatricu(jedinicna); //jedinicna nam vise nije potrebna
    }
    return matricni_polinom;
}


int main ()
{
    Matrica<double> A;

    try {
        std::cout << "Unesite dimenziju kvadratne matrice: ";
        int dimenzija;
        std::cin >> dimenzija;

        std::cout << "Unesite elemente matrice A: " << std::endl;
        A = (StvoriMatricu<double>(dimenzija, dimenzija));
        UnesiMatricu('A', A);

        std::cout << "Unesite red polinoma: ";
        int red_polinoma;
        std::cin >> red_polinoma;

        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<int> v(red_polinoma+1);
        for(int i=0; i<=red_polinoma; i++) {
            int element;
            std::cin >> element;
            v[i]=element;
        }

        IspisiMatricu(MatricniPolinom(A, red_polinoma, v.begin()), 10, 6, true);

    } catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    UnistiMatricu(A);
    return 0;
}

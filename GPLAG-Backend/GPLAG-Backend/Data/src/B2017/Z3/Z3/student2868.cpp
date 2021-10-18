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
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati)
        UnistiMatricu(mat);
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {
            TipElemenata suma {};
            for (int k = 0; k < m1.br_kolona; k++)
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template <typename TipElemenata, typename PokaziliIter>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, int n, PokaziliIter it)
{
    Matrica <TipElemenata> pomocna;
    if (n<0)
        throw std::domain_error("Neispravan stepen polinoma");
    if (mat.br_redova!=mat.br_kolona)
        throw std::domain_error("Matrica mora biti kvadratna");
    int dim(mat.br_redova);
    Matrica<TipElemenata> rez;
    try {
        rez=StvoriMatricu<TipElemenata>(dim, dim);
    } catch (...) {
        throw;
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i==j)
                rez.elementi[i][j] = *it;
            else
                rez.elementi[i][j] = 0;
        }
    }
    it++;
    n--;
    if (n==-1)
        return rez;
    Matrica<TipElemenata> proizvod;
    try {
        proizvod=StvoriMatricu<TipElemenata>(dim, dim);
    } catch (...) {
        UnistiMatricu(rez);
        throw;
    }

    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            proizvod.elementi[i][j] = mat.elementi[i][j];


    for (int k = 0; k < n+1; k++) {
        if (k!=0) {
            try {
                pomocna = ProduktMatrica(proizvod, mat);
            } catch (...) {
                UnistiMatricu(proizvod);
                UnistiMatricu(rez);
                throw;
            }
            for (int i = 0; i < dim; i++)
                for (int j = 0; j < dim; j++)
                    proizvod.elementi[i][j] = pomocna.elementi[i][j];
            UnistiMatricu(pomocna);
        }
        if (*it!=0) {
            for (int i = 0; i < dim; i++)
                for (int j = 0; j < dim; j++)
                    proizvod.elementi[i][j] *= *it;
            try {
                pomocna = ZbirMatrica(rez, proizvod);
            } catch (...) {
                UnistiMatricu(proizvod);
                UnistiMatricu(rez);
                throw;
            }
            for (int i = 0; i < dim; i++)
                for (int j = 0; j < dim; j++)
                    rez.elementi[i][j] = pomocna.elementi[i][j];
            UnistiMatricu(pomocna);
            for (int i = 0; i < dim; i++)
                for (int j = 0; j < dim; j++)
                    proizvod.elementi[i][j] /= *it;
        }
        it++;
    }

    UnistiMatricu(proizvod);
    return rez;
}

int main()
{
    Matrica<int> mat, rez;
    int vel;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> vel;
    try {
        mat = StvoriMatricu<int>(vel, vel);
    } catch (const std::exception &greska) {
        std::cout << greska.what();
        return 0;
    }

    std::cout << "Unesite elemente matrice A: \n";
    UnesiMatricu('A', mat);

    int n;
    std::cout << "Unesite red polinoma: ";
    std::cin >> n;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<int> pol;
    try {
        pol.resize(n+1);
    } catch (...) {
        return 0;
    }

    for (int i = 0; i < pol.size(); i++)
        std::cin >> pol.at(i);

    try {
        rez = MatricniPolinom(mat, n, pol.begin());
    } catch (const std::exception &greska) {
        UnistiMatricu(mat);
        UnistiMatricu(rez);
        std::cout << greska.what();
        return 0;
    }

    IspisiMatricu(rez, 10);

    UnistiMatricu(mat);
    UnistiMatricu(rez);

    return 0;
}

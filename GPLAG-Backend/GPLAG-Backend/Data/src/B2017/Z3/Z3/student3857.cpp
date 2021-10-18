/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

//ZADATAK KOPIRAN SA PREDAVANJA

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
Matrica<TipElemenata> NapraviJedinicnuMatricu(Matrica<TipElemenata> &mat)
{

    for (int i = 0; i < mat.br_redova; i++)
        for (int j = 0; j < mat.br_kolona; j++) {
            if (i == j) mat.elementi[i][j] = 1;
            else mat.elementi[i][j] = 0;
        }

}

template <typename TipElemenata>
Matrica<TipElemenata> PopuniNulama(Matrica<TipElemenata> &mat)
{

    for (int i = 0; i < mat.br_redova; i++)
        for (int j = 0; j < mat.br_kolona; j++) {
            mat.elementi[i][j] = 0;
        }

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
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa ,int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati == true) UnistiMatricu(mat);

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
Matrica <TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");

    auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));

    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {

            TipElemenata suma (0);
            for (int k = 0; k < m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template <typename TipElemenata>
void MnozenjeSkalarom (Matrica<TipElemenata> mat, double skalar)
{

    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++) {
            mat.elementi[i][j] *= skalar;
        }
    }

}

template <typename TipElemenata, typename Iterator>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, int stepen, Iterator it)
{

    if (mat.br_kolona != mat.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    if (stepen < 0) throw std::domain_error ("Neispravan stepen polinoma");

    auto povratna (StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_redova));

    PopuniNulama(povratna);

    for (int i = 0; i <= stepen; i++) {
        if (it[i]==0) continue;
        try {
            Matrica<TipElemenata> jedinicna = (StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_redova));
            NapraviJedinicnuMatricu(jedinicna);

            for (int j = 0; j < i; j++) {
                auto pomocna(jedinicna);
                try {
                    jedinicna = ProduktMatrica(mat,jedinicna);
                    UnistiMatricu(pomocna);
                } catch (...) {
                    UnistiMatricu(jedinicna);
                    throw;
                }
            }
            MnozenjeSkalarom(jedinicna,it[i]);
            try {
                auto pomocna2(povratna);
                povratna = ZbirMatrica(povratna,jedinicna);
                UnistiMatricu(jedinicna);
                UnistiMatricu(pomocna2);
            } catch(...) {
                UnistiMatricu(jedinicna);
                throw;
            }
        } catch (...) {
            UnistiMatricu(povratna);
            throw;
        }
    }
    return povratna;
}

int main()
{
    Matrica<double> a; // AUTOMATSKA INICIJALIZACIJA!!!
    int m, n, g;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);

        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);

        std::cout << "Unesite red polinoma: ";
        std::cin >> n;

        std::cout << "Unesite koeficijente polinoma: ";

        std::vector<double> koeficijenti;

        for (int i = 0; i <=n; i++) {
            double koef;
            std::cin >> koef;
            koeficijenti.push_back(koef);
        }

        IspisiMatricu(MatricniPolinom(a,n,std::begin(koeficijenti)),10,6,true);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
        UnistiMatricu(a);
    }catch(const std::domain_error &e) {
                std::cout << e.what() << std::endl;
                return 0;
    }
    UnistiMatricu(a);

    return 0;
}
/B2017/2018: Zadaća 3, Zadatak 3

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
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona);

template <typename Tip, typename Tip2>
Matrica<Tip> DajJedinicnuMatricu (const Matrica <Tip2> &matrica)
{
    auto Jedinicna = StvoriMatricu<Tip>(matrica.br_redova, matrica.br_kolona);
    for (int i(0); i<matrica.br_redova; i++) {
        for (int j(0); j<matrica.br_kolona; j++) {
            if(i!=j) Jedinicna.elementi[i][j] = 0;
            else Jedinicna.elementi[i][j] = 1;
        }
    }
    return Jedinicna;
}

template <typename Tip, typename SkalarTip>
void MnozenjeMatriceSkalarom (Matrica<Tip> matrica, SkalarTip skalar)
{
    for (int i(0); i<matrica.br_redova; i++)
        for (int j(0); j<matrica.br_kolona; j++)
            matrica.elementi[i][j] *= skalar;
}

template <typename Tip1, typename Tip2>
auto ProduktMatrica (const Matrica<Tip1> &prva, const Matrica<Tip2> &druga) -> Matrica<decltype(**prva.elementi***druga.elementi)>
{
    if(prva.br_kolona != druga.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje!") ;
    Matrica<decltype(**prva.elementi***druga.elementi)> produkt = StvoriMatricu<decltype(**prva.elementi***druga.elementi)>(prva.br_redova, druga.br_kolona);
    for (int i(0); i<prva.br_redova; i++)
        for (int j(0); j<druga.br_kolona; j++)
            for (int k(0); k<prva.br_redova; k++)
                produkt.elementi[i][j] = produkt.elementi[i][j] + (prva.elementi[i][k] * druga.elementi[k][j]);
    return produkt;
}

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
    mat.elementi = new TipElemenata*[br_redova]();
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona]();
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

template <typename Tip1, typename Tip2>
void Uduplaj (Matrica<Tip1> &matrica1, const Matrica<Tip2> &matrica2)
{
    for (int i(0); i<matrica1.br_redova; i++) {
        for(int j(0); j<matrica1.br_kolona; j++) {
            matrica1.elementi[i][j] = matrica2.elementi[i][j];
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

    if(treba_brisati)
        UnistiMatricu(mat);
}


template <typename TipElemenata1, typename TipElemenata2>
auto ZbirMatrica(const Matrica<TipElemenata1> &m1, const Matrica<TipElemenata2> &m2) -> Matrica<decltype(**m1.elementi+**m2.elementi)>
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<decltype(**m1.elementi***m2.elementi)>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m3.br_redova; i++)
        for(int j = 0; j < m3.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename Tip, typename TipPokazivaca>
auto MatricniPolinom (Matrica<Tip> matrica, int stepen_polinoma, TipPokazivaca lokacija) -> Matrica<decltype(**matrica.elementi**lokacija)>
{
    if(matrica.br_kolona != matrica.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    if (stepen_polinoma<0) throw std::domain_error("Neispravan stepen polinoma");
    int brojfaktora = stepen_polinoma+1;
    std::vector<Matrica<decltype(**matrica.elementi**lokacija)>> FaktoriPolinoma;
    for(int i(0); i<brojfaktora; i++) {
        if(i==0) {
            auto FaktorPolinoma = DajJedinicnuMatricu<decltype(**matrica.elementi**lokacija)>(matrica);
            MnozenjeMatriceSkalarom<decltype(**matrica.elementi**lokacija)>(FaktorPolinoma, *lokacija);
            FaktoriPolinoma.push_back(FaktorPolinoma);
            lokacija++;
        } else {
            Matrica<decltype(**matrica.elementi**lokacija)> FaktorPolinoma = StvoriMatricu<decltype(**(matrica.elementi)* *lokacija)>(matrica.br_redova, matrica.br_kolona);
            Uduplaj<decltype(**matrica.elementi**lokacija)>(FaktorPolinoma, matrica);
            for (int j(1); j<i; j++) {
                auto Pomocna = FaktorPolinoma;
                FaktorPolinoma = ProduktMatrica<decltype(**matrica.elementi**lokacija)>(FaktorPolinoma, matrica);
                UnistiMatricu(Pomocna);
            }
            MnozenjeMatriceSkalarom(FaktorPolinoma, *lokacija);
            FaktoriPolinoma.push_back(FaktorPolinoma);
            lokacija++;
        }
    }
    auto Rezultat = StvoriMatricu<decltype(**matrica.elementi**lokacija)>(matrica.br_redova, matrica.br_kolona);
    MnozenjeMatriceSkalarom(Rezultat, 0);
    for(int i(0); i<FaktoriPolinoma.size(); i++) {
        auto Pomocna = Rezultat;
        Rezultat = ZbirMatrica<decltype(**matrica.elementi**lokacija)>(Rezultat, FaktoriPolinoma[i]);
        UnistiMatricu(Pomocna);
    }

    for (int i(0); i<FaktoriPolinoma.size(); i++)
        UnistiMatricu(FaktoriPolinoma[i]);

    return Rezultat;
}


int main()
{
    Matrica<int> A; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    A = StvoriMatricu<int>(m, m);
    std::cout << "Unesite elemente matrice A:\n";
    UnesiMatricu('A', A);
    std::cout << "Unesite red polinoma: ";
    int red_polinoma;
    std::cin >> red_polinoma;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> Koeficijenti;
    for(int i(0); i<=red_polinoma; i++) {
        double coeff;
        std::cin >> coeff;
        Koeficijenti.push_back(coeff);
    }
    auto Rezultat=MatricniPolinom(A, red_polinoma, Koeficijenti.begin());
    IspisiMatricu(Rezultat, 10, 6, true);
    UnistiMatricu(A);
    return 0;
}

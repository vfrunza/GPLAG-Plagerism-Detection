/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <deque>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) {
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    int broj(0);
    bool alocirano(false);
    try {
        mat.elementi = new TipElemenata* [br_redova] {};
        alocirano=true;
        for(int i(0); i < br_redova; i++) {
            mat.elementi[i] = new TipElemenata[br_kolona] {};
            broj++;
        }
    } catch(...) {
        for(int i(0); i<broj; i++) delete[] mat.elementi[i];
        if(alocirano) delete[] mat.elementi;
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    std::cout << "Unesite elemente matrice " << ime_matrice <<":\n";
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_izbisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_izbisati) {
        UnistiMatricu(mat);
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
        std::cout << std::endl;
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &a, const Matrica<TipElemenata> &b)
{
    if(a.br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> c;
    c=StvoriMatricu<TipElemenata>(a.br_redova, b.br_kolona);
    for(int i(0); i<c.br_redova; i++) {
        for(int j(0); j<c.br_kolona; j++) {
            c.elementi[i][j]=TipElemenata(0);
        }
    }
    for(int i(0); i<c.br_redova; i++) {
        for(int j(0); j<c.br_kolona; j++) {
            for(int k(0); k<a.br_kolona; k++) {
                c.elementi[i][j]+=a.elementi[i][k]*b.elementi[k][j];
            }
        }
    }
    return c;
}

template <typename TipElemenata, typename IteratorIliPokazivacNaKontejner>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a, int n, IteratorIliPokazivacNaKontejner koeficijenti)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(a.br_kolona!=a.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> pomocni, matricni_polinom;
    matricni_polinom=StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
    pomocni=StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
    for(int i(0); i<a.br_redova; i++) {
        for(int j(0); j<a.br_kolona; j++) {
            matricni_polinom.elementi[i][j]=TipElemenata(0);
            pomocni.elementi[i][j]=TipElemenata(0);
            if(i==j) pomocni.elementi[i][j]=1;
        }
    }
    for(int red(0); red<=n; red++) {
        for(int i(0); i<a.br_redova; i++) {
            for(int j(0); j<a.br_kolona; j++) {
                matricni_polinom.elementi[i][j]+=*koeficijenti*pomocni.elementi[i][j];
            }
        }
        Matrica<TipElemenata> pomocni2(pomocni);
        pomocni=ProduktMatrica(pomocni, a);
        UnistiMatricu<TipElemenata>(pomocni2);
        koeficijenti++;
    }
    UnistiMatricu<TipElemenata>(pomocni);
    return matricni_polinom;
}

int main()
{
    Matrica<double> a, b; // AUTOMATSKA INICIJALIZACIJA!!!
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::deque<int> koeficijenti(n+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i(0); i<=n; i++) std::cin >> koeficijenti.at(i);
        std::deque<int>::iterator pok(koeficijenti.begin());
        b=MatricniPolinom(a, n, pok);
        IspisiMatricu(b, 10, 6, true);
        UnistiMatricu(a);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;
}
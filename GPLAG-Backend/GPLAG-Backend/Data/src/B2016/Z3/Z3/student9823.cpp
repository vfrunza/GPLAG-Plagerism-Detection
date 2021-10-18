/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <stdexcept>
#include <new>

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
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3;
    try{
    m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for(int i=0; i < m1.br_redova; i++) {
        for(int j=0; j < m2.br_kolona; j++) {
            TipElemenata suma(0);
            for(int k=0; k < m2.br_redova; k++) {
                suma += m1.elementi[i][k] * m2.elementi[k][j];
            }
            m3.elementi[i][j] = suma;
        }
    }
    }catch(...){
        throw std::bad_alloc();
    }
    return m3;
}

template <typename TipElemenata>
void Kvadratna(Matrica<TipElemenata> &m, Matrica<TipElemenata> &a)
{
    auto m2(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    for(int i=0; i < m.br_redova; i++) {
        for(int j=0; j < m.br_kolona; j++) {
            TipElemenata suma(0);
            for(int k=0; k < m.br_redova; k++) {
                suma += m.elementi[i][k] * a.elementi[k][j];
            }
            m2.elementi[i][j] = suma;
        }
    }
    for(int i=0; i < a.br_redova; i++) for(int j=0; j < a.br_kolona; j++) m.elementi[i][j] = m2.elementi[i][j];
    UnistiMatricu(m2);
} 

template <typename TipElemenata>
void PomnoziSa(Matrica<TipElemenata> &m, double x)
{
    for(int i=0; i < m.br_redova; i++) for(int j=0; j < m.br_kolona; j++) m.elementi[i][j] *= x;
}

template <typename TipElemenata>
void Saberinaprvu(Matrica<TipElemenata> &m1, Matrica<TipElemenata> &m2)
{
    for(int i=0; i < m1.br_redova; i++) for(int j=0; j < m1.br_kolona; j++) m1.elementi[i][j] += m2.elementi[i][j];
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &a, const std::vector<double> &koef)
{
    if(a.br_kolona != a.br_redova) throw std::domain_error("Matrica mora biti kvadratna");

    Matrica<TipElemenata> kraj(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));

    for(int i=0; i < kraj.br_redova; i++) for(int j=0; j < kraj.br_kolona; j++) if(i == j) kraj.elementi[i][j] = 1;
            else kraj.elementi[i][j] = 0;
    PomnoziSa(kraj, koef[0]);
    Matrica<TipElemenata> kzapamtit(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    for(int i=0; i < kraj.br_redova; i++) for(int j=0; j < kraj.br_kolona; j++) kzapamtit.elementi[i][j] = a.elementi[i][j];

    for(int i=1; i < koef.size(); i++) {
        if(koef[i]!=0) {
            PomnoziSa(kzapamtit, koef[i]);
            Saberinaprvu(kraj, kzapamtit);
            PomnoziSa(kzapamtit, 1./koef[i]);
        }
        Kvadratna(kzapamtit, a);
    }
    UnistiMatricu(kzapamtit);
    return kraj;
}

int main()
{
    Matrica<double> a, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        int n;
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> vekt(n+1);
        for(int i=0; i < n+1; i++) std::cin >> vekt[i];
        c = MatricniPolinom<double>(a, vekt);
        IspisiMatricu(c, 10, 6);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(c);
    
    return 0;
}

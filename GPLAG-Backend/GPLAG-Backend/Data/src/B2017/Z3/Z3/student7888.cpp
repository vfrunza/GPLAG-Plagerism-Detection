#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona);

template <typename TipElemenata>
Matrica<TipElemenata> MnozenjeSkalarom( Matrica<TipElemenata> &m, double x) {
    auto mat=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    for (int i=0; i<m.br_redova; i++) {
        for (int j=0; j<m.br_kolona; j++) {
            mat.elementi[i][j]=m.elementi[i][j]*x;
        }
    }
    UnistiMatricu(m);
//    m.elementi=nullptr;
    return mat;
}

template <typename TipElemenata>
void UnistiMatricu(const Matrica<TipElemenata> &mat) {
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    try {
        mat.elementi=new TipElemenata*[br_redova];
    }
    catch (...) {
        UnistiMatricu(mat);
        mat.elementi=nullptr;
        throw;
    }
    for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
    for (int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        mat.elementi=nullptr;
        throw;
    }
    for (int i=0; i<br_redova; i++) {
        for (int j=0; j<br_kolona; j++) {
            mat.elementi[i][j]=0;
        }
    }
    return mat;
}

template <typename TipElemenata>
Matrica<TipElemenata> Jedinicna (int n) {
    Matrica<TipElemenata> m;
    try {
    m=StvoriMatricu<TipElemenata>(n,n);
    }
    catch (...) {
        UnistiMatricu(m);
        m.elementi=nullptr;
        throw;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) m.elementi[i][j]=1;
            else m.elementi[i][j]=0;
        }
    }
    return m;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2) {
    if (m1.br_redova!=m2.br_redova or m1.br_kolona!=m2.br_kolona) {
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    }
    Matrica<TipElemenata> m3;
    try {
    m3=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    }
    catch (...) {
        UnistiMatricu(m3);
        m3.elementi=nullptr;
        throw;
    }
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_kolona; j++) {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    UnistiMatricu(m1);
    UnistiMatricu(m2);
    m1.elementi=nullptr;
    m2.elementi=nullptr;
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    Matrica<TipElemenata> m;
    try {
        m=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    }
    catch (...) {
        UnistiMatricu(m);
        m.elementi=nullptr;
        throw;
    }
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m2.br_kolona; j++) {
            m.elementi[i][j]=0;
        }
    }
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    double suma;
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m2.br_kolona; j++) {
            suma=0;
            for (int k=0; k<m1.br_kolona; k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m.elementi[i][j]=suma;
        }
    }
    return m;
}

template <typename TipElemenata, typename TipIt>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &m1, int n, TipIt it) {
    Matrica<TipElemenata> m, faktor;
    try {
        m=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    }
    catch(...) {
        UnistiMatricu(m);
        m.elementi=nullptr;
        throw;
    }
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_redova; j++) {
            m.elementi[i][j]=0;
        }
    }
    if (n<0) throw std::domain_error("Neispravan stepen polinoma");
    if (m1.br_redova!=m1.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    faktor=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_kolona; j++) {
            if (i==j) faktor.elementi[i][j]=1;
            else faktor.elementi[i][j]=0;
        }
    }
    for (int i=0; i<=n; i++) {
        m=ZbirMatrica<TipElemenata>(m, MnozenjeSkalarom(faktor, *it));
        faktor=ProduktMatrica<TipElemenata>(faktor, m1);
        it++;
    }
    UnistiMatricu(m1);
    m1.elementi=nullptr;
    UnistiMatricu(faktor);
    faktor.elementi=nullptr;
    return m;
}

int main ()
{
    Matrica<double> a, b;
    int m, n;
    std::vector<double> v;
    double k;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a=StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> m;
        std::cout << "Unesite koeficijente polinoma: ";
        for (int i=0; i<m+1; i++) {
            std::cin >> k; 
            v.push_back(k);
        }
        b=MatricniPolinom(a, m, v.begin());
        IspisiMatricu(b, 10, 6);
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch (std::domain_error izuzetak1) {
        std::cout << izuzetak1.what() << std::endl;
    }
    UnistiMatricu(a);
    a.elementi=nullptr;
    UnistiMatricu(b);
    b.elementi=nullptr;
	return 0;
}

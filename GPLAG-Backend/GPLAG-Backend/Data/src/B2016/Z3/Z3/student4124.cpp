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
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i(0); i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata *[br_redova];
    for(int i(0); i<br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i(0); i<br_redova; i++)
            mat.elementi[i] = new TipElemenata [br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i(0); i<mat.br_redova; i++) 
        for(int j(0); j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    for(int i(0); i<mat.br_redova; i++)  {
        for(int j(0); j<mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova or m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m2.br_kolona; j++) {
            m3.elementi[i][j] = 0;
            for(int k(0); k<m1.br_kolona; k++) {
                m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    return m3;
}

template <typename TipElemenata>
void Kopiraj(Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2) {
    for(int i(0); i<mat1.br_redova; i++)
        for(int j(0); j<mat1.br_kolona; j++)
            mat1.elementi[i][j]=mat2.elementi[i][j];
}

template <typename TipElemenata>
void ProduktSKonstantom(Matrica<TipElemenata> &mat, double x) {
    for(int i(0); i<mat.br_redova; i++)
        for(int j(0); j<mat.br_kolona; j++)
            if(mat.elementi[i][j]!=0) mat.elementi[i][j]*=x;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<double> v) {
    if(mat.br_redova != mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> mat2(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i(0); i<mat2.br_redova; i++)
        for(int j(0); j<mat2.br_kolona; j++)
            mat2.elementi[i][j] = 0;
    if(v.size()==0) return mat2;
    
    for(int i(0); i<mat2.br_redova; i++)
        for(int j(0); j<mat2.br_kolona; j++)
            if(i==j) mat2.elementi[i][j] = 1;
    ProduktSKonstantom(mat2, v[0]);
    
    for(int i(1); i<v.size(); i++) {
        Matrica<TipElemenata> mat3(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona)), mat4;
        Kopiraj(mat3, mat);
        for(int j(1); j<i; j++) {
            Matrica<TipElemenata> mat5;
            mat5 = ProduktMatrica(mat, mat3);
            Kopiraj(mat3, mat5);
            UnistiMatricu(mat5);
        }
        ProduktSKonstantom(mat3, v[i]);
        mat4 = ZbirMatrica(mat3, mat2);
        Kopiraj(mat2, mat4);
        UnistiMatricu(mat3); UnistiMatricu(mat4);
    }
    return mat2;
}

int main ()
{
    Matrica<double> a, b;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double> (m, m);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        int n;
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::vector<double> v(n+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for(double &x : v) std::cin >> x;
        b = MatricniPolinom(a, v);
        IspisiMatricu(b, 10);
        // ne smijemo pisati Ispisimatricu(ZbirMatrica(a,b), 7); jer funkcija ZbirMatrica
        // dinamicki alocira dvostruki pokazivac na novokreiranu matricu i tom bi naredbom izgubili informaciju
        // o istom te ga ne bismo mogli izbrisati
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(b);
	return 0;
}
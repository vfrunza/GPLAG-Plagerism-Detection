/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
bool DaLiJeJedinicna (Matrica<TipElemenata> mat) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            if (i==j && mat.elementi[i]!=1) return false;
            if (i!=j && mat.elementi[i]!=0) return false;
        }
    }
    return true;
}

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat) {
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;    mat.br_kolona=br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for (int i=0; i<br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (Matrica<TipElemenata> mat1, Matrica<TipElemenata> mat2) {
    if (mat1.br_redova!=mat2.br_kolona) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    int redovi = mat1.br_redova, kolone=mat2.br_kolona;
    Matrica<TipElemenata> mat3;
    mat3 = StvoriMatricu<TipElemenata>(redovi, kolone);
    for (int i=0; i<mat1.br_redova; i++) {
        for (int j=0; j<mat2.br_kolona; j++) {
            TipElemenata suma{};
            for (int k=0; k<mat2.br_redova; k++) suma += mat1.elementi[i][k]*mat2.elementi[k][j];
            mat3.elementi[i][j] = suma;
        }
    }
    return mat3;
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++)
            std::cout << std::cout.precision(preciznost) <<std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
    return;
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimezije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> mat, int n, Tip p) {
    if (n<1) throw std::domain_error ("Neispravan stepen polinoma");
    if (mat.br_kolona!=mat.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    int redovi=mat.br_redova, kolone=mat.br_kolona;
    Matrica<TipElemenata> Suma, MatZaStep, MatZaBris, MatZaMno;
   
    try {
        Suma = StvoriMatricu<TipElemenata>(redovi, kolone);
    }
    catch (std::bad_alloc) {
        throw;
    }
    
    try {
        MatZaStep = StvoriMatricu<TipElemenata>(redovi, kolone);
    }
    catch (std::bad_alloc) {
        UnistiMatricu(Suma);
        throw;
    }
    
    try {
        MatZaMno = StvoriMatricu<TipElemenata>(redovi, kolone);
    }
    catch (std::bad_alloc) {
        UnistiMatricu(Suma);
        UnistiMatricu(MatZaStep);
        throw;
    }
    
    for (int i=0; i<redovi; i++) {
        for (int j=0; j<kolone; j++) {
            Suma.elementi[i][j] = 0;
            MatZaStep.elementi[i][j] = mat.elementi[i][j];
            MatZaMno.elementi[i][j] = 1;
        }
    }
    
    int k(1);
    p++;
    while (k<n) {
        for (int i=0; i<redovi; i++) {
            for (int j=0; j<kolone; j++) {
                MatZaMno.elementi[i][j] = MatZaStep.elementi[i][j];
            }
        }
        for (int i=0; i<redovi; i++) {
            for (int j=0; j<kolone; j++) {
                MatZaMno.elementi[i][j] *= *p;
                //std::cout << MatZaMno.elementi[i][j] << " ";
            }
        }
        MatZaBris = Suma;
        Suma = ZbirMatrica<TipElemenata> (Suma, MatZaMno);
        UnistiMatricu(MatZaBris);
        MatZaBris = MatZaStep;
        MatZaStep = ProduktMatrica<TipElemenata> (MatZaStep, mat);
        UnistiMatricu(MatZaBris);
        p++;
        k++;
    }
    UnistiMatricu(MatZaStep);
    UnistiMatricu(MatZaMno);
    return Suma;
}

int main ()
{
    Matrica<double> a;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;
        std::vector<double> v;
        double koef;
        std::cout << "Unesite koeficijente polinoma: ";
        while (v.size()<(red+1)) {
            std::cin >> koef;
            v.push_back(koef);
        }
        Matrica<double> temp;
        try {
            temp = a;
            a = MatricniPolinom<double> (a, red, v.begin());
            UnistiMatricu(temp);
            IspisiMatricu (a, 10, 6, true);
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what();
            UnistiMatricu(temp);
        }
        catch (...) {
            
        }
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    //UnistiMatricu(a);
	return 0;
}
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
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa=10, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << std::fixed << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m1.br_kolona; j++) m3.elementi[i][j]=m1.elementi[i][j] + m2.elementi[i][j];
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            TipElemenata suma(0);
            for(int k=0; k<m1.br_kolona; k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }

    return m3;
}

template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> PomnoziMatricuBrojem(const Matrica<TipElemenata> &m, Tip broj)
{
    Matrica<TipElemenata> M(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++) {
            M.elementi[i][j]*=broj;
        }
    }
    
    return M;
}

template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int n, IterTip pocetak)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");

    Matrica<TipElemenata> I(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; i<m.br_kolona; i++) {
            if(i==j) I.elementi[i][j]=1;
            else I.elementi[i][j]=0;
        }
    }

    /*Matrica<TipElemenata> P(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto M(I);
    P=PomnoziMatricuBrojem<TipElemenata>(I, *pocetak);
    pocetak++;
    for(int i=0; i<n; i++) {
        M=ProduktMatrica<TipElemenata>(M,m);
        P=ZbirMatrica<TipElemenata>(P,PomnoziMatricuBrojem(M,*pocetak));
        pocetak++;
    }*/
    
    Matrica<TipElemenata> P(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    auto M(I);
    P=I;
    pocetak++;
    for(int i=0; i<n; i++) {
        M=ProduktMatrica<TipElemenata>(M,m);
        P=ZbirMatrica<TipElemenata>(P,M);
        pocetak++;
    }
    
    return P;
}

int main()
{
    Matrica<double> A;
    int dimenzija;
    std::cout << "Unesite dimenziju kvadratne matrice A: ";
    std::cin >> dimenzija;
    try {
        A = StvoriMatricu<double>(dimenzija,dimenzija);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', A);

        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;

        std::vector<double> koeficijenti(red+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i=0; i<red+1; i++) std::cin >> koeficijenti[i];
        
        Matrica<double> B(MatricniPolinom<double>(A,red,koeficijenti.begin()));
        IspisiMatricu(B);
        UnistiMatricu(B);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    
    return 0;
}

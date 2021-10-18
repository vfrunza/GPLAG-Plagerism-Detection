/B2016/2017: Zadaća 3, Zadatak 3
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
void UnistiMatricu (Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete[]mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;

    try {
        mat.elementi= new TipElemenata*[br_redova];
        for (int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
        for (int i=0; i<br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for (int i=0; i<mat.br_redova; i++)
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6 ,bool treba_brisati=false)
{
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++)
            std::cout << std::setprecision(preciznost) <<std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for (int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
    if (mat1.br_kolona!=mat2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    for (int i=0; i<mat1.br_redova; i++) {
        for (int j=0; j<mat2.br_kolona; j++) {
            /*auto suma(mat1.elementi[0][0]);
            suma={};*/
            double suma(0);
            for (int k=0; k<mat2.br_redova; k++) suma += mat1.elementi[i][k]*mat2.elementi[k][j];
            mat3.elementi[i][j]=suma;
        }
    }
    return mat3;
}

template <typename TipElemenata>
Matrica<TipElemenata>  MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<double> vektor)
{
    auto c(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    Matrica<TipElemenata> povratna;
    povratna=(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    auto d(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for (int i=0; i<vektor.size(); i++) {
        if(i==0) {
            for (int m=0; m<mat.br_redova; m++) {
                for (int n=0; n<mat.br_kolona; n++) {
                    if (m==n) c.elementi[m][n]=1;
                    else c.elementi[m][n]=0;
                }
            }
        } else if (i==1) c=mat;
        else {
            c=mat;
            for (int j=1; j<i; j++) c=ProduktMatrica(mat,c);
        }
        for(int a=0; a<mat.br_redova; a++)
            for (int b=0; b<mat.br_kolona; b++)
                d.elementi[a][b]=c.elementi[a][b]*vektor[i];
        povratna=ZbirMatrica(povratna,d);
    }
    UnistiMatricu(c);
    UnistiMatricu(d);
    return povratna;
}

int main ()
{
    Matrica<double> a,m;
    int n,k;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a=StvoriMatricu<double>(n,n);

        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> k;
        std::vector<double> vektor(k+1);
        std::cout << "Unesite koeficijente polinoma: ";
        double b;
        for (int i=0; i<=k; i++) {
            std::cin >> b;
            vektor[i]=b;
        }
        //std::cout << "Matricni polinom: ";
        IspisiMatricu(m=MatricniPolinom(a, vektor),10);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(m);
    return 0;
}
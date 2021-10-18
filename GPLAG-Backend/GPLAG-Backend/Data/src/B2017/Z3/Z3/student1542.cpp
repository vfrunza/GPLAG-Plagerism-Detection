/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat)
{
    if(!mat.elementi)return;
    for(int i=0; i<mat.br_redova; i++)delete []mat.elementi[i];
    delete []mat.elementi;
    mat.elementi=nullptr;
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
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost='6',bool treba_brisati='false')
{
    if(treba_brisati)UnistiMatricu(mat);
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
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
Matrica <TipElemenata> ProduktMatrica(const Matrica <TipElemenata> &mat1,const Matrica<TipElemenata>&mat2)
{
    if(mat1.br_kolona!=mat2.br_redova)throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    for(int i=0; i<mat1.br_redova; i++)
        for(int j=0; j<mat2.br_kolona; j++) {
            TipElemenata suma(0);
            for(int k=0; k<mat2.br_redova; k++)suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
            mat3.elementi[i][j]=suma;
        }
    return mat3;
}
template <typename TipElemenata>
Matrica <TipElemenata> MatricniPolinom(const Matrica <TipElemenata> &A, int n,  TipElemenata *it)
{
    if(n<0)throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_kolona!=A.br_redova)throw std::domain_error("Matrica mora biti kvadratna");

    auto I(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    auto suma(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    
    for(int i=0; i<A.br_redova; i++) {
        for(int j=0; j<A.br_kolona; j++) {
            if(i==j)I.elementi[i][j]=1;
            else I.elementi[i][j]=0;
            suma.elementi[i][j]+=*(it)*I.elementi[i][j];
        }
    }
    it++;
    auto Pom(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    for(int i=0; i<A.br_redova; i++)
        for(int j=0; j<A.br_kolona; j++)
            if(i==j)Pom.elementi[i][j]=1;
            else Pom.elementi[i][j]=0;

    for(int k=1; k<=n; k++) {
        Pom=ProduktMatrica(A,Pom);
        
        for(int i=0; i<A.br_redova; i++) {
            for(int j=0; j<A.br_kolona; j++) {
                suma.elementi[i][j]+=*(it)*Pom.elementi[i][j];
            }
        }
        it++;
    }
    UnistiMatricu(Pom);
    UnistiMatricu(I);
    return suma;
}



int main() {
        Matrica<double> A;
          Matrica<double> B;
        int n;
        std::cout << "Unesite dimenziju kvadratne matrice: ";
        std::cin >> n;
            A = StvoriMatricu<double>(n, n);
            std::cout << "Unesite elemente matrice A:\n";
            UnesiMatricu('A', A);
       
        
        int r;
        double koef(0);
        std::cout<<"Unesite red polinoma: " ;
        std::cin >> r;
        std::vector<double>koeficijenti;
        std::cout << "Unesite koeficijente polinoma: " ;
        for(int i=0;i<=r;i++){
            std::cin>> koef;
            koeficijenti.push_back(koef);
        }
        
        B=MatricniPolinom(A,r,&koeficijenti[0]);
        IspisiMatricu(B,10);
        UnistiMatricu(B);
        UnistiMatricu(A);
        
        return 0;
    }


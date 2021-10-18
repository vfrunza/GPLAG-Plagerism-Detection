/B2016/2017: Zadaća 3,  Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>
struct Matrica{
  int br_redova,br_kolona;
  TipElemenata** elementi = nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i] = nullptr;
    try
    {
        for(int i=0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...)
    {
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
        std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>& mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i=0; i<mat.br_redova; i++)
    {
        for(int j=0; j<mat.br_kolona; j++) 
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata>& m1, const Matrica<TipElemenata>& m2)
{
    if(m1.br_kolona!=m2.br_redova || m1.br_redova != m2.br_redova) 
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3 = m1;
    try{
     m3 = StvoriMatricu(m1.br_kolona, m1.br_kolona);
    }
    catch(...)
    {
        UnistiMatricu(m3);
    }
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
auto ProduktMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2)->Matrica<TipElemenata>
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3;
    try
    {
        m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    }
    catch(...)
    {
        UnistiMatricu(m3);
    }
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
        {
            m3.elementi[i][j] = 0;
            for(int k=0; k<m1.br_kolona; k++) m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
        }
    
    return m3;
}

template<typename TipElemenata>
auto MatricniPolinom(Matrica<TipElemenata> mat, std::vector<double> vkt)->Matrica<TipElemenata>
{
    Matrica<TipElemenata> A, rez;
    int R = mat.br_redova;
    if(mat.br_kolona != mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    try
    {
        A = StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
        rez = StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
    }
    catch(...)
    {
        UnistiMatricu(A);
        UnistiMatricu(rez);
        throw;
    }
    
    for(int i=0; i<R; i++)
        for(int j=0; j<R; j++) { A.elementi[i][j] = 0; A.elementi[i][i] = 1; rez.elementi[i][j] = 0; }
    
    for(int i=0; i<vkt.size(); i++)
    {
        for(int u=0; u<R; u++)
            for(int v=0; v<R; v++) rez.elementi[u][v] += vkt[i] * A.elementi[u][v];
      //  IspisiMatricu(rez, 10, 6, true); std::cout<<"\n==========\n";
        auto pom(ProduktMatrica(A, mat));
        UnistiMatricu(A);
        A = pom;
    }
    UnistiMatricu(A);
    return rez;
}

int main ()
{
    int N;
    std::cout<< "Unesite dimenziju kvadratne matrice: ";
    std::cin>> N;
    Matrica<double> mat;
    try
    {
        mat = StvoriMatricu<double>(N, N);
    }
    catch(...)
    {
        UnistiMatricu(mat);
        return 0;
    }
    std::cout<< "Unesite elemente matrice A: \n";
    UnesiMatricu('A', mat);
    
    int M;
    std::cout<< "Unesite red polinoma: ";
    std::cin>> M;
    std::vector<double> v(M+1);
    std::cout<< "Unesite koeficijente polinoma: ";
    for(auto& e: v) std::cin>> e;
    auto ispis(MatricniPolinom(mat, v));
    UnistiMatricu(mat);
    IspisiMatricu(ispis, 10, 6, true);
	return 0;
} 
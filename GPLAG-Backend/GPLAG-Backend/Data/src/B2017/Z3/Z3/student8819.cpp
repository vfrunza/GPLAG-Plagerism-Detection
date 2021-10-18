/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include<vector>
#include<cmath>
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
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat, std::vector<TipElemenata> &vektor)
{
    
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
         vektor.push_back(mat.elementi[i][j]);
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa,const std::vector<TipElemenata> &vektor)
{
    std::vector<std::vector<TipElemenata>> matrica;
    for(int i=0;i<mat.br_kolona;i++){
        for(int j=0;j<mat.br_kolona;j++) {
            if(i==j) matrica[i][j]=1;
            else matrica[i][j]=0;
        }
    }
    std::vector<std::vector<TipElemenata>>konacna;
    std::vector<std::vector<TipElemenata>>jed;
    for(int k=0;k<vektor.size();k++){
       
    
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            TipElemenata suma(0);
            if(k==0) {
                if(i==j) jed[i][j]=1;
                else jed[i][j]=0;
                suma=vektor[k]*jed[i][j];
            }
            else{
                suma+=vektor[k]* pow(mat.elementi[i][j],k);
            }
            ;
            
            std::cout << std::setw(sirina_ispisa) << suma;
        }
        
        
        }
        std::cout << std::endl;
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

int main()
{
    Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m, n;
    std::vector<double>vektor;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    try {
        a = StvoriMatricu<double>(m, n);
        
        std::cout << "Unesi matricu A:\n";
        UnesiMatricu('A', a, vektor);
        
        
        IspisiMatricu(a,6, vektor);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
    return 0;
}

 
 
 
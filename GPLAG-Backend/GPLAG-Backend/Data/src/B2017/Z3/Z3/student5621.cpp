/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

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
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    std::cin.precision(preciznost);
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
        
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)UnistiMatricu(mat);
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

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
                                     const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_kolona)throw std::domain_error("Matrice nisu saglasne za mnozenje!");
    auto m(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m2.br_kolona;j++)
        {
            m.elementi[i][j]=0;
        }
    }
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m2.br_kolona;j++)
        {
            for(int k=0;k<m1.br_redova;k++)
            {
               m.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m;
}
template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int n, IterTip it)
{
    if (n<0)throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_kolona!=m.br_redova)throw std::domain_error("Matrica mora biti kvadratna");
    std::vector<Matrica<TipElemenata>> veca(n);
    int num(m.br_redova);
    veca.at(0)=StvoriMatricu<TipElemenata>(num,num);
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(i==j)veca.at(0).elementi[i][j]=1;
            else
            veca.at(0).elementi[i][j]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
        veca.at(i)=ProduktMatrica(m,veca.at(i-1));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<num;j++)
        {
            for(int k=0;k<num;k++)
            {
                veca.at(i).elementi[j][k]*=(*it);
            }
        }
        it++;
    }
    auto result(StvoriMatricu<TipElemenata>(num,num));
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            result.elementi[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<num;j++)
        {
            for(int k=0;k<num;k++)
            {
                result.elementi[j][k]+=veca.at(i).elementi[j][k];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        UnistiMatricu(veca.at(i));
    }
    return result;
    
}

int main() {
    
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente matrice A:\n";
    auto m(StvoriMatricu<double>(n,n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<"A("<<i+1<<","<<j+1<<") = ";
            std::cin>>m.elementi[i][j];
        }
    }
    std::cout<<"Unesite red polinoma: ";
    int r;
    std::cin>>r;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<double> koeficijenti(r+1);
    for(int i=0;i<r+1;i++)
    {
        std::cin>>koeficijenti[i];
    }
    auto polinom(MatricniPolinom(m,r+1,koeficijenti.begin()));
    IspisiMatricu(polinom,10);
    UnistiMatricu(polinom);
    
    UnistiMatricu(m);
 return 0;
}

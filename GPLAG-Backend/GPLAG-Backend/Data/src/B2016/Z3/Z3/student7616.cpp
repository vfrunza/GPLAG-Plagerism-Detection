/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>

struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi =nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i(0); i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi= nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi = new TipElemenata *[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try
    {
        for(int i=0; i<br_redova; i++)
        mat.elementi[i]= new TipElemenata[br_kolona];
    }
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
       for(int j=0; j<mat.br_kolona; j++)
       {
           std::cout<<ime_matrice<<"(" <<i+1 <<"," <<j+1 <<") = ";
           std::cin>>mat.elementi[i][j];
       }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati = false)
{
    for(int i=0; i<mat.br_redova; i++)
    {
        for(int j=0; j<mat.br_kolona; j++)
         std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost) <<mat.elementi[i][j];
         std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova  || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
    for(int i=0; i<m3.br_redova; i++)
       for(int j=0; j<m3.br_kolona; j++)
           m3.elementi[i][j]= m1.elementi[i][j] + m2.elementi[i][j];
           return m3;
}

//Produkt matrice
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
        {
            TipElemenata suma(0);
            for(int k=0; k<m2.br_redova; k++)
                suma+= m1.elementi[i][k] * m2.elementi[k][j];
                m3.elementi[i][j]=suma;
        }
        return m3;
}

template<typename TipElemenata>
void Kopiraj(Matrica<TipElemenata> &m1,Matrica<TipElemenata> &m2){
     for(int i = 0; i < m1.br_redova; i++)
         for(int j = 0; j <  m1.br_kolona;  j++)
                m1.elementi[i][j] = m2.elementi[i][j];
}



template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> mat, std::vector<double> p)
{
    if(mat.br_redova != mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    if(p.size() == 0)
    {
        auto m = StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
        for(int i = 0; i < m.br_redova; i++)
           for(int j = 0; j < m.br_kolona;  j++)
           m.elementi[i][j] = 0;
           
        return m;
    }
    
    auto m = StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j <  m.br_kolona;  j++)
             if(i == j)  m.elementi[i][j] = p[0]; 
                  else   m.elementi[i][j] = 0;
                  
                   if(p.size() == 1) return m;
        
        auto mat1 = StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
         for(int i = 0; i < m.br_redova; i++)
             for(int j = 0; j <  m.br_kolona;  j++)
                  mat1.elementi[i][j] = mat.elementi[i][j] * p[1];
                
     auto mat2 = ZbirMatrica<TipElemenata>(m,mat1);
     Kopiraj(m,mat2);
        
    UnistiMatricu(mat1);
    UnistiMatricu(mat2);
    
    mat1 = StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    Kopiraj(mat1,mat);
    for(int k = 2; k < p.size(); k++)
    {
        auto mat3 = ProduktMatrica<TipElemenata>(mat1,mat);
        Kopiraj(mat1,mat3);
        for(int i = 0; i < m.br_redova; i++)
             for(int j = 0; j <  m.br_kolona;  j++)
              mat3.elementi[i][j] = mat3.elementi[i][j] * p[k];
         mat2 = ZbirMatrica<TipElemenata>(m,mat3);
         Kopiraj(m,mat2);
         UnistiMatricu(mat2);
         UnistiMatricu(mat3);
      
    }
    UnistiMatricu(mat1);
    return m;
}


int main ()
{
    int n,m;
    Matrica<double> mat;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    try{
             mat = StvoriMatricu<double>(n,n);
             std::cout<<"Unesite elemente matrice A: ";
             UnesiMatricu<double>('A',mat);

             std::cout<<"Unesite red polinoma: ";
             std::cin>>m;
             std::vector<double> v(m+1);
             std::cout<<"Unesite koeficijente polinoma: ";
             for(int i=0; i<=m; i++) 
             {
                 std::cin>>v[i];
             }
             auto m1 = MatricniPolinom(mat,v);
             IspisiMatricu(m1,8,6,true);
             UnistiMatricu(m1);
             UnistiMatricu(mat);

    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
    return 0;
}

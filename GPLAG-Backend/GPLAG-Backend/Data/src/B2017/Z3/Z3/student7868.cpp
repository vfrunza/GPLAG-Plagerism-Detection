/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>
#include <new>
#include <stdexcept>
using namespace std;

template<typename t>
struct Matrica
{
    int brr, brk;
    t **el=nullptr;
};

template<typename t>
void UnistiMatricu(Matrica<t> mat)
{
    if(!mat.el) return;
    for(int i=0; i<mat.brr; i++) delete [] mat.el[i];
    delete [] mat.el;
    mat.el=nullptr;
}

template<typename t>
Matrica<t> StvoriMatricu(int brr, int brk)
{
    Matrica<t> mat;
    mat.brk=brk;
    mat.brr=brr;
    try{
        mat.el= new t*[brr];
        for(int i=0; i<brr; i++) mat.el[i]=nullptr;
        try{
            for(int i=0; i<brr; i++) mat.el[i]=new t[brk];
            return mat;
        }
        catch(...) { throw;}
    } catch(...) { UnistiMatricu(mat); throw;}    
    
}

template<typename t>
void UnesiMatricu(char ime_matrice, Matrica<t> &mat)
{
    for(int i=0; i<mat.brr; i++)
        for(int j=0; j<mat.brk; j++)
            {
                cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                cin>>mat.el[i][j];
            }
            
}

template <typename t>
Matrica<t> ZbirMatrica(const Matrica<t> &mat1, const Matrica<t> &mat2)
{
    auto m3(StvoriMatricu<t>(mat1.brr, mat1.brk));
    for(int i=0; i<mat1.brr; i++)
        for(int j=0; j<mat2.brk; j++)
            m3.el[i][j]=mat1.el[i][j]+mat2.el[i][j];
    return m3;
}

template<typename t>
Matrica<t> nule(int a, int b)
{
    auto r=StvoriMatricu<t>(a,b);
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            r.el[i][j]=0;
    return r;
}

template<typename t>
Matrica<t> ProduktMatrica(const Matrica<t> &m1, const Matrica<t> &m2)
{
   if(m2.br_redova!=m1.br_kolona) throw domain_error("Matrice nisu saglasne za mnozenje!");
    auto r=nule<t>(m1.brr, m1.brk);
    for(int i=0; i<m1.brr; i++)
        for(int j=0; j<m2.brk; j++)
            for(int k=0; k<m2.brr; k++)
                r.el[i][j]+=m1.el[i][k]*m2.el[k][j];
    return r;
}

template<typename t>
Matrica<t> jedinicna(int a, int b)
{
    auto r=StvoriMatricu<t>(a,b);
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            if(i==j) r.el[i][j]=1;
            else r.el[i][j]=0;
    return r;
}

template<typename t>
void pomnozi1(Matrica<t> &mat, int a)
{
    for(int i=0; i<mat.brr; i++)
        for(int j=0; j<mat.brk; j++)
            mat.el[i][j]*=a;
    
}

template<typename t>
Matrica<t> pomnozi(const Matrica<t> &mat1, int a)
{
    Matrica<t> mat=StvoriMatricu<t>(mat1.brr, mat1.brk);
    for(int i=0; i<mat.brr; i++)
        for(int j=0; j<mat.brk; j++)
            mat.el[i][j]=mat1.el[i][j];
    for(int i=0; i<mat.brr; i++)
        for(int j=0; j<mat.brk; j++)
            mat.el[i][j]*=a;
    return mat;
    
}

template<typename t>
Matrica<t> MatricniPolinom(const Matrica<t> &A, int n, int *pok)
{
   if(A.br_kolona!=A.br_redova)throw domain_error("Matrica mora biti kvadratna!"); 
}

template <typename TipElemenata>   
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=0)
{       
    for(int i = 0; i < mat.brr; i++) 
    {         
        for(int j = 0; j < mat.brk; j++)            
        std::cout << std::setw(sirina_ispisa) << setprecision(preciznost)<<right<<mat.el[i][j];          
        std::cout << std::endl;
        
        
    }    
    if(treba_brisati) UnistiMatricu(mat);
}


int main ()
{
    
	return 0;
}

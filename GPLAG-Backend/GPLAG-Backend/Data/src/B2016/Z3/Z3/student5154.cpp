/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <new>
#include <vector>

template<typename TipElemenata>
struct Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i(0); i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename tip>
Matrica<tip> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<tip> mat;
    mat.br_redova=br_redova; 
    mat.br_kolona=br_kolona;
    mat.elementi=new tip*[br_redova];
    for(int i(0); i<br_redova; i++) mat.elementi[i]=nullptr;
    try
    {
        for(int i(0); i<br_redova; i++) 
        {
            mat.elementi[i]=new tip[br_kolona];
        }
    }
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename tip>
void UnesiMatricu(char ime_matrice, Matrica<tip> &mat)
{
    for(int i(0); i<mat.br_redova; i++)
    {
        for(int j(0); j<mat.br_kolona; j++)
        {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename tip>
void IspisiMatricu(const Matrica<tip> &mat, int sirina_ispisa=10, int preciznost=6, bool treba_brisati=false)
{
    for(int i(0); i<mat.br_redova; i++)
    {
        for(int j(0); j<mat.br_kolona; j++)
        {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati==true) 
    {
        UnistiMatricu(mat);
        return;
    }
}

template<typename tip>
Matrica<tip> ZbirMatrica(const Matrica<tip> &mat1, const Matrica<tip> &mat2)
{
    if(mat1.br_redova!=mat2.br_redova || mat1.br_kolona!=mat2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto mat3(StvoriMatricu<tip>(mat1.br_redova,mat1.br_kolona));
    for(int i(0); i<mat1.br_redova; i++)
    {
        for(int j(0); j<mat1.br_kolona; j++)
        {
            mat3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
        }
    }
    return mat3;
}

template<typename tip>
Matrica<tip> ProduktMatrica(const Matrica<tip> &mat1, const Matrica<tip> &mat2)
{
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<tip>(mat1.br_redova, mat2.br_kolona));
    for(int i(0); i<mat1.br_redova; i++)
    {
        for(int j(0); j<mat2.br_kolona; j++)
        {
            mat3.elementi[i][j]=0;
        }
    }
    for(int i(0); i<mat1.br_redova; i++)
    {
        for(int j(0); j<mat1.br_kolona; j++)
        {
            for(int k(0); k<mat2.br_kolona; k++)
            {
                mat3.elementi[i][k]+=mat1.elementi[i][j]*mat2.elementi[j][k];
            }
        }
    }
    
    return mat3;
}

template<typename tip>
Matrica<tip> Stepen(const Matrica<tip> &m, int k)
{
    std::vector<std::vector<tip>> matrica(m.br_redova, std::vector<tip>(m.br_kolona));
   
    for(int i(0); i<m.br_redova; i++)
    {
        for(int j(0); j<m.br_kolona; j++)
        {
            matrica[i][j]=m.elementi[i][j];
        }
    }
   
    for(int i(1); i<k; i++)
    { 
        Matrica<tip> finalna(StvoriMatricu<tip>(m.br_redova,m.br_kolona));
        
        for(int j(0); j<m.br_redova; j++)
        {
            for(int p(0); p<m.br_kolona; p++)
            {
                finalna.elementi[j][p]=matrica[j][p];
            }
        }
        Matrica<tip> rez(ProduktMatrica<tip>(finalna,m));
        for(int j(0); j<m.br_redova; j++)
        {
            for(int p(0); p<m.br_kolona; p++)
            {
                matrica[j][p]=rez.elementi[j][p];
            }
        }
        UnistiMatricu(finalna);
        UnistiMatricu(rez);
    }
    Matrica<tip> finalna(StvoriMatricu<tip>(m.br_redova,m.br_kolona));
    for(int i(0); i<m.br_redova; i++)
    {
        for(int j(0); j<m.br_kolona; j++)
        {
            finalna.elementi[i][j]=matrica[i][j];
        }
    }
    return finalna;
}

template<typename tip>
Matrica<tip> MatricniPolinom(const Matrica<tip> &mat, std::vector<double> v)
{
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    if(v.size()==0)
    {
        auto finalna(StvoriMatricu<tip>(mat.br_redova,mat.br_kolona));
        for(int i(0); i<mat.br_redova; i++)
        {
            for(int j(0); j<mat.br_kolona; j++)
            {
                finalna.elementi[i][j]=0;
            }
        }
        return finalna;
    }
    std::vector<std::vector<tip>> matrica(mat.br_redova,std::vector<tip>(mat.br_kolona));
    for(int i(0); i<mat.br_redova; i++)
    {
        for(int j(0); j<mat.br_kolona; j++)
        {
            if(i==j) matrica[i][j]=v[0];
            else matrica[i][j]=0;
        }
    }
    
    for(int i(1); i<v.size(); i++)
    {
        double koef(v[i]);
        auto pom(Stepen(mat,i));
        auto rez(StvoriMatricu<tip>(mat.br_redova,mat.br_kolona));
        for(int j(0); j<mat.br_redova; j++)
        {
            for(int k(0); k<mat.br_kolona; k++)
            {
                rez.elementi[j][k]=koef*pom.elementi[j][k];
            }
        }
        auto temp(StvoriMatricu<tip>(mat.br_redova,mat.br_kolona));
        
        for(int j(0); j<mat.br_redova; j++)
        {
            for(int k(0); k<mat.br_kolona; k++)
            {
                temp.elementi[j][k]=matrica[j][k];
            }
        }
        auto suma(ZbirMatrica(temp,rez));
        
        for(int j(0); j<mat.br_redova; j++)
        {
            for(int k(0); k<mat.br_kolona; k++)
            {
                matrica[j][k]=suma.elementi[j][k];
            }
        }
        UnistiMatricu(pom);
        UnistiMatricu(temp);
        UnistiMatricu(suma);
        UnistiMatricu(rez);
    }
    Matrica<tip> finalna(StvoriMatricu<tip>(mat.br_redova,mat.br_kolona));
    
    for(int i(0); i<mat.br_redova; i++)
    {
        for(int j(0); j<mat.br_kolona; j++)
        {
            finalna.elementi[i][j]=matrica[i][j];
        }
    }
    
    return finalna;
}

int main ()
{
    Matrica<double> a,c;
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    //try
    //{
        a=StvoriMatricu<double>(n,n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> v(red+1);
        for(int i(0); i<red+1; i++)
        {
            std::cin >> v[i];
        }
        IspisiMatricu(c=MatricniPolinom(a,v),10,6);
    //}
    //catch(std::bad_alloc)
    //{
      //  std::cout << "Nema dovoljno memorije!\n";
    //}
    UnistiMatricu(a); 
    UnistiMatricu(c);
	return 0;
}
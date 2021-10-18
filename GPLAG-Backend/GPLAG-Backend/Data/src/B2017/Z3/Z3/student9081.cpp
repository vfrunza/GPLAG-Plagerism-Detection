/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <new>
#include <vector>

template <typename Tip>
struct Matrica {
    int red,kolona;
    Tip **pok=nullptr;
};

template <typename Tip>
void UnistiMatricu (Matrica<Tip> mat)
{
    if (!mat.pok) return;
    for (int i=0;i<mat.red;i++) delete [] mat.pok[i];
    delete [] mat.pok;
    mat.pok=nullptr;
}
template <typename Tip>
Matrica<Tip> StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica<Tip> mat;
    mat.red=br_redova; mat.kolona=br_kolona;
    mat.pok=new Tip* [br_redova]{};
    try
    {
        for (int i=0;i<br_redova;i++)
        mat.pok[i]=new Tip [br_kolona];
    }
    catch(std::bad_alloc)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename Tip>
void UnesiMatricu (char ime, Matrica<Tip> &mat)
{
    for (int i=0;i<mat.red;i++)
    {
        for (int j=0;j<mat.kolona;j++) {
        std::cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>mat.pok[i][j];
        }
    }
}
template <typename Tip>
void IspisiMatricu (const Matrica<Tip> &mat,int sirina, int preciznost=6, bool treba_brisati=false)
{
    for (int i=0;i<mat.red;i++)
    {
        for (int j=0;j<mat.kolona;j++)
            std::cout<<std::setw(sirina)<<std::setprecision(preciznost)<<mat.pok[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati)
    UnistiMatricu(mat);
}
template <typename Tip>
Matrica<Tip> ZbirMatrica (const Matrica<Tip> &mat1, const Matrica<Tip> &mat2)
{
    if (mat1.red!=mat2.red || mat1.kolona!=mat2.kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto mat3(StvoriMatricu<Tip>(mat1.red,mat1.kolona));
    for (int i=0;i<mat2.red;i++)
    {
        for (int j=0;j<mat2.kolona;j++)
        mat3.pok[i][j]=mat1.pok[i][j]+mat2.pok[i][j];
    }
    return mat3;
}
template <typename Tip>
Matrica<Tip> ProduktMatrica (const Matrica<Tip> &mat1, const Matrica<Tip> &mat2)
{
    if (mat1.kolona!=mat2.red)
        throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<int>(mat1.red,mat2.kolona));
    for (int i=0;i<mat1.red;i++)
    {
        for (int j=0;j<mat2.kolona;j++)
        {
            mat3.pok[i][j]=0;
            for (int k=0;k<mat1.kolona;k++)
            mat3.pok[i][j]+=mat1.pok[i][k]*mat2.pok[k][j];
        }
    }
    return mat3;
}
template <typename Tip, typename IterPok>
Matrica<Tip> MatricniPolinom (Matrica<Tip> mat, int n, IterPok poc)
{
    if (n<0)
        throw std::domain_error ("Neispravan stepen polinoma");
    if (mat.red!=mat.kolona)
        throw std::domain_error ("Matrica mora biti kvadratna");
    Matrica<Tip> jedinicna,cuvaj,temp,temp2;
    try {
    jedinicna=StvoriMatricu<Tip>(mat.red,mat.kolona);
    for (int i=0;i<mat.red;i++)
    {
        for (int j=0;j<mat.kolona;j++)
        {
            if (i==j)
            jedinicna.pok[i][j]=*poc*1;
            else
            jedinicna.pok[i][j]=0;
        }
    }
    poc++;
    if (n==0)
    return jedinicna;
    temp=StvoriMatricu<Tip>(mat.red,mat.kolona);
    for (int i=0;i<mat.red;i++)
    {
        for (int j=0;j<mat.kolona;j++)
            temp.pok[i][j]=mat.pok[i][j];
    }
    cuvaj=StvoriMatricu<Tip>(mat.red,mat.kolona);
    for (int i=0;i<mat.red;i++)
    {
        for (int j=0;j<mat.kolona;j++)
            cuvaj.pok[i][j]=*poc*mat.pok[i][j];
    }
    poc++;
    temp2=ZbirMatrica(cuvaj,jedinicna);
    }
    catch(std::bad_alloc)
    {
        UnistiMatricu(jedinicna);
        UnistiMatricu(temp);
        UnistiMatricu(cuvaj);
        UnistiMatricu(temp2);
        throw;
    }
    UnistiMatricu(jedinicna);
    UnistiMatricu(cuvaj);
    for (int i=1;i<n;i++)
    {
        Matrica<Tip> pom,pom2,cuvaj2;
        try {
        pom=temp;
        temp=ProduktMatrica(temp,mat);
        cuvaj2=StvoriMatricu<int>(mat.red,mat.kolona);
        for (int j=0;j<cuvaj2.red;j++)
        {
            for (int k=0;k<cuvaj2.kolona;k++)
                cuvaj2.pok[j][k]=*poc*temp.pok[j][k];
        }
        UnistiMatricu(pom);
        poc++;
        pom2=temp2;
        temp2=ZbirMatrica(cuvaj2,temp2);
        UnistiMatricu(pom2);
        UnistiMatricu(cuvaj2);}
        catch (std::bad_alloc)
        {
            UnistiMatricu(pom);
            UnistiMatricu(pom2);
            UnistiMatricu(temp);
            UnistiMatricu(temp2);
            UnistiMatricu(cuvaj2);
            throw;
        }
    }
    UnistiMatricu(temp);
    return temp2;
}
int main ()
{
    int n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    Matrica<int> mat,pol;
    try 
    {
        mat=StvoriMatricu<int>(n,n);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',mat);
        int x;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>x;
        std::vector<int> v(x+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for (int i=0;i<x+1;i++)
            std::cin>>v[i];
        pol=MatricniPolinom(mat,x,v.begin());
        IspisiMatricu(pol,10);
    }
    catch (std::domain_error izuz)
    {
        std::cout<<izuz.what()<<std::endl;
    }
    catch (std::bad_alloc)
    {
        std::cout<<"Nema dovoljno memorije!\n"<<std::endl;
    }
    UnistiMatricu(mat);
    UnistiMatricu(pol);
	return 0;
}

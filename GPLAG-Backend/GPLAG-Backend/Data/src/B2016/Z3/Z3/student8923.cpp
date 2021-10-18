/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <new>
#include <stdexcept>
#include <cmath>
using std::cout;
using std::cin;
using std::vector;
template <typename Tip>
struct Matrica
{
    int br_redova,br_kolona;
    Tip **elementi=nullptr;
};
template <typename Tip>
Matrica<Tip> StvoriMatricu(int br_redova,int br_kolona)
{
    try
    {
    Matrica<Tip> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new Tip*[br_redova];
    for(int i=0;i<br_redova;i++)
    mat.elementi[i]=nullptr;
    try
    {
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]=new Tip[br_kolona];
    }
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
    }
    catch(...)
    {
        throw;
    }
   // return mat;
}
template <typename Tip>
void UnistiMatricu(Matrica<Tip> mat)
{
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++)
    delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename Tip>
void UnesiMatricu(char ime,Matrica<Tip> &mat)
{
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
    }
}
template <typename Tip>
void IspisiMatricu(const Matrica<Tip> &mat,int sirina,int preciznost=6,bool treba_brisati=false)
{
for(int i=0; i<mat.br_redova; i++) 
{
    for(int j=0; j<mat.br_kolona; j++)
    {
    cout<<std::setw(sirina)<<std::setprecision(preciznost)<<mat.elementi[i][j];
    }
 cout << std::endl;
 }
if(treba_brisati)
{
    UnistiMatricu(mat);
}
else
return;
}
template <typename Tip>
Matrica<Tip> ZbirMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2) 
{
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<Tip>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
}
template <typename Tip>
bool SaglasneZaMnozenje(const Matrica<Tip> &mat1,const Matrica<Tip> &mat2)
{
    if(mat1.br_kolona==mat2.br_redova)
    return true;
    return false;
}
template <typename Tip>
Matrica<Tip> ProduktMatrica(const Matrica<Tip> &mat1,const Matrica<Tip> &mat2)
{
    if(!SaglasneZaMnozenje(mat1,mat2))
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<Tip>(mat1.br_redova,mat2.br_kolona));
    if(mat3.br_redova==0 || mat3.br_kolona==0)
    return mat3;
    for(int i=0;i<mat1.br_redova;i++)
    {
        for(int j=0;j<mat2.br_kolona;j++)
        {
          //  Tip suma=Tip();
           Tip suma=0;
            for(int k=0;k<mat2.br_redova;k++)
            suma+=(mat1.elementi[i][k]*mat2.elementi[k][j]);
            mat3.elementi[i][j]=suma;
        }
    }
    return mat3;
}
template <typename Tip>
Matrica<Tip> JedinicnaMatrica(const Matrica<Tip> &mat)
{
    auto mat2(StvoriMatricu<Tip>(mat.br_redova,mat.br_kolona));
    for(int i=0;i<mat2.br_redova;i++)
    {
        for(int j=0;j<mat2.br_kolona;j++)
        {
            if(i==j)
            mat2.elementi[i][j]=1;
            else
            mat2.elementi[i][j]=0;
        }
    }
    return mat2;
}
template <typename Tip,typename Tipkoef>
Matrica<Tip> PomnoziMatricuKoeficijentom(const Matrica<Tip> &mat,Tipkoef koef)
{
    auto mat2(StvoriMatricu<Tip>(mat.br_redova,mat.br_kolona));
    for(int i=0;i<mat2.br_redova;i++)
    {
        for(int j=0;j<mat2.br_kolona;j++)
        {
            mat2.elementi[i][j]=koef*mat.elementi[i][j];
        }
    }
    return mat2;
}
template <typename Tip>
void pomfja(const Matrica<Tip> &mat,Tip **elem)
{
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            elem[i][j]=mat.elementi[i][j];
        }
    }
}
template <typename Tip>
Matrica<Tip> MatricniPolinom(const Matrica<Tip> &mat,vector<double> vek)
{
    if(mat.br_redova!=mat.br_kolona)
    throw std::domain_error("Matrica mora biti kvadratna");
    bool nulvektor(true);
    for(int i=0;i<vek.size();i++)
    {
        if(std::fabs(vek[i])>0.0000000001)
        {
            nulvektor=false;
            break;
        }
    }
   // Matrica<Tip> konacna,jedinicna,pom;
try
{
    auto konacna=StvoriMatricu<Tip>(mat.br_redova,mat.br_kolona);
        for(int i=0;i<konacna.br_redova;i++)
        for(int j=0;j<konacna.br_kolona;j++)
        konacna.elementi[i][j]=0;
    if(nulvektor)
    {
        return konacna;
    }
    for(int i=0;i<vek.size();i++)
    {
        if(i==0)
        {
           try
           {
             Matrica<Tip> jedinicna;
             jedinicna=JedinicnaMatrica<Tip>(mat);
              try
              {
           Matrica<Tip> pom;
          Matrica<Tip> pom2;
            pomfja(pom2=ZbirMatrica(konacna,pom=PomnoziMatricuKoeficijentom(jedinicna,vek[i])),konacna.elementi);
            UnistiMatricu(pom);
            UnistiMatricu(jedinicna);
            UnistiMatricu(pom2);
              }
              catch(...)
               {
               UnistiMatricu(konacna);
               UnistiMatricu(jedinicna);
             //  UnistiMatricu(pom);
               throw;
              }
           }
           catch(...)
           {
               UnistiMatricu(konacna);
             //  UnistiMatricu(jedinicna);
               throw;
           }
        }
        else if(i==1)
        {
            try
            {
          Matrica<Tip> pom;
          //  pom=PomnoziMatricuKoeficijentom(mat,vek[i]);
            try
            {
           Matrica<Tip> pom2;
            pomfja(pom2=ZbirMatrica(konacna,pom=PomnoziMatricuKoeficijentom(mat,vek[i])),konacna.elementi);
            UnistiMatricu(pom);
            UnistiMatricu(pom2);
            }
            catch(...)
            {
                UnistiMatricu(konacna);
                
                UnistiMatricu(pom);
                throw;
            }
            }
            catch(...)
            {
                UnistiMatricu(konacna);
              //  UnistiMatricu(pom);
                throw;
            }
        }
        else
        {
            try
            {
            auto matmnoz(StvoriMatricu<Tip>(mat.br_redova,mat.br_kolona));
            pomfja<Tip>(mat,matmnoz.elementi);
            for(int j=1;j<i;j++)
            {
            Matrica<Tip> konacna1;
            pomfja(konacna1=ProduktMatrica<Tip>(matmnoz,mat),matmnoz.elementi);
            UnistiMatricu(konacna1);
            }
           Matrica<Tip> konacna1;
            pomfja(konacna1=PomnoziMatricuKoeficijentom<Tip>(matmnoz,vek[i]),matmnoz.elementi);
          Matrica<Tip> konacna2;
            pomfja(konacna2=ZbirMatrica<Tip>(konacna,matmnoz),konacna.elementi);
            UnistiMatricu(matmnoz);
            UnistiMatricu(konacna1);
            UnistiMatricu(konacna2);
            }
            catch(...)
            {
                UnistiMatricu(konacna);
              //  UnistiMatricu(matmnoz);
                throw;
            }
        }
    }
    return konacna;
}
catch(...)
{
  //  UnistiMatricu(konacna);
    throw;
}
 //   return konacna;
}
int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int dim;
    cin>>dim;
    Matrica<double> a;
    try
    {
        a=StvoriMatricu<double>(dim,dim);
        cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',a);
        cout<<"Unesite red polinoma: ";
        int red;
        cin>>red;
        cout<<"Unesite koeficijente polinoma: ";
        vector<double> vek;
        for(int i=0;i<=red;i++)
        {
            double pom;
            cin>>pom;
            vek.push_back(pom);
        }
     IspisiMatricu(MatricniPolinom(a,vek),10,6,true);
     //IspisiMatricu(PomnoziMatricuKoeficijentom(a,2.2),10,6,true);
    }
     catch(std::bad_alloc) 
     {
     cout << "Nema dovoljno memorije!\n";
     }
    UnistiMatricu(a);
	return 0;
}
/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<vector>
#include<new>
using namespace std;
template<typename Tip>

struct Matrica
{
    int br_redova, br_kolona;
    Tip **elementi=nullptr;
};
template<typename Tip>
void UnistiMatricu(Matrica<Tip> mat)
{
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++)
    delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}



template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
 Matrica<TipElemenata> mat;
 mat.br_redova = br_redova; mat.br_kolona = br_kolona;
 mat.elementi = new TipElemenata*[br_redova];
 for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
 try {
 for(int i = 0; i < br_redova; i++)
 mat.elementi[i] = new TipElemenata[br_kolona];
 }
 catch(...) {
 UnistiMatricu(mat);
 throw;
 }
 return mat;}
template<typename Tip>
Matrica<Tip> ProduktMatrica( const Matrica <Tip> &mat1,  const Matrica<Tip> &mat2)
{
 if(mat1.br_kolona!=mat2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje!");   
Matrica<Tip> nova(StvoriMatricu<Tip>(mat1.br_redova, mat2.br_kolona));
    for(int i=0;i<mat1.br_redova;i++)
    {
        for(int j=0;j<mat2.br_kolona;j++)
        {
            Tip suma(0);
            for(int k=0;k<mat2.br_redova;k++)
            {
                suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
            }
            nova.elementi[i][j]=suma;
        }
    }
    
    return nova;
    

    
}

template<typename Tip>

void IspisiMatricu(const Matrica<Tip> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
        }    cout<<endl;
        
    }
    if(treba_brisati)
    UnistiMatricu(mat);
}
template<typename Tip>
Matrica<Tip> MnoziSkalarom( const Matrica<Tip> &A, double skalar)
{
    Matrica<Tip>Nova(StvoriMatricu<Tip>(A.br_redova, A.br_kolona));
    for(int i=0;i<A.br_redova;i++)
    {
        for(int j=0;j<A.br_kolona;j++)
        Nova.elementi[i][j]=A.elementi[i][j]*skalar;
    }
   
    return Nova;
}
template<typename Tip>
Matrica<Tip> SaberiMatricu(const  Matrica<Tip> &A, const Matrica<Tip> &B)
{
    if(A.br_redova!=B.br_redova || B.br_kolona!=A.br_kolona) throw domain_error("Matrice se ne mogu sabirati!");
    Matrica<Tip> nova(StvoriMatricu<Tip>(A.br_redova, A.br_kolona));
    for(int i=0;i<A.br_redova;i++)
    {
        for(int j=0;j<A.br_kolona;j++)
        {
            nova.elementi[i][j]=A.elementi[i][j]+B.elementi[i][j];
        }
        
    }
    
    return nova;
}


template<typename Tip>
void UnesiMatricu(char ime_matrice, Matrica<Tip> &mat)
{
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
            
        }
        
    }
}


template<typename Tip>
 Matrica<Tip> MatricniPolinom( Matrica<Tip> &A, vector<double>Koeficijenti)
 {
     if(A.br_redova!=A.br_kolona) throw domain_error ("Matrica mora biti kvadratna!");
     Matrica<Tip> rezultat(StvoriMatricu<Tip>(A.br_redova, A.br_kolona));
     
     if(Koeficijenti.empty())
     {
         for(int i=0;i<A.br_redova;i++)
         {
             for(int j=0;j<A.br_kolona;j++)
             rezultat.elementi[i][j]=0;
             return rezultat;
         } }
                  auto prva_pomocna(StvoriMatricu<Tip>(A.br_redova, A.br_kolona));

         for(int i=0;i<A.br_redova;i++)
         {
             for(int j=0;j<A.br_kolona;j++)
             {
                 if(i==j) rezultat.elementi[i][j]=1*Koeficijenti[0];
                 else rezultat.elementi[i][j]=0*Koeficijenti[0];
             }
         }
         for(int i=0;i<A.br_redova;i++)
         {
             for(int j=0;j<A.br_kolona;j++)
             {
       prva_pomocna.elementi[i][j]=A.elementi[i][j];                 
             }
         }
         for(int brojac(1);brojac<Koeficijenti.size();brojac++)
         {
             if(brojac!=1)
             {
                 auto nova(StvoriMatricu<Tip>(A.br_redova, A.br_kolona));
                 for(int i=0;i<A.br_redova;i++)
                 {
                     for(int j=0;j<A.br_kolona;j++)
                     {
                         nova.elementi[i][j]=prva_pomocna.elementi[i][j];
                     }}    UnistiMatricu(prva_pomocna);
                         prva_pomocna=ProduktMatrica(nova, A);
                         UnistiMatricu(nova);
                     
                     
                 }
                 auto ponovno(StvoriMatricu<Tip>(A.br_redova, A.br_kolona));
                 for(int i=0;i<A.br_redova;i++)
                 {
                     for(int j=0;j<A.br_kolona;j++)
                     {
                         ponovno.elementi[i][j]=Koeficijenti[brojac]*prva_pomocna.elementi[i][j];
                        
                     }
                 }
        {         auto DajOpet(StvoriMatricu<Tip>(A.br_redova, A.br_kolona));
        for(int i=0;i<A.br_redova;i++)
        {
            for(int j=0;j<A.br_kolona;j++)
            DajOpet.elementi[i][j]=rezultat.elementi[i][j];
        }
        UnistiMatricu(rezultat);
        rezultat=SaberiMatricu(DajOpet, ponovno);
        UnistiMatricu(DajOpet);
             }
             UnistiMatricu(ponovno);
         }
         UnistiMatricu(prva_pomocna);
         return rezultat;
     }
    
    
int main ()
{
	int dimenzija;
	cout<<"Unesite dimenziju kvadratne matrice: ";
	cin>>dimenzija;
	Matrica<double> mat, nova;
	vector<double> koeficijenti;
	cout<<"Unesite elemente matrice A: "<<endl;
	int red;
try{
mat=StvoriMatricu<double>(dimenzija, dimenzija);
	
	UnesiMatricu('A', mat);
cin.clear();
cin.ignore(1000,'\n');
	cout<<"Unesite red polinoma: ";
	
	cin>>red;
	
	cout<<"Unesite koeficijente polinoma: ";
	for(int i=0;i<=red;i++)
	{
	    double koef;
	    cin>>koef;
	    koeficijenti.push_back(koef);
	}
	
	IspisiMatricu(nova=MatricniPolinom(mat, koeficijenti), 10, 6);


}
catch(bad_alloc)
{
    cout<<"Poruka: Greska"<<endl;
}
    UnistiMatricu(nova);
	UnistiMatricu(mat); 
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <iomanip>
#include <new>
#include <stdexcept>

using namespace std;

template <typename TipElemenata>   
struct Matrica 
{     
    int br_redova, br_kolona;     
    TipElemenata **elementi = nullptr;
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
    try 
    {       
        for(int i = 0; i < br_redova; i++)          
            mat.elementi[i] = new TipElemenata[br_kolona];       
        
    }      
    catch(...) {       
        UnistiMatricu(mat);        
        throw;     
        
    }     
    return mat;   
    
}




template <typename TipElemenata>   
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) 
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
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=0)
{       
    for(int i = 0; i < mat.br_redova; i++) 
    {         
        for(int j = 0; j < mat.br_kolona; j++)            
        cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<right<<mat.elementi[i][j];          
        cout<<endl;
        
        
    }  
    if(treba_brisati==1) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
     if(mat2.br_redova!=mat1.br_kolona) throw domain_error("Matrice nisu saglasne za mnozenje!");
     auto r=StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona);
     for(int i=0; i<mat1.br_redova; i++)
        for(int j=0; j<mat2.br_kolona; j++)
            r.elementi[i][j]=0;
     for(int i=0; i<mat1.br_redova; i++)
     {
          for(int j=0; j<mat2.br_kolona; j++)
          {
               for(int k=0; k<mat2.br_redova; k++)
                    r.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];
          }
     }
     return r;
}

template<typename TipElemenata, typename tp>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int n, tp pok)
{
     if(A.br_kolona!=A.br_redova)throw domain_error("Matrica mora biti kvadratna!");
     try {
          auto prva=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
           for(int i=0; i<A.br_redova; i++)
             for(int j=0; j<A.br_kolona; j++)
                 if(i==j) prva.elementi[i][j]=1;
                 else prva.elementi[i][j]=0;
          for(int i=0; i<prva.br_redova; i++)
               for(int j=0; j<prva.br_kolona; j++) prva.elementi[i][j]*=(*pok);
          pok++;
          try{
               Matrica<TipElemenata> pom=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
               for(int i=0; i<A.br_redova; i++)
                    for(int j=0; j<A.br_kolona; j++) pom.elementi[i][j]=A.elementi[i][j];
               try{
                    Matrica<TipElemenata> A1=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
                    for(int i=0; i<A.br_redova; i++)
                         for(int j=0; j<A.br_kolona; j++) A1.elementi[i][j]=A.elementi[i][j];
                         
                    for(int i=0; i<n; i++)
                    {
                         Matrica<TipElemenata> pom1=StvoriMatricu<TipElemenata>(pom.br_redova, pom.br_kolona);
                         for(int i=0; i<pom.br_redova; i++)
                              for(int j=0; j<pom.br_kolona; j++) pom1.elementi[i][j]=(*pok)*pom.elementi[i][j];
                         auto pom3=ProduktMatrica<TipElemenata>(pom,A1);
                         UnistiMatricu(pom);
                         pom=pom3;
                         pom3.elementi=0;
                         auto pom2=ZbirMatrica<TipElemenata>(prva,pom1);
                         UnistiMatricu(prva);
                         prva=pom2;
                         pom2.elementi=0;
                         UnistiMatricu(pom1);
                         pok++;
                    }
                    UnistiMatricu(A1);
                    UnistiMatricu(pom);
                    return prva;
               } catch(...) {UnistiMatricu(pom);UnistiMatricu(prva);throw;}
          } catch(...) {UnistiMatricu(prva);throw;}
     } catch(...) {throw;}
     
}

template <typename TipElemenata>   
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) 
{     
    for(int i = 0; i < mat.br_redova; i++)       
    for(int j = 0; j < mat.br_kolona; j++) 
    {         
        std::cout<<ime_matrice<<"("<< i + 1 << "," << j + 1 << ") = ";          
        std::cin >> mat.elementi[i][j];        
        
    }    
    
}

int main ()
{
	cout<<"Unesite dimenziju kvadratne matrice: ";
	try{
	     int n; 
	     cin>>n;
	     auto mat=StvoriMatricu<int>(n,n);
	     cout<<"Unesite elemente matrice A: "<<endl;
	     UnesiMatricu('A',mat);
	     cout<<"Unesite red polinoma: ";
	     int r; cin>>r;
	     vector<int> v(r+1);
	     cout<<"Unesite koeficijente polinoma: ";
	     for(int i=0; i<r+1; i++) cin>>v[i];
	     try{
	          auto rez=MatricniPolinom<int>(mat,r,v.begin());
	          IspisiMatricu(rez,10);
	         UnistiMatricu(mat);
	         UnistiMatricu(rez);
	     } catch(...) {UnistiMatricu(mat);throw;}
	}
	catch(domain_error iz) { cout<<"Izuzetak: "<<iz.what();}
	catch(...) {}

	return 0;
}

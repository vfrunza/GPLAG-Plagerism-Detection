#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using namespace std;
template <typename TipElemenata>
 struct Matrica {
 int br_redova, br_kolona;
 TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
 if(!mat.elementi) return;
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi = nullptr;
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
 return mat;
 }
template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
 for(int i = 0; i < mat.br_redova; i++)
 for(int j = 0; j < mat.br_kolona; j++) {
 std::cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) <<setprecision(preciznost)<< mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati)UnistiMatricu(mat);
 }

template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> mat1, Matrica<TipElemenata> mat2)
 {
     TipElemenata suma;
     try
     {
     Matrica<TipElemenata>mat=StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona);
     for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++)
        mat.elementi[i][j]=0;
    if(mat1.br_kolona!=mat2.br_redova)throw domain_error("Matrice nisu saglasne za mnozenje");
    for(int i=0;i<mat1.br_redova;i++){
        for(int k=0;k<mat2.br_kolona;k++){
            suma=0;
            for(int j=0;j<mat2.br_redova;j++){
                suma+=(mat1.elementi[i][j]*mat2.elementi[j][k]);
            }
            mat.elementi[i][k]=suma;
        }
    }
    return mat;
    }
     catch(bad_alloc)
     {
         cout<<"Problemi sa memorijom!";
         throw;
     }
    
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, vector<double> pk)
 {
     
     if(A.br_redova!=A.br_kolona)throw domain_error("Matrica mora biti kvadratna");
    try
    {
     Matrica<TipElemenata> mat=StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
     if(pk.size()==0)
     {
          for(int i=0;i<A.br_redova;i++)
        for(int j=0;j<A.br_kolona;j++)
            mat.elementi[i][j]=0;
            return mat;
     }
     Matrica<TipElemenata> A1=StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
     for(int i=0;i<A1.br_redova;i++)
        for(int j=0;j<A1.br_kolona;j++)
        A1.elementi[i][j]=A.elementi[i][j];
    for(int i=0;i<A.br_redova;i++)
        for(int j=0;j<A.br_kolona;j++){
            if(i==j)A.elementi[i][j]=1;
            else 
            A.elementi[i][j]=0;
        }
            
        Matrica<TipElemenata> mat1=StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
       for(int i=0;i<A.br_redova;i++)
        for(int j=0;j<A.br_kolona;j++)
            mat1.elementi[i][j]=A1.elementi[i][j];
    
        
        for(int i=0;i<A.br_redova;i++)
        for(int j=0;j<A.br_kolona;j++)
            mat.elementi[i][j]=A1.elementi[i][j];
        
    for(int i=0;i<pk.size();i++)
    {
        double broj=pk[i];
        if(  i==0){
            for(int i=0;i<A.br_redova;i++)
                for(int j=0;j<A.br_kolona;j++)
                A.elementi[i][j]*=broj;
            }
        else if(i==1)
        {
            for(int i=0;i<A.br_redova;i++)
                for(int j=0;j<A.br_kolona;j++)
                mat1.elementi[i][j]*=broj;
                
            Matrica<TipElemenata>A3=ZbirMatrica(mat1,A);
            for(int i=0;i<A.br_redova;i++)
                for(int j=0;j<A.br_kolona;j++)
                A.elementi[i][j]=A3.elementi[i][j];
                UnistiMatricu(A3);
                
                
        }
        else if(i>1)
        {
        
            Matrica<TipElemenata>A2=ProduktMatrica(A1,mat);
            
            
            for(int i=0;i<mat.br_redova;i++)
                for(int j=0;j<mat.br_kolona;j++)
                
                    mat1.elementi[i][j]=A2.elementi[i][j]*broj;
            
                Matrica<TipElemenata>A3=ZbirMatrica(A,mat1);
                for(int i=0;i<A.br_redova;i++)
                for(int j=0;j<A.br_kolona;j++)
                A.elementi[i][j]=A3.elementi[i][j];
                UnistiMatricu(A3);
            
         for(int i=0;i<A.br_redova;i++)
                for(int j=0;j<A.br_kolona;j++)
                A1.elementi[i][j]=A2.elementi[i][j];   
                UnistiMatricu(A2);
        }
    }
    for(int i=0;i<A.br_redova;i++)
                for(int j=0;j<A.br_kolona;j++)
                mat.elementi[i][j]=A.elementi[i][j];
               UnistiMatricu(mat1);UnistiMatricu(A1);
    return mat;
     }
     catch(bad_alloc)
     {
         cout<<"Nedovoljno memorije";
         throw;
     }
 }
 
int main ()
{
    Matrica<double>a,c;
    int m,n;
    double v1;
    vector<double>v;
    cout<<"Unesite dimenziju kvadratne matrice: ",
    cin>>m;
    try
    {
        a=StvoriMatricu<double>(m,m);
        cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        cout<<"Unesite red polinoma: ";
        cin>>n;
        
        cout<<"Unesite koeficijente polinoma: ";
        if(n!=0)
        {
        for(int i=0;i<=n;i++)
        {
            cin>>v1;
            v.push_back(v1);
        }
        }
        IspisiMatricu(c=MatricniPolinom(a,v),10,6);
         UnistiMatricu(a); UnistiMatricu(c);
    }
    catch(domain_error Izuzetak)
    {
    cout<<Izuzetak.what()<<endl;
    UnistiMatricu(a);
    }
    catch(bad_alloc)
    {
        cout<<"Nema dovoljno memorije!\n";
    }
   
	return 0;
}
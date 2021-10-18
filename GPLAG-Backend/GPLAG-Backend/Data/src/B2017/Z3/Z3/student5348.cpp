#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <cmath>
#include <vector>

using namespace std;

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
             cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
             cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void UnesiPraznuMatricu(Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) 
           mat.elementi[i][j]=0;
           
}

template <typename TipElemenata>
void Jedinicna (Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++)
        if(i==j)  mat.elementi[i][j]=1;
          else mat.elementi[i][j]=0;
  
}


template <typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> &mat, int sirina_ispisa=6, int preciznost=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
             cout <<  setw(sirina_ispisa) << setprecision(preciznost) << mat.elementi[i][j];
         cout <<  endl;
    }
    if(treba_brisati==true)UnistiMatricu(mat);
    
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw  domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MnozenjeMatrice(const Matrica<TipElemenata> &m1, double n)
{
  
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    UnesiPraznuMatricu(m3);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j]*n;
        
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_kolona)throw  domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    UnesiPraznuMatricu(m3);
     for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
       for(int k = 0; k < m1.br_kolona; k++)
       m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
    
    return m3;
}



template <typename TipElemenata,typename Iter>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, int n,Iter it){
    
    if(n<0) throw  domain_error("Neispravan stepen polinoma");
    if(m1.br_kolona!=m1.br_redova) throw  domain_error("Matrica mora biti kvadratna");
    

    
    Matrica<TipElemenata> suma;
    suma = StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    UnesiPraznuMatricu(suma);
    
    
    
    Matrica<TipElemenata> m3;
    m3=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    Jedinicna(m3);
    
     Matrica<TipElemenata>a;
     a = StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);UnesiPraznuMatricu(a);
    
    
   
    for(int i=0;i<=n;i++){
        
        
        
        double x=*it;
        
        
        auto l1=m3;
        auto l2=a;
        auto l3=suma;
        
        a=MnozenjeMatrice(m3,x); 
        suma=ZbirMatrica(l3,a);
        m3=ProduktMatrica(l1,m1);
       
        UnistiMatricu(l3);
        UnistiMatricu(l2);
        UnistiMatricu(l1);
        
        it++;
       
    }
    
  UnistiMatricu(m3);
  UnistiMatricu(a);
    
    
    return suma;
    
}


int main()
{
    Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m, n;
    
     cout << "Unesite dimenziju kvadratne matrice: ";
     cin >> m;
     vector<double> niz;
    try {
        a = c=StvoriMatricu<double>(m, m);
        
         cout << "Unesite elemente matrice A:";
         cout<<endl;
        UnesiMatricu('A', a);
        
         cout << "Unesite red polinoma: ";
         cin>>n;
         cout << "Unesite koeficijente polinoma: ";
            for(int i=0;i<=n;i++){
                double x;
                 cin>>x;
                niz.push_back(x);
            }
            
         //IspisiMatricu(MatricniPolinom(a,n,niz),10,6,false);  
         
         c=MatricniPolinom(a,n,niz.begin());  
         IspisiMatricu(c,10);
         
          

       
    } catch( bad_alloc) {
         cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
    return 0;
}
//2  2*2 mat
//1 2  prve vr
//3 4 druge v3
//1 red polinoma
//1 2   koef polinoma
//2 1 2 3 4 1 1 2 

//test
//2
//3 0
//1 -2
//3 
//3 -2 0 1
//2 3 1 0 -2 3 3 -2 0 1

//2
//4 3
//2 1
//3
//4 3 2 1

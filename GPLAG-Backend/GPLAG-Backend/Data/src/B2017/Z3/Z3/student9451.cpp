/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

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
            
        for(int i=0;i<br_redova;i++)
            for(int j=0;j<br_kolona;j++)
                mat.elementi[i][j]=0;
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
                   int sirina_ispisa,int preciznost,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout<<setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
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

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> a,Matrica<TipElemenata> b)
{   
    if(a.br_redova!=b.br_kolona) throw domain_error("Matrice nisu saglasne za mnozenje!");
    Matrica<TipElemenata> mat=StvoriMatricu<TipElemenata>(a.br_redova,b.br_kolona);
    
    for(int i=0;i<a.br_redova;i++)
    {
        for(int j=0;j<b.br_kolona;j++)
        {   int suma=0;
            for(int k=0;k<a.br_kolona;k++)
            {
                suma+=a.elementi[i][k]*b.elementi[k][j];
            }
            mat.elementi[i][j]=suma;
        }
    }
    return mat;
}   

template<typename TipElemenata>
Matrica<TipElemenata> PomnoziSkalarom(Matrica<TipElemenata>a,TipElemenata n)
{   
    Matrica<TipElemenata> mat=StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona);
    for(int i=0;i<a.br_redova;i++)
    {
        for(int j=0;j<a.br_kolona;j++)
            mat.elementi[i][j]=a.elementi[i][j]*n;
    }
    return mat;
}

template<typename TipElemenata>
Matrica<TipElemenata> StepenujMatricu(Matrica<TipElemenata>a,int n)
{   
    Matrica<TipElemenata> mat=StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona);
    Matrica<TipElemenata> p;
    for(int i=0;i<mat.br_kolona;i++) mat.elementi[i][i]=1;
    
    for(int i=1;i<=n;i++)
    {
        mat=ProduktMatrica(p=mat,a);
        UnistiMatricu(p);
    }
    return mat;
}

template<typename TipElemenata,typename Kont>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata>a,int n,Kont niz)
{   
    if(a.br_kolona!=a.br_redova)throw domain_error("Matrica mora biti kvadratna!");
    if(n<0) throw domain_error("Neispravan stepen polinoma!");
    Matrica<TipElemenata> p,q,r,t;
    Matrica<TipElemenata> mat=StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona);
    for(int i=0;i<a.br_redova;i++) 
    {   
        for(int j=0;j<a.br_kolona;j++)
             (i==j)?mat.elementi[i][j]=1:mat.elementi[i][j]=0;
    }
      mat=PomnoziSkalarom<TipElemenata>(r=mat,*niz);
      UnistiMatricu(r);
       niz++;
        
        
    
    for(int i=1;i<=n;i++,niz++){
        
         mat=t=ZbirMatrica(r=mat,p=PomnoziSkalarom<TipElemenata>(q=StepenujMatricu<TipElemenata>(a,i),*niz));
         
         UnistiMatricu(p);UnistiMatricu(q);UnistiMatricu(r);
    }   
    // p.elementi=nullptr;q.elementi=nullptr;r.elementi=nullptr;
     //UnistiMatricu(p);UnistiMatricu(q);UnistiMatricu(r);*/
    return mat;
}

int main()
{
    Matrica<double> a, b; // AUTOMATSKA INICIJALIZACIJA!!!
    int m, n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try
    {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        cin>>n;
        vector<int> v(n+1);
        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<v.size();i++) cin>>v[i];
        
        // IspisiMatricu(a,10);
         IspisiMatricu(b=MatricniPolinom(a,n,v.begin()),10,6);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    
    UnistiMatricu(a);
    UnistiMatricu(b);

    return 0;
}
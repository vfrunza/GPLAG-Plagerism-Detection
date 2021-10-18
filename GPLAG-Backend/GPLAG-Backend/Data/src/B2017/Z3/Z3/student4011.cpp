/B2017/2018: Zadaća 3, Zadatak 3
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
        {
            for(int j=0;j<br_kolona;j++)
                mat.elementi[i][j]=0;
        }
        
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

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_kolona) throw domain_error("Matrice nisu saglasne za mnozenje!");
    Matrica<TipElemenata> m=StvoriMatricu<TipElemenata>(m1.br_kolona,m2.br_redova);
    
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m2.br_kolona;j++)
        {
            for(int k=0;k<m1.br_kolona;k++)
            {
                m.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    
    return m;
}



template <typename TipElemenata>
Matrica<TipElemenata> PrekopirajMatricu(const Matrica<TipElemenata> &m1)
{
   Matrica<TipElemenata> m=StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_redova);
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
          m.elementi[i][j]=m1.elementi[i][j];
    return m;
}

template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSkalarom(const Matrica<TipElemenata> &m1, int n)
{
   Matrica<TipElemenata> m=StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_redova);
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
          m.elementi[i][j]=m1.elementi[i][j]*n;
    return m;
}

template <typename TipElemenata,typename Niz>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,int n,Niz kont)
{
    if(m1.br_redova!=m1.br_kolona) throw domain_error("Matrica mora biti kvadratna!");
    auto m=StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_redova);
    int br=0;
    while(br<m1.br_redova)
    {  
        m.elementi[br][br]=*kont;br++;
    }
    
    kont++;
    Matrica<TipElemenata> m2=PrekopirajMatricu(m1);
    Matrica<TipElemenata> m4=PrekopirajMatricu(m1);
    
   // IspisiMatricu(m2,4); cout<<endl; IspisiMatricu(m4,4); cout<<endl; IspisiMatricu(m,4); cout<<endl;
    
    for(int i=0;i<n;i++)
    {
        
        auto pom=PomnoziSkalarom<TipElemenata>(m2,*kont);
        auto pomm=ProduktMatrica<TipElemenata>(m2,m1);
        UnistiMatricu(m2);
        m2=pomm;
        pomm.elementi=nullptr;
            
        auto pom2=ZbirMatrica<TipElemenata>(m,pom);
       UnistiMatricu(m);
        m=pom2;
       pom2.elementi=nullptr;
       UnistiMatricu(pom);
        kont++;
        
    }
      UnistiMatricu(m2);
      UnistiMatricu(m4);
    return m; 
}

int main ()
{ 
    try{
        cout<<"Unesite dimenziju kvadratne matrice: ";
        int n;
        cin>>n;
        auto mat=StvoriMatricu<int>(n,n);
        cout<<"Unesite elemente matrice A: "<<endl;
        UnesiMatricu('A',mat);
        cout<<"Unesite red polinoma: ";
        int red; cin>>red;
        vector<int> v(red+1);
        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<v.size(); i++) cin>>v[i];
        try{
            auto mat1=MatricniPolinom<int>(mat,red,v.begin());
            IspisiMatricu(mat1,10);
            UnistiMatricu(mat);
            UnistiMatricu(mat1);
        } catch(domain_error e) { UnistiMatricu(mat);cout<<e.what(); throw;}
    }
    catch(...) {} 
    return 0;
}

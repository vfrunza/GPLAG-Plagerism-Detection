/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <stdexcept>
#include <vector> 

using namespace std;

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};

template <typename TipElemenata>
void Prekopiraj(Matrica<TipElemenata> &m,Matrica<TipElemenata> &&m1)
{ 
        for(int i=0;i<m.br_redova;i++)
        {
            for(int j=0;j<m.br_kolona;j++)
            {
                m.elementi[i][j]=m1.elementi[i][j];
            }
        }
    
    UnistiMatricu(m1);
    
}


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
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int pres=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa)<<setprecision(pres) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
       UnistiMatricu(mat); 
    
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> m1,const Matrica<TipElemenata> m2)
{
    if(m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    
    Matrica<TipElemenata> m=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++)
            for(int j=0;j<m2.br_kolona;j++)
                m.elementi[i][j]=0;
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
Matrica<TipElemenata> PomnoziSkalarom(const Matrica<TipElemenata> &m1,double n)
{  
    Matrica<TipElemenata> m=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m1.br_kolona;j++)
        {
            m.elementi[i][j]=m1.elementi[i][j]*n;
        }
    }
    return m;
}

template <typename TipElemenata>
Matrica<TipElemenata> JedinicnaMat(int brr)
{  
    Matrica<TipElemenata> m1=StvoriMatricu<TipElemenata>(brr,brr); 
    
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            if(i==j) m1.elementi[i][j]=1;
            else m1.elementi[i][j]=0;
    
    return m1;
    
}

template<typename TipElemenata>
Matrica<TipElemenata> StepenujMat(const Matrica<TipElemenata> &m1,int br)
{
    if(br==0)
        return JedinicnaMat<TipElemenata>(m1.br_redova);
    else if(br==1)
        return m1;
    else
    {
        Matrica<TipElemenata> m=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona); 
        m=m1;
        for(int i=2; i<=br; i++)
            Prekopiraj(m,ProduktMatrica(m,m1));
        return m;
    }
   
}


template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,vector<double> v)
{
    if(m1.br_redova!=m1.br_kolona) throw domain_error("Matrica nije kvadratna");
    
    Matrica<TipElemenata> m=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);//povratna 
    
    for(int i=0;i<m.br_redova;i++)
        for(int j=0;j<m.br_kolona;j++)
            m.elementi[i][j]=0;
        
        
        for(int i=0;i<v.size();i++)
        {   
            Matrica<TipElemenata> pom=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
            Prekopiraj(pom,StepenujMat(m1,i));
            Prekopiraj(pom,PomnoziSkalarom(pom,v[i]));
            Prekopiraj(m,ZbirMatrica(m,pom));
            //UnistiMatricu(pom);
        }
        
        
    return m;
    
}

int main()
{  
    
    Matrica<double> a ; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m ;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: "<<endl;
        UnesiMatricu('A', a);
        
        cout<<"Unesite red polinoma: ";
        cin>>m;
        vector<double> v(m+1);
        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<v.size();i++)
            cin>>v[i];
          
        IspisiMatricu(MatricniPolinom<double>(a,v),10,6,true); 
        UnistiMatricu(a);
        
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    
    
    return 0;
}

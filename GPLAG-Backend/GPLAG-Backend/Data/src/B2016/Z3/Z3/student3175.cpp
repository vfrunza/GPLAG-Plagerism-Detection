/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <functional>
#include <vector>
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
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) 
{     
    for(int i = 0; i < mat.br_redova; i++)       
    for(int j = 0; j < mat.br_kolona; j++) 
    {         
        std::cout<<ime_matrice<<"("<< i + 1 << "," << j + 1 << ") = ";          
        std::cin >> mat.elementi[i][j];        
        
    }    
    
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

template<typename TipElemenata>
void nanule(Matrica<TipElemenata> &m)
{
   for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            m.elementi[i][j]=0;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) 
{
    if(m2.br_redova!=m1.br_kolona) throw domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> rez=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    nanule(rez);
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m2.br_redova; k++)
                rez.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    return rez;
}

template<typename TipElemenata>
Matrica<TipElemenata> dajjedinicnu(int n)
{
    auto m=StvoriMatricu<TipElemenata>(n,n);
    for(int i=0; i<n; i++)
        for(int  j=0; j<n; j++)
            if(i==j) m.elementi[i][j]=1;
            else m.elementi[i][j]=0;
    return m;
}

template<typename TipElemenata>
Matrica<TipElemenata> pomnozi(int n,const Matrica<TipElemenata> &m)
{
    auto m1=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i=0;i<m.br_redova;i++)
        for(int j=0; j<m.br_kolona; j++)
            m1.elementi[i][j]=n*m.elementi[i][j];
    return m1;
}
template <typename TipElemenata>   
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{       
    for(int i = 0; i < mat.br_redova; i++) 
    {         
        for(int j = 0; j < mat.br_kolona; j++)            
        std::cout<<right<<setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];          
        std::cout << std::endl;        
        
    }    
    if(treba_brisati==true) UnistiMatricu(mat);
} 
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, vector<double> v)
{
    IspisiMatricu(m,6);
    if(m.br_redova!=m.br_kolona) throw domain_error("Matrica mora biti kvadratna");
    auto I=dajjedinicnu<TipElemenata>(m.br_kolona);
    auto i1=pomnozi(v[0],I);
    UnistiMatricu(I);
    for(int i=0; i<i1.br_redova; i++)
        for(int j=0; j<i1.br_kolona; j++)
            I.elementi[i][j]=i1.elementi[i][j];
    UnistiMatricu(i1);
    auto kopija=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            kopija.elementi[i][j]=m.elementi[i][j];
    for(int i=1; i<v.size(); i++)
    {
        if(i==1+v.size()-v.size())
        {
            auto p1=pomnozi(v[1],kopija);
            //IspisiMatricu(p1,6);
            auto i2=ZbirMatrica(p1,I);
            UnistiMatricu(I);
            UnistiMatricu(p1);
            I=StvoriMatricu<TipElemenata>(i2.br_redova, i2.br_kolona);
            for(int i=0; i<i2.br_kolona; i++)
                for(int j=0; j<i2.br_kolona; j++)
                    I.elementi[i][j]=i2.elementi[i][j];
            UnistiMatricu(i2);
        }
        else
        {
            auto p1=ProduktMatrica(kopija,m);
            auto p2=pomnozi(v[i],p1);
            UnistiMatricu(p1);
            auto i2=ZbirMatrica(I,p2);
            UnistiMatricu(I);
            UnistiMatricu(kopija);
            I=StvoriMatricu<TipElemenata>(i2.br_redova, i2.br_kolona);
            for(int i=0; i<i2.br_kolona; i++)
                for(int j=0; j<i2.br_kolona; j++)
                    I.elementi[i][j]=i2.elementi[i][j];
            UnistiMatricu(i2);
            kopija=StvoriMatricu<TipElemenata>(p1.br_kolona,p1.br_kolona);
            for(int i=0; i<p1.br_kolona; i++)
                for(int j=0; j<p1.br_kolona; j++)
                    kopija.elementi[i][j]=p1.elementi[i][j];
            UnistiMatricu(p1);
        }
    }
    UnistiMatricu(kopija);
    return I;
}



int main ()
{
	 Matrica<double> m1;
    m1 = StvoriMatricu<double>(2,2);
    UnesiMatricu<double>('A', m1);
    std::vector<double> v = {1, 2, 3, 4, 5};
    cout<<"ADDd";
    auto polinom = MatricniPolinom(m1, v);
    IspisiMatricu(polinom, 5);
    UnistiMatricu(polinom);
    UnistiMatricu(m1);
	return 0;
}
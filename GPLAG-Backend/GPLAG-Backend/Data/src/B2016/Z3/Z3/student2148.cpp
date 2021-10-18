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
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false) 
{       
    for(int i = 0; i < mat.br_redova; i++) 
    {         
        for(int j = 0; j < mat.br_kolona; j++)            
            std::cout << std::setw(sirina_ispisa)<<setprecision(preciznost) <<right<< mat.elementi[i][j];          
            std::cout << std::endl;        
        
    }    
    if(treba_brisati) UnistiMatricu(mat);
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) 
{
    if(m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++) m3.elementi[i][j]=0;
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m1.br_kolona; k++)
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> zbrojem(Matrica<TipElemenata> m, double n)
{
    auto m3(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            m3.elementi[i][j]=m.elementi[i][j]*n;
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, vector<double> v)
{
    if(m.br_kolona!=m.br_redova) throw domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> a=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            a.elementi[i][j]=m.elementi[i][j];
    Matrica<TipElemenata> e=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            if(i==j) e.elementi[i][j]=v[0];
            else e.elementi[i][j]=0;
    for(int i=1; i<v.size(); i++)
    {
        if(i==1)
        {
            auto pom=zbrojem(a,v[i]);
            auto e1=ZbirMatrica(e,pom);
            UnistiMatricu(e);
            e=StvoriMatricu<TipElemenata>(e1.br_redova,e1.br_kolona);
            for(int i=0; i<e1.br_redova; i++)
                for(int j=0; j<e1.br_kolona; j++) e.elementi[i][j]=e1.elementi[i][j];
            UnistiMatricu(e1);
            UnistiMatricu(pom);
        }
        else
        {
            auto pom=ProduktMatrica(a,m);
            auto pom1=zbrojem(pom,v[i]);
            auto e1=ZbirMatrica(e,pom1);
            UnistiMatricu(a);
            a=StvoriMatricu<TipElemenata>(pom.br_redova, pom.br_kolona);
            for(int i=0; i<pom.br_redova; i++)
                for(int j=0; j<pom.br_kolona; j++) a.elementi[i][j]=pom.elementi[i][j];
            UnistiMatricu(pom);
            UnistiMatricu(e);
            e=StvoriMatricu<TipElemenata>(e1.br_redova,e1.br_kolona);
            for(int i=0; i<e1.br_redova; i++)
                for(int j=0; j<e1.br_kolona; j++) e.elementi[i][j]=e1.elementi[i][j];
            UnistiMatricu(e1);
            UnistiMatricu(pom1);
        }
        
    }
    UnistiMatricu(a);
    return e;
}



int main ()
{
	cout<<"Unesite dimenziju kvadratne matrice: ";
	try
	{
	    int n;
	    cin>>n;
	    auto mat=StvoriMatricu<double>(n,n);
	    cout<<"Unesite elemente matrice A: "<<endl;
	    UnesiMatricu('A',mat);
	    int a;
	    cout<<"Unesite red polinoma: ";
	    cin>>a;
	    vector<double> v; v.resize(a+1);
	    cout<<"Unesite koeficijente polinoma: ";
	    for(int i=0; i<a+1; i++) { cin>>v[i];}
	    auto rez=MatricniPolinom<double>(mat,v);
	    IspisiMatricu(rez,10);
	    UnistiMatricu(rez);
	    UnistiMatricu(mat);
	}
	catch(domain_error e) { cout<<e.what();}
	catch(...) { cout<<"Nedovoljno memorije";} 
	return 0;
}
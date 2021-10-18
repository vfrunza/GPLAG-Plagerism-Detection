/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
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
void dodjela(Matrica<TipElemenata> &m, const Matrica<TipElemenata> &m1)
{
    for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++) m.elementi[i][j]=m1.elementi[i][j];
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
    if(mat1.br_redova!=mat1.br_kolona) throw domain_error("Matrice nisu saglasne za mnozenje!");
    auto r=StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona);
    for(int i=0; i<mat1.br_redova; i++)
        for(int j=0; j<mat2.br_kolona; j++) r.elementi[i][j]=0;
    for(int i=0;i<mat1.br_redova;i++)
        for(int j=0; j<mat2.br_kolona;j++)
            for(int k=0; k<mat1.br_kolona; k++)
            r.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];
    return r;
}

template<typename TipElemenata, typename k>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int n, k niz)
{
    if(m.br_kolona!=m.br_redova) throw domain_error("Matrica mora biti kvadratna!");
        auto rez=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
                if(i!=j) rez.elementi[i][j]=0;
                else rez.elementi[i][j]=1;
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
                if(i==j) rez.elementi[i][j]=*niz;
        niz++;
        Matrica<TipElemenata> m1=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        Matrica<TipElemenata> m2=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        dodjela(m1,m);
        dodjela(m2,m);
        for(int i=0; i<n; i++)
        {
            auto temp3=ProduktMatrica<TipElemenata>(m1,m2);
            Matrica<TipElemenata> temp1=StvoriMatricu<TipElemenata>(m1.br_kolona, m1.br_kolona);
            for(int i=0; i<m1.br_redova; i++)
                for(int j=0; j<m1.br_kolona; j++) temp1.elementi[i][j]=(*niz)*m1.elementi[i][j];
            
            auto temp2=ZbirMatrica<TipElemenata>(rez,temp1);
            UnistiMatricu(m1);
            m1=temp3;
            temp3.elementi=0;
            UnistiMatricu(rez);
            UnistiMatricu(temp1);
            rez=temp2;
            temp2.elementi=0;
            niz++;
        }
        UnistiMatricu(m2);
        UnistiMatricu(m1);
        return rez;
}

int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    cin>>n;
    try{
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
        } catch(...) { UnistiMatricu(mat); throw;}
    } 
    catch(domain_error d) {cout<<d.what();}
	catch(...) {}
	return 0;
}

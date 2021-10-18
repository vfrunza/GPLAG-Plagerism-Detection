/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

template<typename tip>
struct Matrica {
    int br_redova, br_kolona;
    tip ** elementi= nullptr;
    
};

template<typename tip>
void UnistiMatricu( Matrica<tip> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++)
    {
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename tip>
Matrica<tip> StvoriMatricu ( int br_redova, int br_kolona)
{
    Matrica<tip> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi= new tip*[br_redova];
    for( int i(0); i<br_redova; i++)
    {
        mat.elementi[i]=nullptr;
    }
    try{
        
        for(int i(0); i<br_redova; i++)
        {
            mat.elementi[i]= new tip[br_kolona];
        }
        for( int i=0; i<br_redova; i++)
        {
            for( int j=0; j<br_kolona; j++)
            {
                mat.elementi[i][j]=0;
            }
        }
        
    }
    catch(... ){
        UnistiMatricu(mat);
        throw;
        
        }
    return mat;
    
}

template< typename tip>
void UnesiMatricu( char ime_matrice, Matrica<tip> &mat)
{
    for( int i=0; i<mat.br_redova; i++)
    {
        for( int j =0; j<mat.br_kolona; j++)
        {
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false) 
{
    for(int i = 0; i < mat.br_redova; i++) 
    {
        for(int j = 0; j < mat.br_kolona; j++)
        {
            std::cout << std::setprecision(preciznost)<<std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
    std::cout << std::endl;
    }
    if(treba_brisati==true)
    {
        UnistiMatricu(mat);
    }
}
template<typename tip>
void ZbirMatrica( Matrica<tip> &m1, const Matrica<tip> & m2)
{
    for( int i=0; i<m1.br_redova; i++)
    {
        for( int j=0; j<m1.br_kolona; j++)
        {
            m1.elementi[i][j]+=m2.elementi[i][j];
        }
    }
}
        

template<typename tip>
Matrica<tip> ProduktMatrica ( const Matrica<tip> &a, const  Matrica<tip> &b)
{
    if(a.br_kolona != b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<tip> c;
    try{
        c=StvoriMatricu<tip>(a.br_redova,b.br_kolona);
    }
    catch(std::bad_alloc)
    {
        UnistiMatricu(c);
        throw;
    }
    for(int i=0; i<a.br_redova; i++)
    {
        for(int j=0; j<b.br_kolona; j++)
        {
            tip suma{};
            for(int k=0; k<a.br_kolona; k++)
            {
               suma+=a.elementi[i][k] * b.elementi[k][j];
            }
            c.elementi[i][j]=suma;
       
        }
    }
    
    return c;
    
}

template<typename tip>
void MnozenjeSaSkalarom( double n, Matrica<tip> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
    {
        for(int j=0; j<mat.br_kolona; j++)
        {
            mat.elementi[i][j]=n*mat.elementi[i][j];
        }
    }
    
}



template<typename tip>
Matrica<tip> MatricniPolinom ( Matrica<tip> mat, std::vector<double> v)
{
    if(mat.br_kolona != mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<tip> mat_pol;
    try
    {
        mat_pol=StvoriMatricu<tip>(mat.br_redova, mat.br_kolona);
    }
    
    catch(std::bad_alloc)
    {
        UnistiMatricu(mat_pol);
        throw;
    }
   if(v.size()==0) return mat_pol;
   std::vector<Matrica<tip>> vektor_matrica(v.size());
   try{
     
     vektor_matrica[0]=StvoriMatricu<tip>(mat.br_redova, mat.br_kolona);
     vektor_matrica[1]=StvoriMatricu<tip>(mat.br_redova, mat.br_kolona);
   }
   catch(std::bad_alloc)
    {
        
        UnistiMatricu(vektor_matrica[0]);
        UnistiMatricu(vektor_matrica[1]);
         throw;
    }
   for(int i=0; i<mat.br_redova; i++)
        {
            for(int j=0; j<mat.br_kolona; j++)
            {
                if(i==j) vektor_matrica[0].elementi[i][j]=1;
                else vektor_matrica[0].elementi[i][j]=0;
            }
        }
    for( int i=0; i<mat.br_redova; i++)
        {
            for( int j=0; j<mat.br_kolona; j++)
            {
                vektor_matrica[1].elementi[i][j]=mat.elementi[i][j];
            }
        }
    for( int i=2; i<v.size(); i++)
        {
            try
            {
                
                vektor_matrica[i]=ProduktMatrica(vektor_matrica[i-1], mat);
            }
            catch(std::bad_alloc)
            {
                for(int i=0; i<v.size(); i++)
                {
                    UnistiMatricu(vektor_matrica[i]);
                }
                throw;
            }
        }
    try{
       for(int i=0; i<v.size(); i++)
       {
           MnozenjeSaSkalarom(v[i], vektor_matrica[i]);
       }}
    catch(std::bad_alloc)
       {
           for(int i=0; i<v.size(); i++)
           {
               UnistiMatricu(vektor_matrica[i]);
           }
           throw;
       }
    for( int i=0; i<v.size(); i++)
       {
           ZbirMatrica(mat_pol, vektor_matrica[i]);
           UnistiMatricu(vektor_matrica[i]);
       }

    return mat_pol;
        
}


int main ()
{
    Matrica<double> a,c;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int br_redova;
    cin>>br_redova;
    try {
        a=StvoriMatricu<double>(br_redova , br_redova);
        cout<<"Unesite elemente matrice A: "<<endl;
        UnesiMatricu('A', a);
        cout<<"Unesite red polinoma: ";
        int n;
        cin>>n;
        n++;
        std::vector<double> v;
        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<n; i++)
        {
            double broj;
            cin>>broj;
            v.push_back(broj);
        }
        try{
            c=MatricniPolinom(a,v);
            IspisiMatricu(c,10);
              UnistiMatricu(a);
            UnistiMatricu(c);
        }
        catch(std::domain_error e)
        {
              UnistiMatricu(a);
                UnistiMatricu(c);
            cout<<e.what();
        }
    }
    catch(std::bad_alloc)
    {
        UnistiMatricu(a);
        UnistiMatricu(c);
        cout<<"Nema dovoljno memorije!";
    }
 
	return 0;
}
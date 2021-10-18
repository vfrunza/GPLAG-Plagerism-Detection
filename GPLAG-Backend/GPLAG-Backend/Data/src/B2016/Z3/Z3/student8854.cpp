/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <vector>
template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata** elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete [] mat.elementi[i];
    delete[] mat. elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;mat.br_kolona=br_kolona; 
    try{
    mat.elementi=new TipElemenata*[br_redova];
    }
    catch(...)
    {
        UnistiMatricu(mat);
    }
    for(int i=0;i<br_redova;i++)
    mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat)
{
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            std::cout<<std::setw(sirina_ispisa);
            std::cout<<std::setprecision(preciznost);
            std::cout<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    
    if(treba_brisati)
    {
        int k=mat.br_redova;
        for(int i=0;i<k;i++)
        delete[] mat.elementi[i];
        delete[] mat.elementi;
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m1.br_kolona;j++)
        {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for(int i=0;i<m3.br_redova;i++)
    {
        for(int j=0;j<m3.br_kolona;j++)
        {
            for(int k=0;k<m1.br_kolona;k++)
            {
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
    
    
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatricaBroj(const Matrica<TipElemenata> &m1, int broj)
{
    
    auto m3=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m1.br_kolona;j++)
        {
            
            m3.elementi[i][j]=m1.elementi[i][j];
        }
    }
    for(int i=0;i<m3.br_redova;i++)
    {
        for(int j=0;j<m3.br_kolona;j++)
        {
            m3.elementi[i][j]=m3.elementi[i][j]*broj;
        }
    }
    return m3;
    
    
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m,std::vector<double>koeficijenti)
{
    if(m.br_kolona!=m.br_redova)
    throw std::domain_error("Matrica mora biti kvadratna");
    auto pomocna=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i=0;i<m.br_redova;i++)
    {
        for(int j=0;j<m.br_kolona;j++)
        {
            if(i==j)
            pomocna.elementi[i][j]=1;
            else
            pomocna.elementi[i][j]=0;
        }
    }
    auto rezultat=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i=0;i<m.br_redova;i++)
    {
        for(int j=0;j<m.br_kolona;j++)
        {
            rezultat.elementi[i][j]=0;
        }
    }
    for(int i=0;i<koeficijenti.size();i++)
    {
        
        
        auto produktmatricabroj=ProduktMatricaBroj<TipElemenata>(pomocna,koeficijenti[i]);
        /*IspisiMatricu<double>(produktmatricabroj,4);*/
        
        rezultat=ZbirMatrica(produktmatricabroj,rezultat);
        /*IspisiMatricu<double>(rezultat,6);*/
        UnistiMatricu(produktmatricabroj);
        
        pomocna=ProduktMatrica(pomocna,m);
        /*IspisiMatricu<double>(pomocna,8);*/
        
    }
    UnistiMatricu(pomocna);
    return rezultat;
}





int main ()
{
	std::cout<<"Unesite dimenziju kvadratne matrice: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente matrice A: "<<std::endl;
	try{
	Matrica<double> m=StvoriMatricu<double>(n,n);
	UnesiMatricu('A',m);
	
	std::cout<<"Unesite red polinoma: ";
	int red;
	std::cin>>red;
	std::cout<<"Unesite koeficijente polinoma: ";
	std::vector<double>koeficijenti(red+1);
	for(int i=0;i<red+1;i++)
	std::cin>>koeficijenti[i];
	Matrica<double> s=MatricniPolinom<double>(m,koeficijenti);
	IspisiMatricu<double>(s,10,6,true);
	
		UnistiMatricu(m);}
	catch(std::bad_alloc)
	{
	    std::cout<<"Nema dovoljno memorije!\n";
	}
	
	
	return 0;
}
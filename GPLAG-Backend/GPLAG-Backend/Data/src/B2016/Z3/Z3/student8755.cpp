/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <new>
#include <stdexcept>
#include <iomanip>
#include <vector>
template <typename TipElemenata>
    struct Matrica
    {
        int br_redova, br_kolona;
        TipElemenata **elementi=nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat)
    {
        if(!mat.elementi)   return;
        for(int i=0; i<mat.br_redova; i++)  delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
    {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova; mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++)  mat.elementi[i]=nullptr;
        try
        {
            for(int i=0; i<br_redova; i++)
                mat.elementi[i]=new TipElemenata[br_kolona];
        }
        catch(std::bad_alloc izuzetak)
        {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
    {
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++)
            {
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
    }
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
    {
        for(int i=0; i<mat.br_redova; i++)
        {
            for(int j=0; j<mat.br_kolona; j++)
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
        if(treba_brisati)   UnistiMatricu(mat);
    }
template <typename TipElemenata>
    Matrica <TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, 
        const Matrica<TipElemenata> &m2)
        {
            if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
                throw std::domain_error("Matrice nemaju jednake dimenzije!");
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
            for(int i=0; i<m1.br_redova; i++)
                for(int j=0; j<m1.br_kolona; j++)
                    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            return m3;
        }
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
        const Matrica<TipElemenata> &m2)
        {
            if(m1.br_kolona!=m2.br_redova)  
                throw std::domain_error("Matrice nisu saglasne za mnozenje");
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
            for(int i=0; i<m1.br_redova; i++)
                for(int j=0; j<m2.br_kolona; j++)
                {
                    m3.elementi[i][j]=0;
                    for(int k=0; k<m1.br_kolona; k++)
                        m3.elementi[i][j]+=(m1.elementi[i][k]*m2.elementi[k][j]);
                }
            return m3;
        }
template <typename TipElemenata>
    void SkalarniProduktVoid(Matrica<TipElemenata> &m, double x)
    {
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
                m.elementi[i][j]*=x;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> SkalarniProdukt(const Matrica<TipElemenata> &m, double x)
    {
        auto mat(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
                mat.elementi[i][j]=m.elementi[i][j]*x;
        return mat;
    }
template <typename TipElemenata>
    void PostaviJedinicnu(Matrica<TipElemenata> &m)
    {
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
            {
                if(i==j) m.elementi[i][j]=1;
                else m.elementi[i][j]=0;
            }
    }
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> v)
    {
        if(m.br_kolona!=m.br_redova)    throw std::domain_error("Matrica mora biti kvadratna");
        auto jedinicna(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        PostaviJedinicnu(jedinicna);
        auto polinom (StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));   
        auto stepen(ProduktMatrica(m,m));
        for(int i=0; i<v.size(); i++)
        {
            if(i==0) 
            {
                SkalarniProduktVoid(jedinicna,v[i]);
                if(v.size()==1)
                {
                    UnistiMatricu(polinom); UnistiMatricu(stepen);
                    return jedinicna;
                }
            }
            else if(i==1)
            {
                auto skalarni(SkalarniProdukt(m,v[i]));
                auto zbir=ZbirMatrica(jedinicna, skalarni);
                std::swap(zbir, polinom);
                UnistiMatricu(zbir); UnistiMatricu(jedinicna); UnistiMatricu(skalarni);
                if(v.size()==2)
                {
                    UnistiMatricu(stepen);
                    return polinom;
                }
            }
            else
            {
                auto skalarni(SkalarniProdukt(stepen, v[i]));
                auto zbir=ZbirMatrica(polinom, skalarni);
                std::swap(zbir, polinom);
                UnistiMatricu(zbir); UnistiMatricu(skalarni);
                if(i!=int(v.size()-1))
                {
                    auto proizvod(ProduktMatrica(m, stepen));
                    std::swap(stepen, proizvod);
                    UnistiMatricu(proizvod);
                }
            }
        }
        UnistiMatricu(stepen);
        return polinom;
    }
int main ()
{
    try
    {
    	int n;
    	std::cout<<"Unesite dimenziju kvadratne matrice: ";
    	std::cin>>n;
    	Matrica<double> m;
    	m=StvoriMatricu<double>(n,n);
    	std::cout<<"Unesite elemente matrice A: "<<std::endl;
    	UnesiMatricu('A', m);
    	std::cout<<"Unesite red polinoma: ";
    	std::cin>>n;
    	std::vector<double> v;
    	std::cout<<"Unesite koeficijente polinoma: ";
    	for(int i=0; i<n+1; i++)
    	{
    	    int x;
    	    std::cin>>x;
    	    v.push_back(x);
    	}
    	auto polinom = MatricniPolinom(m, v);
    	IspisiMatricu(polinom, 10);
    	UnistiMatricu(polinom); UnistiMatricu(m);
    }
	catch(std::bad_alloc izuzetak)
	{
	    std::cout<<izuzetak.what();
	}
	catch(std::domain_error izuzetak)
	{
	    std::cout<<izuzetak.what();
	}
}
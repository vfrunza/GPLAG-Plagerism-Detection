#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

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
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try 
        {
            for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch(...) 
        {
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
                std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) 
    {
        for(int i = 0; i < mat.br_redova; i++) 
        {
            for(int j = 0; j < mat.br_kolona; j++) std::cout << std::setprecision(6) << std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
        }
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) 
    {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        try
        {
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
            for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++) m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            return m3;
        }
        catch(...)
        {
            throw;
        }
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
    {
        if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        try
        {
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
            for(int i=0;i<m1.br_redova;i++)
            {
                for(int j=0;j<m2.br_kolona;j++)
                {
                    for(int k=0;k<m2.br_redova;k++)
                    {
                        m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
                    }
                }
            }
            return m3;
        }
        catch(...)
        {
            throw;
        }
    }

template<typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, vector<double> v)
    {
        Matrica<TipElemenata> pol;
        try
        {
            pol=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
            if(v.size()>1)
            {
                vector<Matrica<TipElemenata>> m(v.size()-1);
                try
                {
                    for(int i=0;i<m.size();i++) m[i]=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
                    for(int i=0;i<A.br_redova;i++)
                    {
                        for(int j=0;j<A.br_kolona;j++)
                        {
                            if(i==j) pol.elementi[i][j]=1; else pol.elementi[i][j]=0;
                        }
                    }
                    for(int i=0;i<v.size();i++)
                    {
                        if(i==0)
                        {
                            for(int x=0;x<A.br_redova;x++)
                            {
                                pol.elementi[x][x]*=v[0];
                            }
                        }
                        else
                        {
                            for(int r=0;r<A.br_redova;r++)
                            {
                                for(int t=0;t<A.br_kolona;t++)
                                {
                                    m[i-1].elementi[r][t]=A.elementi[r][t];
                                }
                            }
                            for(int o=1;o<i;o++)
                            {
                                Matrica<TipElemenata> priv=m[i-1];
                                m[i-1]=ProduktMatrica(m[i-1], A);
                                UnistiMatricu(priv);
                            }
                            for(int x=0;x<A.br_redova;x++)
                            {
                                for(int y=0;y<A.br_kolona;y++)
                                {
                                    m[i-1].elementi[x][y]*=v[i];
                                }
                            }
                            Matrica<TipElemenata> priv=pol;
                            pol=ZbirMatrica(pol, m[i-1]);
                            UnistiMatricu(priv);
                        }
                    }
                    for(int i=0;i<m.size();i++) UnistiMatricu(m[i]);
                }
                catch(...)
                {
                    for(int i=0;i<m.size();i++) UnistiMatricu(m[i]);
                    UnistiMatricu(pol);
                    throw;
                }
            }
        }
        catch(...)
        {
            throw;
        }
        return pol;
    }

int main() 
{
    Matrica<double> a, b;
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    a = StvoriMatricu<double>(n, n);
    std::cout << "Unesite elemente matrice A: ";
    UnesiMatricu('A', a);
    cout << "Unesite red polinoma: ";
    int r;
    cin >> r;
    vector<double> v(r+1);
    cout << "Unesite koeficijente polinoma: ";
    for(int i=0;i<v.size();i++)
    {
        cin >> v[i];
    }
    b=MatricniPolinom(a, v);
    IspisiMatricu(b, 10);
    UnistiMatricu(a); UnistiMatricu(b);
    return 0;
}

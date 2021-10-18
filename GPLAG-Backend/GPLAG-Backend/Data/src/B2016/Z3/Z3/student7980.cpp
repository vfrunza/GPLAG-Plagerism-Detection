#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace::std;

template <typename TipElemenata>
    struct Matrica 
    {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat)
    {
        if(!mat.elementi)
            return;
        for(int i = 0; i < mat.br_redova; i++) 
            delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) 
    {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = nullptr;
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
    void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost = 6,bool treba_brisati = false) 
    {
        for(int i = 0; i < mat.br_redova; i++)
        {
            for(int j = 0; j < mat.br_kolona; j++)
                std::cout << setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
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

template <typename TipE>
    Matrica<TipE> ProduktMatrica(const Matrica<TipE> &m1,const Matrica<TipE> &m2)
    {
        if(m1.br_kolona != m2.br_redova)
            throw domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipE>(m1.br_redova,m2.br_kolona));
        for(int i = 0; i < m1.br_redova;i++)
        {
            for(int j = 0;j < m2.br_kolona;j++)
            {
                m3.elementi[i][j] = 0;
                for(int k = 0; k < m1.br_kolona;k++)
                {
                    m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
                }
            }
        }
        return m3;
    }

template <typename TipE>
    Matrica<TipE> SkalarniProdukt(const Matrica<TipE> &m1,double p)
    {
        auto m2 = StvoriMatricu<TipE>(m1.br_redova,m1.br_kolona);
        for(int i = 0; i < m1.br_redova;i++)
        {
            for(int j = 0; j < m1.br_kolona; j++)
                m2.elementi[i][j] = p*m1.elementi[i][j];
        }
        return m2;
    }
template <typename TipE>
    Matrica<TipE> MatricniPolinom(const Matrica<TipE> &m1,vector<double> pol)
    {
        if(m1.br_redova != m1.br_kolona)
            throw domain_error("");
        auto Pn = StvoriMatricu<TipE>(m1.br_redova,m1.br_kolona);
        for(int i = 0;i < Pn.br_redova;i++)
        {
            for(int j  = 0; j < Pn.br_kolona;j++)
            {
                Pn.elementi[i][j] = 0;
                if(i == j)
                    Pn.elementi[i][j] = 1;
            }
        }
        auto Pm = SkalarniProdukt(Pn,pol[0]);
        UnistiMatricu(Pn);
        Matrica<TipE> temp = StvoriMatricu<TipE>(m1.br_redova,m1.br_kolona);
        for(int k = 0; k < Pm.br_redova; k++)
            for(int l = 0; l < Pm.br_kolona; l++)
                temp.elementi[k][l] = m1.elementi[k][l];
                
        for(int i = 1;i < pol.size();i++)
        {
            auto temp2 = SkalarniProdukt(temp,pol[i]);
            for(int k = 0; k < Pm.br_redova; k++)
                for(int l = 0; l < Pm.br_kolona; l++)
                {
                    Pm.elementi[k][l] = Pm.elementi[k][l] + temp2.elementi[k][l];
                }
            
            auto temp3 = temp;   
            temp = ProduktMatrica(temp,m1);
            UnistiMatricu(temp3);
            UnistiMatricu(temp2);
        }
        UnistiMatricu(temp);
        return Pm;
    }

int main()
{
    int dim;
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> dim;
    Matrica<double> m1;
    m1 = StvoriMatricu<double>(dim,dim);
    cout << "Unesite elemente matrice A: " << endl;
    UnesiMatricu('A',m1);
    int red;
    cout << "Unesite red polinoma: ";
    cin >> red;
    vector<double> pol(red+1);
    cout << "Unesite koeficijente polinoma: ";
    for(int i = 0;i<pol.size();i++)
    cin >> pol[i];
    IspisiMatricu(MatricniPolinom(m1,pol),10,6,true);
    UnistiMatricu(m1);
    return 0;
}
/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <cmath>
#include <vector>

template <typename TipElemenata>
struct Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if (!mat.elementi) return;
    for (int i(0); i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica <TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for (int i(0); i<br_redova; i++) mat.elementi[i] = nullptr;
    try
    {
        for (int j(0); j<br_redova; j++) mat.elementi[j] = new TipElemenata[br_kolona];
    }
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat)
{
    for (int i(0); i<mat.br_redova; i++)
    {
        for (int j(0); j<mat.br_kolona; j++)
        {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
Matrica <TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
    for (int i(0); i<m1.br_redova; i++)
    {
        for (int j(0); j<m1.br_kolona; j++)
        {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    auto m3(StvoriMatricu<TipElemenata> (m1.br_redova, m2.br_kolona));
    if (m1.br_redova != m2.br_kolona || m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje!");
    
    else
    {
        
    for (int i(0); i<m1.br_redova; i++)
    {
        for (int j(0); j<m2.br_kolona; j++)
        {
            TipElemenata suma(0);
            for (int k(0); k<m2.br_redova; k++)
            {
                suma += m1.elementi[i][k] * m2.elementi[k][j];
            }
            m3.elementi[i][j] = suma;
        }
    }
    }
    
    return m3;
}
template <typename TipElemenata>
void DubokoKopiranje (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    for (int i(0); i<m1.br_redova; i++)
    {
        for (int j(0); j<m1.br_kolona; j++)
        {
            m1.elementi[i][j] = m2.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSaVektorom (const Matrica <TipElemenata> &m, std::vector<TipElemenata> p)
{
    Matrica <TipElemenata> m1(StvoriMatricu<TipElemenata> (m.br_redova, m.br_kolona));
    for (int i(0); i<m1.br_redova; i++)
    {
        for (int j(0); j<m1.br_kolona; j++)
        {
            // for (int k(0); k<p.size(); k++)
            // {
            //     m1.elementi[i][j] = p[k] * m.elementi[i][j];
            // }
            m1.elementi[i][j] = p[i] * m.elementi[i][j];
        }
    }
    return m1;
}

template <typename TipElemenata>
Matrica <TipElemenata> MatricniPolinom(Matrica<TipElemenata> &m, std::vector<double> p)
{
    if (m.br_redova != m.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
    
    Matrica<TipElemenata> polinom(StvoriMatricu<TipElemenata> (m.br_redova, m.br_kolona));
    Matrica<TipElemenata> m1 (StvoriMatricu<TipElemenata> (m.br_redova, m.br_kolona));
    Matrica<TipElemenata> m2 (StvoriMatricu<TipElemenata> (m.br_redova, m.br_kolona));
    
    //Kreiranje jedinicne matrice
    for (int i(0); i<m.br_redova; i++)
    {
        
        for (int j(0); j<m.br_kolona; j++)
        {
            if (i==j)
            {
                m1.elementi[i][j] = 1;
                polinom.elementi[i][j] = 1;
            }
            else
            {
                m1.elementi[i][j] = 0;
                polinom.elementi[i][j] = 0;
            }
            m2.elementi[i][j] = p[i] * m1.elementi[i][j];
        }
    }
    for (int i(0); i<p.size(); i++)
    {
        DubokoKopiranje (m2, ProduktMatrica(m2,m1));
        //DubokoKopiranje (polinom, ZbirMatrica (polinom, PomnoziSaVektorom(m1, p)));
        DubokoKopiranje (polinom, ZbirMatrica (polinom, ProduktMatrica(m2,m)));
    }
    UnistiMatricu(m1);
    
    return polinom;
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for (int i(0); i<mat.br_redova; i++)
    {
        for (int j(0); j<mat.br_kolona; j++)
        {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati ) UnistiMatricu(mat);
}

int main ()
{
    Matrica<double> a, b;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try
    {
        a = StvoriMatricu<double>(m,m);
        b = StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> p;
        for (int i(0); i<red; i++)
        {
            double unos;
            std::cin >> unos;
            p.push_back(unos);
        }
        
        IspisiMatricu(b = MatricniPolinom(a,p), 9, 5, true);
    }
    catch (std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    
	return 0;
}
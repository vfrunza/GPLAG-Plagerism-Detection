/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
//#include "TestCurenja.h" 

template<typename TipElemenata>
struct Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi)
        return;
        
    for(int i = 0; i < mat.br_redova; i++)
        delete[] mat.elementi[i];
        
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    
    for(int i = 0; i < br_redova; i++)
        mat.elementi[i] = nullptr;
        
    try
    {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona]{};
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
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) 
    {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            
        std::cout << std::endl;
    }
    
    if(brisati)
        UnistiMatricu(mat);
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    Matrica<TipElemenata> m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
            for(int a = 0; a < m1.br_kolona; a++)
                    m3.elementi[i][j] += m1.elementi[i][a] * m2.elementi[a][j];
                    
    return m3;
}

template <typename TipElemenata>
void PomnoziSaSkalarom(Matrica<TipElemenata> m, double s)
{
    for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
            m.elementi[i][j] *= s;
}

template <typename TipElemenata>
Matrica<TipElemenata> Stepenovanje(Matrica<TipElemenata> m, int stepen)
{
    auto m2 = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    auto m3 = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
        {
            m2.elementi[i][j] = m.elementi[i][j];
            m3.elementi[i][j] = m.elementi[i][j];
        }
            
    for(int i = 1; i < stepen; i++)
    {
        auto kopija = m3;
        m3 = ProduktMatrica(m3, m2);
        UnistiMatricu(kopija);
    }
    UnistiMatricu(m2);
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> vek)
{
    if(m.br_kolona != m.br_redova)
        throw std::domain_error("Matrica mora biti kvadratna");
        
    Matrica<TipElemenata> jed = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    
    if(vek.empty())
        return jed;
        
    for(int i = 0; i < jed.br_redova; i++)
        jed.elementi[i][i] = 1;
        
    for(int i = 0; i < vek.size(); i++)
    {
        if(i == 0)
        {
            PomnoziSaSkalarom(jed, vek.at(i));
            continue;
        }
        
        Matrica<TipElemenata> m2;
        m2.elementi = nullptr;
        Matrica<TipElemenata> kopija;
        kopija.elementi = nullptr;
        
        try
        {
            kopija = jed;
            m2 = Stepenovanje(m, i);
            PomnoziSaSkalarom(m2, vek.at(i));
            jed = ZbirMatrica(jed, m2);
            UnistiMatricu(kopija);
            UnistiMatricu(m2);
        }
        catch(...)
        {
            UnistiMatricu(m2);
            m2.elementi = nullptr;
            UnistiMatricu(jed);
            jed.elementi = nullptr;
            UnistiMatricu(kopija);
            kopija.elementi = nullptr;
        }
    }
    
    return jed;
}

int main()
{
    int a;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> a;
    Matrica<double> m, m2;
    m.elementi = nullptr;
    m2.elementi = nullptr;
    
    try
    {
        m = StvoriMatricu<double>(a, a);
        std::cout << "Unesite elemente matrice A: \n";
        for(int i = 0; i < a; i++)
            for(int j = 0; j < a; j++)
            {
                std::cout << "A(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> m.elementi[i][j];
            }
            
        int r;
        std::cout << "Unesite red polinoma: ";
        std::cin >> r;
        std::vector<double> vek;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i = 0; i <= r; i++)
        {
            double x;
            std::cin >> x;
            vek.push_back(x);
        }
        
        m2 = MatricniPolinom(m, vek);
        IspisiMatricu(m2, 10, 6, true);
        UnistiMatricu(m);
    }
    catch(...)
    {
        UnistiMatricu(m);
        std::cout << "Izuzetak";
    }
    
    return 0;
}
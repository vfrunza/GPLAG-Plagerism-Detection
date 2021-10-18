/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <new>


template<typename TipElementa>
struct Matrica
{
    int br_redova, br_kolona;
    TipElementa **elementi = nullptr;
};

template<typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat)
{
    if(!mat.elementi) return;
    for(int i(0); i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template<typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElementa> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElementa*[br_redova]{};
    /*for(int i(0); i < br_redova; i++) mat.elementi[i] = nullptr;*/
    try
    {
        for(int i(0); i < br_redova; i++) 
          mat.elementi[i] = new TipElementa[br_kolona];
    }
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElementa>
void UnesiMatricu(char ime_matrice, Matrica<TipElementa> &mat)
{
    for(int i(0); i < mat.br_redova; i++)
    {
        for(int j(0); j < mat.br_kolona; j++)
        {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i(0); i < mat.br_redova; i++)
    {
        for(int j(0); j < mat.br_kolona; j++)
        {
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template<typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
      throw std::domain_error("Matrice nemaju jednake dimenzije!");
    
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
    for(int i(0); i < m1.br_redova; i++)
      for(int j(0); j < m1.br_kolona; j++)
        m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    
    return m3;
}



template<typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    if(m1.br_kolona != m2.br_redova)
      std::domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona));
    
    for(int i(0); i < m1.br_redova; i++)
      for(int j(0); j < m2.br_kolona; j++)
        for(int k(0); k < m1.br_kolona; k++)
          m3.elementi[i][j] += (m1.elementi[i][k] * m2.elementi[k][j]); 
    
    return m3;
}


template<typename TipElementa>
Matrica<TipElementa> Jedinicna(int br_redova, int br_kolona)
{
    auto I(StvoriMatricu<TipElementa>(br_redova, br_kolona));
    for(int i(0); i < br_redova; i++)
    {
        for(int j(0); j < br_kolona; j++)
        {
            I.elementi[i][j] = (i == j) ? 1 : 0;
        }
    }
    return I;
}

template<typename TipElementa>
void SkalarniProdukt(Matrica<TipElementa> &mat, int n)
{
    for(int i(0); i < mat.br_redova; i++)
    {
        for(int j(0); j < mat.br_kolona; j++)
        {
            mat.elementi[i][j] *= n;
        }
    }
}

template<typename TipElementa>
void Kopiraj(Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    for(int i(0); i < m1.br_redova; i++)
    {
        for(int j(0); j < m1.br_kolona; j++)
        {
            m1.elementi[i][j] = m2.elementi[i][j];
        }
    }
}

template<typename TipElementa>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &mat, const std::vector<double> &koeficijenti)
{
    if(mat.br_redova != mat.br_kolona)
      throw std::domain_error("Matrica mora biti kvadratna");
    
    auto Mp(Jedinicna<TipElementa>(mat.br_redova, mat.br_kolona));
    auto stepen(StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona));
    auto pomocna1(StvoriMatricu<TipElementa>(mat.br_redova, mat.br_kolona));
    
    Matrica<TipElementa> hulk;

    Kopiraj(stepen, mat);
    
    for(int i(0); i < koeficijenti.size(); i++)
    {
        if(i == 0)
        {
            SkalarniProdukt(Mp, koeficijenti[i]);
        }
        else
        {
            Kopiraj(stepen, mat);
            for(int k(0); k < i - 1; k++)
            {
                Kopiraj(stepen, hulk = ProduktMatrica(stepen, mat));
                UnistiMatricu(hulk);
            }
            
            Kopiraj(pomocna1, stepen);
            SkalarniProdukt(pomocna1, koeficijenti[i]);
            
            Kopiraj(Mp, hulk = ZbirMatrica(Mp, pomocna1));
            UnistiMatricu(hulk);
        }
    }
    UnistiMatricu(pomocna1);
    UnistiMatricu(stepen);
    return Mp;
}

int main ()
{
    int vel;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> vel;
    
    Matrica<double> mat, Mp;
    try
    {
        mat = StvoriMatricu<double>(vel, vel);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', mat);
        int d;
        std::cout << "Unesite red polinoma: ";
        std::cin >> d;
        
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti(d + 1);
        for(double &x : koeficijenti) std::cin >> x;
        
        Mp = MatricniPolinom<double>(mat, koeficijenti);
        IspisiMatricu(Mp, 10);
        UnistiMatricu(mat); UnistiMatricu(Mp);
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;
}
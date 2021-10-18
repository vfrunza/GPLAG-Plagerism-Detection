/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
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
        for (int i = 0; i < mat.br_redova; i++) 
            delete[] mat.elementi[i];
        delete[] mat.elementi;   
        mat.elementi = nullptr;   
    }   
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
    {
        Matrica <TipElemenata> mat;
        mat.br_kolona = br_kolona; mat.br_redova = br_redova;
        mat.elementi = new TipElemenata*[br_redova];
        for (int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try
        {
            for (int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch (...)  
        {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> StvoriJedinicnu(int n)
    {
        Matrica<TipElemenata> mat(StvoriMatricu<TipElemenata>(n, n));
            for (int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if (i == j) mat.elementi[i][j] = 1; else mat.elementi[i][j] = 0;
        
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
    {
        for (int i = 0; i < mat.br_redova; i++)
            for (int j = 0; j < mat.br_kolona; j++)
            {
                std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }

template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
    {
        for (int i = 0; i < mat.br_redova; i++)
        {
            for (int j = 0; j < mat.br_kolona; j++)
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            std::cout << std::endl;
        }
        if (treba_brisati){UnistiMatricu(mat);}
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
    {
        if (m1.br_kolona != m2.br_kolona || m1.br_redova != m2.br_redova)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_kolona, m1.br_redova));
        for (int i = 0; i < m3.br_redova; i++)
            for (int j = 0; j < m3.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2)
    {
        if (m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for (int i = 0; i < m3.br_redova; i++)
            for (int j = 0; j < m3.br_kolona; j++)
            {
                m3.elementi[i][j] = 0;
                for (int k = 0; k < m1.br_kolona; k++)
                    m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
            }
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> PomnoziKoeficijentom(double x, const Matrica<TipElemenata> &mat)
    {
        Matrica<TipElemenata> mat2(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        for (int i = 0; i < mat2.br_redova; i++)
            for (int j = 0; j < mat2.br_kolona; j++)
                mat2.elementi[i][j] = x*mat.elementi[i][j];
        return mat2;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, const std::vector<double> &koef)
    {
        if (A.br_kolona != A.br_redova)
            throw std::domain_error("Matrica mora biti kvadratna");
        
        Matrica<TipElemenata> polinom(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
        for (int i = 0; i < polinom.br_redova; i++)
            for(int j = 0; j < polinom.br_kolona; j++)
                polinom.elementi[i][j] = 0;
        
        Matrica<TipElemenata> I(StvoriJedinicnu<TipElemenata>(A.br_redova));
        Matrica<TipElemenata> stepen(I);
        Matrica<TipElemenata> p, q, r;
        try
        {
            for (int i = 0; i < koef.size(); i++)
            {
                if (i == 0)
                {
                    polinom = ZbirMatrica(p = polinom, q = PomnoziKoeficijentom(koef[i], I));
                    UnistiMatricu(p); UnistiMatricu(q);
                }
                else
                {
                    stepen = ProduktMatrica(r = stepen, A);
                    UnistiMatricu(r);
                    polinom = ZbirMatrica(p = polinom, q = PomnoziKoeficijentom(koef[i], stepen));
                    UnistiMatricu(p); UnistiMatricu(q); 
                }
            }
        } catch (std::bad_alloc){
            UnistiMatricu(stepen); UnistiMatricu(p); UnistiMatricu(q); UnistiMatricu(r); UnistiMatricu(polinom);
            throw;
        }
        UnistiMatricu(stepen);
        return polinom;
    }
int main ()
{
    Matrica<int> mat, polinom;
    int n(0);
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try
    {
        mat = StvoriMatricu<int>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', mat);
        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;
        std::vector <double> koef(red + 1);
        std::cout << "Unesite koeficijente polinoma: ";
        for (int i = 0; i < red + 1; i++) std::cin >> koef[i];
        IspisiMatricu(polinom = MatricniPolinom(mat, koef), 10, 6);
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(mat); UnistiMatricu(polinom);
    
	return 0;
}
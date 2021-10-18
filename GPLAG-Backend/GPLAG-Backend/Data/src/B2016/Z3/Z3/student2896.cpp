/B2016/2017: Zadaća 3, Zadatak 3.
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
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
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
    for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
    try
    {
        for(int i=0; i<br_redova; i++)
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
    for(int i=0; i<mat.br_redova; i++)
    {
        for(int j=0; j<mat.br_kolona; j++)
        {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati =  false)
{
    for(int i=0; i<mat.br_redova; i++)
    {
        for(int j=0; j<mat.br_kolona; j++)
        {
            std::cout <<  std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati)
    {
        UnistiMatricu(mat);
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa)
{
    for(int i=0; i<mat.br_redova; i++)
    {
        for(int j=0; j<mat.br_kolona; j++)
        {
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const  Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m2.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
auto ProduktMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2) -> Matrica<TipElemenata>
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for(int i=0; i<m3.br_redova; i++)
    {
        for(int j=0; j<m3.br_kolona; j++)
        {
            TipElemenata suma = 0;
            for(int k = 0; k < m1.br_kolona; k++)
            {
                suma += m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template <typename TipElemenata>
auto MatricniPolinom(Matrica<TipElemenata> a, std::vector<double> koef) -> Matrica<TipElemenata>
{
    if(a.br_kolona != a.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    if(koef.size() == 0)
    {
        Matrica<TipElemenata> mat = StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
        for(int i=0; i<mat.br_redova; i++)
        {
            for(int j=0; j<mat.br_kolona; j++)
            {
                mat.elementi[i][j] = 0;
            }
        }
        return mat;
    }
    Matrica<TipElemenata> mat = StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
    for(int i=0; i<a.br_redova; i++)
    {
        for(int j=0; j<a.br_kolona; j++)
        {
            mat.elementi[i][j] = 0;
        }
    }
    for(int i=0; i<koef.size(); i++)
    {
        Matrica<TipElemenata> pomocna = StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
        for(int k=0; k<a.br_redova; k++)
        {
            for(int j=0; j<a.br_kolona; j++)
            {
                if(k==j) pomocna.elementi[k][j] = 1; //gggg
                else pomocna.elementi[k][j] = 0;
            }
        }
        for(int j=0; j<i; j++)
        {
            Matrica<TipElemenata> pomocna2 = ProduktMatrica(pomocna, a);
            UnistiMatricu(pomocna);
            pomocna = pomocna2;
        }
        for(int j=0; j<a.br_redova; j++)
        {
            for(int k=0; k<a.br_kolona; k++)
            {
                pomocna.elementi[j][k] *= koef.at(i);
            }
        }
        Matrica<TipElemenata> mat2 = ZbirMatrica(mat, pomocna);
        UnistiMatricu(mat);
        mat = mat2;
        UnistiMatricu(pomocna);
    }
    return mat;
}

int main ()
{
    Matrica<double> a;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try
    {
        a = StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    std::cout << "Unesite red polinoma: ";
    int red;
    std::cin >> red;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> koef(red+1);
    for(int i=0; i<=red; i++)
    {
        double unos;
        std::cin >> unos;
        koef.at(i) = unos;
    }
    IspisiMatricu(MatricniPolinom(a,koef),10,6,true);
    UnistiMatricu(a);
	return 0;
}
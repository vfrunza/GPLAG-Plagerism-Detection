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
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) 
    {
        delete[] mat.elementi[i];
        mat.elementi[i]=nullptr;
    }
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
    catch(std::bad_alloc) 
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
    {
        for(int j = 0; j < mat.br_kolona; j++) 
        {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) 
{
    for(int i = 0; i < mat.br_redova; i++) 
    {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) 
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
    {
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m3.br_redova; i++)
    {
        for(int j=0; j<m3.br_kolona; j++)
        {
            double suma(0);
            for(int k=0; k<m1.br_kolona; k++)
            {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSkalarSaMatricom(Matrica<TipElemenata> m, double skalar)
{
    Matrica<TipElemenata> proizvod;
    proizvod=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    for(int i=0; i<m.br_redova; i++)
    {
        for(int j=0; j<m.br_redova; j++)
        {
            proizvod.elementi[i][j]=m.elementi[i][j]*skalar;
        }
    }
    
    return proizvod;
}

template <typename TipElemenata>
void AnulirajMatricu(Matrica<TipElemenata> mat) 
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++)
            mat.elementi[i][j] = 0;
}

// Funkcija MatricniPolinom kao rezultat vraca vrijednost matricnog polinoma
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> original, std::vector<double> koeficijenti)
{
    if(original.br_redova!=original.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    if(koeficijenti.size()==0)
    {
        AnulirajMatricu(original);
        return original;
    }
    std::vector<Matrica<TipElemenata>> matrice;
    Matrica<TipElemenata> m;
    try
    {
        m = StvoriMatricu<TipElemenata>(original.br_redova, original.br_kolona);
        for(int k=0; k<original.br_redova; k++)
        {
            for(int l=0; l<original.br_kolona; l++)
            {
                if(k==l) m.elementi[k][l]=1;
                else m.elementi[k][l]=0;
            }
        }
        std::vector<Matrica<TipElemenata>> pomocni1;
        
        for(int i=0; i<koeficijenti.size(); i++)
        {
            if(i==0)
            {
                try
                {
                    Matrica<TipElemenata> pom;
                    pom = StvoriMatricu<TipElemenata>(original.br_redova, original.br_kolona);
                    for(int k=0; k<original.br_redova; k++)
                    {
                        for(int l=0; l<original.br_kolona; l++)
                        {
                            if(k==l) pom.elementi[k][l] = koeficijenti[i];
                            else pom.elementi[k][l] = 0;
                        }
                    }
                    matrice.push_back(pom);
                }
                catch(std::bad_alloc)
                {
                    UnistiMatricu(m);
                    throw;
                }
            }
            else
            {
                try
                {
                    pomocni1.push_back(m);
                    m = ProduktMatrica<TipElemenata>(m, original);
                    try
                    {
                        matrice.push_back(PomnoziSkalarSaMatricom<TipElemenata>(m, koeficijenti[i]));
                    }
                    catch(std::bad_alloc)
                    {
                        for(int i=0; i<pomocni1.size(); i++)
                            UnistiMatricu(pomocni1[i]);
                        for(int i=0; i<matrice.size(); i++)
                            UnistiMatricu(matrice[i]);
                        throw;
                    }
                    if(i==koeficijenti.size()-1) pomocni1.push_back(m);
                }
                catch(std::bad_alloc)
                {
                    for(int i=0; i<pomocni1.size(); i++)
                        UnistiMatricu(pomocni1[i]);
                    for(int i=0; i<matrice.size(); i++)
                        UnistiMatricu(matrice[i]);
                    throw;
                }
            }
            
        }
        
        for(int i=0; i<pomocni1.size(); i++)
            UnistiMatricu(pomocni1[i]);
            
        try
        {
            Matrica<TipElemenata> rez(StvoriMatricu<TipElemenata>(original.br_redova, original.br_kolona));
            AnulirajMatricu(rez);
            std::vector<Matrica<TipElemenata>> rezultati;
            
            try
            {
                for(int i=0; i<matrice.size(); i++)
                {
                    rezultati.push_back(rez);
                    rez = ZbirMatrica<TipElemenata>(rez, matrice[i]);
                    
                    if(i==matrice.size()-1) rezultati.push_back(rez);
                }
            }
            catch(std::bad_alloc)
            {
                for(int i=0; i<rezultati.size()-1; i++)
                    UnistiMatricu(rezultati[i]);
                    
                throw;
            }
            
            for(int i=0; i<matrice.size(); i++)
                UnistiMatricu(matrice[i]);
                
            for(int i=0; i<rezultati.size()-1; i++)
                UnistiMatricu(rezultati[i]);
            
            return rez;
        }
        catch(std::bad_alloc)
        {
            for(int i=0; i<matrice.size(); i++)
                UnistiMatricu(matrice[i]);
            throw;
        }
    }
    catch(std::bad_alloc)
    {
        throw;
    }
}

int main() 
{
    Matrica<double> a, b;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try 
    {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        
        int n;
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::vector<double> koef_pol;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i=0; i<=n; i++)
        {
            double broj;
            std::cin >> broj;
            koef_pol.push_back(broj);
            if(i==n) break;
        }
        b = MatricniPolinom(a, koef_pol);
        IspisiMatricu(b, 10);
        UnistiMatricu(b);
    }
    catch(std::bad_alloc) 
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    
    return 0;
}

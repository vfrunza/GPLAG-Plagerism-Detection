#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>

template <typename TipElemenata>
struct Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
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
        {
            mat.elementi[i] = new TipElemenata[br_kolona];
        }
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
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++)
    {
        for(int j = 0; j < mat.br_kolona; j++)
        {
            std::cout << std::setw(sirina_ispisa);
            std::cout << std::setprecision(preciznost);
            std::cout << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati)
    {
        UnistiMatricu(mat);
    }
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
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
    {
        for(int j = 0; j < m2.br_kolona; j++)
        {
            m3.elementi[i][j] = 0;
            for (int k = 0; k < m1.br_kolona; k++)
            {
                m3.elementi[i][j]+=m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, int n, IterTip it)
{
    if(m1.br_kolona != m1.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> mat;
    mat.br_redova = m1.br_redova; mat.br_kolona = m1.br_kolona;
    Matrica<TipElemenata> pom;
    pom.br_redova = m1.br_redova; pom.br_kolona = m1.br_kolona;
    Matrica<TipElemenata> c;
    c.br_redova = m1.br_redova; c.br_kolona = m1.br_kolona;
    try
    {
        mat=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
        pom=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
        c=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    
        //Pravimo da nam je pocetna jedinicna, nju cemo mnozit sa A, pa tu pomnozenu sa A opet itd..
        for(int i=0; i<pom.br_redova; i++)
        {
            for(int j=0; j<pom.br_kolona; j++) 
            {
                if(i==j) pom.elementi[i][j]=1;
                else pom.elementi[i][j]=0;
                mat.elementi[i][j]=0;
            }
        }
        typename std::remove_reference<decltype(*it)>::type mnozitelj;
        
        for(int i=0;i<=n;i++)
        {
            mnozitelj=*it;
            if(i!=0) 
            {
                c=pom;
                pom=ProduktMatrica(c,m1);
            }
            for(int j=0; j<pom.br_redova; j++)
            {
                for(int k=0; k<pom.br_kolona; k++)
                {
                    mat.elementi[j][k]+=pom.elementi[j][k]*mnozitelj;
                }
                
            }
            UnistiMatricu(c);
            it++;
        }
        UnistiMatricu(pom);
    }
    catch(...)
    {
        UnistiMatricu(mat);
        UnistiMatricu(pom);
        throw std::bad_alloc();
    }
    return mat;
}

int main()
{
    Matrica<double> a; // AUTOMATSKA INICIJALIZACIJA!!!
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int m;
    std::cin>>m;
    try
    {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::vector<int> v;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=red;i++)
        {
            int unos;
            std::cin>>unos;
            v.push_back(unos);
        }
        IspisiMatricu(MatricniPolinom(a, red, v.begin()),10,6,true);
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    
    
    return 0;
}
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>

struct Matrica {
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
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];

        for(int i=0; i<br_redova; i++)
            for(int j=0; j<br_kolona; j++)
                mat.elementi[i][j]=0;
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriKopijuMatricu(const Matrica<TipElemenata>&m)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = m.br_redova;
    mat.br_kolona = m.br_kolona;
    mat.elementi = new TipElemenata*[m.br_redova];
    for(int i = 0; i <m.br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < m.br_redova; i++)
            mat.elementi[i] = new TipElemenata[m.br_kolona];

        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
                mat.elementi[i][j]=m.elementi[i][j];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
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
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata>&m1,const Matrica<TipElemenata>&m2)
{
    if(m1.br_kolona!=m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    int suma=0;
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            for(int k=0; k<m1.br_kolona; k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
            suma=0;
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata>Stepenuj(const Matrica<TipElemenata>&m,int n)
{
    Matrica<TipElemenata>m1;
    Matrica<TipElemenata>m2;

    if(n>2) {
        m1=ProduktMatrica(m,m);
        for(int i=2; i<n; i++) {
            m2=ProduktMatrica(m,m1);
            UnistiMatricu(m1);
            m1=m2;
        }
        return m1;
    }

    else if(n==2) {
        UnistiMatricu(m1);
        UnistiMatricu(m2);

        return ProduktMatrica(m,m);
    } else if(n==1) {
        m1=StvoriKopijuMatricu(m);
        UnistiMatricu(m2);

        return m1;
    } else if(n==0) {
        m1=(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
        for(int i=0; i<m.br_redova; i++) {
            for(int j=0; j<m.br_kolona; j++) {
                if(i==j) m1.elementi[i][j]=1;
                else m1.elementi[i][j]=0;
            }
        }
        UnistiMatricu(m2);
        return m1;
    }
}

template<typename TipElemenata>
Matrica<TipElemenata>MnozenjeSkalarom(const Matrica<TipElemenata>&m,double n)
{
    auto m1(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));

    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++) {
            m1.elementi[i][j]=m.elementi[i][j]*n;
        }
    }
    return m1;
}

template<typename TipElemenata>
Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata>&m,std::vector<double>v)
{
    if(m.br_redova!=m.br_kolona)
        throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata>m1;
    Matrica<TipElemenata>m2;
    Matrica<TipElemenata>m3;
    Matrica<TipElemenata>m4;
    if(v.size()==1) {
        m1=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        for(int i=0; i<m.br_redova; i++) {
            for(int j=0; j<m.br_kolona; j++) {
                m1.elementi[i][j]=0;
            }
        }
        return m1;
    }
    m4=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
    for(int i=0; i<v.size(); i++) {
        m2=Stepenuj(m,i);
        m3=MnozenjeSkalarom(m2,v[i]);
        UnistiMatricu(m2);
        m1=ZbirMatrica(m4,m3);
        UnistiMatricu(m3);
        UnistiMatricu(m4);
        m4=m1;
    }
    return m4;
}



int main()
{
    Matrica<double> a, b; // AUTOMATSKA INICIJALIZACIJA!!!
    int m, n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m ;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout <<"Unesite red polinoma: ";
        std::cin>>n;
        std::vector<double>v(n+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<v.size(); i++) {
            std::cin>>v[i];
        }
        IspisiMatricu(b = MatricniPolinom(a,v),10,6);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    return 0;
}
/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<vector>
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
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
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

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona==m2.br_redova)
    {
        int a=m1.br_redova,b=m2.br_kolona;
        TipElemenata suma;
        Matrica<TipElemenata> produkt=StvoriMatricu<TipElemenata>(a,b);
        for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++)
        {
            suma=0;
            for(int k=0;k<m2.br_redova;k++)
            suma+=m1.elementi[i][k]*m2.elementi[k][j];
            produkt.elementi[i][j]=suma;
        }
        return produkt;
    }
        else throw std::domain_error("Matrice nisu saglasne za mnozenje");
}
template<typename TipElemenata>
Matrica<TipElemenata> IstaMatrica(const Matrica<TipElemenata>&m1)
{
    Matrica<TipElemenata> ista=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    for(int i=0;i<m1.br_kolona;i++)
            for(int j=0;j<m1.br_kolona;j++)
            ista.elementi[i][j]=m1.elementi[i][j];
            return ista;
}

template<typename TipElemenata>
void PomnoziSaSkalarom(const Matrica<TipElemenata>&m1, double skalar)
{
    for(int i=0;i<m1.br_kolona;i++)
            for(int j=0;j<m1.br_kolona;j++)
            m1.elementi[i][j]*=skalar;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,std::vector<double> koeficijentiPolinoma)
{
    if(m1.br_kolona==m1.br_redova)
    {
        
        if(koeficijentiPolinoma.size()==0)
        {
            
            
            Matrica<TipElemenata> matricniPolinom=StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_kolona);
            for(int i=0;i<m1.br_kolona;i++)
            for(int j=0;j<m1.br_kolona;j++)
            {
            matricniPolinom.elementi[i][j]=0;
            }
            return matricniPolinom;
         }
        else
        {
            Matrica<TipElemenata> matricniPolinom=StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_kolona),jedinicna=StvoriMatricu<TipElemenata>(m1.br_kolona,m1.br_kolona);
            for(int i=0;i<m1.br_kolona;i++)
            for(int j=0;j<m1.br_kolona;j++)
            {
            if(i==j)
            {
            jedinicna.elementi[i][j]=1;
            matricniPolinom.elementi[i][j]=0;
            }
            else jedinicna.elementi[i][j]=0;
            matricniPolinom.elementi[i][j]=0;
            }
            for(int i=0;i<koeficijentiPolinoma.size();i++)
            {
                Matrica<TipElemenata> pomocna;
                if(i==0)
                {
                    pomocna=IstaMatrica(jedinicna);
                }
                else
                {
                    Matrica<TipElemenata> pomocna2;
                    for(int k=0;k<i;k++)
                    {
                        if(k==0)
                        pomocna=IstaMatrica(m1);
                        else
                        {
                            pomocna2=IstaMatrica(pomocna);
                            UnistiMatricu(pomocna);
                            pomocna=ProduktMatrica(m1,pomocna2);
                        }
                        UnistiMatricu(pomocna2);
                    }
                }
                
                PomnoziSaSkalarom(pomocna,koeficijentiPolinoma[i]);
                for(int m=0;m<m1.br_kolona;m++)
            for(int n=0;n<m1.br_kolona;n++)
            {
            matricniPolinom.elementi[m][n]+=pomocna.elementi[m][n];
            
            }
            UnistiMatricu(pomocna);
            }
            UnistiMatricu(jedinicna);
            return matricniPolinom;
        }
    } 
    else throw std::domain_error("Matrica mora biti kvadratna");
}
template<typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> & m1, int sirina_ispisa=10, int p=6,bool trebaBrisati=false)
{
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m1.br_kolona;j++)
        {
            int ab=m1.elementi[i][j];
            double xr=m1.elementi[i][j]-ab;
            double nula=0.000000001;
            if(xr>nula)
              std::cout<<std::setprecision(p)<<std::setw(sirina_ispisa)<<m1.elementi[i][j];
              else
              std::cout<<std::setw(sirina_ispisa)<<m1.elementi[i][j];
              
        }
            

        std::cout<<"\n";
    }
    if(trebaBrisati) UnistiMatricu(m1);
}

int main()
{
   // Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    Matrica<double> a;
   std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        int red;
        double pm;
        std::vector<double>koeficijentiPolinoma;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=red;i++)
        {
         
         std::cin>>pm;
         koeficijentiPolinoma.push_back(pm);
        }
        Matrica<double> rez=MatricniPolinom(a,koeficijentiPolinoma);
        UnistiMatricu(a);
        IspisiMatricu(rez,10,2,true);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;
}

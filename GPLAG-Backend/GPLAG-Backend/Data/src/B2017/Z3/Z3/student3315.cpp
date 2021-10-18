/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

// Kod sa predavanja preko kojeg se radi zadatak 3

template<typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi)
    return;
    for(int i=0;i<mat.br_redova;i++){
        delete [] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++){
        mat.elementi[i]=nullptr;
    }
    
    try{
        for(int i=0;i<br_redova;i++){
            mat.elementi[i]=new TipElemenata[br_kolona];
        }
    }
    
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
    
}


template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati)
    {
        UnistiMatricu(mat);
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    
    return m3;
}



template<typename T1, typename T2>
Matrica<T1> PomnoziSaSkalarom(const Matrica<T1>& m, T2 x)
{
    Matrica<T1> result(StvoriMatricu<T1>(m.br_redova, m.br_kolona));
    
    for(int i = 0; i < result.br_redova; ++i)
    {
        for(int j = 0; j < result.br_kolona; ++j)
        {
            result.elementi[i][j] = m.elementi[i][j] * x;
        }
    }
    return result;
}


template<typename T>
Matrica<T> prepisiMatricu(const Matrica<T>& m)
{
    Matrica<T> result(StvoriMatricu<T>(m.br_redova, m.br_kolona));
    for(int i = 0; i < result.br_redova; ++i)
    {
        for(int j = 0; j < result.br_kolona; ++j)
        {
            result.elementi[i][j] = m.elementi[i][j];
        }
    }
    return result;
}

template<typename T>
Matrica<T> ProduktMatrica(const Matrica<T> &m1, const Matrica<T> &m2)
{
    if(m1.br_kolona != m2.br_redova)
    {
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    
    auto result(StvoriMatricu<T>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < result.br_redova; ++i)
    {
        for(int j = 0; j < result.br_kolona; ++j)
        {
            double suma(0);
            for(int k = 0; k < m1.br_kolona; ++k)
            {
                  suma +=m1.elementi[i][k] * m2.elementi[k][j];
               // result.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
            result.elementi[i][j]=suma;
        }
    }
    return result;
}

template<typename T1, typename T2>
Matrica<T1> MatricniPolinom(const Matrica<T1>& m, int n, T2 it)
{
    if(n < 0)
    {
        throw std::domain_error("Neispravan stepen polinoma");
    }
    if(m.br_kolona != m.br_redova)
    {
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    Matrica<T1> I(StvoriMatricu<T1>(m.br_redova, m.br_kolona));
    Matrica<T1> result(StvoriMatricu<T1>(m.br_redova, m.br_kolona));
    Matrica<T1> exponent(StvoriMatricu<T1>(m.br_redova, m.br_kolona));
    Matrica<T1> a(StvoriMatricu<T1>(m.br_redova, m.br_kolona));
    for(int i = 0; i < I.br_redova; ++i)
    {
        for(int j = 0; j < I.br_kolona; ++j)
        {
            result.elementi[i][j] = 0;
            exponent.elementi[i][j] = m.elementi[i][j];
            a.elementi[i][j] = m.elementi[i][j];
            if(i != j)
            {
                I.elementi[i][j] = 0;
            }
            else
            {
                I.elementi[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < n + 1; ++i)
    {
        if(i > 0)
        {
            Matrica<T1> tempResult(prepisiMatricu(result));
            Matrica<T1> tempProduct(PomnoziSaSkalarom(exponent, *it));
            UnistiMatricu(result);
            result = ZbirMatrica(tempResult, tempProduct);
            Matrica<T1> tempExponent(prepisiMatricu(exponent));
            UnistiMatricu(exponent);
            exponent = ProduktMatrica(tempExponent, a);
            UnistiMatricu(tempExponent);
            UnistiMatricu(tempProduct);
            UnistiMatricu(tempResult);
        }
        else
        {
            UnistiMatricu(result);
            result = PomnoziSaSkalarom(I, *it);
        }
        ++it;
    }
    UnistiMatricu(I);
    UnistiMatricu(exponent);
    UnistiMatricu(a);
    
    return result;
}


int main ()
{
    
    int n;
   
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    std::cout<<"Unesite elemente matrice A:\n";
    
   
    
    Matrica<double> matrica(StvoriMatricu<double>(n,n));
    
    try{
    UnesiMatricu('A',matrica);
    
    int red;
    std::cout<<"Unesite red polinoma: ";
    std::cin>>red;
    
    std::vector<double> vektor;
    double koef;
    std::cout<<"Unesite koeficijente polinoma: ";
    for(int k=0;k<=red;k++){
        std::cin>>koef;
      vektor.push_back(koef);
    }
    
    Matrica<double> rezultat(MatricniPolinom(matrica,red,vektor.begin()));
    IspisiMatricu<double>(rezultat,10,6,true);
    
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    

    UnistiMatricu(matrica);
	return 0;
}

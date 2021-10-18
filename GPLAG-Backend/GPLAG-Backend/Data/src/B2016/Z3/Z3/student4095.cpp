/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
  int br_redova, br_kolona;
  TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return; //ako niti jedan ne uspije
    for (int i=0; i<mat.br_redova; i++)
        delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata> 
Matrica <TipElemenata> StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; 
    mat.br_kolona=br_kolona;
    mat.elementi=nullptr;
    mat.elementi=new TipElemenata*[br_redova]; //baci li izuzetak, nemamo nista brisati
    for (int i=0; i<br_redova; i++)
        mat.elementi[i]=nullptr;
    try
    {
        for (int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona]; //baci li izuzetak brisemo ono sto je dosada alocirano
        // zbog javljanja neinicijalizova vrijednost
        for (int i=0; i<br_redova; i++)
            for (int j=0; j<br_kolona; j++)
                mat.elementi[i][j]=0;
    }   
    catch (std::bad_alloc)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat)
{
    for (int i=0; i<mat.br_redova; i++)
        for (int j=0; j<mat.br_kolona; j++)
        {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa ,int preciznost=6, bool treba_brisati=false) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if (treba_brisati) 
        UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (Matrica<TipElemenata> mat1, Matrica<TipElemenata> mat2)
{
    if (mat1.br_kolona!=mat2.br_redova)
        throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> produkt(StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona));
    for (int i=0; i<mat1.br_redova; i++)
        for (int j=0; j<mat2.br_kolona; j++)
        {   
            produkt.elementi[i][j]=0;
            for(int k=0; k<mat2.br_redova; k++)
             {
                  produkt.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];
             }
        }
    return produkt;
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for (int i=0; i<m1.br_redova; i++)
        for (int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatriceISkalara (Matrica<TipElemenata> mat, double skalar) //jer je vec poznato da je double
{
    Matrica<TipElemenata> nova(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for (int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++)
            nova.elementi[i][j]=mat.elementi[i][j]*skalar;
    return nova;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> mat, std::vector<double> koeficijenti)
{
    if (mat.br_redova!=mat.br_kolona)
        throw std::domain_error ("Matrica mora biti kvadratna");
    int n(koeficijenti.size());
    Matrica<TipElemenata> nul_matrica(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        for (int i=0; i<mat.br_redova; i++)
            for (int j=0; j<mat.br_kolona; j++)
                nul_matrica.elementi[i][j]=0;
    if (n==0)
        return nul_matrica;
        
    // pomocna1 je za iteraciju, kopija elemenata od poslane matrice
    Matrica<TipElemenata> pomocna1(ZbirMatrica<TipElemenata>(mat, nul_matrica));
    Matrica<TipElemenata> suma(ProduktMatriceISkalara<TipElemenata>(mat, koeficijenti[1]));
    // paziti pomocna2 i pomocna1 ce na kraju svake iteracije pokazivati na isto mjesto u memoriji
    for (int k=2; k<n; k++)
    {
        Matrica<TipElemenata> pomocna2 (ProduktMatrica<TipElemenata>(pomocna1, mat));
        UnistiMatricu<TipElemenata>(pomocna1); //unistiti staru i u nju spremiti novi stepen
        pomocna1=pomocna2;
       
        Matrica<TipElemenata> pomocna3 (ProduktMatriceISkalara<TipElemenata>(pomocna1, koeficijenti[k]));
        Matrica<TipElemenata> pomocna4 (ZbirMatrica(suma, pomocna3));
        UnistiMatricu<TipElemenata>(pomocna3);
        UnistiMatricu<TipElemenata>(suma);
        suma=pomocna4;
    }
    UnistiMatricu<TipElemenata>(pomocna1);
    
    Matrica<TipElemenata> jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona)); //vec ju pri stvori inicijalizira na 0
    for (int i=0; i<jedinicna.br_redova; i++)
        for (int j=0; j<jedinicna.br_kolona; j++)
            if (i==j)
                jedinicna.elementi[i][j]=1;
    Matrica<TipElemenata> pomocna (ProduktMatriceISkalara<TipElemenata>(jedinicna, koeficijenti[0]));
    Matrica<TipElemenata> m_polinom (ZbirMatrica(suma, pomocna));
    
    UnistiMatricu<TipElemenata>(pomocna);
    UnistiMatricu<TipElemenata>(jedinicna);
    UnistiMatricu<TipElemenata>(suma);
    UnistiMatricu<TipElemenata>(nul_matrica);
    return m_polinom; 
}

int main ()
{
    
    int dimenzija;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    try {
        Matrica<double> matrica(StvoriMatricu<double>(dimenzija,dimenzija));
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A', matrica);
        int red_polinoma;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red_polinoma;
        std::vector<double> koeficijenti(red_polinoma+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for (int i=0; i<=red_polinoma; i++)
            std::cin>>koeficijenti[i];
        Matrica<double> mat_polinom(MatricniPolinom<double>(matrica, koeficijenti));
        IspisiMatricu<double>(mat_polinom, 10);
        UnistiMatricu<double>(matrica); 
        UnistiMatricu<double>(mat_polinom);
    }
    catch (std::bad_alloc)
    {
        std::cout<<"Nema dovoljno memorije!"<<std::endl;
    }
    catch (std::domain_error e)
    {
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
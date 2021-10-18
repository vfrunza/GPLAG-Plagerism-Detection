/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <iterator>
#include <vector>

template <typename TipElemenata>
struct Matrica {
     int br_redova, br_kolona;
     TipElemenata **elementi=nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
 
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
 {
     if(!mat.elementi) 
     return;
     
     for(int i=0; i<mat.br_redova; i++) 
     delete[] mat.elementi[i];
     
     delete[] mat.elementi;
     mat.elementi=nullptr;
 }
 
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
 {
     Matrica<TipElemenata> mat;
     mat.br_redova=br_redova; 
     mat.br_kolona=br_kolona;
     mat.elementi=new TipElemenata*[br_redova];
     
     for(int i=0; i<br_redova; i++) 
     mat.elementi[i]=nullptr;
     
     try
     {
         for(int i=0; i<br_redova; i++)
         mat.elementi[i]=new TipElemenata[br_kolona];
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
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
 }
 
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
 {
     for(int i=0; i<mat.br_redova; i++) 
     {
         for(int j=0; j<mat.br_kolona; j++)
         std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
         
         std::cout<<std::endl;
     }
     
     if(treba_brisati)
     UnistiMatricu(mat);
 }
 
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
 {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
     
    auto m3=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
     
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
         m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
         
     return m3;
 }
 
template<typename Tip1>
bool SaglasneZaMnozenje(const Matrica<Tip1> &m1, const Matrica<Tip1> &m2)
{
    //mora broj redova prve matrice biti isti kao broj kolona druge matrice
    if(m1.br_redova!=m2.br_kolona)
    return false;
    else
    return true;
}

template<typename Tip1>
int Umnozak(const Matrica<Tip1> &m1, const Matrica<Tip1> &m2, int i, int j)
{
    int suma(0);
    for(int k=0; k<m2.br_redova; k++)
        suma+=m2.elementi[i][k]*m1.elementi[k][j];
    
    return suma;
}

template<typename Tip1>
Matrica<Tip1> ProduktMatrica (const Matrica<Tip1> &m1, const Matrica<Tip1> &m2)
{
    if(!SaglasneZaMnozenje(m1, m2))
    throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    
    Matrica<Tip1> produkt = StvoriMatricu<Tip1> (m1.br_redova, m2.br_kolona);
        
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
           produkt.elementi[i][j]=Umnozak(m1, m2, i, j);
    
    return produkt;
}

template<typename Tip1>
Matrica<Tip1> StvoriJedinicnu(int br_redova, int br_kolona)
{
    //ne treba u ovoj funkciji brisat ako baci izuzeta, jer to vec radi funkcija iz koje se poziva ova funkcija
    Matrica<Tip1> jedinicna = StvoriMatricu<Tip1>(br_redova, br_kolona);
    
    for(int i=0; i<br_redova; i++)
    {
        for(int j=0; j<br_kolona; j++)
        {
            if(i==j)
            jedinicna.elementi[i][j]=1;
            else
            jedinicna.elementi[i][j]=0;
        }
    }
    
    return jedinicna;
}

template<typename Tip1>
void PomnoziMatricuSaSkalarom(Matrica<Tip1> pomnozi, int skalar) //ne treba referenca jer svakako atributi "elementi" pokazuju na isti alocirani prostor
{
    for(int i=0; i<pomnozi.br_redova; i++)
        for(int j=0; j<pomnozi.br_kolona; j++)
        pomnozi.elementi[i][j]*=skalar;
}

template<typename Tip1>
void SaberiMatrice(Matrica<Tip1> prva, Matrica<Tip1> sljedeca)
{
     for(int i=0; i<prva.br_redova; i++)
        for(int j=0; j<sljedeca.br_kolona; j++)
         prva.elementi[i][j]+=sljedeca.elementi[i][j];
}

template<typename Tip1, typename NekiKontejner> 
Matrica<Tip1> IzracunajPolinom( Matrica<Tip1> A, int stepen_polinoma, typename NekiKontejner::iterator it_neki_kontejner)
{
    //da je stepen polinoma pozitivan je provjereno u funkciji iz koje je ova pozvana 
    
    std::vector<Matrica<Tip1>> vekotr_matrica(stepen_polinoma);
    int i(0);
    vekotr_matrica.at(0) = StvoriJedinicnu<Tip1> (A.br_redova, A.br_kolona);
    //stoji izvan try-bloka jer ako funkcija "StvoriMatricu" ne uspije da je stvori, cisti sama stvari za sobom pozivom funkcije "UnistiMatricu"
    
    if(stepen_polinoma>=1)
    {
        i++;  //moramo "i" povecati zbog dealociranja u catch bloku
        vekotr_matrica.at(1)=A;
    }
    
    try
    {
        for( i=2; i<stepen_polinoma; i++)
        {
            vekotr_matrica.at(i) = ProduktMatrica <Tip1> (vekotr_matrica.at(i-1), A);
        }
    }
    catch(...)
    {
        for(int j=0; j<i; j++)        //krece od keca, jer ako se on uspije stvoriti, a ostatk ne, mora ga neko obrisati. Da ide do "i", naredba ".at(j)" bi bila out_of_range
        UnistiMatricu( vekotr_matrica.at(j) );
        
        throw;  //da nema ovoga doslo bi dole do duplog brisanja 
    }
    
    for(int k=0; k<vekotr_matrica.size(); k++)
    {
        PomnoziMatricuSaSkalarom<Tip1>( vekotr_matrica.at(k), *it_neki_kontejner);
        std::advance(it_neki_kontejner, 1);
    }
    
    for(int k=1; k<vekotr_matrica.size(); k++)    //ide od keca, jer se sve druge matrice sabiraju/oduzimaju na prvu u vektoru matrica
    SaberiMatrice<Tip1> (vekotr_matrica.at(0), vekotr_matrica.at(k));
    
    for(int k=1; k<vekotr_matrica.size(); k++)
    UnistiMatricu(vekotr_matrica.at(k));  //ne unistava se prva, jer se ona vraca
    
    return vekotr_matrica.at(0);
}

template <typename Tip1, typename NekiKontejner> 
Matrica<Tip1> MatricniPolinom(Matrica<Tip1> A, int stepen_polinoma, typename NekiKontejner::iterator it_neki_kontejner)
{
    if(stepen_polinoma<0)
    throw std::domain_error ("Neispravan stepen polinoma");
    
    if(A.br_redova!=A.br_kolona)
    throw std::domain_error ("Matrica mora biti kvadratna");
    
    Matrica<Tip1> matricni_polinom = IzracunajPolinom<Tip1, NekiKontejner> (A, stepen_polinoma, it_neki_kontejner);
    
    return matricni_polinom;    
}

int main ()
{
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int br_red_kol;
    std::cin>>br_red_kol;
    
    Matrica<int> A;
    try
    {
        A=StvoriMatricu<int>(br_red_kol, br_red_kol);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;;
        UnesiMatricu('A', A);
        
        std::cout<<"Unesite red polinoma: ";
        int red_polinoma;
        std::cin>>red_polinoma;
        
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<int> stepeni_polinoma(red_polinoma+1);
        
        for(int i=0; i<=red_polinoma; i++)
            std::cin>>stepeni_polinoma.at(i);
        
        Matrica<int> m_polinom = MatricniPolinom< int, std::vector<int> > (A, (red_polinoma+1), stepeni_polinoma.begin());
        
        IspisiMatricu(m_polinom, 10, 6);
        
        
        UnistiMatricu(m_polinom);
        //UnistiMatricu(A);
    }
    catch(std::domain_error poruka)
    {
        std::cout<<poruka.what();
        UnistiMatricu(A);
    }
    catch(...)
    {
        std::cout<<"Ja uhvatio nesto";
    }
	return 0;
}

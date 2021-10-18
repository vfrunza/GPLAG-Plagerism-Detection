/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return; 
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=nullptr;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
            for(int i=0; i<br_redova; i++) 
                for(int j=0; j<br_kolona; j++)
                    mat.elementi[i][j]=0;
    } catch (std::bad_alloc) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    //provjera da li se poslane matrice mogu sabirati
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    //provjera jesu li saglasne za mnozenje
    if(!m1.br_kolona==m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            double suma(0);
            for(int k=0; k<m2.br_redova; k++) 
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProizvodSaSkalarom(const Matrica<TipElemenata> &m1, double broj) {
    Matrica<TipElemenata> m2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++) 
        for(int j=0; j<m1.br_kolona; j++)
            m2.elementi[i][j]=broj*m1.elementi[i][j];
    return m2;
}

template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom ( Matrica<TipElemenata> a, int n, IterTip pocetak) {
    if(n<0)
        throw std::domain_error("Neispravan stepen polinoma");
    if(a.br_kolona!=a.br_redova)
        throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> nul_m(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
        for(int i=0; i<a.br_redova; i++) //kom
            for(int j=0; j<a.br_kolona; j++)
                nul_m.elementi[i][j]=0;
    Matrica<TipElemenata> pom_mat1(ZbirMatrica(a, nul_m));
    Matrica<TipElemenata> jedinicna_mat(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona)); //inicijalizirano na 0
    for(int i=0; i<a.br_redova; i++)
        for(int j=0; j<a.br_kolona; j++)
            if(i==j) jedinicna_mat.elementi[i][j]=1;
    Matrica<TipElemenata> prvi_sabirak(ProizvodSaSkalarom<TipElemenata>(jedinicna_mat, *pocetak));
   
    pocetak++;
    Matrica<TipElemenata> suma(ProizvodSaSkalarom<TipElemenata>(a, *pocetak));
    
    pocetak++;
    for(int i=2; i<=n; i++) {
        Matrica<TipElemenata> pom_mat2(ProduktMatrica<TipElemenata>(pom_mat1,a));
        UnistiMatricu<TipElemenata>(pom_mat1);
        pom_mat1=pom_mat2;
        
        Matrica<TipElemenata> pom_mat3(ProizvodSaSkalarom<TipElemenata>(pom_mat1, *pocetak));
        Matrica<TipElemenata> pom_mat4(ZbirMatrica(pom_mat3, suma));
        UnistiMatricu<TipElemenata>(pom_mat3);
        UnistiMatricu<TipElemenata>(suma);
        suma=pom_mat4;
        pocetak++;
    }
    Matrica<TipElemenata> mat_polinom(ZbirMatrica(suma, prvi_sabirak));
    UnistiMatricu<TipElemenata>(nul_m);
    UnistiMatricu<TipElemenata>(pom_mat1);
    UnistiMatricu<TipElemenata>(jedinicna_mat);
    UnistiMatricu<TipElemenata>(prvi_sabirak);
    UnistiMatricu<TipElemenata>(suma);
    return mat_polinom;
}

int main ()
{
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    std::cin>>dimenzija; try {
    Matrica<double> a(StvoriMatricu<double>(dimenzija, dimenzija));
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int red_p;
        std::cin>>red_p;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti_p(red_p+1);
        for(int i=0; i<=red_p; i++)
            std::cin>>koeficijenti_p[i];
        Matrica<double> rezultat(MatricniPolinom<double>(a, red_p, koeficijenti_p.begin()));
        IspisiMatricu<double>(rezultat, 10);
        UnistiMatricu<double>(a);
        UnistiMatricu<double>(rezultat);
    } catch (std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    } catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}

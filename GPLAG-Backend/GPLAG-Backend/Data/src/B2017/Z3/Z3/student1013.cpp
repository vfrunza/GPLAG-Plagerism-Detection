/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using namespace std;

template <typename TipElemenata>
struct Matrica {
    int broj_redova, broj_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;

    int i(0);
    for(i=0; i<mat.broj_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int broj_redova)
{
    Matrica<TipElemenata> mat;
   // TipElemenata **mat(new TipElemenata *[broj_redova]);
    mat.broj_redova = broj_redova;
    mat.broj_kolona = broj_redova;
    mat.elementi = new TipElemenata*[broj_redova];
    for(int i=0; i<broj_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<broj_redova; i++) mat.elementi[i] = new TipElemenata[broj_redova];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.broj_redova; i++) {
        for(int j=0; j<mat.broj_redova; j++) {
            std::cout<<ime_matrice <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    
    for(int i=0; i<mat.broj_redova; i++) {
        for(int j=0; j<mat.broj_redova; j++) {
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost);
            std::cout<<"("<<i<<","<<j<<") = " << mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
      if(m1.broj_kolona != m2.broj_redova || m1.broj_redova != m2.broj_kolona)
         throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.broj_redova));
    for(int i=0; i<m1.broj_redova; i++) {
        for(int j=0; j<m1.broj_redova; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
      if(m1.broj_kolona != m2.broj_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.broj_redova));
    for(int i=0; i<m1.broj_redova; i++) {
        for(int j=0; j<m1.broj_redova; j++) {
            for(int k=0; k<m1.broj_redova; k++)
                m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &mat, int n, std::vector<int>::iterator pok)
{

    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    //if(mat.broj_kolona != mat.broj_redova) std::domain_error("Matrica mora biti kvadratna");

    auto mat_k(StvoriMatricu<TipElemenata>(mat.broj_redova));
    for(int i=0; i<mat.broj_redova; i++) {
        for(int j=0; j<mat.broj_redova; j++) mat_k.elementi[i][j]=0;
    }

    int red(0);

    for(int i=0; i<=n; i++) {

        auto mat_p(StvoriMatricu<TipElemenata>(mat.broj_redova));

        for(int k=0; k<mat.broj_redova; k++) {
            for(int j=0; j<mat.broj_redova; j++) {
                if(k==j) mat_p.elementi[k][j] = 1;
                else mat_p.elementi[k][j] = 0;
            }
        }
        for(int j=0; j<red; j++) mat_p=ProduktMatrica(mat_p, mat);
        auto mat_s=mat_p;
        if(*pok < 0) {for(int j=(*pok)+1; j<0; j++) mat_p=ZbirMatrica(mat_p, mat_s);
            for(int k=0; k<mat.broj_redova; k++) {
                for(int j=0; j<mat.broj_redova; j++) {
                    mat_p.elementi[k][j] *=(-1);
                }
            }
        }
        else if(*pok > 0) for(int j=1; j<(*pok); j++) mat_p=ZbirMatrica(mat_p, mat_s);
        else if(*pok == 0) {
            for(int k=0; k<mat.broj_redova; k++) {
                for(int j=0; j<mat.broj_redova; j++) {
                    mat_p.elementi[k][j] = 0;
                }
            }
        }
        auto mat_k=ZbirMatrica(mat_k, mat_p);
        pok++;
        red++;*/
    }
    return mat_k;
}


int main ()
{
    Matrica<double> A;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int broj_redova_i_kolona;
    std::cin>>broj_redova_i_kolona;
    try {
        A = StvoriMatricu<double>(broj_redova_i_kolona);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A', A);
        std::cout<<"Unesite red polinoma: ";
        int red_polinoma;
        std::cin>>red_polinoma;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<int> koeficijenti;
        for(int i=0; i<=red_polinoma; i++) {
            int n;
            std::cin>>n;
            koeficijenti.push_back(n);
        }
        Matrica<double> B;
        B = MatricniPolinom(A, red_polinoma, koeficijenti.begin());
        IspisiMatricu(B, 10, 6, true);
        UnistiMatricu(A);
        
    } catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!"<<std::endl;
    } catch(...) {

    }
    
    return 0;
}

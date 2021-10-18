/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <iterator>
#include <vector>

template <typename TipElementa>
struct Matrica {
    int br_redova, br_kolona;
    TipElementa **elementi = nullptr;
};

template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElementa> mat;
    try {
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        mat.elementi = new TipElementa*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElementa[br_kolona];
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElementa>
void UnesiMatricu(char ime_matrice, Matrica<TipElementa> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElementa>//Dodati "treba_brisati"
void IspisiMatricu(const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost , bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << std::fixed << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j] ;
        }
        std::cout << std::endl;
    }

    if(treba_brisati) {
        UnistiMatricu(mat);
    }
}

template <typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    try {

        if(m1.br_redova != m2.br_redova || m1.br_kolona != m1.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipElementa> m3;
        try {
            m3=StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona);
        } catch (...) {
            UnistiMatricu(m3);
            UnistiMatricu(m2);
            UnistiMatricu(m1);
            throw;
        }

        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m1.br_kolona; j++) {
                m3.elementi[i][j] = m1.elementi[i][j]+m2.elementi[i][j];
            }
        }

        return m3;
    } catch(...) {
        throw;
    }
}

template <typename TipElementa> //Produkt matrica URAĐENO!
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    try {
        if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    } catch (std::domain_error poruka) {
        std::cout << poruka.what() ;
        UnistiMatricu(m1);
        UnistiMatricu(m2);
        throw;
    }

    Matrica<TipElementa> m3;
    try {
        m3 = StvoriMatricu<TipElementa>(m1.br_redova,m2.br_kolona);

        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m1.br_kolona; j++) {
                m3.elementi[i][j]= {};
            }
        }

        for(int i=0; i<m1.br_redova; i++) {
            int sumator(0);
            for(int j=0; j<m1.br_kolona; j++) {
                for(int k=0; k<m2.br_kolona; k++) {
                    j=0;
                    for (int l=0; l<m2.br_redova; l++) {
                        m3.elementi[i][sumator]+=m1.elementi[i][j]*m2.elementi[l][k];
                        j++;
                    }
                    sumator++;
                }

            }
        }

        return m3;
    } catch(...) {
        UnistiMatricu(m3);
        UnistiMatricu(m1);
        UnistiMatricu(m2);
        throw;
    }


}

template <typename TipElementa,typename TipElementa2>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &m, int n, TipElementa2 ip)
{

    if(n<0) {
        UnistiMatricu(m);
        throw std::domain_error("Neispravan stepen polinoma");
    }

    if(m.br_redova!=m.br_kolona) {
        UnistiMatricu(m);
        throw std::domain_error("Matrica mora biti kvadratna");
    }

    auto matricni_polinom=StvoriMatricu<TipElementa>(m.br_redova,m.br_kolona);
    

        Matrica<TipElementa> povratna_matrica = StvoriMatricu<TipElementa>(m.br_redova,m.br_kolona);
  

    for(int i=0; i<povratna_matrica.br_redova; i++)
        for(int j=0; j<povratna_matrica.br_kolona; j++) povratna_matrica.elementi[i][j]=0; //kreirana povratna_matrica matrica

    for(int k=0; k<=n; k++) {

        if(k==0) {
            
            auto jedinicna_matrica=StvoriMatricu<TipElementa> (m.br_redova,m.br_kolona);

            for(int i=0; i<jedinicna_matrica.br_redova; i++) {
                for(int j=0; j<jedinicna_matrica.br_kolona; j++) {
                    if(j==i) jedinicna_matrica.elementi[i][j]=1;
                    else jedinicna_matrica.elementi[i][j]=0;
                }//pravimo jedinicnu matricu
            }

            for(int i=0; i<matricni_polinom.br_redova; i++) {
                for(int j=0; j<matricni_polinom.br_kolona; j++) {
                    matricni_polinom.elementi[i][j]=jedinicna_matrica.elementi[i][j]*(*ip);
                }
            }
            UnistiMatricu(jedinicna_matrica);
        }//Prvi clan sume... mnozi skalar i jedinicnu matricu

        else if(k==1) {
            for(int i=0; i<matricni_polinom.br_redova; i++) {
                for(int j=0; j<matricni_polinom.br_kolona; j++) {
                    matricni_polinom.elementi[i][j]=m.elementi[i][j]*(*ip);
                }
            }
        }//Drugi clan... mnozi skalar i orginalnu matricu

        else {
            auto pomocna=StvoriMatricu<TipElementa>(m.br_redova,m.br_kolona);

            for(int i=0; i<pomocna.br_redova; i++) {
                for(int j=0; j<pomocna.br_kolona; j++) {
                    if(j==i) pomocna.elementi[i][j]=1;
                    else pomocna.elementi[i][j]=0;
                }
            }//Pravimo jedinicnu matricu

            for(int i=0; i<k; i++) {
                auto privremena=pomocna;
                pomocna=ProduktMatrica(privremena,m);
                UnistiMatricu(privremena);
            }//Stepenujemo matricu

            for(int i=0; i<matricni_polinom.br_redova; i++) {
                for(int j=0; j<matricni_polinom.br_kolona; j++) {
                    matricni_polinom.elementi[i][j]=pomocna.elementi[i][j]*(*ip);
                }
            }//Mnozimo matricu skalarom

            UnistiMatricu(pomocna);
        }

        ip++;
        auto dosadasnja_matrica=povratna_matrica;
        dosadasnja_matrica=ZbirMatrica(povratna_matrica,matricni_polinom);

        for(int i=0; i<povratna_matrica.br_redova; i++) {
            for(int j=0; j<povratna_matrica.br_kolona; j++) {
                povratna_matrica.elementi[i][j]=dosadasnja_matrica.elementi[i][j];
            }
        }

        UnistiMatricu(dosadasnja_matrica);
    }
    UnistiMatricu(matricni_polinom);
    return povratna_matrica;
}

int main ()
{
    Matrica<double> a, c;
    int m,red_polinoma;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;

    try {
        a=StvoriMatricu<double> (m,m);

        std::cout <<"Unesite elemente matrice A:";
        std::cout << std::endl;
        UnesiMatricu('A',a);

        std::cout << "Unesite red polinoma: ";
        std::cin >> red_polinoma;

        std::vector<int> koef_polinoma;
        int pom;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i=0; i<=red_polinoma; i++) {
            std::cin >> pom;
            koef_polinoma.push_back(pom);
        }

        IspisiMatricu(c=MatricniPolinom(a,red_polinoma,koef_polinoma.begin()),10,0,true);
        UnistiMatricu(a);
        return 0;

    } catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what();
    } catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;
}

/B2017/2018: Zadaća 3, Zadatak 3
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

//Doradjivanje funkcije IspisiMatricu
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::fixed<<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati==true) UnistiMatricu(mat);
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

//Dodajemo funkciju ProduktMatrica
template<typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica <TipElementa> &m1,const Matrica<TipElementa> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto produkt(StvoriMatricu<TipElementa>(m1.br_redova,m2.br_kolona));
    for(int i(0); i<m1.br_redova; i++) {
        TipElementa pomocna(0);
        int j(0);
        for( j=0; j<m2.br_kolona; j++) {
            for(int k(0); k<m1.br_kolona; k++) {
                pomocna+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            produkt.elementi[i][j]=pomocna;
            pomocna=0;
        }
    }
    return produkt;
}
template<typename TipElementa, typename Tip>
void PomnoziSkalarom( Matrica<TipElementa> &mat, Tip x)
{
    for(int i(0); i<mat.br_redova; i++) {
        for(int j(0); j<mat.br_kolona; j++) {
            mat.elementi[i][j]=mat.elementi[i][j]*x;
        }
    }
}
//Funkcija MatricniPolinom
template <typename TipElementa, typename Tip>
Matrica<TipElementa> MatricniPolinom(const Matrica <TipElementa> A, int n,Tip pocetak)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElementa> MatPolinom,pomocna;
    try {
        MatPolinom=StvoriMatricu<TipElementa>(A.br_redova,A.br_kolona);
    } catch(std::bad_alloc) {
        UnistiMatricu(MatPolinom);
        throw;
    }
    try {
        pomocna=StvoriMatricu<TipElementa>(A.br_redova,A.br_kolona);
    } catch(std::bad_alloc) {
        UnistiMatricu(MatPolinom);
        UnistiMatricu(pomocna);
        throw;
    }
    for(int i(0); i<A.br_redova; i++) {
        for(int j(0); j<A.br_kolona; j++) {
            MatPolinom.elementi[i][j]=0;
            pomocna.elementi[i][j]=A.elementi[i][j];
        }
    }
    auto prva(*pocetak);
    int broji(0);
    while(broji<=n) {
        Matrica<TipElementa> pomnozistepen;
        try {
            pomnozistepen=StvoriMatricu<TipElementa>(A.br_redova,A.br_kolona);
            for(int i(0); i<A.br_redova; i++) {
                for(int j(0); j<A.br_kolona; j++) {
                    if(i==j) pomnozistepen.elementi[i][j]=1;
                    else pomnozistepen.elementi[i][j]=0;
                }
            }
            int novibroji(0);
            while(novibroji<broji) {
                Matrica <TipElementa> pom;
                if(broji==0) {
                    for(int i(0); i<A.br_redova; i++) {
                        for(int j(0); j<A.br_kolona; j++) {
                            if(i==j) MatPolinom.elementi[i][j]=1;
                            else MatPolinom.elementi[i][j]=0;
                        }
                    }
                    break;
                } else {
                    try {
                        pom=ProduktMatrica(pomocna,pomnozistepen);
                        for(int i(0); i<A.br_redova; i++) {
                            for(int j(0); j<A.br_kolona; j++) {
                                pomnozistepen.elementi[i][j]=pom.elementi[i][j];
                            }
                        }
                        UnistiMatricu(pom);
                        novibroji++;
                    } catch(std::bad_alloc) {
                        UnistiMatricu(MatPolinom);
                        UnistiMatricu(pomocna);
                        UnistiMatricu(pomnozistepen);
                        UnistiMatricu(pom);
                        throw;
                    }
                }
            }
            if(broji==0) {
                PomnoziSkalarom(MatPolinom,*pocetak);
            } else {
                PomnoziSkalarom(pomnozistepen,*pocetak);
                 Matrica<TipElementa> zbir;
                try {
                    zbir=ZbirMatrica(MatPolinom,pomnozistepen);
                    for(int i(0); i<A.br_redova; i++) {
                        for(int j(0); j<A.br_kolona; j++) {
                            MatPolinom.elementi[i][j]=zbir.elementi[i][j];
                        }
                    }
                    UnistiMatricu(zbir);
                } catch(std::bad_alloc) {
                    UnistiMatricu(zbir);
                    UnistiMatricu(MatPolinom);
                    UnistiMatricu(pomocna);
                    UnistiMatricu(pomnozistepen);
                    throw;
                }
            }
            pocetak++;
            novibroji=0;
            UnistiMatricu(pomnozistepen);
            broji++;
        } catch(std::bad_alloc) {
            UnistiMatricu(MatPolinom);
            UnistiMatricu(pomocna);
            UnistiMatricu(pomnozistepen);
            throw;
        }
    }
    for(int i(0); i<A.br_redova; i++) {
        for(int j(0); j<A.br_kolona; j++) {
            if(i==j)MatPolinom.elementi[i][j]+=prva;
        }
    }
    UnistiMatricu(pomocna);
    return MatPolinom;
}
int main()
{
    Matrica<double> a, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >>  n;
    std::cout << "Unesite elemente matrice A:" << std::endl;
    try {
        a = StvoriMatricu<double>(n, n);
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<int> polinom;
        for(int i(0); i<=red; i++) {
            int unos;
            std::cin>>unos;
            polinom.push_back(unos);
        }
        IspisiMatricu(c = MatricniPolinom(a,red, polinom.begin()),10);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    } catch(std::domain_error poruka) {
        std::cout << poruka.what() << std::endl;
    } 
    UnistiMatricu(a);
    UnistiMatricu(c);
    return 0;
}
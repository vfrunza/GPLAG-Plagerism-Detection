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
            mat.elementi[i] = new TipElemenata[br_kolona]();
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
                   int sirina_ispisa,int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }

    if(treba_brisati)
        UnistiMatricu(mat);
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{

    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");

    Matrica<TipElemenata> rezultat(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));

    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            TipElemenata zbir {0};
            for(int k=0; k<m1.br_kolona; k++) {

                zbir+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            rezultat.elementi[i][j]=zbir;
        }
    }

    return rezultat;

}

template <typename TipElemenata>
Matrica<TipElemenata> DubokaKopija(const Matrica<TipElemenata> &mat)
{
    Matrica<TipElemenata> rezultat(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            rezultat.elementi[i][j]=mat.elementi[i][j];
        }
    }
    return rezultat;
}

template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int n, IterTip iterator)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_kolona!=A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> sabirak(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    Matrica<TipElemenata> stepen(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    Matrica<TipElemenata> rezultat(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
    for(int i=0; i<=n; i++) {

        if(i==0) {
            //kreiramo jedinicnu
            for(int i=0; i<A.br_redova; i++) {
                sabirak.elementi[i][i]=1;
            }
        }

        else {

            auto unistiva(sabirak);
            sabirak=DubokaKopija(stepen);
            UnistiMatricu(unistiva);


        }

        auto zaUnistit(stepen);
        stepen=ProduktMatrica(sabirak,A);
        UnistiMatricu(zaUnistit);

        for(int i=0; i<A.br_redova; i++) {
            for(int j=0; j<A.br_kolona; j++) {
                sabirak.elementi[i][j]*=*iterator;
            }
        }

        iterator++;
        zaUnistit=rezultat;
        rezultat=ZbirMatrica(rezultat,sabirak);
        UnistiMatricu(zaUnistit);


    }
    UnistiMatricu(stepen);
    UnistiMatricu(sabirak);
    return rezultat;

}



int main()
{
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    Matrica<double> a;

    try {
        a = StvoriMatricu<double>(n,n);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu<double>('A',a);
        std::cout<<"Unesite red polinoma: ";
        int k;
        std::cin>>k;
        std::vector<double> koef(k+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<=k; i++) {
            std::cin>>koef.at(i);
        }
        auto poli(MatricniPolinom(a,k,koef.begin()));
        IspisiMatricu(poli,10,6,true);
        
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    return 0;
}
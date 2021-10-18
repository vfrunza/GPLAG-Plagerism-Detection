/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <list>
#include <iterator>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata** elementi=nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat) {
        if (mat.elementi==nullptr) return;
        for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova]{};
        try {
            for (int i=0; i<br_redova; i++) {
                mat.elementi[i]=new TipElemenata[br_kolona];
            }
        }
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout << std::right << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            }
            std::cout << std::endl;
        }
        if (treba_brisati) UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) {
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        }
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for (int i=0; i<m1.br_redova; i++) {
            for (int j=0; j<m1.br_kolona; j++) {
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            }
        }
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_kolona!=m2.br_redova) {
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        }
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for (int i=0; i<m1.br_redova; i++) {
            for (int j=0; j<m1.br_kolona; j++) {
                TipElemenata rezultat;
                rezultat=TipElemenata();
                for (int k=0; k<m1.br_kolona; k++) {
                    rezultat=rezultat+((m1.elementi[i][k])*(m2.elementi[k][j]));
                }
                m3.elementi[i][j]=rezultat;
            }
        }
        return m3;
    }
    
template <typename TipElemenata, typename IterTip>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, int n, IterTip pocetak) {
        if (n<0) throw std::domain_error("Neispravan stepen polinoma");
        if (mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
        int p(mat.br_redova), q(mat.br_kolona);
        Matrica<TipElemenata> polinom;
        polinom=StvoriMatricu<TipElemenata>(p, q);
        for (int i=0; i<p; i++) {
            for (int j=0; j<q; j++) {
                if (i==j) polinom.elementi[i][j]=*pocetak;
                else polinom.elementi[i][j]=0;
            }
        }
        pocetak++;
        Matrica<TipElemenata> stepen;
        for (int i=1; i<=n; i++) {
            Matrica<TipElemenata> prethodna;
            prethodna=polinom;
            Matrica<TipElemenata> pomnozeni_stepen;
            if (i==1) {
                stepen=StvoriMatricu<TipElemenata>(p, q);
                for (int i=0; i<p; i++) {
                    for (int j=0; j<q; j++) {
                        stepen.elementi[i][j]=mat.elementi[i][j];
                    }
                }
                pomnozeni_stepen=StvoriMatricu<TipElemenata>(p, q);
                for (int i=0; i<p; i++) {
                    for (int j=0; j<q; j++) {
                        pomnozeni_stepen.elementi[i][j]=(stepen.elementi[i][j])*(*pocetak);
                    }
                }
            }
            else {
                pomnozeni_stepen=StvoriMatricu<TipElemenata>(p, q);
                Matrica<TipElemenata> prethodna_p;
                prethodna_p=stepen;
                stepen=ProduktMatrica<TipElemenata>(stepen, mat);
                UnistiMatricu<TipElemenata>(prethodna_p);
                for (int i=0; i<p; i++) {
                    for (int j=0; j<q; j++) {
                        pomnozeni_stepen.elementi[i][j]=(stepen.elementi[i][j])*(*pocetak);
                    }
                }
            }
            polinom=ZbirMatrica<TipElemenata>(polinom, pomnozeni_stepen);
            UnistiMatricu<TipElemenata>(pomnozeni_stepen);
            UnistiMatricu<TipElemenata>(prethodna);
            pocetak++;
        }
        UnistiMatricu<TipElemenata>(stepen);
        return polinom;
    }

int main ()
{
    Matrica<double> a;
    int dimenzija(0);
    int n(0);
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija;
    try {
        a=StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::cout << "Unesite koeficijente polinoma: ";
        std::list<double> lista;
        for (int i=0; i<=n; i++) {
            double p(0.);
            std::cin >> p;
            lista.push_back(p);
        }
        IspisiMatricu(MatricniPolinom(a, n, lista.begin()), 10, 6, true);
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
	return 0;
}

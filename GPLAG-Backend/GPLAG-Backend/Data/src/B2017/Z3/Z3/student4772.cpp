/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu (Matrica<TipElemenata> mat) {
        if (!mat.elementi) return;
        for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova; mat.br_kolona=br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        try {
            for (int i=0; i<br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch (...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }

template <typename TipElemenata>
    void UnesiMatricu (char ime_matrice, Matrica<TipElemenata>&mat) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
    }
    
template <typename TipElemenata>
    void IspisiMatricu (const Matrica<TipElemenata>&mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                std::cout << std::setw(sirina_ispisa) << std::setprecision (preciznost) << mat.elementi[i][j];
            }
            std::cout << std::endl;
        }
        if (treba_brisati) {
            UnistiMatricu(mat);
        }
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProizvodMatriceISkalara (const Matrica<TipElemenata>&m, TipElemenata skalar) {
        auto m2 (StvoriMatricu<double>(m.br_redova, m.br_kolona));
        for (int i = 0; i < m.br_redova; i++) {
            for (int j = 0; j < m.br_kolona; j++) {
                m2.elementi[i][j] = m.elementi[i][j];
                m2.elementi[i][j] *= skalar;
            }
        }
        return m2;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2) {
        if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) 
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for (int i=0; i<m1.br_redova; i++) {
            for (int j=0; j<m1.br_kolona; j++) {
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            }
        }
        return m3;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2) {
        if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for (int i=0; i<m1.br_redova; i++) {
            for (int j=0; j<m2.br_kolona; j++) {
                m3.elementi[i][j]=0;
            }
        }
        for (int i=0; i<m1.br_redova; i++) {
            for (int j=0; j<m2.br_kolona; j++) {
                for (int k=0; k< m1.br_kolona; k++) {
                    m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
                }
            }
        }
        return m3;
    }

template <typename TipElemenata, typename ItTip>
    Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata>&A, int n, ItTip p) {
         if (n<0) throw std::domain_error ("Neispravan stepen polinoma");
         if (A.br_kolona!=A.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
         auto matpolinom (StvoriMatricu<TipElemenata> (A.br_redova, A.br_kolona));
         for (int i = 0; i < A.br_redova; i++) {
             for (int j = 0; j < A. br_kolona; j++) {
                 matpolinom.elementi[i][j] = 0;
             }
         }
         auto proizvod (StvoriMatricu<TipElemenata> (A.br_redova, A.br_kolona));
         for (int i = 0; i <= n; i++) {
            if (i == 0) {
                for (int k = 0; k < A.br_redova; k++) {
                     for (int l = 0; l < A.br_kolona; l++) {
                         if (k == l) proizvod.elementi[k][l] = 1;
                         else proizvod.elementi[k][l] = 0;
                    }
                }
            }
            else {
               if (i % 2 != 0) {
                    for (int k = 0; k < A.br_redova; k++) {
                        for (int l = 0; l < A.br_kolona; l++) {
                            proizvod.elementi[k][l] = A.elementi[k][l];
                         }
                    }   
               }
               else {
                   for (int j = 0; j < A.br_redova; j++) {
                       for (int k = 0; k<A.br_kolona; k++) {
                           if (j == k) proizvod.elementi[j][k] = 1;
                           else proizvod.elementi[j][k] = 0;
                       }
                   }
               }
                for (int j = 0; j < i/2; j++) {
                    auto kvadrat = ProduktMatrica (A, A);
                    auto trenutni = proizvod;
                    proizvod = ProduktMatrica (trenutni, kvadrat);
                    UnistiMatricu(kvadrat);
                    UnistiMatricu(trenutni);
                }
            }
            auto trenutni = matpolinom;
            auto pomocni_proizvod = ProizvodMatriceISkalara(proizvod, *p);
            matpolinom = ZbirMatrica (matpolinom, pomocni_proizvod);
          /*  std::cout << "Koeficijent " << *p << " puta matrica "; 
            IspisiMatricu(proizvod, 10); 
            std::cout << " daje: "<< std::endl;
            IspisiMatricu(pomocni_proizvod, 10);*/
            p++;
            UnistiMatricu(pomocni_proizvod);
            UnistiMatricu(trenutni);
         }
         UnistiMatricu(proizvod);
         return matpolinom;
     }

int main ()
{
    Matrica<double> a, polinom;
    a.elementi = nullptr;
    polinom.elementi = nullptr;
    try {
        int n;
        std::cout << "Unesite dimenziju kvadratne matrice: ";
        std::cin >> n;
        a = StvoriMatricu<double>(n,n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int r; 
        std::cin >> r;
        std::vector<double> koeficijenti;
        std::cout << "Unesite koeficijente polinoma: ";
        for (int i = 0; i <= r; i++) {
            int broj;
            std::cin >> broj;
            koeficijenti.push_back (broj);
        }
        polinom = MatricniPolinom<double>(a, r, koeficijenti.begin());
        IspisiMatricu (polinom, 10);
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(polinom);
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <iterator>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu(Matrica <TipElemenata> mat) {
        if (!mat.elementi) return;
        for (int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata *[br_redova];
        for (int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try {
            for (int i = 0; i < br_redova; i++)
                mat.elementi[i] = new TipElemenata [br_kolona];
        }
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }

template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica <TipElemenata> &mat) {
        for (int i = 0; i < mat.br_redova; i++)
            for (int j = 0; j < mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }

template <typename TipElemenata>
    void IspisiMatricu(const Matrica <TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati = false) {
        preciznost = 6;
        for (int i = 0; i < mat.br_redova; i++) {
            for (int j = 0; j < mat.br_kolona; j++)
                std::cout << std::setw(10) << std::setprecision(preciznost) << mat.elementi[i][j];
            std::cout << std::endl;
        }
        if (treba_brisati) UnistiMatricu(mat);
    }

template <typename TipElemenata>
    Matrica <TipElemenata> ZbirMatrica(const Matrica <TipElemenata> &m1, const Matrica <TipElemenata> &m2) {
        if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu <TipElemenata>(m1.br_redova, m1.br_kolona));
        for (int i = 0; i < m1.br_redova; i++)
            for (int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1. elementi[i][j] + m2.elementi[i][j];
    return m3;
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> ProduktMatrica(const Matrica <TipElemenata> &m1, const Matrica <TipElemenata> &m2) {
        if (m1.br_kolona != m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        Matrica <TipElemenata> m3(StvoriMatricu <TipElemenata>(m1.br_redova, m2.br_kolona));
        for (int i = 0; i < m1.br_redova; i++) {
            for (int j = 0; j < m2.br_kolona; j++) {
                double suma (0);
                for (int k = 0; k < m2.br_redova; k++) {
                    suma += m1.elementi[i][k] * m2.elementi[k][j];
                }
                m3.elementi[i][j] = suma;
            }
        }
        return m3;
    }
    
bool IsKvadratna (int m, int n) {
    if (m != n) return false;
    return true;
}

template <typename TipElemenata>
    Matrica <TipElemenata> StepenovanaMatrica (Matrica <TipElemenata> matrica, int stepen) {
         Matrica <TipElemenata> Stepenovana = StvoriMatricu<TipElemenata>(matrica.br_redova, matrica.br_redova);
        Stepenovana = matrica;
        for (int i = 1; i < stepen; i++) {
            Stepenovana = ProduktMatrica(Stepenovana, matrica);
        }
    return Stepenovana;
    }

template <typename TipElemenata>
    void JedinicnaMatrica (Matrica <TipElemenata> &PrviClan, TipElemenata n) {
        for (int i = 0; i < PrviClan.br_redova; i++) {
            for (int j = 0; j < PrviClan.br_kolona; j++) {
                if (i == j) PrviClan.elementi[i][j] = n;
                else PrviClan.elementi[i][j] = 0;
            }
        }
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> MatricaSaKoeficijentom (const Matrica <TipElemenata> &m1, int y) {
        Matrica <TipElemenata> OdKoeficijenata (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_redova));
        for (int i = 0; i < m1.br_redova; i++) {
            for (int j = 0; j < m1.br_redova; j++) {
                OdKoeficijenata.elementi[i][j] = m1.elementi[i][j] * y;
            }
        }
        return OdKoeficijenata;
    }
    
template <typename TipElemenata>
    void Prenos (Matrica <TipElemenata> &Konacno, Matrica <TipElemenata> &Trenutno) {
        for (int i = 0; i < Trenutno.br_redova; i++) {
            for (int j = 0; j < Trenutno.br_redova; j++) {
                Konacno.elementi[i][j] = Trenutno.elementi[i][j];
            }    
        }
    }    

template <typename TipElemenata>
    Matrica <TipElemenata> MatricniPolinom(const Matrica <TipElemenata> &m1, int n, int * pok) {
        std::vector <TipElemenata> Kontejner;
        if (n < 0) throw std::domain_error ("Neispravan stepen polinoma");
        if (!IsKvadratna) throw std::domain_error ("Matrica mora biti kvadratna");

        Matrica <TipElemenata> SMatrica (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        Matrica <TipElemenata> Konacno (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        Matrica <TipElemenata> Trenutno (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        
        int y = (*pok);
        
        Matrica <TipElemenata> PrviClan (StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        JedinicnaMatrica<TipElemenata>(PrviClan, y);
        Konacno = PrviClan;
        SMatrica = m1;
        
        for (int i = 1; i < n + 1; i++) {
            pok++;
            y = (*pok);
            SMatrica = StepenovanaMatrica(m1, i);
            Matrica <TipElemenata> Proizvod = MatricaSaKoeficijentom(SMatrica, y);
            Trenutno = ZbirMatrica(Konacno, Proizvod);
            Prenos(Konacno, Trenutno);
        }
        
        return Konacno;
        
    }

//bool ValidnostUnosa();

int main () {
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    Matrica <double> m1;
    Matrica <double> m2;
    std::cout << "Unesite elemente matrice A:\n";
    try {
        m1 = StvoriMatricu <double> (m, m);
        m2 = StvoriMatricu <double> (m, m);
        UnesiMatricu('A', m1);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije";
    }
    int k;
    std::cout << "Unesite red polinoma: ";
    std::cin >> k;
    int koeficijenti [50];
    std::cout << "Unesite koeficijente polinoma: ";
    for (int i = 0; i < k + 1; i++) {
        std::cin >> koeficijenti[i];
    }
    int * pok = koeficijenti;
    m2 = MatricniPolinom(m1, k, pok);
    IspisiMatricu(m2, 10, 6);
    UnistiMatricu(m1);
    UnistiMatricu(m2);
	return 0;
}

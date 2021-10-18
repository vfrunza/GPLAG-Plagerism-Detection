/B2017/2018: Zadaća 3, Zadatak 3
/B2017/2018: Zadaća 3, Zadatak 4
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
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
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

template<typename TipElemenata>
Matrica<TipElemenata> MnozenjeSkalarom(const Matrica<TipElemenata> &mat, double koef)
{
    auto rezultantna(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            rezultantna.elementi[i][j] = mat.elementi[i][j]*koef;
        }
    }
    return rezultantna;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
    if(mat1.br_kolona != mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto proizvod(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    for(int i = 0; i < proizvod.br_redova; i++) {
        for(int j = 0; j < proizvod.br_kolona; j++) {
            TipElemenata suma(0);
             for(int k = 0; k < mat1.br_kolona; k++) {
                suma += mat1.elementi[i][k] * mat2.elementi[k][j];
            }
            proizvod.elementi[i][j] = suma;
        }
    }
    return proizvod;
}

template<typename TipElemenata, typename pok_na_kontejner>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, int stepen, pok_na_kontejner pok)
{
    if(stepen < 0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_redova != mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    
    auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i = 0; i < jedinicna.br_redova; i++) {
        for(int j = 0; j < jedinicna.br_kolona; j++) {
            if(i == j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0;
        }
    }
    auto rezultat(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    auto tmp = rezultat;
    rezultat = MnozenjeSkalarom(jedinicna,pok[0]);
    UnistiMatricu(jedinicna);
    UnistiMatricu(tmp);
    
    auto it(pok);
    it++;
    int brojac(0);
     
    Matrica<TipElemenata> pomocna, pomocna2;
    bool prvi = false;
    if(stepen > 0) {
    for(int i = 1; i <= stepen; i++) {
        if(!prvi) {
            pomocna = mat;
            pomocna2 = MnozenjeSkalarom(mat,*it++);
            prvi = true;
        } else {
            brojac++;
            auto zabrisanje1 = pomocna;
            auto zabrisanje3 = pomocna2;
            pomocna = (ProduktMatrica(pomocna, mat));
            pomocna2 = (MnozenjeSkalarom(pomocna,*it++));
            if(brojac != 1)
            UnistiMatricu(zabrisanje1);
            UnistiMatricu(zabrisanje3);
            
        }
        auto zabrisanje = rezultat;
        rezultat = ZbirMatrica(zabrisanje, pomocna2);
        UnistiMatricu(zabrisanje);
        }
    }
    UnistiMatricu(pomocna);
    UnistiMatricu(pomocna2);
    return rezultat;
}

int main()
{
    Matrica<double> A; 
    int red, n;
    std::vector<double> koeficenti;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        A = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', A);
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i = 0; i <= red; i++) {
            double koef;
            std::cin >> koef;
            koeficenti.push_back(koef);
        }
        
        auto rez(MatricniPolinom(A,red,koeficenti.begin())); 
        IspisiMatricu(rez,10);
        UnistiMatricu(A);
        UnistiMatricu(rez);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    
    return 0;
}

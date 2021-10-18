/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <new>
#include <iomanip>
#include <stdexcept>

// STRUKTURA MATRICA
template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

/* ---------- OSNOVNE Fcije ZA RAD SA MATRICAMA ---------- */
/* ----------   uglavnom date u predavanju 8b   ---------- */

// BRISANJE MATRICE
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi){
        return;
    }
    for(int i=0; i<mat.br_redova; i++){
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
// ALOKACIJA MATRICE
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++){
        mat.elementi[i] = nullptr;
    }
    try{
        for(int i=0; i<br_redova; i++){
            mat.elementi[i] = new TipElemenata[br_kolona];
        }
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
// UNOS MATRICE
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}
// ISPIS MATRICE
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati == true){
        UnistiMatricu(mat);
    }
}

/* ---------- DODATNE Fcije ZA ZADATAK ---------- */
/* ---------------------------------------------- */
// PRODUKT DVIJE MATRICE
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &MATRIX_1, const Matrica<TipElemenata> &MATRIX_2){
    if(MATRIX_1.br_kolona != MATRIX_2.br_redova){
        UnistiMatricu(MATRIX_1);
        UnistiMatricu(MATRIX_2);
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    // mnozenje matrica sa istim brojem redova i kolona jer je matrica kvadratna
    auto produkt = StvoriMatricu<TipElemenata>(MATRIX_1.br_redova, MATRIX_2.br_kolona);
    for(int i = 0; i < MATRIX_1.br_redova; i++){
        for(int j = 0; j < MATRIX_2.br_kolona; j++){
            int suma = 0;
            for(int k=0; k<MATRIX_1.br_kolona; k++){
                suma = suma + ( MATRIX_1.elementi[i][k] * MATRIX_2.elementi[k][j] );
            }
            produkt.elementi[i][j] = suma;
        }
    }
    return produkt;
}
// MNOZENJE MATRICE SKALAROM
template <typename TipElemenata>
void MnozenjeSkalarom (Matrica<TipElemenata> &MATRIX, int skalar){
    for(int i=0; i<MATRIX.br_redova; i++){
        for(int j=0; j<MATRIX.br_kolona; j++){
            MATRIX.elementi[i][j] = MATRIX.elementi[i][j] * skalar;
        }
    }
}
// SABIRANJE DVIJE MATRICE
template<typename TipElemenata>
void SabiranjeMatrica (Matrica<TipElemenata> &MATRIX_1, const Matrica<TipElemenata> &MATRIX_2){
    for(int i=0; i<MATRIX_1.br_redova; i++){
        for(int j=0; j<MATRIX_1.br_kolona; j++){
            MATRIX_1.elementi[i][j] = MATRIX_1.elementi[i][j] + MATRIX_2.elementi[i][j];
        }
    }
}
// MATRICNI POLINOM
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &MATRIX, std::vector<double> koeficijenti){
    if(MATRIX.br_kolona != MATRIX.br_redova){
        UnistiMatricu(MATRIX);
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    
    auto polinom = StvoriMatricu<TipElemenata>(MATRIX.br_redova, MATRIX.br_kolona);
    // sve elemente polinoma postaviti na jedan
    for(int i=0; i<MATRIX.br_redova; i++){
        for(int j=0; j<MATRIX.br_kolona; j++){
            polinom.elementi[i][j] = 0;
        }
    }
    
    // racunanje polinoma
    int brojac_stepena = 1;
    for(int v=1; v<koeficijenti.size(); v++){
        auto tmp = StvoriMatricu<TipElemenata>(MATRIX.br_redova, MATRIX.br_kolona);
        // sve elemente tmp-a postaviti na jedan
        for(int i=0; i<MATRIX.br_redova; i++){
            for(int j=0; j<MATRIX.br_kolona; j++){
                if(i == j)
                    tmp.elementi[i][j] = 1;
                else 
                    tmp.elementi[i][j] = 0;
            }
        }
        
        for(int i=0; i<brojac_stepena; i++){
            auto pomocni = tmp;
            tmp = ProduktMatrica(tmp, MATRIX);
            UnistiMatricu(pomocni);
        }
        brojac_stepena++;
        
        MnozenjeSkalarom(tmp, koeficijenti[v]);
        SabiranjeMatrica(polinom, tmp);
        UnistiMatricu(tmp);
    }
    auto tmp = StvoriMatricu<TipElemenata>(MATRIX.br_redova, MATRIX.br_kolona);
    for(int i=0; i<MATRIX.br_redova; i++){
        for(int j=0; j<MATRIX.br_kolona; j++){
            if(i == j){
                tmp.elementi[i][j] = 1;
            } else {
                tmp.elementi[i][j] = 0;
            }
        }
    }
    MnozenjeSkalarom(tmp, koeficijenti[0]);
    SabiranjeMatrica(polinom, tmp);
    UnistiMatricu(tmp);
    return polinom;
}

int main (){
    int dimenzija_matrice;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija_matrice;
    
    //ALOCIRANJE matrice i UNOS matrice
    Matrica<int> A;
    Matrica<int> PRODUKT;
    try{
        A = StvoriMatricu<int>(dimenzija_matrice, dimenzija_matrice);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', A);
        
        int n, a;
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koeficijenti;
        for(int i=0; i<=n; i++){
            std::cin >> a;
            koeficijenti.push_back(a);
        }
        
        PRODUKT = MatricniPolinom(A, koeficijenti);
        IspisiMatricu(PRODUKT, 10);
        
    } catch (std::bad_alloc){
        UnistiMatricu(A);
        UnistiMatricu(PRODUKT);
    }
      catch (...) {
        UnistiMatricu(A);
        UnistiMatricu(PRODUKT);
      }
    UnistiMatricu(A);
    UnistiMatricu(PRODUKT);
	return 0;
}
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
void UnistiMatricu(const Matrica<TipElemenata> &mat){
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
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
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa = 10, int preciznost = 6, bool TrebaBrisati = false){
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(TrebaBrisati) UnistiMatricu<TipElemenata>(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    auto P(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");

    for(int i = 0; i < P.br_redova; i++){
            for(int j = 0; j < P.br_kolona; j++){
                P.elementi[i][j] = 0;
            }
        }
    for(int i = 0; i < m1.br_redova; i++){
        for(int j = 0; j < m2.br_kolona; j++){
            for(int k  = 0; k < m2.br_kolona; k++)
            P.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
        }
    }
    return P;
}

template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int red, IterTip koeficijenti){
    
    int n = A.br_redova;
    
    auto MatPol(StvoriMatricu<TipElemenata>(n, n));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            MatPol.elementi[i][j] = 0;
        }
    }
    
    
    if(A.br_redova != A.br_kolona) throw std::domain_error("");
    
    
    for(int k = 0; k <= red; k++){
        auto temp(StvoriMatricu<TipElemenata>(n, n));
        if(k == 0){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j) temp.elementi[i][j] = 1;
                    else temp.elementi[i][j] = 0;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    temp.elementi[i][j] = A.elementi[i][j];
                }
            }
            for(int i = 1; i < red; i++){
                auto t = ProduktMatrica<TipElemenata>(temp, A);
                temp = t;
                UnistiMatricu(t);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp.elementi[i][j] *= (*koeficijenti);
            }
        }
        koeficijenti++;
        MatPol = ZbirMatrica<TipElemenata>(MatPol, temp);
        UnistiMatricu<TipElemenata>(temp);
    }

    return MatPol;
}

int main(){
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin>>n;
    Matrica<double> A(StvoriMatricu<double>(n, n));
    std::cout<<"Unesite elemente matrice A: \n";
    UnesiMatricu<double>('A', A);
    std::cout<<"Unesite red polinoma: ";
    int red;
    std::cin>>red;
    std::vector<double> K;
    std::cout<<"Unesite koeficijente polinoma: ";
    for(int i = 0; i <= red; i++){
        int koef;
        std::cin>>koef;
        K.push_back(koef);
    }

    
    auto MatPol = MatricniPolinom(A, red, K.begin());
    
    IspisiMatricu<double>(MatPol);
    UnistiMatricu(A);
    UnistiMatricu(MatPol);
    
    return 0;
}
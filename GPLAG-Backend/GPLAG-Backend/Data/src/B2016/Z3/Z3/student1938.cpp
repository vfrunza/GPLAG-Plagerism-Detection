#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try{
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> A, Matrica<TipElemenata> B){
    if(A.br_kolona != B.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto C(StvoriMatricu<TipElemenata>(A.br_redova,B.br_kolona));
    for(int i = 0; i < C.br_redova; i++)
        for(int j = 0; j < C.br_kolona; j++)
            C.elementi[i][j] = 0;
    for(int i = 0; i < A.br_redova; i++)
        for(int j = 0; j < B.br_kolona; j++)
            for(int k = 0; k < B.br_redova; k++)
                C.elementi[i][j] += A.elementi[i][k] * B.elementi[k][j];
    return C;
}
template <typename TipElemenata>
Matrica<TipElemenata> matNaX(Matrica<TipElemenata> mat, int x){
    Matrica<TipElemenata> I, tmp;
    try{
         I = StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
        for(int i = 0; i < I.br_redova; i++)
            for(int j = 0; j < I.br_kolona; j++){
                if(i == j) I.elementi[i][j] = 1;
                else I.elementi[i][j] = 0;
            }
        if(x == 0) return I;
        //Matrica<TipElemenata> tmp;
        for(int i = 0; i < x; i++){
            tmp = I;
            I = ProduktMatrica(I,mat);
            UnistiMatricu(tmp); tmp.elementi = nullptr;
        }
    }catch(std::bad_alloc){
        UnistiMatricu(I); I.elementi = nullptr;
        throw;
    }
    return I;
}
template<typename TipElemenata>
void multiply(Matrica<TipElemenata> &A, double x){
    for(int i = 0; i < A.br_redova; i++)
        for(int j = 0; j < A.br_kolona; j++)
            A.elementi[i][j] *= x;
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, std::vector<double> v){
    if(A.br_kolona != A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> tmp1, tmp2,ret;
    
    ret = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    try{
        for(int i = 0; i < A.br_redova; i++)
            for(int j = 0; j < A.br_kolona; j++)
                ret.elementi[i][j] = 0;
        if(v.size() == 0) return ret;
        int n = v.size();
        for(int k = 0; k < n; k++){
            tmp1 = ret;
            tmp2 = matNaX(A,k);
            multiply(tmp2, v[k]);
            ret = ZbirMatrica(ret,tmp2);
            UnistiMatricu(tmp1); UnistiMatricu(tmp2); tmp1.elementi = nullptr; tmp2.elementi = nullptr;
        }
    }catch(std::bad_alloc){
           UnistiMatricu(tmp1); UnistiMatricu(tmp2); UnistiMatricu(ret);
           tmp1.elementi = nullptr; tmp2.elementi = nullptr; ret.elementi = nullptr;
           throw;
    }
    return ret;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++){
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,
int preciznost = 6, bool treba_brisati = false){
    std::cout.precision(preciznost);
    for(int i = 0; i < mat.br_redova; i++){
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
int main () {
    Matrica<double> a,b,c;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try{
        a = StvoriMatricu<double>(m,m);
        //b = StvoriMatricu<double>(m,n);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red; std::cin >> red;
        std::vector<double> v(red+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i = 0; i <= red; i++) std::cin >> v[i];
        IspisiMatricu(MatricniPolinom(a,v),10,6,true);
    }catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
	return 0;
}
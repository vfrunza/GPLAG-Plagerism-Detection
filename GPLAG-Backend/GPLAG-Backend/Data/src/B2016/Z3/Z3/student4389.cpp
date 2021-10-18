/B2016/2017: Zadaća 3, Zadatak 3
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
// VEOMA BITNA INICIJALIZACIJA!
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
            << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setprecision(preciznost) 
            <<std::setw(sirina_ispisa) 
            << mat.elementi[i][j];
            std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata, typename BrojniTip>
Matrica<TipElemenata> SkalarniProduktMatrica(const Matrica<TipElemenata> &m2, const BrojniTip a){
    Matrica<TipElemenata> m1(StvoriMatricu<TipElemenata>(m2.br_redova, m2.br_kolona));
    for(int i=0; i<m2.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++) m1.elementi[i][j]=m2.elementi[i][j]*a;
    return m1;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m3.br_redova; i++)
        for(int j=0; j<m3.br_kolona; j++){
            TipElemenata suma = {};
            for(int k=0; k<m1.br_kolona; k++) suma+= m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> KvadratMatrice(const Matrica<TipElemenata> &m, int stepen){
    Matrica<TipElemenata> temp(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<m.br_redova; i++) for(int j=0; j<m.br_kolona; j++) temp.elementi[i][j] = m.elementi[i][j];
    for(int i=1; i<stepen; i++){
        temp = ProduktMatrica(temp, m);
    }
    return temp;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> koef){
    if(A.br_kolona!=A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> polinom;   //Inicijalizacija polinoma
    polinom = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    if(koef.empty()) return polinom;
    for(int i=0; i<A.br_redova; i++) polinom.elementi[i][i] = koef.at(0);
    Matrica<TipElemenata> c(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    Matrica<TipElemenata> skalar(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    for(int i=1; i<koef.size(); i++){
        c = KvadratMatrice(A, i);
        skalar = SkalarniProduktMatrica(c , koef.at(i));
        polinom = ZbirMatrica(skalar, polinom);
    }
    UnistiMatricu(c);
    UnistiMatricu(skalar);
    return polinom;
}
int main() {
    Matrica<double> m1;
    m1 = StvoriMatricu<double>(2,2);
    UnesiMatricu<double>('A', m1);
    std::vector<double> v  = {1, 2, 3, 4, 5};
    auto polinom = MatricniPolinom(m1, v);
    IspisiMatricu(polinom, 5);
    UnistiMatricu(polinom);
    UnistiMatricu(m1);
    /*Matrica<double> a, polinom;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red(0); std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> koef; double temp;
        for(int i=0; i<red+1; i++) {std::cin >> temp; koef.push_back(temp);}
        polinom = StvoriMatricu<double>(m, m);
        polinom = MatricniPolinom(a, koef);
        UnistiMatricu(a);
        IspisiMatricu(polinom, 10, 6, true);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;*/
}
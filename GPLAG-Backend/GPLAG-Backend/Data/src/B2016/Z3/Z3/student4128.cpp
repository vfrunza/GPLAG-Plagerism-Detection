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
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false) {    
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
    std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> mat1,Matrica<TipElemenata> mat2){
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat3=StvoriMatricu(mat1.br_redova,mat2.br_kolona);
    try{
    for(int i=0;i<mat1.br_redova;i++){
        for(int j=0;j<mat2.br_kolona;j++){
            for(int k=0;k<mat1.br_kolona;k++){
                mat3.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];
            }
        }
    }
    }
    catch(...){
        UnistiMatricu(mat3);
        throw;
    }
    return mat3;
}

template<typename TipElemenata>
void PomnoziSkalarom(Matrica<TipElemenata> &m,double x){
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            m[i][j]*=x;
        }
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat1,std::vector<double> v){
    if(mat1.br_kolona!=mat1.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto polinom=StvoriMatricu(mat1.br_redova,mat1.br_kolona);
    std::vector<Matrica<TipElemenata>> pomocne(v.size()-2);
    std::vector<Matrica<TipElemenata>> novi1;
    std::vector<Matrica<TipElemenata>> novi2;
    for(int i=1;i<v.size()+1;i++){
        int br(0);
        for(int j=0;j<i;j++){
            auto pom=ProduktMatrica(pomocne[br],pomocne[br]);
            novi1.push_back(pom);
            pomocne[br]=pom;
        }
        PomnoziSkalarom(pomocne[br],v[i+1]);
        br++;
    }
    for(int i=1;i<pomocne.size();i++){
        auto pom=ZbirMatrica(pomocne[i],pomocne[i-1]);
        novi2.push_back(pom);
        polinom=pom;
    }
    auto nova=ZbirMatrica(polinom,mat1);
    polinom=nova;
    auto nula=StvoriMatricu(mat1.br_redova,mat1.br_kolona);
    for(int i=0;i<mat1.br_redova;i++){
        for(int j=0;j<mat1.br_kolona;j++){
            if(i==j) nula[i][j]=1;
            else nula[i][j]=0;
        }
    }
    auto x=ZbirMatrica(polinom,nula);
    polinom=x;
    UnistiMatricu(nova);
    UnistiMatricu(x);
    UnistiMatricu(nula);
    for(int i=0;i<pomocne.size();i++) UnistiMatricu(pomocne[i]);
    for(int i=0;i<novi1.size();i++) UnistiMatricu(novi1[i]);
    for(int i=0;i<novi2.size();i++) UnistiMatricu(novi2[i]);
    
    return polinom;
    
}













int main() {
    Matrica<double> a, b, c; 
    int m, n;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    try {
        a = StvoriMatricu<double>(m, n);
        b = StvoriMatricu<double>(m, n);
        std::cout << "Unesi matricu A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesi matricu B:\n";
        UnesiMatricu('B', b);
        std::cout << "Zbir ove dvije matrice je:\n";
        IspisiMatricu(c = ZbirMatrica(a, b), 7);
 }
 catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
 }
    UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
 return 0;
}

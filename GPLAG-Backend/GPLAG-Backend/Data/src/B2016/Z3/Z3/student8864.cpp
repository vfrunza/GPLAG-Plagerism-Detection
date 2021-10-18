/B2016/2017: Zadaća 3, Zadatak 3
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
void UnistiMatricu(Matrica<TipElemenata> mat) {
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
    try {
        for(int i = 0; i < br_redova; i++)
        mat.elementi[i] = new TipElemenata[br_kolona]{};
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
            std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6,bool treba_brisati=false) {
    //std::cout<<"redovi: "<<mat.br_redova<<"kolone: "<<mat.br_kolona<<std::endl;
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata>&m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++){
            for(int k=0;k<m1.br_kolona;k++)
               m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
        }
    return m3;
}
template <typename TipElemenata>
void PomnoziSkalarom(Matrica<TipElemenata> &m,double x){
    for(int i=0;i<m.br_redova;i++)
        for(int j=0;j<m.br_kolona;j++)
            m.elementi[i][j]*=x;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m,std::vector<double> p){
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    int n(m.br_kolona);
    auto I(StvoriMatricu<TipElemenata>(n,n));
    auto mp(StvoriMatricu<TipElemenata>(n,n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mp.elementi[i][j]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j) I.elementi[i][j]=1;
            else I.elementi[i][j]=0;
        }
    for(int i=0;i<p.size();i++){
        if(i==0){
            UnistiMatricu(mp);
            mp=I;
            PomnoziSkalarom(mp,p[0]);
        }
        else{
            auto temp(StvoriMatricu<TipElemenata>(n,n));
            for(int k=0;k<n;k++)
                for(int j=0;j<n;j++)
                    temp.elementi[k][j]=m.elementi[k][j];
            for(int j=0;j<i-1;j++){
                auto x(ProduktMatrica(temp,m));
                UnistiMatricu(temp);
                temp=x;
            }
            PomnoziSkalarom(temp,p[i]);
            auto y(ZbirMatrica(mp,temp));
            UnistiMatricu(mp);
            UnistiMatricu(temp);
            mp=y;
        }
    }
    return mp;
}
int main() {
    Matrica<double> a, b; // AUTOMATSKA INICIJALIZACIJA!!!
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >>n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin>>red;
        std::vector<double> p(red+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<red+1;i++){
            std::cin>>p[i];
        }
        IspisiMatricu(b = MatricniPolinom(a,p),10);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!";
    }
    UnistiMatricu(a); UnistiMatricu(b);
 return 0;
}

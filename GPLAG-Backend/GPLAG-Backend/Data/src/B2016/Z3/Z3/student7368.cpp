/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename T>
struct Matrica {
    int br_redova,br_kolona;
    T **elementi = nullptr;
};
template <typename T>
void UnistiMatricu(Matrica<T>mat) {
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename T>
Matrica<T>StvoriMatricu (int br_redova, int br_kolona) {
    Matrica<T> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new T *[br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for (int i=0; i<br_redova; i++)
        mat.elementi[i]=new T [br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename T>
void UnesiMatricu (char ime_matrice, Matrica<T>&mat) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename T>
void IspisiMatricu(const Matrica<T>&mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona;j++) std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if (treba_brisati==true) {
        UnistiMatricu(mat);
    }
}
template<typename T>
Matrica<T>ZbirMatrica (const Matrica<T>&m1, const Matrica<T>&m2) {
    if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) 
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3 (StvoriMatricu<T>(m1.br_redova,m1.br_kolona));
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_kolona; j++) m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    }
    return m3;
}
template<typename T>
Matrica<T>ProduktMatrica(const Matrica<T>&m1, const Matrica<T>&m2) {
    if (m1.br_kolona!=m2.br_redova) throw ("Matrice nisu saglasne za mnozenje");
    Matrica<T>mat=StvoriMatricu<T>(m1.br_redova,m2.br_kolona);
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            for (int k=0; k<mat.br_redova; k++) {
                mat.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return mat; 
}
template<typename T>
Matrica<T>KopijaMatrice(const Matrica<T>a) {
    Matrica<T>mat=StvoriMatricu<T>(a.br_redova,a.br_kolona);
    for (int i=0; i<a.br_redova; i++) {
        for (int j=0; j<a.br_kolona; j++) {
            mat.elementi[i][j]=a.elementi[i][j];
        }
    }
    return mat;
}
template<typename T>
void Zamjena(Matrica<T>&a1, Matrica<T>a) {
    UnistiMatricu(a1);
    a1=KopijaMatrice<T>(a);
}
template<typename T>
Matrica<T>PomnoziSaSkalarom(Matrica<T>a, double n){
    Matrica<T>mat=StvoriMatricu<T>(a.br_redova,a.br_kolona);
    if (n==0){
        for (int i=0; i<mat.br_redova;i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                mat.elementi[i][j]=0;
            }
        }
    }
    else {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            mat.elementi[i][j]=n*a.elementi[i][j];
        }
    }}
    return mat; //mat alocirano
}
template<typename T>
Matrica<T>Stepenuj(Matrica<T>a, int n) {
    Matrica<T>mat=KopijaMatrice<T>(a);
    if (n>1) {
        for (int i=0; i<n-1; i++) {
            Zamjena(mat,ProduktMatrica(mat,a));
        }
        return mat;
    }
    else if (n<1){
        for (int i=0; i<mat.br_redova; i++) {
            for (int j=0; j<mat.br_kolona; j++) {
                if (i==j) mat.elementi[i][j]=1;
                else mat.elementi[i][j]=0;
            }
        }
        return mat;
    }
    return mat;
}
template<typename T>
Matrica<T>MatricniPolinom (Matrica<T>m1, std::vector<double>v) {
    if (m1.br_kolona!=m1.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    Matrica<T>mat=StvoriMatricu<T>(m1.br_redova,m1.br_kolona);
    for (int i=0; i<v.size(); i++) {
    Matrica<T>a=Stepenuj<T>(m1,i);
    Matrica<T>b=PomnoziSaSkalarom<T>(a,v[i]);
    Zamjena<T>(mat,ZbirMatrica<T>(mat,b));
    UnistiMatricu(a);
    UnistiMatricu(b);
    }
    return mat;
}
int main () {
    Matrica<double>a;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
    }
    catch (std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    std::cout<<"Unesite red polinoma: ";
    int n;
    std::cin>>n;
    double x;
    std::vector<double>v;
    std::cout<<"Unesite koeficijente polinoma: ";
    for (int i=0; i<n+1; i++) {
        std::cin>>x;
        v.push_back(x);
    }
    Matrica<double>mat=MatricniPolinom<double>(a,v);
    IspisiMatricu(mat,10);
    UnistiMatricu(a);

	return 0;
}
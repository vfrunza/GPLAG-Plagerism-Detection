/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<new>
#include<vector>
using std::cout;
using std::cin;

template<typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; 
    mat.br_kolona=br_kolona;
    mat.elementi= new TipElemenata*[br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for (int i=0; i<br_redova; i++){
            mat.elementi[i]=new TipElemenata[br_kolona];
        }
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2){
    if (m1.br_kolona != m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje!");
    auto m3=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for (int i=0; i<m1.br_redova; i++){
        for (int j=0; j<m2.br_kolona; j++){
            TipElemenata suma=0;
            for (int k=0; k<m2.br_redova; k++){
                    suma+=m1.elementi[i][k]*m2.elementi[k][j];
                }
                m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> a, std::vector<int> pk){
    if (a.br_redova !=a.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna!");
    Matrica<TipElemenata>pomocna;
    Matrica<TipElemenata>pn;
    pomocna=StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
    pn=StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
    for (int i=0; i<a.br_redova; i++){
        for (int j=0; j<a.br_kolona; j++){
            if (i==j) pn[i][j]=1;
            else {pn[i][j]=0; }
            
        }
    }
    for (int i=0; i<a.br_redova; i++){
        for (int j=0; j<a.br_kolona; j++){
            pomocna[i][j]=0;
            
        }
    }
    for (int i=0; i<pk.size(); i++){
    if (i==0) continue;
    else if (i==1) {pn=a;continue;}
    
    for (int j=0; j<i; i++){
        pn=ProduktMatrica(pn,a);
    }
        for(int k=0; k<pomocna.br_redova; k++){
            for (int l=0; l<pomocna.br_kolona; l++){
                pomocna[k][l]+=pk[i]*pn[k][l];
            }
        }
    }
    UnistiMatricu(pn);
    return pomocna;
}

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    mat.elementi=nullptr;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for (int i=0; i<mat.br_redova; i++){
        for (int j=0; j<mat.br_kolona; j++){
            std::cout<<ime_matrice<<"("<<i+1<<", "<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int precizonst=6, bool treba_brisati=false) {
     for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++){
            std::cout << std::setw(sirina_ispisa) <<std::setprecision(precizonst)<<mat.elementi[i][j];
         }
         std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if (m1.br_redova != m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for (int i=0; i<m1.br_redova; i++){
        for (int j=0; j<m1.br_kolona; j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

int main (){
    //Matrica<int> c;
    Matrica<int> a;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<int>(m, m);
        std::cout << "Unesite matricu A:\n";
        UnesiMatricu('A', a);
    int n;
    std::cout<<"Unesite red polinoma: ";
    cin>>n;
    std::vector<int> v;
    std::cout<<"Unesite koeficijente polinoma: ";
    for (int i=0; i<n; i++){
        int broj;
        cin>>broj;
        v.push_back(broj);
        
    }
    //c=StvoriMatricu<int>(m, m);
    //c=MatricniPolinom<int>(a,v);
    IspisiMatricu(MatricniPolinom(a,v), 10, 6, false);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    //UnistiMatricu(c);
    return 0;
}
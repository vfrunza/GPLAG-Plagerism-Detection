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
 for(int i = 0; i < mat.br_redova; i++){
    delete[] mat.elementi[i];
    mat.elementi[i]=nullptr;
 }
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
            std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
     }
 }
template <typename TipElemenata>
 void IspisiMatricu( Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_bristai=false) {
     for(int i = 0; i < mat.br_redova; i++) {
         for(int j = 0; j < mat.br_kolona; j++)
             std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_bristai)
        UnistiMatricu(mat);
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
    Matrica<TipElemenata>ProduktMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2){
    if (m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m1.br_redova; i++){
        for(int j = 0; j < m2.br_kolona; j++){
            m3.elementi[i][j]=TipElemenata();
            for(int k = 0; k < m2.br_redova; k++){
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }    
    }        
    return m3;
    }
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom( Matrica<TipElemenata> m, std::vector<double> v){
    if (m.br_kolona != m.br_redova)
            throw std::domain_error("Matrica mora biti kvadratna");
    auto m3(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
     for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
            m3.elementi[i][j]=0;
    if(v.size()==0) return m3;
    auto I(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int i = 0; i < I.br_redova; i++)
            for(int j = 0; j < I.br_kolona; j++)
                if(i==j)    
                    I.elementi[i][j]=1;
                else 
                    I.elementi[i][j]=0;
    Matrica<TipElemenata> temp;
    for(int k=0; k<v.size(); k++){
        if(k!=0){
            temp=ProduktMatrica(m,I);
            UnistiMatricu(I);
            I=temp;
        }
        auto g(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
             for(int i = 0; i < I.br_redova; i++)
                    for(int j = 0; j < I.br_kolona; j++)
                            g.elementi[i][j]=I.elementi[i][j]*v[k];       
        auto p=ZbirMatrica(m3,g);
        UnistiMatricu(g);
        for(int i=0;i<m.br_redova;i++)
            for(int j=0;j<m.br_kolona;j++)
                m3.elementi[i][j]=p.elementi[i][j];
        UnistiMatricu(p);
    }
    UnistiMatricu(temp);
    return m3;        
}
int main() {
    
    Matrica<double> A;
    std::cout << "Unesite dimenziju kvadratne matrice: Unesite elemente matrice A: " << std::endl;
    int n; std::cin >> n;
    A = StvoriMatricu<double>(n,n);
    UnesiMatricu('A',A);
    std::cout << "Unesite red polinoma: ";
    int m; std::cin >> m;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<double> v;
    for(int i=0; i<m+1; i++){
        v.push_back(0);
        std::cin>>v[i];
    }
    auto P(MatricniPolinom<double> (A,v));
    IspisiMatricu(P, 10,6);
    UnistiMatricu(A);
    UnistiMatricu(P);
 return 0;
}
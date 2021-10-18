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
         std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<<mat.elementi[i][j];
         std::cout << std::endl;
         }
         
         if(treba_brisati==true){
             UnistiMatricu(mat);
         }
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

template <typename TipElemenata>
        Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
            if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
            auto mat(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
             for(int i = 0; i < m1.br_redova; i++){
             for(int j = 0; j < m2.br_kolona; j++){
                 for(int k=0; k<m1.br_kolona; k++){
                     mat.elementi[i][j]=m1.elementi[i][k]*m2.elementi[k][j];
                 }
            }}
            return mat;
            
        }
        
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> v){
        if (A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
        auto mat(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
        if (v.size()==0) {
            for(int i=0; i<A.br_redova; i++){
                for (int j=0; j<A.br_kolona; j++){
                    mat.elementi[i][j]=0;
                }
            }
            return mat;
        }
        
        auto B (StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
        for(int i=0; i<B.br_redova; i++){
                for (int j=0; j<B.br_kolona; j++){
                    if(i==j) B.elementi[i][j]=1;
                    else B.elementi[i][j]=0;
                }
            }
            
        for(int i=0; i<v.size(); i++){
            
            for(int l=0; l<B.br_redova; l++){
                for(int g=0; g<B.br_kolona; g++){
                    B[l][g]=v[i]*B[l][g];
                }
            }
            B=ProduktMatrica(A,B);
    
        }
        
        return B;
        
    }
int main() {
         Matrica<double> A; // AUTOMATSKA INICIJALIZACIJA!!!
         int m;
         std::cout << "Unesite dimenziju kvadratne matrice: ";
         std::cin >> m;
         try {
         A = StvoriMatricu<double>(m, m);

         std::cout << "Unesite elemente matrice A: ";
         UnesiMatricu('A', A);
         int red;
         std::cout<<"Unesite red polinoma: ";
         std::cin>>red;
         std::cout<<"Unesite koeficijente: ";
         std::vector<double> koef(red);
         for (int i=0; i<red; i++){
             std::cin>>koef[i];
         }
         
         IspisiMatricu(MatricniPolinom(A, koef));
         UnistiMatricu(A);
         }
         catch(std::bad_alloc) {
         std::cout << "Nema dovoljno memorije!\n";
         }
         
         return 0;
        }
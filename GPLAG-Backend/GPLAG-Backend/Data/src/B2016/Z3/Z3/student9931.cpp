#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace std;
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6 ,bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout <<setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 if (treba_brisati) {
     UnistiMatricu(mat);
 }
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    Matrica<TipElemenata> m3;
    if (m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje!");
    m3=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {
            double suma(0);
            for (int k = 0; k < m2.br_redova; k++) {
            suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> m1, std::vector<int> p) {
  auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    auto m2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     auto m4(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
      auto m5(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
       
     if (m1.br_kolona!=m1.br_redova) throw domain_error("Matrica mora biti kvadratna!");
     if (p.empty()) return m3;
     
     for (int q = 0; q < m1.br_redova; q++) {
           for (int w = 0; w < m1.br_kolona; w++) {
               m2.elementi[q][w]=m1.elementi[q][w];
               m4.elementi[q][w]=m1.elementi[q][w];
               m5.elementi[q][w]=m1.elementi[q][w];
               if(q==w)m3.elementi[q][w]=1;
               else m3.elementi[q][w]=0;
           }
        }
        
    
    for (int i = 0; i < p.size(); i++) {
        
        for (int j = 0; j < m1.br_redova; j++) {
           for (int k = 0; k < m1.br_kolona; k++) {
               if (i==0) {
               m3.elementi[j][k]*=p[i];
               }
               if(i==1){
               m4.elementi[j][k]=m2.elementi[j][k]*p[i];
               m5.elementi[j][k]=m3.elementi[j][k]+m4.elementi[j][k];}
               if(i>1){
                m4.elementi[j][k]=m2.elementi[j][k]*p[i];
                m5.elementi[j][k]=m4.elementi[j][k]+m5.elementi[j][k];
                 
               }
               
               }
           
        }
        if(i>0)m2=ProduktMatrica(m1,m2);
    }
    return m5;
}
int main() {
 Matrica<double> a, b, c, d,w; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::vector<int> o ;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m ;
 try {
 a = StvoriMatricu<double>(m, m);
 b = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);

 
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 
     

 
     std::cout << "Unesite red polinoma: ";
     int h,e;
     std::cin >> h;//unos duzine vektora
     std::cout << "Unesite koeficijente polinoma: " ;
     for (int i = 0; i < h+1; i++) {
      std::cin >> e;
      o.push_back(e);
     }//unos vektora
 try {
     IspisiMatricu((w=MatricniPolinom(a,o)),10);
     }
     catch(std::domain_error izuzetak){
         std::cout << izuzetak.what() << std::endl;
     }
 catch (const char error[]) {
     std::cout << error << std::endl;
 }
 
 UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);UnistiMatricu(w);UnistiMatricu(d);
 return 0;
}
/*#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace std;
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6 ,bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout <<setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 if (treba_brisati) {
     UnistiMatricu(mat);
 }
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    Matrica<TipElemenata> m3;
    if (m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje!");
    m3=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {
            double suma(0);
            for (int k = 0; k < m2.br_redova; k++) {
            suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> m1, std::vector<int> p) {
  auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    auto m2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     auto m4(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
      auto m5(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
       
     if (m1.br_kolona!=m1.br_redova) throw domain_error("Matrica mora biti kvadratna!");
     if (p.empty()) return m3;
     
     for (int q = 0; q < m1.br_redova; q++) {
           for (int w = 0; w < m1.br_kolona; w++) {
               m2.elementi[q][w]=m1.elementi[q][w];
               m4.elementi[q][w]=m1.elementi[q][w];
               m5.elementi[q][w]=m1.elementi[q][w];
               if(q==w)m3.elementi[q][w]=1;
               else m3.elementi[q][w]=0;
           }
        }
        
    
    for (int i = 0; i < p.size(); i++) {
        
        for (int j = 0; j < m1.br_redova; j++) {
           for (int k = 0; k < m1.br_kolona; k++) {
               if (i==0) {
               m3.elementi[j][k]*=p[i];
               }
               if(i==1){
               m4.elementi[j][k]=m2.elementi[j][k]*p[i];
               m5.elementi[j][k]=m3.elementi[j][k]+m4.elementi[j][k];}
               if(i>1){
                m4.elementi[j][k]=m2.elementi[j][k]*p[i];
                m5.elementi[j][k]=m4.elementi[j][k]+m5.elementi[j][k];
                 
               }
               
               }
           
        }
        if(i>0)m2=ProduktMatrica(m1,m2);
    }
    return m5;
}
int main() {
 Matrica<double> a, b, c, d,w; // AUTOMATSKA INICIJALIZACIJA!!!
 int m, n;
 std::vector<int> o ;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m >> n;
 try {
 a = StvoriMatricu<double>(m, n);
 b = StvoriMatricu<double>(m, n);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);
 std::cout << "Unesite elemente matrice B: \n";
 UnesiMatricu('B', b);
 std::cout << "Zbir ove dvije matrice je:\n";
 IspisiMatricu(c = ZbirMatrica(a, b), 10);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 try {
     std::cout <<  "Proizvod ove dvije matrice je:\n";
     IspisiMatricu((d=ProduktMatrica(a,b)),10);
     }
     catch(std::domain_error izuzetak){
         std::cout << izuzetak.what() << std::endl;
     }

 
     std::cout << "Unesite red polinoma:\n";
     int h,e;
     std::cin >> h;//unos duzine vektora
     std::cout << "Unesite koeficijente polinoma: " ;
     for (int i = 0; i < h+1; i++) {
      std::cin >> e;
      o.push_back(e);
     }//unos vektora
 try {
     IspisiMatricu((w=MatricniPolinom(a,o)),10);
     }
     catch(std::domain_error izuzetak){
         std::cout << izuzetak.what() << std::endl;
     }
 catch (const char error[]) {
     std::cout << error << std::endl;
 }
 
 UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
 return 0;
}
*/